#include "stdafx.h"
#include "SDK\SteamclientAPI.h"
#include "SDK\SteamAPI.h"
#include "game_admin_base.h"
#include "game_patch_base.h"
#include "game_patch_hookports.h"
#include "game_hotkey_base.h"
#include "game_dvar_base.h"
#include "game_server_items.h"
#include "VMProtectSDK.h"
#include "steam_api_emu.h"
#include "steam_api_emu_misc.h"
#include "dw_stun_server.h"
#include "dw_online_files.h"
#include "util.h"
#include "util_adv_log.h"
#include "util_codehook.h"
#include "util_ini.h"
#include <sys/stat.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

#pragma optimize("", off)


char GAME_MODE = 'U';
bool g_Patch_DW_ConnectionStatus = true;
bool g_Patch_Unauthorized_IP = true;
bool g_Patch_Unregistered_Connection = true;
bool g_Patch_HostAndClient_On_Same_Local_IP_Fail = true;
bool g_Patch_SteamAuthFail_clientDrop = true;
bool g_Patch_Getting_Data_Popup = true;
bool g_Patch_DW_ProcessFileRequest = true;
bool g_Patch_DW_STUN_Server_port_and_hosts = false;
bool g_Patch_Session_Info_Funcs = true;
bool g_Patch_Task_server_Crash = true;
bool g_Patch_Modded_Files_Check = true;
bool g_Patch_Task_matchmaking_search = true;
bool g_Patch_Content_server_init = true;
bool g_Set_Ranked_Games = true;
bool g_SteamGUIDsFail = true;

int g_NewFov = 0; 
bool g_TkDev = false;
bool g_RCon_Full_Access = false;
bool g_GlobalBans = false;
bool g_ValidateNicknames = false;


//UI String Replacements
char TEKNO_TITLE_CAPTION[15] = "^1Tekno MW3";
char TEKNO_OFFICIALSERVLIST_CAPTION[10] = "OFFICIAL";
char TEKNO_FRIENDS_CAPTION[40] = "You have no real friends around here.";
//char TEKNO_NULL_CAPTION[13] = "^8DISABLED";

char MENU_MULTIPLAYER_CAPS[17] = "^1TeknoGods Coop";
char MENU_SP_DESC_MULTIPLAYER[158] = "Play with a friend, rank up to unlock weapons, tactical support, levels and more in Survival mode and a variety of challenging missions. All hail ^1TeknoGods";
char COOP_WRONGSTATE[103] = "Host and client have the same steamid, please change it from teknogods.ini file.\n^1All hail TeknoGods!";
char MENU_POPUP_ACCEPTINVITE[63] = "Joining, if you see this more than 2 seconds your host is bad.";


MYFILLSERVERINFO FillServerInfo = FillServerInfo_Stub;
MYBLOBPROC LoadBlob = (MYBLOBPROC)LoadBlob_Stub;
MYCONPROC Console = (MYCONPROC)Console_Stub;
MYCONPRINTF ConsolePrintf = (MYCONPRINTF)ConsolePrintf_Stub;
MYGUIDFUNC STEAM_TestGUID = NULL;


MYGETDVARVAL GetDvarValueStrFromBuffer = NULL;
DWORD ConsolePrintfProc = 0;
DWORD DvarCountPtr = 0;
DWORD DvarListPtr = 0;
DWORD FuncListPtr = 0;
BYTE * HeatMapCheck_ptr1 = NULL;
DWORD * g_SteamID_DW64 = NULL;
BYTE *g_MpdataLoc = NULL;
DWORD g_GameBuild = 0;

PMW3_CLIENTS_INFO_DEDI g_ClientsBlock = NULL;
DWORD g_ClientsBlock2 = NULL;

typedef FF_FILE_INFO * (__cdecl *GETASSET)(DWORD type, char* name, DWORD unk1);
FF_FILE_INFO * __cdecl myGetAsset(DWORD caller, GETASSET tramp, DWORD type, char* name, DWORD unk1)
{
	FF_FILE_INFO * infos = tramp(type, name, unk1);

	//if (type == AssetTypes::rawfile)
	//{
	//	#ifdef DEBUGGING_ENABLED
	//	DebugOutString("GetAsset", name);
	//	DebugOutValue("type", type);
	//	DebugOutValue("ret", (DWORD)info);
	//	#endif

	//	if ((ModdedFFFiles) && (!IsFFModFileLoaded(info->name)))
	//	{
	//		if (LoadModdedFFFile(info))
	//		{
	//			loaded_ff_mod_files[info->name] = info->data;
	//		}
	//	}
	//}

	//A MOD test of localization strings
	//We could read in all mod strings from some text file and allow ppl to add
	//support to some less common languages?
	if (type == AssetTypes::localize)
	{
		if (GAME_MODE == 'M')
		{
			//info("get loc: %s -> %s", name, infos->name);

			if (strcmp(V("MENU_MULTIPLAYER_CAPS"), name) == 0)
			{
				infos->name = V(TEKNO_TITLE_CAPTION);
			}

			if (strcmp(V("MENU_FRIENDS_CAP"), name) == 0)
			{
				infos->name = V(TEKNO_OFFICIALSERVLIST_CAPTION);
			}

			//DebugOutString(name, infos->name);

			//if (strcmp("MENU_VAULT_CAPS", name) == 0 || strcmp("MENU_MAIN_MENU_CAPS", name) == 0)
			//{
			//	infos->name = TEKNO_NULL_CAPTION;
			//}
		}

		if (strcmp(V("PLATFORM_NO_FRIENDS"), name) == 0)
		{
			infos->name = V(TEKNO_FRIENDS_CAPTION);
		}

		if (GAME_MODE == 'S')
		{
			if (strcmp(V("MENU_MULTIPLAYER_CAPS"), name) == 0)
			{
				infos->name = V(MENU_MULTIPLAYER_CAPS);
			}
			else if(strcmp(V("MENU_SP_DESC_MULTIPLAYER"),name) == 0)
			{
				infos->name = V(MENU_SP_DESC_MULTIPLAYER);
			}
			else if(strcmp(V("COOP_WRONGSTATE"), name) == 0)
			{
				infos->name = V(COOP_WRONGSTATE);
			}
			else if(strcmp(V("MENU_POPUP_ACCEPTINVITE"), name) == 0)
			{
				infos->name = V(MENU_POPUP_ACCEPTINVITE);
			}
		}


	}

	return infos;
}

bool HookGetAssetFunc()
{	VM("HookGetAssetFunc");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);


		//.text:004EA8D0 51                                            push    ecx
		//.text:004EA8D1 53                                            push    ebx
		//.text:004EA8D2 8B 1D F8 A1 7D 00                             mov     ebx, ds:InterlockedDecrement
		//.text:004EA8D8 55                                            push    ebp
		//.text:004EA8D9 56                                            push    esi
		//.text:004EA8DA 57                                            push    edi
		//.text:004EA8DB 8B 7C 24 18                                   mov     edi, [esp+14h+arg_0]
		//.text:004EA8DF C7 44 24 10 00 00 00 00                       mov     [esp+14h+var_4], 0
		//.text:004EA8E7 E8 34 AC 05 00                                call    sub_545520
		//.text:004EA8EC 68 CC 55 85 01                                push    offset dword_18555CC ; lpAddend

		addr = FindHexString(V("51538b1d????????5556578B7C2418c744241000000000e8????????68"), 0);
		
		if (addr != 0)
		{
			hook_cdecl((void*)(addr), myGetAsset);
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 68);
			return 0;
			#endif
		}

		#ifdef DEBUGGING_ENABLED
		DebugOutValue("HOOK_GET_ASSET_FUNC_PTR", addr);
		#endif

		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 67);
		#endif
		return 0;
	}

	return 1;

	VE();
}


int Console_Stub(DWORD code, const char* Format) 
{
		return 0;
}

bool GetConsole()
{	VM("GetConsole");

	__try  
	{
		int addr = FindHexString(V("6A??E8????????8B44240C8A0883C40480F970740580F95075??8A480180F930"), 0);

		if (addr == 0)
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 0x8005);
			#endif
			return 0;
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("CONSOLE_PROC_PTR", addr);
			#endif
			Console = (MYCONPROC)addr;
		}
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 5);
		#endif
		return 0;
	}
	return 1;

	VE();
}




int ConsolePrintf_Stub(DWORD code, const char* Format, ...) 
{
		return 0;
}

//MYCONPRINTF ConsolePrintf = (MYCONPRINTF)ConsolePrintf_Stub;

bool GetConsolePrintf()
{	VM("GetConsolePrintf");

	__try  
	{
		ConsolePrintfProc = FindHexString(V("B800100000E8??????008B8C24081000008D84240C10000050518D542408680010000052E8????????8B8C24141000006A008D4424145051C6"), 0);
		if (ConsolePrintfProc == 0)
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 0x8006);
			#endif
			return 0;
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("CONSOLE_PRINTF_PTR", ConsolePrintfProc);
			#endif
			ConsolePrintf = (MYCONPRINTF)ConsolePrintfProc;
		}
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 6);
		#endif
		return 0;
	}

	return 1;

	VE();
}




void __stdcall LoadBlob_Stub(DWORD dw_low, DWORD dw_high, char* name, void * blob, int unk60h)
{
	#ifdef DEBUGGING_ENABLED
	info("ERROR (LoadBlob): Trying to load a blob, but function wasnt found! Check GetBlobLoader function...");
	#endif
}


bool GetBlobLoader()
{	VM("GetBlobLoader");

	__try  
	{
		//.text:00448370 8B 44 24 14                                   mov     eax, [esp+arg_10]
		//.text:00448374 56                                            push    esi
		//.text:00448375 8B 74 24 14                                   mov     esi, [esp+4+arg_C]
		//.text:00448379 83 F8 08                                      cmp     eax, 8
		//.text:0044837C 72 2D                                         jb      short loc_4483AB
		//.text:0044837E B9 FF F1 00 00                                mov     ecx, 0F1FFh
		//.text:00448383 66 39 0E                                      cmp     [esi], cx
		//8B442414568B74241483F80872??B9FFF1000066390E

		int addr = FindHexString(V("8B442414568B74241483F80872??B9FFF1000066390E"), 0);

		if (addr == 0)
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 898);
			#endif
			return 0;
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("LOAD_BLOB_PROC_PTR", addr);
			#endif
			LoadBlob = (MYBLOBPROC)addr;
		}
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 897);
		#endif
		return 0;
	}
	return 1;
	VE();
}



bool PatchHeatmapCheck()
{	VU("PatchHeatmapCheck");

	if ( HeatMapCheck_ptr1 != NULL)
	{
		HeatMapCheck_ptr1[0] = 1;
		return true;
	}

	return false;
	VE();
}

bool GetHeatmapCheckPtr()
{	VM("GetHeatmapCheckPtr");

	__try  
	{
		//.text:004CB96C 80 3D 2C B6 CC 01 00                          cmp     heatmap_validated, 0
		//.text:004CB973 53                                            push    ebx
		//.text:004CB974 56                                            push    esi
		//.text:004CB975 8D 44 24 4C                                   lea     eax, [esp+9Ch+var_50]
		//.text:004CB979 8D 4C 24 6C                                   lea     ecx, [esp+9Ch+var_30]
		//.text:004CB97D 57                                            push    edi
		//.text:004CB97E 89 44 24 10                                   mov     [esp+0A0h+var_90], eax
		//.text:004CB982 89 4C 24 14                                   mov     [esp+0A0h+var_8C], ecx
		//803D????????0053568D44244C8D4C246C5789442410894C2414 

		int addr = FindHexString(V("803D????????0053568D44244C8D4C246C5789442410894C2414"), 0);
		if (addr != 0)
		{
			addr = *(DWORD*)(addr+2);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("HEATMAP_CHECK_PTR1", addr);
			#endif

			HeatMapCheck_ptr1 = (BYTE*)(addr);
		}


	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 997);
		#endif
		return 0;
	}
	return 1;
	VE();
}



bool GetGameBuildNum()
{	VM("GetGameBuildNum");

	__try  
	{
		if (GAME_MODE == 'D')
		{
			//.text:004CCE50 83 EC 08                                sub     esp, 8
			//.text:004CCE53 56                                      push    esi
			//.text:004CCE54 E8 F7 80 FE FF                          call    getbuild
			//.text:004CCE59 50                                      push    eax
			//.text:004CCE5A 68 EC D6 6E 00                          push    offset a1_4     ; "1.4"
			//.text:004CCE5F 68 DC D6 6E 00                          push    offset aVersionS_I ; "version %s.%i\n"
			//.text:004CCE64 6A 10                                   push    10h
			//.text:004CCE66 E8 25 EA FF FF                          call    sub_4CB890
			// 83EC0856E8????????5068????????68????????6A10E8

			int addr = FindHexString(V("83EC0856E8????????5068????????68????????6A10E8"), 0);
			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("BUILD_NUM_PTR_D", addr+4);
				#endif

				addr = *(DWORD*)(addr+5) + addr + 9;

				if (*(BYTE*)(addr) == 0xB8 && *(BYTE*)(addr+5) == 0xC3)
				{
					g_GameBuild = *(DWORD*)(addr+1);
				}

				#ifdef DEBUGGING_ENABLED
				info("Build is: %d", g_GameBuild);
				#endif
			}
		}

		if (GAME_MODE == 'M')
		{
			//.text:0046CB4F D9 1C 24                                      fstp    [esp+24h+var_24]
			//.text:0046CB52 51                                            push    ecx             ; double
			//.text:0046CB53 6A 40                                         push    40h             ; int
			//.text:0046CB55 E8 36 36 02 00                                call    sub_490190
			//.text:0046CB5A 50                                            push    eax
			//.text:0046CB5B 68 8C 47 81 00                                push    offset a1_4     ; "1.4"
			//.text:0046CB60 68 F0 78 7E 00                                push    offset aS_I     ; "%s.%i"
			//.text:0046CB65 E8 76 6C FC FF                                call    some_sprintf
			//.text:0046CB6A 83 C4 0C                                      add     esp, 0Ch
			//D91C24516A40E8????????5068????????68????????E8????????83C40C

			int addr = FindHexString(V("D91C24516A40E8????????5068????????68????????E8????????83C40C"), 0);
			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("BUILD_NUM_PTR_M", addr+6);
				#endif

				addr = *(DWORD*)(addr+7) + addr + 11;

				if (*(BYTE*)(addr) == 0xB8 && *(BYTE*)(addr+5) == 0xC3)
				{
					g_GameBuild = *(DWORD*)(addr+1);
				}

				#ifdef DEBUGGING_ENABLED
				info("Build is: %d", g_GameBuild);
				#endif
			}
		}
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 1997);
		#endif
		return 0;
	}
	return 1;
	VE();
}

