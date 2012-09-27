#include "MatchmakingServersCommon.h"

class ISteamMatchmakingServerListResponse001_wrapper
{
public:
	virtual void  ServerResponded ( int iServer )	{
		char log[1024];
		sprintf(log,"ServerResponded() iServer=0x%X ",
			iServer		);
		OutputDebugStringA(log);
		iServer);
		OutputDebugStringA("\n");
	}
	virtual void  ServerFailedToRespond ( int iServer )	{
		char log[1024];
		sprintf(log,"ServerFailedToRespond() iServer=0x%X ",
			iServer		);
		OutputDebugStringA(log);
		iServer);
		OutputDebugStringA("\n");
	}
	virtual void  RefreshComplete ( EMatchMakingServerResponse response )	{
		char log[1024];
		sprintf(log,"RefreshComplete() response=0x%X ",
			response		);
		OutputDebugStringA(log);
		response);
		OutputDebugStringA("\n");
	}
class ISteamMatchmakingServerListResponse002_wrapper
{
public:
	virtual void  ServerResponded ( HServerListRequest hRequest,  int iServer )	{
		char log[1024];
		sprintf(log,"ServerResponded() hRequest=0x%X iServer=0x%X ",
			hRequest,
			iServer		);
		OutputDebugStringA(log);
		hRequest, iServer);
		OutputDebugStringA("\n");
	}
	virtual void  ServerFailedToRespond ( HServerListRequest hRequest,  int iServer )	{
		char log[1024];
		sprintf(log,"ServerFailedToRespond() hRequest=0x%X iServer=0x%X ",
			hRequest,
			iServer		);
		OutputDebugStringA(log);
		hRequest, iServer);
		OutputDebugStringA("\n");
	}
	virtual void  RefreshComplete ( HServerListRequest hRequest,  EMatchMakingServerResponse response )	{
		char log[1024];
		sprintf(log,"RefreshComplete() hRequest=0x%X response=0x%X ",
			hRequest,
			response		);
		OutputDebugStringA(log);
		hRequest, response);
		OutputDebugStringA("\n");
	}
	ISteamMatchmakingServerListResponse002_wrapper();
class ISteamMatchmakingPingResponse_wrapper
{
public:
	virtual void  ServerResponded ( gameserveritem_t &server )	{
		char log[1024];
		sprintf(log,"ServerResponded() &server=0x%X ",
			&server		);
		OutputDebugStringA(log);
		&server);
		OutputDebugStringA("\n");
	}
	virtual void  ServerFailedToRespond ()	{
		char log[1024];
		sprintf(log,"ServerFailedToRespond() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
class ISteamMatchmakingPlayersResponse_wrapper
{
public:
	virtual void  AddPlayerToList ( const char *pchName,  int nScore,  float flTimePlayed )	{
		char log[1024];
		sprintf(log,"AddPlayerToList() pchName=%s nScore=0x%X flTimePlayed=0x%X ",
			pchName,
			nScore,
			flTimePlayed		);
		OutputDebugStringA(log);
		pchName, nScore, flTimePlayed);
		OutputDebugStringA("\n");
	}
	virtual void  PlayersFailedToRespond ()	{
		char log[1024];
		sprintf(log,"PlayersFailedToRespond() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  PlayersRefreshComplete ()	{
		char log[1024];
		sprintf(log,"PlayersRefreshComplete() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
class ISteamMatchmakingRulesResponse_wrapper
{
public:
	virtual void  RulesResponded ( const char *pchRule,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"RulesResponded() pchRule=%s pchValue=%s ",
			pchRule,
			pchValue		);
		OutputDebugStringA(log);
		pchRule, pchValue);
		OutputDebugStringA("\n");
	}
	virtual void  RulesFailedToRespond ()	{
		char log[1024];
		sprintf(log,"RulesFailedToRespond() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  RulesRefreshComplete ()	{
		char log[1024];
		sprintf(log,"RulesRefreshComplete() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
};
