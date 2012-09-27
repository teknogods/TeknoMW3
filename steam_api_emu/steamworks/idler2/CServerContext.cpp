#include "CServerContext.h"

bool CServerContext::Begin()
{
	std::cout << "[SERVER] Loading item DB... ";

	if( !CItemDB::LoadDB() )
		return false;

	std::cout << "Loaded." << std::endl << "[SERVER] Initializing... ";

	pipe = client->CreateSteamPipe();
	client->SetLocalIPBinding(bindip, serverport-100);

	user = client->CreateLocalUser(&pipe, k_EAccountTypeGameServer);
	if (!user)
	{
		std::cerr << "Steam user could not be created." << std::endl;
		return false;
	}

	masterserver = (ISteamMasterServerUpdater001 *)client->GetISteamMasterServerUpdater(user, pipe, STEAMMASTERSERVERUPDATER_INTERFACE_VERSION_001);
	if (!masterserver)
	{
		std::cerr << "Unable to get " STEAMMASTERSERVERUPDATER_INTERFACE_VERSION_001 << std::endl;
		return false;
	}

	gameserver = (ISteamGameServer009 *)client->GetISteamGameServer(user, pipe, STEAMGAMESERVER_INTERFACE_VERSION_009);
	if (!gameserver)
	{
		std::cerr << "Unable to get " STEAMGAMESERVER_INTERFACE_VERSION_009 << std::endl;
		return false;
	}

	gameserveritems = (ISteamGameServerItems004 *)client->GetISteamGenericInterface(user, pipe, STEAMGAMESERVERITEMS_INTERFACE_VERSION_004);
	if (!gameserveritems)
	{
		std::cerr << "Unable to get " STEAMGAMESERVERITEMS_INTERFACE_VERSION_004 << std::endl;
		return false;
	}

	networking = (ISteamNetworking002 *)client->GetISteamNetworking( user, pipe, STEAMNETWORKING_INTERFACE_VERSION_002 );
	if (!networking)
	{
		std::cerr << "Unable to get " STEAMNETWORKING_INTERFACE_VERSION_002 << std::endl;
		return false;
	}

	bool serverInit = gameserver->SetServerType(SERVER_FLAGS, 0, serverport, 0, serverport-1, "tf", "1.0.7.1", false);
	if (!serverInit)
	{
		std::cerr << "Error initializing SteamGameServer type." << std::endl;
		return false;
	}

	serverSocket = networking->CreateListenSocket( 0, 0, serverport, false );
	if ( !serverSocket )
	{
		std::cerr << "Unable to create listen socket." << std::endl;
		return false;
	}

	UpdateServerStatus();
	masterserver->SetActive(true);

	gameserver->LogOn();

	std::cout << "Complete. pipe: " << pipe << " user: " << user << std::endl;

	running = true;
	lastping = time(0);

	return true;
}


void CServerContext::RemoveUser(CUser *user)
{
	gameserver->SendUserDisconnect(user->GetSteamID());

	clientSocketMap.erase( user->GetSocket() );
	clientSteamMap.erase( user->GetSteamID() );
	numClients--;

	delete user;
}

void CServerContext::SendPingRequest()
{
	NetServerPingRequest_t msg;
	msg.itemsTotal = 0;

	std::cout << "[SERVER] Ping?" << std::endl;

	SocketUserMap::iterator iter = clientSocketMap.begin();
	while(iter != clientSocketMap.end())
	{
		SNetSocket_t socket = iter->first;
		CUser *user = iter->second;

		if(user->GetPongTime() < lastping)
		{
			std::cout << "[SERVER] Dropping " << *user << " last reponse " << user->GetPongTime() << " / " << lastping << std::endl;

			// they haven't responded between the last ping and now
			iter = clientSocketMap.erase( iter );

			networking->DestroySocket(socket, false);
			RemoveUser(user);
			continue;
		}

		networking->SendDataOnSocket( socket, (void *)&msg, sizeof( NetServerPingRequest_t ), false );
		++iter;
	}

	lastping = time(0);
}

void CServerContext::Think()
{
	HandleNetworking();

	if(time(0) >= lastping + PING_INTERVAL)
		SendPingRequest();
}

