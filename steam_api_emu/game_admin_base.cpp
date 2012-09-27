#include "stdafx.h"
#include "steam_api_emu.h"
#include "game_admin_base.h"
#include "game_dvar_base.h"
#include "game_patch_base.h"
#include "stdio.h"
#include "util.h"
#include "util_ini.h"
#include "util_adv_log.h"
#include "VMProtectSDK.h"
#include <map>


#pragma optimize("", off)

char * g_GlobalBansData;
DWORD g_GlobalBans_status = 0;
bool g_GlobalBans_lock = false;

char p_charset[92] = "'´` _.1234567890^=-+*[]~{}()<>$@|#!qwertyuiopasdfghjklzxcvbnm:QWERTYUIOPASDFGHJKLZXCVBNM";

bool IsNicknameProper(char * nickname, int len)
{	VM("IsNicknameProper");

	if (len > 0x4B) return false;

	if (!g_ValidateNicknames) return true;

	if (len > 33) return false;
	if (strstr(nickname, V("^")) == NULL && len > 16) return false;

	char s[2];

	for (int i = 0; i<len; i++)
	{
		s[1] = 0;
		s[0] = nickname[i];

		if (strstr(V(p_charset), s) == NULL) return false;
	}

	return true;

	VE();
}





#define GLOBAL_BANS_BUFFER_SIZE 0x4000

DWORD WINAPI InitGlobalBansThreadFunc(LPVOID lpParameter)
{	VM("InitGlobalBansThreadFunc");

	if (g_GlobalBansData != NULL) free(g_GlobalBansData);

	g_GlobalBansData = (char *)malloc(GLOBAL_BANS_BUFFER_SIZE);
	memset(g_GlobalBansData, 0, GLOBAL_BANS_BUFFER_SIZE);

	int g_GlobalBans_size = HttpReadFile(V("http://teknogods.com/globalbans/mw3_27.ban"), g_GlobalBansData, GLOBAL_BANS_BUFFER_SIZE);

	if (g_GlobalBans_size != 0) g_GlobalBans_status = 1; else g_GlobalBans_status = 2;

	return 0;

	VE();
}

void InitGlobalBans()
{	VM("InitGlobalBans");

	while (g_GlobalBans_lock) Sleep(1);
	g_GlobalBans_lock = true;

	CreateThread(NULL, 0, InitGlobalBansThreadFunc, NULL, 0, NULL);
	info("InitGlobalBansThreadFunc Created\n");

	ConsolePrintf(0, V("Downloading global ban list"));

	int ct = 0;
	int ret = 15;
	while (g_GlobalBans_status == 0 && ret != 0)
	{
		Sleep(1);
		ct++;
		if (ct % 800 == 1)
		{
			ConsolePrintf(0, ".");
			ret--;
		}
	}

	if (g_GlobalBans_status == 1)
		ConsolePrintf(0, V(" Done.\n"));
	else
		ConsolePrintf(0, V(" Error.\n"));

	g_GlobalBans_lock = false;

	info("InitGlobalBansThreadFunc finished\n");

	VE();
}


DWORD tempBans[1024];
int tempBanCount = 0;
bool tempBanLock = false;

void g_TempBan(DWORD ip)
{	VM("g_TempBan");

	//gyspy thread lock
	while (tempBanLock) Sleep(1);
	tempBanLock = true;

	if (tempBanCount >= 1024)
		tempBanCount = 0;

	tempBans[tempBanCount] = ip;
	tempBanCount++;

	tempBanLock = false;

	VE();
}

bool g_IsTempBanned(DWORD ip)
{	VM("g_IsTempBanned");

	//gyspy thread lock
	while (tempBanLock) Sleep(1);
	tempBanLock = true;

	for (int i = 0; i < tempBanCount; i++)
	{
		if (tempBans[i] == ip)
		{
			tempBanLock = false;
			return true;
		}
	}

	tempBanLock = false;
	return false;

	VE();
}




map<ULONGLONG, DWORD*> serverVisitors;

void InitVisitorsList()
{
	serverVisitors.clear();
}


DWORD * GetServerVisitor(USHORT port, DWORD ip)
{	VM("GetServerVisitor");

	ULONGLONG newVisitorIPPORT = ip * 0x100000000 | (port & 0xFFFF);

	if (!serverVisitors.empty())
	{
		//search for the client
		map<ULONGLONG, DWORD*>::iterator itr;
		for(itr = serverVisitors.begin(); itr != serverVisitors.end(); itr++)
		{
			if(itr->first == newVisitorIPPORT)
			{
				break;
			}
		}

		if(itr != serverVisitors.end())
		{
			return itr->second;
		}
	}

	return NULL;

	VE();
}

