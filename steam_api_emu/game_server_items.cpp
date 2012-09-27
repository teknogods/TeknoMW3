#include "stdafx.h"
#include "game_server_items.h"
#include "util.h"
#include "game_dvar_base.h"
#include "game_patch_base.h"
#include "steam_api_emu.h"
#include "steam_api_emu_misc.h"
#include "VMProtectSDK.h"
#include "..\mw3_master_server\include\MasterServerProtocol.hpp"

#pragma optimize("", off)

short browser_qport = (GetCurrentProcessId() % 400) + 28599;


USHORT g_MasterPort = 0;
DWORD g_MasterIp = 0;

unsigned char ConnBlob_skeleton[0x60] = // 'le ticket blob
{
    0xFF, 0xF1, 0x01, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x44, 0x46, 0x8B, 0x1D,
	0xFA, 0x17, 0xD3, 0x47, 0x83, 0xC6, 0x6A, 0x2B, 0xE4, 0x3A, 0xAC, 0x45, 0x70, 0xAB, 0xB2, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x12, 0x00, 0x70, 0xAB, 0xB2, 0x01,
} ;


char g_ServerKeyId[8];
char g_ServerKey[16];

bool ServerItem::initialize(PMW3_SERVER_INFO serverInfo, DWORD arrival)
{
	if(serverInfo->Magic4CC != MW3_SERVER_4CC)
	{
		return false;
	}

	if( arrival == 0 )
	{
		m_ping = GetTickCount() - serverInfo->TimeStamp;
	}
	else
	{
		m_ping = arrival - serverInfo->TimeStamp;
	}

	m_lastServerInfo = *serverInfo;
	return true;
}

bool ServerItem::updateServer(PMW3_SERVER_INFO serverInfo, DWORD arrival)
{
	return initialize(serverInfo, arrival);
}

DWORD ServerItem::getServerExternalIp()
{
	return m_lastServerInfo.GameIP_int;
}

DWORD ServerItem::getServerInternalIp()
{
	return m_lastServerInfo.GameIP_ext;
}

USHORT ServerItem::getServerExternalPort()
{
	return m_lastServerInfo.NetPort;
}

USHORT ServerItem::getServerInternalPort()
{
	return m_lastServerInfo.NetPort;
}

char * ServerItem::getServerSecKey()
{
	return m_lastServerInfo.SecKey;
}

char * ServerItem::getServerSecId()
{
	return m_lastServerInfo.SecID;
}

bool ServerItem::getServerDedicatedMode()
{
	return m_lastServerInfo.bDedicated;
}

char * ServerItem::getServerInfos()
{
	return &m_lastServerInfo.RawData[m_lastServerInfo.ServerInfos_ptr];
}

void ServerItem::getServerChallenge(PVOID pChallenge)
{
	return;
}

void ServerItem::fillGameServerItem( gameserveritem_t* pItem )
{	VM("fillGameServerItem");

	pItem->m_bHadSuccessfulResponse = true;
	pItem->m_bPassword = m_lastServerInfo.bPasswordProtected;
	//lets imagine global bans equal VAC secure, mmkay?
	pItem->m_bSecure = g_GlobalBans; 
	pItem->m_NetAdr.Init(getServerInternalIp(), m_lastServerInfo.QueryPort, getServerInternalPort());

	pItem->m_nMaxPlayers = m_lastServerInfo.MaxPlayers;

	pItem->m_bDoNotRefresh = false;
	pItem->m_nBotPlayers = 0;

	if (m_ping > 1199)
		m_ping = 1199;

	pItem->m_nPing = m_ping;
	pItem->m_nPlayers = m_lastServerInfo.Players;
	strcpy(pItem->m_szGameDir, V("modernwarfare3"));
	strcpy(pItem->m_szGameDescription, V("MW3 Game Description"));
	pItem->m_steamID.SetFromUint64(m_lastServerInfo.SteamId);
	pItem->m_nServerVersion = m_lastServerInfo.ServerVersion;
	pItem->m_nAppID = g_AppID;

	pItem->SetName(&m_lastServerInfo.RawData[m_lastServerInfo.ServerName_ptr]);
	strcpy(pItem->m_szMap, &m_lastServerInfo.RawData[m_lastServerInfo.MapName_ptr]);
	strcpy(pItem->m_szGameTags, &m_lastServerInfo.RawData[m_lastServerInfo.ServerTags_ptr]);
	info("tags %s", pItem->m_szGameTags);


	VE();
}

gameserveritem_t * ServerItem::getGameServerItem()
{
	fillGameServerItem(&m_gameServerItem);

	return &m_gameServerItem;
}

ServerList* ServerList::s_pInstance = NULL;

void ServerList::initialize()
{	VM("ServerList::initialize");

	if(!m_bInitialized)
	{
		m_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(INVALID_SOCKET == m_sock)
		{
			info("ERROR: Could not initialize a socket\n");
			return;
		}

		if (g_IpList.iAddressCount != 0)
		{
			for (int i = 0; i < g_IpList.iAddressCount; i++)
			{
			}
		}

		sockaddr_in service;
		service.sin_family = AF_INET;
		service.sin_addr.s_addr = GetInternalIP(); //GetInternalIP(); // htonl(INADDR_ANY); //
		service.sin_port = htons(browser_qport);
		USHORT i = 0;
		int res = bind(m_sock, (SOCKADDR*)&service, sizeof(service));
		while((SOCKET_ERROR == res) && (WSAGetLastError() == WSAEADDRINUSE) && (browser_qport + i++ < 0xFFFF))
		{
			service.sin_port = htons(browser_qport + i);
			res = bind(m_sock, (SOCKADDR*)&service, sizeof(service));
			Sleep(1);
		}
		if(SOCKET_ERROR == res)
		{
			closesocket(m_sock);
			info("ERROR: Could not bind the socket\n");
			return;
		}
		u_long iMode=1;
		// Enabling non-blocking mode for the socket
		ioctlsocket(m_sock, FIONBIO, &iMode);
		// Enabling broadcast option for the socket
		setsockopt(m_sock, SOL_SOCKET, SO_BROADCAST, (char*)&iMode, sizeof(char));
		
		m_bInitialized = true;
	}

	VE();
}

