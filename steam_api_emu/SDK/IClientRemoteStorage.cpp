#include "IClientRemoteStorage.h"

	virtual bool  FileWrite ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile,  const void *pvData,  int cubData )	{
		char log[1024];
		sprintf(log,"FileWrite() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s pvData=0x%X cubData=0x%X ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile,
			pvData,
			cubData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileWrite(nAppId, eRemoteStorageFileRoot, pchFile, pvData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetFileSize ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile  )	{
		char log[1024];
		sprintf(log,"GetFileSize() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetFileSize(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  FileRead ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile,  void *pvData,  int cubDataToRead )	{
		char log[1024];
		sprintf(log,"FileRead() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s pvData=0x%X cubDataToRead=0x%X ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile,
			pvData,
			cubDataToRead		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->FileRead(nAppId, eRemoteStorageFileRoot, pchFile, pvData, cubDataToRead);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileForget ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileForget() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileForget(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileDelete ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileDelete() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileDelete(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  FileShare ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileShare() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->FileShare(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileExists ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileExists() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileExists(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FilePersisted ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"FilePersisted() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FilePersisted(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int64  GetFileTimestamp ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"GetFileTimestamp() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		int64  ret = m_pWrapper->GetFileTimestamp(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetSyncPlatforms ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile,  ERemoteStoragePlatform eRemoteStoragePlatform )	{
		char log[1024];
		sprintf(log,"SetSyncPlatforms() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s eRemoteStoragePlatform=0x%X ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile,
			eRemoteStoragePlatform		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetSyncPlatforms(nAppId, eRemoteStorageFileRoot, pchFile, eRemoteStoragePlatform);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSyncPlatforms ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"GetSyncPlatforms() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSyncPlatforms(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetFileCount ( AppId_t nAppId,  bool bUnk1 )	{
		char log[1024];
		sprintf(log,"GetFileCount() nAppId=0x%X bUnk1=0x%X ",
			nAppId,
			bUnk1		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetFileCount(nAppId, bUnk1);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetFileNameAndSize ( AppId_t nAppId,  int iFile,  ERemoteStorageFileRoot *peRemoteStorageFileRoot,  int *pnFileSizeInBytes,  bool bUnk1 )	{
		char log[1024];
		sprintf(log,"GetFileNameAndSize() nAppId=0x%X iFile=0x%X peRemoteStorageFileRoot=0x%X pnFileSizeInBytes=0x%X bUnk1=0x%X ",
			nAppId,
			iFile,
			peRemoteStorageFileRoot,
			pnFileSizeInBytes,
			bUnk1		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFileNameAndSize(nAppId, iFile, peRemoteStorageFileRoot, pnFileSizeInBytes, bUnk1);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetQuota ( AppId_t nAppId,  int32 *pnTotalBytes,  int32 *pnAvailableBytes )	{
		char log[1024];
		sprintf(log,"GetQuota() nAppId=0x%X pnTotalBytes=0x%X pnAvailableBytes=0x%X ",
			nAppId,
			pnTotalBytes,
			pnAvailableBytes		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetQuota(nAppId, pnTotalBytes, pnAvailableBytes);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsCloudEnabledForAccount ()	{
		char log[1024];
		sprintf(log,"IsCloudEnabledForAccount() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsCloudEnabledForAccount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsCloudEnabledForApp ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"IsCloudEnabledForApp() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsCloudEnabledForApp(nAppId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetCloudEnabledForApp ( AppId_t nAppId,  bool bEnable )	{
		char log[1024];
		sprintf(log,"SetCloudEnabledForApp() nAppId=0x%X bEnable=0x%X ",
			nAppId,
			bEnable		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetCloudEnabledForApp(nAppId, bEnable);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UGCDownload ( UGCHandle_t hContent,  bool bUseNewCallback )	{
		char log[1024];
		sprintf(log,"UGCDownload() hContent=0x%X bUseNewCallback=0x%X ",
			hContent,
			bUseNewCallback		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UGCDownload(hContent, bUseNewCallback);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUGCDetails ( UGCHandle_t hContent,  AppId_t *pnAppID,  char **ppchName,  int32 *pnFileSizeInBytes,  CSteamID *pSteamIDOwner )	{
		char log[1024];
		sprintf(log,"GetUGCDetails() hContent=0x%X pnAppID=0x%X ppchName=%s pnFileSizeInBytes=0x%X pSteamIDOwner=0x%X ",
			hContent,
			pnAppID,
			ppchName,
			pnFileSizeInBytes,
			pSteamIDOwner		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUGCDetails(hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  UGCRead ( UGCHandle_t hContent,  void *pubDest,  int32 nDestBufferSize )	{
		char log[1024];
		sprintf(log,"UGCRead() hContent=0x%X pubDest=0x%X nDestBufferSize=0x%X ",
			hContent,
			pubDest,
			nDestBufferSize		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->UGCRead(hContent, pubDest, nDestBufferSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetCachedUGCCount ()	{
		char log[1024];
		sprintf(log,"GetCachedUGCCount() "		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetCachedUGCCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual UGCHandle_t  GetCachedUGCHandle ( int32 iCachedContent )	{
		char log[1024];
		sprintf(log,"GetCachedUGCHandle() iCachedContent=0x%X ",
			iCachedContent		);
		OutputDebugStringA(log);
		UGCHandle_t  ret = m_pWrapper->GetCachedUGCHandle(iCachedContent);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  PublishFile ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *cszFileName,  const char *cszPreviewFileName,  AppId_t nConsumerAppId ,  const char *cszTitle,  const char *cszDescription,  ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility,  bool bOverwrite,  SteamParamStringArray_t *pTags,  bool bWorkshopFile )	{
		char log[1024];
		sprintf(log,"PublishFile() nAppId=0x%X eRemoteStorageFileRoot=0x%X cszFileName=%s cszPreviewFileName=%s nConsumerAppId=0x%X cszTitle=%s cszDescription=%s eRemoteStoragePublishedFileVisibility=0x%X bOverwrite=0x%X pTags=0x%X bWorkshopFile=0x%X ",
			nAppId,
			eRemoteStorageFileRoot,
			cszFileName,
			cszPreviewFileName,
			nConsumerAppId,
			cszTitle,
			cszDescription,
			eRemoteStoragePublishedFileVisibility,
			bOverwrite,
			pTags,
			bWorkshopFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->PublishFile(nAppId, eRemoteStorageFileRoot, cszFileName, cszPreviewFileName, nConsumerAppId, cszTitle, cszDescription, eRemoteStoragePublishedFileVisibility, bOverwrite, pTags, bWorkshopFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UpdatePublishedFile ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  RemoteStorageUpdatePublishedFileRequest_t remoteStorageUpdatePublishedFileRequest )	{
		char log[1024];
		sprintf(log,"UpdatePublishedFile() nAppId=0x%X eRemoteStorageFileRoot=0x%X remoteStorageUpdatePublishedFileRequest=0x%X ",
			nAppId,
			eRemoteStorageFileRoot,
			remoteStorageUpdatePublishedFileRequest		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UpdatePublishedFile(nAppId, eRemoteStorageFileRoot, remoteStorageUpdatePublishedFileRequest);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  GetPublishedFileDetails ( uint64 ullPublishedFile )	{
		char log[1024];
		sprintf(log,"GetPublishedFileDetails() ullPublishedFile=0x%X ",
			ullPublishedFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetPublishedFileDetails(ullPublishedFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  DeletePublishedFile ( uint64 ullPublishedFile )	{
		char log[1024];
		sprintf(log,"DeletePublishedFile() ullPublishedFile=0x%X ",
			ullPublishedFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DeletePublishedFile(ullPublishedFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  EnumerateUserPublishedFiles ( AppId_t nAppId,  uint32 uStartIndex,  ERemoteStoragePublishedFileSortOrder eOrder )	{
		char log[1024];
		sprintf(log,"EnumerateUserPublishedFiles() nAppId=0x%X uStartIndex=0x%X eOrder=0x%X ",
			nAppId,
			uStartIndex,
			eOrder		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->EnumerateUserPublishedFiles(nAppId, uStartIndex, eOrder);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  SubscribePublishedFile ( AppId_t nAppId,  uint64 ullPublishedFile )	{
		char log[1024];
		sprintf(log,"SubscribePublishedFile() nAppId=0x%X ullPublishedFile=0x%X ",
			nAppId,
			ullPublishedFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->SubscribePublishedFile(nAppId, ullPublishedFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  EnumerateUserSubscribedFiles ( AppId_t nAppId,  uint32 uStartIndex )	{
		char log[1024];
		sprintf(log,"EnumerateUserSubscribedFiles() nAppId=0x%X uStartIndex=0x%X ",
			nAppId,
			uStartIndex		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->EnumerateUserSubscribedFiles(nAppId, uStartIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UnsubscribePublishedFile ( AppId_t nAppId,  uint64 ullPublishedFile )	{
		char log[1024];
		sprintf(log,"UnsubscribePublishedFile() nAppId=0x%X ullPublishedFile=0x%X ",
			nAppId,
			ullPublishedFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UnsubscribePublishedFile(nAppId, ullPublishedFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  FilePersist ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"FilePersist() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->FilePersist(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileFetch ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileFetch() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileFetch(nAppId, eRemoteStorageFileRoot, pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ResolvePath ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *,  char *,  uint32 )	{
		char log[1024];
		sprintf(log,"ResolvePath() nAppId=0x%X eRemoteStorageFileRoot=0x%X =%s =%s uint32=0x%X ",
			nAppId,
			eRemoteStorageFileRoot,
			,
			,
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ResolvePath(nAppId, eRemoteStorageFileRoot, , , uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  FileTouch ( AppId_t nAppId,  ERemoteStorageFileRoot eRemoteStorageFileRoot,  const char *pchFile,  bool )	{
		char log[1024];
		sprintf(log,"FileTouch() nAppId=0x%X eRemoteStorageFileRoot=0x%X pchFile=%s bool=0x%X ",
			nAppId,
			eRemoteStorageFileRoot,
			pchFile,
			bool		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->FileTouch(nAppId, eRemoteStorageFileRoot, pchFile, bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetCloudEnabledForAccount ( bool bEnable )	{
		char log[1024];
		sprintf(log,"SetCloudEnabledForAccount() bEnable=0x%X ",
			bEnable		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetCloudEnabledForAccount(bEnable);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  LoadLocalFileInfoCache ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"LoadLocalFileInfoCache() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		nAppId);
		OutputDebugStringA("\n");
	}
	virtual void  EvaluateRemoteStorageSyncState ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"EvaluateRemoteStorageSyncState() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		nAppId);
		OutputDebugStringA("\n");
	}
	virtual ERemoteStorageSyncState  GetRemoteStorageSyncState ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"GetRemoteStorageSyncState() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		ERemoteStorageSyncState  ret = m_pWrapper->GetRemoteStorageSyncState(nAppId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  HaveLatestFilesLocally ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"HaveLatestFilesLocally() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HaveLatestFilesLocally(nAppId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetConflictingFileTimestamps ( AppId_t nAppId,  RTime32 * puTimestamp1,  RTime32 * puTimestamp2 )	{
		char log[1024];
		sprintf(log,"GetConflictingFileTimestamps() nAppId=0x%X puTimestamp1=0x%X puTimestamp2=0x%X ",
			nAppId,
			puTimestamp1,
			puTimestamp2		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetConflictingFileTimestamps(nAppId, puTimestamp1, puTimestamp2);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ResolveSyncConflict ( AppId_t nAppId,  bool )	{
		char log[1024];
		sprintf(log,"ResolveSyncConflict() nAppId=0x%X bool=0x%X ",
			nAppId,
			bool		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ResolveSyncConflict(nAppId, bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SynchronizeApp ( AppId_t nAppId,  bool bSyncClient,  bool bSyncServer )	{
		char log[1024];
		sprintf(log,"SynchronizeApp() nAppId=0x%X bSyncClient=0x%X bSyncServer=0x%X ",
			nAppId,
			bSyncClient,
			bSyncServer		);
		OutputDebugStringA(log);
		nAppId, bSyncClient, bSyncServer);
		OutputDebugStringA("\n");
	}
	virtual bool  IsAppSyncInProgress ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"IsAppSyncInProgress() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsAppSyncInProgress(nAppId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ERemoteStorageFileRoot  ERemoteStorageFileRootFromName ( const char *cszName )	{
		char log[1024];
		sprintf(log,"ERemoteStorageFileRootFromName() cszName=%s ",
			cszName		);
		OutputDebugStringA(log);
		ERemoteStorageFileRoot  ret = m_pWrapper->ERemoteStorageFileRootFromName(cszName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char*  PchNameFromERemoteStorageFileRoot ( ERemoteStorageFileRoot eRemoteStorageFileRoot )	{
		char log[1024];
		sprintf(log,"PchNameFromERemoteStorageFileRoot() eRemoteStorageFileRoot=0x%X ",
			eRemoteStorageFileRoot		);
		OutputDebugStringA(log);
		const char*  ret = m_pWrapper->PchNameFromERemoteStorageFileRoot(eRemoteStorageFileRoot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ResetFileRequestState ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"ResetFileRequestState() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ResetFileRequestState(nAppId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