bool banVisitorLock = false;

bool BanServerClient(USHORT port, DWORD ip, char * nickname)
{	VU("BanServerClient");

	//gypsy thread lock
	while (banVisitorLock) Sleep(1);
	banVisitorLock = true;

	DWORD * hwid = GetServerVisitor(port, ip);

	if (hwid != NULL)
	{
		char hwid_str[256];
		sprintf(hwid_str, "%08X%08X%08X", hwid[1], hwid[2], hwid[3]);

		CIniWriter iniWriter(V(".\\main\\permanent_ex.ban"));
		char ip_str[256];
		makeIPstr(ip, ip_str);
		char info_line[256];
		sprintf(info_line, "%s (%s)", ip_str, nickname);

		iniWriter.WriteString(V("Bans"), hwid_str, info_line);

		banVisitorLock = false;
		return true;
	}

	banVisitorLock = false;
	return false;

	VE();
}

bool IsServerClientBanned(DWORD * hwid)
{	VU("IsServerClientBanned");

	if (hwid == NULL) return false;

	//gypsy thread lock
	while (banVisitorLock) Sleep(1);
	banVisitorLock = true;

	CIniReader iniReader(V(".\\main\\permanent_ex.ban"));

	char hwid_str[256];
	sprintf(hwid_str, "%08X%08X%08X", hwid[1], hwid[2], hwid[3]);

	char * found_id = iniReader.ReadString(V("Bans"), hwid_str, "");

	//check if the hwid was found, return true if was, else, check online
	if (strcmp(found_id, "") != 0)
	{
		delete [] found_id;
		banVisitorLock = false;
		return true;
	}
	delete [] found_id;

	//check global/online bans
	if (g_GlobalBans_status == 1 && g_GlobalBansData != NULL)
	{
		if (strstr(g_GlobalBansData, hwid_str) != NULL)
		{
			banVisitorLock = false;
			return true;
		}
	}

	banVisitorLock = false;
	return false;	

	VE();
}



bool AddServerVisitor(DWORD * hwid, USHORT port, DWORD ip)
{	VM("AddServerVisitor");

	//gypsy thread lock
	while (banVisitorLock) Sleep(1);
	banVisitorLock = true;

	DWORD * hwid_e = GetServerVisitor(port, ip);

	if (hwid_e == NULL)
	{
		ULONGLONG newVisitorIPPORT = ip * 0x100000000 | (port & 0xFFFF);
		DWORD * newVisitorHWID = new DWORD[5];
		memcpy(newVisitorHWID, hwid, 16);
		newVisitorHWID[4] = 0;
		serverVisitors.insert(std::make_pair(newVisitorIPPORT, newVisitorHWID));
		banVisitorLock = false;
		return true;
	}
	else
	{
		hwid_e[4] = 0;
	}

	banVisitorLock = false;
	return true;

	VE();
}

int __stdcall myGetBanStatus(bool SteamID_perm_banned, DWORD * hwid, DWORD steamID_hi, DWORD steamID_low, USHORT port, DWORD ip)
{	VU("myGetBanStatus");

	info("ip = %08X, port = %d, SteamID = %08X %08X, hwid[0] = %08X, perm_banned = %d", ip, port, steamID_low, steamID_hi, hwid[0], SteamID_perm_banned);

	if (SteamID_perm_banned) return true;
	if (g_IsTempBanned(ip)) return true;

	//decrypt and hash hwid
	DWORD hwid_l[4] = {hwid[0], hwid[1], hwid[2], hwid[3]};
	hwid_l[0] = hwid_l[0] ^ 0x23586134 ^ 0xC0DEB100;
	hwid_l[1] = hwid_l[1] ^ ntohl(hwid_l[0]) ^ 0x7629d1b9;
	hwid_l[2] = hwid_l[2] ^ hwid_l[0] ^ 0x1337D00D;
	hwid_l[3] = hwid_l[3] ^ (hwid_l[0] >> 1) ^ 0xDEADCAFE;
	DWORD hwid_crc = GetCRC32((void *)&hwid_l[1], 12);
	info("gotcrc %08X, expected %08X", hwid_crc, hwid_l[0]);

	if (hwid_crc == hwid_l[0] && !IsServerClientBanned(hwid_l)) 
	{
		AddServerVisitor(hwid_l, port, ip);
	}
	else
	{
		g_TempBan(ip);
		return 1;
	}

	return 0;
	VE();
}