bool GetSteamIDAndMpdataLocs()
{	VM("GetSteamIDAndMpdataLocs");

	if (g_MpdataLoc != NULL && g_SteamID_DW64 != NULL)
		return 1;

	__try  
	{
		//.text:00417E80 53                                            push    ebx
		//.text:00417E81 8B 5C 24 08                                   mov     ebx, [esp+4+arg_0]
		//.text:00417E85 56                                            push    esi
		//.text:00417E86 8B F3                                         mov     esi, ebx
		//.text:00417E88 69 F6 18 90 00 00                             imul    esi, 9018h
		//.text:00417E8E 53                                            push    ebx
		//.text:00417E8F 6A 06                                         push    6
		//.text:00417E91 81 C6 38 B6 CC 01                             add     esi, offset mpdata_data
		//.text:00417E97 68 80 4B CD 01                                push    offset mpdata_xxxxxxxxxxxxxxxxxxxxx
		//.text:00417E9C C6 86 00 30 00 00 00                          mov     byte ptr [esi+3000h], 0
		//538B5C2408568BF369F618900000536A0681C6
		int addr = FindHexString(V("538B5C2408568BF369F618900000536A0681C6"), 0);

		if (addr != 0)
		{
			g_MpdataLoc = (BYTE *)(*(DWORD*)(addr+19));

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("MPDATA_LOC", (DWORD)g_MpdataLoc);
			#endif
		}

		//.text:005576E0 8B 44 24 04                                   mov     eax, [esp+arg_0]
		//.text:005576E4 6B C0 68                                      imul    eax, 68h
		//.text:005576E7 8B 88 40 89 A6 05                             mov     ecx, steam_id__dw1[eax]
		//.text:005576ED 8B 80 44 89 A6 05                             mov     eax, steam_id__dw2[eax]
		//.text:005576F3 50                                            push    eax
		//.text:005576F4 8B 44 24 0C                                   mov     eax, [esp+4+arg_4]
		//.text:005576F8 51                                            push    ecx
		//.text:005576F9 50                                            push    eax
		//8B4424046BC0688B88????????8B80????????508B44240C5150
		addr = FindHexString(V("8B4424046BC0688B88????????8B80????????508B44240C5150"), 0);

		if (addr != 0)
		{
			g_SteamID_DW64 = (DWORD *)(*(DWORD*)(addr+9));

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("STEAMID_DW64_LOC", (DWORD)g_SteamID_DW64);
			#endif
		}
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 1001);
		#endif
		return 0;
	}
	return 1;
	VE();
}


typedef int (__cdecl *MYGETCLIENTCMD)(int requestedParam, char * outBuf, int outMaxSize);
int myGetClientCmd(DWORD caller, MYGETCLIENTCMD tramp, int requestedParam, char * outBuf, int outMaxSize)
{
	int ret = tramp(requestedParam, outBuf, outMaxSize);

	info("myGetClientCmd(requestedParam=%d, outBuf='%s', outMaxSize=%08X) -> result=%08X", requestedParam, outBuf, outMaxSize, ret);

	if (ret == NULL || (requestedParam == 0 && strncmp(outBuf, V("n"), 1) == 0))
		return ret;
	
	if (requestedParam == 0 && strncmp(outBuf, V("say"), 3) == 0)
	{
		char saytext[0x400];
		int ret2 = tramp(1, saytext, 0x400);

		if (ret2 != NULL && strnicmp(saytext+1, V("vote "), 5) == 0)
		{
			memset(outBuf, 0, outMaxSize);
			strcpy(outBuf, V("callvote"));
		}
	}

	if (requestedParam == 1 && strnicmp(outBuf+1, V("vote "), 5) == 0)
	{
		char cmdtext[0x400];
		int ret2 = tramp(0, cmdtext, 0x400);

		if (ret2 != NULL && strncmp(cmdtext, V("say"), 3) == 0)
		{
			strcpy(cmdtext, outBuf+6);
			memset(outBuf, 0, outMaxSize);
			strcpy(outBuf, cmdtext);
		}
	}

	//if (requestedParam == 2 && strcmp(outBuf, "") == 0)
	//{
	//	char saytext[0x400];
	//	int ret2 = tramp(1, saytext, 0x400);

	//	if (ret2 != NULL && strnicmp(saytext+1, V("vote kick "), 10) == 0)
	//	{
	//		memset(outBuf, 0, outMaxSize);
	//		strcpy(outBuf, saytext+11);
	//	}
	//}

	return ret;
}


bool GetClientsBlock()
{	VM("GetClientsBlock");

	if (GAME_MODE != 'D') return false;

	__try  
	{
		//.text:004E6EA0 8B 44 24 04                                   mov     eax, [esp+arg_0]
		//.text:004E6EA4 69 C0 88 86 07 00                             imul    eax, 78688h
		//.text:004E6EAA 05 90 B6 9E 04                                add     eax, offset clinets_block
		//.text:004E6EAF C7 80 C4 52 04 00 00 00 00 00                 mov     dword ptr [eax+452C4h], 0
		//.text:004E6EB9 C6 80 C0 52 04 00 01                          mov     byte ptr [eax+452C0h], 1
		//.text:004E6EC0 C3                                            retn
		//05????????C780C452040000000000C680C052040001
		int addr = FindHexString(V("05????????C780C452040000000000C680C052040001"), 0);

		if (addr != 0)
		{
			g_ClientsBlock = (PMW3_CLIENTS_INFO_DEDI)(*(DWORD*)(addr+1) - 4);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("CLIENTS_BLOCK_LOC", (DWORD)g_ClientsBlock);
			#endif
		}

		//.text:004800BF 8B F7                                         mov     esi, edi
		//.text:004800C1 69 F6 74 02 00 00                             imul    esi, 274h
		//.text:004800C7 81 C6 28 BB 8F 01                             add     esi, offset xxxxxxxx
		//.text:004800CD 83 BE 58 01 00 00 00                          cmp     dword ptr [esi+158h], 0
		//.text:004800D4 0F 84 6B 01 00 00                             jz      loc_480245
		//.text:004800DA 68 00 04 00 00                                push    400h            ; int
		//.text:004800DF 8D 44 24 0C                                   lea     eax, [esp+40Ch+var_400]
		//.text:004800E3 50                                            push    eax             ; char *
		//.text:004800E4 6A 00                                         push    0               ; int
		//.text:004800E6 E8 C5 F2 03 00                                call    sub_4BF3B0
		//8BF769F67402000081C6????????83BE58010000000F84????????68000400008D44240C506A00E8 
		addr = FindHexString(V("8BF769F67402000081C6????????83BE58010000000F84????????68000400008D44240C506A00E8"), 0);

		if (addr != 0)
		{
			g_ClientsBlock2 = *(DWORD*)(addr+10);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("CLIENTS_BLOCK2_LOC", (DWORD)g_ClientsBlock2);
			#endif

			addr += 40;
			addr = *(DWORD*)(addr) + 4 + addr;  
			hook_cdecl((void *)addr, myGetClientCmd);
		}

	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 5550);
		#endif
		return 0;
	}
	return 1;
	VE();
}





int myConsoleFunc(DWORD caller, MYCONPROC tramp, DWORD unk, char * command)
{	VM("myConsoleFunc");

	#ifdef DEBUGGING_ENABLED
	g_Logging.AddToLogFileA( "GameConsole.log", command);
	info("ConsoleCmd(%s)", command);
	#endif
	

	if (strncmp(command, V("exec config_mp"), 14) == 0)
	{
		if (GAME_MODE == 'D')
		{
			//cpu requirement stuff
			{
				dvar cpu_speed_8players(V("cpu_speed_8players"));
				float old = cpu_speed_8players.GetValueFL();
				cpu_speed_8players.SetValue(1);
				//ConsolePrintf(0, V("Set '%s' to %fGhz (from %fGhz)\n"), V("cpu_speed_8players"), cpu_speed_8players.GetValueFL(), old);

				dvar cpu_speed_12players(V("cpu_speed_12players"));
				old = cpu_speed_12players.GetValueFL();
				cpu_speed_12players.SetValue(1);
				//ConsolePrintf(0, V("Set '%s' to %fGhz (from %fGhz)\n"), V("cpu_speed_12players"), cpu_speed_12players.GetValueFL(), old);

				dvar cpu_speed_18players(V("cpu_speed_18players"));
				old = cpu_speed_18players.GetValueFL();
				cpu_speed_18players.SetValue(1);
				//ConsolePrintf(0, V("Set '%s' to %fGhz (from %fGhz)\n"), V("cpu_speed_18players"), cpu_speed_18players.GetValueFL(), old);

				ConsolePrintf(0, V("Using lowered CPU requirements (1Ghz).\n"));
			}


			//initialize team balance to 1 (true) - you can override it via server.cfg
			dvar tb(V("scr_teambalance"));
			if (tb.Inited)
			{
				//ConsolePrintf(0, "TB already inited to %s\n", tb.GetValueSTR());
			}
			else
			{
				Console(0, V("seta scr_teambalance 1;\n"));
				//ConsolePrintf(0, "TB inited to 1\n");
			}


			//get global ban list
			if (g_OnlineMode && g_GlobalBans) InitGlobalBans();

			//discover external ip -- primary way
			DWORD ip = GetExternalIP(false);

			if (g_OnlineMode)
			{	
				if (ip == 0x0100007F)
					StartIpDiscovery();
				else
				{
					char ipstr[256];
					makeIPstr(ip, ipstr);
					ConsolePrintf(0, V("Discovering external IP address skipped, using ini override: %s\n"), ipstr);
				}
			}
			else
			{
				char ipstr[256];
				makeIPstr(ip, ipstr);
				ConsolePrintf(0, V("Using external IP address: %s\n"), ipstr);
			}

		}
	}



	if (GAME_MODE == 'D')
	{
		if ((strncmp(command, V("redirect"), 8) == 0 && strstr(command, V("pdvars")) != NULL) || strncmp(command, V("pdvars"), 6) == 0)
		{
			MakeAllDvarsPrintable();
			ConsolePrintf(0, V("Dvars are now printable.\n"));
		}

		if ((strncmp(command, V("redirect"), 8) == 0 & strstr(command, V("dumpclients")) != NULL) || strncmp(command, V("dumpclients"), 11) == 0)
		{
			DumpClientsData();
		}
	}


	//
	// This allows a remote console users to execute a bit more commands
	// by using 'set' to carry the data over, for example
	// rcon set @quit
	// would execute 'quit' directly on the server (shut it down)
	// rcon set @say ohh please ^1LOL
	// would print 'console msg' to all clients on the server
	//
	if (GAME_MODE == 'D' && strncmp(command, V("redirect"), 8) == 0)
	{
		if (g_RCon_Full_Access)
		{
			char * newcmd = strstr(command, V("set @"));
			if (newcmd != NULL)
			{
				newcmd[0] = 0;
				newcmd += 5;
				char fixedcmd[256];
				sprintf(fixedcmd, V("%s%s\n"), command, newcmd);
				info("fixedcmd = %s", fixedcmd);

				return tramp(unk, fixedcmd);
				//return myConsoleFunc(caller, tramp, unk, fixedcmd);
			}
		}

		char * saycmd = strstr(command, V("set #say "));
		if (saycmd != NULL)
		{
				saycmd += 5;
				Console(0, saycmd);
		}
	}

	
	if (strncmp(command, V("cmd "), 4) == 0)
	{
		//nicos most wanted patch!!! show ping as number, not green bars
		// .. turned out to be COD4 feature, thanks nico for checking out if it works before requesting this feature... lame
		if (GAME_MODE == 'M')
		{
			LockIntDvarTo("cg_scoreboardpingtext", 1);
			LockIntDvarTo("cg_scoreboardpinggraph", 0);
			LockIntDvarTo("cg_scoreboardheight", 800);
			LockIntDvarTo("cg_scoreboardwidth", 500);
			LockIntDvarTo("cg_scoreboarditemheight", 12);
		}
	}


	



	//lets use this as a trigger to patch heatmap checks
	if (strncmp(command, V("xcheckezpatchversion"), 20) == 0 || strncmp(command, V("updategamerprofile"), 18) == 0)
	{
		SaveDWMpdataToFile(false);
	}

	if (strncmp(command, V("connect "), 8) == 0)
	{
		ServerList* pList = ServerList::getInstance();
		if (pList == NULL)
		{
			info("ERROR: Unable to get ServerList instance!");
			return 0;
		}

		char *server = strstr(command, V("connect "))+8;
		DWORD ip = 0;
		USHORT port = 0;

		if (parseIpPort(server, &ip, &port))
		{

			void * blob = pList->createConnectionBlob(htonl(ip), port, true);

			if (blob != NULL)
			{
				pList->startConnBlobLoaderThread(blob);
			}
			else
			{
				info("ERROR: Blob for selected server couldn't be found.");
				return 0;
			}
		}
		else
		{
			info("ERROR: Invalid server ip:port");
			return 0;
		}
	}

	//special command triggered by F12 key, connects to a server specified by "server" command line value (for ex. +server "1.2.3.4:1337")
	if (strncmp(command, V("connect_ext"), 11) == 0)
	{
		char * cmdline = (char *)GetCommandLineA();
		char *server = strstr(cmdline, V("+server "));
		if (server == NULL)
		{
			info("ERROR: +server commandline param not found.");
			return 0;
		}

		ServerList* pList = ServerList::getInstance();
		if (pList == NULL)
		{
			info("ERROR: Unable to get ServerList instance!");
			return 0;
		}

		char connect_cmd[255];

		DWORD ip = 0;
		USHORT port = 0;
		char ip_str[255];

		if (parseIpPort(server+8, &ip, &port))
		{
			makeIPstr(ip, ip_str);

			sprintf(connect_cmd, V("connect %s:%d\n"), ip_str, port);

			#ifdef DEBUGGING_ENABLED
			info("ip %08X port %04X  ->> console cmd will be: %s", ip, port, connect_cmd);
			#endif
			
			
			void * blob = pList->createConnectionBlob(htonl(ip), port, false);
			pList->startConnBlobLoaderThread(blob);

			return tramp(unk, connect_cmd);
		}
		else
		{
			info("ERROR: Invalid 'server' command line value. Required format: +server ip:netport");
			return 0;
		}
	}


	//if we need to change some dvars, lets do it here..
	if (g_NewFov != 0) 
	{
		if (g_NewFov > 90)
			g_NewFov = 90;
		if (g_NewFov < 65)
			g_NewFov = 65;

		if (g_NewFov > 80)
		{
			float scale = 1.0 + ((g_NewFov-80.0) * 0.0125);
			LockFloatDvarTo(V("cg_fovscale"), scale);

			LockIntDvarTo(V("cg_fov"), 80);
		}
		else
		{
			LockIntDvarTo(V("cg_fov"), g_NewFov);
		}
	}


	return tramp(unk, command);
	VE();
}

