
#include "CClientContext.h"
#include "NetMessages.h"
#include "Util.h"

#include <iostream>
#include <iomanip>


CClientContext::CClientContext(ISteamClient008 *steamClient, IClientEngine *clientEngine)
{
	connected = false;

	std::cout << "[CLIENT] Initializing... ";

	pipe = steamClient->CreateSteamPipe();
	if (!pipe)
		ShowError("Steam pipe could not be created.");

	user = steamClient->ConnectToGlobalUser(pipe);
	if (!user)
		ShowError("Steam user could not be created.");

	friends = (ISteamFriends005 *)steamClient->GetISteamFriends(user, pipe, STEAMFRIENDS_INTERFACE_VERSION_005);
	if (!friends)
		ShowError("Unable to get ISteamFriends.");

	clientUser = (ISteamUser012 *)steamClient->GetISteamUser(user, pipe, STEAMUSER_INTERFACE_VERSION_012);
	if (!clientUser)
		ShowError("Unable to get ISteamUser.");

	userItems = (ISteamUserItems003 *)steamClient->GetISteamGenericInterface(user, pipe, STEAMUSERITEMS_INTERFACE_VERSION_003);
	if (!userItems)
		ShowError("Unable to get ISteamUserItems.");

	networking = (ISteamNetworking003 *)steamClient->GetISteamNetworking(user, pipe, STEAMNETWORKING_INTERFACE_VERSION_003);
	if (!networking)
		ShowError("Unable to get ISteamNetworking.");

	utils = (IClientUtils *)clientEngine->GetIClientUtils(pipe, CLIENTUTILS_INTERFACE_VERSION);
	if (!utils)
		ShowError("Unable to get IClientUtils.");

	std::cout << "Done!" << std::endl;
}

void CClientContext::Connect(uint32 ip, uint16 port, AppId_t appId)
{
	utils->SetAppIDForCurrentPipe(appId);
	if (utils->GetAppID() != appId)
		ShowError("Unable to set pipe AppID.");

	clientSocket = networking->CreateConnectionSocket(ip, port, 10);

	remoteIp = ip;
	remotePort = port;
}

void CClientContext::OnSocketCallback(CallbackMsg_t &callbackMsg)
{
	SocketStatusCallback_t *sockStatus = (SocketStatusCallback_t *)callbackMsg.m_pubParam;

	if (sockStatus->m_eSNetSocketState == k_ESNetSocketStateConnected)
	{
		connected = true;

		// might as well confirm our own item details
		SteamAPICall_t asyncCall = userItems->GetItemCount();
		std::cout << "[CLIENT] Requesting own items. Async Call: " << asyncCall << std::endl;

		// if we connected, lets begin our data connection
		NetClientInitConnection_t msg;
		networking->SendDataOnSocket(clientSocket, (char *)&msg, sizeof(msg), false);
	}
}

void CClientContext::OnPersonaChange(CallbackMsg_t &callbackMsg)
{
	PersonaStateChange_t *persona = (PersonaStateChange_t *)callbackMsg.m_pubParam;

	// only handle our own persona changes
	if (persona->m_ulSteamID != clientUser->GetSteamID().ConvertToUint64())
		return;

	// game started
	if (persona->m_nChangeFlags & k_EPersonaChangeGamePlayed)
	{
		FriendGameInfo_t friendInfo;

		if (!friends->GetFriendGamePlayed(persona->m_ulSteamID, &friendInfo))
			return;

		const char *friendName = friends->GetFriendPersonaName(persona->m_ulSteamID);

		std::cout << "[CLIENT] " << friendName << " (" << CSteamID(persona->m_ulSteamID).Render() << ") is now playing: " << friendInfo.m_gameID.AppID() << std::endl;
	}

	// joined server
	if (persona->m_nChangeFlags & k_EPersonaChangeGameServer)
	{
		FriendGameInfo_t friendInfo;

		if (!friends->GetFriendGamePlayed(persona->m_ulSteamID, &friendInfo))
			return;

		const char *friendName = friends->GetFriendPersonaName(persona->m_ulSteamID);

		in_addr addr;
		addr.S_un.S_addr = htonl(friendInfo.m_unGameIP);

		char *ipStr = inet_ntoa(addr);

		std::cout << "[CLIENT] " << friendName << " (" << CSteamID(persona->m_ulSteamID).Render() << ") is now playing on server: " << ipStr << std::endl;
	}
}
void CClientContext::OnItemGranted(CallbackMsg_t &callbackMsg)
{
	UserItemGranted_t *itemGranted = (UserItemGranted_t *)callbackMsg.m_pubParam;

	std::cout << "[CLIENT] ITEM GRANTED!! Item ID: " << itemGranted->m_itemID << ", Game ID: " << itemGranted->m_gameID.AppID() << std::endl;
}


