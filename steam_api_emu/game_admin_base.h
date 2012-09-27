#pragma once
#include "stdafx.h"

#pragma pack(1)
typedef struct _MW3_CLIENT_INFO_DEDI {
	DWORD		Type;
	BYTE		unk1[0x28];
	DWORD		Ip;
	USHORT		Port;
	BYTE		unk2[0x63E];
	char		ClientTags[0x400];
	BYTE		unk3[0x209B8];
	char		Nickname[0x50];
	DWORD		Ping;
	BYTE		unk4[0x20818];
	char		SteamId[17];
	BYTE		unk5[0xC];
	BYTE		GameProfile[0x2FF4];
	DWORD		sHWID[3];
	BYTE		unk6[0x339D7];
} MW3_CLIENT_INFO_DEDI, *PMW3_CLIENT_INFO_DEDI;

typedef struct _MW3_CLIENT_INFO_MP {
	DWORD		Type;
	BYTE		unk1[0x28];
	DWORD		Ip;
	USHORT		Port;
	BYTE		unk2[0x63E];
	char		ClientTags[0x400];
	BYTE		unk3[0x209B8];
	char		Nickname[0x50];
	DWORD		Ping;
	BYTE		unk4[0x20818];
	char		SteamId[17];
	BYTE		unk5[0xC];
	BYTE		GameProfile[0x2FF4];
	DWORD		sHWID[3];
	BYTE		unk6[0x339D7];
	BYTE		unk7[8];
} MW3_CLIENT_INFO_MP, *PMW3_CLIENT_INFO_MP;


typedef struct _MW3_CLIENTS_INFO_DEDI {
	DWORD		MaxClientCount;
	MW3_CLIENT_INFO_DEDI Clients[18];
} MW3_CLIENTS_INFO_DEDI, *PMW3_CLIENTS_INFO_DEDI;

typedef struct _MW3_CLIENTS_INFO_MP {
	DWORD		MaxClientCount;
	MW3_CLIENT_INFO_MP Clients[18];
} MW3_CLIENTS_INFO_MP, *PMW3_CLIENTS_INFO_MP;


#pragma pack()

typedef void (__cdecl *CLIENTBAN)(PMW3_CLIENT_INFO_DEDI client);


void InitVisitorsList();
void InitGlobalBans();
void InitGameplayGuard();
bool IsNicknameProper(char * nickname, int len);
void DumpClientsData();

int __stdcall myGetBanStatus(bool SteamID_perm_banned, DWORD * hwid, DWORD steamID_hi, DWORD steamID_low, USHORT port, DWORD ip);
DWORD __cdecl myClientBan(DWORD caller, CLIENTBAN tramp, PMW3_CLIENT_INFO_DEDI client);