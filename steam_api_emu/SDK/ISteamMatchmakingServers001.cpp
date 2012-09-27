#include "ISteamMatchmakingServers001.h"

class ISteamMatchmakingServers001_wrapper
{
public:
	virtual void  RequestInternetServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse001 *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestInternetServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		iApp, ppchFilters, nFilters, pRequestServersResponse);
		OutputDebugStringA("\n");
	}
	virtual void  RequestLANServerList ( AppId_t iApp,  ISteamMatchmakingServerListResponse001 *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestLANServerList() iApp=0x%X pRequestServersResponse=0x%X ",
			iApp,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		iApp, pRequestServersResponse);
		OutputDebugStringA("\n");
	}
	virtual void  RequestFriendsServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse001 *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestFriendsServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		iApp, ppchFilters, nFilters, pRequestServersResponse);
		OutputDebugStringA("\n");
	}
	virtual void  RequestFavoritesServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse001 *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestFavoritesServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		iApp, ppchFilters, nFilters, pRequestServersResponse);
		OutputDebugStringA("\n");
	}
	virtual void  RequestHistoryServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse001 *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestHistoryServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		iApp, ppchFilters, nFilters, pRequestServersResponse);
		OutputDebugStringA("\n");
	}
	virtual void  RequestSpectatorServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse001 *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestSpectatorServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		iApp, ppchFilters, nFilters, pRequestServersResponse);
		OutputDebugStringA("\n");
	}
	virtual gameserveritem_t * GetServerDetails ( EMatchMakingType eType,  int iServer )	{
		char log[1024];
		sprintf(log,"GetServerDetails() eType=0x%X iServer=0x%X ",
			eType,
			iServer		);
		OutputDebugStringA(log);
		gameserveritem_t * ret = m_pWrapper->GetServerDetails(eType, iServer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  CancelQuery ( EMatchMakingType eType )	{
		char log[1024];
		sprintf(log,"CancelQuery() eType=0x%X ",
			eType		);
		OutputDebugStringA(log);
		eType);
		OutputDebugStringA("\n");
	}
	virtual void  RefreshQuery ( EMatchMakingType eType )	{
		char log[1024];
		sprintf(log,"RefreshQuery() eType=0x%X ",
			eType		);
		OutputDebugStringA(log);
		eType);
		OutputDebugStringA("\n");
	}
	virtual bool  IsRefreshing ( EMatchMakingType eType )	{
		char log[1024];
		sprintf(log,"IsRefreshing() eType=0x%X ",
			eType		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsRefreshing(eType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetServerCount ( EMatchMakingType eType )	{
		char log[1024];
		sprintf(log,"GetServerCount() eType=0x%X ",
			eType		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetServerCount(eType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RefreshServer ( EMatchMakingType eType,  int iServer )	{
		char log[1024];
		sprintf(log,"RefreshServer() eType=0x%X iServer=0x%X ",
			eType,
			iServer		);
		OutputDebugStringA(log);
		eType, iServer);
		OutputDebugStringA("\n");
	}
	virtual HServerQuery  PingServer ( uint32 unIP,  uint16 usPort,  ISteamMatchmakingPingResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"PingServer() unIP=0x%X usPort=0x%X pRequestServersResponse=0x%X ",
			unIP,
			usPort,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerQuery  ret = m_pWrapper->PingServer(unIP, usPort, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HServerQuery  PlayerDetails ( uint32 unIP,  uint16 usPort,  ISteamMatchmakingPlayersResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"PlayerDetails() unIP=0x%X usPort=0x%X pRequestServersResponse=0x%X ",
			unIP,
			usPort,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerQuery  ret = m_pWrapper->PlayerDetails(unIP, usPort, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HServerQuery  ServerRules ( uint32 unIP,  uint16 usPort,  ISteamMatchmakingRulesResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"ServerRules() unIP=0x%X usPort=0x%X pRequestServersResponse=0x%X ",
			unIP,
			usPort,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerQuery  ret = m_pWrapper->ServerRules(unIP, usPort, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  CancelServerQuery ( HServerQuery hServerQuery )	{
		char log[1024];
		sprintf(log,"CancelServerQuery() hServerQuery=0x%X ",
			hServerQuery		);
		OutputDebugStringA(log);
		hServerQuery);
		OutputDebugStringA("\n");
	}
};
