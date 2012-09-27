//
// Developed by Fahister Group Projects 
// http://code.google.com/p/fahister/source/browse/trunk/tbmessage/src/Libraries/MachineCode/HwInfo.cpp?r=90
// Slightly modded by TeknoGods Team
//


#pragma once
#include <atlstr.h>

typedef struct _UNICODE_STRING {
  USHORT  Length;//长溔
  USHORT  MaximumLength;//最大长溔
  PWSTR  Buffer;//澓存指针∶问物理内存使此磳指向UNICODE字←磶"\device\physicalmemory"
} UNICODE_STRING,*PUNICODE_STRING;


typedef struct _OBJECT_ATTRIBUTES {
    ULONG Length;//长溔 18h
    HANDLE RootDirectory;//  00000000
    PUNICODE_STRING ObjectName;//指向溤象名灸指针
    ULONG Attributes;//溤象属性00000040h
    PVOID SecurityDescriptor;        // Points to type SECURITY_DESCRIPTOR0
    PVOID SecurityQualityOfService;  // Points to type SECURITY_QUALITY_OF_SERVICE0
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

#define InitializeObjectAttributes( p, n, a, r, s ) { \
    (p)->Length = sizeof( OBJECT_ATTRIBUTES );          \
    (p)->RootDirectory = r;                             \
    (p)->Attributes = a;                                \
    (p)->ObjectName = n;                                \
    (p)->SecurityDescriptor = s;                        \
    (p)->SecurityQualityOfService = NULL;               \
    }

#define NT_SUCCESS(Status) ((long)(Status) >= 0)

typedef long (__stdcall *NtOpenSectionProc)(OUT PHANDLE  SectionHandle,
                    IN ACCESS_MASK  DesiredAccess,
                    IN POBJECT_ATTRIBUTES  ObjectAttributes);

typedef long (__stdcall *NtMapViewOfSectionProc)(IN HANDLE  SectionHandle,    
                              IN HANDLE  ProcessHandle,    
                              IN OUT PVOID  *BaseAddress,    
                              IN ULONG_PTR  ZeroBits,    
                              IN SIZE_T  CommitSize,    
                              IN OUT PLARGE_INTEGER  SectionOffset  OPTIONAL,    
                              IN OUT PSIZE_T  ViewSize,    
                              IN ULONG  InheritDisposition,    
                              IN ULONG  AllocationType,    
                              IN ULONG  Win32Protect );

typedef long (__stdcall*NtUnmapViewOfSectionProc)(IN HANDLE  ProcessHandle,
                           IN PVOID  BaseAddress);

typedef void (__stdcall *RtlInitUnicodeStringProc)(
		IN OUT PUNICODE_STRING  DestinationString,
		IN PCWSTR  SourceString
		);

typedef ULONG (__stdcall *RtlNtStatusToDosErrorProc) (
		IN long Status
		);

typedef struct tagSMBIOSEntryPoint
{
    char anchorString[4];
    BYTE checkSum;
    BYTE entryLength;
    BYTE majorVersion;
    BYTE minorVersion;
    WORD maxSize;
    BYTE entryPointRevision;
    char formattedArea[5];
    char intermediaAncharString[5];
    BYTE intermediaChecksum;
    WORD totalStructureLength;
    DWORD structureAddress;
    WORD numberofStructuress;
    BYTE bcdRevision;
} SMBIOSEntryPoint, *PSMBIOSEntryPoint;

class WinxpSMBiosReader
{
public:
    WinxpSMBiosReader(){ NtOpenSection = NULL; }
    ~WinxpSMBiosReader(){}

    BYTE * GetSMBiosRawData(DWORD& size);
private:
    BOOL LocateNtdllEntryPoints();
    HANDLE OpenPhysicalMemory();
    BOOL MapPhysicalMemory( HANDLE PhysicalMemory,
							PDWORD Address, PDWORD Length,
							PDWORD VirtualAddress );
    void UnmapPhysicalMemory(DWORD Address);
    void WinxpSMBiosReader::win_dump_mem(BYTE *buf, size_t base, size_t len);
    void PrintError( char *message, long status );
    
    NtOpenSectionProc NtOpenSection;
    NtMapViewOfSectionProc NtMapViewOfSection;
    NtUnmapViewOfSectionProc NtUnmapViewOfSection;
    RtlInitUnicodeStringProc RtlInitUnicodeString;
    RtlNtStatusToDosErrorProc RtlNtStatusToDosError;
    int Checksum(const BYTE *buf, int len);
};

typedef UINT (__stdcall *GetSMBiosTableProc)(DWORD, DWORD, PVOID, DWORD);

typedef struct tagRawSMBIOSData
{
    BYTE	Used20CallingMethod;
    BYTE	SMBIOSMajorVersion;
    BYTE	SMBIOSMinorVersion;
    BYTE	DmiRevision;
    DWORD	Length;
    BYTE	SMBIOSTableData[];
} RawSMBIOSData, *PRawSMBIOSData;

class Win2k3SMBiosReader
{
public:
    Win2k3SMBiosReader()
    {
    }
    ~Win2k3SMBiosReader()
    {
    }

    BYTE * GetSMBiosRawData(DWORD& size);

private:
    GetSMBiosTableProc GetSMBiosTable;
};

typedef struct tagSMBiosStructHeader
{
	BYTE type;
	BYTE length;
	WORD handle;
	BYTE data[];
} SMBiosStructHeader, *PSMBiosStructHeader;

class CHwInfo
{
private:
    BYTE* m_pBufBios;
    int m_nBufSize;

    //char* GetString(SMBiosStructHeader *structHeader, int index);
    static BOOL IsWin2k3OrLater();
public:
    bool CHwInfo::GetSMBiosData();
    //CHwInfo(BYTE* buf, int size);
	BYTE* GetSMBiosStructure(BYTE type, DWORD& size);
	CHwInfo();
	~CHwInfo();
    //CString GetMahineUuid();
    //CString GetMachineSn();
};
