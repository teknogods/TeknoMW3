#define STEAMWORKS_CLIENT_INTERFACES
#define STEAM
#include "Steamworks.h"

#include "Util.h" // ShowError, ObtainSteamDirectory
#include "NetMessages.h"
#include "CServerContext.h"
#include "CClientContext.h"

#include <fstream>
#include <shlwapi.h>

#pragma comment(lib, "shlwapi")
#pragma comment(lib, "ws2_32")
#pragma comment(lib, "..\\steamclient")

#define APPID 440
#define LISTEN_PORT 27015

CreateInterfaceFn ClientFactory;

int main()
{
	std::ofstream appIdFile;
	appIdFile.open( "steam_appid.txt" );
	appIdFile << APPID;
	appIdFile.flush();
	appIdFile.close();

	std::string steamDirectory = ObtainSteamFolder();

	// this block does nothing if not using runtime linkage
	std::cout << "Loading libraries from '" << steamDirectory << "'... ";
	SetDllDirectory( steamDirectory.c_str() );

	ClientFactory = Sys_GetFactory( "steamclient" );
	if ( !ClientFactory )
	{

		ShowError( "Unable to load steamclient library, exiting..." );

	}

	std::cout << "Done!" << std::endl;

	std::cout << "Getting root interfaces... ";

	int error;
	ISteamClient008 *steamClient = (ISteamClient008 *) ClientFactory( STEAMCLIENT_INTERFACE_VERSION_008, &error );
	if ( error == IFACE_FAILED )
	{

		ShowError("Unable to get ISteamClient.");

	}

	IClientEngine *engine = (IClientEngine *) ClientFactory( CLIENTENGINE_INTERFACE_VERSION, &error );
	if ( error == IFACE_FAILED )
	{

		ShowError("Unable to get IClientEngine.");

	}

	std::cout << "Done!" << std::endl;

	CServerContext server( steamClient, engine );
	server.StartServer( LISTEN_PORT, APPID );

	CClientContext client( steamClient, engine );

	// !!!!!!!!!!!! HEY YOU !!!!!!!!!!!!!!!!!!!!!!!!
	// THIS IS IMPORTANT LOOK HERE
	//
	// CHANGE THIS IP TO YOUR EXTERNAL IP IF YOU WANT TO BE VISIBLE ON FRIENDS
	// OTHERWISE USE 127.0.0.1
	uint32 ip = htonl(inet_addr("127.0.0.1"));

	unsigned int tickCount = 0;

	while ( true )
	{
		server.RunFrame();
		client.RunFrame();

		// hackhack: this gives the server some time to get the steam connection callback
		if ( tickCount == 500 )
		{

			client.Connect( ip, LISTEN_PORT, APPID );

		}

		tickCount++;

		Sleep( 1 );
	}

	return 0;
}
