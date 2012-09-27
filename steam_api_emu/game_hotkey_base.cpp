#pragma once 
#include "stdafx.h"
#include "util.h"
#include "game_patch_base.h"
#include "game_dvar_base.h"
#include "game_admin_base.h"
#include "game_server_items.h"
#include "steam_api_emu.h"
#include "dw_online_files.h"
#include "VMProtectSDK.h"



void ExecHotkey(int vKey)
{
	//if (vKey == VK_F11 && GAME_MODE == 'M')
	//{
	//	//char cmd[255];
	//	//sprintf(cmd, "connect_lobby %llu\n", g_RemoteLobbySteamId.ConvertToUint64());
	//	//Console(0, cmd);
	//	//TeknoGodzMW2_SetPendingConnection(htonl(0x230BA8C0), 0x20c);

	//	//char name[255];
	//	//sprintf(name, "tkuser_%08X", GetTickCount());
	//	//TeknoGodzMW2_SetNickname(name);

	//	//if (g_SteamUserCallbacks[3] != NULL)
	//	//{
	//	//	GameServerChangeRequested_t req;
	//	//	memset(req.m_rgchPassword, 0, 64); 
	//	//	strcpy(req.m_rgchServer, "192.168.1.1:1111");
	//	//	g_SteamUserCallbacks[3]->Run(&req);
	//	//}

	//	DWORD add2 = FindHexString("a1????????8d94240408000052565068????????e8????????8b8c24180c00005051e8????????83c418", 0) + 1;

	//	if (add2 > 0x400000)
	//	{
	//		info("Addr: %08X", add2);
	//		DWORD magicNumber = *(DWORD*)*(DWORD*)add2;

	//		CHAR buffer[256];
	//		sprintf(buffer, "mr %d 2 axis; mr %d 9 custom1;", magicNumber, magicNumber);
	//		Console(0, buffer);  
	//	}

	//}

	//if (vKey == VK_SUBTRACT && GAME_MODE == 'M')
	//{
	//	DWORD add2 = FindHexString("a1????????8d94240408000052565068????????e8????????8b8c24180c00005051e8????????83c418", 0) + 1;

	//	if (add2 > 0x400000)
	//	{
	//		info("Addr: %08X", add2);
	//		DWORD magicNumber = *(DWORD*)*(DWORD*)add2;

	//		CHAR buffer[256];
	//		sprintf(buffer, "mr %d -1 endround;", magicNumber);
	//		Console(0, buffer);  
	//	}
	//}


	//if (vKey == VK_SUBTRACT && GAME_MODE == 'M')
	//{
	//	DWORD add2 = FindHexString("a1????????8d94240408000052565068????????e8????????8b8c24180c00005051e8????????83c418", 0) + 1;

	//	if (add2 > 0x400000)
	//	{
	//		info("Addr: %08X", add2);
	//		DWORD magicNumber = *(DWORD*)*(DWORD*)add2;

	//		CHAR buffer[256];
	//		sprintf(buffer, "callvote map_restart;\n", magicNumber);
	//		Console(0, buffer);  
	//	}
	//}

	if (vKey == VK_F12 && GAME_MODE == 'M')
	{
		Console(0, V("connect_ext\n"));
	}

	if (vKey == VK_F11)
	{
		if (g_TkDev)
			DumpDvarToFile();
	}

	if (vKey == VK_SUBTRACT)
	{

		//if (GAME_MODE == 'D')
		//{
			//BYTE * ptr1 = (BYTE *)0x1B7B24C;

			//for (int i = 0; i < 0xD0; i++)
			//{
			//	if (ptr1[i] == 0x3b) info("%08X + 0x3b\n", i);
			//	if (ptr1[i] == 0x22) info("%08X + 0x22\n", i);
			//	if (ptr1[i] == 0x0a) info("%08X + 0x0a\n", i);
			//	if (ptr1[i] == 0x0d) info("%08X + 0x0d\n", i);
			//}


			//BYTE * ptr2 = (BYTE *)(0x1B7B24C+0xD0);

			//for (int i = 0; i < 0xD0; i++)
			//{
			//	ptr1[i] = 0x30+i;
			//	ptr2[i] = 0x30+i;
			//}
			//MessageBoxA(0,0,0,0); __asm int 3;

			//for (int j=0; j<0x100; j++)
			//{

			//	char key[400];
			//	memset(key, j&0xFF, 8);
			//	memset(ptr1, 0, 0x1a0);	

			//	__asm
			//	{
			//		pushad

			//		mov eax, 0x4CB790
			//		push 8
			//		lea ebx, key
			//		push ebx
			//		call eax
			//		add esp, 8

			//		popad
			//	}
			//	info("%08X ------------\n", j);


			//	for (int i = 0; i < 0xD0; i++)
			//	{
			//		if (ptr1[i] == 0x3b) info("%08X + 0x3b\n", i);
			//		if (ptr1[i] == 0x22) info("%08X + 0x22\n", i);
			//		if (ptr1[i] == 0x0a) info("%08X + 0x0a\n", i);
			//		if (ptr1[i] == 0x0d) info("%08X + 0x0d\n", i);
			//	}
			//}

		//}

		//if (GAME_MODE == 'M')
		//{
		//	BYTE * ptr1 = (BYTE *)0x1CE5FCC;
		//	BYTE * ptr2 = (BYTE *)(0x1CE5FCC+0xD0);

		//	for (int i = 0; i < 0xD0; i++)
		//	{
		//		ptr1[i] = 0x30+i;
		//		ptr2[i] = 0x30+i;
		//	}
		//}

		//this is somewhat recreated console command "map", cus its missing in the client
		//if (GAME_MODE == 'M')
		//{
		//	char mapname[30] = "mp_village";
		//	__asm
		//	{
		//
		//		push ebx
		//		push 0x5000
		//		lea eax, mapname
		//		mov ebx, 0x621FE0
		//		call ebx
		//		add esp, 4
		//		pop ebx
		//	}
		//}
		

		////print eagle heatmap trolololol
		//memcpy((void*)(*(DWORD*)0x01CD4674), heatmap_unp_vfile, 0x10000);
		//*(BYTE*)0x1CD466D = 0;

/*
		#ifdef DEBUGGING_ENABLED
		if (GAME_MODE == 'D')
		{
			PMW3_CLIENTS_INFO_DEDI clinfo = (PMW3_CLIENTS_INFO_DEDI)0x49EB68C;

			int clients = 0;

			for (int i=0; i<18; i++)
			{
				DWORD score = 0;
				__asm
				{
					pushad
					push i
					mov eax, 0x489220
					call eax
					add esp, 4
					mov score, eax
					popad
				}

				if (clinfo->Clients[i].Type == 5) 
				{
					clients++;				
					info("Client %d: type: %d, nick: %s, ping: %d, score: %d, ip: %08X, port: %04X, steamid: %s, tags: %s", i+1, clinfo->Clients[i].Type, clinfo->Clients[i].Nickname, clinfo->Clients[i].Ping, score, clinfo->Clients[i].Ip, clinfo->Clients[i].Port, clinfo->Clients[i].SteamId, clinfo->Clients[i].ClientTags);
				}
			}

			info("Server players: %d/%d", clients, clinfo->MaxClientCount);
		}
		#endif*/



		//for (int i = 0; i < (0x6805000-100); i++)
		//{
		//	if (*(DWORD*)(i+0x400000) == 0x537C4754 && *(DWORD*)(i+0x400004) == 0x6672756D)
		//	{
		//		info("found name at %08X", i);
		//		*(DWORD*)(i+4) = 0x31313131;
		//	}
		//}

		//info("is nn prop (%s) -> %d", "TG|Smurf^1==D+", IsNicknameProper("TG|Smurf^1==D+"));
		//info("is nn prop (%s) -> %d", ";%hax$$$<>", IsNicknameProper(";%hax$$$<>"));
		//DumpClientsData();
	}



}
