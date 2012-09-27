#include "stdafx.h"
#include "game_dvar_base.h"
#include "game_admin_base.h"
#include "util.h"
#include "util_adv_log.h"
#include "steam_api_emu.h"
#include "steam_api_emu_interfaces.h"
#include "dw_stun_server.h"
#include "VMProtectSDK.h"

#pragma optimize("", off)

extern "C"
{
	__declspec(dllexport) HSteamPipe __cdecl GetHSteamPipe()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "GetHSteamPipe" );

		return 1;
	}
	__declspec(dllexport) HSteamUser __cdecl GetHSteamUser()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "GetHSteamUser" );

		return 1;
	}
	__declspec(dllexport) HSteamPipe __cdecl SteamAPI_GetHSteamPipe()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_GetHSteamPipe" );

		return 1;
	}
	__declspec(dllexport) HSteamUser __cdecl SteamAPI_GetHSteamUser()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_GetHSteamUser" );

		return 1;
	}
	__declspec(dllexport) const char *__cdecl SteamAPI_GetSteamInstallPath()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_GetSteamInstallPath" );

		return g_Logging.GetDirectoryFileA( "" );
	}

	//typedef bool (__cdecl *SAI)();
	//typedef DWORD (__cdecl *SCI)(char * interface_name, DWORD unk0);
	__declspec(dllexport) bool __cdecl SteamAPI_Init()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_Init" );



		//HMODULE sclientdll = LoadLibraryA("steamclient.dll");
		//SCI CreateInterface_original = (SCI)GetProcAddress(sclientdll, "CreateInterface");

		//if ((DWORD)CreateInterface_original != NULL)
		//{
		//	SteamClient_org = (ISteamClient011 *)CreateInterface_original("SteamClient011", 0);

		//	CreateInterface_original("SteamMatchmakingServers002", 0);
		//}
		//
		//SteamMatchmakingServers_org = (ISteamMatchmakingServers002*)SteamClient_org->GetISteamMatchmakingServers(1, 1, "SteamMatchmakingServers002");


		//g_Logging.AddToLogFileA( "steam_emu.log", "SteamMatchmakingServers_org = %08X", SteamMatchmakingServers_org);

		return true;
	}
	__declspec(dllexport) bool __cdecl SteamAPI_InitSafe()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_InitSafe" );

		return true;
	}
	__declspec(dllexport) void __cdecl SteamAPI_RegisterCallResult( CCallbackBase* pResult, SteamAPICall_t APICall )
	{	VM("SteamAPI_RegisterCallResult");

		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallResult APICall=%I64d Callback=0x%8.8X", APICall, pResult->GetICallback() );

//#define _SERVER_
		if( APICall == 0x10101 && pResult->GetICallback() == k_iSteamMatchmakingCallbacks + 4 )
		{
			LobbyEnter_t lobbyEnter;
			lobbyEnter.m_ulSteamIDLobby = g_RemoteLobbySteamId.ConvertToUint64();//CSteamID( 0x840100, k_EChatInstanceFlagLobby, k_EUniversePublic, k_EAccountTypeChat ).ConvertToUint64();//CSteamID( 0x100100, k_EUniversePublic, k_EAccountTypeIndividual ).ConvertToUint64();
			lobbyEnter.m_EChatRoomEnterResponse = k_EChatRoomEnterResponseSuccess;
			lobbyEnter.m_rgfChatPermissions = k_EChatPermissionOwnerDefault;
			lobbyEnter.m_bLocked = false;
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallResult() Calling LobbyEnter");
			pResult->Run(&lobbyEnter);
		}

		if( pResult->GetICallback() == k_iSteamMatchmakingCallbacks + 13 )
		{
			LobbyCreated_t lobbyCreated;
			lobbyCreated.m_eResult = k_EResultOK;
			lobbyCreated.m_ulSteamIDLobby = g_LobbySteamId.ConvertToUint64();
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallResult() Calling LobbyCreated");
			pResult->Run(&lobbyCreated);
		}

		if( pResult->GetICallback() == 154 )
		{
			g_bEncryptedAppTicketRequested = true;
			g_SteamUserCallbacks[0] = pResult;
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallResult() Calling AppTicketSchaise");
			
		}

		VE();
	}
	__declspec(dllexport) void __cdecl SteamAPI_RegisterCallback( CCallbackBase *pCallback, int iCallback )
	{	VM("SteamAPI_RegisterCallback");

		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback iCallback=%d CallbackProc=0x%08X", iCallback, *(DWORD*)((DWORD)pCallback+0x10) );

		if( iCallback == k_iSteamFriendsCallbacks + 32 )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering GameServerChangeRequested_t" );
			g_SteamUserCallbacks[3] = pCallback;
		}

		if( iCallback == k_iSteamFriendsCallbacks + 33 )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering GameLobbyJoinRequested" );
			g_MatchMakingCallbacks[0] = pCallback;
		}

		if( iCallback == k_iSteamFriendsCallbacks + 4 )
		{
			if (g_SteamUserCallbacks[1] == NULL)
				g_SteamUserCallbacks[1] = pCallback;
			else
				g_SteamUserCallbacks[2] = pCallback;

			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering PersonaStateChange_t");
			
		}



		if( iCallback == 101 )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering InitServerIP" );
			g_ServerCallbacks[0] = pCallback;
		}

		if( iCallback == 115 )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering VAC_Check" );
			g_ServerCallbacks[1] = pCallback;
		}

		if( iCallback == 103 )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering ServerDisconnect" );
			g_ServerCallbacks[2] = pCallback;
		}

		if( iCallback == 201 )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering Unk1" );
			g_ServerCallbacks[3] = pCallback;
		}

		if( iCallback == 202 || iCallback == 203)
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RegisterCallback() Registering SteamAuthKickCheatEtc" );
			g_ServerCallbacks[4] = pCallback;
		}

		VE();
	}
	__declspec(dllexport) void __cdecl SteamAPI_RunCallbacks()
	{	VM("SteamAPI_RunCallbacks");

		//g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RunCallbacks" );
		if( g_TeknoGodzMW2_isPendingConnect )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RunCallbacks(): preparing InviteCallback" );

			g_TeknoGodzMW2_isPendingConnect = false;
			LobbyInvite_t invite;
			invite.m_ulSteamIDLobby = CSteamID( 0x840100, k_EChatInstanceFlagLobby, k_EUniversePublic, k_EAccountTypeChat ).ConvertToUint64();
			invite.m_ulSteamIDUser = CSteamID( 0x840100, k_EChatInstanceFlagLobby, k_EUniversePublic, k_EAccountTypeChat ).ConvertToUint64();//CSteamID( 0x100100, k_EUniversePublic, k_EAccountTypeIndividual ).ConvertToUint64();
			if( g_MatchMakingCallbacks[0] != NULL )
			{
				g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RunCallbacks(): running InviteCallback" );
				g_MatchMakingCallbacks[0]->Run(&invite);
			}
		}

		if( g_bEncryptedAppTicketRequested )
		{
			g_bEncryptedAppTicketRequested = false;
			EncryptedAppTicketResponse_t appTickResp;
			appTickResp.m_eResult = k_EResultOK;
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RunCallbacks() Calling AppTicketSchaise");
			g_SteamUserCallbacks[0]->Run(&appTickResp);
		}

		VE();
	}
	__declspec(dllexport) void __cdecl SteamAPI_SetMiniDumpComment( const char *pchMsg )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_SetMiniDumpComment" );

		//
	}
	__declspec(dllexport) void __cdecl SteamAPI_SetTryCatchCallbacks( bool bUnknown )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_SetTryCatchCallbacks" );
	}
	__declspec(dllexport) void __cdecl SteamAPI_Shutdown()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_Shutdown" );

		//
	}
	__declspec(dllexport) void __cdecl SteamAPI_UnregisterCallResult( CCallbackBase* pResult, SteamAPICall_t APICall )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_UnregisterCallResult" );

		//
	}

	__declspec(dllexport) void __cdecl SteamAPI_UnregisterCallback( CCallbackBase *pCallback )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_UnregisterCallback" );

		//
	}
	__declspec(dllexport) void __cdecl SteamAPI_WriteMiniDump( uint32 uStructuredExceptionCode, void* pvExceptionInfo, uint32 uBuildID )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_WriteMiniDump" );
	}

	__declspec(dllexport) void* __cdecl SteamApps()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamApps" );

		return g_pSteamAppsEmu;
	}
	__declspec(dllexport) void* __cdecl SteamClient()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamClient" );

		return g_pSteamClientEmu;
	}
	__declspec(dllexport) void* __cdecl SteamContentServer()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamContentServer" );

		return NULL;
	}
	__declspec(dllexport) void* __cdecl SteamContentServerUtils()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamContentServerUtils" );

		return g_pSteamUtilsEmu;
	}
	__declspec(dllexport) bool __cdecl SteamContentServer_Init( unsigned int uLocalIP, unsigned short usPort )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamContentServer_Init" );

		return true;
	}
	__declspec(dllexport) void __cdecl SteamContentServer_RunCallbacks()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamContentServer_RunCallbacks" );

	}
	__declspec(dllexport) void __cdecl SteamContentServer_Shutdown()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamContentServer_Shutdown" );
	}

	__declspec(dllexport) void* __cdecl SteamGameServerNetworking()
	{
		//g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServerNetworking" );

		return g_pSteamNetworkingEmu;
	}
	
	__declspec(dllexport) void* __cdecl SteamGameServerStats()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServerStats" );

		return NULL;
	}
	
	__declspec(dllexport) void* __cdecl SteamFriends()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamFriends" );

		return g_pSteamFriendsEmu;
	}


	typedef void* (__cdecl *SGS)();
	
	__declspec(dllexport) void* __cdecl SteamGameServer()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer" );

		//MessageBoxA(0,0,0,0);
		//HMODULE sapidll = LoadLibraryA("steam_api_org.dll");
		//SGS SteamGameServer_original = (SGS)GetProcAddress(sapidll, "SteamGameServer");
		//SteamGameServer_org = (CSteamGameServer010 *)SteamGameServer_original();

		return g_pSteamGameServerEmu;
	}
	__declspec(dllexport) void* __cdecl SteamGameServerUtils()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServerUtils" );

		return g_pSteamUtilsEmu;
	}
	__declspec(dllexport) bool __cdecl SteamGameServer_BSecure()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_BSecure" );

		return true;
	}
	__declspec(dllexport) HSteamPipe __cdecl SteamGameServer_GetHSteamPipe()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_GetHSteamPipe" );

		return 1;
	}
	__declspec(dllexport) HSteamUser __cdecl SteamGameServer_GetHSteamUser()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_GetHSteamUser" );

		return 1;
	}
	__declspec(dllexport) int32 __cdecl SteamGameServer_GetIPCCallCount()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_GetIPCCallCount" );

		return 0;
	}
	__declspec(dllexport) CSteamID __cdecl SteamGameServer_GetSteamID()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_GetSteamID" );

		return g_DedicatedServerSteamId;
	}


	typedef bool (__cdecl *SGSINIT)( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString );
	
	__declspec(dllexport) bool __cdecl SteamGameServer_Init( uint32 unIP, uint16 usPort, uint16 usGamePort, uint16 usSpectatorPort, uint16 usQueryPort, EServerMode eServerMode, const char *pchGameDir, const char *pchVersionString )
	{	VM("SteamGameServer_Init");

		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_Init(unIP=%08X, usPort=%d, usGamePort=%d, usSpectatorPort=%d, usQueryPort=%d, eServerMode=%d, pchGameDir='%s', pchVersionString='%s' )", unIP, usPort, usGamePort, usSpectatorPort, usQueryPort, eServerMode, pchGameDir, pchVersionString );

		g_pSteamGameServerEmu->LogOn();
		g_pSteamGameServerEmu->BSetServerType(0, unIP, usGamePort, usSpectatorPort, usQueryPort, pchGameDir, pchVersionString, true);

		InitGameplayGuard();

		dvar rconax(V("rcon_full_access"));
		if (rconax.Inited)
		{
			if (strncmp(rconax.GetValueSTR(), "1", 1) == 0)
			{
				ConsolePrintf(0, V("Enabled full rcon access.\n"));
				g_RCon_Full_Access = true;
			}
		}

		dvar valnick(V("proper_nicknames_only"));
		if (valnick.Inited)
		{
			if (strncmp(valnick.GetValueSTR(), "1", 1) == 0)
			{
				ConsolePrintf(0, V("Enabled nickname validation.\n"));
				g_ValidateNicknames = true;
			}
		}		

		//waypoints and skill icons over bodies
		{
			dvar a(V("ui_hud_obituaries"));
			dvar b(V("waypointiconheight")); 
			dvar c(V("waypointiconwidth"));

			if (a.Inited) a.data->Flags = dvarFlags::DVF_A | dvarFlags::DVF_PRINTABLE;
			if (b.Inited) b.data->Flags = dvarFlags::DVF_A | dvarFlags::DVF_PRINTABLE;
			if (c.Inited) c.data->Flags = dvarFlags::DVF_A | dvarFlags::DVF_PRINTABLE;
		}

		return true;
		VE();
	}
	__declspec(dllexport) bool __cdecl SteamGameServer_InitSafe( uint32 unIP, uint16 usPort, uint16 usGamePort, EServerMode eServerMode, int nGameAppId, const char *pchGameDir, const char *pchVersionString, unsigned long dongs )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_InitSafe" );

		return true;
	}
	__declspec(dllexport) void __cdecl SteamGameServer_RunCallbacks()
	{

		//CreateThread(NULL, 0, nettest, 0, 0, NULL);
		//MessageBoxA(0,"x",0,0);
		//ExitProcess(0);


		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_RunCallbacks" );

		if(!g_isServerIPInitialized )
		{
			g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_RunCallbacks(): preparing InitServerIPCallback" );

			g_isServerIPInitialized = true;

			if( g_ServerCallbacks[0] != NULL )
			{
				g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_RunCallbacks(): running InitServerIPCallback" );
				g_ServerCallbacks[0]->Run(NULL);
			}

			if( g_ServerCallbacks[1] != NULL )
			{
				g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_RunCallbacks(): running VacCheckCallback" );
				g_ServerCallbacks[1]->Run(NULL);
			}

			//if( g_ServerCallbacks[3] != NULL )
			//{
			//	g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_RunCallbacks(): running Unk1Callback" );
			//	g_ServerCallbacks[3]->Run(NULL);
			//}

		}
	}
	__declspec(dllexport) void __cdecl SteamGameServer_Shutdown()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamGameServer_Shutdown" );

		//
	}
	__declspec(dllexport) void* __cdecl SteamMasterServerUpdater()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamMasterServerUpdater" );


		//HMODULE sapidll = LoadLibraryA("steam_api_org.dll");
		//SGS SteamMasterServerUpdater_original = (SGS)GetProcAddress(sapidll, "SteamMasterServerUpdater");
		//SteamMasterServerUpdater_org = (CSteamMasterServerUpdater001 *)SteamMasterServerUpdater_original();

		return g_pSteamMasterServerUpEmu;
	}
	__declspec(dllexport) void* __cdecl SteamMatchmaking()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamMatchmaking" );

		return g_pSteamMatchmakingEmu;
	}
	__declspec(dllexport) void* __cdecl SteamMatchmakingServers()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamMatchmakingServers" );

		return g_pSteamMatchmakingServEmu;
	}
	__declspec(dllexport) void* __cdecl SteamNetworking()
	{
		//g_Logging.AddToLogFileA( "steam_emu.log", "SteamNetworking" );

		return g_pSteamNetworkingEmu;
	}
	__declspec(dllexport) void* __cdecl SteamRemoteStorage()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamRemoteStorage" );

		return g_pSteamRemoteStorageEmu;
	}
	__declspec(dllexport) void* __cdecl SteamUser()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamUser" );

		return g_pSteamUserEmu;
	}
	__declspec(dllexport) void* __cdecl SteamUserStats()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamUserStats" );
		
		if ((GAME_MODE == 'S') || (GAME_MODE == 'M'))
			return g_pSteamUserStatsEmu;
		
		return NULL;
	}
	__declspec(dllexport) void* __cdecl SteamUtils()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamUtils" );

		return g_pSteamUtilsEmu;
	}
	__declspec(dllexport) HSteamUser __cdecl Steam_GetHSteamUserCurrent()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "Steam_GetHSteamUserCurrent" );

		return NULL;
	}
	__declspec(dllexport) void __cdecl Steam_RegisterInterfaceFuncs( void *hModule )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "Steam_RegisterInterfaceFuncs" );

		//
	}
	__declspec(dllexport) void __cdecl Steam_RunCallbacks( HSteamPipe hSteamPipe, bool bGameServerCallbacks )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "Steam_RunCallbacks" );

		//
	}

	__declspec(dllexport) bool __cdecl SteamAPI_RestartApp( int appid )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RestartApp" );

		Sleep(1);

		return true;
	}

	__declspec(dllexport) bool __cdecl SteamAPI_RestartAppIfNecessary( int appid )
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_RestartAppIfNecessary" );

		Sleep(1);

		return false;
	}
	

	__declspec(dllexport) bool __cdecl SteamAPI_IsSteamRunning()
	{
		g_Logging.AddToLogFileA( "steam_emu.log", "SteamAPI_IsSteamRunning" );

		return true;
	}

	__declspec(dllexport) void *g_pSteamClientGameServer = NULL;

	__declspec(dllexport) void *V_2_7_0_5 = NULL;

}

#pragma optimize("", on)