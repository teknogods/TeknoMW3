#include "ISteamUserStats010.h"

class ISteamUserStats010_wrapper
{
public:
	virtual bool  RequestCurrentStats ()	{
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
	virtual bool  UpdateAvgRateStat ( const char *pchName,  float flCountThisSession,  double dSessionLength )	{
		char log[1024];
		sprintf(log,"UpdateAvgRateStat() pchName=%s flCountThisSession=0x%X dSessionLength=0x%X ",
			pchName,
			flCountThisSession,
			dSessionLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateAvgRateStat(pchName, flCountThisSession, dSessionLength);
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
	virtual bool  GetAchievementAndUnlockTime ( const char *pchName,  bool *pbAchieved,  uint32 *punUnlockTime )	{
		char log[1024];
		sprintf(log,"GetAchievementAndUnlockTime() pchName=%s pbAchieved=0x%X punUnlockTime=0x%X ",
			pchName,
			pbAchieved,
			punUnlockTime		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAchievementAndUnlockTime(pchName, pbAchieved, punUnlockTime);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  StoreStats ()	{
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
	virtual bool  GetUserAchievementAndUnlockTime ( CSteamID steamIDUser,  const char *pchName,  bool *pbAchieved,  uint32 *punUnlockTime )	{
		char log[1024];
		sprintf(log,"GetUserAchievementAndUnlockTime() steamIDUser=0x%X pchName=%s pbAchieved=0x%X punUnlockTime=0x%X ",
			steamIDUser,
			pchName,
			pbAchieved,
			punUnlockTime		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserAchievementAndUnlockTime(steamIDUser, pchName, pbAchieved, punUnlockTime);
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
	virtual const char * GetLeaderboardName ( SteamLeaderboard_t hSteamLeaderboard )	{
		char log[1024];
		sprintf(log,"GetLeaderboardName() hSteamLeaderboard=0x%X ",
			hSteamLeaderboard		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetLeaderboardName(hSteamLeaderboard);
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
	virtual SteamAPICall_t  DownloadLeaderboardEntriesForUsers ( SteamLeaderboard_t hSteamLeaderboard,  CSteamID *prgUsers,  int cUsers )	{
		char log[1024];
		sprintf(log,"DownloadLeaderboardEntriesForUsers() hSteamLeaderboard=0x%X prgUsers=0x%X cUsers=0x%X ",
			hSteamLeaderboard,
			prgUsers,
			cUsers		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DownloadLeaderboardEntriesForUsers(hSteamLeaderboard, prgUsers, cUsers);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetDownloadedLeaderboardEntry ( SteamLeaderboardEntries_t hSteamLeaderboardEntries,  int index,  LeaderboardEntry_t *pLeaderboardEntry,  int32 *pDetails,  int cDetailsMax )	{
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
	virtual SteamAPICall_t  UploadLeaderboardScore ( SteamLeaderboard_t hSteamLeaderboard,  ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod,  int32 nScore,  const int32 *pScoreDetails,  int cScoreDetailsCount )	{
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
	virtual SteamAPICall_t  AttachLeaderboardUGC ( SteamLeaderboard_t hSteamLeaderboard,  UGCHandle_t hUGC )	{
		char log[1024];
		sprintf(log,"AttachLeaderboardUGC() hSteamLeaderboard=0x%X hUGC=0x%X ",
			hSteamLeaderboard,
			hUGC		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->AttachLeaderboardUGC(hSteamLeaderboard, hUGC);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  GetNumberOfCurrentPlayers ()	{
		char log[1024];
		sprintf(log,"GetNumberOfCurrentPlayers() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetNumberOfCurrentPlayers();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestGlobalAchievementPercentages ()	{
		char log[1024];
		sprintf(log,"RequestGlobalAchievementPercentages() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestGlobalAchievementPercentages();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetMostAchievedAchievementInfo ( char *pchName,  uint32 unNameBufLen,  float *pflPercent,  bool *pbAchieved )	{
		char log[1024];
		sprintf(log,"GetMostAchievedAchievementInfo() pchName=%s unNameBufLen=0x%X pflPercent=0x%X pbAchieved=0x%X ",
			pchName,
			unNameBufLen,
			pflPercent,
			pbAchieved		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetMostAchievedAchievementInfo(pchName, unNameBufLen, pflPercent, pbAchieved);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetNextMostAchievedAchievementInfo ( int iIteratorPrevious,  char *pchName,  uint32 unNameBufLen,  float *pflPercent,  bool *pbAchieved )	{
		char log[1024];
		sprintf(log,"GetNextMostAchievedAchievementInfo() iIteratorPrevious=0x%X pchName=%s unNameBufLen=0x%X pflPercent=0x%X pbAchieved=0x%X ",
			iIteratorPrevious,
			pchName,
			unNameBufLen,
			pflPercent,
			pbAchieved		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetNextMostAchievedAchievementInfo(iIteratorPrevious, pchName, unNameBufLen, pflPercent, pbAchieved);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAchievementAchievedPercent ( const char *pchName,  float *pflPercent )	{
		char log[1024];
		sprintf(log,"GetAchievementAchievedPercent() pchName=%s pflPercent=0x%X ",
			pchName,
			pflPercent		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAchievementAchievedPercent(pchName, pflPercent);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestGlobalStats ( int nHistoryDays )	{
		char log[1024];
		sprintf(log,"RequestGlobalStats() nHistoryDays=0x%X ",
			nHistoryDays		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestGlobalStats(nHistoryDays);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGlobalStat ( const char *pchStatName,  int64 *pData )	{
		char log[1024];
		sprintf(log,"GetGlobalStat() pchStatName=%s pData=0x%X ",
			pchStatName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGlobalStat(pchStatName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGlobalStat ( const char *pchStatName,  double *pData )	{
		char log[1024];
		sprintf(log,"GetGlobalStat() pchStatName=%s pData=0x%X ",
			pchStatName,
			pData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGlobalStat(pchStatName, pData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetGlobalStatHistory ( const char *pchStatName,  int64 *pData,  uint32 cubData )	{
		char log[1024];
		sprintf(log,"GetGlobalStatHistory() pchStatName=%s pData=0x%X cubData=0x%X ",
			pchStatName,
			pData,
			cubData		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetGlobalStatHistory(pchStatName, pData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetGlobalStatHistory ( const char *pchStatName,  double *pData,  uint32 cubData )	{
		char log[1024];
		sprintf(log,"GetGlobalStatHistory() pchStatName=%s pData=0x%X cubData=0x%X ",
			pchStatName,
			pData,
			cubData		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetGlobalStatHistory(pchStatName, pData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
