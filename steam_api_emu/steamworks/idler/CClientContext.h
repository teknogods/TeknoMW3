#ifndef CCLIENTCONTEXT_H
#define CCLIENTCONTEXT_H

#define STEAMWORKS_CLIENT_INTERFACES
#define STEAM
#include "Steamworks.h"

class CClientContext
{
public:
	CClientContext(ISteamClient008 *steamClient, IClientEngine *clientEngine);

	void Connect(uint32 ip, uint16 port, AppId_t appId);

	void OnSocketCallback(CallbackMsg_t &callbackMsg);
	void OnPersonaChange(CallbackMsg_t &callbackMsg);
	void OnItemGranted(CallbackMsg_t &callbackMsg);

	void HandleCallbacks();
	void HandleNetworking();

	void RunFrame();

private:
	HSteamPipe pipe;
	HSteamUser user;

	ISteamFriends005 *friends;

	ISteamUser012 *clientUser;
	ISteamUserItems003 *userItems;

	ISteamNetworking003 *networking;
	SNetSocket_t clientSocket;
	bool connected;

	uint32 remoteIp;
	uint16 remotePort;

	IClientUtils *utils;
};

#endif // CCLIENTCONTEXT_H