DWORD WINAPI ServerList::recvThread(LPVOID lpParameter)
{
	ServerList* pThis = (ServerList*)lpParameter;
	pThis->m_bThreadStopped = false;
	CreateThread(NULL, 0, serverQueryHandlerThread, pThis, 0, NULL);
	char* recvBuf = new char[0x2000];
	pThis->cleanList();
	ULONG serverIndex = 0;
	ULONG startTime = GetTickCount();
	info("ServerList::recvThread(): start\n");
	while(pThis->m_bRunThread && (startTime + 10000) > GetTickCount())
	{
		memset(recvBuf, 0, 0x2000);

		sockaddr_in senderAddr;
		int senderAddrSize = sizeof(senderAddr);
		int dataLen = recvfrom(pThis->m_sock, recvBuf, sizeof(MW3_SERVER_INFO), 0, (SOCKADDR*)&senderAddr, &senderAddrSize);
		if(dataLen != SOCKET_ERROR && dataLen >= sizeof(MW3_SERVER_INFO)-MW3_SERVER_INFO_MAX_RAW_DATA_SIZE)
		{
			info("ServerList::recvThread(): received packet\n");
			PMW3_SERVER_INFO pServerInfo = (PMW3_SERVER_INFO)recvBuf;
			if(pServerInfo->Magic4CC == MW3_SERVER_4CC)
			{
				info("ServerList::recvThread(): got server item\n");
				PSERVERQUERY_QUEUEITEM pNewItem = new SERVERQUERY_QUEUEITEM;
				pNewItem->address = senderAddr;
				pNewItem->serverInfo = *pServerInfo;
				pNewItem->arrivalTime = GetTickCount();
				EnterCriticalSection(&pThis->m_queueProtection);
				pThis->m_queue.push(pNewItem);
				LeaveCriticalSection(&pThis->m_queueProtection);
			}
		}

		Sleep(1);
	}

	info("ServerList::recvThread(): end\n");
	delete [] recvBuf;
	pThis->m_bRunThread = false;
	pThis->m_responseInterface->RefreshComplete(pThis, (pThis->m_List.empty() ? EMatchMakingServerResponse::eNoServersListedOnMasterServer : eServerResponded));

	while (!pThis->m_bHandlerThreadStopped)
	{
		info("trying to stop m_bHandlerThread thread...");
		Sleep(10);
	}

	pThis->m_bThreadStopped = true;

	return 0;
}


DWORD WINAPI ServerList::serverQueryHandlerThread(LPVOID lpParameter)
{	VM("ServerList::serverQueryHandlerThread");


	ServerList* pThis = (ServerList*)lpParameter;
	pThis->m_bHandlerThreadStopped = false;
	while(pThis->m_bRunThread || !pThis->m_queue.empty())
	{
		EnterCriticalSection(&pThis->m_queueProtection);

		if(!pThis->m_queue.empty())
		{
			// Handle items
			PSERVERQUERY_QUEUEITEM & pItem = pThis->m_queue.front();
			//LeaveCriticalSection(&pThis->m_queueProtection);

			map<ULONGLONG, ServerItem*>::iterator itr;// = pThis->m_List.find();
			DWORD index = 0;
			ULONGLONG key = pItem->address.sin_addr.S_un.S_addr | (pItem->serverInfo.NetPort * 0x100000000);
			for(itr = pThis->m_List.begin(); itr != pThis->m_List.end(); itr++, index++)
			{
				if(itr->first == key)
				{
					break;
				}
			}

			if(itr != pThis->m_List.end())
			{
				itr->second->updateServer(&pItem->serverInfo, pItem->arrivalTime);
				info("KNOWN server responded");
				//pThis->m_responseInterface->ServerResponded(itr->second, itr->second->getServerIndex());
			}
			else
			{
				//index++;
				if (pItem->serverInfo.SecID[0] == STATIC_SECURITY_KEY)
				{
					ServerItem* newItem = new ServerItem();
					newItem->setServerIndex(index);
					newItem->initialize(&pItem->serverInfo, pItem->arrivalTime);
					pThis->m_List.insert(std::make_pair(key, newItem));
					info("NEW server responded");
					pThis->m_responseInterface->ServerResponded(newItem, index);
				}
				else
				{
					info("OLD-TYPE server responded");
				}

			}

			//EnterCriticalSection(&pThis->m_queueProtection);
			pThis->m_queue.pop();
			delete pItem;
		}

		LeaveCriticalSection(&pThis->m_queueProtection);
		Sleep(1);
	}

	pThis->m_bHandlerThreadStopped = true;
	return 0;
	VE();
}





void ServerList::startThread()
{
	if(!m_bRunThread)
	{
		m_bRunThread = true;
		CreateThread(NULL, 0, recvThread, this, 0, NULL);
	}
}

void ServerList::stopThread()
{
	m_bRunThread = false;
	while(!m_bThreadStopped && !m_bHandlerThreadStopped)
	{
		info("trying to stop threads...");
		Sleep(10);
	}
}

bool ServerList::m_bBlobLoadInProgress = false;

DWORD WINAPI ServerList::blobThread(LPVOID lpParameter)
{	VM("ServerList::blobThread");

	m_bBlobLoadInProgress = true;
	Sleep(3000);

	#ifdef DEBUGGING_ENABLED
	LoadBlob(0x12121212, 0x13131313, V("HostUser"), lpParameter, 0x60);
	#else
	LoadBlob(GetTickCount(), !GetTickCount(), V("HostUser"), lpParameter, 0x60);
	#endif

	m_bBlobLoadInProgress = false;
	return 0;

	VE();
}

void ServerList::startConnBlobLoaderThread(void * blob)
{
	while (m_bBlobLoadInProgress)
		Sleep(500);

	CreateThread(NULL, 0, blobThread, blob, 0, NULL);
}





DWORD WINAPI ServerList::refreshLanListThread(LPVOID lpParameter)
{	VM("ServerList::refreshLanListThread");

	ServerList* pThis = (ServerList*)lpParameter;
	EnterCriticalSection(&pThis->m_refreshProtection);

	MW3_SERVER_QUERY query = {0};
	sockaddr_in s;
	s.sin_family = AF_INET;

	dvar qport_dvar(V("net_masterServerPort"));
	USHORT queryPort = qport_dvar.GetValueDW() & 0xFFFF;
	s.sin_addr.s_addr = htonl(INADDR_BROADCAST); //



	query.Magic4CC = MW3_SERVER_4CC;
	pThis->startThread();
	for(int i = 0; i <= SERVER_INFORMER_PORT_RANGE; i++)
	{
		info("Sending LAN broadcast for port %d", queryPort+i);

		s.sin_port = htons(queryPort+i);
		query.TimeStamp = GetTickCount();
		int ret = sendto(pThis->m_sock, (char*)&query, sizeof(query), 0, (SOCKADDR*)&s, sizeof(s));
		while(ret == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK)
		{
			info("ServerList::refreshLanListThread() send failed. resending\n");
			query.TimeStamp = GetTickCount();
			ret = sendto(pThis->m_sock, (char*)&query, sizeof(query), 0, (SOCKADDR*)&s, sizeof(s));
			Sleep(1);
		}
		if(ret == SOCKET_ERROR)
		{
			info("ServerList::refreshLanListThread() send failed. Error %d\n", WSAGetLastError());
		}
		Sleep(1);
	}

	LeaveCriticalSection(&pThis->m_refreshProtection);
	return 0;

	VE();
}



