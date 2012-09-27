
#include "Client.h"

//-----------------------------------------------------------------------------
// Purpose:
//		   
//-----------------------------------------------------------------------------
CClient::CClient()
{
	running = false;

	steamClient = NULL;

	pipe = 0;
	user = 0;

	steamUser = NULL;
	userItems = NULL;

	remoteIp = 0;
	remotePort = 0;
}

//-----------------------------------------------------------------------------
// Purpose:
//		   
//-----------------------------------------------------------------------------
CClient::~CClient()
{
}

//-----------------------------------------------------------------------------
// Purpose:
//		   
//-----------------------------------------------------------------------------
bool CClient::Initialize( CreateInterfaceFn clientFactory )
{
	std::cout << "[CLIENT] Initializing client..." << std::endl;

	steamClient = (ISteamClient008 *)clientFactory( STEAMCLIENT_INTERFACE_VERSION_008, NULL );
	if ( !steamClient )
	{
		std::cout << "CClient::Initialize() - Unable to get ISteamClient." << std::endl;
		return false;
	}

	pipe = steamClient->CreateSteamPipe();
	if ( !pipe )
	{
		std::cout << "CClient::Initialize() - Unable to create steam pipe." << std::endl;
		return false;
	}

	user = steamClient->ConnectToGlobalUser( pipe );
	if ( !user )
	{
		std::cout << "CClient::Initialize() - Unable to connect to global user." << std::endl;
		return false;
	}

	networking = (ISteamNetworking002 *)steamClient->GetISteamNetworking( user, pipe, STEAMNETWORKING_INTERFACE_VERSION_002 );
	if ( !networking )
	{
		std::cout << "CClient::Initialize() - Unable to get ISteamNetworking." << std::endl;
		return false;
	}

	steamUser = (ISteamUser012 *)steamClient->GetISteamUser( user, pipe, STEAMUSER_INTERFACE_VERSION_012 );
	if ( !steamUser )
	{
		std::cout << "CClient::Initialize() - Unable to get ISteamUser." << std::endl;
		return false;
	}

	userItems = (ISteamUserItems003 *)steamClient->GetISteamGenericInterface( user, pipe, STEAMUSERITEMS_INTERFACE_VERSION_003 );
	if ( !userItems )
	{
		std::cout << "CClient::Initialize() - Unable to get ISteamUserItems." << std::endl;
		return false;
	}

	std::cout << "[CLIENT] Done!" << std::endl;

	return true;
}

//-----------------------------------------------------------------------------
// Purpose:
//		   
//-----------------------------------------------------------------------------
bool CClient::Connect( uint32 ip, uint16 port )
{
	this->remoteIp = ip;
	this->remotePort = port;

	clientSocket = networking->CreateConnectionSocket( ip, port, 20 );
	if ( !clientSocket )
	{
		std::cout << "CClient::Connect() - Unable to create connection socket." << std::endl;
		return false;
	}

	running = true;

	return true;
}

//-----------------------------------------------------------------------------
// Purpose: Runs one network and callback frame
//		   
//-----------------------------------------------------------------------------
void CClient::RunFrame()
{
	HandleCallbacks();

	HandleNetworking();
}

//-----------------------------------------------------------------------------
// Purpose: Handles one incomming callback
//		   
//-----------------------------------------------------------------------------
void CClient::HandleCallbacks()
{
	CallbackMsg_t callBack;
	HSteamCall steamCall;

	if ( Steam_BGetCallback( pipe, &callBack, &steamCall ) )
	{
		switch ( callBack.m_iCallback )
		{

		case SocketStatusCallback_t::k_iCallback:
			HandleCallbackSocketStatus( (SocketStatusCallback_t *)callBack.m_pubParam );
			break;

		case PersonaStateChange_t::k_iCallback:
			break; // not interested in this callback

		default:
			HandleCallbackDefault( &callBack );
			break;

		}
		Steam_FreeLastCallback( pipe );
	}
}

