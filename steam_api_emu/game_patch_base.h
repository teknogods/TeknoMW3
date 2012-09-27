#pragma once
#include "stdafx.h"
#include "game_admin_base.h"

struct FF_FILE_INFO
{
	char * name;
	DWORD size_p;
	DWORD size_u;
	void * data;
};

enum AssetTypes {
	physpreset,
	phys_collmap,
	xanim,
	xmodelsurfs,
	xmodel,
	material,
	pixelshader,
	vertexshader,
	vertexdecl,
	techset,
	image,
	sound,
	sndcurve,
	loaded_sound,
	col_map_sp,
	col_map_mp,
	com_map,
	game_map_sp,
	game_map_mp,
	map_ents,
	fx_map,
	gfx_map,
	lightdef,
	ui_map,
	font,
	menufile,
	menu,
	localize,
	weapon,
	snddriverglobals,
	fx,
	impactfx,
	aitype,
	mptype,
	character,
	xmodelalias,
	rawfile,
	scriptfile,
	stringtable,
	leaderboarddef,
	structureddatadef,
	tracer,
	vehicle,
	addon_map_ents
};



typedef char* (*MYGETDVARVAL)(DWORD); 
extern MYGETDVARVAL GetDvarValueStrFromBuffer;
extern DWORD DvarCountPtr;
extern DWORD DvarListPtr;
extern DWORD FuncListPtr;
extern DWORD * g_SteamID_DW64;
extern BYTE *g_MpdataLoc;

char * GetDvarValueStr(char * DvarName);
DWORD GetDvarBuffByName(char * DvarName);
bool GetDvarAndFuncListPtrs();
DWORD GetDvarBuffById(int id);
bool GetDvarAddingFuncs();

bool GetClientsBlock();
bool GetConsole();
bool GetConsolePrintf();
bool GetGameMode();
bool GetBlobLoader();
bool GetHeatmapCheckPtr();
bool GetSteamIDAndMpdataLocs();
bool GetFillServerInfo();
bool GetGameBuildNum();
bool HookClientBan();
bool HookGetBanStatus();
bool HookAuthorizeIP();
bool HookDWLogFunc();
bool HookDWGetFile();
bool HookGenerateSecurityKeys();
bool HookGetAssetFunc();
bool HookGetServerInfo();
bool HookConsole();
bool HookKeyboard();
bool HookProcessClientUICommand();
bool HookDvarToStrForScripts();
bool HookIsMapInstalled();
//bool HookGenerateSharedSecretKey();
bool HookGenerateSharedKey();
bool PatchVariousStuff();
bool PatchHeatmapCheck();

int ConsolePrintf_Stub(DWORD code, const char* Format, ...);
int Console_Stub(DWORD code, const char* Format);
void FillServerInfo_Stub(char* outbuf);
void __stdcall LoadBlob_Stub(DWORD dw_low, DWORD dw_high, char* name, void * blob, int unk60h);


typedef bool (__stdcall *MYGUIDFUNC)();

typedef int (*MYCONPRINTF)(DWORD, const char*, ...); 
typedef int (*MYCONPROC)(DWORD, const char*);
typedef void (__stdcall *MYBLOBPROC)(DWORD, DWORD, char*, void *, int);
typedef void (__cdecl *MYFILLSERVERINFO)(char * outbuf);

extern MYBLOBPROC LoadBlob;
extern MYCONPROC Console;
extern MYFILLSERVERINFO FillServerInfo;
extern MYCONPRINTF ConsolePrintf;


extern char GAME_MODE;
extern bool g_Patch_DW_STUN_Server_port_and_hosts;
extern bool g_Patch_DW_ConnectionStatus;
extern bool g_Patch_DW_ProcessFileRequest;
extern bool g_Patch_Unauthorized_IP;
extern bool g_Patch_Unregistered_Connection;
extern bool g_Patch_HostAndClient_On_Same_Local_IP_Fail;
extern bool g_Patch_SteamAuthFail_clientDrop;
extern bool g_Patch_Getting_Data_Popup;
extern bool g_Patch_Session_Info_Funcs;
extern bool g_Patch_Task_server_Crash;
extern bool g_Patch_Task_matchmaking_search;
extern bool g_Patch_Content_server_init;
extern bool g_Set_Ranked_Games;
extern bool g_SteamGUIDsFail;

//UI String Replacements
extern char TEKNO_CAPTION[20];

extern int g_NewFov; 
extern bool g_TkDev; 
extern bool g_RCon_Full_Access; 
extern bool g_GlobalBans;
extern bool g_ValidateNicknames;
extern DWORD g_GameBuild; 

extern PMW3_CLIENTS_INFO_DEDI g_ClientsBlock;
extern DWORD g_ClientsBlock2;