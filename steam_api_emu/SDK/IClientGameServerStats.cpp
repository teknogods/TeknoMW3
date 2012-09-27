#include "IClientGameServerStats.h"

class IClientGameServerStats_wrapper
{
public:
	virtual SteamAPICall_t  RequestUserStats ( CSteamID steamIDUser,  CGameID gameID )	{
		char log[1024];
		sprintf(log,"RequestUserStats() steamIDUser=0x%X gameID=0x%X ",
			steamIDUser,
			gameID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestUserStats(steamIDUser, gameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserStat ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName,  int32 *pData )	{
		char log[1024];
		sprintf(log,"GetUserStat() steamIDUser=0x%X gameID=0x%X pchName=%s pData=0x%X ",
			steamIDUser,
			gameID,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserStat(steamIDUser, gameID, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserStat ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName,  float *pData )	{
		char log[1024];
		sprintf(log,"GetUserStat() steamIDUser=0x%X gameID=0x%X pchName=%s pData=0x%X ",
			steamIDUser,
			gameID,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserStat(steamIDUser, gameID, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserAchievement ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName,  bool *pbAchieved,  uint32* puUnk = NULL )	{
		char log[1024];
		sprintf(log,"GetUserAchievement() steamIDUser=0x%X gameID=0x%X pchName=%s pbAchieved=0x%X NULL=0x%X ",
			steamIDUser,
			gameID,
			pchName,
			pbAchieved,
			NULL		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserAchievement(steamIDUser, gameID, pchName, pbAchieved, NULL);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetUserStat ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName,  int32 nData )	{
		char log[1024];
		sprintf(log,"SetUserStat() steamIDUser=0x%X gameID=0x%X pchName=%s nData=0x%X ",
			steamIDUser,
			gameID,
			pchName,
			nData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetUserStat(steamIDUser, gameID, pchName, nData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetUserStat ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName,  float fData )	{
		char log[1024];
		sprintf(log,"SetUserStat() steamIDUser=0x%X gameID=0x%X pchName=%s fData=0x%X ",
			steamIDUser,
			gameID,
			pchName,
			fData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetUserStat(steamIDUser, gameID, pchName, fData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UpdateUserAvgRateStat ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName,  float flCountThisSession,  double dSessionLength )	{
		char log[1024];
		sprintf(log,"UpdateUserAvgRateStat() steamIDUser=0x%X gameID=0x%X pchName=%s flCountThisSession=0x%X dSessionLength=0x%X ",
			steamIDUser,
			gameID,
			pchName,
			flCountThisSession,
			dSessionLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateUserAvgRateStat(steamIDUser, gameID, pchName, flCountThisSession, dSessionLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetUserAchievement ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"SetUserAchievement() steamIDUser=0x%X gameID=0x%X pchName=%s ",
			steamIDUser,
			gameID,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetUserAchievement(steamIDUser, gameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ClearUserAchievement ( CSteamID steamIDUser,  CGameID gameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"ClearUserAchievement() steamIDUser=0x%X gameID=0x%X pchName=%s ",
			steamIDUser,
			gameID,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ClearUserAchievement(steamIDUser, gameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  StoreUserStats ( CSteamID steamIDUser,  CGameID gameID )	{
		char log[1024];
		sprintf(log,"StoreUserStats() steamIDUser=0x%X gameID=0x%X ",
			steamIDUser,
			gameID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->StoreUserStats(steamIDUser, gameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetMaxStatsLoaded ( uint32 uMax )	{
		char log[1024];
		sprintf(log,"SetMaxStatsLoaded() uMax=0x%X ",
			uMax		);
		OutputDebugStringA(log);
		uMax);
		OutputDebugStringA("\n");
	}
};
