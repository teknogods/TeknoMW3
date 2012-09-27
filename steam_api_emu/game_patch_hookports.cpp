#include "stdafx.h"
//#include "SDK\SteamclientAPI.h"
//#include "SDK\SteamAPI.h"
#include "game_patch_base.h"
#include "game_admin_base.h"
//#include "game_hotkey_base.h"
//#include "game_dvar_base.h"
//#include "game_server_items.h"
//#include "VMProtectSDK.h"
//#include "steam_api_emu.h"
//#include "steam_api_emu_misc.h"
//#include "dw_stun_server.h"
//#include "dw_online_files.h"
//#include "util.h"
//#include "util_adv_log.h"
//#include "util_codehook.h"
//#include "util_ini.h"
//#include <sys/stat.h>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;

#pragma optimize("", off)

//
// This is an example item that's hooked in a way v1.5 will require.
// regs are saved, needed params re-ordered and a "standard" hook proc which is used by 1.4
// called in a way "myGetBanStatus" would understand.
// The original func that I hooked here took param in the eax variable.
//

void __declspec(naked) myGetBanStatus_asm_port14()
{
	__asm
	{
		pushfd
		pushad

		call [esp+0x28] //call the original func

		lea	ebp, [esp+0x44]
		
		push [ebp]		//ip
		push [ebp+4]	//port
		push [ebp+8]	//steamID low
		push [ebp+0xC]	//steamID high
		lea  ebp, [ebp+0x10]
		push ebp		//challenge / hwid
		push eax		//steamID ban status from permanent.ban file
		call myGetBanStatus
		//save result to pushaded eax
		mov [esp+0x1c], eax
		popad
		popfd
		retn 4 //4 because there is an address to the original func pushed by the hook code
	}
}



#pragma optimize("", on)