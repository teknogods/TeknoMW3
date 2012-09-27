#include "ISteamUtils001.h"

class ISteamUtils001_wrapper
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
};
