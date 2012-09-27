// steam_api_emu.cpp : Defines the entry point for the DLL application.
//
#include "stdafx.h"
#include "util.h"
//#include "util_smbios.h"
#include "util_smbios2.h"
#include "steam_api_emu.h"
#include "steam_api_emu_misc.h"
#include "game_patch_base.h"
#include "VMProtectSDK.h"
#include <sys/stat.h>
#include <time.h>
char mpdata_name[100];

#pragma optimize("", off)

char * GetMpdataName(CSteamID * steam_id)
{	VU("GetMpdataName");

	DWORD *keys;
	__asm
	{
		push eax
		mov eax, steam_id
		mov keys, eax
		pop eax
	}
	sprintf(mpdata_name, V(".\\dw\\iw5_m%x_%07x%08x.stat"), 0x2d02ef8d, keys[1], keys[0]);

	return mpdata_name;
	VE();
}


bool ValidateLoaderMutex()
{	VU("ValidateLoaderMutex");

	char mtx[256];
	sprintf(mtx, V("TeknoMW3%08X"), GetCurrentProcessId() ^ 0x57);
	//OutputDebugStringA(mtx);
	CreateMutexA(0, true, mtx);
	if(GetLastError() != 0xB7)
	{
		#ifdef DEBUGGING_ENABLED
		return true;
		#else
		return true;
		#endif
	}

	return true;	
	VE();
}


bool ValidateDumperMutex()
{	VU("ValidateDumperMutex");

	char mtx[256];
	sprintf(mtx, V("TeknoPDump%08X"), GetCurrentProcessId() ^ 0x80);
	CreateMutexA(0, true, mtx);
	if(GetLastError() != 0xB7)
	{
		return false;
	}

	return true;	
	VE();
}



bool SteamDataCrypto(BYTE * data, BYTE * outbuf, int size, CSteamID *steam_id)
{	VM("SteamDataCrypto");

	DWORD *keys;
	__asm
	{
		push eax
		mov eax, steam_id
		mov keys, eax
		pop eax
	}

	DWORD * cryptotable = (DWORD *)malloc(256*4+100);
	DWORD * seedtable = (DWORD *)kCrc32Table;
	DWORD seedkey = keys[0] ^ keys[1];
	BYTE last_rot = 0x13;

	for (int i=0; i<256; i++)
	{
		__asm
		{	push ecx
			mov cl, last_rot
			rol seedkey, cl
			pop ecx  }

		if (i%2==1)
			cryptotable[i] = seedtable[(i + (seedkey&0xFF)) & 0xFF] + seedkey ^ seedkey;
		else
			cryptotable[i] = seedtable[(i + (seedkey&0xFF)) & 0xFF] - seedkey ^ seedkey;
		last_rot = cryptotable[i] % 0xFF;
	}
	#ifdef DEBUGGING_ENABLED
	info("Using crypto table (seed keys: %08X %08X):", keys[0], keys[1]);
	//PrintBuffer((BYTE*)cryptotable, 256*4, 16);
	info("--------------");
	#endif

	if (size <= 256 * 4)
	{
		BYTE * byte_cryptotable = (BYTE *)cryptotable;

		for (int i=0; i<size; i++)
		{
			outbuf[i] = data[i] ^ byte_cryptotable[i];
		}
	}
	else
	{
		int block = 0;
		DWORD * d_data = (DWORD *)data;
		DWORD * d_outbuf = (DWORD *)outbuf;
		
		for (int i=0; i<(size/4); i++)
		{
			if (i % 256 == 0) block ++;

			DWORD xkey = cryptotable[i & 0xFF] ^ seedtable[((i+1000) % (111 + block)) & 0xFF];
			
			d_outbuf[i] = d_data[i] ^ xkey; 
		}
	}

	#ifdef DEBUGGING_ENABLED
	info("Output data:");
	//PrintBuffer((BYTE*)outbuf, size, 16);
	info("--------------");
	#endif



	free(cryptotable);

	return true;
	VE();
}

