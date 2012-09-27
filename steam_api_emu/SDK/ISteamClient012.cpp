#include "ISteamClient012.h"

class ISteamClient012_wrapper
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
	virtual HSteamUser  CreateLocalUser ( HSteamPipe *phSteamPipe,  EAccountType eAccountType )	{
		char log[1024];
		sprintf(log,"CreateLocalUser() phSteamPipe=0x%X eAccountType=0x%X ",
			phSteamPipe,
			eAccountType		);
		OutputDebugStringA(log);
		HSteamUser  ret = m_pWrapper->CreateLocalUser(phSteamPipe, eAccountType);
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
	virtual void * GetISteamGenericInterface ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamGenericInterface() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		void * ret = m_pWrapper->GetISteamGenericInterface(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamUserStats * GetISteamUserStats ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamUserStats() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamUserStats * ret = m_pWrapper->GetISteamUserStats(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamGameServerStats * GetISteamGameServerStats ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamGameServerStats() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamGameServerStats * ret = m_pWrapper->GetISteamGameServerStats(hSteamUser, hSteamPipe, pchVersion);
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
	virtual ISteamNetworking * GetISteamNetworking ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamNetworking() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamNetworking * ret = m_pWrapper->GetISteamNetworking(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamRemoteStorage * GetISteamRemoteStorage ( HSteamUser hSteamuser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamRemoteStorage() hSteamuser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamuser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamRemoteStorage * ret = m_pWrapper->GetISteamRemoteStorage(hSteamuser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamScreenshots * GetISteamScreenshots ( HSteamUser hSteamuser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamScreenshots() hSteamuser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamuser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamScreenshots * ret = m_pWrapper->GetISteamScreenshots(hSteamuser, hSteamPipe, pchVersion);
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
	virtual void  SetWarningMessageHook ( SteamAPIWarningMessageHook_t pFunction )	{
		char log[1024];
		sprintf(log,"SetWarningMessageHook() pFunction=0x%X ",
			pFunction		);
		OutputDebugStringA(log);
		pFunction);
		OutputDebugStringA("\n");
	}
	virtual bool  BShutdownIfAllPipesClosed ()	{
		char log[1024];
		sprintf(log,"BShutdownIfAllPipesClosed() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BShutdownIfAllPipesClosed();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ISteamHTTP*  GetISteamHTTP ( HSteamUser hSteamuser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetISteamHTTP() hSteamuser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamuser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		ISteamHTTP*  ret = m_pWrapper->GetISteamHTTP(hSteamuser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
