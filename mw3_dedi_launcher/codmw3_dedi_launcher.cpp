// codmw3_dedi_launcher.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "stdio.h"
#include "codmw3_dedi_launcher.h"
#include "..\steam_api_emu\VMProtectSDK.h"
#include "..\steam_api_emu\util.h"

char g_DediExeName[17] = "iw5mp_server.exe";
char g_DllName[13] = "TeknoMW3.dll";

#pragma optimize("", off)

int FindString(char * str, void * buffer, int size)
{
	int strl = strlen(str);

	for (int i=0; i < size; i++)
	{
		if (strncmp((char*)((DWORD)buffer+i), str, strl) == 0)
			return i;
	}
	return 0;
}


void InfoVal(char * name, DWORD val)
{
	char addr[255];
	sprintf(addr, "%s = %08X", name, val);
	OutputDebugStringA(addr);
}



DWORD LocateSteamApiString(char * filename)
{	VU("LocateSteamApiString");

	FILE * pFile;
	pFile = fopen(filename, "rb");
	if (pFile != NULL)
	{
		BYTE fileheader[0x400];

		if (fread(fileheader, 1, 0x400, pFile) == 0x400)
		{
			DWORD pe_ptr = *(DWORD*)(fileheader+0x3c) & 0xFFFF;
			DWORD opt_hdr_size = *(DWORD*)(fileheader+pe_ptr+0x14) & 0xFFFF;
			DWORD sect_hdr_ptr = pe_ptr + 0x18 + opt_hdr_size;
			DWORD r_data_hdr_ptr = sect_hdr_ptr + 0x28;
			DWORD rdata_v_ptr = *(DWORD*)(fileheader+r_data_hdr_ptr+0x0c);
			DWORD rdata_r_ptr = *(DWORD*)(fileheader+r_data_hdr_ptr+0x14);
			DWORD rdata_r_size = *(DWORD*)(fileheader+r_data_hdr_ptr+0x10);
			DWORD raw_distance = rdata_v_ptr - rdata_r_ptr;

			if (raw_distance < 0 || rdata_r_size < 0xB000)
				return 0;

			void * rdata = malloc(0xB000);

			fseek(pFile , rdata_r_ptr + rdata_r_size - 0xB000 , SEEK_SET);

			if (fread(rdata, 1, 0xB000, pFile) == 0xB000)
			{
				if (FindString(V("pc\\iw5mp_server"), rdata, 0xB000)  != 0)
				{
					int str_api_ptr = FindString(V("steam_api.dll"), rdata, 0xB000);

					if (str_api_ptr != 0)
					{
						return str_api_ptr + rdata_v_ptr + (rdata_r_size - 0xB000);
					}
				}
			}

			free(rdata);
			//OutputDebugStringA("fail processing rdata");
			return 0;
		}
		//OutputDebugStringA("fail reading fileheader");
		return 0;
	}
	//OutputDebugStringA("fail opening file");
	return 0;

	VE();
}


void StartProcessWithTeknoDll(char * exe_name, char * params)
{	VU("StartProcessWithTeknoDll");

	DWORD dllnameptr = LocateSteamApiString(exe_name);
	if (dllnameptr == 0)
	{
		MessageBoxA(0, V("Unsupported or missing 'iw5mp_server.exe' executable."), V("Error"), MB_ICONERROR);
		return;
	}
	dllnameptr += 0x400000;

	char cmd_line[255];
	sprintf(cmd_line, V("\"%s\" %s"), exe_name, params);

	STARTUPINFO MyStartUpInfo;
	PROCESS_INFORMATION MyProcessInfo;
	ZeroMemory( &MyStartUpInfo, sizeof(MyStartUpInfo));
	MyStartUpInfo.cb = sizeof(MyStartUpInfo);
	ZeroMemory( &MyProcessInfo, sizeof(MyProcessInfo));
   
	if( !CreateProcess(exe_name, cmd_line, NULL, NULL, false, THREAD_PRIORITY_NORMAL | CREATE_SUSPENDED, NULL, NULL, &MyStartUpInfo, &MyProcessInfo) )
	{
		MessageBoxA(0, V("CreateProcess failed."), V("Error"), MB_ICONERROR);
		return;
	}
	
	//WaitForSingleObject( MyProcessInfo.hProcess, INFINITE );

	//HANDLE phandle = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_WRITE | PROCESS_SUSPEND_RESUME, false, MyProcessInfo.dwProcessId);
	//HANDLE phandle = OpenProcess(PROCESS_ALL_ACCESS, false, MyProcessInfo.dwProcessId);

	//if (phandle == NULL)
	//{
	//	TerminateProcess(MyProcessInfo.hProcess, 0);
	//	CloseHandle(MyProcessInfo.hProcess);
	//	CloseHandle(MyProcessInfo.hThread);
	//	MessageBoxA(0, V("OpenProcess failed."), V("Error"), MB_ICONERROR);
	//	return;
	//}


	DWORD oldp;
	VirtualProtectEx(MyProcessInfo.hProcess, (LPVOID)(dllnameptr), sizeof(g_DllName), PAGE_EXECUTE_READWRITE, &oldp);

    // write dllname to remote process
	DWORD written = 0;
	if (!WriteProcessMemory(MyProcessInfo.hProcess, (LPVOID)(dllnameptr), (void*)V(g_DllName), sizeof(g_DllName), &written) || written != sizeof(g_DllName))
	{
		TerminateProcess(MyProcessInfo.hProcess, 0);
		CloseHandle(MyProcessInfo.hProcess);
		CloseHandle(MyProcessInfo.hThread);
		//CloseHandle(phandle);
		MessageBoxA(0, V("Failed to write dllname to process."), V("Error"), MB_ICONERROR);
		return;
	}

	VirtualProtectEx(MyProcessInfo.hProcess, (LPVOID)(dllnameptr), sizeof(g_DllName), oldp, &oldp);

	
	char mtx[256];
	sprintf(mtx, V("TeknoMW3%08X"), MyProcessInfo.dwProcessId ^ 0x57);
	OutputDebugStringA(mtx);
	HANDLE hMutex = CreateMutexA(0, true, mtx);
	if (hMutex == NULL)
	{
		TerminateProcess(MyProcessInfo.hProcess, 0);
		CloseHandle(MyProcessInfo.hProcess);
		CloseHandle(MyProcessInfo.hThread);
		return;
	}
	ResumeThread(MyProcessInfo.hThread);


	while (true) Sleep(1);

	TerminateProcess(MyProcessInfo.hProcess, 0);


	
	CloseHandle(hMutex);
	CloseHandle(MyProcessInfo.hProcess);
	CloseHandle(MyProcessInfo.hThread);
	return;

	VE();
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR    lpCmdLine,
                     int       nCmdShow)
{
	if (CheckForNewVersion())
		return 0;

	if (strstr(lpCmdLine, V("-help")) != NULL)
	{
		MessageBoxA(0, V("Usage: Please put this exe and TeknoMW3.dll to your Modern Warfare 3\ndirectory and launch using any parameters you would normally use\nfor 'iw5mp_server.exe', for example:\n\n\"iw5mp_server.exe\" +dedicated 1 +set net_port 1337 +start_map_rotate"), V("Help"), MB_ICONINFORMATION);
	}
	else
	{
		StartProcessWithTeknoDll(V(g_DediExeName), lpCmdLine);
	}
}


#pragma optimize("", on)