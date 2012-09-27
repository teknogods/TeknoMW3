// steam_api_emu.cpp : Defines the entry point for the DLL application.
//
#include "stdafx.h"
#include "SDK\SteamclientAPI.h"
#include "SDK\SteamAPI.h"
#include "util.h"
#include "util_codehook.h"
#include "util_adv_log.h"
#include "util_ini.h"
#include "winsock2.h"
#include "steam_api_emu.h"
#include "steam_api_emu_misc.h"
#include "steam_api_emu_interfaces.h"
#include "game_patch_base.h"
#include "game_patch_base_coop.h"
#include "game_server_items.h"
#include "dw_stun_server.h"
#include "dw_online_files.h"
#include "VMProtectSDK.h"
#pragma comment(lib, "WSOCK32.LIB")




#ifdef __cplusplus
extern "C"
#endif
void * _ReturnAddress(void);
#pragma intrinsic(_ReturnAddress)



bool IsInited = false;

CCallbackBase* g_MatchMakingCallbacks[20] = {NULL};
CCallbackBase* g_ServerCallbacks[20] = {NULL};
CCallbackBase* g_SteamUserCallbacks[20] = {NULL};
ISteamMatchmakingServerListResponse* g_RequestServersResponse = NULL;

char g_TeknoGodzMW2_Nickname[128] = "null";
int g_AppID = 42690;
unsigned long g_TeknoGodzMW2_ConnectIpAddr = 0;
unsigned short g_TeknoGodzMW2_ConnectPort = 0;
bool g_TeknoGodzMW2_isPendingConnect = false;
bool g_RequestLANServerList = false;
bool g_isServerIPInitialized = false;
bool g_OnlineMode = false;
CSteamID  g_LobbySteamId;
BYTE * g_AppTicket = NULL;
bool g_LobbyPendingCreate = false;
CSteamID  g_UserSteamId_def = CSteamID( 0x840101, k_EUniversePublic, k_EAccountTypeIndividual );
CSteamID  g_UserSteamId = g_UserSteamId_def;
bool g_bEncryptedAppTicketRequested = false;
CSteamID  g_RemoteLobbySteamId = CSteamID( 0x840100, k_EChatInstanceFlagLobby, k_EUniversePublic, k_EAccountTypeChat );
CSteamID  g_DedicatedServerSteamId = CSteamID( 0x840401, k_EUniversePublic, k_EAccountTypeGameServer );
DWORD g_HWID_Bak[5];


void __cdecl TeknoGodzMW2_SetNickname( char* nickname )
{
	g_Logging.AddToLogFileA( "steam_emu.log", "TeknoGodzMW2_SetNickname %s", nickname );

	//HKEY hKey;

	//if (RegCreateKeyA(HKEY_CURRENT_USER, "Software\\Valve\\Steam\\", &hKey ) == ERROR_SUCCESS)
	//{
	//	RegSetValueExA(hKey, "LastNickName", NULL, REG_SZ, (BYTE *)nickname, strlen(nickname));
	//}

	_snprintf(g_TeknoGodzMW2_Nickname, 128, nickname);

	PersonaStateChange_t persset;
	persset.m_nChangeFlags = k_EPersonaChangeName;
	persset.m_ulSteamID = g_UserSteamId.ConvertToUint64();

	if (g_SteamUserCallbacks[1] != NULL)
	{
		g_SteamUserCallbacks[1]->Run(&persset);
	}
	if (g_SteamUserCallbacks[2] != NULL)
	{
		g_SteamUserCallbacks[2]->Run(&persset);
	}

}

void __cdecl TeknoGodzMW2_SetPendingConnection( unsigned long ipaddr, unsigned short port )
{
	g_Logging.AddToLogFileA( "steam_emu.log", "TeknoGodzMW2_SetPendingConnection %d.%d.%d.%d:%d", ipaddr>>24, (ipaddr&0xff0000) >> 16, (ipaddr&0xff00)>>8, ipaddr&0xff, port );
	g_TeknoGodzMW2_ConnectIpAddr = ipaddr;
	g_TeknoGodzMW2_ConnectPort = port;
	g_TeknoGodzMW2_isPendingConnect = true;
}



#pragma optimize("", off)

