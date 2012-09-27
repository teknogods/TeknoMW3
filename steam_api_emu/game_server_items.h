#ifndef __SERVER_ITEMS_H__
#define __SERVER_ITEMS_H__

#include "stdafx.h"
#include "winsock2.h"
#include "SDK\SteamAPI.h"
#include "SDK\SteamclientAPI.h"
#include <map>
#include <queue>
#include "../mw3_master_server/include/MasterServerProtocol.hpp"

using namespace std;

#define MW3_SERVER_4CC 'POOL'
#define MW3_SERVER_4CC_old 'POOP'
#define MW3_SERVER_4BB 'BOOB'
#define SERVER_INFORMER_PORT_RANGE 10
#define STATIC_SECURITY_KEY 0x31
#define MW3_GAME_BUILD_MOD 1

#pragma pack(1)
typedef struct _MW3_SERVER_QUERY {
	ULONG		Magic4CC;
	ULONG		TimeStamp;
} MW3_SERVER_QUERY, *PMW3_SERVER_QUERY;

typedef struct _MW3_MASTER_SERVER_UPDATE_MSG {
	ULONG		Magic4BB;
	DWORD		LongVersion;
	USHORT		QPort;
} MW3_MASTER_SERVER_UPDATE_MSG, *PMW3_MASTER_SERVER_UPDATE_MSG;

//typedef struct _MW3_SERVER_INFO {
//	ULONG		Magic4CC;
//	ULONG		TimeStamp;
//	char		MapName[32];
//	int			Players;
//	int			MaxPlayers;
//	bool		bPasswordProtected;
//	ULONG		bDedicated;
//	int			ServerVersion;
//	ULONGLONG	SteamId;
//	ULONG		GameIP_int;
//	ULONG		GameIP_ext;
//	USHORT		GamePort;
//	USHORT		QueryPort;
//	USHORT		NetPort;
//	char		ServerName[64];
//	char		ServerTags[256];
//	char		ServerInfos[1024];
//	char		SecID[8];
//	char		SecKey[16];
//} MW3_SERVER_INFO, *PMW3_SERVER_INFO;

#define MW3_SERVER_INFO_MAX_RAW_DATA_SIZE 2048

typedef struct _MW_SERVER_INFO_EX
{
	BYTE		unused;
} MW_SERVER_INFO_EX, *PMW_SERVER_INFO_EX;

typedef struct _MW3_SERVER_INFO {
	ULONG		Magic4CC;
	ULONG		TimeStamp;
	int			Players;
	int			MaxPlayers;
	bool		bPasswordProtected;
	ULONG		bDedicated;
	int			ServerVersion;
	ULONGLONG	SteamId;
	ULONG		GameIP_int;
	ULONG		GameIP_ext;
	USHORT		GamePort;
	USHORT		QueryPort;
	USHORT		NetPort;
	char		SecID[8];
	char		SecKey[16];

	WORD		MapName_ptr;
	WORD		ServerName_ptr;
	WORD		ServerTags_ptr;
	WORD		ServerInfos_ptr;

	WORD		RawDataSize;
	char		RawData[MW3_SERVER_INFO_MAX_RAW_DATA_SIZE];

} MW3_SERVER_INFO, *PMW3_SERVER_INFO;

#pragma pack()

class ServerItem 
{
public:
	ServerItem() {
		memset(&m_lastServerInfo, 0, sizeof(MW3_SERVER_INFO));
	}
	~ServerItem() {}

	virtual bool initialize(PMW3_SERVER_INFO serverInfo, DWORD arrival);
	virtual bool updateServer(PMW3_SERVER_INFO serverInfo, DWORD arrival);
	virtual DWORD getServerExternalIp();
	virtual DWORD getServerInternalIp();
	virtual bool getServerDedicatedMode();
	virtual USHORT getServerExternalPort();
	virtual USHORT getServerInternalPort();
	virtual char * ServerItem::getServerSecKey();
	virtual char * ServerItem::getServerSecId();
	virtual void getServerChallenge(PVOID pChallenge);
	virtual void fillGameServerItem(gameserveritem_t* pItem);
	virtual gameserveritem_t * getGameServerItem();
	virtual char * ServerItem::getServerInfos();
	virtual int getServerIndex();
	virtual void setServerIndex(int index);
protected:
	MW3_SERVER_INFO m_lastServerInfo;
	ULONG			m_ping;
	gameserveritem_t m_gameServerItem;
	int				ServerIndex;
};

class ServerList
{
public:
	ServerList() : m_sock(INVALID_SOCKET), m_bInitialized(false), m_bRunThread(false), m_pMasterResponse(NULL), m_bThreadStopped(true) {
		InitializeCriticalSection(&m_queueProtection);
		InitializeCriticalSection(&m_refreshProtection);
	}
	~ServerList() {
		if(m_pMasterResponse != NULL)
		{
			free(m_pMasterResponse);
			m_pMasterResponse = NULL;
		}
	};

