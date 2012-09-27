#include "ISteamRemoteStorage003.h"

class ISteamRemoteStorage003_wrapper
{
public:
	virtual bool  FileWrite ( const char *pchFile,  const void *pvData,  int32 cubData )	{
		char log[1024];
		sprintf(log,"FileWrite() pchFile=%s pvData=0x%X cubData=0x%X ",
			pchFile,
			pvData,
			cubData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileWrite(pchFile, pvData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  FileRead ( const char *pchFile,  void *pvData,  int32 cubDataToRead )	{
		char log[1024];
		sprintf(log,"FileRead() pchFile=%s pvData=0x%X cubDataToRead=0x%X ",
			pchFile,
			pvData,
			cubDataToRead		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->FileRead(pchFile, pvData, cubDataToRead);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileForget ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileForget() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileForget(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileDelete ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileDelete() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileDelete(pchFile);
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
	virtual bool  FileExists ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FileExists() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileExists(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FilePersisted ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"FilePersisted() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FilePersisted(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetFileSize ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"GetFileSize() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetFileSize(pchFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int64  GetFileTimestamp ( const char *pchFile )	{
		char log[1024];
		sprintf(log,"GetFileTimestamp() pchFile=%s ",
			pchFile		);
		OutputDebugStringA(log);
		int64  ret = m_pWrapper->GetFileTimestamp(pchFile);
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
	virtual bool  IsCloudEnabledThisApp ()	{
		char log[1024];
		sprintf(log,"IsCloudEnabledThisApp() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsCloudEnabledThisApp();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetCloudEnabledThisApp ( bool bEnable )	{
		char log[1024];
		sprintf(log,"SetCloudEnabledThisApp() bEnable=0x%X ",
			bEnable		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetCloudEnabledThisApp(bEnable);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  UGCDownload ( unsigned long long )	{
		char log[1024];
		sprintf(log,"UGCDownload() long=0x%X ",
			long		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->UGCDownload(long);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUGCDetails ( unsigned long long,  unsigned int *,  char **,  int *,  CSteamID * )	{
		char log[1024];
		sprintf(log,"GetUGCDetails() long=0x%X =0x%X =%s =0x%X =0x%X ",
			long,
			,
			,
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUGCDetails(long, , , , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  UGCRead ( unsigned long long,  void *,  int )	{
		char log[1024];
		sprintf(log,"UGCRead() long=0x%X =0x%X int=0x%X ",
			long,
			,
			int		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->UGCRead(long, , int);
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
	virtual uint64  GetCachedUGCHandle ( int )	{
		char log[1024];
		sprintf(log,"GetCachedUGCHandle() int=0x%X ",
			int		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->GetCachedUGCHandle(int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
