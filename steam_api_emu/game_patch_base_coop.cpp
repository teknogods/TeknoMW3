#include "stdafx.h"
#include "game_patch_base_coop.h"
#include "game_patch_base.h"
#include "util.h"
#include "VMProtectSDK.h"
DWORD stackspot1;
DWORD stackspot2;
DWORD stackspot3;
char commands[256];
char myip[256];
DWORD cmdlinedw;
DWORD spot;
//DWORD videoloc;
//DWORD binkhook;
char *fovptr;
char newfov[32];
DWORD pausevar1;
DWORD pausevar2;
DWORD fovfuncloc1;
DWORD fovfuncloc2;
DWORD g = 1;
#pragma optimize("", off)
bool PatchMW3Coop()
{	VU("PatchMW3Coop");

	DWORD oldp;
	char location[256];

	int addr2 = 0x400000 + GetSectionPtr(0);
	VirtualProtect((void*)addr2, GetSectionSize(0), PAGE_EXECUTE_READWRITE, &oldp);
	//MessageBoxA(0,newfov,"",0);
	//binkhook = FindHexString(V("68000100008D54241068"), 0);
	DWORD netfix1 = FindHexString(V("750B8B3D????????E9"), 0);
	DWORD netfix2 = FindHexString(V("3B3D????????75116A1EE8"), 0) + 6;
	DWORD netfix3 = FindHexString(V("83FF0175??8B8680000000"), 0) + 3;
	DWORD netfix4 = FindHexString(V("837C2410000F84??00000033DB"), 0) + 5;
	DWORD lobbyfix1 = FindHexString(V("84C0751A8B4C2410"), 0) + 2;
	DWORD lobbyfix2 = FindHexString(V("8BCEE8????????84C07416FF15"), 0) + 9;
	DWORD lobbyfix3 = FindHexString(V("8BF139107561"), 0) + 4;
	DWORD lobbyfix4 = FindHexString(V("381D????????756E"), 0) + 6;
	DWORD netport1 = FindHexString(V("6A006888690000"), 0) + 3;
	DWORD netport2 = FindHexString(V("6A006888690000"), netport1) + 3;
	DWORD netport3 = FindHexString(V("6A006888690000"), netport2) + 3;
	DWORD joinfix = FindHexString(V("83C40884C0751A8B4C2404"), 0) + 5;
	DWORD xlivefix = FindHexString(V("83C41485C0741CA1"), 0) + 5;
	cmdlinedw = FindHexString(V("CC6A1FE8????????8B44240C"), 0) + 1;
	DWORD stackfix1 = FindHexString(V("83EC386801400100"), 0);
	DWORD stackfix2 = FindHexString(V("83EC406800400000"), 0);
	DWORD stackfix3 = FindHexString(V("8B44240881EC1C090000"), 0);
	DWORD MPSTR = FindHexString(V("73746172744D756C7469706C6179657200000000"),1);
	DWORD netfix5 = FindHexString(V("7FED8B44240C"),0);
	DWORD fovvar1 = FindHexString(V("741CA1????????6A00"),0) + 3;
	DWORD fovvar2 = FindHexString(V("74298B15????????6A00"),0) + 4;

	if(netfix1 < 0x401000 ||
		netfix2 < 0x401000 || 
		netfix3 < 0x401000 || 
		netfix4 < 0x401000 || 
		netfix5 < 0x401000 || 
		lobbyfix1 < 0x401000 ||
		lobbyfix2 < 0x401000 ||
		lobbyfix3 < 0x401000 ||
		lobbyfix4 < 0x401000 ||
		netport1 < 0x401000 ||
		netport3 < 0x401000 ||
		netport2 < 0x401000 ||
		joinfix < 0x401000 ||
		xlivefix < 0x401000 ||
		cmdlinedw < 0x401000 ||
		stackfix1 < 0x401000 ||
		stackfix2 < 0x401000 ||
		stackfix3 < 0x401000 ||
		fovvar1 < 0x401000 ||
		fovvar2 < 0x401000 ||
		MPSTR < 0x401000)
	{
		return false;
	}

	if (g_NewFov == 0)
	{
		sprintf(newfov, V("cg_fov %d"), 65);
	}
	else
	{
		sprintf(newfov, V("cg_fov %d"), g_NewFov);
	}

	fovptr = &newfov[0];

	pausevar1 = *(DWORD *)fovvar1;
	pausevar2 = *(DWORD *)fovvar2;
	fovvar1--;
	fovvar2 -= 2;
	fovfuncloc1 = fovvar1+5;
	fovfuncloc2 = fovvar2+6;

	DWORD fovfunc1 = (DWORD)fovhook1;
	DWORD fovdw1 = (fovfunc1 - fovvar1) - 5;
	*(BYTE *)fovvar1 = 0xE9;
	fovvar1++;
	*(DWORD *)fovvar1 = fovdw1;
	fovvar1--;

	DWORD fovfunc2 = (DWORD)fovhook2;
	DWORD fovdw2 = (fovfunc2 - fovvar2) - 5;
	*(BYTE *)fovvar2 = 0xE9;
	fovvar2++;
	*(DWORD *)fovvar2 = fovdw2;
	fovvar2--;

	//videoloc = *(DWORD*)(binkhook + 10);
	//DWORD binkfunc = (DWORD)GetProcAddress(GetModuleHandleA(V("steam_api.dll")), V("xx4"));
	//DWORD jumpdw4 = (binkfunc - binkhook) - 5;
	//*(BYTE *)binkhook = 0xE9;
	//binkhook++;
	//*(DWORD *)binkhook = jumpdw4;
	//binkhook--;


	*(WORD *)netfix1 = 0x9090;
	
	*(WORD *)netfix2 = 0x9090;
	
	*(WORD *)netfix3 = 0x9090;
	
	*(DWORD *)netfix4 = 0x90909090;
	netfix4 += 4;
	*(WORD *)netfix4 = 0x9090;

	*(BYTE *)netfix5 = 0xEB;
	
	*(BYTE *)lobbyfix1 = 0xEB;
	
	*(WORD *)lobbyfix2 = 0x9090;
	
	*(WORD *)lobbyfix3 = 0x9090;
	
	*(WORD*)lobbyfix4 = 0x9090;
	
	*(WORD*)netport1 = 0x7200;
	
	*(WORD*)netport2 = 0x7200;
	
	*(WORD*)netport3 = 0x7200;
	
	*(BYTE *)joinfix = 0xEB;
	
	*(WORD*)xlivefix = 0x9090;
	
	
	// Stackfix1
	// E9 NOP NOP NOP to hook
	
	stackspot1 = stackfix1 + 8;
	DWORD stackfunc1 = (DWORD)xx1;
	DWORD jumpdw1 = (stackfunc1 - stackfix1) - 5;
	*(BYTE *)stackfix1 = 0xE9;
	stackfix1++;
	*(DWORD *)stackfix1 = jumpdw1;


	// Stackfix2
	// E9 NOP NOP NOP to hook
	
	stackspot2 = stackfix2 + 8;
	DWORD stackfunc2 = (DWORD)xx2;
	DWORD jumpdw2 = (stackfunc2 - stackfix2) - 5;
	*(BYTE *)stackfix2 = 0xE9;
	stackfix2++;
	*(DWORD *)stackfix2 = jumpdw2;

	// Stackfix3
	// E9 NOP NOP NOP NOP NOP
	
	stackspot3 = stackfix3 + 10;
	DWORD stackfunc3 = (DWORD)xx3;
	DWORD jumpdw3 = (stackfunc3 - stackfix3) - 5;
	*(BYTE *)stackfix3 = 0xE9;
	stackfix3++;
	*(DWORD *)stackfix3 = jumpdw3;

	// Search startMultiplayerPTR
	

	wsprintfA(location, V("68????????68%08X"),reinterpret_cast<char*>(((MPSTR>>24)&0x000000FF) | ((MPSTR>>8)&0x0000FF00) | ((MPSTR<<8)&0x00FF0000) | ((MPSTR<<24)&0xFF000000)));

	DWORD MPloc = FindHexString(location,0) + 1;
	*(DWORD*)MPloc = (DWORD)_xx;
	

	char *cmdline2 = (char *)GetCommandLineA();
	char *server = strstr(cmdline2, V("+server "));
	DWORD ip = 0;
	USHORT port = 0;

	if (server != NULL && parseIpPort(server+8, &ip, &port))
	{
		makeIPstr(ip, myip);
		wsprintfA(commands, V("disconnect; startPrivateListen; connect %s 114; clear"), myip);

		#ifdef DEBUGGING_ENABLED
		info("Commands will be: %s", commands);
		info("Commandline was: '%s'", cmdline2);
		#endif
	}
	else
	{
		wsprintfA(commands, V("disconnect; startPrivateListen; clear"));

		#ifdef DEBUGGING_ENABLED
		info("Commands will be: %s", commands);
		info("Commandline was: '%s'", cmdline2);
		#endif
	}

	spot = (DWORD)commands;

	VirtualProtect((void*)addr2, GetSectionSize(0), oldp, &oldp);
	return true;
	VE();
}
#pragma optimize("", on)