void CClientContext::HandleCallbacks()
{
	CallbackMsg_t callbackMsg;
	HSteamCall steamCall;

	if (Steam_BGetCallback(pipe, &callbackMsg, &steamCall))
	{
		switch (callbackMsg.m_iCallback)
		{
		case SocketStatusCallback_t::k_iCallback:
			OnSocketCallback(callbackMsg);
			break;

		case PersonaStateChange_t::k_iCallback:
			OnPersonaChange(callbackMsg);
			break;

		case SteamAPICallCompleted_t::k_iCallback: // this will be recieved when the item count callback finishes
			{
				SteamAPICallCompleted_t *steamCall =  (SteamAPICallCompleted_t *)callbackMsg.m_pubParam;

				std::cout << "[CLIENT] Async call completed: " << steamCall->m_hAsyncCall << std::endl;
				break;
			}
		case UserItemCount_t::k_iCallback:
			{
				UserItemCount_t *itemCount = (UserItemCount_t *)callbackMsg.m_pubParam;
				std::cout << "[CLIENT] Item count recieved. Result: " << EnumString<EItemRequestResult>::From(itemCount->m_eResult) << 
					"\n\t GameID: " << itemCount->m_gameID.AppID() << ", Count: " << itemCount->m_unCount << std::endl;

				break;
			}

		case UserItemGranted_t::k_iCallback:
			OnItemGranted(callbackMsg);
			break;

		default:
			int32 callBack = callbackMsg.m_iCallback;
			ECallbackType type = (ECallbackType)((callBack / 100) * 100);
			std::cout << "[CLIENT] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;

			int32 callSize = callbackMsg.m_cubParam;
			unsigned char *data = callbackMsg.m_pubParam;
			std::cout << "  ";
			for (int i = 0; i < callSize; i++)
			{
				unsigned char value = data[i];
			
				std::cout << std::hex << std::setw(2) << std::setfill('0') << std::uppercase << (unsigned int)value;
				std::cout << " ";
			}

			std::cout << std::resetiosflags(std::ios_base::hex | std::ios_base::uppercase) << std::endl;
		}

		Steam_FreeLastCallback(pipe);
	}
}

void CClientContext::HandleNetworking()
{
	if (!connected)
		return;

	uint32 size;
	if(!networking->IsDataAvailableOnSocket(clientSocket, &size))
		return;
	
	void *data = malloc(size);
	uint32 realSize; // how much data we really need

	if (!networking->RetrieveDataFromSocket(clientSocket, data, size, &realSize))
	{
		free(data);
		return; // nothing waiting
	}

	if (realSize > size)
	{
		// didn't have enough space, lets re-allocate how much we need
		data = realloc(data, realSize);
		size = realSize;

		networking->RetrieveDataFromSocket(clientSocket, data, size, &size);
	}

	ENetworkMessages *eMsg = (ENetworkMessages *)data;

	switch (*eMsg)
	{
	case eServerSendInfo:
		NetServerInfo_t *serverInfo = (NetServerInfo_t *)data;
		std::cout << "[CLIENT] Server sent details. SteamID: " << serverInfo->serverSteamID << ", VAC Secure: " << serverInfo->vacSecure << std::endl;

		in_addr addr;
		addr.S_un.S_addr = htonl(remoteIp);

		char *ipStr = inet_ntoa(addr);

		std::cout << "[CLIENT] Initiating game connection to " << ipStr << ":" << remotePort << std::endl;
		NetClientAuthentication_t auth;
		auth.ticketLen = clientUser->InitiateGameConnection((void*)&auth.authTicket, 2048, CSteamID(serverInfo->serverSteamID), remoteIp, remotePort, serverInfo->vacSecure);

		networking->SendDataOnSocket(clientSocket, (void*)&auth, sizeof(auth), false);
		break;
	}

	free(data);
}

void CClientContext::RunFrame()
{
	// process any recieved callbacks this frame
	HandleCallbacks();

	// run networking events
	HandleNetworking();
}