DWORD GetHWIDchunk(int chunk)
{	VU("GetHWIDchunk");

	int res = -1;

	switch (chunk)
	{
	case 1:
		{
			//CPUID
			char cpudata[0x50];
			memset(cpudata, 0, 0x50);
				
			__asm
			{
				pushad
				lea edi, cpudata
				add edi, 0x4C
				mov esi, 0x80000004

				mov eax, 0x80000000
				cpuid
				cmp eax, esi
				jl errora
			loopa:
				mov eax, esi
				cpuid

				mov [edi], edx
				mov [edi-4], ecx
				mov [edi-8], ebx
				mov [edi-12], eax
				sub edi, 0x10

				dec esi
				cmp esi, 0x7FFFFFFF
				jne loopa

				mov res, 1
				jmp exita
			errora:
				mov res, 0
			exita:
				popad
			}

			PrintBuffer((BYTE *)cpudata, 0x50, 16);
			info("GetHWIDchunk(%d) %d res", chunk, res);

			if (res = 1) return GetCRC32(cpudata, 0x50);
		
			info("GetHWIDchunk() Fail, returning default for request %d.", chunk);
			return 0xBAADD00D;
		}
		break;
	case 2:
		{
			//windows installation date
			char windir[256];
			memset(windir, 0, 256);
			GetWindowsDirectoryA(windir, 255);
			info("GetHWIDchunk()  Windows folder = %s", windir);

			struct _stat32 f_stats; 

			if (_stat32(windir, &f_stats) == 0)
			{
				char timebuf[256];
				_ctime32_s(timebuf, 26, &f_stats.st_ctime);
				info("GetHWIDchunk() Windows folder (%s) creation date = %s", windir, timebuf);

				if (strstr(timebuf, V(" 201")) == NULL && strstr(timebuf, V(" 200")) == NULL) return 0xBAADD00D;

				return f_stats.st_ctime ^ GetCRC32(windir, 20);
			}


			info("GetHWIDchunk() Fail, returning default for request %d.", chunk);
			return 0xBAADD00D;
		}
		break;
	case 3:
		{
			char compname[256];
			memset(compname, 0, 256);
			DWORD maxlen = 256;
			GetComputerNameA(compname, &maxlen);

			return GetCRC32(compname, sizeof(compname));
		}
		break;
	default:
		return 0;
	}

	return 0;

	VE();
}


