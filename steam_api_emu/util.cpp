#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <string>
#include "Wininet.h"
#include "Shellapi.h"
#include <winsock2.h>
#include "VMProtectSDK.h"
#include "version.h"
#include "util.h"
#include "util_ini.h"
#pragma comment(lib, "Wininet.lib")
#pragma comment(lib, "ws2_32.lib")
using namespace std;

BYTE lwr[256] = 
{
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,
	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,
	0x40,  'a',  'b',  'c',  'd',  'e',  'f',  'g',  'h',  'i',  'j',  'k',  'l',  'm',  'n',  'o',
	'p',  'q',  'r',  's',  't',  'u',  'v',  'w',  'x',  'y',  'z', 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,
	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,
	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F,
	0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F,
	0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F,
	0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF,
	0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF,
	0xC0, 0xC1, 0xC2, 0xC3,  'ä', 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF,
	0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5,  'ö', 0xD7, 0xD8, 0xD9, 0xDA, 0xDB,  'ü', 0xDD, 0xDE, 0xDF,
	0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF,
	0xF0, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF
};

char *strstrnocase(const char *string, const char *strSearch)
{
	DWORD matched = 0, i = 0;

	while(string[i] != 0)
	{
		if (lwr[(BYTE)string[i]] != lwr[(BYTE)strSearch[matched]]) matched = 0;
		if (lwr[(BYTE)string[i]] == lwr[(BYTE)strSearch[matched]]) if (strSearch[++matched] == 0) return (char *)&string[i - matched + 1];

		i++;
	}

	return NULL;
}

void info(const char *format, ...)
{
	#ifdef DEBUGGING_ENABLED
	//static HANDLE infoFile = INVALID_HANDLE_VALUE;
	//if (infoFile == INVALID_HANDLE_VALUE)
	//{
	//	static bool initialized = false;
	//	if (initialized)
	//		return;
	//	initialized = true;

	//	char path[1024];
	//	GetModuleFileNameA(NULL, path, sizeof(path));

	//	char infoName[1024];
	//	//sprintf(infoName, "%s_log_%08x.txt", path, GetCurrentProcessId());
	//	sprintf(infoName, "%s_log_%08x.txt", path, 0);

	//	infoFile = CreateFileA(infoName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	//	if (infoFile == INVALID_HANDLE_VALUE)
	//		return;
	//}

	char buf[1024 * 10];
	va_list marker;
	va_start(marker, format);
	DWORD len = vsprintf(buf, format, marker);
	va_end(marker);

	strcpy(buf + len, "\r\n");

	//DWORD written;
	//WriteFile(infoFile, buf, len + 2, &written, NULL);
	OutputDebugStringA(buf);
	//printf(buf);
	#endif
}

void infoCon(const char *format, ...)
{
	static HANDLE infoConH = INVALID_HANDLE_VALUE;
	if (infoConH == INVALID_HANDLE_VALUE)
	{
		static bool initializedConH = false;
		if (initializedConH)
			return;

		initializedConH = true;

		infoConH = GetStdHandle(STD_OUTPUT_HANDLE);
		if (infoConH == INVALID_HANDLE_VALUE)
			return;
	}

	char buf[1024 * 10];
	memset(buf, 0, sizeof(buf));
	va_list marker;
	va_start(marker, format);
	DWORD len = vsprintf(buf, format, marker);
	va_end(marker);

	//strcpy(buf + len, "\r\n");

	DWORD written;
	WriteFile(infoConH, buf, len, &written, NULL);
	//OutputDebugString(buf);
	//printf(buf);
}



bool isCharPrintable( const char _c )
{
	#ifdef DEBUGGING_ENABLED
	//if( isprint( _c ) )
	//{
		if( (_c >= ' ' && _c <= '~') )
		{
			return true;
		}
	//}
	#endif

	return false;
}

