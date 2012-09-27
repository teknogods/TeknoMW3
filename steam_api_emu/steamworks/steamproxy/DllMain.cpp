#define STEAMWORKS_CLIENT_INTERFACES
#define _CRT_SECURE_NO_WARNINGS

#define STEAM
#define STEAM_API_EXPORTS
#include "..\\open steamworks\\Steamworks.h"
#include <windows.h>
#undef UNICODE
#include <tlhelp32.h>
#define UNICODE

#include <iostream>


#define ENSURE_PROXY(name) \
	if ( !Orig##name ) \
		Orig##name = (name##Fn)GetProcAddress(valveSteam, #name);

#define DECL_PROXY(ret, name, params) \
	typedef ret (*name##Fn) params; \
	name##Fn Orig##name; \
	S_API ret STEAM_CALL name params \
	{ \
		unsigned int retAddr = GetReturnAddress(); \
		ENSURE_PROXY(name); \
		HANDLE snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0); \
		MODULEENTRY32 me32; \
		MODULEENTRY32 callerModule; \
		me32.dwSize = sizeof (MODULEENTRY32); \
		Module32First(snapShot, &me32); \
		do \
		{ \
			unsigned int start = (unsigned int)me32.modBaseAddr; \
			unsigned int end = (unsigned int)start + me32.modBaseSize; \
			if ((retAddr > start) && (retAddr < end)) \
			{ \
				callerModule = me32; \
				break; \
			} \
		} \
		while (Module32Next(snapShot, &me32)); \
		CloseHandle(snapShot);

#define RETURN_PROXY(name, params) \
		return Orig##name params; \
	}

#define LOG_PROXY(name) \
	Log("[%s]\t"#name"\n", callerModule.szModule);

#define PROXY(ret, name, params, retParams) \
	DECL_PROXY(ret, name, params) \
	LOG_PROXY(name) \
	RETURN_PROXY(name, retParams);

#define DECL_CLASS_PROXY(ret, name, params) \
	virtual ret name params \
	{ \
		unsigned int retAddr = ::GetReturnAddress(); \
		HANDLE snapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 0); \
		MODULEENTRY32 me32; \
		MODULEENTRY32 callerModule; \
		me32.dwSize = sizeof (MODULEENTRY32); \
		Module32First(snapShot, &me32); \
		do \
		{ \
			unsigned int start = (unsigned int)me32.modBaseAddr; \
			unsigned int end = (unsigned int)start + me32.modBaseSize; \
			if ((retAddr > start) && (retAddr < end)) \
			{ \
				callerModule = me32; \
				break; \
			} \
		} \
		while (Module32Next(snapShot, &me32)); \

#define LOG_CLASS_PROXY(name) \
		::Log("[%s]\tCSteam::"#name"\n", callerModule.szModule);

#define RETURN_CLASS_PROXY(name, params) \
		return origSteam->name params; \
	}

#define CLASS_PROXY(ret, name, params, retParams) \
	DECL_CLASS_PROXY(ret, name, params) \
	LOG_CLASS_PROXY(name) \
	RETURN_CLASS_PROXY(name, retParams) 



__forceinline unsigned int GetReturnAddress()
{
	unsigned int retAddr;
	__asm
	{
		push eax;
		mov eax, [ebp+4];
		mov retAddr, eax;
		pop eax;
	}
	return retAddr;
}


HMODULE valveSteam;

void Log(char *msg, ...)
{
	FILE *logFile = fopen("MySteam.log", "a");
	FILE *log2 = fopen("steam.proxy.log", "a");
	FILE *log3 = fopen("proxy.log", "a");

	char buffer[1024];
	memset(buffer, 0, 1024);

	va_list args;
	va_start(args, msg);

	vsprintf(buffer, msg, args);

	va_end(args);

	SYSTEMTIME time;
	GetLocalTime(&time);

	char szLine[2048];
	memset(szLine, 0, 2048);
	sprintf(szLine, "%02d:%02d:%02d:%03d \t%s",  time.wHour, time.wMinute, time.wSecond, time.wMilliseconds, buffer);

	fputs(szLine, logFile);
	fputs(szLine, log2);
	fputs(szLine, log3);

	fflush(logFile);
	fflush(log2);
	fflush(log3);

	printf(szLine);

	fclose(logFile);
	fclose(log2);
	fclose(log3);
}

class CSteam006
{
public:
	CSteam006(ISteam006 *base)
	{
		origSteam = base;
	}
	virtual ~CSteam006()
	{
	}


	CLASS_PROXY(SteamCallHandle_t, ChangePassword, (const char *cszCurrentPassphrase, const char *cszNewPassphrase, int *pbChanged, TSteamError *pError), (cszCurrentPassphrase, cszNewPassphrase, pbChanged, pError));
	CLASS_PROXY(int, GetCurrentEmailAddress, (char *szEmailaddress, unsigned int uBufSize, unsigned int *puEmailaddressChars, TSteamError *pError), (szEmailaddress, uBufSize, puEmailaddressChars, pError));
	CLASS_PROXY(SteamCallHandle_t, ChangePersonalQA, (const char *cszCurrentPassphrase, const char *cszNewPersonalQuestion, const char *cszNewAnswerToQuestion, int *pbChanged, TSteamError *pError),(cszCurrentPassphrase, cszNewPersonalQuestion, cszNewAnswerToQuestion, pbChanged, pError));
	CLASS_PROXY(SteamCallHandle_t, ChangeEmailAddress, (const char *cszNewEmailAddress, int *pbChanged, TSteamError *pError), (cszNewEmailAddress, pbChanged, pError));
	CLASS_PROXY(int, VerifyEmailAddress, (), ());
	CLASS_PROXY(int, RequestEmailAddressVerificationEmail, (), ());
	CLASS_PROXY(int, ChangeAccountName, (), ());
	CLASS_PROXY(int, MountAppFilesystem, (TSteamError * pError), (pError));
	CLASS_PROXY(int, UnmountAppFilesystem, (TSteamError*  pError), (pError));
	CLASS_PROXY(int, MountFilesystem, (unsigned int uAppId, const char *szMountPath, TSteamError *pError), (uAppId, szMountPath, pError));
	CLASS_PROXY(int, UnmountFilesystem, (const char * szMountPath,  TSteamError * pError), (szMountPath, pError));

	DECL_CLASS_PROXY(int, Stat, (const char *cszName, TSteamElemInfo *pInfo, TSteamError *pError))
		::Log("[%s]\tCSteam::Stat( cszName = \"%s\" )\n", callerModule.szModule, cszName);
	RETURN_CLASS_PROXY(Stat, (cszName, pInfo, pError));

	CLASS_PROXY(int, SetvBuf, (SteamHandle_t hFile, void* pBuf, ESteamBufferMethod eMethod, unsigned int uBytes, TSteamError *pError), (hFile, pBuf, eMethod, uBytes, pError));
	CLASS_PROXY(int, FlushFile, (SteamHandle_t hFile, TSteamError *pError), (hFile, pError));

	DECL_CLASS_PROXY(SteamHandle_t, OpenFile, (const char *cszName, const char *cszMode, TSteamError *pError))
		::Log("[%s]\tCSteam::OpenFile( cszName = \"%s\", cszMode = \"%s\" )\n", callerModule.szModule, cszName, cszMode);
	RETURN_CLASS_PROXY(OpenFile, (cszName, cszMode, pError));

	CLASS_PROXY(SteamHandle_t, OpenFileEx, (const char *cszFileName, const char *cszMode, unsigned int *size, TSteamError *pError), (cszFileName, cszMode, size, pError));
	CLASS_PROXY(SteamHandle_t, OpenTmpFile, (TSteamError* pError), (pError));
	CLASS_PROXY(void, ClearError, (TSteamError*  pError), (pError));
	CLASS_PROXY(int, GetVersion, (char*  szVersion,  unsigned int  uVersionBufSize), (szVersion, uVersionBufSize));
	CLASS_PROXY(int, GetOfflineStatus, (unsigned int*  buIsOffline,  TSteamError * pError), (buIsOffline, pError));
	CLASS_PROXY(int, ChangeOfflineStatus, (), ());
	CLASS_PROXY(int, ProcessCall, (SteamCallHandle_t handle, TSteamProgress *pProgress, TSteamError *pError), (handle, pProgress, pError));
	CLASS_PROXY(int, AbortCall, (SteamCallHandle_t handle, TSteamError *pError), (handle, pError));
	CLASS_PROXY(int, BlockingCall, (SteamCallHandle_t handle, unsigned int uiProcessTickMS, TSteamError *pError), (handle, uiProcessTickMS, pError));
	CLASS_PROXY(int, SetMaxStallCount, (unsigned int  uNumStalls,  TSteamError * pError), (uNumStalls, pError));
	CLASS_PROXY(int, CloseFile, (SteamHandle_t hFile, TSteamError *pError), (hFile, pError))
	CLASS_PROXY(unsigned int, ReadFile, (void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError), (pBuf, uSize, uCount, hFile, pError))
	CLASS_PROXY(unsigned int, WriteFile, (const void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError), (pBuf, uSize, uCount, hFile, pError));
	CLASS_PROXY(int, Getc, (SteamHandle_t hFile, TSteamError *pError), (hFile, pError));
	CLASS_PROXY(int, Putc, (int cChar, SteamHandle_t hFile, TSteamError *pError), (cChar, hFile, pError));
	CLASS_PROXY(int, SeekFile,(SteamHandle_t hFile, long lOffset, ESteamSeekMethod sm, TSteamError *pError), (hFile, lOffset, sm, pError));
	CLASS_PROXY(long, TellFile,(SteamHandle_t hFile, TSteamError *pError), (hFile, pError))
	CLASS_PROXY(int, SizeFile, (SteamHandle_t hFile, TSteamError *pError), (hFile, pError))

	DECL_CLASS_PROXY(SteamHandle_t, FindFirst, (const char *cszPattern, ESteamFindFilter eFilter, TSteamElemInfo *pFindInfo, TSteamError *pError))
		::Log("[%s]\tCSteam::FindFirst( cszPattern = \"%s\", eFilter =\"%s\"(%d) )\n", callerModule.szModule, cszPattern, EnumString<ESteamFindFilter>::From( eFilter ), eFilter);
	RETURN_CLASS_PROXY(FindFirst, (cszPattern, eFilter, pFindInfo, pError))

	CLASS_PROXY(int, FindNext, (SteamHandle_t hFind, TSteamElemInfo *pFindInfo, TSteamError *pError), (hFind, pFindInfo, pError))
	CLASS_PROXY(int, FindClose, (SteamHandle_t hFind, TSteamError *pError), (hFind, pError))
	CLASS_PROXY(int, GetLocalFileCopy, (const char * cszName,  TSteamError * pError), (cszName, pError));
	CLASS_PROXY(int, IsFileImmediatelyAvailable, (const char * cszName,  TSteamError * pError), (cszName, pError));
	CLASS_PROXY(int, HintResourceNeed, (const char *cszHintList, int bForgetEverything, TSteamError *pError), (cszHintList, bForgetEverything, pError))
	CLASS_PROXY(int, ForgetAllHints, (const char * cszMountPath,  TSteamError * pError), (cszMountPath, pError));
	CLASS_PROXY(int, PauseCachePreloading, (const char * cszMountPath,  TSteamError * pError), (cszMountPath, pError));
	CLASS_PROXY(int, ResumeCachePreloading, (const char * cszMountPath,  TSteamError * pError), (cszMountPath, pError));
	CLASS_PROXY(SteamCallHandle_t, WaitForResources, (const char *cszMasterList, TSteamError *pError), (cszMasterList, pError))
	CLASS_PROXY(int, StartEngine, (TSteamError * pError), (pError));
	CLASS_PROXY(int, ShutdownEngine, (TSteamError * pError), (pError));

	DECL_CLASS_PROXY(int, Startup, (unsigned int  uUsingMask,  TSteamError * pError))
		::Log("[%s]\tCSteam::Startup( uUsingMask = %d )\n", callerModule.szModule, uUsingMask);
	RETURN_CLASS_PROXY(Startup, (uUsingMask, pError))

	CLASS_PROXY(int, Cleanup, (TSteamError * pError), (pError));
	CLASS_PROXY(int, NumAppsRunning, (), ());
	CLASS_PROXY(SteamCallHandle_t, CreateAccount, (const char *cszUser, const char *cszPassphrase, const char *cszCreationKey, const char *cszPersonalQuestion, const char *cszAnswerToQuestion, int *pbCreated, unsigned int uUnknown, TSteamError *pError), ( cszUser, cszPassphrase, cszCreationKey, cszPersonalQuestion, cszAnswerToQuestion, pbCreated, uUnknown, pError)) 
	CLASS_PROXY(int, GenerateSuggestedAccountNames, (), ());
	CLASS_PROXY(int, IsLoggedIn, (int * pbIsLoggedIn,  TSteamError * pError), (pbIsLoggedIn, pError));
	CLASS_PROXY(SteamCallHandle_t, Logout, (TSteamError *pError), (pError))
	CLASS_PROXY(int, IsSecureComputer, (int * pbIsSecure,  TSteamError * pError), (pbIsSecure, pError));
	CLASS_PROXY(SteamHandle_t, CreateLogContext, (const char *cszName), (cszName))
	CLASS_PROXY(int, Log, (SteamHandle_t hContext, const char *cszMsg), (hContext, cszMsg))
	CLASS_PROXY(void, LogResourceLoadStarted, (const char * cszMsg), (cszMsg));
	CLASS_PROXY(void, LogResourceLoadFinished, (const char * cszMsg), (cszMsg));
	CLASS_PROXY(SteamCallHandle_t, RefreshLogin, (const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError), (cszPassphrase, bIsSecureComputer, pError))
	CLASS_PROXY(int, VerifyPassword, (), ());
	CLASS_PROXY(int, GetUserType, (), ());
	CLASS_PROXY(int, GetAppStats, (TSteamAppStats * pAppStats,  TSteamError * pError), (pAppStats, pError));
	CLASS_PROXY(int, IsAccountNameInUse, (), ());
	CLASS_PROXY(int, GetAppIds, (unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError), (puIds, uMaxIds, pError))
	CLASS_PROXY(int, GetSubscriptionStats, (TSteamSubscriptionStats * pSubscriptionStats,  TSteamError * pError), (pSubscriptionStats, pError));
	CLASS_PROXY(int, RefreshAccountInfo, (), ());
	CLASS_PROXY(SteamCallHandle_t, Subscribe, (unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, TSteamError *pError), (uSubscriptionId, pSubscriptionBillingInfo, pError))
	CLASS_PROXY(SteamCallHandle_t, Unsubscribe, (unsigned int uSubscriptionId, TSteamError *pError), (uSubscriptionId, pError))
	CLASS_PROXY(int, GetSubscriptionReceipt, (), ());
	CLASS_PROXY(int, GetAccountStatus, (), ());
	CLASS_PROXY(SteamCallHandle_t, SetUser, (const char *cszUser, int *pbUserSet, TSteamError *pError), (cszUser, pbUserSet, pError))
	CLASS_PROXY(int, GetUser, (char *szUser, unsigned int uBufSize, unsigned int *puUserChars, TSteamGlobalUserID *pGlobalSteamID, TSteamError *pError), (szUser, uBufSize, puUserChars, pGlobalSteamID, pError))
	CLASS_PROXY(SteamCallHandle_t, Login, (const char *cszUser, const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError), (cszUser, cszPassphrase, bIsSecureComputer, pError))
	CLASS_PROXY(int, AckSubscriptionReceipt, (), ());
	CLASS_PROXY(int, IsAppSubscribed, (unsigned int uAppId, int *pbIsAppSubscribed, int *pReserved, TSteamError *pError), (uAppId, pbIsAppSubscribed, pReserved, pError))
	CLASS_PROXY(int, GetSubscriptionIds, (unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError), (puIds, uMaxIds, pError))
	CLASS_PROXY(int, EnumerateSubscription, (unsigned int uId, TSteamSubscription *pSubscription, TSteamError *pError), (uId, pSubscription, pError))
	CLASS_PROXY(int, EnumerateSubscriptionDiscount, (), ());
	CLASS_PROXY(int, EnumerateSubscriptionDiscountQualifier, (), ());
	CLASS_PROXY(int, EnumerateApp, (unsigned int uId, TSteamApp *pApp, TSteamError *pError), (uId, pApp, pError))
	CLASS_PROXY(int, EnumerateAppLaunchOption, (unsigned int uAppId, unsigned int uLaunchOptionIndex, TSteamAppLaunchOption *pLaunchOption, TSteamError *pError), (uAppId, uLaunchOptionIndex, pLaunchOption, pError))
	CLASS_PROXY(SteamCallHandle_t, DeleteAccount, (TSteamError *pError), (pError))
	CLASS_PROXY(int, EnumerateAppIcon, (unsigned int uAppId, unsigned int uIconIndex, unsigned char *pIconData, unsigned int uIconDataBufSize,  unsigned int *puSizeOfIconData, TSteamError *pError), (uAppId, uIconIndex, pIconData, uIconDataBufSize, puSizeOfIconData, pError))
	CLASS_PROXY(SteamCallHandle_t, LaunchApp, (unsigned int uAppId, unsigned int uLaunchOption, const char *cszArgs, TSteamError *pError), (uAppId, uLaunchOption, cszArgs, pError))
	CLASS_PROXY(int, GetCacheFilePath, (), ());
	CLASS_PROXY(int, EnumerateAppVersion, (unsigned int uAppId, unsigned int uVersionIndex, TSteamAppVersion *pAppVersion, TSteamError *pError), (uAppId, uVersionIndex, pAppVersion, pError))
	CLASS_PROXY(int, EnumerateAppDependency, (unsigned int AppId, unsigned int uDependency, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError), (AppId, uDependency, pDependencyInfo, pError))
	CLASS_PROXY(SteamCallHandle_t, StartLoadingCache, (unsigned int uAppId, TSteamError *pError), (uAppId, pError))
	CLASS_PROXY(int, InsertAppDependency, (), ());
	CLASS_PROXY(int, RemoveAppDependency, (), ());
	CLASS_PROXY(int, FindApp, (), ());
	CLASS_PROXY(int, GetAppDependencies, (), ());
	CLASS_PROXY(int, IsSubscribed, (unsigned int uSubscriptionId, int *pbIsSubscribed, int *pReserved, TSteamError *pError), (uSubscriptionId, pbIsSubscribed, pReserved, pError))
	CLASS_PROXY(int, GetAppUserDefinedInfo, (unsigned int uAppId, const char *cszPropertyName, char *szPropertyValue, unsigned int uBufSize, unsigned int *puPropertyValueLength, TSteamError *pError), (uAppId, cszPropertyName, szPropertyValue, uBufSize, puPropertyValueLength, pError))
	CLASS_PROXY(SteamCallHandle_t, WaitForAppReadyToLaunch, (unsigned int uAppId, TSteamError *pError), (uAppId, pError))
	CLASS_PROXY(int, IsCacheLoadingEnabled, (unsigned int uAppId, int *pbIsLoading, TSteamError *pError), (uAppId, pbIsLoading, pError))
	CLASS_PROXY(SteamCallHandle_t, StopLoadingCache, (unsigned int uAppId, TSteamError *pError), (uAppId, pError))
	CLASS_PROXY(int, GetEncryptedUserIDTicket, (const void *pEncryptionKeyReceivedFromAppServer, unsigned int uEncryptionKeyLength, void *pOutputBuffer, unsigned int uSizeOfOutputBuffer, unsigned int *pReceiveSizeOfEncryptedTicket, TSteamError *pError), (pEncryptionKeyReceivedFromAppServer, uEncryptionKeyLength, pOutputBuffer, uSizeOfOutputBuffer, pReceiveSizeOfEncryptedTicket, pError))
	CLASS_PROXY(int, FlushCache, (unsigned int  uAppId,  TSteamError * pError), (uAppId, pError));
	CLASS_PROXY(int, RepairOrDecryptCaches, (), ());
	CLASS_PROXY(int, LoadCacheFromDir, (unsigned int uAppId, const char *cszPath, TSteamError *pError), (uAppId, cszPath, pError))
	CLASS_PROXY(int, GetCacheDefaultDirectory, (char * szPath,  TSteamError * pError), (szPath, pError))
	CLASS_PROXY(int, SetCacheDefaultDirectory, (const char * cszPath,  TSteamError * pError), (cszPath, pError));
	CLASS_PROXY(int, GetAppDir, (), ());
	CLASS_PROXY(SteamCallHandle_t, MoveApp, (unsigned int uAppId, const char *szPath, TSteamError *pError), (uAppId, szPath, pError))
	CLASS_PROXY(SteamCallHandle_t, GetAppCacheSize, (unsigned int uAppId, unsigned int *puCacheSizeInMb, TSteamError *pError), (uAppId, puCacheSizeInMb, pError))
	CLASS_PROXY(SteamCallHandle_t, SetAppCacheSize, (unsigned int uAppId, unsigned int uCacheSizeInMb, TSteamError *pError), (uAppId, uCacheSizeInMb, pError))
	CLASS_PROXY(int, SetAppVersion, (unsigned int uAppId, unsigned int uAppVersionId, TSteamError *pError), (uAppId, uAppVersionId, pError))
	CLASS_PROXY(SteamCallHandle_t, Uninstall, (TSteamError *pError), (pError))
	CLASS_PROXY(int, SetNotificationCallback, (SteamNotificationCallback_t pCallbackFunction, TSteamError *pError), (pCallbackFunction, pError))
	CLASS_PROXY(int, ChangeForgottenPassword, (), ());
	CLASS_PROXY(int, RequestForgottenPasswordEmail, (), ());
	CLASS_PROXY(int, RequestAccountsByEmailAddressEmail, (), ());
	CLASS_PROXY(int, RequestAccountsByCdKeyEmail, (), ());
	CLASS_PROXY(int, GetNumAccountsWithEmailAddress, (), ());
	CLASS_PROXY(int, UpdateAccountBillingInfo, (const TSteamPaymentCardInfo *pPaymentCardInfo, int *pbChanged, TSteamError *pError), (pPaymentCardInfo, pbChanged, pError))
	CLASS_PROXY(int, UpdateSubscriptionBillingInfo, (unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, int *pbChanged, TSteamError *pError), (uSubscriptionId, pSubscriptionBillingInfo, pbChanged, pError))
	CLASS_PROXY(int, GetSponsorUrl, (unsigned int uAppId, char *szUrl, unsigned int uBufSize, unsigned int *pUrlChars, TSteamError *pError), (uAppId, szUrl, uBufSize, pUrlChars, pError))
	CLASS_PROXY(int, GetContentServerInfo, (), ());
	CLASS_PROXY(int, GetAppUpdateStats, (unsigned int uAppId, unsigned int uStatType, TSteamUpdateStats *pUpdateStats, TSteamError *pError), (uAppId, uStatType, pUpdateStats, pError))
	CLASS_PROXY(int, GetTotalUpdateStats, (TSteamUpdateStats * pUpdateStats,  TSteamError * pError), (pUpdateStats, pError))
	CLASS_PROXY(SteamCallHandle_t, CreateCachePreloaders, (TSteamError *pError), (pError))

	CLASS_PROXY(int, WriteMiniDumpSetComment, (const char *cszComment), (cszComment))
	CLASS_PROXY(int, Dummy1, (), ())
	CLASS_PROXY(int, Dummy2, (), ())
	CLASS_PROXY(int, Dummy3, (), ())
	CLASS_PROXY(int, Dummy4, (), ())
	CLASS_PROXY(int, GetAppPurchaseCountry, (int appID, char* szCountryCode, unsigned int a3, unsigned int* pPurchaseTime, TSteamError* pError), (appID, szCountryCode, a3, pPurchaseTime, pError))

	
	CLASS_PROXY(int, GetLocalClientVersion, (), ())
	CLASS_PROXY(int, IsFileNeededByCache, (), ())
	CLASS_PROXY(int, LoadFileToCache, (), ())
	CLASS_PROXY(int, GetCacheDecryptionKey, (), ())
	CLASS_PROXY(int, GetSubscriptionExtendedInfo, (), ())
	CLASS_PROXY(int, GetSubscriptionPurchaseCountry, (), ())
	CLASS_PROXY(int, GetAppUserDefinedRecord, (unsigned int uAppId, unsigned int arg2, unsigned int arg3, TSteamError *pError), (uAppId, arg2, arg3, pError))

	
	CLASS_PROXY(int, FindServersNumServers, (unsigned int arg1), (arg1))
	CLASS_PROXY(int, FindServersIterateServer, (int arg1, int arg2, char *szServerAddress, unsigned int uServerAddressChars), (arg1, arg2, szServerAddress, uServerAddressChars))
	CLASS_PROXY(int, FindServersGetErrorString, (), ())

	private:
		ISteam006 *origSteam;
};




void Init()
{
	// preload used libraries
	/*LoadLibrary(L"vstdlib_s.dll");
	LoadLibrary(L"tier0_s.dll");
	LoadLibrary(L"steamclient.dll");*/

	valveSteam = LoadLibrary( L"stean.dll" );

	AllocConsole();
}


DECL_PROXY(void*, CreateInterface, ( const char *pName, int *pReturnCode ))
	Log("[%s]\tCreateInterface( pName = \"%s\" )\n", callerModule.szModule, pName);
RETURN_PROXY(CreateInterface, (pName, pReturnCode))

DECL_PROXY(void*, _f, ( const char *pName ))
	Log("[%s]\t_f( pName = \"%s\" )\n", callerModule.szModule, pName);

	static CSteam006 *mySteam;
	if (strcmp(pName, "Steam006") == 0)
	{
		if (!mySteam)
			mySteam = new CSteam006((ISteam006*)Orig_f("Steam006"));

		return (void*)mySteam;
	}
RETURN_PROXY(_f, (pName))


PROXY(int, SteamStartEngine, (TSteamError *pError), (pError))

DECL_PROXY(int, SteamStartup, ( uint32 uUsingMask, TSteamError *pError ))
  Log("[%s]\tSteamStartup( uUsingMask = %d )\n", callerModule.szModule, uUsingMask);
RETURN_PROXY(SteamStartup, (uUsingMask, pError))

PROXY(int, SteamCleanup, ( TSteamError *pError ), (pError))
PROXY(int, SteamShutdownEngine, ( TSteamError *pError ), (pError))

DECL_PROXY(int, SteamGetLocalClientVersion, ( int *a, int *b, int *c ))
	int ret = OrigSteamGetLocalClientVersion(a, b, c );
	::Log("[%s]\tSteamGetLocalClientVersion( a = %d (%d), b = %d (%d), c = %d (%d)) = %d\n", callerModule.szModule, a, *a, b, *b, c, *c, ret );
	return ret;
}

PROXY(int, SteamGetVersion, ( char *szVersion, uint32 uVersionBufSize ), (szVersion, uVersionBufSize) )






PROXY(int, SteamProcessCall, ( SteamCallHandle_t handle, TSteamProgress *pProgress, TSteamError *pError ), ( handle, pProgress, pError ) )
PROXY(int, SteamAbortCall, ( SteamCallHandle_t handle, TSteamError *pError ), (handle, pError))
PROXY(int, SteamBlockingCall,( SteamCallHandle_t handle, uint32 uiProcessTickMS, TSteamError *pError ), (handle, uiProcessTickMS, pError) )
PROXY(int, SteamSetMaxStallCount, ( uint32 uNumStalls, TSteamError *pError ), (uNumStalls, pError))





PROXY(int, SteamMountAppFilesystem, ( TSteamError *pError ), (pError))
PROXY(int, SteamUnmountAppFilesystem, ( TSteamError *pError ), (pError))

DECL_PROXY(int, SteamMountFilesystem, ( unsigned int uAppId, const char *szMountPath, TSteamError *pError ))
	::Log("[%s]\tSteamMountFilesystem( uAppId = %d, szMountPath = \"%s\" )\n", callerModule.szModule, uAppId, szMountPath);
RETURN_PROXY(SteamMountFilesystem, (uAppId, szMountPath, pError))


PROXY(int, SteamUnmountFilesystem, ( const char *szMountPath, TSteamError *pError ), (szMountPath, pError))

PROXY(SteamHandle_t, SteamOpenFileEx, ( const char *cszFileName, const char *cszMode, unsigned int *puSize, TSteamError *pError ), (cszFileName, cszMode, puSize, pError))
PROXY(SteamHandle_t, SteamOpenFile, ( const char *cszName, const char *cszMode, TSteamError *pError ), (cszName, cszMode, pError))
PROXY(SteamHandle_t, SteamOpenTmpFile, ( TSteamError *pError ), (pError))

PROXY(int, SteamFlushFile, ( SteamHandle_t hFile, TSteamError *pError ), (hFile, pError))
PROXY(int, SteamCloseFile, ( SteamHandle_t hFile, TSteamError *pError ), (hFile, pError))

PROXY(int, SteamSetvBuf, ( SteamHandle_t hFile, void* pBuf, ESteamBufferMethod eMethod, unsigned int uBytes, TSteamError *pError ), (hFile, pBuf, eMethod, uBytes, pError))
PROXY(int, SteamGetc, ( SteamHandle_t hFile, TSteamError *pError ), (hFile, pError))
PROXY(int, SteamPutc, ( int cChar, SteamHandle_t hFile, TSteamError *pError ), (cChar, hFile, pError))

//PROXY(int, SteamPrintFile, ( SteamHandle_t hFile, TSteamError *pError, const char *cszFormat, ... )
PROXY(unsigned int, SteamReadFile, ( void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError ), (pBuf, uSize, uCount, hFile, pError))
PROXY(unsigned int, SteamWriteFile, ( const void *pBuf, unsigned int uSize, unsigned int uCount, SteamHandle_t hFile, TSteamError *pError ), (pBuf, uSize, uCount, hFile, pError))

PROXY(int, SteamSeekFile, ( SteamHandle_t hFile, long lOffset, ESteamSeekMethod seek, TSteamError *pError ), (hFile, lOffset, seek, pError))
PROXY(long, SteamSizeFile, ( SteamHandle_t hFile, TSteamError *pError ), (hFile, pError))
PROXY(long, SteamTellFile, ( SteamHandle_t hFile, TSteamError *pError ), (hFile, pError))

PROXY(int, SteamStat, ( const char *cszName, TSteamElemInfo *pInfo, TSteamError *pError ), (cszName, pInfo, pError))

PROXY(SteamHandle_t, SteamFindFirst, ( const char *cszPattern, ESteamFindFilter eFilter, TSteamElemInfo *pFindInfo, TSteamError *pError ), (cszPattern, eFilter, pFindInfo, pError))
PROXY(int, SteamFindNext, ( SteamHandle_t hDirectory, TSteamElemInfo *pFindInfo, TSteamError *pError ), (hDirectory, pFindInfo, pError))
PROXY(int, SteamFindClose, ( SteamHandle_t hDirectory, TSteamError *pError ), (hDirectory, pError))

PROXY(int, SteamGetLocalFileCopy, ( const char *cszName, TSteamError *pError ), (cszName, pError))

PROXY(int, SteamIsFileImmediatelyAvailable, ( const char *cszName, TSteamError *pError ), (cszName, pError))

PROXY(int, SteamHintResourceNeed, ( const char *cszMountPath, const char *cszMasterList, int bForgetEverything, TSteamError *pError ), (cszMountPath, cszMasterList, bForgetEverything, pError))
PROXY(int, SteamForgetAllHints, ( const char *cszMountPath, TSteamError *pError ), (cszMountPath, pError))

PROXY(int, SteamPauseCachePreloading, ( const char *cszMountPath, TSteamError *pError ), (cszMountPath, pError))
PROXY(int, SteamResumeCachePreloading, ( const char *cszMountPath, TSteamError *pError ), (cszMountPath, pError))

PROXY(SteamCallHandle_t, SteamWaitForResources, ( const char *cszMountPath, const char *cszMasterList, TSteamError *pError ), (cszMountPath, cszMasterList, pError))
PROXY(SteamCallHandle_t, SteamFlushCache, ( unsigned int uAppId, TSteamError *pError ), (uAppId, pError))

PROXY(int, SteamGetCacheDecryptionKey, (), ())
PROXY(int, SteamGetCacheDefaultDirectory, ( char *szPath, TSteamError *pError ), (szPath, pError))
PROXY(int, SteamSetCacheDefaultDirectory, ( const char *szPath, TSteamError *pError ), (szPath, pError))
PROXY(int, SteamGetCacheFilePath, (), ())

PROXY(int, SteamIsFileNeededByCache, (), ())

PROXY(int, SteamRepairOrDecryptCaches, (), ())

PROXY(int, SteamCreateCachePreloaders, ( TSteamError *pError ), (pError))
PROXY(int, SteamIsCacheLoadingEnabled, ( unsigned int uAppId, int *pbIsLoading, TSteamError *pError ), (uAppId, pbIsLoading, pError))

PROXY(SteamCallHandle_t, SteamLoadCacheFromDir, ( unsigned int uAppId, const char *szPath, TSteamError *pError ), (uAppId, szPath, pError))
PROXY(int, SteamLoadFileToCache, (), ())

DECL_PROXY(SteamCallHandle_t, SteamStartLoadingCache, ( unsigned int uAppId, TSteamError *pError ))
	::Log("[%s]\tSteamStartLoadingCache( uAppId = %d )\n", callerModule.szModule, uAppId);
RETURN_PROXY(SteamStartLoadingCache, (uAppId, pError))

PROXY(SteamCallHandle_t, SteamStopLoadingCache, ( unsigned int uAppId, TSteamError *pError ), (uAppId, pError))



PROXY(SteamHandle_t, SteamCreateLogContext, ( const char *cszName ), (cszName))
PROXY(int,  SteamLog, ( SteamHandle_t hContext, const char *cszMsg ), (hContext, cszMsg))
PROXY(void, SteamLogResourceLoadStarted, ( const char *cszMsg ), (cszMsg))
PROXY(void, SteamLogResourceLoadFinished, ( const char *cszMsg ), (cszMsg))



PROXY(SteamCallHandle_t, SteamCreateAccount, ( const char *cszUser, const char *cszPassphrase, const char *cszCreationKey, const char *cszPersonalQuestion, const char *cszAnswerToQuestion, int *pbCreated, unsigned int uUnknown, TSteamError *pError ), (cszUser, cszPassphrase, cszCreationKey, cszPersonalQuestion, cszAnswerToQuestion, pbCreated, uUnknown, pError ))
PROXY(SteamCallHandle_t, SteamDeleteAccount, ( TSteamError *pError ), (pError))

PROXY(int, SteamChangeAccountName,(), ())
PROXY(SteamCallHandle_t, SteamChangeEmailAddress, ( const char *cszNewEmailAddress, int *pbChanged, TSteamError *pError ), (cszNewEmailAddress, pbChanged, pError))
PROXY(int, SteamChangeForgottenPassword,(), ())

PROXY(SteamCallHandle_t, SteamChangePassword, ( const char *cszCurrentPassphrase, const char *cszNewPassphrase, int *pbChanged, TSteamError *pError ), (cszCurrentPassphrase, cszNewPassphrase, pbChanged, pError))
PROXY(SteamCallHandle_t, SteamChangePersonalQA, ( const char *cszCurrentPassphrase, const char *cszNewPersonalQuestion, const char *cszNewAnswerToQuestion, int *pbChanged, TSteamError *pError ), (cszCurrentPassphrase, cszNewPersonalQuestion, cszNewAnswerToQuestion, pbChanged, pError))

DECL_PROXY(int, SteamEnumerateApp, ( unsigned int uAppId, TSteamApp *pApp, TSteamError *pError ))
	::Log("[%s]\tSteamEnumerateApp( uAppId = %d )\n", callerModule.szModule, uAppId);
RETURN_PROXY(SteamEnumerateApp, (uAppId, pApp, pError))

DECL_PROXY(int, SteamEnumerateAppDependency, ( unsigned int AppId, unsigned int uDependency, TSteamAppDependencyInfo *pDependencyInfo, TSteamError *pError))
	::Log("[%s]\tSteamEnumerateAppDependency( AppId = %d, uDependency = %d )\n", callerModule.szModule, AppId, uDependency);
RETURN_PROXY(SteamEnumerateAppDependency, (AppId, uDependency, pDependencyInfo, pError))

PROXY(int, SteamEnumerateAppIcon, ( unsigned int uAppId, unsigned int uIconIndex, unsigned char *pIconData, unsigned int uIconDataBufSize, unsigned int *puSizeOfIconData, TSteamError *pError ), (uAppId, uIconIndex, pIconData, uIconDataBufSize, puSizeOfIconData, pError))

DECL_PROXY(int, SteamEnumerateAppLaunchOption, ( unsigned int uAppId, unsigned int uLaunchOptionIndex, TSteamAppLaunchOption *pLaunchOption, TSteamError *pError ))
	::Log("[%s]\tSteamEnumerateAppLaunchOption( uAppId = %d, uLaunchOptionIndex = %d )\n", callerModule.szModule, uAppId, uLaunchOptionIndex);
RETURN_PROXY(SteamEnumerateAppLaunchOption, (uAppId, uLaunchOptionIndex, pLaunchOption, pError))

PROXY(int, SteamEnumerateAppVersion, ( unsigned int uAppId, unsigned int uVersionIndex, TSteamAppVersion *pAppVersion, TSteamError *pError ), (uAppId, uVersionIndex, pAppVersion, pError))
DECL_PROXY(int, SteamEnumerateSubscription, ( unsigned int uAppId, TSteamSubscription *pSubscription, TSteamError *pError ))
	::Log("[%s]\tSteamEnumerateSubscription( uAppId = %d )\n", callerModule.szModule, uAppId);
RETURN_PROXY(SteamEnumerateSubscription, (uAppId, pSubscription, pError))

PROXY(int, SteamEnumerateSubscriptionDiscount, (), ())
PROXY(int, SteamEnumerateSubscriptionDiscountQualifier, (), ())
PROXY(int, SteamGenerateSuggestedAccountNames, (), ())

DECL_PROXY(int, SteamGetAccountStatus, (unsigned int unknown, TSteamError *pError))
	::Log("[%s]\tSteamGetAccountStatus( unknown =\"%s\"(%d) )\n", callerModule.szModule, (char*)unknown, unknown);
RETURN_PROXY(SteamGetAccountStatus, (unknown, pError))

DECL_PROXY(SteamCallHandle_t, SteamGetAppCacheSize, ( unsigned int uAppId, unsigned int *pCacheSizeInMb, TSteamError *pError ))
	::Log("[%s]\tSteamGetAppCacheSize( uAppId = %d )\n", callerModule.szModule, uAppId);
RETURN_PROXY(SteamGetAppCacheSize, (uAppId, pCacheSizeInMb, pError))

PROXY(int, SteamGetAppDependencies, (), ())
PROXY(int, SteamGetAppDir, (), ())
PROXY(int, SteamGetAppCacheDir, ( unsigned int uAppId, char *szPath, TSteamError *pError ), (uAppId, szPath, pError))
PROXY(int, SteamGetAppIds, ( unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError ), (puIds, uMaxIds, pError))
PROXY(int, SteamGetAppPurchaseCountry, ( unsigned int uAppID, char* szCountryCode, unsigned int a3, unsigned int* pPurchaseTime, TSteamError* pError ), (uAppID, szCountryCode, a3, pPurchaseTime, pError))
PROXY(int, SteamGetAppStats, ( TSteamAppStats *pAppStats, TSteamError *pError ), (pAppStats, pError))
PROXY(int, SteamGetAppUpdateStats, ( unsigned int uAppId, TSteamUpdateStats *pUpdateStats, TSteamError *pError ), (uAppId, pUpdateStats, pError))

DECL_PROXY(int, SteamGetAppUserDefinedInfo, ( unsigned int uAppId, const char *cszPropertyName, char *szPropertyValue, unsigned int uBufSize, unsigned int *puPropertyValueLength, TSteamError *pError ))
	::Log("[%s]\tSteamGetAppUserDefinedInfo( uAppId = %d, cszPropertyName = \"%s\" )\n", callerModule.szModule, uAppId, cszPropertyName);
RETURN_PROXY(SteamGetAppUserDefinedInfo, ( uAppId, cszPropertyName, szPropertyValue, uBufSize, puPropertyValueLength, pError ))

DECL_PROXY(int, SteamGetAppUserDefinedRecord, ( unsigned int uAppId, unsigned int arg2, unsigned int arg3, TSteamError *pError ))
	::Log("[%s]\tSteamGetAppUserDefinedRecord( uAppId = %d, arg2 = %d, arg3 = %d )\n", callerModule.szModule, uAppId, arg2, arg3);
RETURN_PROXY(SteamGetAppUserDefinedRecord, (uAppId, arg2, arg3, pError))

PROXY(int, SteamGetCurrentEmailAddress, ( char *szEmailaddress, unsigned int uBufSize, unsigned int *puEmailaddressChars, TSteamError *pError ), (szEmailaddress, uBufSize, puEmailaddressChars, pError))

PROXY(int, SteamGetNumAccountsWithEmailAddress, (), ())

PROXY(int, SteamGetSponsorUrl, ( unsigned int uAppId, char *szUrl, unsigned int uBufSize, unsigned int *pUrlChars, TSteamError *pError ), (uAppId, szUrl, uBufSize, pUrlChars, pError))

DECL_PROXY(int, SteamGetSubscriptionExtendedInfo, (unsigned int uSubscriptionId, char *string, unsigned int *unknown, unsigned int a, unsigned int *unknown2, unsigned int *unknown3 ))
	::Log("[%s]\tSteamGetSubscriptionExtendedInfo( uSubscriptionId = %d, string = \"%s\", a = %d )\n", callerModule.szModule, uSubscriptionId, string, a);
RETURN_PROXY(SteamGetSubscriptionExtendedInfo, (uSubscriptionId, string, unknown, a, unknown2, unknown3))

PROXY(int, SteamGetSubscriptionIds, ( unsigned int *puIds, unsigned int uMaxIds, TSteamError *pError ), (puIds, uMaxIds, pError))

DECL_PROXY(int, SteamGetSubscriptionPurchaseCountry, ( unsigned int uSubscriptionId, char *szCountryCode, unsigned int uCount, unsigned int unknown, TSteamError *pError))
	::Log("[%s]\tSteamGetSubscriptionPurchaseCountry( uSubscriptionId = %d )\n", callerModule.szModule, uSubscriptionId);
RETURN_PROXY(SteamGetSubscriptionPurchaseCountry, (uSubscriptionId, szCountryCode, uCount, unknown, pError))

PROXY(int, SteamGetSubscriptionReceipt, (), ())
PROXY(int, SteamGetSubscriptionStats, ( TSteamSubscriptionStats *pSubscriptionStats, TSteamError *pError ), (pSubscriptionStats, pError))

PROXY(int, SteamGetTotalUpdateStats, ( TSteamUpdateStats *pUpdateStats, TSteamError *pError ), (pUpdateStats, pError))

PROXY(int, SteamGetUser, ( char *szUser, unsigned int uBufSize, unsigned int *puUserChars, TSteamGlobalUserID* pSteamGlobalUserID, TSteamError *pError ), (szUser, uBufSize, puUserChars, pSteamGlobalUserID, pError))
PROXY(SteamCallHandle_t, SteamSetUser, ( const char *cszUser, int *pbUserSet, TSteamError *pError ), (cszUser, pbUserSet, pError))

PROXY(int, SteamGetUserType, (), ())

PROXY(int, SteamIsAccountNameInUse, (), ())

PROXY(int, SteamIsAppSubscribed, ( unsigned int uAppId, int *pbIsAppSubscribed, int *pReserved, TSteamError *pError ), (uAppId, pbIsAppSubscribed, pReserved, pError))


DECL_PROXY(int, SteamIsSubscribed, ( unsigned int uSubscriptionId, int *pbIsSubscribed, int *pReserved, TSteamError *pError ))
	::Log("[%s]\tSteamIsSubscribed( uSubscriptionId = %d )\n", callerModule.szModule, uSubscriptionId);
RETURN_PROXY(SteamIsSubscribed, (uSubscriptionId, pbIsSubscribed, pReserved, pError))

PROXY(int, SteamIsLoggedIn, ( int *pbIsLoggedIn, TSteamError *pError ), (pbIsLoggedIn, pError))
PROXY(int, SteamIsSecureComputer, ( int *pbIsSecure, TSteamError *pError ), (pbIsSecure, pError))

PROXY(SteamCallHandle_t, SteamLaunchApp, ( unsigned int uAppId, unsigned int uLaunchOption, const char *cszArgs, TSteamError *pError ), (uAppId, uLaunchOption, cszArgs, pError))


DECL_PROXY(SteamCallHandle_t, SteamLogin, ( const char *cszUser, const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError ))
	::Log("[%s]\tSteamLogin( cszUser = \"%s\", cszPassphrase = \"%s\", bIsSecureComputer = %d )\n", callerModule.szModule, cszUser, cszPassphrase, bIsSecureComputer);
RETURN_PROXY(SteamLogin, (cszUser, cszPassphrase, bIsSecureComputer, pError))


PROXY(SteamCallHandle_t, SteamLogout, ( TSteamError *pError ), (pError))

PROXY(SteamCallHandle_t, SteamMoveApp, ( unsigned int uAppId, const char *szPath, TSteamError *pError ), (uAppId, szPath, pError))

PROXY(int, SteamRefreshAccountInfo, (), ())
PROXY(int, SteamRefreshAccountInfoEx, (), ())

PROXY(SteamCallHandle_t, SteamRefreshLogin, ( const char *cszPassphrase, int bIsSecureComputer, TSteamError *pError ), (cszPassphrase, bIsSecureComputer, pError))

PROXY(int, SteamRequestAccountsByCdKeyEmail, (), ())
PROXY(int, SteamRequestAccountsByEmailAddressEmail, (), ())
PROXY(int, SteamRequestEmailAddressVerificationEmail, (), ())
PROXY(int, SteamRequestForgottenPasswordEmail, (), ())

PROXY(SteamCallHandle_t, SteamSubscribe, ( unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, TSteamError *pError ), (uSubscriptionId, pSubscriptionBillingInfo, pError))
PROXY(SteamCallHandle_t, SteamUnsubscribe, ( unsigned int uSubscriptionId, TSteamError *pError ), (uSubscriptionId, pError))

PROXY(SteamCallHandle_t, SteamUpdateAccountBillingInfo, ( const TSteamPaymentCardInfo *pPaymentCardInfo, int *pbChanged, TSteamError *pError ), (pPaymentCardInfo, pbChanged, pError))
PROXY(SteamCallHandle_t, SteamUpdateSubscriptionBillingInfo, ( unsigned int uSubscriptionId, const TSteamSubscriptionBillingInfo *pSubscriptionBillingInfo, int *pbChanged, TSteamError *pError ), (uSubscriptionId, pSubscriptionBillingInfo, pbChanged, pError))

PROXY(int, SteamVerifyEmailAddress, (), ())
PROXY(int, SteamVerifyPassword, (), ())

PROXY(SteamCallHandle_t, SteamWaitForAppReadyToLaunch, ( unsigned int uAppId, TSteamError *pError ), (uAppId, pError))

PROXY(int, SteamAckSubscriptionReceipt, (), ())
PROXY(int, SteamRemoveAppDependency, (), ())

PROXY(SteamCallHandle_t, SteamSetAppCacheSize, ( unsigned int uAppId, unsigned int nCacheSizeInMb, TSteamError *pError ), (uAppId, nCacheSizeInMb, pError))
PROXY(SteamCallHandle_t, SteamSetAppVersion, ( unsigned int uAppId, unsigned int uAppVersionId, TSteamError *pError ), (uAppId, uAppVersionId, pError))

DECL_PROXY(int, SteamInsertAppDependency, (unsigned int uAppId, unsigned int unknown1, unsigned int unknown2, TSteamError *pError))
	::Log("[%s]\tSteamInsertAppDependency( uAppId? = %d, unknown1 = \"%s\" (%d), unknown2 = \"%s\" (%d) )\n", callerModule.szModule, uAppId, (char*)unknown1, unknown1, (char*)unknown2, unknown2);
RETURN_PROXY(SteamInsertAppDependency, (uAppId, unknown1, unknown2, pError))

DECL_PROXY(int, SteamNumAppsRunning, (unsigned int unknown))
	::Log("[%s]\tSteamNumAppsRunning( unknown = %d )\n", (char*)unknown, unknown);
RETURN_PROXY(SteamNumAppsRunning, (unknown))

PROXY(int, SteamFindApp, (), ())

PROXY(SteamCallHandle_t, SteamSetNewPassword, ( const char *cszUser, const char *cszAnswerToQuestion, const SteamSalt_t *cpSaltForAnswer, const char *cszNewPassphrase, int *pbChanged, TSteamError *pError ), ( cszUser, cszAnswerToQuestion, cpSaltForAnswer, cszNewPassphrase, pbChanged, pError))
PROXY(SteamCallHandle_t, SteamGetPersonalQuestion, ( const char *cszUser, SteamPersonalQuestion_t PersonalQuestion, SteamSalt_t *pSaltForAnswer, TSteamError *pError ), (cszUser, PersonalQuestion, pSaltForAnswer, pError))

PROXY(SteamCallHandle_t, SteamEmailVerified, ( const char *cszEmailVerificationKey, int *pbVerified, TSteamError *pError ), (cszEmailVerificationKey, pbVerified, pError))
PROXY(SteamCallHandle_t, SteamSendVerificationEmail, ( int *pbSent, TSteamError *pError ), (pbSent, pError))




DECL_PROXY(int, SteamWriteMiniDumpFromAssert, (unsigned int a1, unsigned int a2, unsigned int a3, const char *szMessage, const char *szFile))
	::Log("[%s]\tSteamWriteMiniDumpFromAssert( a1 = %d, a2 = %d, a3 = %d, szMessage = \"%s\" , szFile = \"%s\" )", callerModule.szModule, a1,  a2, a3, szMessage, szFile );
RETURN_PROXY(SteamWriteMiniDumpFromAssert, (a1, a2, a3, szMessage, szFile))

PROXY(int, SteamWriteMiniDumpSetComment, ( const char *cszComment ), (cszComment))
PROXY(int, SteamWriteMiniDumpUsingExceptionInfo, (), ())
PROXY(int, SteamWriteMiniDumpUsingExceptionInfoWithBuildId, (), ())




PROXY(void, SteamClearError, ( TSteamError *pError ), (pError))

PROXY(int, InternalSteamNumClientsConnectedToEngine, (TSteamError *pError), (pError))
PROXY(int, InternalSteamShouldShutdownEngine2, (), ())

PROXY(int, SteamChangeOfflineStatus, (), ())
PROXY(int, SteamGetOfflineStatus, ( unsigned int* buIsOffline, TSteamError *pError ), (buIsOffline, pError))

PROXY(SteamCallHandle_t, SteamUninstall, ( TSteamError *pError ), (pError))

PROXY(int, SteamWeakVerifyNewValveCDKey, (), ())
PROXY(int, SteamGetEncryptedNewValveCDKey,( const char *cszValveCDkey, int *pnGameCode, uint32 *puTerritoryCode, void *pUniqueSerialNumber ), (cszValveCDkey, pnGameCode, puTerritoryCode, pUniqueSerialNumber))

PROXY( ESteamError, SteamDecryptDataForThisMachine, ( const uint8 *pEncryptedData, uint32 uEncryptedDataSize, uint8 *pDecryptedBuffer, uint32 uDecryptedBufferSize, uint32 *puDecryptedDataSize ), (pEncryptedData, uEncryptedDataSize, pDecryptedBuffer, uDecryptedBufferSize, puDecryptedDataSize))
PROXY( ESteamError, SteamEncryptDataForThisMachine, ( const uint8 *pPlaintextData, uint32 uPlaintextDataSize, uint8 *pEncryptedBuffer, uint32 uEncryptedBufferSize, uint32 *puEncryptedDataSize ), (pPlaintextData, uPlaintextDataSize, pEncryptedBuffer, uEncryptedBufferSize, puEncryptedDataSize ))

PROXY(int, SteamFindServersGetErrorString,(), ())
PROXY(int, SteamFindServersIterateServer, ( int arg1, int arg2, char *szServerAddress, unsigned int uServerAddressChars ), (arg1, arg2, szServerAddress, uServerAddressChars))
PROXY(int, SteamFindServersNumServers, ( unsigned int arg1 ), (arg1))

PROXY(int, SteamGetContentServerInfo,(), ())

PROXY(int, SteamRefreshMinimumFootprintFiles, (), ())

PROXY(int, SteamSetNotificationCallback, ( SteamNotificationCallback_t pCallbackFunction, TSteamError *pError ), (pCallbackFunction, pError))


PROXY(int, SteamRefreshAccountInfo2, (), ())
PROXY(int, SteamGetCachePercentFragmentation, (), ())
PROXY(int, SteamGetAppDLCStatus, (), ())

DECL_PROXY(int, SteamIsUsingSdkContentServer, (int unknown, TSteamError *pError))
	::Log("[%s]\tSteamIsUsingSdkContentserver( unknown = %d )\n", callerModule.szModule, unknown);
RETURN_PROXY(SteamIsUsingSdkContentServer, (unknown, pError))

PROXY(int, SteamIsFileNeededByApp, (), ())
PROXY(int, SteamFindFirst64, (), ())
PROXY(int, SteamFindNext64, (), ())
PROXY(int, SteamForceCellId, (), ())
PROXY(int, SteamDefragCaches, (), ())
PROXY(int, SteamWaitForAppResources, (), ())
PROXY(int, SteamOpenFile64, (), ())
PROXY(int, SteamSizeFile64, (), ())

DECL_PROXY(int, SteamWasBlobRegistryDeleted, (unsigned int unknown, TSteamError *pError))
	::Log("[%s]\tSteamWasBlobRegistryDeleted( unknown = %d )\n", callerModule.szModule, unknown);
RETURN_PROXY(SteamWasBlobRegistryDeleted, (unknown, pError))


BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved )
{
	switch ( fdwReason )
	{

	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		//Cleanup();
		break;

	}

	return TRUE;
}
