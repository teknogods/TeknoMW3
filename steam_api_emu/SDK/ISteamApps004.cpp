#include "ISteamApps004.h"

class ISteamApps004_wrapper
{
public:
	virtual bool  BIsSubscribed ()	{
		char log[1024];
		sprintf(log,"BIsSubscribed() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsSubscribed();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsLowViolence ()	{
		char log[1024];
		sprintf(log,"BIsLowViolence() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsLowViolence();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsCybercafe ()	{
		char log[1024];
		sprintf(log,"BIsCybercafe() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsCybercafe();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsVACBanned ()	{
		char log[1024];
		sprintf(log,"BIsVACBanned() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsVACBanned();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetCurrentGameLanguage ()	{
		char log[1024];
		sprintf(log,"GetCurrentGameLanguage() "		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetCurrentGameLanguage();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetAvailableGameLanguages ()	{
		char log[1024];
		sprintf(log,"GetAvailableGameLanguages() "		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetAvailableGameLanguages();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsSubscribedApp ( AppId_t appID )	{
		char log[1024];
		sprintf(log,"BIsSubscribedApp() appID=0x%X ",
			appID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsSubscribedApp(appID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsDlcInstalled ( AppId_t appID )	{
		char log[1024];
		sprintf(log,"BIsDlcInstalled() appID=0x%X ",
			appID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsDlcInstalled(appID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetEarliestPurchaseUnixTime ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"GetEarliestPurchaseUnixTime() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetEarliestPurchaseUnixTime(nAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsSubscribedFromFreeWeekend ()	{
		char log[1024];
		sprintf(log,"BIsSubscribedFromFreeWeekend() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsSubscribedFromFreeWeekend();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetDLCCount ()	{
		char log[1024];
		sprintf(log,"GetDLCCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetDLCCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetDLCDataByIndex ( int iDLC,  AppId_t *pAppID,  bool *pbAvailable,  char *pchName,  int cchNameBufferSize )	{
		char log[1024];
		sprintf(log,"BGetDLCDataByIndex() iDLC=0x%X pAppID=0x%X pbAvailable=0x%X pchName=%s cchNameBufferSize=0x%X ",
			iDLC,
			pAppID,
			pbAvailable,
			pchName,
			cchNameBufferSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetDLCDataByIndex(iDLC, pAppID, pbAvailable, pchName, cchNameBufferSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  InstallDLC ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"InstallDLC() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		nAppID);
		OutputDebugStringA("\n");
	}
	virtual void  UninstallDLC ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"UninstallDLC() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		nAppID);
		OutputDebugStringA("\n");
	}
};
