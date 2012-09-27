#include "ISteamUtils002.h"

class ISteamUtils002_wrapper
{
public:
	virtual uint32  GetSecondsSinceAppActive ()	{
		char log[1024];
		sprintf(log,"GetSecondsSinceAppActive() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetSecondsSinceAppActive();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetSecondsSinceComputerActive ()	{
		char log[1024];
		sprintf(log,"GetSecondsSinceComputerActive() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetSecondsSinceComputerActive();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EUniverse  GetConnectedUniverse ()	{
		char log[1024];
		sprintf(log,"GetConnectedUniverse() "		);
		OutputDebugStringA(log);
		EUniverse  ret = m_pWrapper->GetConnectedUniverse();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetServerRealTime ()	{
		char log[1024];
		sprintf(log,"GetServerRealTime() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetServerRealTime();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetIPCountry ()	{
		char log[1024];
		sprintf(log,"GetIPCountry() "		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetIPCountry();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetImageSize ( int iImage,  uint32 *pnWidth,  uint32 *pnHeight )	{
		char log[1024];
		sprintf(log,"GetImageSize() iImage=0x%X pnWidth=0x%X pnHeight=0x%X ",
			iImage,
			pnWidth,
			pnHeight		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetImageSize(iImage, pnWidth, pnHeight);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetImageRGBA ( int iImage,  uint8 *pubDest,  int nDestBufferSize )	{
		char log[1024];
		sprintf(log,"GetImageRGBA() iImage=0x%X pubDest=0x%X nDestBufferSize=0x%X ",
			iImage,
			pubDest,
			nDestBufferSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetImageRGBA(iImage, pubDest, nDestBufferSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetCSERIPPort ( uint32 *unIP,  uint16 *usPort )	{
		char log[1024];
		sprintf(log,"GetCSERIPPort() unIP=0x%X usPort=0x%X ",
			unIP,
			usPort		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetCSERIPPort(unIP, usPort);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint8  GetCurrentBatteryPower ()	{
		char log[1024];
		sprintf(log,"GetCurrentBatteryPower() "		);
		OutputDebugStringA(log);
		uint8  ret = m_pWrapper->GetCurrentBatteryPower();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