bool HookConsole()
{	VM("HookConsole");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		addr = FindHexString(V("6A??E8????????8B44240C8A0883C40480F970740580F95075??8A480180F930"), 0);
		if (addr > 0)
		{
			hook_cdecl((void*)(addr), myConsoleFunc);
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 476);
			#endif
			return 0;
		}

	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 477);
		#endif
		return 0;
	}
	return 1;

	VE();
}





//.text:006DBDA2 68 A0 00 85 00                                push    offset aFailedToSendIp ; "Failed to send IP discovery packet."
//.text:006DBDA7 68 9A 00 00 00                                push    9Ah
//.text:006DBDAC 68 C4 00 85 00                                push    offset aBdipdiscover_3 ; "bdIPDiscoveryClient::sendIPDiscoveryPac"...
//.text:006DBDB1 68 F8 FE 84 00                                push    offset aCTreesIw5bu_12 ; "c:\\trees\\iw5build6-iw-release\\iw5\\code_"...
//.text:006DBDB6 68 B8 F9 84 00                                push    offset aBdsocketNat ; "bdSocket/nat"
//.text:006DBDBB 68 50 C1 84 00                                push    offset aErr     ; "err/"
//.text:006DBDC0 6A 02                                         push    2
typedef DWORD (__cdecl *DWLOG)(DWORD e_type, char * prolog, char * service, char * codetree, char * funcname, DWORD unk1, char * format);
DWORD __cdecl myDWLogFunc(DWORD caller, DWLOG tramp, DWORD e_type, char * prolog, char * service, char * codetree, char * funcname, DWORD unk1, char * format, ... )
{	VM("myDWLogFunc");

	#ifdef DEBUGGING_ENABLED
	char buf[1024 * 10];
	va_list marker;
	va_start(marker, format);
	vsprintf(buf, format, marker);
	va_end(marker);

	char* whole_msg = new char[2048];
	sprintf(whole_msg, "%s %s->(%s)\n", service, funcname, buf);
	OutputDebugStringA(whole_msg);
	delete [] whole_msg;
	#endif

	//Set external ip to whatever game has figured out from the router
	//if (GAME_MODE == 'D' && strncmp(format, V("External address on device"), 26) == 0)
	//{
	//	char bufb[1024];
	//	va_list markerb;
	//	char * format_b = new char [20];
	//	strcpy(format_b, V("%s")); 
	//	va_start(markerb, format);
	//	vsprintf(bufb, format_b, markerb);
	//	delete []format_b;
	//	GetExternalIP(false, bufb);
	//}

	return 0; //tramp(e_type, prolog, service, codetree, funcname, unk1, format);

	VE();
}





bool HookDWLogFunc()
{	VM("HookDWLogFunc");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);


		//.text:006E89E0 55                                            push    ebp
		//.text:006E89E1 8B EC                                         mov     ebp, esp
		//.text:006E89E3 81 EC 28 02 00 00                             sub     esp, 228h
		//.text:006E89E9 A1 24 02 8C 00                                mov     eax, dword_8C0224
		//.text:006E89EE 33 C5                                         xor     eax, ebp
		//.text:006E89F0 89 45 F8                                      mov     [ebp+var_8], eax
		//.text:006E89F3 83 3D 3C 15 BD 06 00                          cmp     dword_6BD153C, 0
		//.text:006E89FA 0F 84 91 01 00 00                             jz      loc_6E8B91
		//.text:006E8A00 C7 85 E8 FD FF FF 00 01 00 00                 mov     [ebp+var_218], 100h
		//.text:006E8A0A 68 00 01 00 00                                push    100h            ; size_t
		//.text:006E8A0F 6A 00                                         push    0               ; int
		//.text:006E8A11 8D 85 F0 FD FF FF                             lea     eax, [ebp+DstBuf]
		// 558BEC81EC??020000A1????????33C58945F8833D????????000F??????0000C785E8FDFFFF0001000068000100006A00
		addr = FindHexString(V("558BEC81EC??020000A1????????33C58945F8833D????????000F??????0000C785E8FDFFFF0001000068000100006A00"), 0);

		
		if (addr > 14)
		{
			hook_cdecl((void*)(addr), myDWLogFunc);
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 111);
			#endif
			return 0;
		}

		#ifdef DEBUGGING_ENABLED
		DebugOutValue("DW_LOG_FUNC_PTR", addr);
		#endif

		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 112);
		#endif
		return 0;
	}

	return 1;

	VE();
}



bool HookDWGetFile()
{	VM("HookDWGetFile");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);



		//online files request
		//.text:00456180 81 EC 84 00 00 00                             sub     esp, 84h
		//.text:00456186 56                                            push    esi
		//.text:00456187 8B B4 24 8C 00 00 00                          mov     esi, [esp+88h+arg_0]
		//.text:0045618E 0F B6 46 7D                                   movzx   eax, byte ptr [esi+7Dh]
		//.text:00456192 50                                            push    eax
		//.text:00456193 E8 78 BD FB FF                                call    sub_411F10
		//.text:00456198 83 C4 04                                      add     esp, 4
		//.text:0045619B 85 C0                                         test    eax, eax
		//81EC??000000568BB424??0000000FB6467D50E8????????83C40485C0
		FindHexString_Quiet = true;
		addr = addr = FindHexString(V("81EC??000000568BB424??0000000FB6467D50E8????????83C40485C0"), 0); 
		while (addr > 0)
		{

			hook_cdecl((void*)(addr), myDWGetFile);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("DW_GETFILE_FUNC_PTR_A", addr);
			#endif

			addr = FindHexString(V("81EC??000000568BB424??0000000FB6467D50E8????????83C40485C0"), 0);
		}
		

		
		//
		//.text:004E1DC0 83 EC 48                                      sub     esp, 48h
		//.text:004E1DC3 56                                            push    esi
		//.text:004E1DC4 57                                            push    edi
		//.text:004E1DC5 8B 7C 24 54                                   mov     edi, [esp+50h+arg_0]
		//.text:004E1DC9 0F B6 47 7D                                   movzx   eax, byte ptr [edi+7Dh]
		//.text:004E1DCD 50                                            push    eax
		//.text:004E1DCE E8 3D 01 F3 FF                                call    sub_411F10
		//.text:004E1DD3 8B F0                                         mov     esi, eax
		// 83EC??56578B7C24??0FB6477D50E8????????8BF0
		addr = addr = FindHexString(V("83EC??56578B7C24??0FB6477D50E8????????8BF0"), 0); 
		while (addr > 0)
		{

			hook_cdecl((void*)(addr), myDWGetFile);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("DW_GETFILE_FUNC_PTR_B", addr);
			#endif

			addr = FindHexString(V("83EC??56578B7C24??0FB6477D50E8????????8BF0"), 0);
		}
		// used to get infos also upload
		//.text:00505180 81 EC 84 00 00 00                             sub     esp, 84h
		//.text:00505186 53                                            push    ebx
		//.text:00505187 8B 9C 24 8C 00 00 00                          mov     ebx, [esp+88h+arg_0]
		//.text:0050518E 0F B6 43 7D                                   movzx   eax, byte ptr [ebx+7Dh]
		//.text:00505192 50                                            push    eax
		//.text:00505193 E8 78 CD F0 FF                                call    sub_411F10
		//.text:00505198 83 C4 04                                      add     esp, 4
		// 81EC??000000538B9C24??0000000FB6437D50E8????????83C404
		addr = addr = FindHexString(V("81EC??000000538B9C24??0000000FB6437D50E8????????83C404"), 0); 
		while (addr > 0)
		{

			hook_cdecl((void*)(addr), myDWGetFile);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("DW_GETFILE_FUNC_PTR_C", addr);
			#endif

			addr = FindHexString(V("81EC??000000538B9C24??0000000FB6437D50E8????????83C404"), 0);
		}
		// used to get files
		//.text:004D8550 81 EC 88 00 00 00                             sub     esp, 88h
		//.text:004D8556 55                                            push    ebp
		//.text:004D8557 8B AC 24 90 00 00 00                          mov     ebp, [esp+8Ch+arg_0]
		//.text:004D855E 0F B6 45 7D                                   movzx   eax, byte ptr [ebp+7Dh]
		//.text:004D8562 50                                            push    eax
		//.text:004D8563 E8 A8 99 F3 FF                                call    sub_411F10
		//.text:004D8568 8B C8                                         mov     ecx, eax
		//.text:004D856A 83 C4 04                                      add     esp, 4
		// 81EC??000000558BAC24??0000000FB6457D50E8????????8BC883C404
		addr = addr = FindHexString(V("81EC??000000558BAC24??0000000FB6457D50E8????????8BC883C404"), 0); 
		while (addr > 0)
		{

			hook_cdecl((void*)(addr), myDWGetFile);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("DW_GETFILE_FUNC_PTR_D", addr);
			#endif

			addr = FindHexString(V("81EC??000000558BAC24??0000000FB6457D50E8????????8BC883C404"), 0);
		}


		FindHexString_Quiet = false;
		
		//if (addr > 14)
		//{
		//	hook_cdecl((void*)(addr), myDWGetFile);
		//}
		//else
		//{
		//	DebugOutValue("Error", 211);
		//	return 0;
		//}

		//#ifdef DEBUGGING_ENABLED
		//DebugOutValue("DW_GETFILE_FUNC_PTR", addr);
		//#endif

		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 212);
		#endif
		return 0;
	}

	return 1;

	VE();
}


typedef DWORD (__cdecl *ISMAPINST)(char * file_name, int type);
DWORD __cdecl myIsMapInstalled(DWORD caller, ISMAPINST tramp, char * file_name, int type)
{	VM("myIsMapInstalled");

	DWORD ret = tramp(file_name, type);

	if ((ret&0xFF) == 0 && type == 0)
	{
		ConsolePrintf(0, V("Warning: Map files for '%s' are missing (could be from DLC), running map_rotate again...\n"), file_name);
		Console(0, V("map_rotate\n"));
	}

	return ret;
	VE();
}



bool HookIsMapInstalled()
{	VM("HookIsMapInstalled");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		//.text:00456C00 81 EC 00 01 00 00                             sub     esp, 100h
		//.text:00456C06 83 BC 24 08 01 00 00 00                       cmp     [esp+100h+arg_4], 0
		//.text:00456C0E 75 2F                                         jnz     short loc_456C3F
		//.text:00456C10 8B 84 24 04 01 00 00                          mov     eax, [esp+100h+arg_0]
		//.text:00456C17 50                                            push    eax
		//.text:00456C18 50                                            push    eax
		//81EC0001000083BC240801000000752F8B8424040100005050
		addr = FindHexString(V("81EC0001000083BC240801000000752F8B8424040100005050"), 0);  //
		if (addr > 0)
		{
			hook_cdecl((void*)(addr), myIsMapInstalled);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("IS_MAP_INSTALLED_FUNC_PTR", addr);
			#endif
		}

		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 330);
		#endif
		return 0;
	}

	return 1;

	VE();
}





typedef void (__cdecl *PROCUICMD)(int clientnum);
void __cdecl myProcessClientUICommand(DWORD caller, PROCUICMD tramp, int clientnum)
{	VM("myProcessClientUICommand");

	char *cmd = NULL;
	__asm
	{
		push dword ptr [ebp+0x14];
		pop cmd; 
	}

	
	if (strncmp(cmd, V("callvote "), 9) == 0)
	{
		PrintBuffer((BYTE *)(g_ClientsBlock2 + 0x274 * clientnum), 0x274, 16);
	}

	if (strncmp(cmd, V("mr "), 3) == 0)
	{
		#ifdef DEBUGGING_ENABLED
		if (g_ClientsBlock != NULL)
		{
			ConsolePrintf(0, V("User(%d) '%s' tried command '%s'\n"), clientnum, g_ClientsBlock->Clients[clientnum].Nickname, cmd);
		}
		#endif

		dvar gm(V("g_gametype"));
		if (strcmp(V("infect"), gm.GetValueSTR()) == 0)
		{
			if (strstrnocase(cmd, V("2 allies")) != NULL || strstrnocase(cmd, V("2 axis")) != NULL || strstrnocase(cmd, V("2 autoassign")) || strstrnocase(cmd, V("2 spectator")) != NULL)
			{
				#ifdef DEBUGGING_ENABLED
				ConsolePrintf(0, "-> this command is forbidden when playing '%s' game type, banning client(%d).\n", gm.GetValueSTR(), clientnum);
				#endif
				char cmd2[256];
				sprintf(cmd2, V("kickclient %d;\n"), clientnum);
				Console(0, cmd2);
				return;
			}
		}

		if (strstrnocase(cmd, V("endround")) != NULL || strstrnocase(cmd, V("endme")) != NULL || strstrnocase(cmd, V("endgame")) != NULL)
		{
			#ifdef DEBUGGING_ENABLED
			ConsolePrintf(0, "-> this command is forbidden, banning client(%d).\n", clientnum);
			#endif
			char cmd2[256];
			sprintf(cmd2, V("banclient %d;\n"), clientnum);
			Console(0, cmd2);
			return;
		}
	}

	tramp(clientnum);

	VE();
}