DWORD __cdecl myClientBan(DWORD caller, CLIENTBAN tramp, PMW3_CLIENT_INFO_DEDI client)
{	VM("myClientBan");

	tramp(client);
	
	#ifdef DEBUGGING_ENABLED
	info("ClientBan(%s)", client->Nickname);
	#endif

	BanServerClient(htons(client->Port), client->Ip, client->Nickname);

	char cmd[256];
	int cnum = -1;
	for (int i = 0; i < g_ClientsBlock->MaxClientCount; i++)
	{
		if ((DWORD)(&g_ClientsBlock->Clients[i]) == (DWORD)client)
		{
			cnum = i;
			break;
		}
	}

	if (cnum != -1)
		sprintf(cmd, V("kickclient %d\n"), cnum);
	else
		sprintf(cmd, V("kick %s\n"), client->Nickname);
	
	Console(0, cmd);

	return 0;

	VE();
}





DWORD WINAPI GameplayGuardThreadFunc(LPVOID lpParameter)
{	VM("GameplayGuardThreadFunc");

	if (g_ClientsBlock != NULL)
		ConsolePrintf(0, V("Gameplay guard initialized.\n"));
	else
	{
		ConsolePrintf(0, V("Gameplay guard failed to initialize!\n"));
		return 0;
	}

	while (true)
	{
		for (int i=0; i<g_ClientsBlock->MaxClientCount; i++)
		{
			if (g_ClientsBlock->Clients[i].Type == 5)
			{
				int len = strlen(g_ClientsBlock->Clients[i].Nickname);

				if (!IsNicknameProper(g_ClientsBlock->Clients[i].Nickname, len))
				{
					char cmd[256];
					sprintf(cmd, V("kickClient %d;\n"), i);

					Console(0, cmd);
				}

				DWORD * hwid = GetServerVisitor(htons(g_ClientsBlock->Clients[i].Port), g_ClientsBlock->Clients[i].Ip);

				if (hwid[4] == 0)
				{
					char * mem = (char *)malloc(256);
					memset(mem, 0, 256);
					hwid[4] = (DWORD)mem;
					strncpy(mem, g_ClientsBlock->Clients[i].Nickname, len);
				}
				else
				{
					char * mem = (char*)hwid[4];
					if (strcmp(mem, g_ClientsBlock->Clients[i].Nickname) != 0)
					{

						free(mem);
						hwid[4] = 0;

						char cmd[256];
						sprintf(cmd, V("banClient %d;\n"), i);
						Console(0, cmd);
					}
				}


				//client block + 44ca5 = secondary hwid
				
				//DWORD shwid[3];
				//shwid[0] = g_ClientsBlock->Clients[i].sHWID[0] ^ 0xDEADDEAD;
				//shwid[1] = g_ClientsBlock->Clients[i].sHWID[1] ^ 0xDEADDEAD;
				//shwid[2] = g_ClientsBlock->Clients[i].sHWID[2] ^ 0xDEADDEAD;
				////info("client s hwid %08X%08X%08X", shwid[0], shwid[1], shwid[2]);

				//if (hwid[1] != shwid[0] || hwid[2] != shwid[1] || hwid[3] != shwid[2])
				//{
				//	char * mem = (char*)hwid[4];
				//	free(mem);
				//	hwid[4] = 0;

				//	char cmd[256];
				//	sprintf(cmd, V("banClient %d;\n"), i);
				//	Console(0, cmd);
				//}
			}
		}

		Sleep(3000);
	}

	return 1;
	VE();
}


void InitGameplayGuard()
{
	CreateThread(NULL, 0, GameplayGuardThreadFunc, NULL, 0, NULL); 
}



void DumpClientsData()
{	VM("DumpClientsData");

	if (g_ClientsBlock == NULL)
		return;

	char fname[256];
	sprintf(fname, V(".\\main\\clients_dump_%08X.bin"), GetTickCount());


	FILE * pFile;
	pFile = fopen(fname, "wb");

	if (pFile != NULL)
	{
		int writeSize = g_ClientsBlock->MaxClientCount * sizeof(MW3_CLIENT_INFO_DEDI) + 4;

		if (fwrite((void*)g_ClientsBlock, 1, writeSize, pFile) == writeSize)
		{
			ConsolePrintf(0, V("Clients data dumped to: \"%s\".\n"), fname);
		}

		fclose(pFile);
	}


	//for (int i = 0; i < g_ClientsBlock->MaxClientCount; i++)
	//{
	//	if (g_ClientsBlock->Clients[i].Type == 5)
	//	{
	//		strcpy(g_ClientsBlock->Clients[i].Nickname, "test123");
	//	}
	//}

	VE();
}



#pragma optimize("", on)