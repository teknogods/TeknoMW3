//
// Developed by Fahister Group Projects 
// http://code.google.com/p/fahister/source/browse/trunk/tbmessage/src/Libraries/MachineCode/HwInfo.cpp?r=90
// Slightly modded by TeknoGods Team
//

#include "StdAfx.h"
#include "util_smbios2.h"
#include "util.h"
#include "VMProtectSDK.h"

#pragma optimize("", off)

int WinxpSMBiosReader::Checksum(const BYTE *buf, int len)
{	VM("WinxpSMBiosReader::Checksum");

	BYTE sum = 0;

	for (int i = 0; i < len; i++)
		sum += buf[i];

	return sum;

	VE();
}

#define WINXP_LOWMEM_MAX_LEN 0x100000
#define WINXP_LOWMEM_OPT_START_ADDR 0xF0000
#define WINXP_LOWMEM_OPT_LEN WINXP_LOWMEM_MAX_LEN-WINXP_LOWMEM_OPT_START_ADDR

BYTE* WinxpSMBiosReader::GetSMBiosRawData(DWORD& size)
{	VM("WinxpSMBiosReader::GetSMBiosRawData");

    BYTE* result = NULL;
	size = 0;

    BYTE *mem = (BYTE *)malloc(WINXP_LOWMEM_OPT_LEN);
    win_dump_mem(mem, WINXP_LOWMEM_OPT_START_ADDR, WINXP_LOWMEM_OPT_LEN);
    
    for (int offset = WINXP_LOWMEM_OPT_LEN-0x10000; offset <= WINXP_LOWMEM_OPT_LEN; offset += 16)
	{
		if (memcmp(mem + offset, "_SM_", 4) == 0 && offset <= WINXP_LOWMEM_OPT_LEN)
		{
            if (Checksum(mem + offset, *(mem + offset + 5)) == 0)
            {
                SMBIOSEntryPoint *entryPoint = (SMBIOSEntryPoint *)(mem + offset);

                // decode smbios entry point structure
                WORD len = entryPoint->totalStructureLength;
                DWORD startAddress = entryPoint->structureAddress;
				size = 0;
				result = 0;

				if (startAddress > WINXP_LOWMEM_OPT_START_ADDR && startAddress+len < WINXP_LOWMEM_MAX_LEN)
				{
					__try  
					{
						info("SMBIOS structure was in bounds.");

						DWORD addressOffset = startAddress - WINXP_LOWMEM_OPT_START_ADDR;

						BYTE *buf = (BYTE *)malloc(len+100);
						memcpy(buf, mem + addressOffset, len);
						size = len;
						result = buf;
						break;
					}
					__except ( EXCEPTION_EXECUTE_HANDLER )
					{
						#ifdef DEBUGGING_ENABLED
						info("Exception while reading SMBIOS (1)");
						#endif
					}
				}
				else
				{
					__try  
					{
						info("SMBIOS structure was out of bounds. Reading it directly.");

						free(mem);
						mem = (BYTE *)malloc(WINXP_LOWMEM_MAX_LEN-0x10000);
						win_dump_mem(mem, 0x10000, WINXP_LOWMEM_MAX_LEN-0x10000);

						if (startAddress > 0x10000 && startAddress+len < WINXP_LOWMEM_MAX_LEN)
						{
							DWORD addressOffset = startAddress - 0x10000;

							BYTE *buf = (BYTE *)malloc(len+100);
							memcpy(buf, mem + addressOffset, len);

							size = len;
							result = buf;
							break;
						}
					}
					__except ( EXCEPTION_EXECUTE_HANDLER )
					{
						#ifdef DEBUGGING_ENABLED
						info("Exception while reading SMBIOS (2)");
						#endif
					}
				}
            }
		}
	}
    free(mem);
    return result;

	VE();
}

BOOL WinxpSMBiosReader::LocateNtdllEntryPoints()
{	VM("WinxpSMBiosReader::LocateNtdllEntryPoints");

	if (NtOpenSection != NULL) return true;

    HINSTANCE hMoudle1 = LoadLibraryA(V("ntdll.dll"));
    if (hMoudle1 == NULL)
    {
        return FALSE;
    }
    
    NtOpenSection = (NtOpenSectionProc)GetProcAddress(hMoudle1, V("ZwOpenSection") );
     
    NtMapViewOfSection = (NtMapViewOfSectionProc) GetProcAddress(hMoudle1, V("ZwMapViewOfSection") );
    
    NtUnmapViewOfSection = (NtUnmapViewOfSectionProc) GetProcAddress(hMoudle1, V("ZwUnmapViewOfSection") );

    RtlInitUnicodeString = (RtlInitUnicodeStringProc) GetProcAddress(hMoudle1, V("RtlInitUnicodeString") );

    RtlNtStatusToDosError = (RtlNtStatusToDosErrorProc) GetProcAddress(hMoudle1, V("RtlNtStatusToDosError") );
    
	return TRUE;

	VE();
}