DWORD WINAPI ServerList::refreshInternetListThread(LPVOID lpParameter)
{	VM("ServerList::refreshInternetListThread");

	ServerList* pThis = (ServerList*)lpParameter;

	EnterCriticalSection(&pThis->m_refreshProtection);

	dvar net_source("ui_netSource");
	//0:Local
	//1:Internet
	//2:Favourites
	//3:History
	//4:Friends
	info("net source = %d", net_source.GetValueDW());

	bool refresh = false;

	switch(net_source.GetValueDW())
	{
	case 1:
		refresh = pThis->refreshFromMasterServer();
		break;
	case 2:
		refresh = pThis->refreshFavoriteGames();
		break;
	case 3:
		refresh = pThis->refreshHistoryGames();
		break;
	case 4:
		refresh = pThis->refreshOfficialGames();
		break;
	default:
		LeaveCriticalSection(&pThis->m_refreshProtection);
		return 0;
	}

	if(!refresh)
	{
		pThis->m_responseInterface->RefreshComplete(pThis, EMatchMakingServerResponse::eNoServersListedOnMasterServer);
		LeaveCriticalSection(&pThis->m_refreshProtection);
		return 0;
	}

	MW3_SERVER_QUERY query = {0};
	sockaddr_in s;
	s.sin_family = AF_INET;
	query.Magic4CC = MW3_SERVER_4CC;
	pThis->startThread();
	for(int i=0; i < pThis->m_pMasterResponse->NumberOfEntries; i++)
	{
		s.sin_port = htons(pThis->m_pMasterResponse->Entries[i].QPort);
		s.sin_addr.s_addr = htonl(pThis->m_pMasterResponse->Entries[i].IpAddress);
		query.TimeStamp = GetTickCount();
		int ret = sendto(pThis->m_sock, (char*)&query, sizeof(query), 0, (SOCKADDR*)&s, sizeof(s));
		Sleep(1);
		ret = sendto(pThis->m_sock, (char*)&query, sizeof(query), 0, (SOCKADDR*)&s, sizeof(s));

		int rep = 5;
		while(ret == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK && rep != 0)
		{
			info("ServerList::refreshInternetListThread() send failed. resending\n");
			query.TimeStamp = GetTickCount();
			ret = sendto(pThis->m_sock, (char*)&query, sizeof(query), 0, (SOCKADDR*)&s, sizeof(s));
			rep--;
			Sleep(5);
		}
		if(ret == SOCKET_ERROR)
		{
			info("ServerList::refreshInternetListThread() send failed. Error %d\n", WSAGetLastError());
		}
		info("Sent query to client %d (%08X, %d).", i, pThis->m_pMasterResponse->Entries[i].IpAddress, pThis->m_pMasterResponse->Entries[i].QPort);
		Sleep(1);
	}

	LeaveCriticalSection(&pThis->m_refreshProtection);
	return 0;

	VE();
}


