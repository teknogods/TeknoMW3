#include "ISteamUser007.h"

class ISteamUser007_wrapper
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
	virtual void  LogOn ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"LogOn() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		steamID);
		OutputDebugStringA("\n");
	}
	virtual void  LogOff ()	{
		char log[1024];
		sprintf(log,"LogOff() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
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
	virtual bool  SetRegistryString ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetRegistryString() eRegistrySubTree=0x%X pchKey=%s pchValue=%s ",
			eRegistrySubTree,
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetRegistryString(eRegistrySubTree, pchKey, pchValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetRegistryString ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  char *pchValue,  int cbValue )	{
		char log[1024];
		sprintf(log,"GetRegistryString() eRegistrySubTree=0x%X pchKey=%s pchValue=%s cbValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			pchValue,
			cbValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetRegistryString(eRegistrySubTree, pchKey, pchValue, cbValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetRegistryInt ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  int iValue )	{
		char log[1024];
		sprintf(log,"SetRegistryInt() eRegistrySubTree=0x%X pchKey=%s iValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			iValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetRegistryInt(eRegistrySubTree, pchKey, iValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetRegistryInt ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  int *piValue )	{
		char log[1024];
		sprintf(log,"GetRegistryInt() eRegistrySubTree=0x%X pchKey=%s piValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			piValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetRegistryInt(eRegistrySubTree, pchKey, piValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  InitiateGameConnection ( void *pBlob,  int cbMaxBlob,  CSteamID steamID,  CGameID nGameAppID,  uint32 unIPServer,  uint16 usPortServer,  bool bSecure,  void *pvSteam2GetEncryptionKey,  int cbSteam2GetEncryptionKey )	{
		char log[1024];
		sprintf(log,"InitiateGameConnection() pBlob=0x%X cbMaxBlob=0x%X steamID=0x%X nGameAppID=0x%X unIPServer=0x%X usPortServer=0x%X bSecure=0x%X pvSteam2GetEncryptionKey=0x%X cbSteam2GetEncryptionKey=0x%X ",
			pBlob,
			cbMaxBlob,
			steamID,
			nGameAppID,
			unIPServer,
			usPortServer,
			bSecure,
			pvSteam2GetEncryptionKey,
			cbSteam2GetEncryptionKey		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->InitiateGameConnection(pBlob, cbMaxBlob, steamID, nGameAppID, unIPServer, usPortServer, bSecure, pvSteam2GetEncryptionKey, cbSteam2GetEncryptionKey);
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