bool IsSetupDone = false;
int __cdecl TeknoGodzMW2_SteamSetup()
{	VU("TeknoGodzMW2_SteamSetup");

	if (!IsSetupDone)
	{
		IsSetupDone = true;
		HKEY hKey;
		DWORD dwType = 0;
		DWORD dwSize = 0;
		DWORD steamIdDw = 0;
		char nickName[255];
		char tempid[255];
		memset(nickName, 0, 255);

		//init floating point operations
		InitFloat();


		CIniReader iniReader(V(".\\teknogods.ini"));
		CIniWriter iniWriter(V(".\\teknogods.ini"));

		char *name = iniReader.ReadString(V("Settings"),V("Name"),"");
		char *id = iniReader.ReadString(V("Settings"),V("ID"),"");
		g_NewFov = iniReader.ReadInteger(V("Settings"),V("FOV"), 0);
		g_TkDev = iniReader.ReadBoolean(V("Settings"),V("tkdev"), false);
		
		g_DefaultInterface = iniReader.ReadInteger(V("Network"),V("NetworkInterface"), 255);
		if (g_DefaultInterface == 255) iniWriter.WriteInteger(V("Network"),V("NetworkInterface"), 255);

		g_GlobalBans = iniReader.ReadBoolean(V("Network"),V("GlobalBans"), false);
		g_OnlineMode = iniReader.ReadBoolean(V("Network"),V("OnlineMode"), true);
		info("OnlineMode = %d", g_OnlineMode);


		//save all interfaces to ini file -- as extra info for people
		string ip_list = V("[");
		for (int i = 0; i < g_IpList.iAddressCount; i++)
		{
			const sockaddr_in *addr = (sockaddr_in *)g_IpList.Address[i].lpSockaddr;
			char ip_item[256];
			sprintf(ip_item, V("%d = %s; "), i, inet_ntoa(addr->sin_addr));
			ip_list = ip_list + ip_item;
		}
		ip_list = ip_list + V("255 (default) = ANY IP]");
		iniWriter.WriteString(V("Network"), V("NetworkInterfaceList"), (char *)ip_list.c_str()); 

		//other ip stuff
		char *lan_ip = iniReader.ReadString(V("Network"),V("ExternalIP"), "");
		if (strcmp(lan_ip, "") == 0) lan_ip = NULL;

		if (GAME_MODE == 'D' || lan_ip != NULL)
		{
			GetExternalIP(false, lan_ip);
		}
		else
		{
			//get lan ip
			DWORD int_ip = GetInternalIP();
			if (int_ip == 0) int_ip = GetHWIDSteamID();

			SetExternalIP(int_ip);
		}



		//master server stuff
		if (g_OnlineMode)
		{
			char *master = iniReader.ReadString(V("Network"),V("MasterServer"), V("teknogods.com:27017"));
			
			if (!parseIpPort(master, &g_MasterIp, &g_MasterPort))
			{
				info("Failed to set the master-server port and ip (%s).", master);
			}
			else
			{
				char ips[255];
				makeIPstr(g_MasterIp, ips); 
				info("Master-server address set to: %s:%d.", ips, g_MasterPort);
			}
		}



		//dedicated server doesnt need special SteamID, so lets make it stay with the default one.
		if (GAME_MODE != 'D')
		{
			if(strcmp(id, "") == 0)
			{
				steamIdDw = GetHWIDSteamID();
				wsprintfA(tempid, V("%08X"),steamIdDw);
				iniWriter.WriteString(V("Settings"), V("ID"),tempid);
			}
			else
			{
				if (!charToDword(id, &steamIdDw))
				{
					iniWriter.WriteString(V("Errors"), V("LastError"), V("Your ID was incorrect (must be hex chars [0-9 a-f]), so we re-set it to HWID."));
					steamIdDw = GetHWIDSteamID();
					wsprintfA(tempid, V("%08X"),steamIdDw);
					iniWriter.WriteString(V("Settings"), V("ID"),tempid);
				}
			}

			//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			//steamIdDw = GetHWIDSteamID() ^ GetCurrentProcessId();

			g_UserSteamId = CSteamID( steamIdDw, k_EUniversePublic, k_EAccountTypeIndividual );
		}
		else
		{
			//dedicated server doesnt need any specific steam id or name.
			steamIdDw = GetHWIDSteamID() ^ GetCurrentProcessId();
			g_UserSteamId = CSteamID( steamIdDw, k_EUniversePublic, k_EAccountTypeGameServer );
			g_DedicatedServerSteamId = g_UserSteamId;
			sprintf(nickName, V("HostUser_%08X"), steamIdDw);
			name = nickName;
		}

		if(strcmp(name,"") != 0)
		{
			// Name is not empty
			TeknoGodzMW2_SetNickname(name);
		}
		else if (RegOpenKeyExA(HKEY_CURRENT_USER, V("Software\\Valve\\Steam\\"), 0L, KEY_READ, &hKey ) == ERROR_SUCCESS)
		{
			dwSize = 255;

			if (RegQueryValueExA(hKey, V("LastGameNameUsed"), NULL, &dwType, (BYTE *)nickName, &dwSize) == ERROR_SUCCESS)
			{
				_snprintf(g_TeknoGodzMW2_Nickname, 128, nickName);
				iniWriter.WriteString(V("Settings"),V("Name"),nickName);
			}
			else
			{

				char nickName[100];
				DWORD nnickName = sizeof(nickName);
				if (GetUserNameA((char*)nickName, &nnickName))
				{
					TeknoGodzMW2_SetNickname(nickName);
					iniWriter.WriteString(V("Settings"),V("Name"),nickName);
				}
				else
				{
					TeknoGodzMW2_SetNickname(V("^3TeknoSlave"));
					iniWriter.WriteString(V("Settings"), V("Name"), V("^3TeknoSlave"));
				}				
			}

			RegCloseKey(hKey);
		}
		else
		{
			CIniWriter iniWriter(V(".\\teknogods.ini"));
			TeknoGodzMW2_SetNickname(V("^3TeknoSlave"));
			iniWriter.WriteString(V("Settings"),V("Name"), V("^3TeknoSlave"));
		}




		#ifdef DEBUGGING_ENABLED
		char dbgout[255];
		sprintf_s(dbgout, 255, "TeknoGodzMW2_SteamSetup done. Name: %s, SteamID: 0x%08X.", g_TeknoGodzMW2_Nickname, steamIdDw);
		g_Logging.AddToLogFileA( "steam_emu.log", dbgout );
		OutputDebugStringA(dbgout);
		#endif
	}
	return 1;
	VE();
}





