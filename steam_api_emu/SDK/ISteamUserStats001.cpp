#include "ISteamUserStats001.h"

class ISteamUserStats001_wrapper
{
public:
	virtual uint32  GetNumStats ( CGameID nGameID )	{
		char log[1024];
		sprintf(log,"GetNumStats() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNumStats(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetStatName ( CGameID nGameID,  uint32 iStat )	{
		char log[1024];
		sprintf(log,"GetStatName() nGameID=0x%X iStat=0x%X ",
			nGameID,
			iStat		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetStatName(nGameID, iStat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ESteamUserStatType  GetStatType ( CGameID nGameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"GetStatType() nGameID=0x%X pchName=%s ",
			nGameID,
			pchName		);
		OutputDebugStringA(log);
		ESteamUserStatType  ret = m_pWrapper->GetStatType(nGameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetNumAchievements ( CGameID nGameID )	{
		char log[1024];
		sprintf(log,"GetNumAchievements() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNumAchievements(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetAchievementName ( CGameID nGameID,  uint32 iAchievement )	{
		char log[1024];
		sprintf(log,"GetAchievementName() nGameID=0x%X iAchievement=0x%X ",
			nGameID,
			iAchievement		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetAchievementName(nGameID, iAchievement);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION uint32  GetNumGroupAchievements ( CGameID )	{
		char log[1024];
		sprintf(log,"GetNumGroupAchievements() CGameID=0x%X ",
			CGameID		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION uint32  ret = m_pWrapper->GetNumGroupAchievements(CGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION const char * GetGroupAchievementName ( CGameID,  uint32 iAchievement )	{
		char log[1024];
		sprintf(log,"GetGroupAchievementName() CGameID=0x%X iAchievement=0x%X ",
			CGameID,
			iAchievement		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION const char * ret = m_pWrapper->GetGroupAchievementName(CGameID, iAchievement);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestCurrentStats ( CGameID nGameID )	{
		char log[1024];
		sprintf(log,"RequestCurrentStats() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestCurrentStats(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetStat ( CGameID nGameID,  const char *pchName,  int32 *pData )	{
		char log[1024];
		sprintf(log,"GetStat() nGameID=0x%X pchName=%s pData=0x%X ",
			nGameID,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetStat(nGameID, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetStat ( CGameID nGameID,  const char *pchName,  float *pData )	{
		char log[1024];
		sprintf(log,"GetStat() nGameID=0x%X pchName=%s pData=0x%X ",
			nGameID,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetStat(nGameID, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetStat ( CGameID nGameID,  const char *pchName,  int32 nData )	{
		char log[1024];
		sprintf(log,"SetStat() nGameID=0x%X pchName=%s nData=0x%X ",
			nGameID,
			pchName,
			nData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetStat(nGameID, pchName, nData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetStat ( CGameID nGameID,  const char *pchName,  float fData )	{
		char log[1024];
		sprintf(log,"SetStat() nGameID=0x%X pchName=%s fData=0x%X ",
			nGameID,
			pchName,
			fData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetStat(nGameID, pchName, fData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UpdateAvgRateStat ( CGameID nGameID,  const char *pchName,  float,  double dSessionLength )	{
		char log[1024];
		sprintf(log,"UpdateAvgRateStat() nGameID=0x%X pchName=%s float=0x%X dSessionLength=0x%X ",
			nGameID,
			pchName,
			float,
			dSessionLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateAvgRateStat(nGameID, pchName, float, dSessionLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAchievement ( CGameID nGameID,  const char *pchName,  bool *pbAchieved )	{
		char log[1024];
		sprintf(log,"GetAchievement() nGameID=0x%X pchName=%s pbAchieved=0x%X ",
			nGameID,
			pchName,
			pbAchieved		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAchievement(nGameID, pchName, pbAchieved);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGroupAchievement ( CGameID nGameID,  const char *pchName,  bool *pbAchieved )	{
		char log[1024];
		sprintf(log,"GetGroupAchievement() nGameID=0x%X pchName=%s pbAchieved=0x%X ",
			nGameID,
			pchName,
			pbAchieved		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGroupAchievement(nGameID, pchName, pbAchieved);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetAchievement ( CGameID nGameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"SetAchievement() nGameID=0x%X pchName=%s ",
			nGameID,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetAchievement(nGameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetGroupAchievement ( CGameID nGameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"SetGroupAchievement() nGameID=0x%X pchName=%s ",
			nGameID,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetGroupAchievement(nGameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  StoreStats ( CGameID nGameID )	{
		char log[1024];
		sprintf(log,"StoreStats() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->StoreStats(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ClearAchievement ( CGameID nGameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"ClearAchievement() nGameID=0x%X pchName=%s ",
			nGameID,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ClearAchievement(nGameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ClearGroupAchievement ( CGameID nGameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"ClearGroupAchievement() nGameID=0x%X pchName=%s ",
			nGameID,
			pchName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ClearGroupAchievement(nGameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAchievementIcon ( CGameID nGameID,  const char *pchName )	{
		char log[1024];
		sprintf(log,"GetAchievementIcon() nGameID=0x%X pchName=%s ",
			nGameID,
			pchName		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAchievementIcon(nGameID, pchName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetAchievementDisplayAttribute ( CGameID nGameID,  const char *pchName,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"GetAchievementDisplayAttribute() nGameID=0x%X pchName=%s pchKey=%s ",
			nGameID,
			pchName,
			pchKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetAchievementDisplayAttribute(nGameID, pchName, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
