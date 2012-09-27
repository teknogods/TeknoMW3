#pragma once

#ifndef VMProtect

#ifdef _WIN64
	#pragma comment(lib, "VMProtectSDK64.lib")
#else
	#pragma comment(lib, "VMProtectSDK32.lib")
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define V VMProtectDecryptStringA
#define VU VMProtectBeginUltra
#define VM VMProtectBeginMutation
#define VV VMProtectBeginVirtualization
#define VE VMProtectEnd

// protection
__declspec(dllimport) void __stdcall VMProtectBegin(char *);
__declspec(dllimport) void __stdcall VMProtectBeginVirtualization(char *);
__declspec(dllimport) void __stdcall VMProtectBeginMutation(char *);
__declspec(dllimport) void __stdcall VMProtectBeginUltra(char *);
__declspec(dllimport) void __stdcall VMProtectEnd(void);
__declspec(dllimport) BOOL __stdcall VMProtectIsDebuggerPresent(BOOL);
__declspec(dllimport) BOOL __stdcall VMProtectIsVirtualMachinePresent(void);
__declspec(dllimport) BOOL __stdcall VMProtectIsValidImageCRC(void);
__declspec(dllimport) char * __stdcall VMProtectDecryptStringA(char *value);
__declspec(dllimport) wchar_t * __stdcall VMProtectDecryptStringW(wchar_t *value);

// licensing
enum VMProtectSerialStateFlags
{
	SERIAL_STATE_FLAG_CORRUPTED			= 0x00000001,
	SERIAL_STATE_FLAG_INVALID			= 0x00000002,
	SERIAL_STATE_FLAG_BLACKLISTED		= 0x00000004,
	SERIAL_STATE_FLAG_DATE_EXPIRED		= 0x00000008,
	SERIAL_STATE_FLAG_RUNNING_TIME_OVER	= 0x00000010,
	SERIAL_STATE_FLAG_BAD_HWID			= 0x00000020,
	SERIAL_STATE_FLAG_MAX_BUILD_EXPIRED	= 0x00000040,
};
#pragma pack(push, 1)
struct VMProtectDate
{
	WORD			wYear;
	BYTE			bMonth;
	BYTE			bDay;
};
struct VMProtectSerialNumberData
{
	INT				nState;				// VMProtectSerialStateFlags
	wchar_t			wUserName[256];		// user name
	wchar_t			wEMail[256];		// email
	VMProtectDate	dtExpire;			// date of serial number expiration
	VMProtectDate	dtMaxBuild;			// max date of build, that will accept this key
	INT				bRunningTime;		// running time in minutes
	BYTE			nUserDataLength;	// length of user data in bUserData
	BYTE			bUserData[255];		// up to 255 bytes of user data
};

#pragma pack(pop)
__declspec(dllimport) INT  __stdcall VMProtectSetSerialNumber(char * SerialNumber);
__declspec(dllimport) INT  __stdcall VMProtectGetSerialNumberState();
__declspec(dllimport) BOOL __stdcall VMProtectGetSerialNumberData(VMProtectSerialNumberData *pData, UINT nSize);
__declspec(dllimport) INT  __stdcall VMProtectGetCurrentHWID(char * HWID, UINT nSize);

#ifdef __cplusplus
}
#endif
#else
#define V (char *)
#endif