bool GetHWID(DWORD * hwid)
{	VU("GetHWID");

	
	CHwInfo smbios2;

	DWORD hwid_l[3] = {0, 0, 0};

	//old method, w2k+ only...
	//
	//SMBiosData smbios;
	//
	//if (smbios.FetchSMBiosData())
	//{
	//	DWORD dwSize = 0;
	//	BYTE * table = NULL;
	//	
	//	table = smbios.GetTable(1, dwSize);
	//	info("returned size %d table %08X", dwSize, table);
	//	if (dwSize > 4)
	//	{
	//		hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
	//		hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
	//		hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
	//		info("--- table 1 -----");
	//		PrintBuffer(table, dwSize, 16);
	//	}
	//	table = smbios.GetTable(2, dwSize);
	//	info("returned size %d table %08X", dwSize, table);
	//	if (dwSize > 4)
	//	{
	//		hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
	//		hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
	//		hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
	//		info("--- table 2 -----");
	//		PrintBuffer(table, dwSize, 16);
	//	}
	//	table = smbios.GetTable(4, dwSize);
	//	info("returned size %d table %08X", dwSize, table);
	//	if (dwSize > 4)
	//	{
	//		hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
	//		hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
	//		hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
	//		info("--- table 4 -----");
	//		PrintBuffer(table, dwSize, 16);
	//	}
	//	table = smbios.GetTable(11, dwSize);
	//	info("returned size %d table %08X", dwSize, table);
	//	if (dwSize > 4)
	//	{
	//		hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
	//		hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
	//		hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
	//		info("--- table 11 ----");
	//		PrintBuffer(table, dwSize, 16);
	//	}

	//	info("main hwid done, result: %08X %08X %08X", hwid_l[0], hwid_l[1], hwid_l[2]);

	//}

	//hwid_l[0] = 0;
	//hwid_l[1] = 0;
	//hwid_l[2] = 0;


	if (smbios2.GetSMBiosData())
	{
		DWORD dwSize = 0;
		BYTE * table = NULL;
		
		table = smbios2.GetSMBiosStructure(1, dwSize);
		info("returned size %d table %08X", dwSize, table);
		if (dwSize > 4 && table != NULL)
		{
			hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
			hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
			hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
			info("--- table 1 -----");
			PrintBuffer(table, dwSize, 16);
		}
		table = smbios2.GetSMBiosStructure(2, dwSize);
		info("returned size %d table %08X", dwSize, table);
		if (dwSize > 4 && table != NULL)
		{
			hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
			hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
			hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
			info("--- table 2 -----");
			PrintBuffer(table, dwSize, 16);
		}
		table = smbios2.GetSMBiosStructure(4, dwSize);
		info("returned size %d table %08X", dwSize, table);
		if (dwSize > 4 && table != NULL)
		{
			hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
			hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
			hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
			info("--- table 4 -----");
			PrintBuffer(table, dwSize, 16);
		}
		table = smbios2.GetSMBiosStructure(11, dwSize);
		info("returned size %d table %08X", dwSize, table);
		if (dwSize > 4 && table != NULL)
		{
			hwid_l[0] = hwid_l[0] ^ GetCRC32(table, dwSize);
			hwid_l[1] = hwid_l[1] ^ GetCRC32(table+2, dwSize-2);
			hwid_l[2] = hwid_l[2] ^ GetCRC32(table+4, dwSize-4);
			info("--- table 11 ----");
			PrintBuffer(table, dwSize, 16);
		}

		info("main hwid done, result: %08X %08X %08X", hwid_l[0], hwid_l[1], hwid_l[2]);
	}
	else
	{
		hwid_l[0] = GetHWIDchunk(1);
		hwid_l[1] = GetHWIDchunk(2);
		hwid_l[2] = GetHWIDchunk(3);

		info("secondary hwid done, result: %08X %08X %08X", hwid_l[0], hwid_l[1], hwid_l[2]);
	}

	g_HWID_Bak[0] = GetTickCount();
	g_HWID_Bak[1] = hwid_l[0] ^ g_HWID_Bak[0];
	g_HWID_Bak[2] = hwid_l[1] ^ g_HWID_Bak[0];
	g_HWID_Bak[3] = hwid_l[2] ^ g_HWID_Bak[0];

	hwid[0] = 0;
	hwid[1] = hwid_l[0];
	hwid[2] = hwid_l[1];
	hwid[3] = hwid_l[2];

	return true;

	VE();
}



int GetHWIDSteamID()
{	VU("GetHWIDSteamID");

	char p[255];
	memset(p, 0, 255);
	DWORD a = 0;
	DWORD b = 0;

	char nickname[100];
	DWORD nnickName = sizeof(nickname);
	GetUserNameA((char*)nickname, &nnickName);

	__asm
	{
		pushad
		mov eax, 2
		cpuid
		mov a, eax
		mov b, edx
		popad
	}

	sprintf(p, V("(-%s-%d-%x-%c-)"), nickname, a, b, GAME_MODE);

	int crc32 = GetCRC32(p, 250);
	info("HWID is '%s', crc32 is %08X", p, crc32);
	
	//delete [] p;

	
	return crc32;
	VE();

	//DWORD res = 0;
	//HKEY hKey2;

	////generate steamid from machine OSid+CPUid
	//if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup", 0L, KEY_READ, &hKey2 ) == ERROR_SUCCESS)
	//{
	//	DWORD dwType;
	//	DWORD dwSize = 32;
	//	DWORD hashData[8];
	//	memset(hashData, 0, 32);

	//	if (RegQueryValueExA(hKey2, "PrivateHash", NULL, &dwType, (unsigned char *)hashData, &dwSize) == ERROR_SUCCESS)
	//	{
	//		res ^= hashData[0] + hashData[2];
	//	}

	//	__asm
	//	{
	//		pushad
	//		mov eax, 2
	//		cpuid
	//		add eax, edx
	//		xor res, eax
	//		popad
	//	}

	//	RegCloseKey(hKey2);
	//}

	//return res;
}
#pragma optimize("", on)



void InitFloat()
{
	float floating_decoy = 1.0;
	printf(V("TeknoMW3 v%f by Stte&Simon"), floating_decoy);
}
