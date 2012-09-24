#include <windows.h>
#include <stdio.h>

//bool (PFN_3DES_ENCRYPT*)(void* Iv, void* pBufferIn, void* pBufferOut, DWORD BufferSize);
//bool (PFN_3DES_DECRYPT*)(void* Iv, void* pBufferIn, void* pBufferOut, DWORD BufferSize);

PVOID g_encrypt = NULL;
PVOID g_decrypt = NULL;

static int LOG_NUM = 0;

char sDec[4] = "In";
char sEnc[4] = "Out";

enum msg_type {  MSG_DEC, MSG_ENC } ;

char * GetDumpFileName(int type)
{
	char * name = new char [100];
	char * t = sEnc;
	if (type == MSG_DEC) t = sDec;
	
	sprintf(name, ".\\PacketLogs\\%04X_%s.bin", LOG_NUM, t);

	++LOG_NUM;

	return name;
}

void DumpMsgToFile(void * data, int len, int type)
{
	FILE * outf = fopen(GetDumpFileName(type), "w+b");

	if (outf != NULL)
	{
		fwrite(data, 1, len, outf);
		fclose(outf);
	}
}

char GetPrintableChar(BYTE c)
{
	if ((c >= 0x20) && (c <= 0x7E))
		return c;
	else
		return 0x2e;
}


void BytesToCharLine(char * DstBuf, BYTE * ptr, int count, int max_count)
{
	char * HEX_BYTES_PTR = DstBuf;

	for (int i = 0; i < max_count; i++)
	{
		if (i >= count)
			HEX_BYTES_PTR += sprintf(HEX_BYTES_PTR, "   ");
		else
			HEX_BYTES_PTR += sprintf(HEX_BYTES_PTR, " %02X", ptr[i]);
	}

	HEX_BYTES_PTR += sprintf(HEX_BYTES_PTR, "   ");

	for (int i = 0; i < count; i++)
	{
			HEX_BYTES_PTR += sprintf(HEX_BYTES_PTR, "%c", GetPrintableChar(ptr[i]));
	}
}

void PrintBuffer(BYTE * ptr, int size, int bytes_per_line)
{
	char NEW_LINE[4096];

	int left_overs = size % bytes_per_line;

	for (int i = 0; i < (size/bytes_per_line); i++)
	{
		memset(NEW_LINE, 0, 4096);
		BytesToCharLine(NEW_LINE, (BYTE *)((DWORD)ptr + i*bytes_per_line), bytes_per_line, bytes_per_line);
		OutputDebugStringA(NEW_LINE);
	}

	if (left_overs != 0)
	{
		memset(NEW_LINE, 0, 4096);
		BytesToCharLine(NEW_LINE, (BYTE *)((DWORD)ptr + (size-left_overs)), left_overs, bytes_per_line);
		OutputDebugStringA(NEW_LINE);
	}
}




bool __stdcall TripleDesDecrypt(void* Iv, void* pBufferIn, void* pBufferOut, DWORD BufferSize)
{
	//MessageBoxA(0,0,0,0);
	DWORD thisptr = 0;
	_asm{ mov thisptr, ecx };
	//memcpy(pBufferOut, pBufferIn, BufferSize);

	_asm {
		mov eax, BufferSize
		push eax
		mov eax, pBufferOut
		push eax
		mov eax, pBufferIn
		push eax
		mov eax, Iv
		push eax
		mov eax, g_decrypt
		mov ecx, thisptr
		call eax
	};

	char * msg = new char[1024];
	unsigned char* p = (unsigned char*)pBufferOut;
	sprintf(msg, "TripleDesDecrypt %d bytes", BufferSize);
	OutputDebugString(msg);
	PrintBuffer(p, BufferSize, 16);
	DumpMsgToFile(p, BufferSize, MSG_DEC);
	delete[] msg;

	return true;
}

bool __stdcall TripleDesEncrypt(void* Iv, void* pBufferIn, void* pBufferOut, DWORD BufferSize)
{
	//MessageBoxA(0,0,0,0);
	//memcpy(pBufferOut, pBufferIn, BufferSize);

	DWORD thisptr = 0;
	_asm{ mov thisptr, ecx };


	char * msg = new char[1024];
	unsigned char* p = (unsigned char*)pBufferIn;
	sprintf(msg, "TripleDesEncrypt %d bytes", BufferSize);
	OutputDebugString(msg);
	PrintBuffer(p, BufferSize, 16);
	DumpMsgToFile(p, BufferSize, MSG_ENC);
	delete[] msg;


	_asm {
		mov eax, BufferSize
		push eax
		mov eax, pBufferOut
		push eax
		mov eax, pBufferIn
		push eax
		mov eax, Iv
		push eax
		mov eax, g_encrypt
		mov ecx, thisptr
		call eax
	};
	return true;
}

