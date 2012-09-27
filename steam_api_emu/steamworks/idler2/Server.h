#ifndef SERVER_H
#define SERVER_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>

#include <Steamworks.h>

#include "Common.h"
#include "NetMessages.h"


struct ClientData_t
{
	bool active;

	CSteamID steamID;
	time_t lastPing;

	SNetSocket_t clientSocket;
};

class CServer
{
public:
	CServer();
	virtual ~CServer();

	bool Initialize( CreateInterfaceFn clientFactory );

	bool StartServer( uint16 port, uint32 maxPlayers );


	void RunFrame();


private:
	void HandleCallbacks();
	void HandleNetworking();

	// callback handlers
	void HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus );
	void HandleCallbackPolicyResponse( GSPolicyResponse_t *pPolicyResponse );
	void HandleCallbackClientKick( GSClientKick_t *pClientKick );
	void HandleCallbackClientDeny( GSClientDeny_t *pClientDeny );
	void HandleCallbackClientApprove( GSClientApprove_t *pClientApprove );
	void HandleCallbackDefault( CallbackMsg_t *pCallBack );

	// network handling
	void HandleNetClientAuth( SNetSocket_t clientSocket, NetClientAuth_t *pClientAuth );


private:
	ISteamClient008 *steamClient;

	HSteamPipe pipe;
	HSteamUser user;

	ISteamGameServer009 *gameServer;
	ISteamGameServerItems004 *serverItems;

	ISteamNetworking002 *networking;
	SNetSocket_t serverSocket;

	bool vacSecure;

	uint32 maxClients;

	ClientData_t clients[MAX_CLIENTS];
};



#endif // SERVER_H