DWORD WINAPI ProfileDumper_thread(LPVOID lpParameter)
{	VM("ProfileDumper_thread");

	int i = 0;
	while (1)
	{
		Sleep(100);
		i++;
		if (i == 5)
		{
			char * profname = SaveDWMpdataToFile(true);

			if (profname == NULL)
			{
				MessageBoxA(0, V("Profile couldn't be dumped! Please report your game version back to us."), V("Information"), MB_ICONERROR);
				ExitProcess(0);
			}

			DWORD steamID = g_SteamID_DW64[0];

			char message[255];
			sprintf(message, V("Done. Profile dumped to \"%s\".\n\nClick YES if you would like to modify \"teknogods.ini\" to use SteamID (%08X) linked to that profile."), profname, steamID);

			if (MessageBoxA(0, message, V("Information"), MB_ICONINFORMATION | MB_YESNO) == IDYES)
			{
				sprintf(message, V("%08X"), steamID);
				CIniWriter iniWriter(V(".\\teknogods.ini"));

				iniWriter.WriteString(V("Settings"),V("ID"), message);
			}
			ExitProcess(0);			
		}
	}

	VE();
}


bool RunSteamDRMCheck()
{	VU("RunSteamDRMCheck");

	//char * cmdline = GetCommandLineA();

	//if (strstr(cmdline, V("+edebug")) != NULL || GAME_MODE == 'D') return true;

	//if (g_SteamGUIDsFail)
	//{
	//	MessageBoxA(0, V("Steam DRM checks failed. Please use the original executable (bound to your account/computer)."), V("Error"), MB_ICONERROR);
	//	ExitProcess(0xDEAD);
	//}

	//char cdir[1024];
	//GetCurrentDirectoryA(1024, cdir);

	//if (strstr(cdir, V("steamapps\\common")) == NULL)
	//{
	//	MessageBoxA(0, V("Steam DRM checks failed. Unable to validate the game installation path."), V("Error"), MB_ICONERROR);
	//	ExitProcess(0xDEAD);
	//}

	return true;

	VE();
}



