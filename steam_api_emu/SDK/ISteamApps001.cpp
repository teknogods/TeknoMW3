#include "ISteamApps001.h"

class ISteamApps001_wrapper
{
public:
	virtual int  GetAppData ( AppId_t nAppID,  const char *pchKey,  char *pchValue,  int cchValueMax )	{
		char log[1024];
		sprintf(log,"GetAppData() nAppID=0x%X pchKey=%s pchValue=%s cchValueMax=0x%X ",
			nAppID,
			pchKey,
			pchValue,
			cchValueMax		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppData(nAppID, pchKey, pchValue, cchValueMax);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
