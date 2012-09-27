#include "ISteamUserStats004.h"

class ISteamUserStats004_wrapper
{
public:
	virtual bool  RequestCurrentStats ( )	{
		char log[1024];
		sprintf(log,"RequestCurrentStats() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestCurrentStats();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetStat ( const char *pchName,  int32 *pData )	{
		char log[1024];
		sprintf(log,"GetStat() pchName=%s pData=0x%X ",
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetStat(pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetStat ( const char *pchName,  float *pData )	{
		char log[1024];
		sprintf(log,"GetStat() pchName=%s pData=0x%X ",
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetStat(pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetStat ( const char *pchName,  int32 nData )	{
		char log[1024];
		sprintf(log,"SetStat() pchName=%s nData=0x%X ",
			pchName,
			nData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetStat(pchName, nData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetStat ( const char *pchName,  float fData )	{
		char log[1024];
		sprintf(log,"SetStat() pchName=%s fData=0x%X ",
			pchName,
			fData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetStat(pchName, fData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UpdateAvgRateStat ( const char *pchName,  float,  double dSessionLength )	{
		char log[1024];
		sprintf(log,"UpdateAvgRateStat() pchName=%s float=0x%X dSessionLength=0x%X ",
			pchName,
			float,
			dSessionLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateAvgRateStat(pchName, float, dSessionLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAchievement ( const char *pchName,  bool *pbAchieved )	{
		char log[1024];
		sprintf(log,"GetAchievement() pchName=%s pbAchieved=0x%X ",
			pchName,
			pbAchieved		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAchievement(pchName, pbAchieved);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetAchievement ( const char *pchName )	{
		char log[1024];
		sprintf(log,"SetAchievement() pchName=%s ",
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetAchievement(pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ClearAchievement ( const char *pchName )	{
		char log[1024];
		sprintf(log,"ClearAchievement() pchName=%s ",
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ClearAchievement(pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  StoreStats ( )	{
		char log[1024];
		sprintf(log,"StoreStats() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->StoreStats();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAchievementIcon ( const char *pchName )	{
		char log[1024];
		sprintf(log,"GetAchievementIcon() pchName=%s ",
			pchName		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAchievementIcon(pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetAchievementDisplayAttribute ( const char *pchName,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"GetAchievementDisplayAttribute() pchName=%s pchKey=%s ",
			pchName,
			pchKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetAchievementDisplayAttribute(pchName, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IndicateAchievementProgress ( const char *pchName,  uint32 nCurProgress,  uint32 nMaxProgress )	{
		char log[1024];
		sprintf(log,"IndicateAchievementProgress() pchName=%s nCurProgress=0x%X nMaxProgress=0x%X ",
			pchName,
			nCurProgress,
			nMaxProgress		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IndicateAchievementProgress(pchName, nCurProgress, nMaxProgress);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
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
	virtual bool  ResetAllStats ( bool bAchievementsToo )	{
		char log[1024];
		sprintf(log,"ResetAllStats() bAchievementsToo=0x%X ",
			bAchievementsToo		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ResetAllStats(bAchievementsToo);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
