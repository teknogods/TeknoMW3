#include "IClientEngine.h"

class IClientApps;_wrapper
{
public:
class IClientBilling;_wrapper
{
public:
class IClientContentServer;_wrapper
{
public:
class IClientFriends;_wrapper
{
public:
class IClientGameCoordinator;_wrapper
{
public:
class IClientGameServer;_wrapper
{
public:
class IClientGameServerItems;_wrapper
{
public:
class IClientGameStats;_wrapper
{
public:
class IClientMasterServerUpdater;_wrapper
{
public:
class IClientMatchmaking;_wrapper
{
public:
class IClientMatchmakingServers;_wrapper
{
public:
class IClientNetworking;_wrapper
{
public:
class IClientRemoteStorage;_wrapper
{
public:
class IClientUser;_wrapper
{
public:
class IClientUserItems;_wrapper
{
public:
class IClientUserStats;_wrapper
{
public:
class IClientUtils;_wrapper
{
public:
class IP2PController;_wrapper
{
public:
class IClientAppManager;_wrapper
{
public:
class IClientDepotBuilder;_wrapper
{
public:
class IConCommandBaseAccessor;_wrapper
{
public:
class IClientGameCoordinator;_wrapper
{
public:
class IClientHTTP;_wrapper
{
public:
class IClientGameServerStats;_wrapper
{
public:
class IClientConfigStore;_wrapper
{
public:
class IClientScreenshots;_wrapper
{
public:
class IClientAudio;_wrapper
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
	virtual HSteamUser  CreateGlobalUser ( HSteamPipe* phSteamPipe )	{
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
	virtual HSteamUser  CreateLocalUser ( HSteamPipe* phSteamPipe,  EAccountType eAccountType )	{
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
	virtual bool  IsValidHSteamUserPipe ( HSteamPipe hSteamPipe,  HSteamUser hUser )	{
		char log[1024];
		sprintf(log,"IsValidHSteamUserPipe() hSteamPipe=0x%X hUser=0x%X ",
			hSteamPipe,
			hUser		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsValidHSteamUserPipe(hSteamPipe, hUser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientUser * GetIClientUser ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientUser() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientUser * ret = m_pWrapper->GetIClientUser(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientGameServer * GetIClientGameServer ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientGameServer() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientGameServer * ret = m_pWrapper->GetIClientGameServer(hSteamUser, hSteamPipe, pchVersion);
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
	virtual char const * GetUniverseName ( EUniverse eUniverse )	{
		char log[1024];
		sprintf(log,"GetUniverseName() eUniverse=0x%X ",
			eUniverse		);
		OutputDebugStringA(log);
		char const * ret = m_pWrapper->GetUniverseName(eUniverse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientFriends * GetIClientFriends ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientFriends() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientFriends * ret = m_pWrapper->GetIClientFriends(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientUtils * GetIClientUtils ( HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientUtils() hSteamPipe=0x%X pchVersion=%s ",
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientUtils * ret = m_pWrapper->GetIClientUtils(hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientBilling * GetIClientBilling ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientBilling() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientBilling * ret = m_pWrapper->GetIClientBilling(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientMatchmaking * GetIClientMatchmaking ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientMatchmaking() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientMatchmaking * ret = m_pWrapper->GetIClientMatchmaking(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientApps * GetIClientApps ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientApps() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientApps * ret = m_pWrapper->GetIClientApps(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientContentServer * GetIClientContentServer ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientContentServer() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientContentServer * ret = m_pWrapper->GetIClientContentServer(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientMatchmakingServers * GetIClientMatchmakingServers ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientMatchmakingServers() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientMatchmakingServers * ret = m_pWrapper->GetIClientMatchmakingServers(hSteamUser, hSteamPipe, pchVersion);
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
	virtual IClientUserStats * GetIClientUserStats ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientUserStats() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientUserStats * ret = m_pWrapper->GetIClientUserStats(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientGameServerStats * GetIClientGameServerStats ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientGameServerStats() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientGameServerStats * ret = m_pWrapper->GetIClientGameServerStats(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientNetworking * GetIClientNetworking ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientNetworking() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientNetworking * ret = m_pWrapper->GetIClientNetworking(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientRemoteStorage * GetIClientRemoteStorage ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientRemoteStorage() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientRemoteStorage * ret = m_pWrapper->GetIClientRemoteStorage(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientScreenshots * GetIClientScreenshots ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientScreenshots() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientScreenshots * ret = m_pWrapper->GetIClientScreenshots(hSteamUser, hSteamPipe, pchVersion);
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
	virtual IClientGameCoordinator * GetIClientGameCoordinator ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientGameCoordinator() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientGameCoordinator * ret = m_pWrapper->GetIClientGameCoordinator(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetOverlayNotificationPosition ( ENotificationPosition eNotificationPosition )	{
		char log[1024];
		sprintf(log,"SetOverlayNotificationPosition() eNotificationPosition=0x%X ",
			eNotificationPosition		);
		OutputDebugStringA(log);
		eNotificationPosition);
		OutputDebugStringA("\n");
	}
	virtual bool  HookScreenshots ( bool bHook )	{
		char log[1024];
		sprintf(log,"HookScreenshots() bHook=0x%X ",
			bHook		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HookScreenshots(bHook);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsOverlayEnabled ()	{
		char log[1024];
		sprintf(log,"IsOverlayEnabled() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsOverlayEnabled();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAPICallResult ( HSteamPipe hSteamPipe,  SteamAPICall_t hSteamAPICall,  void* pCallback,  int cubCallback,  int iCallbackExpected,  bool* pbFailed )	{
		char log[1024];
		sprintf(log,"GetAPICallResult() hSteamPipe=0x%X hSteamAPICall=0x%X pCallback=0x%X cubCallback=0x%X iCallbackExpected=0x%X pbFailed=0x%X ",
			hSteamPipe,
			hSteamAPICall,
			pCallback,
			cubCallback,
			iCallbackExpected,
			pbFailed		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAPICallResult(hSteamPipe, hSteamAPICall, pCallback, cubCallback, iCallbackExpected, pbFailed);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientDepotBuilder * GetIClientDepotBuilder ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientDepotBuilder() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientDepotBuilder * ret = m_pWrapper->GetIClientDepotBuilder(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ConCommandInit ( IConCommandBaseAccessor *pAccessor )	{
		char log[1024];
		sprintf(log,"ConCommandInit() pAccessor=0x%X ",
			pAccessor		);
		OutputDebugStringA(log);
		pAccessor);
		OutputDebugStringA("\n");
	}
	virtual IClientAppManager * GetIClientAppManager ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientAppManager() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientAppManager * ret = m_pWrapper->GetIClientAppManager(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientConfigStore * GetIClientConfigStore ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientConfigStore() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientConfigStore * ret = m_pWrapper->GetIClientConfigStore(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BOverlayNeedsPresent ()	{
		char log[1024];
		sprintf(log,"BOverlayNeedsPresent() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BOverlayNeedsPresent();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientGameStats * GetIClientGameStats ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientGameStats() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientGameStats * ret = m_pWrapper->GetIClientGameStats(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual IClientHTTP * GetIClientHTTP ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientHTTP() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientHTTP * ret = m_pWrapper->GetIClientHTTP(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
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
	virtual IClientAudio * GetIClientAudio ( HSteamUser hSteamUser,  HSteamPipe hSteamPipe,  char const* pchVersion )	{
		char log[1024];
		sprintf(log,"GetIClientAudio() hSteamUser=0x%X hSteamPipe=0x%X pchVersion=%s ",
			hSteamUser,
			hSteamPipe,
			pchVersion		);
		OutputDebugStringA(log);
		IClientAudio * ret = m_pWrapper->GetIClientAudio(hSteamUser, hSteamPipe, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void * GetIPCServerMap ()	{
		char log[1024];
		sprintf(log,"GetIPCServerMap() "		);
		OutputDebugStringA(log);
		void * ret = m_pWrapper->GetIPCServerMap();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  OnDebugTextArrived ( const char *pchDebugText )	{
		char log[1024];
		sprintf(log,"OnDebugTextArrived() pchDebugText=%s ",
			pchDebugText		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->OnDebugTextArrived(pchDebugText);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