bool HookProcessClientUICommand()
{	VM("HookProcessClientUICommand");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		//.text:004800B0 81 EC 00 04 00 00                             sub     esp, 400h
		//.text:004800B6 56                                            push    esi
		//.text:004800B7 57                                            push    edi
		//.text:004800B8 8B BC 24 0C 04 00 00                          mov     edi, [esp+408h+arg_0]
		//.text:004800BF 8B F7                                         mov     esi, edi
		//.text:004800C1 69 F6 74 02 00 00                             imul    esi, 274h
		//.text:004800C7 81 C6 28 BB 8F 01                             add     esi, offset unk_18FBB28
		//.text:004800CD 83 BE 58 01 00 00 00                          cmp     dword ptr [esi+158h], 0
		//.text:004800D4 0F 84 6B 01 00 00                             jz      loc_480245
		//81EC0004000056578BBC240C0400008BF769F67402000081C6
		addr = FindHexString(V("81EC0004000056578BBC240C0400008BF769F67402000081C6"), 0);
		if (addr > 0)
		{
			hook_cdecl((void*)(addr), myProcessClientUICommand);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("GET_PROCESS_CLIENT_UI_CMD_FUNC_PTR", addr);
			#endif
		}
		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 1612);
		#endif
		return 0;
	}
	return 1;

	VE();
}





typedef DWORD (__cdecl *GENSECKEY)(void * sec_id, void * sec_key);
DWORD __cdecl myGenerateSecurityKeys(DWORD caller, GENSECKEY tramp, DWORD * sec_id, DWORD * sec_key)
{	VM("myGenerateSecurityKeys");

	DWORD ret = tramp(sec_id, sec_key);

	if (strstr(GetCommandLineA(), V("+usekeys")) == NULL)
	{
		memset(sec_id, STATIC_SECURITY_KEY, 8);
		memset(sec_key, STATIC_SECURITY_KEY, 16);
	}

	memcpy(g_ServerKeyId, sec_id, 8);
	memcpy(g_ServerKey, sec_key, 16);

	return ret;
	VE();
}


bool HookGenerateSecurityKeys()
{	VM("HookGenerateSecurityKeys");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);



		//.text:00567CD0 6A 1E                                   push    1Eh
		//.text:00567CD2 E8 C9 B0 FB FF                          call    sub_522DA0
		//.text:00567CD7 83 C4 04                                add     esp, 4
		//.text:00567CDA E8 C1 34 02 00                          call    sub_58B1A0
		//.text:00567CDF 85 C0                                   test    eax, eax
		//.text:00567CE1 74 12                                   jz      short loc_567CF5
		//.text:00567CE3 8B 44 24 08                             mov     eax, [esp+arg_4]
		//.text:00567CE7 8B 4C 24 04                             mov     ecx, [esp+arg_0]
		//.text:00567CEB 50                                      push    eax
		//.text:00567CEC 51                                      push    ecx
		//.text:00567CED E8 6E C7 06 00                          call    sub_5D4460
		//.text:00567CF2 83 C4 08                                add     esp, 8
		//.text:00567CF5
		//.text:00567CF5                         loc_567CF5:                             ; CODE XREF: sub_567CD0+11j
		//.text:00567CF5 6A 1E                                   push    1Eh
		//.text:00567CF7 E8 C4 B0 FB FF                          call    sub_522DC0
		//.text:00567CFC 59                                      pop     ecx
		//.text:00567CFD C3                                      retn
		//6A1EE8????????83C404E8????????85C07412 8B4424088B4C24045051E8????????83C4086A1E59C3
		FindHexString_Quiet = true;
		addr = FindHexString(V("6A1EE8????????83C404E8????????85C07412"), 0);  //
		while (addr > 0)
		{

			hook_cdecl((void*)(addr), myGenerateSecurityKeys);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("GENERATE_SECKEY_FUNC_PTR_A", addr);
			#endif

			addr = FindHexString(V("6A1EE8????????83C404E8????????85C07412"), 0);
		}
		FindHexString_Quiet = false;


		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 312);
		#endif
		return 0;
	}

	return 1;

	VE();

}


bool HookGetBanStatus()
{	VM("HookGetBanStatus");

	//clear visitor list
	InitVisitorsList();
	//hook ban func
	if (!HookClientBan()) return false;

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		//.text:004E5AB0 81 EC 08 02 00 00                             sub     esp, 208h
		//.text:004E5AB6 80 3E 00                                      cmp     byte ptr [esi], 0
		//.text:004E5AB9 75 09                                         jnz     short loc_4E5AC4
		//.text:004E5ABB
		//.text:004E5ABB                               loc_4E5ABB:                             ; CODE XREF: sub_4E5AB0+27j
		//.text:004E5ABB 33 C0                                         xor     eax, eax
		//.text:004E5ABD 81 C4 08 02 00 00                             add     esp, 208h
		//.text:004E5AC3 C3                                            retn
		//81EC08020000803E00750933C081C408020000C3
		addr = FindHexString(V("81EC08020000803E00750933C081C408020000C3"), 0);  //
		if (addr > 0)
		{
			hook((void*)(addr), myGetBanStatus_asm_port14);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("GET_BAN_STATUS_FUNC_PTR", addr);
			#endif
		}
		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 1412);
		#endif
		return 0;
	}
	return 1;

	VE();
}




bool HookClientBan()
{	VM("HookClientBan");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		//.text:004E8140 83 EC 40                                      sub     esp, 40h
		//.text:004E8143 57                                            push    edi
		//.text:004E8144 8B 7C 24 48                                   mov     edi, [esp+44h+arg_0]
		//.text:004E8148 83 7F 28 02                                   cmp     dword ptr [edi+28h], 2
		//.text:004E814C 75 18                                         jnz     short loc_4E8166
		//.text:004E814E 6A 65                                         push    65h             ; char
		//.text:004E8150 68 2C 62 6F 00                                push    offset aCExe_cannotkic ; "%c \"EXE_CANNOTKICKHOSTPLAYER\""
		//.text:004E8155 6A 00                                         push    0               ; int
		//.text:004E8157 6A 00                                         push    0               ; int
		//.text:004E8159 E8 F2 31 00 00                                call    sub_4EB350
		//.text:004E815E 83 C4 10                                      add     esp, 10h
		//.text:004E8161 5F                                            pop     edi
		//.text:004E8162 83 C4 40                                      add     esp, 40h
		//.text:004E8165 C3                                            retn
		//83EC40578B7C2448837F280275186A6568????????6A006A00E8????????83C4105F83C440C3
		addr = FindHexString(V("83EC40578B7C2448837F280275186A6568????????6A006A00E8????????83C4105F83C440C3"), 0);
		if (addr > 0)
		{
			hook_cdecl((void*)(addr), myClientBan);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("CLIENT_BAN_FUNC_PTR", addr);
			#endif
		}
		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 1412);
		#endif
		return 0;
	}
	return 1;

	VE();
}






typedef bool (__cdecl *AUTHIP)(int length, int ip, short port, int unk1, int unk2, int unk3);
DWORD __cdecl myAuthorizeIP(DWORD caller, AUTHIP tramp, int length, int ip, short port, int unk1, int unk2, int unk3)
{	VM("myAuthorizeIP");

	bool ret = tramp(length, ip, port, unk1, unk2, unk3);
	
	#ifdef DEBUGGING_ENABLED
	info("AuthorizeIP(%08X, %08X, %08X, %08X, %08X, %08X) -> %d", length, ip, port, unk1, unk2, unk3, ret);
	#endif

	if (GAME_MODE == 'D')
		return 1;

	return 0;

	VE();
}



bool HookAuthorizeIP()
{
	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		//.text:005260C0 8B 4C 24 04                             mov     ecx, [esp+arg_0]
		//.text:005260C4 8B 54 24 0C                             mov     edx, [esp+arg_8]
		//.text:005260C8 56                                      push    esi
		//.text:005260C9 83 EC 18                                sub     esp, 18h
		//.text:005260CC 8B C4                                   mov     eax, esp
		//.text:005260CE 89 08                                   mov     [eax], ecx
		//.text:005260D0 8B 4C 24 24                             mov     ecx, [esp+1Ch+arg_4]
		//.text:005260D4 89 48 04                                mov     [eax+4], ecx
		//.text:005260D7 89 50 08                                mov     [eax+8], edx
		//8B4C24048B54240C5683EC188BC489088B4C2424894804895008
		addr = FindHexString(V("8B4C24048B54240C5683EC188BC489088B4C2424894804895008"), 0);  //
		if (addr > 0)
		{

			hook_cdecl((void*)(addr), myAuthorizeIP);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("AUTHORIZE_IP_FUNC_PTR", addr);
			#endif
		}
		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 412);
		#endif
		return 0;
	}
	return 1;
}


//
//
//typedef int (__stdcall *GENSECRETKEY)(int x, int y, int z, int q);
//DWORD __stdcall myGenerateSharedSecretKey(DWORD caller, GENSECRETKEY tramp, int x, int y, int z, int q)
//{
//	int _this = 0;
//	__asm mov _this, ecx;
//
//	int ret = 0; //tramp(x, y, z, q);
//	
//	#ifdef DEBUGGING_ENABLED
//	info("GenerateSharedSecretKey(%08X, %08X, %08X, %08X) -> %08X", x, y, z, q, ret);
//	#endif
//
//	memset((void*)_this, 1, z);
//
//	return 1;
//}
//
//
//int __stdcall myFuncX(int dis, int x, int y, int z, int q)
//{
//	info("GenerateSharedSecretKey(%08X, %08X, %08X, %08X) dis = %08X", x, y, z, q, dis);
//	memset((void*)z, 1, q);
//	return 1;
//}
//
//int test_ptr = 0;
//int test_ptr2 = 0;
//int test_ptr3 = 0;
//void __declspec(naked) myGenerateSharedSecretKey_naked()
//{
//	__asm
//	{	
//		pop		test_ptr2
//		mov		test_ptr3, ecx
//		call	func
//		
//		mov eax, esp
//
//		push [eax-4]
//		push [eax-0x8]
//		push [eax-0xc]
//		push [eax-0x10]
//		push test_ptr3
//		call myFuncX
//		jmp test_ptr2
//
//	func:
//		push	ebp
//		mov		ebp, esp
//		push    0FFFFFFFFh
//		jmp		test_ptr
//	}
//}
//
//
//
//
//bool HookGenerateSharedSecretKey()
//{
//	int addr = 0;
//	__try  
//	{
//		DWORD oldp;
//		int addr2 = 0x400000 + GetSectionPtr(0);
//		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);
//
//		//.text:005EEA90 55                                      push    ebp
//		//.text:005EEA91 8B EC                                   mov     ebp, esp
//		//.text:005EEA93 6A FF                                   push    0FFFFFFFFh
//		//.text:005EEA95 68 88 34 6D 00                          push    offset loc_6D3488
//		//.text:005EEA9A 64 A1 00 00 00 00                       mov     eax, large fs:0
//		//.text:005EEAA0 50                                      push    eax
//		//.text:005EEAA1 83 EC 40                                sub     esp, 40h
//		//.text:005EEAA4 A1 E4 BC 79 00                          mov     eax, dword_79BCE4
//		//.text:005EEAA9 33 C5                                   xor     eax, ebp
//		//.text:005EEAAB 50                                      push    eax
//		//.text:005EEAAC 8D 45 F4                                lea     eax, [ebp+var_C]
//		//.text:005EEAAF 64 A3 00 00 00 00                       mov     large fs:0, eax
//		//.text:005EEAB5 89 4D B4                                mov     [ebp+var_4C], ecx
//		//.text:005EEAB8 C6 45 CF 00                             mov     [ebp+var_31], 0
//		//.text:005EEABC 8D 4D D0                                lea     ecx, [ebp+var_30]
//		//558BEC6AFF68????????64A1000000005083EC40A1????????33C5508D45F464A300000000894DB4C645CF008D4DD0
//		addr = FindHexString(V("558BEC6AFF68????????64A1000000005083EC40A1????????33C5508D45F464A300000000894DB4C645CF008D4DD0"), 0);
//		if (addr > 0)
//		{
//
//			//hook((void*)(addr), myGenerateSharedSecretKey);
//			//hookNoTramp((void*)(addr), myGenerateSharedSecretKey_naked);
//			//test_ptr = addr + 5;
//
//			#ifdef DEBUGGING_ENABLED
//			DebugOutValue("GENERATE_SHARED_SECRET_KEY_FUNC_PTR", addr);
//			#endif
//		}
//		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
//	}
//	__except ( EXCEPTION_EXECUTE_HANDLER )
//	{
//		#ifdef DEBUGGING_ENABLED
//		DebugOutValue("Error", 1412);
//		#endif
//		return 0;
//	}
//	return 1;
//}



//DWORD __stdcall myGenerateSharedKey(int x, int y, int z, int q)
//{
//	#ifdef DEBUGGING_ENABLED
//	info("GenerateSharedSecretKey(%08X, %08X, %08X, %08X)", x, y, z, q);
//	#endif
//
//	memset((void*)z, 1, 0x1c);
//
//	return 1;
//}

//
//
//bool HookGenerateSharedKey()
//{
//	int addr = 0;
//	__try  
//	{
//		DWORD oldp;
//		int addr2 = 0x400000 + GetSectionPtr(0);
//		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);
//
//		//.text:006E45F6 8B 45 80                             mov     eax, [ebp+var_80]
//		//.text:006E45F9 05 A0 03 00 00                       add     eax, 3A0h
//		//.text:006E45FE 50                                   push    eax
//		//.text:006E45FF 6A 2C                                push    2Ch
//		//.text:006E4601 8D 4D 8C                             lea     ecx, [ebp+var_74]
//		//.text:006E4604 51                                   push    ecx
//		//.text:006E4605 8D 4D F0                             lea     ecx, [ebp+var_10]
//		//.text:006E4608 E8 33 A7 00 00                       call    sub_6EED40
//		//8B458005A0030000506A2C8D4D8C518D4DF0E8
//		addr = FindHexString(V("8B458005A0030000506A2C8D4D8C518D4DF0E8"), 0);
//		if (addr > 0)
//		{
//
//			hookNoTramp((void*)(addr+18), myGenerateSharedKey);
//			*(BYTE*)(addr+18) = 0xE8;
//			//hookNoTramp((void*)(addr), myGenerateSharedSecretKey_naked);
//			//test_ptr = addr + 5;
//
//			#ifdef DEBUGGING_ENABLED
//			DebugOutValue("GENERATE_SHARED_SECRET_KEY_FUNC_PTR", addr);
//			#endif
//		}
//		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
//	}
//	__except ( EXCEPTION_EXECUTE_HANDLER )
//	{
//		#ifdef DEBUGGING_ENABLED
//		DebugOutValue("Error", 1412);
//		#endif
//		return 0;
//	}
//	return 1;
//}