bool CreatePath(string &sPath)
{
	DWORD attr;
	int pos;
	bool result = true;

	// Check for trailing slash:
	pos = sPath.find_last_of('\\');
	if (sPath.length() == pos + 1)	// last character is "\"
	{
		sPath.resize(pos);
	}

	// Look for existing object:
	attr = GetFileAttributesA(sPath.c_str());
	if (0xFFFFFFFF == attr)	// doesn't exist yet - create it!
	{
		pos = sPath.find_last_of('\\');
		if (0 < pos)
		{
			// Create parent dirs:
			result = CreatePath(sPath.substr(0, pos));
		}
		// Create node:
		result = result && CreateDirectoryA(sPath.c_str(), NULL);
	}
	else if (FILE_ATTRIBUTE_DIRECTORY != attr)
	{	// object already exists, but is not a dir
		SetLastError(ERROR_FILE_EXISTS);
		result = false;
	}

	return result;
}

bool CreateFilePath(string &sPath)
{
	char * cstr = (char *)(sPath.c_str());

	for (int i=0; i<sPath.length(); i++)
	{
		if (cstr[i] == '/')
			cstr[i] = '\\';
	}

	string dname = cstr;

	//cut off file name from the path
	int pos = dname.find_last_of('\\');
	if (pos > 2)
	{
		dname.resize(pos);
	}

	return CreatePath(dname);
}


DWORD dw_swap(DWORD dw)
{
	return htonl(dw);
}

void LCase(char string[])
{
   int  i = 0;

   while ( string[i] )
   {
      string[i] = tolower(string[i]);
      i++;
   }

   return;
}

void DebugOutValue(char *title, DWORD value)
{
	#ifdef DEBUGGING_ENABLED
	char dbgout[255];
	sprintf_s(dbgout, sizeof(dbgout), "%s = %08x", title, value);
	OutputDebugStringA(dbgout);
	#endif
}
void DebugOutString(char *title, char *string)
{
	#ifdef DEBUGGING_ENABLED
	char dbgout[255];
	sprintf_s(dbgout, sizeof(dbgout), "%s: %s", title, string);
	OutputDebugStringA(dbgout);
	#endif
}

DWORD GetSectionSize(DWORD sect)
{
	int res = 0;
	__try  
	{
		__asm
		{
			push eax
			push ebx
			mov ebx, sect
			imul ebx, 0x28
			xor eax, eax
			//pointer to PE
			mov eax, [eax+0x3c+0x400000]
			//get virtual size of the .text section
			mov eax, [eax+0x100+ebx+0x400000]
			mov res, eax
			pop ebx
			pop eax
		}
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 13);
		#endif
	}
	return res;
}
DWORD GetSectionPtr(DWORD sect)
{
	int res = 0;
	__try  
	{
		__asm
		{
			push eax
			push ebx
			mov ebx, sect
			imul ebx, 0x28
			xor eax, eax
			//pointer to PE
			mov eax, [eax+0x3c+0x400000]
			//get virtual size of the .text section
			mov eax, [eax+0x104+ebx+0x400000]
			mov res, eax
			pop ebx
			pop eax
		}
	}
	__except ( EXCEPTION_EXECUTE_HANDLER )
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 14);
		#endif
	}
	return res;
}

bool FindHexString_Quiet = false;