bool isOurMPProcess()
{
	char file_path[MAX_PATH];
	GetModuleFileName(NULL, file_path, MAX_PATH);
	OutputDebugString(file_path);
	/*for(int i=0; i < strlen(file_path); i++)
	{
		file_path[i] = _tolower(file_path[i]);
	}
	*/
	
	if(strstr(file_path, "iw5mp.exe") == NULL)
	{
		return false;
	}

	return true;
}

bool isOurDEDIProcess()
{
	char file_path[MAX_PATH];
	GetModuleFileName(NULL, file_path, MAX_PATH);
	OutputDebugString(file_path);
	/*for(int i=0; i < strlen(file_path); i++)
	{
		file_path[i] = _tolower(file_path[i]);
	}
	*/
	
	if(strstr(file_path, "iw5mp_server") == NULL)
	{
		return false;
	}

	return true;
}

static bool inited = false;




DWORD WINAPI test_thread(LPVOID lpParameter)
{
	int i = 0;
	while (1)
	{
		Sleep(1000);
		i++;
		if (i == 5)
		{
			char mtx[256];
			sprintf(mtx, "TeknoPDump%08X", GetCurrentProcessId() ^ 0x80);
			CreateMutexA(0, true, mtx);
			OutputDebugString("dll loaded!!! :D");
			LoadLibraryA("teknomw3.dll");

		}
	}
}





BOOL APIENTRY DllMain(
					  HANDLE hModule,	// Handle to DLL module
					  DWORD ul_reason_for_call,
					  LPVOID lpReserved ) // Reserved
{
	switch ( ul_reason_for_call )
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:

		if (!inited)
		{
			inited = true;
			//A process is loading the DLL.
			if(isOurMPProcess())
			{
				OutputDebugString("Our Process detected!!! :D");
				DWORD* foo = (DWORD*)0x08555B4; //0x00852AB4;
				g_encrypt = (PVOID)foo[0];
				g_decrypt = (PVOID)foo[1];
				DWORD oldProtect = 0;
				VirtualProtect(foo, 8, PAGE_READWRITE, &oldProtect);
				foo[0] = (DWORD)TripleDesEncrypt;
				foo[1] = (DWORD)TripleDesDecrypt;
				VirtualProtect(foo, 8, oldProtect, &oldProtect);
			}
			else if(isOurDEDIProcess())
			{
				OutputDebugString("Our Process detected!!! :D");
				DWORD* foo = (DWORD*)0x0070B6B4;
				g_encrypt = (PVOID)foo[0];
				g_decrypt = (PVOID)foo[1];
				DWORD oldProtect = 0;
				VirtualProtect(foo, 8, PAGE_READWRITE, &oldProtect);
				foo[0] = (DWORD)TripleDesEncrypt;
				foo[1] = (DWORD)TripleDesDecrypt;
				VirtualProtect(foo, 8, oldProtect, &oldProtect);
			}
			else
			{
				return FALSE;
			}

			//DWORD oldProtect = 0;
			//DWORD* foo = (DWORD*)0x400000;
			//VirtualProtect(foo, 8, PAGE_READWRITE, &oldProtect);
			//memcpy((void*)0x400000, "TK", 2);
			//VirtualProtect(foo, 8, oldProtect, &oldProtect);

			//OutputDebugString("Our Process detected!!! :D");
			//CreateThread(NULL, 0, test_thread, 0, 0, NULL);
			return true;
		}
		break;
	case DLL_THREAD_DETACH:
		// A thread exits normally.
		break;
	case DLL_PROCESS_DETACH:
		// A process unloads the DLL.
		break;
	}
	return TRUE;
}


int main( int argc, const char* argv[] )
{
	//Build as EXE to use these tests.
	char testline[200] = "11111111111111112222222222222222dddddddddddddddd1";
	PrintBuffer((BYTE *)testline, strlen(testline), 16);

	printf("Log file (in):  %s\n", GetDumpFileName(MSG_DEC));
	printf("Log file (out): %s\n", GetDumpFileName(MSG_ENC));

	DumpMsgToFile(testline, strlen(testline), MSG_DEC);
}