char g_FALSE[4] = "0";
char g_TRUE[4] = "1";

typedef char* (__cdecl *DVARTOSTRFORSCRIPTS)(char * dvar_name, char * dvar_def_val);
char* __cdecl myDvarToStrForScripts(DWORD caller, DVARTOSTRFORSCRIPTS tramp, char * dvar_name, char * dvar_def_val)
{	VM("myDvarToStrForScripts");

	char* ret = tramp(dvar_name, dvar_def_val);

	if (g_Set_Ranked_Games)
	{
		#ifdef DEBUGGING_ENABLED
		
		char buf[1024];
		if (*(BYTE*)ret == 0)
			sprintf(buf, "%30s = (null)", dvar_name);
		else if (strlen(ret) < 1024)
			sprintf(buf, "%30s = %s (default = %s)", dvar_name, ret, dvar_def_val);
		else
			sprintf(buf, "%30s = (too long)", dvar_name);

		if (GAME_MODE == 'D')
			g_Logging.AddToLogFileA( "ScriptDvarAccess_D.log", buf);
		else if (GAME_MODE == 'M')
			g_Logging.AddToLogFileA( "ScriptDvarAccess_M.log", buf);
		else if (GAME_MODE == 'S')
			g_Logging.AddToLogFileA( "ScriptDvarAccess_S.log", buf);
		#endif	

		if (strncmp(dvar_name, V("xblive_privatematch"), 19) == 0 || strncmp(dvar_name, V("onlinegame"), 10) == 0)
		{
			#ifdef DEBUGGING_ENABLED
			info("Fixed script Dvar ('%s') read from '%s' to '0'.", dvar_name, ret);
			#endif	
			return g_FALSE;
		}

	}

	return ret;
	VE();
}


bool HookDvarToStrForScripts()
{	VU("HookDvarToStrForScripts");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		//.text:0051D010 57                                      push    edi
		//.text:0051D011 8B 7C 24 08                             mov     edi, [esp+4+arg_0]
		//.text:0051D015 E8 36 FE FF FF                          call    sub_51CE50
		//.text:0051D01A 85 C0                                   test    eax, eax
		//.text:0051D01C 75 06                                   jnz     short loc_51D024
		//.text:0051D01E 8B 44 24 0C                             mov     eax, [esp+4+arg_4]
		//.text:0051D022 5F                                      pop     edi
		//.text:0051D023 C3                                      retn
		//.text:0051D024                         ; ---------------------------------------------------------------------------
		//.text:0051D024
		//.text:0051D024                         loc_51D024:                             ; CODE XREF: sub_51D010+Cj
		//.text:0051D024 8B 50 0C                                mov     edx, [eax+0Ch]
		//.text:0051D027 83 EC 10                                sub     esp, 10h
		//.text:0051D02A 8B CC                                   mov     ecx, esp
		//.text:0051D02C 89 11                                   mov     [ecx], edx
		//578B7C2408E8????????85C075068B44240C5FC38B500C83EC108BCC8911
		addr = FindHexString(V("578B7C2408E8????????85C075068B44240C5FC38B500C83EC108BCC8911"), 0); 
		if (addr > 0)
		{

			hook_cdecl((void*)(addr), myDvarToStrForScripts);

			#ifdef DEBUGGING_ENABLED
			DebugOutValue("DVAR_TO_STR_FOR_SCRIPTS_PTR", addr);
			#endif
		}
		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 888);
		#endif
		return 0;
	}
	return 1;
	VE();
}

bool GetDvarAndFuncListPtrs()
{
	int addr = 0;
	__try  
	{
		//.text:0051BD30 8B 4C 24 04                             mov     ecx, [esp+arg_0]
		//.text:0051BD34 8B 51 0C                                mov     edx, [ecx+0Ch]
		//.text:0051BD37 83 EC 10                                sub     esp, 10h
		//.text:0051BD3A 8B C4                                   mov     eax, esp
		//.text:0051BD3C 89 10                                   mov     [eax], edx
		//.text:0051BD3E 8B 51 10                                mov     edx, [ecx+10h]
		//.text:0051BD41 89 50 04                                mov     [eax+4], edx
		//.text:0051BD44 8B 51 14                                mov     edx, [ecx+14h]
		//.text:0051BD47 89 50 08                                mov     [eax+8], edx
		//.text:0051BD4A 8B 51 18                                mov     edx, [ecx+18h]
		//.text:0051BD4D 51                                      push    ecx
		//.text:0051BD4E 89 50 0C                                mov     [eax+0Ch], edx
		//.text:0051BD51 E8 AA FA FF FF                          call    sub_51B800
		//.text:0051BD56 83 C4 14                                add     esp, 14h
		//.text:0051BD59 C3                                      retn
		addr = FindHexString(V("8B4C24048B510C83EC108BC48910"), 0);
		if (addr==0)
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 30);
			#endif
			return 0;
		}
		GetDvarValueStrFromBuffer = (MYGETDVARVAL)addr;


		//.text:0051F220 8B 14 B5 98 10 84 05                    mov     edx, dword_5841098[esi*4]
		//.text:0051F227 57                                      push    edi
		//.text:0051F228 52                                      push    edx
		//.text:0051F229 FF D3                                   call    ebx
		//.text:0051F22B 46                                      inc     esi
		//.text:0051F22C 83 C4 08                                add     esp, 8
		//.text:0051F22F 3B 35 70 10 84 05                       cmp     esi, dword_5841070
		//.text:0051F235 7C E9                                   jl      short loc_51F220
		addr = FindHexString(V("8B14B5????????5752FFD34683C4083B35????????7C"), 0);
		DvarListPtr = *(DWORD*)(addr+3);
		DvarCountPtr = *(DWORD*)(addr+17);

		//.text:005483F0 A1 58 37 C9 01                                mov     eax, dword_1C93758
		//.text:005483F5 53                                            push    ebx
		//.text:005483F6 56                                            push    esi
		//.text:005483F7 85 C0                                         test    eax, eax
		//.text:005483F9 74 39                                         jz      short loc_548434
		//.text:005483FB 8B 74 24 0C                                   mov     esi, [esp+8+arg_0]
		//.text:005483FF 90                                            nop
		addr = FindHexString(V("A1????????535685C074??8B74240C90"), 0);
		FuncListPtr = *(DWORD*)(addr+1);

		#ifdef DEBUGGING_ENABLED
		DebugOutValue("GET_DVAR_VALUE_STR_FROM_BUFFER_PTR", (DWORD)GetDvarValueStrFromBuffer);
		DebugOutValue("DVAR_LIST_PTR", DvarListPtr);
		DebugOutValue("DVAR_COUNT_PTR", DvarCountPtr);
		DebugOutValue("FUNC_LIST_PTR", FuncListPtr);
		#endif
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 31);
		#endif
		return 0;
	}

	return 1;
}




DWORD GetDvarBuffById(int id)
{
	//safely iterate the list
	__try  
	{
		return *(DWORD*)(DvarListPtr + id*4);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 34);
		#endif
	}
	return 0;
}


DWORD GetDvarBuffByName(char * DvarName)
{
	//safely iterate the list
	__try  
	{
		int id = 0;
		int count = *(DWORD*)DvarCountPtr;
		DWORD buff = 0;

		for (int i = 0; i<count; i++)
		{
			buff = GetDvarBuffById(i);
			char * curr_name = (char *)(*(DWORD*)buff);

			if (stricmp(curr_name, DvarName) == 0)
			{
				return buff;
			}
		}

		return 0;
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 33);
		#endif
	}
	return 0;
}

char * GetDvarValueStr(char * DvarName)
{
	//validate pointers before doing anything
	if ((GetDvarValueStrFromBuffer == NULL) || (DvarCountPtr == 0) || (DvarListPtr == 0))
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 32);
		#endif
		return "";
	}
	
	DWORD buff = GetDvarBuffByName(DvarName);

	if (buff != 0)
	{
		return GetDvarValueStrFromBuffer(buff);
	}
	return "";

	//dvar dv(DvarName);

	//return dv.GetValueAsString();
}




bool GetDvarAddingFuncs()
{
	int addr = 0;
	__try  
	{
		addr = FindHexString(V("83EC108A4424188B4C2420??8B??24"), 0);
		DvarAddBool = (MYDVARADDBOOL)addr;
		addr = FindHexString(V("83EC18D94424208B442430D95C2408"), 0);
		DvarAddFloat = (MYDVARADDFLOAT)addr;		
		addr = FindHexString(V("8B5424108B44240C8B4C240883EC10"), 0);
		DvarAddInt = (MYDVARADDINT)addr;	
		addr = FindHexString(V("8B5424108B4C240883EC10??8B??24"), 0);
		DvarAddText = (MYDVARADDTEXT)addr;	

		if ((DWORD)DvarAddBool+(DWORD)DvarAddFloat+(DWORD)DvarAddInt+(DWORD)DvarAddText == 0)
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 186);
			#endif
			return 0;
		}

		#ifdef DEBUGGING_ENABLED
		DebugOutValue("GET_DVAR_ADDING_FUNC_BOOL_PTR", (DWORD)DvarAddBool);
		DebugOutValue("GET_DVAR_ADDING_FUNC_FLOAT_PTR", (DWORD)DvarAddFloat);
		DebugOutValue("GET_DVAR_ADDING_FUNC_INT_PTR", (DWORD)DvarAddInt);
		DebugOutValue("GET_DVAR_ADDING_FUNC_TEXT_PTR", (DWORD)DvarAddText);
		#endif
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 187);
		#endif
		return 0;
	}

	return 1;
}










bool GetGameMode()
{	VM("GetGameMode");

	//SP = 5C69773573702E70646200
	//MP = 5C6977356D702E70646200
	//DEDI = 5C6977356D705F7365727665725F736869702E70646200

	int addr = 0;

	FindHexString_Quiet = true;

	if (FindHexString(V("5C69773573702E70646200"), 1) != 0)
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutString("GameMode", "Singleplayer");
		#endif
		GAME_MODE = 'S';
	}
	else
	if (FindHexString(V("5C6977356D702E70646200"), 1) != 0)
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutString("GameMode", "Multiplayer");
		#endif
		GAME_MODE = 'M';
	}
	else
	if (FindHexString(V("70635C6977356D705F736572766572"), 1) != 0)
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutString("GameMode", "Multiplayer - Dedicated Server");
		#endif
		GAME_MODE = 'D';
	}
	else
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutString("GameMode", "Unknown");
		#endif
		FindHexString_Quiet = false;
		GAME_MODE = 'U';
		return 0;
	}

	FindHexString_Quiet = false;
	return 1;
	VE();
}


bool PatchVariousStuff_done = false;