void CServerContext::HandleNetworking()
{
	uint32 dataSize;
	SNetSocket_t socketFrom;

	if ( !networking->IsDataAvailable( serverSocket, &dataSize, &socketFrom ) )
		return;

	void *data = malloc( dataSize );

	if ( !networking->RetrieveDataFromSocket( socketFrom, data, dataSize, &dataSize ) )
	{
		std::cout << "[SERVER] Error reading data from socket." << std::endl;
		free( data );
		return;
	}

	if ( dataSize < sizeof( ENetworkMessage ) )
	{
		std::cout << "[SERVER] Garbage data received." << std::endl;
		free( data );
		return;
	}

	ENetworkMessage *netMessage = (ENetworkMessage *)data;

	switch ( *netMessage )
	{
	case eClientInitConnection:
		{
			NetServerSendInfo_t msg;

			msg.serverSteamID = gameserver->GetSteamID();
			msg.vacSecure = gameserver->Secure();

			networking->SendDataOnSocket( socketFrom, (void *)&msg, sizeof( NetServerSendInfo_t ), false );
		}
		break;

	case eClientAuth:
		HandleNetClientAuth( socketFrom, (NetClientAuth_t *)data );
		break;

	case eClientPingReply:
		HandleNetClientPingReply( socketFrom, (NetClientPingReply_t *)data );
		break;

	case eClientItemGranted:
		HandleNetClientItemGranted( socketFrom, (NetClientItemGranted_t *)data );
		break;

	default:
		std::cout << "[SERVER] Recieved garbage data." << std::endl;
		break;
	}


	free( data );
}

bool CServerContext::HandleCallback(const CallbackMsg_t &callback)
{
	switch(callback.m_iCallback)
	{
		case SteamServersConnected_t::k_iCallback:
			std::cout << "[SERVER] Connected to steam back-end." << std::endl;
			UpdateServerStatus();
			break;

		case SocketStatusCallback_t::k_iCallback:
			HandleCallbackSocketStatus( (SocketStatusCallback_t *)callback.m_pubParam );
			break;

		case GSPolicyResponse_t::k_iCallback:
			HandleCallbackPolicyResponse( (GSPolicyResponse_t *)callback.m_pubParam );
			break;

		case GSClientKick_t::k_iCallback:
			HandleCallbackClientKick( (GSClientKick_t *)callback.m_pubParam );
			break;

		case GSClientDeny_t::k_iCallback:
			HandleCallbackClientDeny( (GSClientDeny_t *)callback.m_pubParam );
			break;

		case GSClientApprove_t::k_iCallback:
			HandleCallbackClientApprove( (GSClientApprove_t *)callback.m_pubParam );
			break;

		case GSItemCount_t::k_iCallback:
			HandleCallbackItemCount( (GSItemCount_t *)callback.m_pubParam );
			break;

		case SteamAPICallCompleted_t::k_iCallback:
			break;

		default:
			return false;
	}
	return true;
}

void CServerContext::UpdateServerStatus()
{
	gameserver->UpdateServerStatus(numClients, MAX_CLIENTS, 0, "Team Fortress 2", "", "ctf_2fort");
	masterserver->SetBasicServerData(7, true, "255", "tf", MAX_CLIENTS, false, "Team Fortress");
}


void CServerContext::HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus )
{
	if ( pSocketStatus->m_hListenSocket != serverSocket )
		return;

	if ( pSocketStatus->m_eSNetSocketState >= k_ESNetSocketStateDisconnecting )
	{
		SocketUserMap::iterator iter = clientSocketMap.find( pSocketStatus->m_hSocket );
		if( iter != clientSocketMap.end() )
		{
			CUser *user = iter->second;
			std::cout << "[SERVER] Client " << *user << " has disconnected." << std::endl;

			RemoveUser(user);
		}

		return;
	}

	if ( pSocketStatus->m_eSNetSocketState == k_ESNetSocketStateConnected )
		return; // we can ignore these

	std::cout << "[SERVER] Socket " << pSocketStatus->m_hListenSocket << " is now in state: " << EnumString<ESNetSocketState>::From( (ESNetSocketState)pSocketStatus->m_eSNetSocketState ) << std::endl;
}

void CServerContext::HandleCallbackPolicyResponse( GSPolicyResponse_t *pPolicyResponse )
{
	bool vacSecure = !!pPolicyResponse->m_bSecure;
	std::cout << "  VAC Secure mode " << ( vacSecure ? "enabled" : "disabled" ) << "." << std::endl;
}
void CServerContext::HandleCallbackClientKick( GSClientKick_t *pClientKick )
{
	std::cout << "[SERVER] Back-end is requesting the kick of " << pClientKick->m_SteamID << ": " << EnumString<EDenyReason>::From( pClientKick->m_eDenyReason ) << std::endl;

	// kick the user?

}
void CServerContext::HandleCallbackClientDeny( GSClientDeny_t *pClientDeny )
{
	std::cout << "[SERVER] Back-end is denying " << pClientDeny->m_SteamID << ": " << EnumString<EDenyReason>::From( pClientDeny->m_eDenyReason ) << std::endl;
	std::cout << "  Message: " << pClientDeny->m_pchOptionalText << std::endl;

	// kick the user?
}
void CServerContext::HandleCallbackClientApprove( GSClientApprove_t *pClientApprove )
{
	std::cout << "[SERVER] Back-end approved " << pClientApprove->m_SteamID << std::endl;

	SteamUserMap::iterator iter = clientSteamMap.find( pClientApprove->m_SteamID );
	if( iter != clientSteamMap.end() )
	{
		CUser *user = iter->second;
		std::cout << "[SERVER] User " << *user << " was authed, updating user data." << std::endl;
		gameserver->UpdateUserData(user->GetSteamID(), user->GetUsername().c_str(), 0);

		gameserveritems->LoadItems(user->GetSteamID());
	}
}

