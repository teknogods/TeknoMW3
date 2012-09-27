#include "IClientUserStats.h"

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
	virtual const char *  GetStatName ( CGameID nGameID,  uint32 iStat )	{
		char log[1024];
		sprintf(log,"GetStatName() nGameID=0x%X iStat=0x%X ",
			nGameID,
			iStat		);
		OutputDebugStringA(log);
		const char *  ret = m_pWrapper->GetStatName(nGameID, iStat);
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
	virtual const char *  GetAchievementName ( CGameID nGameID,  uint32 iAchievement )	{
		char log[1024];
		sprintf(log,"GetAchievementName() nGameID=0x%X iAchievement=0x%X ",
			nGameID,
			iAchievement		);
		OutputDebugStringA(log);
		const char *  ret = m_pWrapper->GetAchievementName(nGameID, iAchievement);
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
	virtual bool  GetStat ( CGameID nGameID,  const char *pchName,  int *pData )	{
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
	virtual bool  SetStat ( CGameID nGameID,  const char *pchName,  int nData )	{
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
	virtual bool  UpdateAvgRateStat ( CGameID nGameID,  const char *pchName,  float flCountThisSession,  double dSessionLength )	{
		char log[1024];
		sprintf(log,"UpdateAvgRateStat() nGameID=0x%X pchName=%s flCountThisSession=0x%X dSessionLength=0x%X ",
			nGameID,
			pchName,
			flCountThisSession,
			dSessionLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateAvgRateStat(nGameID, pchName, flCountThisSession, dSessionLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAchievement ( CGameID nGameID,  const char *pchName,  bool *pbAchieved,  uint32 * )	{
		char log[1024];
		sprintf(log,"GetAchievement() nGameID=0x%X pchName=%s pbAchieved=0x%X =0x%X ",
			nGameID,
			pchName,
			pbAchieved,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAchievement(nGameID, pchName, pbAchieved, );
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
	virtual int  GetAchievementIcon ( CGameID nGameID,  const char *pchName,  EGetAchievementIcon )	{
		char log[1024];
		sprintf(log,"GetAchievementIcon() nGameID=0x%X pchName=%s EGetAchievementIcon=0x%X ",
			nGameID,
			pchName,
			EGetAchievementIcon		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAchievementIcon(nGameID, pchName, EGetAchievementIcon);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char *  GetAchievementDisplayAttribute ( CGameID nGameID,  const char *pchName,  const char *pchKey,  bool )	{
		char log[1024];
		sprintf(log,"GetAchievementDisplayAttribute() nGameID=0x%X pchName=%s pchKey=%s bool=0x%X ",
			nGameID,
			pchName,
			pchKey,
			bool		);
		OutputDebugStringA(log);
		const char *  ret = m_pWrapper->GetAchievementDisplayAttribute(nGameID, pchName, pchKey, bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IndicateAchievementProgress ( CGameID nGameID,  const char *pchName,  uint32 nCurProgress,  uint32 nMaxProgress )	{
		char log[1024];
		sprintf(log,"IndicateAchievementProgress() nGameID=0x%X pchName=%s nCurProgress=0x%X nMaxProgress=0x%X ",
			nGameID,
			pchName,
			nCurProgress,
			nMaxProgress		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IndicateAchievementProgress(nGameID, pchName, nCurProgress, nMaxProgress);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetMaxStatsLoaded ( uint32 uMax )	{
		char log[1024];
		sprintf(log,"SetMaxStatsLoaded() uMax=0x%X ",
			uMax		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetMaxStatsLoaded(uMax);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestUserStats ( CSteamID steamIDUser,  CGameID nGameID )	{
		char log[1024];
		sprintf(log,"RequestUserStats() steamIDUser=0x%X nGameID=0x%X ",
			steamIDUser,
			nGameID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestUserStats(steamIDUser, nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserStat ( CSteamID steamIDUser,  CGameID nGameID,  const char *pchName,  int *pData )	{
		char log[1024];
		sprintf(log,"GetUserStat() steamIDUser=0x%X nGameID=0x%X pchName=%s pData=0x%X ",
			steamIDUser,
			nGameID,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserStat(steamIDUser, nGameID, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserStat ( CSteamID steamIDUser,  CGameID nGameID,  const char *pchName,  float *pData )	{
		char log[1024];
		sprintf(log,"GetUserStat() steamIDUser=0x%X nGameID=0x%X pchName=%s pData=0x%X ",
			steamIDUser,
			nGameID,
			pchName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserStat(steamIDUser, nGameID, pchName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserAchievement ( CSteamID steamIDUser,  CGameID nGameID,  const char  *pchName,  bool *pbAchieved,  uint32 * )	{
		char log[1024];
		sprintf(log,"GetUserAchievement() steamIDUser=0x%X nGameID=0x%X pchName=%s pbAchieved=0x%X =0x%X ",
			steamIDUser,
			nGameID,
			pchName,
			pbAchieved,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserAchievement(steamIDUser, nGameID, pchName, pbAchieved, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ResetAllStats ( CGameID nGameID,  bool bAchievementsToo )	{
		char log[1024];
		sprintf(log,"ResetAllStats() nGameID=0x%X bAchievementsToo=0x%X ",
			nGameID,
			bAchievementsToo		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ResetAllStats(nGameID, bAchievementsToo);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  FindOrCreateLeaderboard ( const char *pchLeaderboardName,  ELeaderboardSortMethod eLeaderboardSortMethod,  ELeaderboardDisplayType eLeaderboardDisplayType )	{
		char log[1024];
		sprintf(log,"FindOrCreateLeaderboard() pchLeaderboardName=%s eLeaderboardSortMethod=0x%X eLeaderboardDisplayType=0x%X ",
			pchLeaderboardName,
			eLeaderboardSortMethod,
			eLeaderboardDisplayType		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->FindOrCreateLeaderboard(pchLeaderboardName, eLeaderboardSortMethod, eLeaderboardDisplayType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  FindLeaderboard ( const char *pchLeaderboardName )	{
		char log[1024];
		sprintf(log,"FindLeaderboard() pchLeaderboardName=%s ",
			pchLeaderboardName		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->FindLeaderboard(pchLeaderboardName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char *  GetLeaderboardName ( SteamLeaderboard_t hSteamLeaderboard )	{
		char log[1024];
		sprintf(log,"GetLeaderboardName() hSteamLeaderboard=0x%X ",
			hSteamLeaderboard		);
		OutputDebugStringA(log);
		const char *  ret = m_pWrapper->GetLeaderboardName(hSteamLeaderboard);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetLeaderboardEntryCount ( SteamLeaderboard_t hSteamLeaderboard )	{
		char log[1024];
		sprintf(log,"GetLeaderboardEntryCount() hSteamLeaderboard=0x%X ",
			hSteamLeaderboard		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetLeaderboardEntryCount(hSteamLeaderboard);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ELeaderboardSortMethod  GetLeaderboardSortMethod ( SteamLeaderboard_t hSteamLeaderboard )	{
		char log[1024];
		sprintf(log,"GetLeaderboardSortMethod() hSteamLeaderboard=0x%X ",
			hSteamLeaderboard		);
		OutputDebugStringA(log);
		ELeaderboardSortMethod  ret = m_pWrapper->GetLeaderboardSortMethod(hSteamLeaderboard);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ELeaderboardDisplayType  GetLeaderboardDisplayType ( SteamLeaderboard_t hSteamLeaderboard )	{
		char log[1024];
		sprintf(log,"GetLeaderboardDisplayType() hSteamLeaderboard=0x%X ",
			hSteamLeaderboard		);
		OutputDebugStringA(log);
		ELeaderboardDisplayType  ret = m_pWrapper->GetLeaderboardDisplayType(hSteamLeaderboard);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  DownloadLeaderboardEntries ( SteamLeaderboard_t hSteamLeaderboard,  ELeaderboardDataRequest eLeaderboardDataRequest,  int nRangeStart,  int nRangeEnd )	{
		char log[1024];
		sprintf(log,"DownloadLeaderboardEntries() hSteamLeaderboard=0x%X eLeaderboardDataRequest=0x%X nRangeStart=0x%X nRangeEnd=0x%X ",
			hSteamLeaderboard,
			eLeaderboardDataRequest,
			nRangeStart,
			nRangeEnd		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DownloadLeaderboardEntries(hSteamLeaderboard, eLeaderboardDataRequest, nRangeStart, nRangeEnd);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  DownloadLeaderboardEntriesForUsers ( SteamLeaderboard_t hSteamLeaderboard,  CSteamID *,  int )	{
		char log[1024];
		sprintf(log,"DownloadLeaderboardEntriesForUsers() hSteamLeaderboard=0x%X =0x%X int=0x%X ",
			hSteamLeaderboard,
			,
			int		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, , int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetDownloadedLeaderboardEntry ( SteamLeaderboardEntries_t hSteamLeaderboardEntries,  int index,  LeaderboardEntry_t *pLeaderboardEntry,  int *pDetails,  int cDetailsMax )	{
		char log[1024];
		sprintf(log,"GetDownloadedLeaderboardEntry() hSteamLeaderboardEntries=0x%X index=0x%X pLeaderboardEntry=0x%X pDetails=0x%X cDetailsMax=0x%X ",
			hSteamLeaderboardEntries,
			index,
			pLeaderboardEntry,
			pDetails,
			cDetailsMax		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetDownloadedLeaderboardEntry(hSteamLeaderboardEntries, index, pLeaderboardEntry, pDetails, cDetailsMax);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  AttachLeaderboardUGC ( SteamLeaderboard_t hSteamLeaderboard,  uint64 Unk1 )	{
		char log[1024];
		sprintf(log,"AttachLeaderboardUGC() hSteamLeaderboard=0x%X Unk1=0x%X ",
			hSteamLeaderboard,
			Unk1		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->AttachLeaderboardUGC(hSteamLeaderboard, Unk1);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UploadLeaderboardScore ( SteamLeaderboard_t hSteamLeaderboard,  ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod,  int nScore,  const int *pScoreDetails,  int cScoreDetailsCount )	{
		char log[1024];
		sprintf(log,"UploadLeaderboardScore() hSteamLeaderboard=0x%X eLeaderboardUploadScoreMethod=0x%X nScore=0x%X pScoreDetails=0x%X cScoreDetailsCount=0x%X ",
			hSteamLeaderboard,
			eLeaderboardUploadScoreMethod,
			nScore,
			pScoreDetails,
			cScoreDetailsCount		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UploadLeaderboardScore(hSteamLeaderboard, eLeaderboardUploadScoreMethod, nScore, pScoreDetails, cScoreDetailsCount);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  GetNumberOfCurrentPlayers (  )	{
		char log[1024];
		sprintf(log,"GetNumberOfCurrentPlayers() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetNumberOfCurrentPlayers();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetNumAchievedAchievements ( CGameID nGameID )	{
		char log[1024];
		sprintf(log,"GetNumAchievedAchievements() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNumAchievedAchievements(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetLastAchievementUnlocked ( CGameID nGameID )	{
		char log[1024];
		sprintf(log,"GetLastAchievementUnlocked() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetLastAchievementUnlocked(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestGlobalAchievementPercentages ( CGameID nGameID )	{
		char log[1024];
		sprintf(log,"RequestGlobalAchievementPercentages() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestGlobalAchievementPercentages(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetMostAchievedAchievementInfo ( CGameID nGameID,  char *a,  uint32 b,  float *c,  bool *d )	{
		char log[1024];
		sprintf(log,"GetMostAchievedAchievementInfo() nGameID=0x%X a=%s b=0x%X c=0x%X d=0x%X ",
			nGameID,
			a,
			b,
			c,
			d		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetMostAchievedAchievementInfo(nGameID, a, b, c, d);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetNextMostAchievedAchievementInfo ( CGameID nGameID,  int a,  char *b,  uint32 c,  float *d,  bool *f )	{
		char log[1024];
		sprintf(log,"GetNextMostAchievedAchievementInfo() nGameID=0x%X a=0x%X b=%s c=0x%X d=0x%X f=0x%X ",
			nGameID,
			a,
			b,
			c,
			d,
			f		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetNextMostAchievedAchievementInfo(nGameID, a, b, c, d, f);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAchievementAchievedPercent ( CGameID nGameID,  char  const*,  float * )	{
		char log[1024];
		sprintf(log,"GetAchievementAchievedPercent() nGameID=0x%X =%s =0x%X ",
			nGameID,
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAchievementAchievedPercent(nGameID, , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestGlobalStats ( CGameID nGameID,  int )	{
		char log[1024];
		sprintf(log,"RequestGlobalStats() nGameID=0x%X int=0x%X ",
			nGameID,
			int		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestGlobalStats(nGameID, int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGlobalStat ( CGameID nGameID,  char const* pchName,  long long * )	{
		char log[1024];
		sprintf(log,"GetGlobalStat() nGameID=0x%X pchName=%s =0x%X ",
			nGameID,
			pchName,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGlobalStat(nGameID, pchName, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGlobalStat ( CGameID nGameID,  char const* pchName,  double * )	{
		char log[1024];
		sprintf(log,"GetGlobalStat() nGameID=0x%X pchName=%s =0x%X ",
			nGameID,
			pchName,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGlobalStat(nGameID, pchName, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetGlobalStatHistory ( CGameID nGameID,  char const* pchName,  long long *,  unsigned int )	{
		char log[1024];
		sprintf(log,"GetGlobalStatHistory() nGameID=0x%X pchName=%s =0x%X int=0x%X ",
			nGameID,
			pchName,
			,
			int		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetGlobalStatHistory(nGameID, pchName, , int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetGlobalStatHistory ( CGameID nGameID,  char const* pchName,  double *,  unsigned int )	{
		char log[1024];
		sprintf(log,"GetGlobalStatHistory() nGameID=0x%X pchName=%s =0x%X int=0x%X ",
			nGameID,
			pchName,
			,
			int		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetGlobalStatHistory(nGameID, pchName, , int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