bool PatchVariousStuff()
{	VU("PatchVariousStuff");

	if (PatchVariousStuff_done) return true; else PatchVariousStuff_done = true;

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		if (GAME_MODE =='M')
		{
			//.text:005F6F7E 74 3C                                         jz      short loc_5F6FBC
			//.text:005F6F80 57                                            push    edi
			//.text:005F6F81 8B BE B0 02 00 00                             mov     edi, [esi+2B0h]
			//.text:005F6F87 8D 96 20 01 00 00                             lea     edx, [esi+120h]
			//.text:005F6F8D 52                                            push    edx
			//743C578BBEB00200008D962001000052

			addr = FindHexString(V("743C578BBEB00200008D962001000052E8"), 0);

			if (addr != 0)
			{
				DWORD ptr_a = addr + 0x10 + 5 + *(DWORD*)(addr+0x11);
				info("Get protocol: ptr_a = %08X", ptr_a);

				if (ptr_a > 0x400000 && ptr_a < 0x7C0000 && *(BYTE*)ptr_a == 0xB8 && *(BYTE*)(ptr_a+5) == 0xC3)
				{
					info("Get protocol: protocol = %08X", *(DWORD*)(ptr_a+1));

					if (*(DWORD*)(ptr_a+1) > 0x4D68)
						*(DWORD*)(ptr_a+1) = 0x4D68;
				}
				else
				{
					info("Get protocol: Failed (ptr_a doesnt point at normal function)");
				}
			}
		}

		//dedicated has no crc libs
		if (GAME_MODE != 'D')
		{
			FindHexString_Quiet = true;

			addr = FindHexString(V("E8????????83C41C3B05????????0F94C384DB75"), 0);
			while (addr > 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_CRC_CHECKS_TYPE_A", addr);
				#endif
				*(DWORD*)(addr) = 0x90909090;
				*(BYTE*)(addr+4) = 0x90;
				*(DWORD*)(addr+8) = 0xF883C033;
				*(WORD*)(addr+12) = 0x9000; 
				addr = FindHexString(V("E8????????83C41C3B05????????0F94C384DB75"), addr);
			}
			#ifdef DEBUGGING_ENABLED
			DebugOutString("DISABLE_CRC_CHECKS_TYPE_A", "Search completed.");
			#endif

			addr = FindHexString(V("57E8????????83C41C3B86????????0F94C183C604"), 0);
			while (addr > 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_CRC_CHECKS_TYPE_B", addr);
				#endif
				*(DWORD*)(addr+1) = 0x90909090;
				*(BYTE*)(addr+5) = 0x90;
				*(DWORD*)(addr+9) = 0xF883C033;
				*(WORD*)(addr+13) = 0x9000;
				addr = FindHexString(V("57E8????????83C41C3B86????????0F94C183C604"), 0);
			}
			#ifdef DEBUGGING_ENABLED
			DebugOutString("DISABLE_CRC_CHECKS_TYPE_B", "Search completed.");
			#endif



			addr = FindHexString(V("81EC????0000E8????????84C07509B00181C4????0000C3"), 0);

			DWORD GUID_count = 0;
			DWORD GUID_fail = 0;

			while (addr > 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_GUID_CHECK", addr);
				#endif

				//this was crashing for many reasons
				//-> disabled
				//
				//GUID_count++;
				//MYGUIDFUNC checkGuid = (MYGUIDFUNC)addr;
				//__try  
				//{
				//	if (!checkGuid()) GUID_fail++;
				//}
				//__except ( EXCEPTION_EXECUTE_HANDLER )
				//{
				//	GUID_fail++;
				//}

				*(WORD*)(addr+13) = 0x9090;
				addr = FindHexString(V("81EC????0000E8????????84C07509B00181C4????0000C3"), 0);
			}
			#ifdef DEBUGGING_ENABLED
			info("DISABLE_GUID_CHECKS: Search completed (count:%d/failed:%d).", GUID_count, GUID_fail);
			#endif

			//if (GUID_count > 0 && GUID_fail == 0) g_SteamGUIDsFail = false;
			g_SteamGUIDsFail = false;



			addr = FindHexString(V("83EC48535556576a018d4424345033edff15"), 0);
			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_STEAM_IPCS_PTR", addr);
				#endif
				*(DWORD*)addr = 0xc340c033;
			}
			FindHexString_Quiet = false;
		}

		if (g_Patch_Getting_Data_Popup && GAME_MODE == 'M')
		{
			//.text:00456F4E 74 37                                         jz      short loc_456F87
			//.text:00456F50 8B 44 24 04                                   mov     eax, [esp+arg_0]
			//.text:00456F54 50                                            push    eax
			//.text:00456F55 E8 86 90 0B 00                                call    sub_50FFE0
			//.text:00456F5A 83 C4 04                                      add     esp, 4
			//.text:00456F5D 83 F8 01                                      cmp     eax, 1
			//.text:00456F60 74 25                                         jz      short loc_456F87
			//74378B44240450E8????????83C40483F8017425
			addr = FindHexString(V("74378B44240450E8????????83C40483F8017425"), 0);
			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_GETTING_DATA_POPUP", addr);
				#endif
				*(BYTE*)(addr+18) = 0xEB;
			}
		}

		//if (g_Patch_DW_GameSessionTask && GAME_MODE == 'D')
		//{
		//	//.text:00566350 83 EC 18                                sub     esp, 18h
		//	//.text:00566353 55                                      push    ebp
		//	//.text:00566354 8B 6C 24 20                             mov     ebp, [esp+1Ch+arg_0]
		//	//.text:00566358 69 ED 88 00 00 00                       imul    ebp, 88h
		//	//.text:0056635E 56                                      push    esi
		//	//.text:0056635F 57                                      push    edi
		//	//.text:00566360 8B BD 10 37 B0 05                       mov     edi, ss:dword_5B03710[ebp]
		//	//.text:00566366 8D 44 24 0C                             lea     eax, [esp+24h+var_18]
		//	//.text:0056636A 8D B5 90 36 B0 05                       lea     esi, unk_5B03690[ebp]
		//	//.text:00566370 50                                      push    eax
		//	//.text:00566371 C7 44 24 10 00 00 00 00                 mov     [esp+28h+var_18], 0
		//	//.text:00566379 E8 92 4D 02 00                          call    sub_58B110
		//	//.text:0056637E 83 C4 04                                add     esp, 4
		//	//.text:00566381 84 C0                                   test    al, al
		//	//83EC18558B6C242069ED8800000056578BBD????????8D44240C8DB5????????50C744241000000000E8????????83C40484C0756E
		//	addr = FindHexString("83EC18558B6C242069ED8800000056578BBD????????8D44240C8DB5????????50C744241000000000E8????????83C40484C0756E", 0);
		//	if (addr != 0)
		//	{
		//		#ifdef DEBUGGING_ENABLED
		//		DebugOutValue("DISABLE_DW_GAMESESSION_TASK", addr);
		//		#endif
		//		//*(DWORD*)(addr+1) = 0x2;
		//		//*(BYTE*)(addr) = 0xb8;
		//		//*(BYTE*)(addr+5) = 0xc3;
		//		//*(WORD*)0x00566401 = 0x9090;
		//		//*(BYTE*)0x00566383 = 0xEB;
		//		//*(BYTE*)0x005663F9 = 0xEB;
		//		//*(WORD*)0x00566460 = 0x04EB;
		//		
		//	}
		//}


		if (g_Patch_DW_ProcessFileRequest)
		{
			//.text:00430BB0 83 EC 40                                      sub     esp, 40h
			//.text:00430BB3 56                                            push    esi
			//.text:00430BB4 8B 74 24 48                                   mov     esi, [esp+44h+arg_0]
			//.text:00430BB8 83 7E 08 00                                   cmp     dword ptr [esi+8], 0
			//.text:00430BBC 75 21                                         jnz     short loc_430BDF
			//.text:00430BBE 6A 40                                         push    40h
			//.text:00430BC0 8D 44 24 08                                   lea     eax, [esp+48h+var_40]
			//.text:00430BC4 50                                            push    eax
			//.text:00430BC5 6A 04                                         push    4
			// 83EC40568B742448837E080075216A408D442408506A04 
			FindHexString_Quiet = true;
			addr = FindHexString(V("83EC40568B742448837E080075216A408D442408506A04"), 0);
			while (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_DW_PROCESS_FILE_REQUEST", addr);
				#endif
				*(DWORD*)(addr) = 0xc340c033;
				addr = FindHexString(V("83EC40568B742448837E080075216A408D442408506A04"), 0);
			}
			FindHexString_Quiet = false;
		}


		if (g_Patch_DW_STUN_Server_port_and_hosts)
		{
			//port patch
			//.text:006CBB32 B9 02 0C 00 00                                mov     ecx, 0C02h
			//.text:006CBB37 8B 95 18 FF FF FF                             mov     edx, [ebp+var_E8]
			//.text:006CBB3D 66 89 4A 14                                   mov     [edx+14h], cx
			//.text:006CBB41 C7 45 FC FF FF FF FF                          mov     [ebp+var_4], 0FFFFFFFFh
			//.text:006CBB48 8B 85 18 FF FF FF                             mov     eax, [ebp+var_E8]
			//.text:006CBB4E 8B 4D F4                                      mov     ecx, [ebp+var_C]
			//.text:006CBB51 64 89 0D 00 00 00 00                          mov     large fs:0, ecx
			// B9020C00008B9518FFFFFF66894A14C745FCFFFFFFFF8B8518FFFFFF8B4DF464890D00000000 
			addr = FindHexString(V("B9020C00008B9518FFFFFF66894A14C745FCFFFFFFFF8B8518FFFFFF8B4DF464890D00000000"), 0);
			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("SET_DW_STUN_SERVER_PORT", addr);
				#endif
				*(WORD*)(addr+1) = StunServerPort;
			}


			int hosts_section = 1;
			DWORD oldp2;
			int addr3 = 0x400000 + GetSectionPtr(hosts_section);
			VirtualProtect((void*)addr3, GetSectionSize(hosts_section), PAGE_EXECUTE_READWRITE, &oldp2);
			FindHexString_Quiet = true;
			{
				int hosts_patched = 0;
				int StunHostStr_len = strlen(V(StunServerHost)) + 1;

				//mw3-pc-auth.prod.demonware.net   6D77332D70632D617574682E70726F642E64656D6F6E776172652E6E6574
				addr = FindHexString(V("6D77332D70632D617574682E70726F642E64656D6F6E776172652E6E6574"), hosts_section);
				while (addr > 0)
				{
					memcpy((void*)addr, V(StunServerHost), StunHostStr_len);
					addr = FindHexString(V("6D77332D70632D617574682E70726F642E64656D6F6E776172652E6E6574"), hosts_section);
					hosts_patched++;
				}

				//mw3-pc-lobby.prod.demonware.net  6D77332D70632D6C6F6262792E70726F642E64656D6F6E776172652E6E6574
				addr = FindHexString(V("6D77332D70632D6C6F6262792E70726F642E64656D6F6E776172652E6E6574"), hosts_section);
				while (addr > 0)
				{
					memcpy((void*)addr, V(StunServerHost), StunHostStr_len);
					addr = FindHexString(V("6D77332D70632D6C6F6262792E70726F642E64656D6F6E776172652E6E6574"), hosts_section);
					hosts_patched++;
				}

				//mw3-stun.eu.demonware.net   6D77332D7374756E2E????2E64656D6F6E776172652E6E6574
				//mw3-stun.us.demonware.net
				addr = FindHexString(V("6D77332D7374756E2E????2E64656D6F6E776172652E6E6574"), hosts_section);
				while (addr > 0)
				{
					memcpy((void*)addr, V(StunServerHost), StunHostStr_len);
					addr = FindHexString(V("6D77332D7374756E2E????2E64656D6F6E776172652E6E6574"), hosts_section);
					hosts_patched++;
				}

				//stun.au.demonware.net 7374756E2E????2E64656D6F6E776172652E6E6574
				//stun.jp.demonware.net
				//stun.eu.demonware.net
				//stun.us.demonware.net
				addr = FindHexString(V("7374756E2E????2E64656D6F6E776172652E6E6574"), hosts_section);
				while (addr > 0)
				{
					memcpy((void*)addr, V(StunServerHost), StunHostStr_len);
					addr = FindHexString(V("7374756E2E????2E64656D6F6E776172652E6E6574"), hosts_section);
					hosts_patched++;
				}
				info("DW Stun Server host patching completed. Redirected %d hosts to '%s'.", hosts_patched, V(StunServerHost));
			}
			FindHexString_Quiet = false;
			VirtualProtect((void*)addr3, GetSectionSize(hosts_section), oldp2, &oldp2);
		}

		if (GAME_MODE == 'D' && g_Patch_Session_Info_Funcs)
		{
			//querysessioninfo
			//.text:004E5420 A1 98 DB B3 01                          mov     eax, dword_1B3DB98
			//.text:004E5425 83 EC 78                                sub     esp, 78h
			//.text:004E5428 83 3C 85 DC DB B3 01 01                 cmp     dword_1B3DBDC[eax*4], 1
			//.text:004E5430 7E 0C                                   jle     short loc_4E543E
			//.text:004E5432 8B 04 85 FC DB B3 01                    mov     eax, dword_1B3DBFC[eax*4]
			//.text:004E5439 8B 40 04                                mov     eax, [eax+4]
			//.text:004E543C EB 05                                   jmp     short loc_4E5443
			//.text:004E543E                         ; ---------------------------------------------------------------------------
			//.text:004E543E
			//.text:004E543E                         loc_4E543E:                             ; CODE XREF: sub_4E5420+10j
			//.text:004E543E B8 B0 A8 77 00                          mov     eax, offset String
			//.text:004E5443
			//.text:004E5443                         loc_4E5443:                             ; CODE XREF: sub_4E5420+1Cj
			//.text:004E5443 8D 4C 24 08                             lea     ecx, [esp+78h+var_70]
			//.text:004E5447 51                                      push    ecx
			//.text:004E5448 68 CC 98 6E 00                          push    offset aLlu_0   ; "%llu"
			//.text:004E544D 50                                      push    eax  
			//A1????????83EC78833C85????????017E0C8B0485????????8B4004EB05B8????????8D4C24085168????????50
			addr = FindHexString(V("A1????????83EC78833C85????????017E0C8B0485????????8B4004EB05B8????????8D4C24085168????????50"), 0);
			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_QUERYSESSIONINFO_FUNC", addr);
				#endif
				*(BYTE*)(addr) = 0xC3;
			}

			//replyserverinfo
			//.text:004E4480 B8 28 20 00 00                          mov     eax, 2028h
			//.text:004E4485 E8 B6 7B 14 00                          call    __alloca_probe
			//.text:004E448A A1 D0 AA B2 01                          mov     eax, dword_1B2AAD0
			//.text:004E448F 83 3C 85 14 AB B2 01 01                 cmp     dword_1B2AB14[eax*4], 1
			//.text:004E4497 7E 0C                                   jle     short loc_4E44A5
			//.text:004E4499 8B 04 85 34 AB B2 01                    mov     eax, dword_1B2AB34[eax*4]
			//.text:004E44A0 8B 40 04                                mov     eax, [eax+4]
			//.text:004E44A3 EB 05                                   jmp     short loc_4E44AA
			//.text:004E44A5                         ; ---------------------------------------------------------------------------
			//.text:004E44A5
			//.text:004E44A5                         loc_4E44A5:                             ; CODE XREF: .text:004E4497j
			//.text:004E44A5 B8 B0 A8 77 00                          mov     eax, offset String
			//.text:004E44AA
			//.text:004E44AA                         loc_4E44AA:                             ; CODE XREF: .text:004E44A3j
			//.text:004E44AA 8D 0C 24                                lea     ecx, [esp]
			//.text:004E44AD 51                                      push    ecx
			//.text:004E44AE 68 CC 98 6E 00                          push    offset aLlu_0   ; "%llu"
			//.text:004E44B3 50                                      push    eax
			//B828200000E8????????A1????????833C85????????017E0C8B0485????????8B4004EB05B8????????8D0C245168????????50
			addr = FindHexString(V("B828200000E8????????A1????????833C85????????017E0C8B0485????????8B4004EB05B8????????8D0C245168????????50"), 0);
			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DISABLE_REPLYSERVERINFO_FUNC", addr);
				#endif
				*(BYTE*)(addr) = 0xC3;
			}
		}


		if (g_Set_Ranked_Games)
		{
			if (GAME_MODE == 'D')
			{
				//.text:004E51B0 A1 04 96 90 05                          mov     eax, xblive_privatematch
				//.text:004E51B5 6A 01                                   push    1
				//.text:004E51B7 50                                      push    eax
				//.text:004E51B8 89 35 BC 4F F4 01                       mov     dword_1F44FBC, esi
				//.text:004E51BE E8 CD 92 03 00                          call    SetDvarBool
				//.text:004E51C3 8D 4C 24 20                             lea     ecx, [esp+60h+var_40]
				//.text:004E51C7 51                                      push    ecx
				//.text:004E51C8 E8 B3 C1 02 00                          call    sub_511380
				//.text:004E51CD 0F B6 54 24 68                          movzx   edx, [esp+64h+arg_0]
				//.text:004E51D2 6A 00                                   push    0
				// A1????????6A05508935????????E8????????8D4C242051E8????????0FB65424686A00    
				addr = FindHexString(V("A1????????6A??508935????????E8????????8D4C242051E8????????0FB65424686A00"), 0);
				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("SET_RANKED_GAMES_D", addr);
					#endif
					*(BYTE*)(addr+6) = 0;
				}
			}


			if (GAME_MODE == 'M')
			{
				//when server is dedicated, client automatically assumes private match, disabling custom classes at the same time
				//.text:005B2100 83 7A 0C 00                                   cmp     dword ptr [edx+0Ch], 0
				//.text:005B2104 74 31                                         jz      short loc_5B2137
				//.text:005B2106 A1 58 8A A6 05                                mov     eax, xblive_privatematc
				//.text:005B210B 6A 01                                         push    1
				//.text:005B210D 50                                            push    eax
				//.text:005B210E E8 6D 22 F3 FF                                call    sub_4E4380
				//.text:005B2113 8B 0D D4 D0 05 01                             mov     ecx, onlinegame
				//.text:005B2119 6A 01                                         push    1
				//.text:005B211B 51                                            push    ecx
				//.text:005B211C E8 5F 22 F3 FF                                call    sub_4E4380
				//.text:005B2121 6A 08                                         push    8
				//837A0C007431A1????????6A0150E8????????8B0D????????6A0151E8????????6A08
				addr = FindHexString(V("837A0C007431A1????????6A0150E8????????8B0D????????6A0151E8????????6A08"), 0);
				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("SET_RANKED_GAMES_M", addr);
					#endif
					*(BYTE*)(addr+12) = 0;
				}


				FindHexString_Quiet = true;
				//these three will prevent the UI from reading the game mode name from playlist, instead turn g_gamemode to a proper name.
				//.text:0062A59D 80 78 0C 00                                   cmp     byte ptr [eax+0Ch], 0
				//.text:0062A5A1 74 2F                                         jz      short loc_62A5D2
				//.text:0062A5A3 8B 0D 58 8A A6 05                             mov     ecx, xblive_privatematc
				//.text:0062A5A9 80 79 0C 00                                   cmp     byte ptr [ecx+0Ch], 0
				//.text:0062A5AD 75 23                                         jnz     short loc_62A5D2
				//.text:0062A5AF
				//.text:0062A5AF                               loc_62A5AF:                             ; CODE XREF: sub_62A580+6Cj
				//.text:0062A5AF E8 8C A8 EF FF                                call    playlist_func_1
				//.text:0062A5B4 50                                            push    eax
				//.text:0062A5B5 E8 E6 F9 EB FF                                call    sub_4E9FA0
				//.text:0062A5BA 83 C4 04                                      add     esp, 4
				//.text:0062A5BD 50                                            push    eax
				//.text:0062A5BE 56                                            push    esi
				//80780C00742F8B0D????????80790C007523E8????????50E8????????83C4045056
				addr = FindHexString(V("80780C00742F8B0D????????80790C007523E8????????50E8????????83C4045056"), 0);
				while (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("SET_PROPER_GAME_MODE_NAME_A", addr);
					#endif
					*(WORD*)(addr+18) = 0x21EB;
					addr = FindHexString(V("80780C00742F8B0D????????80790C007523E8????????50E8????????83C4045056"), 0);
				}
				//.text:0062A657 80 78 0C 00                                   cmp     byte ptr [eax+0Ch], 0
				//.text:0062A65B 74 30                                         jz      short loc_62A68D
				//.text:0062A65D 8B 0D 58 8A A6 05                             mov     ecx, xblive_privatematc
				//.text:0062A663 80 79 0C 00                                   cmp     byte ptr [ecx+0Ch], 0
				//.text:0062A667 75 24                                         jnz     short loc_62A68D
				//.text:0062A669
				//.text:0062A669                               loc_62A669:                             ; CODE XREF: sub_62A620+87j
				//.text:0062A669 56                                            push    esi
				//.text:0062A66A E8 D1 A7 EF FF                                call    playlist_func_1
				//.text:0062A66F 50                                            push    eax
				//.text:0062A670 E8 4B 31 F0 FF                                call    playlist_func_2
				//.text:0062A675 83 C4 08                                      add     esp, 8
				//.text:0062A678 50                                            push    eax
				//.text:0062A679 57                                            push    edi
				//80780C0074308B0D????????80790C00752456E8????????50E8????????83C4085057
				addr = FindHexString(V("80780C0074308B0D????????80790C00752456E8????????50E8????????83C4085057"), 0);
				while (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("SET_PROPER_GAME_MODE_NAME_B", addr);
					#endif
					*(WORD*)(addr+18) = 0x22EB;
					addr = FindHexString(V("80780C0074308B0D????????80790C00752456E8????????50E8????????83C4085057"), 0);
				}
				//.text:0062A836 74 21                                         jz      short loc_62A859
				//.text:0062A838 A1 58 8A A6 05                                mov     eax, xblive_privatematc
				//.text:0062A83D 80 78 0C 00                                   cmp     byte ptr [eax+0Ch], 0
				//.text:0062A841 75 16                                         jnz     short loc_62A859
				//.text:0062A843 E8 F8 A5 EF FF                                call    playlist_func_1
				//.text:0062A848 50                                            push    eax
				//.text:0062A849 E8 52 F7 EB FF                                call    sub_4E9FA0
				//.text:0062A84E 50                                            push    eax
				//.text:0062A84F E8 AC 1C E5 FF                                call    sub_47C500
				//.text:0062A854 83 C4 08                                      add     esp, 8
				//.text:0062A857 EB 05                                         jmp     short loc_62A85E
				//7421A1????????80780C007516E8????????50????????50????????83C408EB05 
				addr = FindHexString(V("7421A1????????80780C007516E8????????50E8????????50E8????????83C408EB05"), 0);
				while (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("SET_PROPER_GAME_MODE_NAME_C", addr);
					#endif
					*(BYTE*)(addr+11) = 0xEB;
					addr = FindHexString(V("7421A1????????80780C007516E8????????50E8????????50E8????????83C408EB05"), 0);
				}
				FindHexString_Quiet = false;
			}

		}



		if (g_Patch_DW_ConnectionStatus)
		{
			//Function that fetches some value from DW buffer (should get 2)
			//	     55             PUSH EBP
			//006F2221     8BEC           MOV EBP,ESP
			//006F2223     83EC 08        SUB ESP,8
			//006F2226     894D F8        MOV DWORD PTR SS:[EBP-8],ECX
			//006F2229  |. 8B45 F8        MOV EAX,DWORD PTR SS:[EBP-8]
			//006F222C  |. 33C9           XOR ECX,ECX
			//006F222E  |. 8378 78 00     CMP DWORD PTR DS:[EAX+78],0
			//558BEC83EC08894DF88B45F833C983787800
			addr = FindHexString(V("558BEC83EC08894DF88B45F833C9837878000F94C10FB6D185D27404"), 0);

			if (addr != 0)
			{
				#ifdef DEBUGGING_ENABLED
				DebugOutValue("DW_BUFFER_FETCH_CHECK", addr);
				#endif
				*(BYTE*)addr = 0xB8;
				*(DWORD*)(addr+1) = 0x2;
				*(BYTE*)(addr+5) = 0xC3;
			}

			if (GAME_MODE == 'D')
			{
				//Function that sets DW cnnection status (SERVER EXE) (should set 9)
				//.text:00585970 83 EC 64                                sub     esp, 64h
				//.text:00585973 55                                      push    ebp
				//.text:00585974 56                                      push    esi
				//.text:00585975 8B 35 68 9B B7 05                       mov     esi, dword_5B79B68
				//.text:0058597B 57                                      push    edi
				//.text:0058597C 8D 4C 24 0C                             lea     ecx, [esp+70h+var_64]
				//.text:00585980 E8 3B 48 06 00                          call    sub_5EA1C0
				//.text:00585985 33 ED                                   xor     ebp, ebp
				//.text:00585987 8D 46 FF                                lea     eax, [esi-1]
				// 83EC6455568B35????????578D4C240CE8????????33ED8D46FF
				addr = FindHexString(V("83EC6455568B35????????578D4C240CE8????????33ED8D46FF"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DW_CONNECTION_STATUS_FUNC", addr);
					#endif
					*(WORD*)addr = 0x05C7;
					*(DWORD*)(addr+2) = *(DWORD*)(addr+7);
					*(DWORD*)(addr+6) = 9;
					*(BYTE*)(addr+10) = 0xC3;
				}
			}
			else
			{
				//Function that sets DW cnnection status (MP EXE) (should set 8)
				//0049AF50     81EC 10040000  SUB ESP,410
				//0049AF56     53             PUSH EBX
				//0049AF57     56             PUSH ESI
				//0049AF58     8B35 30A1CB05  MOV ESI,DWORD PTR DS:[5CBA130]  --- status buffer
				//0049AF5E     57             PUSH EDI
				//0049AF5F     8D4C24 10      LEA ECX,DWORD PTR SS:[ESP+10]
				//0049AF63     E8 C8DB2400    CALL iw5mp.006E8B30
				//0049AF68     33DB           XOR EBX,EBX                              ;  Switch (cases 1..7)
				//0049AF6A  |. 8D46 FF        LEA EAX,DWORD PTR DS:[ESI-1]
				//81EC1004000053568B35????????578D4C2410E8????????33DB8D46FF
				addr = FindHexString(V("81EC1004000053568B35????????578D4C2410E8????????33DB8D46FF"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DW_CONNECTION_STATUS_FUNC", addr);
					#endif
					*(WORD*)addr = 0x05C7;
					*(DWORD*)(addr+2) = *(DWORD*)(addr+10);
					*(DWORD*)(addr+6) = 8;
					*(BYTE*)(addr+10) = 0xC3;
				}
			}
		}


		if (GAME_MODE == 'D')
		{
			if (g_Patch_Task_server_Crash)
			{
				//.text:004A0D3E C7 05 6C 3C B0 01 03 00 00 00                 mov     dword_1B03C6C, 3
				//.text:004A0D48 C7 05 D4 23 B0 01 00 00 00 00                 mov     dword_1B023D4, 0
				//.text:004A0D52 E8 E9 D3 03 00                                call    sub_4DE140
				//.text:004A0D57 85 C0                                         test    eax, eax
				//.text:004A0D59 74 0F                                         jz      short loc_4A0D6A
				//.text:004A0D5B 6A 00                                         push    0
				//.text:004A0D5D E8 DE C9 03 00                                call    sub_4DD740
				//.text:004A0D62 83 C4 04                                      add     esp, 4
				//.text:004A0D65 A3 D4 23 B0 01                                mov     dword_1B023D4, eax
				//.text:004A0D6A
				//.text:004A0D6A                               loc_4A0D6A:                             ; CODE XREF: sub_4A0D30+29j
				//.text:004A0D6A E8 D1 BE 04 00                                call    Server_quit
				//.text:004A0D6F E9 5C 9A FE FF                                jmp     sub_48A7D0
				//C705????????03000000C705????????00000000E8????????85C0740F6A00E8????????83C404A3????????E8????????E9
				addr = FindHexString(V("C705????????03000000C705????????00000000E8????????85C0740F6A00E8????????83C404A3????????E8????????E9"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("PATCH_MAP_ROTATE_SERVER_SHUTDOWN", addr);
					#endif
					*(WORD*)(addr+44) = 0x03EB;
				}

				//.text:0056644B 8B 7F 04                                      mov     edi, [edi+4]
				//.text:0056644E 8D 57 2A                                      lea     edx, [edi+2Ah]
				//.text:00566451 52                                            push    edx
				//.text:00566452 83 C7 09                                      add     edi, 9
				//.text:00566455 57                                            push    edi
				//.text:00566456 E8 A5 18 00 00                                call    sub_567D00
				//.text:0056645B 83 C4 10                                      add     esp, 10h
				//.text:0056645E 84 C0                                         test    al, al
				//.text:00566460 0F 84 1F FF FF FF                             jz      loc_566385
				//8B7F048D572A5283C70957E8????????83C41084C00F841FFFFFFF
				addr = FindHexString(V("8B7F048D572A5283C70957E8????????83C41084C00F84??FFFFFF"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("PATCH_DW_REGISTER_KEY", addr);
					#endif
					*(DWORD*)(addr+19) = 0xEB40c033;
					*(BYTE*)(addr+23) = 0x03;
				}
			}

			   

			if (g_Patch_Unauthorized_IP)
			{
				//.text:004E5D2A 83 C4 18                                add     esp, 18h
				//.text:004E5D2D 85 C0                                   test    eax, eax
				//.text:004E5D2F 75 61                                   jnz     short loc_4E5D92
				//.text:004E5D31 68 D4 57 6F 00                          push    offset aErrorExe_err_u ; "error\nEXE_ERR_UNAUTHORIZED_IP"
				//.text:004E5D36
				//.text:004E5D36                         loc_4E5D36:                             ; CODE XREF: sub_4E5B20+280j
				//.text:004E5D36                                                                 ; sub_4E5B20+292j
				//.text:004E5D36 8D 34 ED 00 00 00 00                    lea     esi, ds:0[ebp*8]
				//.text:004E5D3D 2B F5                                   sub     esi, ebp
				//83C41885C075??68??????008D34ED000000002BF5

				addr = FindHexString(V("83C41885C075??68??????008D34ED000000002BF5"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DISABLE_UNAUTHORIZED_IP_CHECK", addr);
					#endif
					*(BYTE*)(addr+5) = 0xEB;
				}
			}

			if (g_Patch_Unregistered_Connection)
			{
				//.text:004E5CCC 8B 44 24 24                             mov     eax, [esp+3Ch+var_18]
				//.text:004E5CD0 8D 4C 24 1C                             lea     ecx, [esp+3Ch+var_20]
				//.text:004E5CD4 51                                      push    ecx
				//.text:004E5CD5 52                                      push    edx
				//.text:004E5CD6 50                                      push    eax
				//.text:004E5CD7 E8 94 E6 03 00                          call    sub_524370
				//.text:004E5CDC 83 C4 10                                add     esp, 10h
				//.text:004E5CDF 84 C0                                   test    al, al
				//.text:004E5CE1 0F 84 3C 01 00 00                       jz      loc_4E5E23
				// 8B4424248D4C241C515250E8????????83C41084C00F84

				addr = FindHexString(V("8B4424248D4C241C515250E8????????83C41084C00F84"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DISABLE_UNREGISTERED_CONNECTION_CHECK", addr);
					#endif
					*(WORD*)(addr+21) = 0x04EB;
				}
			}


			if (g_Patch_HostAndClient_On_Same_Local_IP_Fail)
			{
				//.text:005DE7B6 3B F0                                   cmp     esi, eax
				//.text:005DE7B8 0F 85 4B 01 00 00                       jnz     loc_5DE909
				//.text:005DE7BE 8B 45 08                                mov     eax, [ebp+arg_0]
				//.text:005DE7C1 50                                      push    eax
				//.text:005DE7C2 8D 8D 2C FA FF FF                       lea     ecx, [ebp+var_5D4]
				//.text:005DE7C8 E8 D3 BC 00 00                          call    sub_5EA4A0
				//.text:005DE7CD C7 45 FC 03 00 00 00                    mov     [ebp+var_4], 3
				//.text:005DE7D4 6A 0C                                   push    0Ch
				//3BF00F85??0100008B4508508D8D2CFAFFFFE8????????C745FC030000006A0C 

				addr = FindHexString(V("3BF00F85??0100008B4508508D8D2CFAFFFFE8????????C745FC030000006A0C"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DISABLE_HOST_AND_CLIENT_ON_SAME_LOCAL_IP_FAIL", addr);
					#endif
					*(WORD*)(addr+2) = 0x04EB;
				}
			}

			if (g_Patch_SteamAuthFail_clientDrop)
			{
				//.text:0058306D 80 7E FF 00                             cmp     byte ptr [esi-1], 0
				//.text:00583071 0F 85 86 00 00 00                       jnz     loc_5830FD
				//.text:00583077 FE 06                                   inc     byte ptr [esi]
				//.text:00583079 80 3E 04                                cmp     byte ptr [esi], 4
				//.text:0058307C 75 1B                                   jnz     short loc_583099
				//.text:0058307E 57                                      push    edi
				//807EFF000F85??000000FE06803E04751B57 

				addr = FindHexString(V("807EFF000F85??000000FE06803E04751B57"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DISABLE_STEAM_AUTH_FAIL_CLIENT_DROP", addr);
					#endif
					*(BYTE*)(addr+15) = 0xEB;
				}
			}
		}
		
		if (GAME_MODE == 'M')
		{


			//these patches enable the original stat file saving/loading
			//however they do not make it so custom classes get saved
			//*(WORD*)(0x006125FE) = 0x9090;
			//*(WORD*)(0x0061260A) = 0x9090;
			////*(BYTE*)(0x0061259B) = 0x90;
			////*(BYTE*)(0x006125A1) = 0x90;
			//*(BYTE*)(0x00612591) = 0xEB;
			//*(WORD*)(0x00457604) = 0x18EB;
			//*(WORD*)(0x00457635) = 0xC032;
			//*(BYTE*)(0x00450FCB) = 0xEB;


			
			{
				//.text:006CDA27 B9 02 0C 00 00                                mov     ecx, 0C02h
				//.text:006CDA2C 8B 95 18 FF FF FF                             mov     edx, [ebp+var_E8]
				//.text:006CDA32 66 89 4A 02                                   mov     [edx+2], cx
				//.text:006CDA36 8B 85 18 FF FF FF                             mov     eax, [ebp+var_E8]
				//.text:006CDA3C C7 40 04 00 00 00 00                          mov     dword ptr [eax+4], 0
				//B9020C00008B9518FFFFFF66894A028B8518FFFFFFC7400400000000

				addr = FindHexString(V("B9020C00008B9518FFFFFF66894A028B8518FFFFFFC7400400000000"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("RANDOMIZE_CLIENT_PORT_LOC", addr);
					#endif

					*(WORD*)(addr+1) = 29000 + (GetCurrentProcessId() & 0xFFF);
				}
			}




			if (g_Patch_Content_server_init)
			{
				//.text:004B7320 56                                            push    esi
				//.text:004B7321 8B 74 24 08                                   mov     esi, [esp+4+arg_0]
				//.text:004B7325 F6 04 B5 E4 ED 8A 00 04                       test    byte ptr dword_8AEDE4[esi*4], 4
				//.text:004B732D 0F 85 86 00 00 00                             jnz     loc_4B73B9
				//.text:004B7333 57                                            push    edi             ; char
				//.text:004B7334 56                                            push    esi
				//.text:004B7335 E8 D6 E2 F9 FF                                call    sub_455610
				//.text:004B733A 8B F8                                         mov     edi, eax
				//.text:004B733C 83 C4 04                                      add     esp, 4
				//568B742408F604B5??????00040F85??0000005756E8????????8BF883C404
				addr = FindHexString(V("568B742408F604B5??????00040F85??0000005756E8????????8BF883C404"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DISABLE_CONTENT_SERVER_INIT_FAIL", addr);
					#endif
					//C605 ???????? 04     MOV BYTE PTR DS:[????????],4
					//33C0                 xor eax, eax
					//C3                   ret

					*(WORD*)(addr) = 0x05C6;
					*(DWORD*)(addr+2) = *(DWORD*)(addr+8);
					*(DWORD*)(addr+6) = 0xc3c03304;
				}
			}


			if (g_Patch_Task_matchmaking_search)
			{
				//.text:004458B0 8B 4C 24 14                                   mov     ecx, [esp+arg_10]
				//.text:004458B4 8B 44 24 0C                                   mov     eax, [esp+arg_8]
				//.text:004458B8 8B 54 24 10                                   mov     edx, [esp+arg_C]
				//.text:004458BC 53                                            push    ebx
				//.text:004458BD 8B 5C 24 0C                                   mov     ebx, [esp+4+arg_4]
				//.text:004458C1 56                                            push    esi
				//.text:004458C2 8B 74 24 0C                                   mov     esi, [esp+8+arg_0]
				//.text:004458C6 6A 00                                         push    0
				//.text:004458C8 51                                            push    ecx
				//.text:004458C9 6A 00                                         push    0
				//.text:004458CB 52                                            push    edx
				//.text:004458CC 50                                            push    eax
				//.text:004458CD A8 08                                         test    al, 8
				//8B4C24148B44240C8B542410538B5C240C568B74240C6A00516A005250A808
				addr = FindHexString(V("8B4C24148B44240C8B542410538B5C240C568B74240C6A00516A005250A808"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DISABLE_MATCHMAKING_SEARCH_TASK", addr);
					#endif
					*(BYTE*)(addr) = 0xC3;
				}
			}

			if (g_Patch_Modded_Files_Check)
			{
				//.text:0054A4D7 83 3D EC 15 99 05 00                          cmp     dword_59915EC, 0
				//.text:0054A4DE 5E                                            pop     esi
				//.text:0054A4DF 75 0F                                         jnz     short loc_54A4F0
				//.text:0054A4E1 68 54 83 80 00                                push    offset byte_808354 ; char *
				//.text:0054A4E6 6A 01                                         push    1               ; int
				//.text:0054A4E8 E8 E3 D6 FF FF                                call    sub_547BD0
				//.text:0054A4ED 83 C4 08                                      add     esp, 8
				//.text:0054A4F0
				//.text:0054A4F0                               loc_54A4F0:                             ; CODE XREF: sub_54A3C0+46j
				//.text:0054A4F0                                                                       ; sub_54A3C0+11Fj
				//.text:0054A4F0 8D 4C 24 0C                                   lea     ecx, [esp+1Ch+var_10]
				//833D????????005E750F68????????6A01E8????????83C4088D4C240C
				addr = FindHexString(V("833D????????005E750F68????????6A01E8????????83C4088D4C240C"), 0);

				if (addr != 0)
				{
					#ifdef DEBUGGING_ENABLED
					DebugOutValue("DISABLE_MOD_FILES_CHECK", addr);
					#endif
					*(BYTE*)(addr+8) = 0xEB;
				}
			}
		}

		

		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 12);
		#endif
		return 0;
	}

	return 1;
	VE();
}



bool GetServerInfo(char * ipport, char * destBuffer, DWORD buffer_size)
{	VM("GetServerInfo_sb");
	
	memset(destBuffer, 0, buffer_size);

	ServerList* pList = ServerList::getInstance();
	if (pList == NULL)
	{
		info("ERROR: Unable to get ServerList instance!");
		return 0;
	}

	char *server = ipport;
	DWORD ip = 0;
	USHORT port = 0;

	if (parseIpPort(server, &ip, &port))
	{
		ServerItem * item = pList->getServerItemByAddress(htonl(ip), port);
		if (item == NULL)
		{
			return false;
		}

		info("infos = %s", item->getServerInfos());


		sprintf_s(destBuffer, buffer_size, "%s",  item->getServerInfos());


		//g_gametype\war
		//g_hardcore\0
		//gamename\IW5
		//mapname\mp_village
		//protocol\101
		//scr_game_allowkillcam\1
		//scr_team_fftype\0
		//shortversion\1.4
		//sv_allowClientConsole\0
		//sv_floodProtect\1
		//sv_hostname\Modern Warfare 3
		//sv_maxclients\16
		//sv_privateClients\0
		//sv_privateClientsForClients\0
		//sv_pure\1
		//sv_voice\Team Chat
		//challenge\76561197993898380
		//pswrd\0
		//mod\0
		//


		return true;
	}
	else
	{
		info("ERROR: Invalid server ip:port");
		return false;
	}



	VE();
}


typedef DWORD (__cdecl *GETSERVERINFO)(char * ipport, char* outbuffer, DWORD outbuffer_size);
DWORD __cdecl myGetServerInfo(DWORD caller, GETSERVERINFO tramp, char * ipport, char* outbuffer, DWORD outbuffer_size)
{	VM("myGetServerInfo");

	///DWORD ret = tramp(ipport, outbuffer, outbuffer_size);

	//info("GetServerInfo('%s', '%s', %d) = %08X", ipport, outbuffer, outbuffer_size, ret);

	if (outbuffer_size == 0x400)
	{
		if (GetServerInfo(ipport, outbuffer, outbuffer_size))
		{
			return 1;
		}
	}

	return 0;

	VE();
}

bool HookGetServerInfo()
{	VM("HookGetServerInfo");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		/*
		.text:004244B0 8B 44 24 04                                   mov     eax, [esp+arg_0]
		.text:004244B4 83 EC 08                                      sub     esp, 8
		.text:004244B7 53                                            push    ebx
		.text:004244B8 55                                            push    ebp
		.text:004244B9 33 DB                                         xor     ebx, ebx
		.text:004244BB 56                                            push    esi
		.text:004244BC 57                                            push    edi
		.text:004244BD 3B C3                                         cmp     eax, ebx
		.text:004244BF 75 30  */
		//8B44240483EC08535533DB56573BC37530
		addr = FindHexString(V("8B44240483EC08535533DB56573BC37530"), 0);
		
		if (addr > 14)
		{
			hook_cdecl((void*)(addr), myGetServerInfo);
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 73);
			#endif
			return 0;
		}

		#ifdef DEBUGGING_ENABLED
		DebugOutValue("GET_SERVER_INFO_FUNC_PTR", addr);
		#endif

		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 74);
		#endif
		return 0;
	}

	return 1;

	VE();
}








void FillServerInfo_Stub(char* outbuf) 
{	VM("FillServerInfo_Stub");

	char secondary[200];
	sprintf(secondary, V("sv_allowClientConsole\\%d\\sv_floodProtect\\%d\\sv_maxclients\\%d\\sv_privateClients\\%d\\sv_privateClientsForClients\\%d\\"), 0, 1, 16, 0, 0);

	sprintf(outbuf, V("\\g_gametype\\%s\\g_hardcore\\%d\\gamename\\IW5\\mapname\\%s\\protocol\\%d\\scr_game_allowkillcam\\%d\\scr_team_fftype\\%d\\shortversion\\%s\\challenge\\%s\\pswrd\\%d\\mod\\%d\\sv_hostname\\%s\\sv_voice\\%s\\sv_pure\\%d\\%s\\"), V("war"), 0, V("mp_village"), 101, 1, 0, V("1.4"), V("01234567890123456789"), 0, 0, V("Not Implemented Yet :("), V("Scream across the room"), 1, secondary );

	VE();
}






bool GetFillServerInfo()
{	VM("GetFillServerInfo");

	int addr = 0;
	__try  
	{
		DWORD oldp;
		int addr2 = 0x400000 + GetSectionPtr(0);
		VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);

		//.text:004EB3F0 B8 14 24 00 00                                mov     eax, 2414h
		//.text:004EB3F5 E8 46 0C 14 00                                call    __alloca_probe
		//.text:004EB3FA 55                                            push    ebp
		//.text:004EB3FB 56                                            push    esi
		//.text:004EB3FC 57                                            push    edi
		//.text:004EB3FD 68 00 00 02 00                                push    20000h
		//.text:004EB402 8D 4C 24 1C                                   lea     ecx, [esp+2424h+var_2408]
		//.text:004EB406 E8 65 BF 02 00                                call    sub_517370
		//.text:004EB40B 8D 4C 24 18                                   lea     ecx, [esp+2420h+var_2408]
		//.text:004EB40F E8 DC BF 02 00                                call    sub_5173F0
		//.text:004EB414 68 00 20 00 00                                push    2000h
		//.text:004EB419 33 ED                                         xor     ebp, ebp
		//B814240000E8????????55565768000002008D4C241CE8????????8D4C2418E8????????6800200000 
		addr = FindHexString(V("B814240000E8????????55565768000002008D4C241CE8????????8D4C2418E8????????6800200000"), 0);
		
		if (addr > 14)
		{
			FillServerInfo = (MYFILLSERVERINFO)addr;
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			DebugOutValue("Error", 83);
			#endif
			return 0;
		}

		#ifdef DEBUGGING_ENABLED
		DebugOutValue("FILL_SERVER_INFO_FUNC_PTR", addr);
		#endif

		VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 84);
		#endif
		return 0;
	}

	return 1;

	VE();
}








typedef BOOL (__stdcall *GETMESSAGE)(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL __stdcall myGetMessage( GETMESSAGE tramp, LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax )
{
	BOOL retVal = tramp(lpMsg, hWnd, wMsgFilterMin, wMsgFilterMax);

	if( lpMsg->message == WM_KEYDOWN )
	{
		ExecHotkey(lpMsg->wParam);
	}

	return retVal;
}


bool HookKeyboard()
{	VU("HookKeyboard");

	return hook((void *)GetMessageA, myGetMessage);

	VE();
}


#pragma optimize("", on)