	static ServerList* getInstance() {
		if(s_pInstance == NULL)
		{
			s_pInstance = new ServerList();
			s_pInstance->initialize();
		}

		return s_pInstance;
	}

	static void deleteSingleton() {
		if(s_pInstance != NULL)
		{
			delete s_pInstance;
			s_pInstance = NULL;
		}
	}


	virtual void sendLocalBroadcast(ISteamMatchmakingServerListResponse* pResponse);
	virtual int getServerCount();
	virtual bool getGameServerItem(int serverIndex, gameserveritem_t* pItem);
	void stopThread();
	virtual void * createConnectionBlob(ULONG ipAddr, USHORT port, bool ServerItemMustExist);
	virtual void startConnBlobLoaderThread(void * blob);
	virtual ServerItem* getServerItemByAddress(ULONG ipAddr, USHORT port);
	virtual ServerItem* getServerItemByIndex(int serverIndex);

	virtual void sendInternetListMulticast(ISteamMatchmakingServerListResponse* pResponse);	
	//virtual void simpleRefresh();

	//Favorities
	virtual bool addFavoriteGame(DWORD ip, USHORT port);
	virtual bool removeFavoriteGame(DWORD ip, USHORT port);
	virtual bool refreshFavoriteGames();

	//History
	virtual bool addHistoryGame(DWORD ip, USHORT port);
	virtual bool refreshHistoryGames();

	//Official TK servers
	virtual bool refreshOfficialGames();


protected:
	typedef struct _SERVERQUERY_QUEUEITEM {
		SOCKADDR_IN		address;
		DWORD			arrivalTime;
		MW3_SERVER_INFO	serverInfo;
	} SERVERQUERY_QUEUEITEM, *PSERVERQUERY_QUEUEITEM;

	static ServerList*						s_pInstance;
	static bool								m_bBlobLoadInProgress;
	SOCKET									m_sock;
	bool									m_bInitialized;
	volatile bool							m_bRunThread;
	volatile bool							m_bThreadStopped;
	volatile bool							m_bHandlerThreadStopped;
	map<ULONGLONG, ServerItem*>				m_List;
	ISteamMatchmakingServerListResponse*	m_responseInterface;
	PMW3_MS_CLIENT_RESPONSE					m_pMasterResponse;
	queue<SERVERQUERY_QUEUEITEM*>			m_queue;
	CRITICAL_SECTION						m_queueProtection;
	CRITICAL_SECTION						m_refreshProtection;

	void initialize();
	static DWORD WINAPI recvThread(LPVOID lpParameter);
	static DWORD WINAPI blobThread(LPVOID lpParameter);
	static DWORD WINAPI refreshInternetListThread(LPVOID lpParameter);
	static DWORD WINAPI refreshLanListThread(LPVOID lpParameter);
	static DWORD WINAPI serverQueryHandlerThread(LPVOID lpParameter);

	void startThread();
	void cleanList();

	//Master Server
	virtual bool refreshFromMasterServer();

};



class ServerInformer
{
public:
	ServerInformer() :m_sock(INVALID_SOCKET), m_bInitialized(false), m_bRunThread(false) {}
	~ServerInformer() {}

	static ServerInformer* getInstance() {
		if(s_pInstance == NULL)
		{
			s_pInstance = new ServerInformer();
		}

		return s_pInstance;
	}

	static void deleteSingleton() {
		if(s_pInstance != NULL)
		{
			delete s_pInstance;
			s_pInstance = NULL;
		}
	}

	bool initialize(CSteamID* steamId);
	void start();
	void stop();
	void updateServer(int cPlayers, int cPlayersMax, const char *pchServerName, const char *pchMapName);
	void setGameTags(const char *pchGameTags);
	void setServerType(uint32 unGameIP, uint16 unGamePort, uint16 usQueryPort, const char *pchVersion, bool bLANMode);
	void updateOnMasterServer();
private:
	static ServerInformer*	s_pInstance;
	SOCKET					m_sock;
	MW3_SERVER_INFO			m_serverInfo;
	char					m_ServerTags[512];
	bool					m_bInitialized;
	MW3_MS_SERVER_REQUEST	m_updateMsg;
	volatile bool		m_bRunThread;

	static DWORD WINAPI recvThread(LPVOID lpParameter);
	void startThread();
	void stopThread();
};

extern unsigned char ConnBlob_skeleton[0x60];
extern USHORT g_MasterPort;
extern DWORD g_MasterIp;


extern char g_ServerKeyId[8];
extern char g_ServerKey[16];


//DWORD WINAPI  nettest(LPVOID param);


#endif //__SERVER_ITEMS_H__
