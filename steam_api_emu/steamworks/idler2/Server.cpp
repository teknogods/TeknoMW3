
#include "Server.h"

CServer::CServer()
{
	steamClient = NULL;

	pipe = 0;
	user = 0;

	gameServer = NULL;
	serverItems = NULL;

	networking = NULL;
	serverSocket = 0;

	maxClients = 0;

	memset( &clients, 0, sizeof( clients ) );

}

CServer::~CServer()
{
	std::cout << "[SERVER] Server shutting down..." << std::endl;
	for ( uint32 i = 0; i < maxClients; ++i )
	{
		if ( clients[i].active )
		{
			std::cout << "#" << i << " is active, kicking..." << std::endl;

			NetServerClientKicked_t kickedMsg;

			strcpy( kickedMsg.kickMessage, "Server shutting down." );

			networking->SendDataOnSocket( clients[i].clientSocket, (void *)&kickedMsg, sizeof( kickedMsg ), true );
		}
	}

	if ( gameServer )
		gameServer->LogOff();

	Sleep( 1000 ); // wait for network data to send through

	for ( uint32 i = 0; i < maxClients; ++i )
	{
		if ( clients[i].active )
			networking->DestroySocket( clients[i].clientSocket, true );
	}

	if ( serverSocket )
		networking->DestroyListenSocket( serverSocket, true );
}

bool CServer::Initialize( CreateInterfaceFn clientFactory )
{
	std::cout << "[SERVER] Initializing server..." << std::endl;

	steamClient = (ISteamClient008 *)clientFactory( STEAMCLIENT_INTERFACE_VERSION_008, NULL );
	if ( !steamClient )
	{
		std::cout << "CServer::Initialize() - Unable to get ISteamClient." << std::endl;
		return false;
	}

	user = steamClient->CreateLocalUser( &pipe, k_EAccountTypeGameServer );
	if ( !user || !pipe )
	{
		std::cout << "CServer::Initialize() - Unable to create local user." << std::endl;
		return false;
	}

	networking = (ISteamNetworking002 *)steamClient->GetISteamNetworking( user, pipe, STEAMNETWORKING_INTERFACE_VERSION_002 );
	if ( !networking )
	{
		std::cout << "CServer::Initialize() - Unable to get ISteamNetworking." << std::endl;
		return false;
	}

	gameServer = (ISteamGameServer009 *)steamClient->GetISteamGameServer( user, pipe, STEAMGAMESERVER_INTERFACE_VERSION_009 );
	if ( !gameServer )
	{
		std::cout << "CServer::Initialize() - Unable to get ISteamGameServer." << std::endl;
		return false;
	}

	serverItems = (ISteamGameServerItems004 *)steamClient->GetISteamGenericInterface( user, pipe, STEAMGAMESERVERITEMS_INTERFACE_VERSION_004 );
	if ( !serverItems)
	{
		std::cout << "CServer::Initialize() - Unable to get ISteamGameServerItems." << std::endl;
		return false;
	}

	std::cout << "[SERVER] Done!" << std::endl;

	return true;
}

bool CServer::StartServer( uint16 port, uint32 maxPlayers )
{
	maxClients = maxPlayers;

	std::cout << "[SERVER] Starting server..." << std::endl;

	serverSocket = networking->CreateListenSocket( 0, 0, port, false );
	if ( !serverSocket )
	{
		std::cout << "CServer::StartServer() - Unable to create listen socket." << std::endl;
		return false;
	}

	gameServer->SetGameType("arena");

	bool serverInit = gameServer->SetServerType(
		k_unServerFlagDedicated | k_unServerFlagActive | k_unServerFlagLinux | k_unServerFlagSecure,
		INADDR_ANY,
		port,
		0, port - 1,
		"tf",
		"1.0.7.1",
		false
	);

	if ( !serverInit )
	{
		std::cout << "CServer::StartServer() - Unable to set server type." << std::endl;
		return false;
	}

	gameServer->LogOn();

	std::cout << "[SERVER] Done!" << std::endl;

	return true;
}


void CServer::RunFrame()
{
	HandleCallbacks();

	HandleNetworking();
}