void CServerContext::HandleCallbackItemCount( GSItemCount_t *pClientItems )
{
	SteamUserMap::iterator iter = clientSteamMap.find( pClientItems->m_steamID );
	if( iter != clientSteamMap.end() )
	{
		CUser *user = iter->second;
		std::cout << "[SERVER] Loaded items for " << *user << ", " << pClientItems->m_unCount << " items." << std::endl;
	}
}

void CServerContext::HandleNetClientAuth( SNetSocket_t clientSocket, NetClientAuth_t *pClientAuth )
{
	if( clientSocketMap.find( clientSocket ) != clientSocketMap.end() )
	{
		return;
	}

	if ( numClients >= MAX_CLIENTS )
	{
		NetServerConnectionDenied_t denyMsg;
		denyMsg.denyReason = EDenyServerFull;

		networking->SendDataOnSocket( clientSocket, (void *)&denyMsg, sizeof( denyMsg ), true );
		return;
	}

	uint32 clientIP;
	networking->GetSocketInfo( clientSocket, NULL, NULL, &clientIP, NULL );

	CSteamID clientSteamID;
	EConnectionDenyReason denyReason = EDenyAuthFailed;
	bool passedAuth = gameserver->SendUserConnectAndAuthenticate( clientIP, pClientAuth->authTicket, pClientAuth->ticketLen, &clientSteamID );

	if( clientSteamMap.find( clientSteamID ) != clientSteamMap.end() )
	{
		passedAuth = false;
		denyReason = EDenySteamIDExists;
	}

	if ( !passedAuth )
	{
		NetServerConnectionDenied_t denyMsg;
		denyMsg.denyReason = denyReason;

		networking->SendDataOnSocket( clientSocket, (void *)&denyMsg, sizeof( denyMsg ), true );

		return;
	}

	CUser *user = new CUser(clientSocket, clientSteamID, pClientAuth->username);

	clientSocketMap.insert( SocketUserMap::value_type( clientSocket, user ) );
	clientSteamMap.insert( SteamUserMap::value_type( user->GetSteamID(), user ) );
	numClients++;

	UpdateServerStatus();

	std::cout << "[SERVER] " << *user << " connected. Clients: " << numClients << ", Max Clients: " << MAX_CLIENTS << std::endl;

	NetServerClientAuthed_t authedMsg;
	strcpy( authedMsg.messageOfTheDay, "Welcome to the idler2 test server. Please report any bugs and issues to: VoiDeD @ irc.gamesurge.net / #opensteamworks" );

	networking->SendDataOnSocket( clientSocket, (void *)&authedMsg, sizeof( authedMsg ), true );
}

void CServerContext::HandleNetClientPingReply( SNetSocket_t clientSocket, NetClientPingReply_t *pClientPong )
{
	SocketUserMap::iterator iter = clientSocketMap.find( clientSocket );

	if( iter == clientSocketMap.end() )
		return;

	CUser *user = iter->second;
	user->PongResponse();

	std::cout << "[SERVER] User " << *user << ": Pong!" << std::endl;
}

void CServerContext::HandleNetClientItemGranted( SNetSocket_t clientSocket, NetClientItemGranted_t *pClientItemGranted )
{
	SocketUserMap::iterator iter = clientSocketMap.find( clientSocket );

	if( iter == clientSocketMap.end() )
		return;

	CUser *user = iter->second;

	std::string name = CItemDB::GetItemName(pClientItemGranted->itemid);

	NetServerYourItemWas_t itemResponse;
	strncpy(itemResponse.itemName, name.c_str(), sizeof(itemResponse.itemName));

	networking->SendDataOnSocket( clientSocket, (void *)&itemResponse, sizeof( itemResponse ), true );

	std::cout << "[SERVER] User " << *user << " got a " << name << " (" << pClientItemGranted->itemid << ")" << std::endl;
}

void CServerContext::End()
{
	SocketUserMap::iterator iter = clientSocketMap.begin();
	while( iter != clientSocketMap.end() )
	{
		SNetSocket_t socket = iter->first;
		CUser *user = iter->second;

		iter = clientSocketMap.erase( iter );

		networking->DestroySocket(socket, true);
		RemoveUser(user);
	}

	if(serverSocket)
		networking->DestroyListenSocket(serverSocket, true);

	if(masterserver)
		masterserver->SetActive(false);
	if(gameserver)
		gameserver->LogOff();

	if(user)
		client->ReleaseUser(pipe, user);
	if(pipe)
		client->ReleaseSteamPipe(pipe);
}
