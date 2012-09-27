#pragma once
#include "stdafx.h"
#include "SDK\SteamclientAPI.h"
#include "SDK\SteamAPI.h"


extern bool g_mpdata_loaded;
extern unsigned char HeatMap_vfile[1565];
#ifdef DEBUGGING_ENABLED
extern unsigned char Mpdate_vfile_d[12288];
#endif
extern unsigned char Mpdate_vfile_r[12288];
extern unsigned char Social_vfile[1476];
extern unsigned char Playlists_vfile[13474];
extern unsigned char Entitlement_vfile[925];

extern unsigned char heatmap_unp_vfile[65536];

typedef struct _RequestTicketBlob {
	char * name;
	DWORD unk0_1;
	DWORD some_val_a_1;
	DWORD some_val_a_2;
	__int64 real_size_a;
	DWORD some_class1;
	DWORD unk0_2;
	DWORD some_val_b_1;
	DWORD some_val_b_2;
	DWORD timestamp_c;  
	DWORD timestamp_m;
	__int64 consumption_state;
	CSteamID steam_id;
	char local_name[0x80];
	__int64 real_size_b;
	DWORD some_class2;
	DWORD buffer_ptr_a;
	DWORD buffer_size_a;
	DWORD buffer_size_b;
	DWORD buffer_ptr_b;
	DWORD unk0_3;
} RequestTicketBlob, *PRequestTicketBlob;




typedef DWORD (__cdecl *DWGETFILE)(DWORD * info_struct_a, RequestTicketBlob * info_struct_b);
DWORD __cdecl myDWGetFile(DWORD caller, DWGETFILE tramp, DWORD * info_struct_a, RequestTicketBlob * info_struct_b);


char * SaveDWMpdataToFile(bool no_fail);