void CServer::HandleCallbacks()
{
	CallbackMsg_t callBack;
	HSteamCall steamCall;

	// todo: switch this over to registered callbacks
	if ( Steam_BGetCallback( pipe, &callBack, &steamCall ) )
	{
		switch ( callBack.m_iCallback )
		{
		case SteamServersConnected_t::k_iCallback:
			std::cout << "[SERVER] Connected to steam back-end." << std::endl;
			break;

		case SocketStatusCallback_t::k_iCallback:
			HandleCallbackSocketStatus( (SocketStatusCallback_t *)callBack.m_pubParam );
			break;

		case GSPolicyResponse_t::k_iCallback:
			HandleCallbackPolicyResponse( (GSPolicyResponse_t *)callBack.m_pubParam );
			break;

		case GSClientKick_t::k_iCallback:
			HandleCallbackClientKick( (GSClientKick_t *)callBack.m_pubParam );
			break;

		case GSClientDeny_t::k_iCallback:
			HandleCallbackClientDeny( (GSClientDeny_t *)callBack.m_pubParam );
			break;

		case GSClientApprove_t::k_iCallback:
			HandleCallbackClientApprove( (GSClientApprove_t *)callBack.m_pubParam );
			break;

		default:
			HandleCallbackDefault( &callBack );
			break;

		}


		Steam_FreeLastCallback( pipe );
	}
}

void CServer::HandleNetworking()
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

			msg.serverSteamID = gameServer->GetSteamID().ConvertToUint64();
			msg.vacSecure = gameServer->Secure();

			networking->SendDataOnSocket( socketFrom, (void *)&msg, sizeof( NetServerSendInfo_t ), false );
		}
		break;

	case eClientAuth:
		HandleNetClientAuth( socketFrom, (NetClientAuth_t *)data );
		break;
	}


	free( data );
}


void CServer::HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus )
{
	// only want to handle callbacks for our listener
	if ( pSocketStatus->m_hListenSocket != serverSocket )
		return;

	if ( pSocketStatus->m_eSNetSocketState >= k_ESNetSocketStateDisconnecting )
	{
		for ( uint32 i = 0; i < maxClients; ++i )
		{
			if ( !clients[i].active )
				continue;

			if ( clients[i].clientSocket == pSocketStatus->m_hSocket )
			{
				gameServer->SendUserDisconnect( clients[i].steamID );

				std::cout << "[SERVER] Client " << clients[i].steamID.Render() << " has disconnected." << std::endl;

				// clear out client data
				memset( &clients[i], 0, sizeof( ClientData_t ) );
			}
		}

		return;
	}


	std::cout << "[SERVER] Socket " << pSocketStatus->m_hListenSocket << " is now in state: " << EnumString<ESNetSocketState>::From( (ESNetSocketState)pSocketStatus->m_eSNetSocketState ) << std::endl;
}


void CServer::HandleCallbackPolicyResponse( GSPolicyResponse_t *pPolicyResponse )
{
	vacSecure = !!pPolicyResponse->m_bSecure;
	std::cout << "  VAC Secure mode " << ( vacSecure ? "enabled" : "disabled" ) << "." << std::endl;
}
void CServer::HandleCallbackClientKick( GSClientKick_t *pClientKick )
{
	std::cout << "[SERVER] Back-end is requesting the kick of " << pClientKick->m_SteamID.Render() << ": " << EnumString<EDenyReason>::From( pClientKick->m_eDenyReason ) << std::endl;

	// kick the user?

}
void CServer::HandleCallbackClientDeny( GSClientDeny_t *pClientDeny )
{
	std::cout << "[SERVER] Back-end is denying " << pClientDeny->m_SteamID.Render() << ": " << EnumString<EDenyReason>::From( pClientDeny->m_eDenyReason ) << std::endl;
	std::cout << "  Message: " << pClientDeny->m_pchOptionalText << std::endl;

	// kick the user?
}
void CServer::HandleCallbackClientApprove( GSClientApprove_t *pClientApprove )
{
	std::cout << "[SERVER] Back-end approved " << pClientApprove->m_SteamID.Render() << std::endl;
}

