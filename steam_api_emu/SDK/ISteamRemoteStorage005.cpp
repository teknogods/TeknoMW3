#include "ISteamRemoteStorage005.h"

class ISteamRemoteStorage005_wrapper
{
public:
	virtual  FileWrite ( const char *pchFile,  const void *pvData,  int32 cubData )	{
		char log[1024];
		sprintf(log,"FileWrite() pchFile=%s pvData=0x%X cubData=0x%X ",
			pchFile,
			pvData,
			cubData		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->FileWrite(pchFile, pvData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  FileRead ( const char *pchFile,  void *pvData,  int32 cubDataToRead )	{
		char log[1024];
		sprintf(log,"FileRead() pchFile=%s pvData=0x%X cubDataToRead=0x%X ",
			pchFile,
			pvData,
			cubDataToRead		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->FileRead(pchFile, pvData, cubDataToRead);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  FileForget ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileForget() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->FileForget(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  FileDelete ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileDelete() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->FileDelete(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  FileShare ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileShare() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->FileShare(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  SetSyncPlatforms ( const char *pchFile,  ERemoteStoragePlatform eRemoteStoragePlatform )	{
		char log[1024];
		sprintf(log,"SetSyncPlatforms() pchFile=%s eRemoteStoragePlatform=0x%X ",
			pchFile,
			eRemoteStoragePlatform		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  FileExists ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileExists() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->FileExists(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  FilePersisted ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FilePersisted() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->FilePersisted(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  GetFileSize ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"GetFileSize() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->GetFileSize(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  GetFileTimestamp ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"GetFileTimestamp() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->GetFileTimestamp(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ERemoteStoragePlatform  GetSyncPlatforms ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"GetSyncPlatforms() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		ERemoteStoragePlatform  ret = m_pWrapper->GetSyncPlatforms(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetFileCount ()	{
		char log[1024];
		sprintf(log,"GetFileCount() "		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetFileCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetFileNameAndSize ( int iFile,  int32 *pnFileSizeInBytes )	{
		char log[1024];
		sprintf(log,"GetFileNameAndSize() iFile=0x%X pnFileSizeInBytes=0x%X ",
			iFile,
			pnFileSizeInBytes		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFileNameAndSize(iFile, pnFileSizeInBytes);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetQuota ( int32 *pnTotalBytes,  int32 *puAvailableBytes )	{
		char log[1024];
		sprintf(log,"GetQuota() pnTotalBytes=0x%X puAvailableBytes=0x%X ",
			pnTotalBytes,
			puAvailableBytes		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetQuota(pnTotalBytes, puAvailableBytes);
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
	virtual bool  IsCloudEnabledForApp ()	{
		char log[1024];
		sprintf(log,"IsCloudEnabledForApp() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsCloudEnabledForApp();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetCloudEnabledForApp ( bool bEnabled )	{
		char log[1024];
		sprintf(log,"SetCloudEnabledForApp() bEnabled=0x%X ",
			bEnabled		);
		OutputDebugStringA(log);
		bEnabled);
		OutputDebugStringA("\n");
	}
	virtual SteamAPICall_t  UGCDownload ( UGCHandle_t hContent )	{
		char log[1024];
		sprintf(log,"UGCDownload() hContent=0x%X ",
			hContent		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UGCDownload(hContent);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  GetUGCDetails ( UGCHandle_t hContent,  AppId_t *pnAppID,  char **ppchName,  int32 *pnFileSizeInBytes,  CSteamID *pSteamIDOwner )	{
		char log[1024];
		sprintf(log,"GetUGCDetails() hContent=0x%X pnAppID=0x%X ppchName=%s pnFileSizeInBytes=0x%X pSteamIDOwner=0x%X ",
			hContent,
			pnAppID,
			ppchName,
			pnFileSizeInBytes,
			pSteamIDOwner		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->GetUGCDetails(hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  UGCRead ( UGCHandle_t hContent,  void *pvData,  int32 cubDataToRead )	{
		char log[1024];
		sprintf(log,"UGCRead() hContent=0x%X pvData=0x%X cubDataToRead=0x%X ",
			hContent,
			pvData,
			cubDataToRead		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->UGCRead(hContent, pvData, cubDataToRead);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual  GetCachedUGCCount ()	{
		char log[1024];
		sprintf(log,"GetCachedUGCCount() "		);
		OutputDebugStringA(log);
		 ret = m_pWrapper->GetCachedUGCCount();
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
	virtual SteamAPICall_t  PublishFile ( const char *cszFileName,  const char *cszPreviewFileName,  AppId_t nConsumerAppId,  const char *cszTitle,  const char *cszDescription,  ERemoteStoragePublishedFileVisibility eRemoteStoragePublishedFileVisibility,  SteamParamStringArray_t *pTags )	{
		char log[1024];
		sprintf(log,"PublishFile() cszFileName=%s cszPreviewFileName=%s nConsumerAppId=0x%X cszTitle=%s cszDescription=%s eRemoteStoragePublishedFileVisibility=0x%X pTags=0x%X ",
			cszFileName,
			cszPreviewFileName,
			nConsumerAppId,
			cszTitle,
			cszDescription,
			eRemoteStoragePublishedFileVisibility,
			pTags		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->PublishFile(cszFileName, cszPreviewFileName, nConsumerAppId, cszTitle, cszDescription, eRemoteStoragePublishedFileVisibility, pTags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  PublishWorkshopFile ( const char *cszFileName,  const char *cszPreviewFileName,  AppId_t nConsumerAppId,  const char *cszTitle,  const char *cszDescription,  SteamParamStringArray_t *pTags )	{
		char log[1024];
		sprintf(log,"PublishWorkshopFile() cszFileName=%s cszPreviewFileName=%s nConsumerAppId=0x%X cszTitle=%s cszDescription=%s pTags=0x%X ",
			cszFileName,
			cszPreviewFileName,
			nConsumerAppId,
			cszTitle,
			cszDescription,
			pTags		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->PublishWorkshopFile(cszFileName, cszPreviewFileName, nConsumerAppId, cszTitle, cszDescription, pTags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UpdatePublishedFile ( RemoteStorageUpdatePublishedFileRequest_t remoteStorageUpdatePublishedFileRequest )	{
		char log[1024];
		sprintf(log,"UpdatePublishedFile() remoteStorageUpdatePublishedFileRequest=0x%X ",
			remoteStorageUpdatePublishedFileRequest		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UpdatePublishedFile(remoteStorageUpdatePublishedFileRequest);
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
	virtual SteamAPICall_t  EnumerateUserPublishedFiles ( uint32 uStartIndex )	{
		char log[1024];
		sprintf(log,"EnumerateUserPublishedFiles() uStartIndex=0x%X ",
			uStartIndex		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->EnumerateUserPublishedFiles(uStartIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  SubscribePublishedFile ( uint64 ullPublishedFile )	{
		char log[1024];
		sprintf(log,"SubscribePublishedFile() ullPublishedFile=0x%X ",
			ullPublishedFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->SubscribePublishedFile(ullPublishedFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  EnumerateUserSubscribedFiles ( uint32 uStartIndex )	{
		char log[1024];
		sprintf(log,"EnumerateUserSubscribedFiles() uStartIndex=0x%X ",
			uStartIndex		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->EnumerateUserSubscribedFiles(uStartIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UnsubscribePublishedFile ( uint64 ullPublishedFile )	{
		char log[1024];
		sprintf(log,"UnsubscribePublishedFile() ullPublishedFile=0x%X ",
			ullPublishedFile		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UnsubscribePublishedFile(ullPublishedFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
