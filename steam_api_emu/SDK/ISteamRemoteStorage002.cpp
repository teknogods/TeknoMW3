#include "ISteamRemoteStorage002.h"

class ISteamRemoteStorage002_wrapper
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
};