//extern "C" void __declspec(naked) DLLx xx4()
//{
//	__asm
//	{
//		MOV ESI, videoloc
//		CMP DWORD PTR DS:[ESI], 0x72617473
//		JNE nofix
//		MOV DWORD PTR DS:[ESI], 0x6E6B6574
//nofix:
//		PUSH 0x100
//		MOV ESI, binkhook
//		ADD ESI, 5
//		JMP ESI
//	}
//}



// Stackfix1
void __declspec(naked) xx1()
{
	__asm
	{
		MOV EAX, ESP
		SUB ESP, 0x38
restart:
		CMP ESP, EAX
		JE exit1
		MOV DWORD PTR DS:[ESP], 0
		ADD ESP, 4
		JMP restart
exit1:
		SUB ESP, 0x38
		PUSH 0x14001
		JMP stackspot1
	}
}

// Stackfix2
void __declspec(naked) xx2()
{
	__asm
	{
		MOV EAX, ESP
		SUB ESP, 0x40
restart:
		CMP ESP, EAX
		JE exit1
		MOV DWORD PTR DS:[ESP], 0
		ADD ESP, 4
		JMP restart
exit1:
		SUB ESP, 0x40
		PUSH 0x4000
		JMP stackspot2
	}
}

// Stackfix3
void __declspec(naked) xx3()
{
	__asm
	{
		MOV EAX, ESP
		SUB ESP, 0x91C
restart:
		CMP ESP, EAX
		JE exit1
		MOV DWORD PTR DS:[ESP], 0
		ADD ESP, 4
		JMP restart
exit1:
		MOV EAX, DWORD PTR DS:[ESP+8]
		SUB ESP, 0x91C
		JMP stackspot3
	}
}
void __declspec(naked) _xx()
{
	__asm
	{
		PUSH spot
		PUSH 0
		CALL cmdlinedw
		ADD ESP, 8
		RETN
	}
}

void __declspec(naked) fovhook1()
{
	__asm
	{
		PUSHFD
		PUSHAD
		PUSH fovptr
		PUSH 0
		CALL cmdlinedw
		ADD ESP, 8
		POPAD
		POPFD
		MOV EAX, pausevar1
		MOV EAX, DWORD PTR DS:[EAX]
		JMP fovfuncloc1
	}
}

void __declspec(naked) fovhook2()
{
	__asm
	{
		PUSHFD
		PUSHAD
		PUSH fovptr
		PUSH 0
		CALL cmdlinedw
		ADD ESP, 8
		POPAD
		POPFD
		MOV EDX, pausevar2
		MOV EDX, DWORD PTR DS:[EDX]
		JMP fovfuncloc2
	}
}