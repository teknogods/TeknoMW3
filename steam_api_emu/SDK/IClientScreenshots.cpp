#include "IClientScreenshots.h"

	virtual const char * GetShortcutDisplayName ( CGameID gameID )	{
		char log[1024];
		sprintf(log,"GetShortcutDisplayName() gameID=0x%X ",
			gameID		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetShortcutDisplayName(gameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetShortcutDisplayName ( CGameID,  const char *cszName )	{
		char log[1024];
		sprintf(log,"SetShortcutDisplayName() CGameID=0x%X cszName=%s ",
			CGameID,
			cszName		);
		OutputDebugStringA(log);
		CGameID, cszName);
		OutputDebugStringA("\n");
	}
	virtual HScreenshot  WriteScreenshot ( CGameID,  const uint8 *pubRGBData,  uint32 uRGBDataSize,  int32 iWidth,  int32 iHeight )	{
		char log[1024];
		sprintf(log,"WriteScreenshot() CGameID=0x%X pubRGBData=0x%X uRGBDataSize=0x%X iWidth=0x%X iHeight=0x%X ",
			CGameID,
			pubRGBData,
			uRGBDataSize,
			iWidth,
			iHeight		);
		OutputDebugStringA(log);
		HScreenshot  ret = m_pWrapper->WriteScreenshot(CGameID, pubRGBData, uRGBDataSize, iWidth, iHeight);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HScreenshot  AddScreenshotToLibrary ( CGameID,  const char *cszScreenshotPath,  const char *cszThumbnailPath,  int32 iWidth,  int32 iHeight )	{
		char log[1024];
		sprintf(log,"AddScreenshotToLibrary() CGameID=0x%X cszScreenshotPath=%s cszThumbnailPath=%s iWidth=0x%X iHeight=0x%X ",
			CGameID,
			cszScreenshotPath,
			cszThumbnailPath,
			iWidth,
			iHeight		);
		OutputDebugStringA(log);
		HScreenshot  ret = m_pWrapper->AddScreenshotToLibrary(CGameID, cszScreenshotPath, cszThumbnailPath, iWidth, iHeight);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  TriggerScreenshot ( CGameID gameID )	{
		char log[1024];
		sprintf(log,"TriggerScreenshot() gameID=0x%X ",
			gameID		);
		OutputDebugStringA(log);
		gameID);
		OutputDebugStringA("\n");
	}
	virtual void  RequestScreenshotFromGame ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"RequestScreenshotFromGame() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		nAppId);
		OutputDebugStringA("\n");
	}
	virtual bool  SetLocation ( CGameID gameID,  HScreenshot hScreenshot,  const char *cszLocation )	{
		char log[1024];
		sprintf(log,"SetLocation() gameID=0x%X hScreenshot=0x%X cszLocation=%s ",
			gameID,
			hScreenshot,
			cszLocation		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLocation(gameID, hScreenshot, cszLocation);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  TagUser ( CGameID gameID,  HScreenshot hScreenshot,  CSteamID userID )	{
		char log[1024];
		sprintf(log,"TagUser() gameID=0x%X hScreenshot=0x%X userID=0x%X ",
			gameID,
			hScreenshot,
			userID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->TagUser(gameID, hScreenshot, userID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ResolvePath ( CGameID gameID,  HScreenshot hScreenshot,  bool bUnk,  char *szResolvedPath,  uint32 cubResolvedPath )	{
		char log[1024];
		sprintf(log,"ResolvePath() gameID=0x%X hScreenshot=0x%X bUnk=0x%X szResolvedPath=%s cubResolvedPath=0x%X ",
			gameID,
			hScreenshot,
			bUnk,
			szResolvedPath,
			cubResolvedPath		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ResolvePath(gameID, hScreenshot, bUnk, szResolvedPath, cubResolvedPath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetSizeOnDisk ( CGameID gameID,  HScreenshot hScreenshot )	{
		char log[1024];
		sprintf(log,"GetSizeOnDisk() gameID=0x%X hScreenshot=0x%X ",
			gameID,
			hScreenshot		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetSizeOnDisk(gameID, hScreenshot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetSizeInCloud ( CGameID gameID,  HScreenshot hScreenshot )	{
		char log[1024];
		sprintf(log,"GetSizeInCloud() gameID=0x%X hScreenshot=0x%X ",
			gameID,
			hScreenshot		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetSizeInCloud(gameID, hScreenshot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsPersisted ( CGameID gameID,  HScreenshot hScreenshot )	{
		char log[1024];
		sprintf(log,"IsPersisted() gameID=0x%X hScreenshot=0x%X ",
			gameID,
			hScreenshot		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsPersisted(gameID, hScreenshot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetNumGamesWithLocalScreenshots ()	{
		char log[1024];
		sprintf(log,"GetNumGamesWithLocalScreenshots() "		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetNumGamesWithLocalScreenshots();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CGameID  GetGameWithLocalScreenshots ( int32 iGameIndex )	{
		char log[1024];
		sprintf(log,"GetGameWithLocalScreenshots() iGameIndex=0x%X ",
			iGameIndex		);
		OutputDebugStringA(log);
		CGameID  ret = m_pWrapper->GetGameWithLocalScreenshots(iGameIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetLocalScreenshotCount ( CGameID gameID )	{
		char log[1024];
		sprintf(log,"GetLocalScreenshotCount() gameID=0x%X ",
			gameID		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetLocalScreenshotCount(gameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetLocalScreenshot ( CGameID gameID,  int32 iScreenshotIndex,  HScreenshot* phScreenshot,  int32 *piWidth,  int32 *piHeight,  uint32 *puTimestamp,  EUCMFilePrivacyState *pePrivacy,  uint64* pullFileID,  char *pchCaption,  uint32 cubCaption )	{
		char log[1024];
		sprintf(log,"GetLocalScreenshot() gameID=0x%X iScreenshotIndex=0x%X phScreenshot=0x%X piWidth=0x%X piHeight=0x%X puTimestamp=0x%X pePrivacy=0x%X pullFileID=0x%X pchCaption=%s cubCaption=0x%X ",
			gameID,
			iScreenshotIndex,
			phScreenshot,
			piWidth,
			piHeight,
			puTimestamp,
			pePrivacy,
			pullFileID,
			pchCaption,
			cubCaption		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLocalScreenshot(gameID, iScreenshotIndex, phScreenshot, piWidth, piHeight, puTimestamp, pePrivacy, pullFileID, pchCaption, cubCaption);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLocalScreenshotCaption ( CGameID gameID,  HScreenshot hScreenshot,  const char *cszCaption )	{
		char log[1024];
		sprintf(log,"SetLocalScreenshotCaption() gameID=0x%X hScreenshot=0x%X cszCaption=%s ",
			gameID,
			hScreenshot,
			cszCaption		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLocalScreenshotCaption(gameID, hScreenshot, cszCaption);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLocalScreenshotPrivacy ( CGameID gameID,  HScreenshot hScreenshot,  EUCMFilePrivacyState ePrivacy )	{
		char log[1024];
		sprintf(log,"SetLocalScreenshotPrivacy() gameID=0x%X hScreenshot=0x%X ePrivacy=0x%X ",
			gameID,
			hScreenshot,
			ePrivacy		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLocalScreenshotPrivacy(gameID, hScreenshot, ePrivacy);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  StartBatch ( CGameID gameID )	{
		char log[1024];
		sprintf(log,"StartBatch() gameID=0x%X ",
			gameID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->StartBatch(gameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddToBatch ( HScreenshot hScreenshot )	{
		char log[1024];
		sprintf(log,"AddToBatch() hScreenshot=0x%X ",
			hScreenshot		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddToBatch(hScreenshot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UploadBatch ( EUCMFilePrivacyState ePrivacy )	{
		char log[1024];
		sprintf(log,"UploadBatch() ePrivacy=0x%X ",
			ePrivacy		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UploadBatch(ePrivacy);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  DeleteBatch ( bool bDeleteFromCloud )	{
		char log[1024];
		sprintf(log,"DeleteBatch() bDeleteFromCloud=0x%X ",
			bDeleteFromCloud		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DeleteBatch(bDeleteFromCloud);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  CancelBatch ()	{
		char log[1024];
		sprintf(log,"CancelBatch() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->CancelBatch();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RecoverOldScreenshots ()	{
		char log[1024];
		sprintf(log,"RecoverOldScreenshots() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual int32  GetTaggedUserCount ( CGameID gameID,  HScreenshot hScreenshot )	{
		char log[1024];
		sprintf(log,"GetTaggedUserCount() gameID=0x%X hScreenshot=0x%X ",
			gameID,
			hScreenshot		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetTaggedUserCount(gameID, hScreenshot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetTaggedUser ( CGameID gameID,  HScreenshot hScreenshot,  int32 iUserIndex )	{
		char log[1024];
		sprintf(log,"GetTaggedUser() gameID=0x%X hScreenshot=0x%X iUserIndex=0x%X ",
			gameID,
			hScreenshot,
			iUserIndex		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetTaggedUser(gameID, hScreenshot, iUserIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetLocation ( CGameID gameID,  HScreenshot hScreenshot,  char *pchLocation,  uint32 cubLocation )	{
		char log[1024];
		sprintf(log,"GetLocation() gameID=0x%X hScreenshot=0x%X pchLocation=%s cubLocation=0x%X ",
			gameID,
			hScreenshot,
			pchLocation,
			cubLocation		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLocation(gameID, hScreenshot, pchLocation, cubLocation);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
