#include "ISteamUser009.h"

class ISteamUser009_wrapper
{
public:
	virtual HSteamUser  GetHSteamUser ()	{
		char log[1024];
		sprintf(log,"GetHSteamUser() "		);
		OutputDebugStringA(log);
		HSteamUser  ret = m_pWrapper->GetHSteamUser();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BLoggedOn ()	{
		char log[1024];
		sprintf(log,"BLoggedOn() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BLoggedOn();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetSteamID ()	{
		char log[1024];
		sprintf(log,"GetSteamID() "		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetSteamID();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  InitiateGameConnection ( void *pBlob,  int cbMaxBlob,  CSteamID steamID,  CGameID gameID,  uint32 unIPServer,  uint16 usPortServer,  bool bSecure )	{
		char log[1024];
		sprintf(log,"InitiateGameConnection() pBlob=0x%X cbMaxBlob=0x%X steamID=0x%X gameID=0x%X unIPServer=0x%X usPortServer=0x%X bSecure=0x%X ",
			pBlob,
			cbMaxBlob,
			steamID,
			gameID,
			unIPServer,
			usPortServer,
			bSecure		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->InitiateGameConnection(pBlob, cbMaxBlob, steamID, gameID, unIPServer, usPortServer, bSecure);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  TerminateGameConnection ( uint32 unIPServer,  uint16 usPortServer )	{
		char log[1024];
		sprintf(log,"TerminateGameConnection() unIPServer=0x%X usPortServer=0x%X ",
			unIPServer,
			usPortServer		);
		OutputDebugStringA(log);
		unIPServer, usPortServer);
		OutputDebugStringA("\n");
	}
	virtual void  TrackAppUsageEvent ( CGameID gameID,  EAppUsageEvent eAppUsageEvent,  const char *pchExtraInfo = "" )	{
		char log[1024];
		sprintf(log,"TrackAppUsageEvent() gameID=0x%X eAppUsageEvent=0x%X ""=%s ",
			gameID,
			eAppUsageEvent,
			""		);
		OutputDebugStringA(log);
		gameID, eAppUsageEvent, "");
		OutputDebugStringA("\n");
	}
	virtual void  RefreshSteam2Login ()	{
		char log[1024];
		sprintf(log,"RefreshSteam2Login() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
};
