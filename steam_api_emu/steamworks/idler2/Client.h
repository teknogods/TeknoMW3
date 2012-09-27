#ifndef CLIENT_H
#define CLIENT_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

#include <Steamworks.h>

#include "Common.h"
#include "NetMessages.h"


class CClient
{
public:
	CClient();
	~CClient();

	bool Initialize( CreateInterfaceFn clientFactory );

	bool Connect( uint32 ip, uint16 port );

	void RunFrame();


	bool IsRunning() { return running; }

private:
	void HandleCallbacks();
	void HandleNetworking();

	// callback handlers
	void HandleCallbackSocketStatus( SocketStatusCallback_t *pSocketStatus );
	void HandleCallbackDefault( CallbackMsg_t *pCallBack );

	// network handlers
	void HandleNetConnectionDenied( NetServerConnectionDenied_t *pConnectionDenied );
	void HandleNetSendInfo( NetServerSendInfo_t *pSendInfo );
	void HandleNetClientAuthed( NetServerClientAuthed_t *pClientAuthed );
	void HandleNetClientKicked( NetServerClientKicked_t *pClientKicked );


private:
	bool running;

	ISteamClient008 *steamClient;

	HSteamPipe pipe;
	HSteamUser user;

	ISteamUser012 *steamUser;
	ISteamUserItems003 *userItems;

	ISteamNetworking002 *networking;
	SNetSocket_t clientSocket;

	uint32 remoteIp;
	uint16 remotePort;
};


#endif // CLIENT_H