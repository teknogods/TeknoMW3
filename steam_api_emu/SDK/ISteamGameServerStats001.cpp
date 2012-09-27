#include "ISteamGameServerStats001.h"

class ISteamGameServerStats001_wrapper
{
public:
	virtual SteamAPICall_t  RequestUserStats ( CSteamID steamIDUser )	{
		char log[1024];
		sprintf(log,"RequestUserStats() steamIDUser=0x%X ",
			steamIDUser		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestUserStats(steamIDUser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserStat ( CSteamID steamIDUser,  const char *pchName,  int32 *pData )	{
		char log[1024];
		sprintf(log,"GetUserStat() steamIDUser=0x%X pchName=%s pData=0x%X ",
			steamIDUser,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserStat(steamIDUser, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserStat ( CSteamID steamIDUser,  const char *pchName,  float *pData )	{
		char log[1024];
		sprintf(log,"GetUserStat() steamIDUser=0x%X pchName=%s pData=0x%X ",
			steamIDUser,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserStat(steamIDUser, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserAchievement ( CSteamID steamIDUser,  const char *pchName,  bool *pbAchieved )	{
		char log[1024];
		sprintf(log,"GetUserAchievement() steamIDUser=0x%X pchName=%s pbAchieved=0x%X ",
			steamIDUser,
			pchName,
			pbAchieved		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserAchievement(steamIDUser, pchName, pbAchieved);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetUserStat ( CSteamID steamIDUser,  const char *pchName,  int32 nData )	{
		char log[1024];
		sprintf(log,"SetUserStat() steamIDUser=0x%X pchName=%s nData=0x%X ",
			steamIDUser,
			pchName,
			nData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetUserStat(steamIDUser, pchName, nData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetUserStat ( CSteamID steamIDUser,  const char *pchName,  float fData )	{
		char log[1024];
		sprintf(log,"SetUserStat() steamIDUser=0x%X pchName=%s fData=0x%X ",
			steamIDUser,
			pchName,
			fData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetUserStat(steamIDUser, pchName, fData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UpdateUserAvgRateStat ( CSteamID steamIDUser,  const char *pchName,  float flCountThisSession,  double dSessionLength )	{
		char log[1024];
		sprintf(log,"UpdateUserAvgRateStat() steamIDUser=0x%X pchName=%s flCountThisSession=0x%X dSessionLength=0x%X ",
			steamIDUser,
			pchName,
			flCountThisSession,
			dSessionLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateUserAvgRateStat(steamIDUser, pchName, flCountThisSession, dSessionLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetUserAchievement ( CSteamID steamIDUser,  const char *pchName )	{
		char log[1024];
		sprintf(log,"SetUserAchievement() steamIDUser=0x%X pchName=%s ",
			steamIDUser,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetUserAchievement(steamIDUser, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ClearUserAchievement ( CSteamID steamIDUser,  const char *pchName )	{
		char log[1024];
		sprintf(log,"ClearUserAchievement() steamIDUser=0x%X pchName=%s ",
			steamIDUser,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ClearUserAchievement(steamIDUser, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  StoreUserStats ( CSteamID steamIDUser )	{
		char log[1024];
		sprintf(log,"StoreUserStats() steamIDUser=0x%X ",
			steamIDUser		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->StoreUserStats(steamIDUser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
