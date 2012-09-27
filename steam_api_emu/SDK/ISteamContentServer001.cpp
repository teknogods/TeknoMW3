#include "ISteamContentServer001.h"

class ISteamContentServer001_wrapper
{
public:
	virtual bool  LogOn ( uint32 uContentServerID )	{
		char log[1024];
		sprintf(log,"LogOn() uContentServerID=0x%X ",
			uContentServerID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->LogOn(uContentServerID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  LogOff ()	{
		char log[1024];
		sprintf(log,"LogOff() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->LogOff();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BLoggedOn ()	{
		char log[1024];
		sprintf(log,"BLoggedOn() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BLoggedOn();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SendClientContentAuthRequest ( CSteamID steamId,  uint32 unContentID )	{
		char log[1024];
		sprintf(log,"SendClientContentAuthRequest() steamId=0x%X unContentID=0x%X ",
			steamId,
			unContentID		);
		OutputDebugStringA(log);
		steamId, unContentID);
		OutputDebugStringA("\n");
	}
};
