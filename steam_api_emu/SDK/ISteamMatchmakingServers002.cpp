#include "ISteamMatchmakingServers002.h"

class ISteamMatchmakingServers002_wrapper
{
public:
	virtual HServerListRequest  RequestInternetServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestInternetServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerListRequest  ret = m_pWrapper->RequestInternetServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HServerListRequest  RequestLANServerList ( AppId_t iApp,  ISteamMatchmakingServerListResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestLANServerList() iApp=0x%X pRequestServersResponse=0x%X ",
			iApp,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerListRequest  ret = m_pWrapper->RequestLANServerList(iApp, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HServerListRequest  RequestFriendsServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestFriendsServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerListRequest  ret = m_pWrapper->RequestFriendsServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HServerListRequest  RequestFavoritesServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestFavoritesServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerListRequest  ret = m_pWrapper->RequestFavoritesServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HServerListRequest  RequestHistoryServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestHistoryServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerListRequest  ret = m_pWrapper->RequestHistoryServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HServerListRequest  RequestSpectatorServerList ( AppId_t iApp,  MatchMakingKeyValuePair_t **ppchFilters,  uint32 nFilters,  ISteamMatchmakingServerListResponse *pRequestServersResponse )	{
		char log[1024];
		sprintf(log,"RequestSpectatorServerList() iApp=0x%X ppchFilters=0x%X nFilters=0x%X pRequestServersResponse=0x%X ",
			iApp,
			ppchFilters,
			nFilters,
			pRequestServersResponse		);
		OutputDebugStringA(log);
		HServerListRequest  ret = m_pWrapper->RequestSpectatorServerList(iApp, ppchFilters, nFilters, pRequestServersResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ReleaseRequest ( HServerListRequest hServerListRequest )	{
		char log[1024];
		sprintf(log,"ReleaseRequest() hServerListRequest=0x%X ",
			hServerListRequest		);
		OutputDebugStringA(log);
		hServerListRequest);
		OutputDebugStringA("\n");
	}
	virtual gameserveritem_t * GetServerDetails ( HServerListRequest hRequest,  int iServer )	{
		char log[1024];
		sprintf(log,"GetServerDetails() hRequest=0x%X iServer=0x%X ",
			hRequest,
			iServer		);
		OutputDebugStringA(log);
		gameserveritem_t * ret = m_pWrapper->GetServerDetails(hRequest, iServer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  CancelQuery ( HServerListRequest hRequest )	{
		char log[1024];
		sprintf(log,"CancelQuery() hRequest=0x%X ",
			hRequest		);
		OutputDebugStringA(log);
		hRequest);
		OutputDebugStringA("\n");
	}
	virtual void  RefreshQuery ( HServerListRequest hRequest )	{
		char log[1024];
		sprintf(log,"RefreshQuery() hRequest=0x%X ",
			hRequest		);
		OutputDebugStringA(log);
		hRequest);
		OutputDebugStringA("\n");
	}
	virtual bool  IsRefreshing ( HServerListRequest hRequest )	{
		char log[1024];
		sprintf(log,"IsRefreshing() hRequest=0x%X ",
			hRequest		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsRefreshing(hRequest);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetServerCount ( HServerListRequest hRequest )	{
		char log[1024];
		sprintf(log,"GetServerCount() hRequest=0x%X ",
			hRequest		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetServerCount(hRequest);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RefreshServer ( HServerListRequest hRequest,  int iServer )	{
		char log[1024];
		sprintf(log,"RefreshServer() hRequest=0x%X iServer=0x%X ",
			hRequest,
			iServer		);
		OutputDebugStringA(log);
		hRequest, iServer);
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