void CServer::HandleCallbackDefault( CallbackMsg_t *pCallBack )
{
	using namespace std;

	int32 callBack = pCallBack->m_iCallback;
	ECallbackType type = (ECallbackType)((callBack / 100) * 100);

	cout << "[SERVER] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << pCallBack->m_cubParam << endl;

	unsigned char *data = pCallBack->m_pubParam;

	cout << "  ";

	for (int i = 0; i < pCallBack->m_cubParam; i++)
	{
		unsigned char value = data[i];
	
		cout << hex << setw(2) << setfill('0') << uppercase << (unsigned int)value;
		cout << " ";
	}

	cout << resetiosflags(ios_base::hex | ios_base::uppercase) << endl;
}

void CServer::HandleNetClientAuth( SNetSocket_t clientSocket, NetClientAuth_t *pClientAuth )
{
	for ( uint32 i = 0; i < maxClients; ++i )
	{
		if ( clients[i].clientSocket == clientSocket )
		{
			// this client is already logged on, so we ignore the auth
			return;
		}
	}

	uint32 currentClients = 0;
	for ( uint32 i = 0; i < maxClients; ++i )
	{
		if ( clients[i].active )
			currentClients++;
	}

	if ( currentClients >= maxClients )
	{
		NetServerConnectionDenied_t denyMsg;
		denyMsg.denyReason = EDenyServerFull;

		networking->SendDataOnSocket( clientSocket, (void *)&denyMsg, sizeof( denyMsg ), true );
		return;
	}

	for ( uint32 i = 0; i < maxClients; ++i )
	{
		if ( !clients[i].active )
		{
			clients[i].clientSocket = clientSocket;
			clients[i].lastPing = time( 0 );

			uint32 clientIP = 0;
			networking->GetSocketInfo( clientSocket, NULL, NULL, &clientIP, NULL );

			CSteamID clientSteamID;
			EConnectionDenyReason denyReason = EDenyAuthFailed;
			bool passedAuth = gameServer->SendUserConnectAndAuthenticate( clientIP, pClientAuth->authTicket, pClientAuth->ticketLen, &clientSteamID );

			// check the steamid to see if it's already connected to us
			for ( uint32 x = 0; x < maxClients; ++x )
			{
				if ( !clients[x].active )
					continue;

				if ( clients[x].steamID == clientSteamID )
				{
					passedAuth = false;
					denyReason = EDenySteamIDExists;
				}
			}

			if ( !passedAuth )
			{
				NetServerConnectionDenied_t denyMsg;
				denyMsg.denyReason = denyReason;

				networking->SendDataOnSocket( clientSocket, (void *)&denyMsg, sizeof( denyMsg ), true );

				return;
			}

			clients[i].active = passedAuth;
			clients[i].steamID = clientSteamID;

			break;
		}
	}

	currentClients++;
	std::cout << "# Clients: " << currentClients << ", Max Clients: " << maxClients << std::endl;

	NetServerClientAuthed_t authedMsg;
	strcpy( authedMsg.messageOfTheDay, "Welcome to the idler2 beta test server. Admin contact: irc.gamesurge.net / #opensteamworks" );

	networking->SendDataOnSocket( clientSocket, (void *)&authedMsg, sizeof( authedMsg ), true );
}



int main( int argc, char *argv[] )
{
	unsigned short port = DEFAULT_PORT;

	if ( argc >= 2 )
	{
		if ( ( port = atoi( argv[1] ) ) == 0 )
			port = DEFAULT_PORT;
	}

	std::cout << "Initializing SteamAPI..." << std::endl;
	if ( !SteamAPI_Init() )
	{
		std::cout << "Fatal Error: Unable to init SteamAPI." << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Done!" << std::endl;

	CreateInterfaceFn clientFactory = Sys_GetFactory( "steamclient" );
	if ( !clientFactory )
	{
		std::cout << "Fatal Error: Unable to get steamclient factory." << std::endl;
		return EXIT_FAILURE;
	}

	CServer *server = new CServer;
	if ( !server->Initialize( clientFactory ) )
		return EXIT_FAILURE;

	if ( !server->StartServer( port, 3 ) )
		return EXIT_FAILURE;


	while ( !GetAsyncKeyState( VK_ESCAPE ) ) // todo: better quit logic
	{
		server->RunFrame();

		Sleep( 5 ); // todo: implement a better way not to use 100% CPU
	}

	delete server;

	return EXIT_SUCCESS;
}