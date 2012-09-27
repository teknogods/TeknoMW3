#pragma once
#include "stdafx.h"
#include "SDK\SteamclientAPI.h"
#include "SDK\SteamAPI.h"


BOOL SteamAPI_Main(HMODULE hModule, DWORD ul_reason_for_call);
//void __cdecl TeknoGodzMW2_SetUserId( unsigned long userId );
int __cdecl TeknoGodzMW2_SteamSetup();
void __cdecl TeknoGodzMW2_SetNickname( char* nickname );
void __cdecl TeknoGodzMW2_SetPendingConnection( unsigned long ipaddr, unsigned short port );

extern bool IsInited;

extern CCallbackBase* g_MatchMakingCallbacks[20];
extern CCallbackBase* g_ServerCallbacks[20];
extern CCallbackBase* g_SteamUserCallbacks[20];
extern ISteamMatchmakingServerListResponse* g_RequestServersResponse;


extern char g_TeknoGodzMW2_Nickname[128];
extern int g_AppID;
extern unsigned long g_TeknoGodzMW2_ConnectIpAddr;
extern unsigned short g_TeknoGodzMW2_ConnectPort;
extern bool g_TeknoGodzMW2_isPendingConnect;
extern bool g_RequestLANServerList;
extern bool g_isServerIPInitialized;
extern bool g_OnlineMode;
extern CSteamID  g_LobbySteamId;
extern BYTE * g_AppTicket;
extern bool g_LobbyPendingCreate;
extern CSteamID  g_UserSteamId;
extern CSteamID  g_UserSteamId_def;
extern bool g_bEncryptedAppTicketRequested;
extern CSteamID  g_RemoteLobbySteamId;
extern CSteamID	 g_DedicatedServerSteamId;
extern DWORD g_HWID_Bak[5];