//void WinxpSMBiosReader::PrintError(char *message, long status)
//{
//	#ifdef DEBUGGING_ENABLED
//	char *errMsg;
//
//	FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
//			NULL, RtlNtStatusToDosError( status ), 
//			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), 
//			(LPTSTR) &errMsg, 0, NULL );
//	info("%s: %s\n", message, errMsg );
//	LocalFree( errMsg );
//	#endif
//}

HANDLE WinxpSMBiosReader::OpenPhysicalMemory()
{	VM("WinxpSMBiosReader::OpenPhysicalMemory");

	long		status;
	HANDLE			physmem;
	UNICODE_STRING	physmemString;
	OBJECT_ATTRIBUTES attributes;
	WCHAR			physmemName[] = L"\\device\\physicalmemory";

	RtlInitUnicodeString( &physmemString, physmemName );	

	InitializeObjectAttributes( &attributes, &physmemString,
								0x00000040L, NULL, NULL );			
	status = NtOpenSection( &physmem, SECTION_MAP_READ, &attributes );

	if( !NT_SUCCESS( status ))
	{
		info("Could not open \\device\\physicalmemory -> %08X", status );
		return NULL;
	}

	return physmem;

	VE();
}

BOOL WinxpSMBiosReader::MapPhysicalMemory( HANDLE PhysicalMemory,PDWORD Address, PDWORD Length,PDWORD VirtualAddress )
{	VM("WinxpSMBiosReader::MapPhysicalMemory");
    
	long			ntStatus;
	LARGE_INTEGER	viewBase;

	*VirtualAddress = 0;
	viewBase.QuadPart = (ULONGLONG) (*Address);
	ntStatus = NtMapViewOfSection (PhysicalMemory,
                               (HANDLE) -1,
                               (PVOID*) VirtualAddress,
                               0L,
                               *Length,
                               &viewBase,
                               Length,
                               1,
                               0,
                               PAGE_READONLY );

	if( !NT_SUCCESS( ntStatus ))
	{
		info("Could not map view of %X length %X", *Address, *Length );
		return FALSE;					
	}

	*Address = viewBase.LowPart;
	return TRUE;

	VE();
}

void WinxpSMBiosReader::UnmapPhysicalMemory(DWORD Address)
{	VM("WinxpSMBiosReader::UnmapPhysicalMemory");
	long status;

	status = NtUnmapViewOfSection( (HANDLE) -1, (PVOID) Address );
	if( !NT_SUCCESS(status))
	{
		info("Unable to unmap view %08X", status );
	}

	VE();
}

void WinxpSMBiosReader::win_dump_mem(BYTE *buf, size_t base, size_t len)
{	VM("WinxpSMBiosReader::win_dump_mem");

    LocateNtdllEntryPoints();//×÷ÓÃ??

	size_t mmoffset;
	SYSTEM_INFO sysinfo;
	HANDLE	physmem;
	DWORD paddress, vaddress, length;
    	
	//
	// Open physical memory
	//
	if( !(physmem = OpenPhysicalMemory())) {
		return;
	}

	GetSystemInfo(&sysinfo);
	mmoffset = base%sysinfo.dwPageSize;
	len += mmoffset;
    
	paddress = (DWORD)base;
	length = (DWORD)len;
	if(!MapPhysicalMemory( physmem, &paddress, &length, &vaddress )){
	    //free(p);
	    return;
	}
    
	//if((p=(BYTE*)malloc(length))==NULL){
	//	return NULL;
	//}
        
	memcpy(buf, (BYTE *)vaddress + mmoffset, length - mmoffset); 
    
	//
	// Unmap the view
	//
	UnmapPhysicalMemory( vaddress );  
	
	//
	// Close physical memory section
	//
	CloseHandle( physmem );	

	VE();
}


