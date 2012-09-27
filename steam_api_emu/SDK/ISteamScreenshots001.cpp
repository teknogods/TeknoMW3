#include "ISteamScreenshots001.h"

class ISteamScreenshots001_wrapper
{
public:
	virtual HScreenshot  WriteScreenshot ( const uint8 *pubRGBData,  uint32 uRGBDataSize,  int32 iWidth,  int32 iHeight )	{
		char log[1024];
		sprintf(log,"WriteScreenshot() pubRGBData=0x%X uRGBDataSize=0x%X iWidth=0x%X iHeight=0x%X ",
			pubRGBData,
			uRGBDataSize,
			iWidth,
			iHeight		);
		OutputDebugStringA(log);
		HScreenshot  ret = m_pWrapper->WriteScreenshot(pubRGBData, uRGBDataSize, iWidth, iHeight);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HScreenshot  AddScreenshotToLibrary ( const char* cszScreenshotPath,  const char* cszThumbnailPath,  int32 iWidth,  int32 iHeight )	{
		char log[1024];
		sprintf(log,"AddScreenshotToLibrary() cszScreenshotPath=%s cszThumbnailPath=%s iWidth=0x%X iHeight=0x%X ",
			cszScreenshotPath,
			cszThumbnailPath,
			iWidth,
			iHeight		);
		OutputDebugStringA(log);
		HScreenshot  ret = m_pWrapper->AddScreenshotToLibrary(cszScreenshotPath, cszThumbnailPath, iWidth, iHeight);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  TriggerScreenshot ()	{
		char log[1024];
		sprintf(log,"TriggerScreenshot() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  HookScreenshots ( bool )	{
		char log[1024];
		sprintf(log,"HookScreenshots() bool=0x%X ",
			bool		);
		OutputDebugStringA(log);
		bool);
		OutputDebugStringA("\n");
	}
	virtual bool  SetLocation ( HScreenshot hScreenshot,  const char * cszLocation )	{
		char log[1024];
		sprintf(log,"SetLocation() hScreenshot=0x%X cszLocation=%s ",
			hScreenshot,
			cszLocation		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLocation(hScreenshot, cszLocation);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  TagUser ( HScreenshot hScreenshot,  CSteamID steamIDUser )	{
		char log[1024];
		sprintf(log,"TagUser() hScreenshot=0x%X steamIDUser=0x%X ",
			hScreenshot,
			steamIDUser		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->TagUser(hScreenshot, steamIDUser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