int FindHexString(char *string, DWORD sect)
{
	int start = 0;
	int length = 0;

	if (sect < 10)
	{
		start = 0x400000 + GetSectionPtr(sect);
		length = GetSectionSize(sect);
	}
	else
	{
		start = sect;
		length = GetSectionSize(0) - (sect-0x401000);
	}

	int len = strlen(string) / 2;
	char bytemap[400][2];
	char cstr[200];
	int val, i, j;

	if (len > 199)
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutString("FindHexString() string too long", string);
		#endif
		return -1;
	}

	//convert string to 2 layer table with byte-values and byte-skips
	memset(bytemap,0,sizeof(bytemap));
	for (i = 0; i < len; i++)
	{
		val = 0;
		if (string[i*2] != '?')
		{
			sscanf_s((char*)(&string[i*2]), V("%02X"), &val);

			bytemap[i][0] = val & 0xFF;
			bytemap[i][1] = 1;
		}
		else
			bytemap[i][1] = 0;
	}

	//now find the converted pattern [start .. end]
	int matched = 0;
	for (i = 0; i < length; i++)
	{
		for (j=0; j<len; j++)
		{
			if (bytemap[j][1] == 0)
				matched++;
			else if ( *(BYTE *)(i+j+start) == (bytemap[j][0] & 0xFF))
				matched++;
			else
				break;
		}

		if (matched == len)
			return i+start;
		else
			matched = 0;
	}
	if (!FindHexString_Quiet)
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutString("FindHexString() string not found", string);
		DebugOutValue("Start used", start);
		DebugOutValue("Length used", length);
		#endif
	}
	return 0;
};

DWORD ConvertIPSTRtoDWORD(const char *ip)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	if (sscanf_s(ip, V("%d.%d.%d.%d"), &a, &b, &c, &d) == 4)
		return (d&0xFF)*0x1000000 ^ (c&0xFF)*0x10000 ^ (b&0xFF)*0x100 ^ (a&0xFF);

	return 0;
}


bool FileExists(const char * filename)
{
    if (FILE * file = fopen(filename, "r"))
    {
        fclose(file);
        return true;
    }
    return false;
}