BOOL SteamAPI_Main(HMODULE hModule, DWORD ul_reason_for_call)
{

	//if ((ul_reason_for_call == DLL_PROCESS_ATTACH ) && (!IsInited))
	if (!IsInited)
	{	VU("SteamAPI_Main");
		
		//check if we need to dump the profile from steam-powered process
		if (ValidateDumperMutex())
		{
			info("Profile Dumper mode detected....");
			IsInited = true;
			CreateThread(NULL, 0, ProfileDumper_thread, 0, 0, NULL);
			return true;
		}

		//MessageBoxA(0,0,0,0); //__asm int 3;
		////GetHWIDchunk(3);
		//DWORD x[4];
		//GetHWID(x);
		//ExitProcess(0);



		char * cmdline = GetCommandLineA();
		IsInited = true;
		WSADATA wsaData;
		WSAStartup(MAKEWORD(2,2), &wsaData);
		#ifdef DEBUGGING_ENABLED
		g_Logging.BaseUponModule( hModule );
		g_Logging.AddToLogFileA( "steam_emu.log", "Attached to process!" );

		MessageBoxA(0,0,0,0);
		LoadLibraryA("a.dll");
		#endif

		//if +offline is not found, set online mode, else, offline (no master server connection)
		//if (strstr(cmdline, V("+offline")) == NULL)
		//	g_OnlineMode = true;
		//else
		//	g_OnlineMode = false;

		#ifndef DEBUGGING_ENABLED
		if ((!GetGameMode()) || GAME_MODE == 'U' || !ValidateLoaderMutex() || !VMProtectIsValidImageCRC() || VMProtectIsDebuggerPresent(false))
			ExitProcess(0);
		#else
		GetGameMode();
		#endif

		//get all available ip's
		EnumNetworkAdapters();

		TeknoGodzMW2_SteamSetup();
		GetConsole();
		//HookGenerateSharedKey();

	
		if (GAME_MODE == 'S')
		{
			if (PatchMW3Coop())
			{
				#ifdef DEBUGGING_ENABLED
				info("PatchMW3Coop done.");
				#endif

				g_Patch_DW_STUN_Server_port_and_hosts = true;
				StartStunServer();

				#ifdef DEBUGGING_ENABLED
				HookDWLogFunc();
				#endif

				g_Patch_DW_ConnectionStatus = true;
				HookGetAssetFunc();
				PatchVariousStuff();

				RunSteamDRMCheck();
				HookDvarToStrForScripts();

				return true;
			}
			else
			{
				MessageBoxA(0,V("Failed to init the DLL - unsupported game version?"), V("Error"), MB_ICONERROR);
			}
			ExitProcess(0);
		}

		if ((GAME_MODE == 'M') || (GAME_MODE == 'D'))
		{
			g_Patch_DW_STUN_Server_port_and_hosts = true;
			StartStunServer();
			HookAuthorizeIP();
			GetGameBuildNum();

			if (GAME_MODE == 'D')
			{
				HookIsMapInstalled();
				GetFillServerInfo();
				GetConsolePrintf();
				HookGetBanStatus();
				GetClientsBlock();
				HookProcessClientUICommand();
			}

			if (GAME_MODE == 'M')
			{
				HookGetServerInfo();
				HookGetAssetFunc();
				GetHeatmapCheckPtr();
				GetBlobLoader();
			}
		}

		if (strstr(cmdline, V("+unranked")) != NULL)
		{
			g_Set_Ranked_Games = false;
		}
		

		HookDWLogFunc();
		HookDWGetFile();
		HookGenerateSecurityKeys();
		HookConsole();
		HookDvarToStrForScripts();
		PatchVariousStuff();
		GetDvarAndFuncListPtrs();
		HookKeyboard();

		RunSteamDRMCheck();

		VE();
	}

    return true;
}

#pragma optimize("", on)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	return SteamAPI_Main(hModule, ul_reason_for_call);
}