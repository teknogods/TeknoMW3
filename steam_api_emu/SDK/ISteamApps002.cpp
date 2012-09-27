#include "ISteamApps002.h"

class ISteamApps002_wrapper
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
};
