#include "ISteamClient006.h"

class ISteamClient006_wrapper
{
public:
	virtual HSteamPipe  CreateSteamPipe ()	{
		char log[1024];
		sprintf(log,"CreateSteamPipe() "		);
		OutputDebugStringA(log);
		HSteamPipe  ret = m_pWrapper->CreateSteamPipe();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BReleaseSteamPipe ( HSteamPipe hSteamPipe )	{
		char log[1024];
		sprintf(log,"BReleaseSteamPipe() hSteamPipe=0x%X ",
			hSteamPipe		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BReleaseSteamPipe(hSteamPipe);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HSteamUser  CreateGlobalUser ( HSteamPipe *phSteamPipe )	{
		char log[1024];
		sprintf(log,"CreateGlobalUser() phSteamPipe=0x%X ",
			phSteamPipe		);
		OutputDebugStringA(log);
		HSteamUser  ret = m_pWrapper->CreateGlobalUser(phSteamPipe);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HSteamUser  ConnectToGlobalUser ( HSteamPipe hSteamPipe )	{
		char log[1024];
		sprintf(log,"ConnectToGlobalUser() hSteamPipe=0x%X ",
			hSteamPipe		);
		OutputDebugStringA(log);
		HSteamUser  ret = m_pWrapper->ConnectToGlobalUser(hSteamPipe);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HSteamUser  CreateLocalUser ( HSteamPipe *phSteamPipe )	{
		char log[1024];
		sprintf(log,"CreateLocalUser() phSteamPipe=0x%X ",
			phSteamPipe		);
		OutputDebugStringA(log);
		HSteamUser  ret = m_pWrapper->CreateLocalUser(phSteamPipe);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ReleaseUser ( HSteamPipe hSteamPipe,  HSteamUser hUser )	{
		char log[1024];
		sprintf(log,"ReleaseUser() hSteamPipe=0x%X hUser=0x%X ",
			hSteamPipe,
			hUser		);
		OutputDebugStringA(log);
		hSteamPipe, hUser);
		OutputDebugStringA("\n");
	}
	virtual ISteamUser * GetISteamUser ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamUser() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamUser * ret = m_pWrapper->GetISteamUser(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION IVAC * GetIVAC ( HSteamUser hSteamUser )	{
		char log[1024];
		sprintf(log,"GetIVAC() hSteamUser=0x%X ",
			hSteamUser		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION IVAC * ret = m_pWrapper->GetIVAC(hSteamUser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamGameServer * GetISteamGameServer ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamGameServer() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamGameServer * ret = m_pWrapper->GetISteamGameServer(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetLocalIPBinding ( uint32 unIP,  uint16 usPort )	{
		char log[1024];
		sprintf(log,"SetLocalIPBinding() unIP=0x%X usPort=0x%X ",
			unIP,
			usPort		);
		OutputDebugStringA(log);
		unIP, usPort);
		OutputDebugStringA("\n");
	}
	virtual const char * GetUniverseName ( EUniverse eUniverse )	{
		char log[1024];
		sprintf(log,"GetUniverseName() eUniverse=0x%X ",
			eUniverse		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetUniverseName(eUniverse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamFriends * GetISteamFriends ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamFriends() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamFriends * ret = m_pWrapper->GetISteamFriends(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamUtils * GetISteamUtils ( HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamUtils() hSteamPipe=0x%X pchVersion=%s ",
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamUtils * ret = m_pWrapper->GetISteamUtils(hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamBilling * GetISteamBilling ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamBilling() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamBilling * ret = m_pWrapper->GetISteamBilling(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamMatchmaking * GetISteamMatchmaking ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamMatchmaking() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamMatchmaking * ret = m_pWrapper->GetISteamMatchmaking(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamContentServer * GetISteamContentServer ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamContentServer() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamContentServer * ret = m_pWrapper->GetISteamContentServer(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamApps * GetISteamApps ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamApps() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamApps * ret = m_pWrapper->GetISteamApps(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamMasterServerUpdater * GetISteamMasterServerUpdater ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamMasterServerUpdater() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamMasterServerUpdater * ret = m_pWrapper->GetISteamMasterServerUpdater(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamMatchmakingServers * GetISteamMatchmakingServers ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamMatchmakingServers() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamMatchmakingServers * ret = m_pWrapper->GetISteamMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RunFrame ()	{
		char log[1024];
		sprintf(log,"RunFrame() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual uint32  GetIPCCallCount ()	{
		char log[1024];
		sprintf(log,"GetIPCCallCount() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetIPCCallCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