DWORD HttpReadFile(char * url, char * buffer, DWORD buffer_size)
{
	memset(buffer, 0, buffer_size);
	DWORD dwBytesRead = 0;

	HINTERNET inet = InternetOpenA(V("MW3"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if	(inet <= 0)
	{
		return 0;         
	}


	DWORD var = 4000L; // millisec
	int b = InternetSetOption(inet, INTERNET_OPTION_CONNECT_TIMEOUT, (void *)&var, sizeof(var));
	b = InternetSetOption(inet, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT, (void *)&var, sizeof(var));
	b = InternetSetOption(inet, INTERNET_OPTION_DATA_SEND_TIMEOUT, (void *)&var, sizeof(var));
	b = InternetSetOption(inet, INTERNET_OPTION_SEND_TIMEOUT, (void	*)&var, sizeof(var));
	b = InternetSetOption(inet, INTERNET_OPTION_RECEIVE_TIMEOUT, (void *)&var, sizeof(var));
	var = 4; // Retries
	b = InternetSetOption(inet, INTERNET_OPTION_CONNECT_RETRIES, (void *)&var, sizeof(var));


	HINTERNET iurl = InternetOpenUrlA(inet, url, "", 0, INTERNET_FLAG_RELOAD, 0);
	if (iurl <= 0)
	{
		InternetCloseHandle(inet);
		return 0;         
	}

	if (InternetReadFile(iurl, buffer, buffer_size, &dwBytesRead))
	{
		InternetCloseHandle(iurl);
		InternetCloseHandle(inet);
		return dwBytesRead;
	}

	return 0;
}


bool CheckForNewVersion()
{
	char data[2048];

	if (HttpReadFile(V("http://teknogods.com:8080/updatecheck/?project=mw3"), data, sizeof(data)) == 0)
		return false;

	char * link = strstr(data, V(";"));
	if (link == NULL) return false;

	link[0] = 0;
	link++;

	char * term = strstr(link, V("\n"));
	if (term != NULL)
		term[0] = 0;

	info("link %s, ver %s", link, data);

	DWORD ver[4];
	if (sscanf(data, V("%d.%d.%d.%d"), &ver[0], &ver[1], &ver[2], &ver[3]) != 4)
		return 0;

	DWORD ver_f = ver[0] * 0x1000000 | ver[1] * 0x10000 | ver[2] * 0x100 | ver[3];

	info("ver_f = %08X", ver_f);

	if (ver_f > CURRENT_VER)
	{
		char msg[255];
		sprintf(msg, V("New version (v%s) is available. Download now?"), data);

		if (MessageBoxA(0, msg, V("Update notification"), MB_ICONINFORMATION | MB_YESNO) == IDYES)
		{
			ShellExecuteA(NULL, V("open"), link, NULL, NULL, SW_SHOWNORMAL);
			return true;
		}
	}

	return false;
}



DWORD FileTimeToUnixTime(const FILETIME *lpFileTime)
{
        return (DWORD)((((lpFileTime->dwHighDateTime<<32) + lpFileTime->dwLowDateTime) - 116444736000000000)/10000000);
}


bool parseIpPort(char* str, DWORD* ip, USHORT* port)
{
	DWORD ipAddr[4];
	DWORD tempPort;

	if (sscanf(str, V("%d.%d.%d.%d:%d"), &ipAddr[0], &ipAddr[1], &ipAddr[2], &ipAddr[3], &tempPort) == 5)
	{
		#ifdef DEBUGGING_ENABLED
		info("parseIpPort %08X %08X %08X %08X %08X", ipAddr[0], ipAddr[1], ipAddr[2], ipAddr[3], tempPort);
		#endif

		ip[0] = ipAddr[0]&0xFF ^ (ipAddr[1]&0xFF)*0x100 ^ (ipAddr[2]&0xFF)*0x10000 ^ (ipAddr[3]&0xFF)*0x1000000;
		port[0] = tempPort & 0xFFFF;
		return true;
	}

	char hostname[255];

	char * port_str = strstr(str, ":");
	if (port == NULL) return false;

	int len = (DWORD)port_str - (DWORD)str;
	if (len > 250) return false;

	memset(hostname, 0, 255);
	memcpy(hostname, str, len);

	info("host: %s, len: %d", hostname, len);

	if (sscanf(port_str, V(":%d"), &tempPort) == 1)
	{
		DWORD ip2 = GetHostIpByName(hostname);
		if (ip2 == 0) return false;

		ip[0] = ip2;
		port[0] = tempPort & 0xFFFF;
		return true;
	}

	return false;
}

void makeIPstr(DWORD ip, char * destBuff)
{
	sprintf(destBuff, "%d.%d.%d.%d", ip&0xFF, (ip>>8)&0xFF, (ip>>16)&0xFF, (ip>>24)&0xFF);
}


bool charToDword(char* str, DWORD* out_dw)
{
	DWORD dwResult = 0;	

	int ret = sscanf(str, "%X", &dwResult);

	if (ret == 1)
	{
		out_dw[0] = dwResult;
		return true;
	}

	return false;
}

DWORD GetHostIpByName(char * host_name)
{
	struct hostent *remoteHost;
	struct in_addr addr;
    //int iResult;
    DWORD dwError;
    int i = 0;
	char **pAlias;

	remoteHost = gethostbyname(host_name);
    if (remoteHost == NULL) {
        dwError = WSAGetLastError();
        if (dwError != 0) {
            if (dwError == WSAHOST_NOT_FOUND) {
                info("GetHostIpByName() Host not found\n");
                return 0;
            } else if (dwError == WSANO_DATA) {
                info("GetHostIpByName() No data record found\n");
                return 0;
            } else {
                info("GetHostIpByName() Function failed with error: %ld\n", dwError);
                return 0;
            }
        }
    } else {
        info("GetHostIpByName() Function returned:\n");
        info("GetHostIpByName() \tOfficial name: %s\n", remoteHost->h_name);
        for (pAlias = remoteHost->h_aliases; *pAlias != 0; pAlias++) {
            info("GetHostIpByName() \tAlternate name #%d: %s\n", ++i, *pAlias);
        }
        info("GetHostIpByName() \tAddress type: ");
        switch (remoteHost->h_addrtype) {
        case AF_INET:
            info("GetHostIpByName() AF_INET\n");
            break;
        case AF_NETBIOS:
            info("GetHostIpByName() AF_NETBIOS\n");
            break;
        default:
            info("GetHostIpByName()  %d\n", remoteHost->h_addrtype);
            break;
        }
        info("GetHostIpByName() \tAddress length: %d\n", remoteHost->h_length);

        i = 0;
        if (remoteHost->h_addrtype == AF_INET)
        {
            while (remoteHost->h_addr_list[i] != 0) {
                addr.s_addr = *(u_long *) remoteHost->h_addr_list[i++];
                info("GetHostIpByName() \tIP Address #%d: %s\n", i, inet_ntoa(addr));

				return addr.s_addr;
            }
        }
        else if (remoteHost->h_addrtype == AF_NETBIOS)
        {   
            info("GetHostIpByName() NETBIOS address was returned\n");
        }   
    }

    return 0;

}





NET_ADDRESS_LIST g_IpList;
int g_DefaultInterface = 0;
PNET_ADDRESS_LIST EnumNetworkAdapters()
{
	memset(&g_IpList, 0, sizeof(g_IpList));

	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);

	DWORD retLen = 0;
	DWORD res = WSAIoctl(sock, SIO_ADDRESS_LIST_QUERY, NULL, 0, &g_IpList, 
		sizeof(g_IpList), &retLen, NULL, NULL);
	
	for (DWORD i = 0; i < g_IpList.iAddressCount; ++i)
	{
		const sockaddr_in *addr = (sockaddr_in *)g_IpList.Address[i].lpSockaddr;
		const char *ip = inet_ntoa(addr->sin_addr);

		#ifdef DEBUGGING_ENABLED
		info("ip %s", ip);
		#endif
	}

	closesocket(sock);

	return &g_IpList;
}




// advanced way of getting the ip's of all adapters -- not needed
//
//#include <iphlpapi.h>
//#pragma comment(lib, "IPHLPAPI.lib")
//#define WORKING_BUFFER_SIZE 15000
//
//
//int EnumNetworkAdapters_Adv()
//{	EnumBla();
//	
//	memset(&IpList, 0, sizeof(LULZ_SOCKET_ADDRESS_LIST));
//	
//	ULONG outBufLen = WORKING_BUFFER_SIZE;
//	DWORD dwRetVal = 0;
//    PIP_ADAPTER_ADDRESSES pAddresses = NULL;
//    DWORD dwSize = 0;
//    PIP_ADAPTER_ADDRESSES pCurrAddresses = NULL;
//    PIP_ADAPTER_UNICAST_ADDRESS pUnicast = NULL;
//
//    pAddresses = (IP_ADAPTER_ADDRESSES *)malloc(WORKING_BUFFER_SIZE);
//    if (pAddresses == NULL)
//	{
//        info("Memory allocation failed for IP_ADAPTER_ADDRESSES struct\n");
//		free(pAddresses);
//		return 0;
//    }
//
//    dwRetVal = GetAdaptersAddresses(AF_INET, GAA_FLAG_INCLUDE_PREFIX, NULL, pAddresses, &outBufLen);
//
//    if (dwRetVal == ERROR_BUFFER_OVERFLOW)
//	{
//		free(pAddresses);
//		return 0;
//    }
//
//    if (dwRetVal == NO_ERROR)
//	{
//        // If successful, output some information from the data we received
//        pCurrAddresses = pAddresses;
//        while (pCurrAddresses)
//		{
//            info("\tDescription: %wS\n", pCurrAddresses->Description);
//
//            pUnicast = pCurrAddresses->FirstUnicastAddress;
//            if (pUnicast != NULL)
//			{
//                for (int i = 0; pUnicast != NULL; i++)
//                {
//
//                    sockaddr_in *sa_in = (sockaddr_in *)pUnicast->Address.lpSockaddr;
//					info("IPV4: %08X", sa_in->sin_addr.S_un.S_addr);
//					IpList.iAddressCount++;
//					*IpList.Address = pUnicast->Address;
//
//                    pUnicast = pUnicast->Next;
//                }
//            }
//            pCurrAddresses = pCurrAddresses->Next;
//        }
//		free(pAddresses);
//		return IpList.iAddressCount;
//	}
//	free(pAddresses);
//	return 0;
//}


DWORD ExternalIP = 0;

#pragma optimize("", off)

DWORD GetInternalIP()
{
	//char ac[80];
	//if (gethostname(ac, sizeof(ac)) == SOCKET_ERROR) {
	//	info("Error %d when getting local host name.", WSAGetLastError());
	//}
	//info("Computer name is: %s", ac);

	//struct hostent *phe = gethostbyname(ac);
	//if (phe == 0) {
	//	info("Yow! Bad host lookup.");
	//	return 0;
	//}

	//for (int i = 0; phe->h_addr_list[i] != 0; ++i) {
	//	struct in_addr addr;
	//	memcpy(&addr, phe->h_addr_list[i], sizeof(struct in_addr));
	//	info("Address %d : %s", i, inet_ntoa(addr));

	//	return addr.S_un.S_addr;
	//}

	if (g_IpList.iAddressCount > 0 && g_DefaultInterface < g_IpList.iAddressCount)
	{
		sockaddr_in * addr = (sockaddr_in *)g_IpList.Address[g_DefaultInterface].lpSockaddr;
		info("Address %d : %s", g_DefaultInterface, inet_ntoa(addr->sin_addr));
		return addr->sin_addr.S_un.S_addr;
	}

	return INADDR_ANY;
}


void SetExternalIP(DWORD ip)
{
	#ifdef DEBUGGING_ENABLED
	char ipb[255];
	makeIPstr(ip, ipb);

	info("SetExternalIP() Setting IP to %s", ipb);
	#endif

	ExternalIP = ip;
}

DWORD GetExternalIP(bool bswap, char * local)
{	VM("GetExternalIP");

	if (ExternalIP != 0 && local == NULL)
	{
		if (bswap)
			return htonl(ExternalIP);
		else
			return ExternalIP;
	}
	else
	{
		char ipbuf[256];
		DWORD fsize = 0;

		if (local != NULL)
		{
			fsize = strlen(local);
			if (fsize < 20)
				strcpy(ipbuf, local);
			else
				fsize = 0;
		}
		else
		{
			fsize = 0;
		}


		if ((fsize != 0) && (fsize <= 20))
		{
			ExternalIP = ConvertIPSTRtoDWORD(ipbuf);

			#ifdef DEBUGGING_ENABLED
			char ipb[255];
			makeIPstr(ExternalIP, ipb);

			info("GetExternalIP() success! Setting IP to %s", ipb);
			#endif
		}
		else
		{
			#ifdef DEBUGGING_ENABLED
			OutputDebugStringA("GetExternalIP() failed! Setting loopback IP (127.0.0.1)");
			#endif

			ExternalIP = GetInternalIP();
			if (ExternalIP == 0) ExternalIP = 0x0100007F;
		}

		return GetExternalIP(bswap);
	}

	VE();
}
#pragma optimize("", on)




char GetPrintableChar(BYTE c)
{
	if (isCharPrintable(c))
		return c;
	else
		return 0x2e;
}


void BytesToCharLine(char * DstBuf, BYTE * ptr, int count, int max_count)
{
	#ifdef DEBUGGING_ENABLED
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
	#endif
}

void PrintBuffer(BYTE * ptr, int size, int bytes_per_line)
{
	#ifdef DEBUGGING_ENABLED
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
	#endif
}



DWORD GetCRC32(void* pData, const int length)
{
	DWORD _crc = 0xFFFFFFFF;
    unsigned char* pCur = (unsigned char*)pData;
    int remaining = length;
    for (; remaining--; ++pCur)
        _crc = ( _crc >> 8 ) ^ kCrc32Table[(_crc ^ *pCur) & 0xff];

	return _crc ^ 0xFFFFFFFF;
}