BYTE * Win2k3SMBiosReader::GetSMBiosRawData(DWORD& size)
{	VM("Win2k3SMBiosReader::GetSMBiosRawData");

    HINSTANCE hMoudle1 = GetModuleHandleA(V("kernel32.dll"));
    if (hMoudle1 == NULL)
    {
        info("failed to load library kernel32.dll");
		size = 0;
        return NULL;
    }
    
    GetSMBiosTable = (GetSMBiosTableProc)GetProcAddress(hMoudle1,V("GetSystemFirmwareTable"));

    int size1 = GetSMBiosTable('RSMB', 0, NULL, 0);
    if (size1 == 0)
    {
		size = 0;
        return NULL;
    }

    RawSMBIOSData *pRawSMBiosData = (RawSMBIOSData*)malloc(size1);
    GetSMBiosTable('RSMB', 0, pRawSMBiosData, size1);

    size = pRawSMBiosData->Length;
    return (BYTE *)pRawSMBiosData;

	VE();
}

//CHwInfo::CHwInfo(BYTE* buf, int size)
//{
//    m_pBufBios = buf;
//    m_nBufSize = size;
//}

CHwInfo::CHwInfo()
{
    m_pBufBios = 0;
    m_nBufSize = 0;
}

CHwInfo::~CHwInfo()
{
    if (m_pBufBios != NULL)
		free(m_pBufBios);
	m_nBufSize = 0;
}

BYTE* CHwInfo::GetSMBiosStructure(BYTE type, DWORD& size)
{	VM("GetFirstStructure");

    BYTE *p = m_pBufBios;

    while (p - m_pBufBios < m_nBufSize)
    {
        SMBiosStructHeader *header = (SMBiosStructHeader *)p;

        p += header->length;

        while (TRUE)
        {
            BYTE SEPARATOR[2] = {0x00,0x00};

            if (memcmp(p, SEPARATOR, 2) == 0)
            {
                p = p + 2;
                break;
            }
                
            p++;
        }

        if (header->type == type)
		{	
			size = p - (BYTE*)header - 1;
            return (BYTE*)header;
		}
    }

	size = 0;
    return NULL;

	VE();
}


//// read the string from the structure
////   the start address of the smbios structure
////   index is the string index base 1
//char* CHwInfo::GetString(SMBiosStructHeader *structHeader, int index)
//{
//    //BYTE *p = (BYTE *)structHeader;
//    BYTE *p = (BYTE *)structHeader;
//    int savIndex = index;
//    p += structHeader->length;
//
//    int i = 1;
//    while (i++ < index)
//    {
//        while (*p != 0)
//        {
//            p++;            
//        }
//        p++;
//
//    }
//    return (char*)p;
//}

BOOL CHwInfo::IsWin2k3OrLater()
{    
    OSVERSIONINFO version;
    version.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&version);
   
    switch(version.dwPlatformId){        
        case VER_PLATFORM_WIN32_NT:
            if((version.dwMajorVersion >= 6) || (version.dwMajorVersion = 5 && version.dwMinorVersion >= 2)){
                return TRUE;
            }else{
                return FALSE;
            }            
        break;
        
        default:
        break;
    }
    return FALSE;
}

bool CHwInfo::GetSMBiosData()
{	VM("CHwInfo::GetSMBiosData");

    BOOL bIs2k3 = IsWin2k3OrLater();
	DWORD size = 0;

	if (m_pBufBios) 
	{
		free(m_pBufBios);
		m_pBufBios = NULL;
	}

    if (bIs2k3)
    {
        Win2k3SMBiosReader *reader = new Win2k3SMBiosReader();
        m_pBufBios = reader->GetSMBiosRawData(size);
    }
    else
    {
        WinxpSMBiosReader *reader = new WinxpSMBiosReader();
        m_pBufBios = reader->GetSMBiosRawData(size);
    }

	if (size > 4 && m_pBufBios != NULL)
	{
		m_nBufSize = size;
		return true;
	}

	return false;

	VE();
}

//
//CString CHwInfo::GetMahineUuid()
//{
//    CString szUuid("");
//    SMBiosStructHeader* structEnclosure = GetFirstStructure(1);
//    
//    BYTE arrUuid[16];
//    memcpy(arrUuid, structEnclosure->data + 4, 16);
//
//    for (int i = 0; i < 16; i++)
//    {
//        szUuid.AppendFormat("%02X", arrUuid[i]);
//        if ((i+1)%4 == 0 && i < 15)
//        {
//            szUuid.Append("-");
//        }
//    }
//
//    return szUuid;
//}
//
//CString CHwInfo::GetMachineSn()
//{
//    CString szSN("");
//    SMBiosStructHeader* structEnclosure = GetFirstStructure(1);
//    int snIndex = structEnclosure->data[3];
//    szSN = GetString(structEnclosure, snIndex);
//
//    return szSN;
//}


#pragma optimize("", on)