//-----------------------------------------------------------------------------
// Purpose: Handles one network packet
//		   
//-----------------------------------------------------------------------------
void CClient::HandleNetworking()
{
	uint32 dataSize;

	if ( !networking->IsDataAvailableOnSocket( clientSocket, &dataSize ) )
		return; // no data waiting

	void *data = malloc( dataSize );

	if ( !networking->RetrieveDataFromSocket( clientSocket, data, dataSize, &dataSize ) )
	{
		// data is waiting, but we're unable to read it

		free( data );

		return;
	}

	ENetworkMessage *eMsg = (ENetworkMessage *)data;

	switch ( *eMsg )
	{

		case eServerConnectionDenied:
			HandleNetConnectionDenied( (NetServerConnectionDenied_t *)data );
			break;

		case eServerSendInfo:
			HandleNetSendInfo( (NetServerSendInfo_t *)data );
			break;

		case eServerClientAuthed:
			HandleNetClientAuthed( (NetServerClientAuthed_t *)data );
			break;

		case eServerClientKicked:
			HandleNetClientKicked( (NetServerClientKicked_t *)data );
			break;

	}

	free( data );
}

//-----------------------------------------------------------------------------
// Purpose: 
//		   
//-----------------------------------------------------------------------------
void CClient::HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus )
{
	// handle various client socket situations
	switch ( pSocketStatus->m_eSNetSocketState )
	{

	case k_ESNetSocketStateTimeoutDuringConnect:
		// connection timeout to destination server, so we exit out
		running = false;
		std::cout << "CClient::HandleSocketStatusCallback() - Unable to connect to destination server." << std::endl;
		break;

	case k_ESNetSocketStateConnected:
		{
			std::cout << "[CLIENT] Connected to server, initiating handshake..." << std::endl;
			// we've connected, lets start our data handshake
			NetClientInitConnection_t msg;
			networking->SendDataOnSocket( clientSocket, (void *)&msg, sizeof( msg ), false );
		}
		break;

	case k_ESNetSocketStateConnectionBroken:
	case k_ESNetSocketStateRemoteEndDisconnected:
		std::cout << "[CLIENT] Lost connection to remote server." << std::endl;
		running = false;

		break;

	default:
		std::cout << "[CLIENT] Socket " << pSocketStatus->m_hListenSocket << " is now " << EnumString<ESNetSocketState>::From( (ESNetSocketState)pSocketStatus->m_eSNetSocketState ) << std::endl;
		break;

	}
}

