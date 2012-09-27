#ifndef CSERVERCONTEXT_H
#define CSERVERCONTEXT_H

#define STEAMWORKS_CLIENT_INTERFACES
#define STEAM
#include "Steamworks.h"

#include <iostream>
#include <iomanip>


class CServerContext
{
public:
	CServerContext(ISteamClient008 *steamClient, IClientEngine *clientEngine);
	~CServerContext();

	void StartServer(uint16 listenPort, AppId_t appId);

	void HandleCallbacks();

	void HandleNetworking();

	void UpdateServerStatus();

	void RunFrame();

private:
	AppId_t serverAppId;

	HSteamPipe pipe;
	HSteamUser user;

	ISteamGameServer009 *gameServer;
	ISteamGameServerItems004 *serverItems;
	ISteamMasterServerUpdater001 *masterServer;

	ISteamNetworking003 *networking;
	SNetSocket_t serverSocket;

	IClientUtils *utils;

	bool clientConnected;
	CSteamID clientSteamID;
};

#endif CSERVERCONTEXT_H