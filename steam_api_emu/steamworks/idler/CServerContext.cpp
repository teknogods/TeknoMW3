
#include "CServerContext.h"
#include "Util.h"
#include "NetMessages.h"

CServerContext::CServerContext(ISteamClient008 *steamClient, IClientEngine *clientEngine)
{
	clientConnected = false;

	std::cout << "[SERVER] Initializing... ";

	pipe = steamClient->CreateSteamPipe();
	if (!pipe)
		ShowError("Steam pipe could not be created.");

	user = steamClient->CreateLocalUser(&pipe, k_EAccountTypeGameServer);
	if (!user)
		ShowError("Steam user could not be created.");

	utils = clientEngine->GetIClientUtils(pipe, CLIENTUTILS_INTERFACE_VERSION);
	if (!utils)
		ShowError("Unable to get IClientUtils.");

	networking = (ISteamNetworking003 *)steamClient->GetISteamNetworking(user, pipe, STEAMNETWORKING_INTERFACE_VERSION_003);
	if (!networking)
		ShowError("Unable to get ISteamNetworking.");

	gameServer = (ISteamGameServer009 *)steamClient->GetISteamGameServer(user, pipe, STEAMGAMESERVER_INTERFACE_VERSION_009);
	if (!gameServer)
		ShowError("Unable to get ISteamGameServer.");

	serverItems = (ISteamGameServerItems004 *)steamClient->GetISteamGenericInterface(user, pipe, STEAMGAMESERVERITEMS_INTERFACE_VERSION_004);
	if (!serverItems)
		ShowError("Unable to get ISteamGameServerItems.");

	masterServer = (ISteamMasterServerUpdater001 *)steamClient->GetISteamMasterServerUpdater(user, pipe, STEAMMASTERSERVERUPDATER_INTERFACE_VERSION_001);
	if (!masterServer)
		ShowError("Unable to get ISteamMasterServerUpdater.");

	utils = (IClientUtils *)clientEngine->GetIClientUtils(pipe, CLIENTUTILS_INTERFACE_VERSION);
	if (!utils)
		ShowError("Unable to get IClientUtils.");

	std::cout << "Done!" << std::endl;
}

CServerContext::~CServerContext()
{
	masterServer->SetActive(false);

	gameServer->LogOff();

	if (serverSocket)
	{
		networking->DestroyListenSocket(serverSocket, true);
	}
}

void CServerContext::StartServer(uint16 listenPort, AppId_t appId)
{
	serverAppId = appId;

	std::cout << "[SERVER] Starting... ";

	utils->SetAppIDForCurrentPipe(appId);
	if (utils->GetAppID() != appId)
		ShowError("Unable to set pipe AppID.");

	gameServer->SetGameType("arena");

	bool serverInit = gameServer->SetServerType(
		k_unServerFlagDedicated | k_unServerFlagActive | k_unServerFlagLinux | k_unServerFlagSecure,			// flags
		INADDR_ANY,					// bind address
		8887,						// game port
		0, 8888,					// query spectate ports
		"tf",						// game dir
		"1.0.7.1",					// version
		false						// lan mode
	);

	if (!serverInit)
		ShowError("Unable to initialize server settings.");

	masterServer->SetBasicServerData(
		7,
		true,
		"255",
		"tf",
		2,
		false,
		"Team Fortress"
	);

	masterServer->SetActive(true);

	// logon!
	gameServer->LogOn();

	serverSocket = networking->CreateListenSocket(0, 0, listenPort, false);
	if (!serverSocket)
		ShowError("Unable to create listen socket.");

	std::cout << "Done!" << std::endl;
}