//-----------------------------------------------------------------------------
// Purpose: Handle an unknown or uncaught callback
//		   
//-----------------------------------------------------------------------------
void CClient::HandleCallbackDefault( CallbackMsg_t *pCallBack )
{
	// this is an unknown callback, so lets dump the data for easier debugging

	using namespace std;

	int32 callBack = pCallBack->m_iCallback;
	ECallbackType type = (ECallbackType)((callBack / 100) * 100);

	cout << "[CLIENT] Unhandled Callback: " << callBack << ", Type: " << EnumString<ECallbackType>::From( type ) << ", Size: " << pCallBack->m_cubParam << endl;

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

//-----------------------------------------------------------------------------
// Purpose:
//		   
//-----------------------------------------------------------------------------
void CClient::HandleNetConnectionDenied( NetServerConnectionDenied_t *pConnectionDenied )
{
	// handle various denial reasons
	switch ( pConnectionDenied->denyReason )
	{

	case EDenyServerFull:
		std::cout << "[CLIENT] Connection denied to server: Server is full." << std::endl;
		running = false;
		break;

	case EDenySteamIDBanned:
		std::cout << "[CLIENT] Connection denied to server: You are banned." << std::endl;
		running = false;
		break;

	case EDenyAuthFailed:
		std::cout << "[CLIENT] Connection denied to server: Authentication failure." << std::endl;
		running = false;
		break;

	case EDenySteamIDExists:
		std::cout << "[CLIENT] Connection denied to server: SteamID is already present on server." << std::endl;
		running = false;
		break;

	default:
		std::cout << "[CLIENT] Connection denied to server, but an invalid reason (" << pConnectionDenied->denyReason << ") was supplied." << std::endl;
		std::cout << "  Your client is out of date." << std::endl;
		running = false;
		break;

	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//		   
//-----------------------------------------------------------------------------
void CClient::HandleNetSendInfo( NetServerSendInfo_t *pSendInfo )
{
	// should maybe store this server info somewhere?
	std::cout << "[CLIENT] Recieved server details. SteamID: " << pSendInfo->serverSteamID << ", VAC Secure: " << pSendInfo->vacSecure << std::endl;

	std::cout << "[CLIENT] Authenticating with server..." << std::endl;

	NetClientAuth_t auth;
	auth.ticketLen = steamUser->InitiateGameConnection( (void *)&auth.authTicket, AUTHTICKET_SIZE, CSteamID( pSendInfo->serverSteamID ), remoteIp, remotePort, pSendInfo->vacSecure );

	if ( !auth.ticketLen )
	{
		// if InitiateGameConnection fails, we bail out
		std::cout << "CClient::HandleNetSendInfo() - InitiateGameConnection failed." << std::endl;
		running = false;
		return;
	}
	
	if ( !networking->SendDataOnSocket( clientSocket, (void *)&auth, sizeof( auth ), false ) )
	{
		// connection was interrupted during the authentication process
		std::cout << "CClient::HandleNetSendInfo() - Unable to send authticket to server." << std::endl;
		running = false;
		return;
	}
}

void CClient::HandleNetClientAuthed( NetServerClientAuthed_t *pClientAuthed )
{
	std::cout << "[CLIENT] Authentication completed." << std::endl;
	std::cout << "[CLIENT]   MOTD: " << pClientAuthed->messageOfTheDay << std::endl;
}

void CClient::HandleNetClientKicked( NetServerClientKicked_t *pClientKicked )
{
	// we've been kicked from the server, so we destroy our socket
	networking->DestroySocket( clientSocket, false );

	std::cout << "[CLIENT] You have been kicked from the server: " << pClientKicked->kickMessage << std::endl;
	
	running = false;

	return;
}

void PrintUsage()
{
	std::cout << std::endl << "Usage:" << std::endl;
	std::cout << "client <ip> [port]" << std::endl;
}

int main( int argc, char *argv[] )
{
	unsigned int ip = 0;

	if ( argc < 2 )
	{
		std::cout << "Error, no IP specified." << std::endl;
		PrintUsage();
		return EXIT_FAILURE;
	}

	ip = htonl( inet_addr( argv[1] ) );
	if ( ip == INADDR_ANY || ip == INADDR_NONE )
	{
		std::cout << "Error, invalid IP." << std::endl;
		PrintUsage();
		return EXIT_FAILURE;
	}

	unsigned short port = DEFAULT_PORT;

	if ( argc >= 3 )
	{
		if ( ( port = atoi( argv[2] ) ) == 0 )
			port = DEFAULT_PORT;
	}

	std::cout << "Initializing SteamAPI..." << std::endl;
	// this will find and load steamclient.dll for us
	if ( !SteamAPI_Init() )
	{
		std::cout << "Fatal Error: Unable to init SteamAPI." << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "Done!" << std::endl;

	CreateInterfaceFn clientFactory = Sys_GetFactory( "steamclient" );
	if ( !clientFactory )
	{
		// shouldn't ever happen, but if it does...
		std::cout << "Fatal Error: Unable to get steamclient factory." << std::endl;
		return EXIT_FAILURE;
	}

	CClient client;
	if ( !client.Initialize( clientFactory ) )
		return EXIT_FAILURE;
	
	if ( !client.Connect( ip, port ) )
		return EXIT_FAILURE;

	while ( client.IsRunning() )
	{
		client.RunFrame();

		Sleep( 5 );
	}

	return EXIT_SUCCESS;
}