bool ServerList::refreshFromMasterServer()
{	VM("ServerList::refreshFromMasterServer");

	if(!m_bInitialized)
	{
		initialize();
	}
	
	if(m_pMasterResponse != NULL)
	{
		free(m_pMasterResponse);
		m_pMasterResponse = NULL;
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in masterAddr;
	masterAddr.sin_family = AF_INET;
	masterAddr.sin_port = htons(g_MasterPort);
	masterAddr.sin_addr.s_addr = g_MasterIp;
	int iResult = connect(s, (SOCKADDR*)&masterAddr, sizeof(masterAddr));
	if(iResult == SOCKET_ERROR)
	{
		info("ServerList::refreshFromMasterServer() error connecting to master server (%d)\n", WSAGetLastError());
		closesocket(s);
		return false;
	}
	info("ServerList::refreshFromMasterServer() connected to master server.");

	MW3_MS_CLIENT_REQUEST req = {0};
	req.Magic4CC = MW3_MS_CLIENT_MAGIC4CC;
	dvar shortver(V("shortversion"));
	DWORD v_Maj = 0;
	DWORD v_Min = 0;
	sscanf_s(shortver.GetValueSTR(), "%d.%d", &v_Maj, &v_Min);
	req.Version = (v_Maj&0xFF)*0x1000000 | (v_Min&0xFF)*0x10000 | g_GameBuild+MW3_GAME_BUILD_MOD &0xFFFF;
	iResult = send(s, (char*)&req, sizeof(req), 0);
	if(iResult == SOCKET_ERROR)
	{
		info("ServerList::refreshFromMasterServer() error sending request to master (%d)\n", WSAGetLastError());
		closesocket(s);
		return false;
	}
	info("ServerList::refreshFromMasterServer() sent request to master server.");

	MW3_MS_CLIENT_RESPONSE response;
	int recvSize = recv(s, (char*)&response, sizeof(response), MSG_PEEK);
	if(recvSize == SOCKET_ERROR)
	{
		info("ServerList::refreshFromMasterServer() error receiving response from master (%d)\n", WSAGetLastError());
		closesocket(s);
		return false;
	}
	info("ServerList::refreshFromMasterServer() received response from master server. #1");

	if (response.NumberOfEntries > 0x1000)
	{
		info("ServerList::refreshFromMasterServer() error too many entries (%d)\n", response.NumberOfEntries);
		closesocket(s);
		return false;
	}

	int responseSize = sizeof(MW3_MS_CLIENT_RESPONSE)+sizeof(MW3_MS_SERVER_ENTRY)*response.NumberOfEntries;
	info("ServerList::refreshFromMasterServer() number of entries: %d", response.NumberOfEntries);

	PMW3_MS_CLIENT_RESPONSE pResponse = (PMW3_MS_CLIENT_RESPONSE)malloc(responseSize);
	memset(pResponse, 0, responseSize);
	recvSize = recv(s, (char*)pResponse, responseSize, 0);
	if(recvSize == SOCKET_ERROR)
	{
		info("ServerList::refreshFromMasterServer() error receiving response from master (%d)\n", WSAGetLastError());
		free(pResponse);
		m_pMasterResponse = NULL;
		closesocket(s);
		return false;
	}
	m_pMasterResponse = pResponse;
	info("ServerList::refreshFromMasterServer() received response from master server. #2");

	#ifdef DEBUGGING_ENABLED
	info("received %d items", m_pMasterResponse->NumberOfEntries);
	for (int i=0; i<m_pMasterResponse->NumberOfEntries; i++)
	{
		info("entry %d: %08X %04X", i, m_pMasterResponse->Entries[i].IpAddress, m_pMasterResponse->Entries[i].QPort);
	}
	#endif

	closesocket(s);
	return true;

	VE();
}

void ServerList::sendInternetListMulticast(ISteamMatchmakingServerListResponse* pResponse)
{	VM("ServerList::sendInternetListMulticast");

	if(!m_bInitialized)
	{
		initialize();
	}

	stopThread();
	cleanList();

	m_responseInterface = pResponse;
	CreateThread(NULL, 0, refreshInternetListThread, this, 0, NULL);

	VE();
}

//void ServerList::simpleRefresh()
//{	VM("ServerList::simpleRefresh");
//
//	if(!m_bInitialized)
//	{
//		initialize();
//	}
//
//	if (m_responseInterface != NULL)
//	{
//		stopThread();
//		cleanList();
//
//		CreateThread(NULL, 0, refreshInternetListThread, this, 0, NULL);
//	}
//
//	VE();
//}

void ServerList::sendLocalBroadcast(ISteamMatchmakingServerListResponse* pResponse)
{	VM("ServerList::sendLocalBroadcast");

	if(!m_bInitialized)
	{
		initialize();
	}
	stopThread();
	cleanList();

	m_responseInterface = pResponse;
	CreateThread(NULL, 0, refreshLanListThread, this, 0, NULL);

	VE();
}

void ServerList::cleanList()
{
	for(map<ULONGLONG, ServerItem*>::iterator itr = m_List.begin(); itr != m_List.end(); itr++)
	{
		ServerItem* pItem = itr->second;
		delete pItem;
	}

	m_List.clear();
}

int ServerList::getServerCount()
{
	return (int)m_List.size();
}

void ServerItem::setServerIndex(int index)
{
	ServerIndex = index;
}
int ServerItem::getServerIndex()
{
	return ServerIndex;
}


bool ServerList::getGameServerItem(int serverIndex, gameserveritem_t* pItem)
{	VM("ServerList::getGameServerItem");

	info("ServerList::getGameServerItem() start Index=%d\n", serverIndex);

	if(m_List.empty() || serverIndex >= m_List.size())
	{
		info("ServerList::getGameServerItem() no items found");
		return false;
	}

	for(map<ULONGLONG, ServerItem*>::iterator itr = m_List.begin(); itr != m_List.end(); itr++)
	{
		if(itr->second->getServerIndex() == serverIndex)
		{
			info("ServerList::getGameServerItem() item found");
			ServerItem* pServerItem = itr->second;
			pServerItem->fillGameServerItem(pItem);
			info("item = %08X   %04X", pServerItem->getServerInternalIp(), pServerItem->getServerInternalPort());
		}

		
	}

	return true;
	VE();
}


ServerItem* ServerList::getServerItemByIndex(int serverIndex)
{	VM("ServerList::getServerItemByIndex");

	info("ServerList::getServerItemByIndex() start Index=%d\n", serverIndex);

	if(m_List.empty() || serverIndex >= m_List.size())
	{
		info("ServerList::getServerItemByIndex() no items found");
		return NULL;
	}

	for(map<ULONGLONG, ServerItem*>::iterator itr = m_List.begin(); itr != m_List.end(); itr++)
	{
		if(itr->second->getServerIndex() == serverIndex)
		{
			info("ServerList::getServerItemByIndex(%d) item found", serverIndex);

			return itr->second;
		}
	}


	return NULL;
	VE();
}


ServerInformer* ServerInformer::s_pInstance = NULL;

bool ServerInformer::initialize(CSteamID* steamId)
{	VM("ServerInformer::initialize");

	if(!m_bInitialized)
	{
		


		memset(&m_serverInfo, 0, sizeof(MW3_SERVER_INFO));
		m_serverInfo.Magic4CC = MW3_SERVER_4CC;
		m_serverInfo.SteamId = steamId->ConvertToUint64();
		m_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if(INVALID_SOCKET == m_sock)
		{
			info("ERROR: Could not initialize a socket\n");
			return false;
		}

		sockaddr_in service;
		service.sin_family = AF_INET;
		service.sin_addr.s_addr = htonl(INADDR_ANY); // GetInternalIP(); //

		dvar qport_dvar(V("net_masterServerPort"));
		USHORT listenPort = qport_dvar.GetValueDW() & 0xFFFF;
		service.sin_port = htons(listenPort);
		int portRange = 0;
		int res = bind(m_sock, (SOCKADDR*)&service, sizeof(service));
		while( (SOCKET_ERROR == res) && (portRange++ <= SERVER_INFORMER_PORT_RANGE) )
		{
			service.sin_port = htons(listenPort+portRange);
			res = bind(m_sock, (SOCKADDR*)&service, sizeof(service));
			Sleep(1);
		}

		if(SOCKET_ERROR == res)
		{
			closesocket(m_sock);
			info("ERROR: Could not bind the socket\n");
			return false;
		}

		u_long iMode=1;
		// Enabling non-blocking mode for the socket
		ioctlsocket(m_sock, FIONBIO, &iMode);


		dvar nport("net_port");
		ConsolePrintf(0, V("%s\nProtected game port (net_port): %d (needs to be NAT'ed out, also - use this port when direct-connecting (won't work if server is password protected))\nQuery port (net_masterServerPort): %d (you need to NAT this one out in order to make your server visible online)\n%s\n"), V("-----------------------------------"), nport.GetValueDW(), listenPort+portRange, V("-----------------------------------"));


		//master server stuff
		//
		// build update msg unique to this server
		//
		if (g_OnlineMode)
		{
			
			dvar shortver(V("shortversion"));
			DWORD v_Maj = 0;
			DWORD v_Min = 0;
			sscanf_s(shortver.GetValueSTR(), "%d.%d", &v_Maj, &v_Min);

			m_updateMsg.Magic4CC = MW3_MS_SERVER_MAGIC4CC;
			m_updateMsg.QPort = listenPort+portRange;
			m_updateMsg.Version = (v_Maj&0xFF)*0x1000000 | (v_Min&0xFF)*0x10000 | g_GameBuild+MW3_GAME_BUILD_MOD &0xFFFF;

			#ifdef DEBUGGING_ENABLED
			info("ServerInformer::m_updateMsg.Version = %08X", m_updateMsg.Version);
			#endif
		}

		m_bInitialized = true;
	}

	return m_bInitialized;
	VE();
}


void ServerInformer::updateOnMasterServer()
{	VM("ServerInformer::updateOnMasterServer");

	if (g_OnlineMode && m_bInitialized)
	{
		if (g_MasterIp != 0 || g_MasterPort != 0 || m_updateMsg.QPort != 0 || m_updateMsg.Version != 0)
		{
			SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if(INVALID_SOCKET == s)
			{
				info("ServerInformer::updateOnMasterServer() ERROR: Couldn't initialize a socket.");
				return;
			}

			sockaddr_in masterAddr;
			masterAddr.sin_family = AF_INET;
			masterAddr.sin_port = htons(g_MasterPort);
			masterAddr.sin_addr.s_addr = g_MasterIp;

			int iResult = connect(s, (SOCKADDR*)&masterAddr, sizeof(masterAddr));
			if(iResult == SOCKET_ERROR)
			{
				info("ServerInformer::updateOnMasterServer() ERROR: Couldn't connect to the master server (%d).", WSAGetLastError());
				closesocket(s);
				return;
			}

			iResult = send(s, (char*)&m_updateMsg, sizeof(m_updateMsg), 0);
			while(iResult == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK)
			{
				info("ServerInformer::updateOnMasterServer() ERROR: Send failed. Resending...");
				iResult = send(s, (char*)&m_updateMsg, sizeof(m_updateMsg), 0);
				Sleep(1);
			}

			if(iResult == SOCKET_ERROR)
			{
				info("ServerInformer::updateOnMasterServer() ERROR: Send failed. Error %d.", WSAGetLastError());
			}

			closesocket(s);
		}
		else
		{
			info("ServerInformer::updateOnMasterServer() ERROR: Master server connection is enabled but ip or port is null!");
		}
	}
	else
	{
		info("ServerInformer::updateOnMasterServer() Skipping... (m_bInitialized=false)", WSAGetLastError());
	}

	VE();
}



void ServerInformer::startThread()
{
	if(!m_bRunThread)
	{
		m_bRunThread = true;
		CreateThread(NULL, 0, recvThread, this, 0, NULL);
	}
}

void ServerInformer::stopThread()
{
	m_bRunThread = false;
}

DWORD WINAPI ServerInformer::recvThread(LPVOID lpParameter)
{
	ServerInformer* pThis = (ServerInformer*)lpParameter;
	char* recvBuf = new char[1024];

	u_long iMode=1;
	// Enabling non-blocking mode for the socket
	ioctlsocket(pThis->m_sock, FIONBIO, &iMode);

    sockaddr_in senderAddr;
    int senderAddrSize = sizeof (senderAddr);

	while(pThis->m_bRunThread)
	{
		memset(recvBuf, 0, 1024);

		int dataLen = recvfrom(pThis->m_sock, recvBuf, 1024, 0, (SOCKADDR*)&senderAddr, &senderAddrSize);

		if(dataLen == SOCKET_ERROR)
		{
			if (WSAEWOULDBLOCK != WSAGetLastError())
			{
				//some real error
				info("Socket error %d", WSAGetLastError());
			}
			else
			{
				//wsa block
			}
		}
		else if (dataLen >= 8)
		{
			PMW3_SERVER_QUERY pServerQuery = (PMW3_SERVER_QUERY)recvBuf;
			if(pServerQuery->Magic4CC == MW3_SERVER_4CC)
			{
				pThis->m_serverInfo.TimeStamp = pServerQuery->TimeStamp;

				int sendSize = sizeof(MW3_SERVER_INFO)-MW3_SERVER_INFO_MAX_RAW_DATA_SIZE+pThis->m_serverInfo.RawDataSize;

				info("ServerInformer::recvThread() Sending server info to a client, size %d", sendSize);

				sendto(pThis->m_sock, (char*)&pThis->m_serverInfo, sendSize, 0, (SOCKADDR*)&senderAddr, senderAddrSize);
			}
		}

		Sleep(1);
	}
	delete [] recvBuf;

	return 0;
}

void ServerInformer::start()
{
	startThread();
}

void ServerInformer::stop()
{
	stopThread();
}

void ServerInformer::updateServer(int cPlayers, int cPlayersMax, const char *pchServerName, const char *pchMapName)
{	VM("ServerInformer::updateServer");


	if (m_serverInfo.Magic4CC != MW3_SERVER_4CC) 
	{
		MessageBoxA(0, "Warning! server item corrupted",0,0);
	}

	m_serverInfo.Players = cPlayers;
	m_serverInfo.MaxPlayers = cPlayersMax;


	char infos[0x2000];
	memset(infos, 0, 0x2000);
	FillServerInfo(infos); 

	//BYTE	MapName_ptr;
	//BYTE	ServerName_ptr;
	//WORD	ServerTags_ptr;
	//WORD	ServerInfos_ptr;

	//WORD		RawDataSize;
	//char		RawData[2048];

	memset(m_serverInfo.RawData, 0, MW3_SERVER_INFO_MAX_RAW_DATA_SIZE);

	int smaplen = strlen(pchMapName);
	int sinfolen = strlen(infos);
	int stagslen = strlen(m_ServerTags);
	int snamelen = strlen(pchServerName);

	if (smaplen + smaplen + smaplen + smaplen + 10 > MW3_SERVER_INFO_MAX_RAW_DATA_SIZE)
	{
		info("updateServer() Error, infos too long!");
		return;
	}

	//copy map name
	char * ptr = m_serverInfo.RawData + sizeof(MW_SERVER_INFO_EX);
	m_serverInfo.MapName_ptr = (ptr - m_serverInfo.RawData) & 0xFFFF;
	memcpy(ptr, pchMapName, smaplen);

	//copy server name
	ptr += smaplen + 1;
	m_serverInfo.ServerName_ptr = (ptr - m_serverInfo.RawData) & 0xFFFF;
	memcpy(ptr, pchServerName, snamelen);

	//copy server tags
	ptr += snamelen + 1;
	m_serverInfo.ServerTags_ptr = (ptr - m_serverInfo.RawData) & 0xFFFF;
	memcpy(ptr, m_ServerTags, stagslen);

	//copy server infos
	ptr += stagslen + 1;
	m_serverInfo.ServerInfos_ptr = (ptr - m_serverInfo.RawData) & 0xFFFF;
	memcpy(ptr, infos, sinfolen);

	//set final raw data size
	m_serverInfo.RawDataSize = (ptr - m_serverInfo.RawData) + sinfolen + 1;


	//info("------------ dumping server info ------------");
	//PrintBuffer((BYTE *)&m_serverInfo.Magic4CC, sizeof(MW3_SERVER_INFO)-MW3_SERVER_INFO_MAX_RAW_DATA_SIZE+m_serverInfo.RawDataSize, 16);


	VE();
}

void ServerInformer::setGameTags(const char *pchGameTags)
{
	snprintf(m_ServerTags, sizeof(m_ServerTags), "%s", pchGameTags);
}


void ServerInformer::setServerType(uint32 unGameIP, uint16 unGamePort, uint16 usQueryPort, const char *pchVersion, bool bLANMode)
{	VM("ServerInformer::setServerType");

	m_serverInfo.GameIP_int = unGameIP;
	m_serverInfo.GameIP_ext = GetExternalIP(true);
	m_serverInfo.GamePort = unGamePort;
	m_serverInfo.QueryPort = usQueryPort;
	m_serverInfo.ServerVersion = atoi(pchVersion);
	dvar net_port(V("net_port"));
	m_serverInfo.NetPort = net_port.GetValueDW() & 0xFFFF;
	dvar dedicated(V("dedicated"));
	m_serverInfo.bDedicated = dedicated.GetValueDW();
	dvar g_password("g_password");
	if (strcmp(g_password.GetValueSTR(), "") == 0)
		m_serverInfo.bPasswordProtected = 0;
	else
		m_serverInfo.bPasswordProtected = 1;

	memcpy(m_serverInfo.SecID, g_ServerKeyId, 8);
	memcpy(m_serverInfo.SecKey, g_ServerKey, 16);

	VE();
}


ServerItem* ServerList::getServerItemByAddress(ULONG ipAddr, USHORT port)
{	VM("ServerList::getServerIndexByAddress");

	for(map<ULONGLONG, ServerItem*>::iterator itr = m_List.begin(); itr != m_List.end(); itr++)
	{
		info("ip %08X -- %08X, port %04X -- %04X", itr->second->getServerInternalIp(), ipAddr, itr->second->getServerInternalPort(), port);
		if( (itr->second->getServerExternalIp() == ipAddr && itr->second->getServerExternalPort() == port) || 
			(itr->second->getServerInternalIp() == ipAddr && itr->second->getServerInternalPort() == port) )
		{
			return itr->second;
		}
			
	}

	return NULL;
	VE();
}

void * ServerList::createConnectionBlob(ULONG ipAddr, USHORT port, bool ServerItemMustExist)
{	VU("ServerList::createConnectionBlob");

	void * blob = ConnBlob_skeleton;

	if (ServerItemMustExist)
	{
		ServerItem * item = getServerItemByAddress(ipAddr, port);

		if (item != NULL)
		{
			info("ServerList::createConnectionBlob() generating blob\n");

			*(DWORD*)((DWORD)blob+0x10) = htonl(item->getServerInternalIp());
			*(DWORD*)((DWORD)blob+0x22) = htonl(item->getServerExternalIp());
			*(WORD*)((DWORD)blob+0x14) = item->getServerInternalPort();
			*(WORD*)((DWORD)blob+0x26) = item->getServerExternalPort();
			*(BYTE*)((DWORD)blob+0x59) = 1; 


			//hwid challenge
			DWORD * hwid = (DWORD*)((DWORD)blob+0x3C);

			GetHWID(hwid);

			//hwid[1] = 0x14141414 ^ GetTickCount();
			//hwid[2] = 0x15151515 ^ GetTickCount();
			//hwid[3] = 0x16161616 ^ GetTickCount();

			hwid[0] = GetCRC32((void *)&hwid[1], 12);

			hwid[1] = hwid[1] ^ ntohl(hwid[0]) ^ 0x7629d1b9;
			hwid[2] = hwid[2] ^ hwid[0] ^ 0x1337D00D;
			hwid[3] = hwid[3] ^ (hwid[0] >> 1) ^ 0xDEADCAFE;
			hwid[0] = hwid[0] ^ 0x23586134 ^ 0xC0DEB100;


			//some other unknown vals CC'ed
			*(DWORD*)((DWORD)blob+0x30) = 0xCCCCCCCC;
			*(DWORD*)((DWORD)blob+0x34) = 0xCCCCCCCC;

			//copy serurity id+key (null by default)
			memcpy((void *)((DWORD)blob+0x8), item->getServerSecId(), 8);
			memcpy((void *)((DWORD)blob+0x29), item->getServerSecKey(), 16);

			#ifdef DEBUGGING_ENABLED
			info("Connection blob dump:");
			PrintBuffer((BYTE*)blob, 0x60, 0x10);
			#endif
			return blob;
		}

		info("ServerList::createConnectionBlob() server information not found\n");

		return NULL;
	}
	else
	{
		info("ServerList::createConnectionBlob() generating blob\n");

		*(DWORD*)((DWORD)blob+0x10) = htonl(ipAddr);
		*(DWORD*)((DWORD)blob+0x22) = htonl(ipAddr);
		*(WORD*)((DWORD)blob+0x14) = port;
		*(WORD*)((DWORD)blob+0x26) = port;
		*(BYTE*)((DWORD)blob+0x59) = 1; 

		//hwid challenge
		DWORD * hwid = (DWORD*)((DWORD)blob+0x3C);

		//hwid[1] = 0x14141414;
		//hwid[2] = 0x15151515;
		//hwid[3] = 0x16161616;
		GetHWID(hwid);
		hwid[0] = GetCRC32((void *)&hwid[1], 12);

		hwid[1] = hwid[1] ^ ntohl(hwid[0]) ^ 0x7629d1b9;
		hwid[2] = hwid[2] ^ hwid[0] ^ 0x1337D00D;
		hwid[3] = hwid[3] ^ (hwid[0] >> 1) ^ 0xDEADCAFE;
		hwid[0] = hwid[0] ^ 0x23586134 ^ 0xC0DEB100;


		//some other unknown vals CC'ed
		*(DWORD*)((DWORD)blob+0x30) = 0xCCCCCCCC;
		*(DWORD*)((DWORD)blob+0x34) = 0xCCCCCCCC;

		//copy serurity id+key (null by default)
		memset((void *)((DWORD)blob+0x8), STATIC_SECURITY_KEY, 8);
		memset((void *)((DWORD)blob+0x29), STATIC_SECURITY_KEY, 16);


		#ifdef DEBUGGING_ENABLED
		info("Connection blob dump:");
		PrintBuffer((BYTE*)blob, 0x60, 0x10);
		#endif
		return blob;
	}

	return NULL;

	VE();
}




int GetServerEntryIndexFromList(PMW3_MS_CLIENT_RESPONSE listData, DWORD ip, USHORT port)
{	VM("GetServerEntryIndexFromList");

	bool found = false;

	for (int i = 0; i < listData->NumberOfEntries; i++)
	{
		if (listData->Entries[i].IpAddress == ip && listData->Entries[i].QPort == port)
		{
			return i;
		}
	}

	return -1;

	VE();
}

bool RemoveServerEntryFromList(PMW3_MS_CLIENT_RESPONSE listData, DWORD ip, USHORT port)
{	VM("RemoveServerEntryFromList");

	int idx = GetServerEntryIndexFromList(listData, ip, port);

	if (idx == -1) 
	{
		info("RemoveServerEntryFromList(%08X, %d) -> error, item not found.", ip, port, idx);
		return false;
	}

 	info("RemoveServerEntryFromList(%08X, %d) -> removing server from the list (idx %d).", ip, port, idx);

	if (idx < listData->NumberOfEntries-1)
	{	//item existed but wasnt the last one

		//shuffle all newer items back over the old one
		for (int i = idx; i < listData->NumberOfEntries-1; i++)
		{
			listData->Entries[i].IpAddress = listData->Entries[i+1].IpAddress;
			listData->Entries[i].QPort = listData->Entries[i+1].QPort;
		}
	}

	listData->NumberOfEntries--;
	return true;

	VE();
}



PMW3_MS_CLIENT_RESPONSE LoadOfficialServerList()
{	VM("LoadOfficialServerList");

	int entries = 1;
	int max_size = entries*sizeof(MW3_MS_SERVER_ENTRY)+4;
	PMW3_MS_CLIENT_RESPONSE listData = (PMW3_MS_CLIENT_RESPONSE)malloc(max_size);

	listData->NumberOfEntries = 1;
	listData->Entries[0].IpAddress = 0x3eed0440;  
	listData->Entries[0].QPort = 27017;

	return listData;

	VE();
}

PMW3_MS_CLIENT_RESPONSE LoadServerList(char * name, DWORD max_items)
{	VM("LoadServerList");

	//SteamDataCrypto
	char fname[256];
	sprintf(fname, V(".\\dw\\%s.slist"), name);

	info("OpenServerList(%s): Loading server list.", name);

	FILE * pFile;
	pFile = fopen(fname, "rb");

	int max_size = max_items*sizeof(MW3_MS_SERVER_ENTRY)+4;
	PMW3_MS_CLIENT_RESPONSE listData = (PMW3_MS_CLIENT_RESPONSE)malloc(max_size);
	memset((void*)listData, 0, max_size);

	if (pFile != NULL)
	{
		int bytesRead = fread((void*)listData, 1, max_size, pFile);

		#ifdef DEBUGGING_ENABLED
		info("OpenServerList(%s): Read %d bytes.", name, bytesRead);
		if (bytesRead != 0) PrintBuffer((BYTE *)listData, bytesRead, 16);
		#endif

		//verify item count, fix if needed
		if (listData->NumberOfEntries > max_items)
		{
			info("OpenServerList(%s): Error, server list is corrupted (over %d items).", name, max_items);
			listData->NumberOfEntries = max_items;
		}

		info("OpenServerList(%s): Success, server list loaded (%d items).", name, listData->NumberOfEntries);
		fclose(pFile);
		return listData;
	}

	return listData;

	VE();
}

bool SaveServerList(PMW3_MS_CLIENT_RESPONSE listData, char * name, DWORD max_items)
{	VM("SaveServerList");

	if (listData == NULL || name == NULL) return false;

	//SteamDataCrypto
	char fname[256];
	sprintf(fname, V(".\\dw\\%s.slist"), name);

	info("SaveServerList(%s): Saving server list.", name);

	FILE * pFile;
	pFile = fopen(fname, "wb");

	if (pFile != NULL)
	{
		//verify item count, fix if needed
		if (listData->NumberOfEntries > max_items)
		{
			info("SaveServerList(%s): Error, server list is corrupted (over %d items).", name, max_items);
			listData->NumberOfEntries = max_items;
		}

		int writeSize = listData->NumberOfEntries * sizeof(MW3_MS_SERVER_ENTRY) + 4;

		if (fwrite((void*)listData, 1, writeSize, pFile) != writeSize)
		{
			info("SaveServerList(%s): Error, failed to write %d bytes to the list.", name, writeSize);
			fclose(pFile);
			return false;
		}

		info("SaveServerList(%s): Written %d bytes to the list.", name, writeSize);
		fclose(pFile);
		return true;
	}

	return false;

	VE();
}



bool ServerList::addHistoryGame(DWORD ip, USHORT port)
{	VM("ServerList::addHistoryGame");

	//return WriteServerEntryToListFile(V("History"), ip, port, 30);
	PMW3_MS_CLIENT_RESPONSE listData = LoadServerList(V("History"), 30);

	if (listData != NULL)
	{
		RemoveServerEntryFromList(listData, ip, port);

		if (listData->NumberOfEntries >= 30)
		{
			listData->NumberOfEntries = 30;			
			RemoveServerEntryFromList(listData, listData->Entries[0].IpAddress, listData->Entries[0].QPort);
		}

		listData->Entries[listData->NumberOfEntries].IpAddress = ip;
		listData->Entries[listData->NumberOfEntries].QPort = port;
		listData->NumberOfEntries++;

		if (SaveServerList(listData, V("History"), 30))
		{
			info("ServerList::addHistoryGame(%08X, %d) -> true (new count: %d)", ip, port, listData->NumberOfEntries);
			free(listData);
			return true;
		}
		free(listData);
	}

	info("ServerList::addHistoryGame(%08X, %d) -> false", ip, port);
	return false;

	VE();
}

bool ServerList::addFavoriteGame(DWORD ip, USHORT port)
{	VM("ServerList::addFavoriteGame");

	//return WriteServerEntryToListFile(V("Favorities"), ip, port, 1000);
	PMW3_MS_CLIENT_RESPONSE listData = LoadServerList(V("Favorities"), 1000);

	if (listData != NULL)
	{
		if (GetServerEntryIndexFromList(listData, ip, port) != -1)
		{
			info("ServerList::addFavoriteGame(%08X, %d) -> true (already existed, same count: %d)", ip, port, listData->NumberOfEntries);
			free(listData);
			return true;
		}

		if (listData->NumberOfEntries >= 1000)
		{
			listData->NumberOfEntries = 1000;
			RemoveServerEntryFromList(listData, listData->Entries[0].IpAddress, listData->Entries[0].QPort);
		}

		listData->Entries[listData->NumberOfEntries].IpAddress = ip;
		listData->Entries[listData->NumberOfEntries].QPort = port;
		listData->NumberOfEntries++;

		if (SaveServerList(listData, V("Favorities"), 1000))
		{
			info("ServerList::addFavoriteGame(%08X, %d) -> true (new count: %d)", ip, port, listData->NumberOfEntries);
			free(listData);
			return true;
		}
		free(listData);
	}

	info("ServerList::addFavoriteGame(%08X, %d) -> false", ip, port);
	return false;

	VE();
}



bool ServerList::removeFavoriteGame(DWORD ip, USHORT port)
{	VM("ServerList::removeFavoriteGame");

	//return RemoveServerEntryFromListFile(V("Favorities"), ip, port, 1000);
	PMW3_MS_CLIENT_RESPONSE listData = LoadServerList(V("Favorities"), 1000);

	if (listData != NULL)
	{
		bool removed = RemoveServerEntryFromList(listData, ip, port);

		if (removed)
		{
			if (SaveServerList(listData, V("Favorities"), 1000))
			{
				info("ServerList::removeFavoriteGame(%08X, %d) -> true (new count: %d)", ip, port, listData->NumberOfEntries);
				free(listData);
				return true;
			}
		}

		free(listData);
	}

	info("ServerList::removeFavoriteGame(%08X, %d) -> false", ip, port);
	return false;

	VE();
}


bool ServerList::refreshFavoriteGames()
{	VM("ServerList::refreshFavoriteGames");

	if(!m_bInitialized)
	{
		initialize();
	}
	
	if(m_pMasterResponse != NULL)
	{
		free(m_pMasterResponse);
		m_pMasterResponse = NULL;
	}

	m_pMasterResponse = LoadServerList(V("Favorities"), 1000);

	if (m_pMasterResponse == NULL)
		return false;

	if (m_pMasterResponse->NumberOfEntries == 0)
	{
		free(m_pMasterResponse);
		m_pMasterResponse = NULL;
		return false;
	}

	return true;

	VE();
}

bool ServerList::refreshHistoryGames()
{	VM("ServerList::refreshHistoryGames");

	if(!m_bInitialized)
	{
		initialize();
	}
	
	if(m_pMasterResponse != NULL)
	{
		free(m_pMasterResponse);
		m_pMasterResponse = NULL;
	}

	m_pMasterResponse = LoadServerList(V("History"), 30);

	if (m_pMasterResponse == NULL)
		return false;

	if (m_pMasterResponse->NumberOfEntries == 0)
	{
		free(m_pMasterResponse);
		m_pMasterResponse = NULL;
		return false;
	}

	return true;

	VE();
}
bool ServerList::refreshOfficialGames()
{	VM("ServerList::refreshOfficialGames");

	if(!m_bInitialized)
	{
		initialize();
	}
	
	if(m_pMasterResponse != NULL)
	{
		free(m_pMasterResponse);
		m_pMasterResponse = NULL;
	}

	m_pMasterResponse = LoadOfficialServerList();

	if (m_pMasterResponse == NULL)
		return false;

	if (m_pMasterResponse->NumberOfEntries == 0)
	{
		free(m_pMasterResponse);
		m_pMasterResponse = NULL;
		return false;
	}

	return true;

	VE();
}

//
//DWORD WINAPI nettest(LPVOID param)
//{
//
//    int iResult = 0;
//
//    WSADATA wsaData;
//
//    SOCKET RecvSocket;
//    sockaddr_in RecvAddr;
//
//    unsigned short Port = 27020;
//
//    char RecvBuf[1024];
//    int BufLen = 1024;
//
//    sockaddr_in SenderAddr;
//    int SenderAddrSize = sizeof (SenderAddr);
//
//    //-----------------------------------------------
//    // Initialize Winsock
//    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//    if (iResult != NO_ERROR) {
//        info("WSAStartup failed with error %d\n", iResult);
//        return 1;
//    }
//    //-----------------------------------------------
//    // Create a receiver socket to receive datagrams
//    RecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
//    if (RecvSocket == INVALID_SOCKET) {
//        info("socket failed with error %d\n", WSAGetLastError());
//        return 1;
//    }
//    //-----------------------------------------------
//    // Bind the socket to any address and the specified port.
//    RecvAddr.sin_family = AF_INET;
//    RecvAddr.sin_port = htons(Port);
//    RecvAddr.sin_addr.s_addr = htonl(0xC0A80B23);//htonl(INADDR_ANY);
//
//    iResult = bind(RecvSocket, (SOCKADDR *) & RecvAddr, sizeof (RecvAddr));
//    if (iResult != 0) {
//        info("bind failed with error %d\n", WSAGetLastError());
//        return 1;
//    }
//
//	//u_long iMode=1;
//	//// Enabling non-blocking mode for the socket
//	//iResult = ioctlsocket(RecvSocket, FIONBIO, &iMode);
//	//if (iResult == SOCKET_ERROR)
//	//{
//	//	if ( WSAEWOULDBLOCK != WSAGetLastError())
//	//	{
//	//		info("ioctlsocket failed with error %d\n", WSAGetLastError());
//	//		ExitProcess(0);
//	//	}
//	//}
//
//    //-----------------------------------------------
//    // Call the recvfrom function to receive datagrams
//    // on the bound socket.
//    info("Receiving datagrams ...\n");
//	while (true)
//	{
//		iResult = recvfrom(RecvSocket,
//						   RecvBuf, BufLen, 0, (SOCKADDR *) & SenderAddr, &SenderAddrSize);
//		//if (iResult == SOCKET_ERROR)
//		//{
//		//	if ( WSAEWOULDBLOCK != WSAGetLastError())
//		//	{
//		//		wprintf(L"recvfrom failed with error %d\n", WSAGetLastError());
//		//	}
//		//}
//		//else
//		//{
//		//	wprintf(L"received packet\n");
//		//}
//		info("received packet: %08X  - > %08X\n", iResult, WSAGetLastError());
//
//		Sleep(1);
//	}
//    //-----------------------------------------------
//    // Close the socket when finished receiving datagrams
//    info("Finished receiving. Closing socket.\n");
//    iResult = closesocket(RecvSocket);
//    if (iResult == SOCKET_ERROR) {
//        info("closesocket failed with error %d\n", WSAGetLastError());
//        return 1;
//    }
//
//    //-----------------------------------------------
//    // Clean up and exit.
//    info("Exiting.\n");
//    WSACleanup();
//    return 0;
//}

#pragma optimize("", on)