void CServerContext::HandleCallbacks()
{
	CallbackMsg_t callbackMsg;
	HSteamCall steamCall;

	if (Steam_BGetCallback(pipe, &callbackMsg, &steamCall))
	{
		switch (callbackMsg.m_iCallback)
		{
		case SteamServersConnected_t::k_iCallback:
			std::cout << "[SERVER] Connected to steam back-end." << std::endl;
			UpdateServerStatus();

			break;

		case SocketStatusCallback_t::k_iCallback:
			{
				SocketStatusCallback_t *sockStatus = (SocketStatusCallback_t *)callbackMsg.m_pubParam;
				std::cout << "[SERVER] Socket status: " << EnumString<ESNetSocketState>::From((ESNetSocketState)sockStatus->m_eSNetSocketState) << std::endl;
				break;
			}
		case SteamAPICallCompleted_t::k_iCallback: // this will be recieved when the item count callback finishes
			{
				SteamAPICallCompleted_t *steamCall =  (SteamAPICallCompleted_t *)callbackMsg.m_pubParam;

				std::cout << "[SERVER] Async call completed: " << steamCall->m_hAsyncCall << std::endl;
				break;
			}
		case GSItemCount_t::k_iCallback:
			{
				GSItemCount_t *itemCount = (GSItemCount_t *)callbackMsg.m_pubParam;
				std::cout << "[SERVER] Item count recieved. Result: " << EnumString<EItemRequestResult>::From(itemCount->m_eResult) << 
					"\n\t SteamID: " << itemCount->m_steamID.Render() << ", Count: " << itemCount->m_unCount << std::endl;

				break;
			}
		case GSClientApprove_t::k_iCallback:
			{
				GSClientApprove_t *approve = (GSClientApprove_t *)callbackMsg.m_pubParam;
				std::cout << "[SERVER] Back-end approved: " << approve->m_SteamID.Render() << std::endl;

				// lets get our client's item count
				SteamAPICall_t asyncCall = serverItems->GetItemCount(approve->m_SteamID);
				std::cout << "[SERVER] Requesting client's items. Async Call: " << asyncCall << std::endl;
				break;
			}

		case GSClientDeny_t::k_iCallback:
			{
				GSClientDeny_t *deny = (GSClientDeny_t *)callbackMsg.m_pubParam;
				std::cout << "[SERVER] Back-end denied: " << deny->m_SteamID.Render() << ", Reason: " << EnumString<EDenyReason>::From(deny->m_eDenyReason) << ", Message: " << deny->m_pchOptionalText << std::endl;
				break;
			}
		case GSClientKick_t::k_iCallback:
			{
				GSClientKick_t *kick = (GSClientKick_t *)callbackMsg.m_pubParam;
				std::cout << "[SERVER] Back-end requesting client kick of " << kick->m_SteamID.Render() << ", Reason: " << EnumString<EDenyReason>::From(kick->m_eDenyReason) << std::endl;
				break;
			}

		case GSPolicyResponse_t::k_iCallback:
			{
				GSPolicyResponse_t *policy = (GSPolicyResponse_t *)callbackMsg.m_pubParam;
				std::cout << "[SERVER] Policy response recieved. Secure: " << (int)policy->m_bSecure << std::endl;
				break;
			}

		default:
			int32 callBack = callbackMsg.m_iCallback;
			ECallbackType type = (ECallbackType)((callBack / 100) * 100);
			std::cout << "[SERVER] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From(type) << ", Size: " << callbackMsg.m_cubParam << std::endl;

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

void CServerContext::HandleNetworking()
{
	uint32 size;
	SNetSocket_t socketFrom;
	if (!networking->IsDataAvailable(serverSocket, &size, &socketFrom))
		return;

	void *data = malloc(size);
	ENetworkMessages eMessage;

	if (!networking->RetrieveDataFromSocket(socketFrom, data, size, &size))
	{
		std::cout << "[SERVER] Error reading data from socket." << std::endl;
		free(data);
		return;
	}

	eMessage = *((ENetworkMessages *)data);
	switch (eMessage)
	{
	case eClientInitConnection:
		{
			CSteamID remoteId;
			int status;
			uint32 ip;
			uint16 port;
			networking->GetSocketInfo(socketFrom, &remoteId, &status, &ip, &port);

			NetServerInfo_t reply;
			reply.serverSteamID = gameServer->GetSteamID().ConvertToUint64();
			reply.vacSecure = gameServer->Secure();

			in_addr addr;
			addr.S_un.S_addr = htonl(ip);

			char *ipStr = inet_ntoa(addr);

			std::cout << "[SERVER] Client connecting. IP: " << ipStr << 
				"\n\t SteamID: " << remoteId.Render() << ", Port: " << port << std::endl;

			networking->SendDataOnSocket(socketFrom, (char*)&reply, sizeof(reply), false);

			break;
		}

	case eClientAuth:
		{
			NetClientAuthentication_t clientAuth = *((NetClientAuthentication_t *)data);
			std::cout << "[SERVER] Client authenticating. Ticket Length: " << clientAuth.ticketLen << std::endl;

			CSteamID remoteId;
			int status;
			uint32 ip;
			uint16 port;
			networking->GetSocketInfo(socketFrom, &remoteId, &status, &ip, &port);

			in_addr addr;
			addr.S_un.S_addr = htonl(ip);

			char *ipStr = inet_ntoa(addr);

			std::cout << "[SERVER] Running auth check on " << remoteId.Render() << ", IP: " << ipStr << std::endl;
			bool basicAuth = gameServer->SendUserConnectAndAuthenticate(ip, clientAuth.authTicket, clientAuth.ticketLen, &remoteId);

			if (!basicAuth)
				std::cout << "[SERVER] WARNING: Client failed basic auth checks." << std::endl;

			uint32 liCheck = gameServer->UserHasLicenseForApp(remoteId, serverAppId);
			std::cout << "[SERVER] License check for " << remoteId.Render() << ": " << liCheck << std::endl;

			clientConnected = true;
			clientSteamID = remoteId;
			break;
		}
	}

	free(data);
}

void CServerContext::UpdateServerStatus()
{

	gameServer->UpdateServerStatus(
		1,
		4,
		0,
		"Team Fortress 2",
		"",
		"ctf_2fort"
	);

	if (clientConnected)
	{
		bool update = gameServer->UpdateUserData(clientSteamID, "VoiDeD", 1);
		if (!update)
			std::cout << "[SERVER] Client connected, but the server is unable to update user data." << std::endl;
	}

	gameServer->SetGameType("arena");

	masterServer->SetBasicServerData(
		7,
		true,
		"255",
		"tf",
		2,
		false,
		"Team Fortress"
	);

}

void CServerContext::RunFrame()
{
	HandleCallbacks();

	HandleNetworking();

	UpdateServerStatus();
}