#include "ISteam005.h"

class ISteam005_wrapper
{
public:
	virtual ~ISteam005_wrapper();
	virtual SteamCallHandle_t  ChangePassword (const char* cszCurrentPassphrase,  const char* cszNewPassphrase,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ChangePassword() cszCurrentPassphrase=%s cszNewPassphrase=%s pError=0x%X ",
			cszCurrentPassphrase,
			cszNewPassphrase,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->ChangePassword(cszCurrentPassphrase, cszNewPassphrase, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetCurrentEmailAddress (char* szEmailaddress,  unsigned int uBufSize,  unsigned int* puEmailaddressChars,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetCurrentEmailAddress() szEmailaddress=%s uBufSize=0x%X puEmailaddressChars=0x%X pError=0x%X ",
			szEmailaddress,
			uBufSize,
			puEmailaddressChars,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetCurrentEmailAddress(szEmailaddress, uBufSize, puEmailaddressChars, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  ChangePersonalQA (const char* cszCurrentPassphrase,  const char* cszNewPersonalQuestion,  const char* cszNewAnswerToQuestion,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ChangePersonalQA() cszCurrentPassphrase=%s cszNewPersonalQuestion=%s cszNewAnswerToQuestion=%s pError=0x%X ",
			cszCurrentPassphrase,
			cszNewPersonalQuestion,
			cszNewAnswerToQuestion,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->ChangePersonalQA(cszCurrentPassphrase, cszNewPersonalQuestion, cszNewAnswerToQuestion, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  ChangeEmailAddress (const char* cszNewEmailAddress,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ChangeEmailAddress() cszNewEmailAddress=%s pError=0x%X ",
			cszNewEmailAddress,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->ChangeEmailAddress(cszNewEmailAddress, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  VerifyEmailAddress (const char* cszEmailAddress,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"VerifyEmailAddress() cszEmailAddress=%s pError=0x%X ",
			cszEmailAddress,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->VerifyEmailAddress(cszEmailAddress, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  RequestEmailAddressVerificationEmail (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RequestEmailAddressVerificationEmail() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->RequestEmailAddressVerificationEmail(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  ChangeAccountName (const char* cszCurrentAccountName,  const char* cszNewAccountName,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ChangeAccountName() cszCurrentAccountName=%s cszNewAccountName=%s pError=0x%X ",
			cszCurrentAccountName,
			cszNewAccountName,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->ChangeAccountName(cszCurrentAccountName, cszNewAccountName, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  MountAppFilesystem (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"MountAppFilesystem() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->MountAppFilesystem(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  UnmountAppFilesystem (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"UnmountAppFilesystem() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->UnmountAppFilesystem(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamHandle_t  MountFilesystem (unsigned int uAppId,  const char* szMountPath,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"MountFilesystem() uAppId=0x%X szMountPath=%s pError=0x%X ",
			uAppId,
			szMountPath,
			pError		);
		OutputDebugStringA(log);
		SteamHandle_t  ret = m_pWrapper->MountFilesystem(uAppId, szMountPath, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  UnmountFilesystem (SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"UnmountFilesystem() hFile=0x%X pError=0x%X ",
			hFile,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->UnmountFilesystem(hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  Stat (const char* cszName,  TSteamElemInfo* pInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Stat() cszName=%s pInfo=0x%X pError=0x%X ",
			cszName,
			pInfo,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->Stat(cszName, pInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  SetvBuf (SteamHandle_t hFile,  void* pBuf,  ESteamBufferMethod eMethod,  unsigned int uBytes,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SetvBuf() hFile=0x%X pBuf=0x%X eMethod=0x%X uBytes=0x%X pError=0x%X ",
			hFile,
			pBuf,
			eMethod,
			uBytes,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->SetvBuf(hFile, pBuf, eMethod, uBytes, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  FlushFile (SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"FlushFile() hFile=0x%X pError=0x%X ",
			hFile,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->FlushFile(hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamHandle_t  OpenFile (const char* cszName,  const char* cszMode,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"OpenFile() cszName=%s cszMode=%s pError=0x%X ",
			cszName,
			cszMode,
			pError		);
		OutputDebugStringA(log);
		SteamHandle_t  ret = m_pWrapper->OpenFile(cszName, cszMode, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamHandle_t  OpenFileEx (const char* cszFileName,  const char* cszMode,  unsigned int* puSize,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"OpenFileEx() cszFileName=%s cszMode=%s puSize=0x%X pError=0x%X ",
			cszFileName,
			cszMode,
			puSize,
			pError		);
		OutputDebugStringA(log);
		SteamHandle_t  ret = m_pWrapper->OpenFileEx(cszFileName, cszMode, puSize, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamHandle_t  OpenTmpFile (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"OpenTmpFile() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		SteamHandle_t  ret = m_pWrapper->OpenTmpFile(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ClearError (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ClearError() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		pError);
		OutputDebugStringA("\n");
	}
	virtual int  GetVersion (char* szVersion,  unsigned int uVersionBufSize)	{
		char log[1024];
		sprintf(log,"GetVersion() szVersion=%s uVersionBufSize=0x%X ",
			szVersion,
			uVersionBufSize		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetVersion(szVersion, uVersionBufSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetOfflineStatus (TSteamOfflineStatus* pSteamOfflineStatus,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetOfflineStatus() pSteamOfflineStatus=0x%X pError=0x%X ",
			pSteamOfflineStatus,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetOfflineStatus(pSteamOfflineStatus, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  ChangeOfflineStatus (TSteamOfflineStatus* pSteamOfflineStatus,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ChangeOfflineStatus() pSteamOfflineStatus=0x%X pError=0x%X ",
			pSteamOfflineStatus,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->ChangeOfflineStatus(pSteamOfflineStatus, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  ProcessCall (SteamCallHandle_t handle,  TSteamProgress* pProgress,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ProcessCall() handle=0x%X pProgress=0x%X pError=0x%X ",
			handle,
			pProgress,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->ProcessCall(handle, pProgress, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  AbortCall (SteamCallHandle_t handle,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"AbortCall() handle=0x%X pError=0x%X ",
			handle,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->AbortCall(handle, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  BlockingCall (SteamCallHandle_t handle,  unsigned int uiProcessTickMS,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"BlockingCall() handle=0x%X uiProcessTickMS=0x%X pError=0x%X ",
			handle,
			uiProcessTickMS,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->BlockingCall(handle, uiProcessTickMS, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  SetMaxStallCount (unsigned int uNumStalls,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SetMaxStallCount() uNumStalls=0x%X pError=0x%X ",
			uNumStalls,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->SetMaxStallCount(uNumStalls, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  CloseFile (SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"CloseFile() hFile=0x%X pError=0x%X ",
			hFile,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->CloseFile(hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unsigned int  ReadFile (void* pBuf,  unsigned int uSize,  unsigned int uCount,  SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ReadFile() pBuf=0x%X uSize=0x%X uCount=0x%X hFile=0x%X pError=0x%X ",
			pBuf,
			uSize,
			uCount,
			hFile,
			pError		);
		OutputDebugStringA(log);
		unsigned int  ret = m_pWrapper->ReadFile(pBuf, uSize, uCount, hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unsigned int  WriteFile (const void* pBuf,  unsigned int uSize,  unsigned int uCount,  SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"WriteFile() pBuf=0x%X uSize=0x%X uCount=0x%X hFile=0x%X pError=0x%X ",
			pBuf,
			uSize,
			uCount,
			hFile,
			pError		);
		OutputDebugStringA(log);
		unsigned int  ret = m_pWrapper->WriteFile(pBuf, uSize, uCount, hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  Getc (SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Getc() hFile=0x%X pError=0x%X ",
			hFile,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->Getc(hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  Putc (int cChar,  SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Putc() cChar=0x%X hFile=0x%X pError=0x%X ",
			cChar,
			hFile,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->Putc(cChar, hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  SeekFile (SteamHandle_t hFile,  long lOffset,  ESteamSeekMethod sm,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SeekFile() hFile=0x%X lOffset=0x%X sm=0x%X pError=0x%X ",
			hFile,
			lOffset,
			sm,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->SeekFile(hFile, lOffset, sm, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual long  TellFile (SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"TellFile() hFile=0x%X pError=0x%X ",
			hFile,
			pError		);
		OutputDebugStringA(log);
		long  ret = m_pWrapper->TellFile(hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  SizeFile (SteamHandle_t hFile,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SizeFile() hFile=0x%X pError=0x%X ",
			hFile,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->SizeFile(hFile, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamHandle_t  FindFirst (const char* cszPattern,  ESteamFindFilter eFilter,  TSteamElemInfo* pFindInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"FindFirst() cszPattern=%s eFilter=0x%X pFindInfo=0x%X pError=0x%X ",
			cszPattern,
			eFilter,
			pFindInfo,
			pError		);
		OutputDebugStringA(log);
		SteamHandle_t  ret = m_pWrapper->FindFirst(cszPattern, eFilter, pFindInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  FindNext (SteamHandle_t hFind,  TSteamElemInfo* pFindInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"FindNext() hFind=0x%X pFindInfo=0x%X pError=0x%X ",
			hFind,
			pFindInfo,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->FindNext(hFind, pFindInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  FindClose (SteamHandle_t hFind,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"FindClose() hFind=0x%X pError=0x%X ",
			hFind,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->FindClose(hFind, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetLocalFileCopy (const char* cszName,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetLocalFileCopy() cszName=%s pError=0x%X ",
			cszName,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetLocalFileCopy(cszName, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  IsFileImmediatelyAvailable (const char* cszName,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsFileImmediatelyAvailable() cszName=%s pError=0x%X ",
			cszName,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsFileImmediatelyAvailable(cszName, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  HintResourceNeed (const char* cszHintList,  int bForgetEverything,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"HintResourceNeed() cszHintList=%s bForgetEverything=0x%X pError=0x%X ",
			cszHintList,
			bForgetEverything,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->HintResourceNeed(cszHintList, bForgetEverything, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  ForgetAllHints (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ForgetAllHints() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->ForgetAllHints(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  PauseCachePreloading (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"PauseCachePreloading() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->PauseCachePreloading(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  ResumeCachePreloading (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ResumeCachePreloading() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->ResumeCachePreloading(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  WaitForResources (const char* cszMasterList,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"WaitForResources() cszMasterList=%s pError=0x%X ",
			cszMasterList,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->WaitForResources(cszMasterList, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  StartEngine (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"StartEngine() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->StartEngine(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  ShutdownEngine (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ShutdownEngine() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->ShutdownEngine(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  Startup (unsigned int uUsingMask,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Startup() uUsingMask=0x%X pError=0x%X ",
			uUsingMask,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->Startup(uUsingMask, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  Cleanup (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Cleanup() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->Cleanup(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unsigned int  NumAppsRunning (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"NumAppsRunning() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		unsigned int  ret = m_pWrapper->NumAppsRunning(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  CreateAccount (const char* cszUser,  const char* cszPassphrase,  const char* cszCreationKey,  const char* cszPersonalQuestion,  const char* cszAnswerToQuestion,  const char* cszArg6,  int* pbCreated,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"CreateAccount() cszUser=%s cszPassphrase=%s cszCreationKey=%s cszPersonalQuestion=%s cszAnswerToQuestion=%s cszArg6=%s pbCreated=0x%X pError=0x%X ",
			cszUser,
			cszPassphrase,
			cszCreationKey,
			cszPersonalQuestion,
			cszAnswerToQuestion,
			cszArg6,
			pbCreated,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->CreateAccount(cszUser, cszPassphrase, cszCreationKey, cszPersonalQuestion, cszAnswerToQuestion, cszArg6, pbCreated, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  GenerateSuggestedAccountNames (const char* cszArg1,  const char* cszArg2,  char* szArg3,  unsigned int uArg4,  unsigned int* puArg5,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GenerateSuggestedAccountNames() cszArg1=%s cszArg2=%s szArg3=%s uArg4=0x%X puArg5=0x%X pError=0x%X ",
			cszArg1,
			cszArg2,
			szArg3,
			uArg4,
			puArg5,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->GenerateSuggestedAccountNames(cszArg1, cszArg2, szArg3, uArg4, puArg5, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  IsLoggedIn (int* pbIsLoggedIn,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsLoggedIn() pbIsLoggedIn=0x%X pError=0x%X ",
			pbIsLoggedIn,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsLoggedIn(pbIsLoggedIn, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  Logout (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Logout() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->Logout(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  IsSecureComputer (int* pbIsSecure,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsSecureComputer() pbIsSecure=0x%X pError=0x%X ",
			pbIsSecure,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsSecureComputer(pbIsSecure, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamHandle_t  CreateLogContext (const char* cszName)	{
		char log[1024];
		sprintf(log,"CreateLogContext() cszName=%s ",
			cszName		);
		OutputDebugStringA(log);
		SteamHandle_t  ret = m_pWrapper->CreateLogContext(cszName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  Log (SteamHandle_t hContext,  const char* cszMsg)	{
		char log[1024];
		sprintf(log,"Log() hContext=0x%X cszMsg=%s ",
			hContext,
			cszMsg		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->Log(hContext, cszMsg);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  LogResourceLoadStarted (const char* cszMsg)	{
		char log[1024];
		sprintf(log,"LogResourceLoadStarted() cszMsg=%s ",
			cszMsg		);
		OutputDebugStringA(log);
		cszMsg);
		OutputDebugStringA("\n");
	}
	virtual void  LogResourceLoadFinished (const char* cszMsg)	{
		char log[1024];
		sprintf(log,"LogResourceLoadFinished() cszMsg=%s ",
			cszMsg		);
		OutputDebugStringA(log);
		cszMsg);
		OutputDebugStringA("\n");
	}
	virtual SteamCallHandle_t  RefreshLogin (const char* cszPassphrase,  int bIsSecureComputer,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RefreshLogin() cszPassphrase=%s bIsSecureComputer=0x%X pError=0x%X ",
			cszPassphrase,
			bIsSecureComputer,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->RefreshLogin(cszPassphrase, bIsSecureComputer, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  VerifyPassword (const char* cszPasswordToVerify,  int* pbIsCorrectPassword,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"VerifyPassword() cszPasswordToVerify=%s pbIsCorrectPassword=0x%X pError=0x%X ",
			cszPasswordToVerify,
			pbIsCorrectPassword,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->VerifyPassword(cszPasswordToVerify, pbIsCorrectPassword, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetUserType (unsigned int* puUserType,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetUserType() puUserType=0x%X pError=0x%X ",
			puUserType,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetUserType(puUserType, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAppStats (TSteamAppStats* pAppStats,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppStats() pAppStats=0x%X pError=0x%X ",
			pAppStats,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppStats(pAppStats, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  IsAccountNameInUse (const char* cszUser,  int* pbInUse,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsAccountNameInUse() cszUser=%s pbInUse=0x%X pError=0x%X ",
			cszUser,
			pbInUse,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->IsAccountNameInUse(cszUser, pbInUse, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAppIds (unsigned int puIds[],  unsigned int uMaxIds,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppIds() puIds[]=0x%X uMaxIds=0x%X pError=0x%X ",
			puIds[],
			uMaxIds,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppIds(puIds[], uMaxIds, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSubscriptionStats (TSteamSubscriptionStats* pSubscriptionStats,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetSubscriptionStats() pSubscriptionStats=0x%X pError=0x%X ",
			pSubscriptionStats,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSubscriptionStats(pSubscriptionStats, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  RefreshAccountInfo (int bUseCachedInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RefreshAccountInfo() bUseCachedInfo=0x%X pError=0x%X ",
			bUseCachedInfo,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->RefreshAccountInfo(bUseCachedInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  Subscribe (unsigned int uSubscriptionId,  const TSteamSubscriptionBillingInfo* pSubscriptionBillingInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Subscribe() uSubscriptionId=0x%X pSubscriptionBillingInfo=0x%X pError=0x%X ",
			uSubscriptionId,
			pSubscriptionBillingInfo,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->Subscribe(uSubscriptionId, pSubscriptionBillingInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  Unsubscribe (unsigned int uSubscriptionId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Unsubscribe() uSubscriptionId=0x%X pError=0x%X ",
			uSubscriptionId,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->Unsubscribe(uSubscriptionId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSubscriptionReceipt (unsigned int uSubscriptionId ,  TSteamSubscriptionReceipt* pSteamSubscriptionReceipt,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetSubscriptionReceipt() uSubscriptionId=0x%X pSteamSubscriptionReceipt=0x%X pError=0x%X ",
			uSubscriptionId,
			pSteamSubscriptionReceipt,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSubscriptionReceipt(uSubscriptionId, pSteamSubscriptionReceipt, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAccountStatus (unsigned int* puAccountStatus,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAccountStatus() puAccountStatus=0x%X pError=0x%X ",
			puAccountStatus,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAccountStatus(puAccountStatus, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  SetUser (const char* cszUser,  int* pbUserSet,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SetUser() cszUser=%s pbUserSet=0x%X pError=0x%X ",
			cszUser,
			pbUserSet,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->SetUser(cszUser, pbUserSet, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetUser (char* szUser,  unsigned int uBufSize,  unsigned int* puUserChars,  TSteamGlobalUserID* pSteamGlobalUserID,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetUser() szUser=%s uBufSize=0x%X puUserChars=0x%X pSteamGlobalUserID=0x%X pError=0x%X ",
			szUser,
			uBufSize,
			puUserChars,
			pSteamGlobalUserID,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetUser(szUser, uBufSize, puUserChars, pSteamGlobalUserID, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  Login (const char* cszUser,  const char* cszPassphrase,  int bIsSecureComputer,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Login() cszUser=%s cszPassphrase=%s bIsSecureComputer=0x%X pError=0x%X ",
			cszUser,
			cszPassphrase,
			bIsSecureComputer,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->Login(cszUser, cszPassphrase, bIsSecureComputer, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  AckSubscriptionReceipt (unsigned int uArg1,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"AckSubscriptionReceipt() uArg1=0x%X pError=0x%X ",
			uArg1,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->AckSubscriptionReceipt(uArg1, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  IsAppSubscribed (unsigned int uAppId,  int* pbIsAppSubscribed,  int* pReserved,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsAppSubscribed() uAppId=0x%X pbIsAppSubscribed=0x%X pReserved=0x%X pError=0x%X ",
			uAppId,
			pbIsAppSubscribed,
			pReserved,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsAppSubscribed(uAppId, pbIsAppSubscribed, pReserved, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSubscriptionIds (unsigned int puIds[],  unsigned int uMaxIds,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetSubscriptionIds() puIds[]=0x%X uMaxIds=0x%X pError=0x%X ",
			puIds[],
			uMaxIds,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSubscriptionIds(puIds[], uMaxIds, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateSubscription (unsigned int uSubscriptionId,  TSteamSubscription* pSubscription,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateSubscription() uSubscriptionId=0x%X pSubscription=0x%X pError=0x%X ",
			uSubscriptionId,
			pSubscription,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateSubscription(uSubscriptionId, pSubscription, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateSubscriptionDiscount (unsigned int uSubscriptionId,  unsigned int uDiscountIdx,  TSteamSubscriptionDiscount* pSteamSubscriptionDiscount,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateSubscriptionDiscount() uSubscriptionId=0x%X uDiscountIdx=0x%X pSteamSubscriptionDiscount=0x%X pError=0x%X ",
			uSubscriptionId,
			uDiscountIdx,
			pSteamSubscriptionDiscount,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateSubscriptionDiscount(uSubscriptionId, uDiscountIdx, pSteamSubscriptionDiscount, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateSubscriptionDiscountQualifier (unsigned int uSubscriptionId,  unsigned int uDiscountIdx,  unsigned int uQualifierIdx,  TSteamDiscountQualifier* pSteamDiscountQualifier,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateSubscriptionDiscountQualifier() uSubscriptionId=0x%X uDiscountIdx=0x%X uQualifierIdx=0x%X pSteamDiscountQualifier=0x%X pError=0x%X ",
			uSubscriptionId,
			uDiscountIdx,
			uQualifierIdx,
			pSteamDiscountQualifier,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateSubscriptionDiscountQualifier(uSubscriptionId, uDiscountIdx, uQualifierIdx, pSteamDiscountQualifier, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateApp (unsigned int uAppId,  TSteamApp* pApp,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateApp() uAppId=0x%X pApp=0x%X pError=0x%X ",
			uAppId,
			pApp,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateApp(uAppId, pApp, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateAppLaunchOption (unsigned int uAppId,  unsigned int uLaunchOptionIndex,  TSteamAppLaunchOption* pLaunchOption,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateAppLaunchOption() uAppId=0x%X uLaunchOptionIndex=0x%X pLaunchOption=0x%X pError=0x%X ",
			uAppId,
			uLaunchOptionIndex,
			pLaunchOption,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateAppLaunchOption(uAppId, uLaunchOptionIndex, pLaunchOption, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  DeleteAccount (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"DeleteAccount() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->DeleteAccount(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateAppIcon (unsigned int uAppId,  unsigned int uIconIndex,  unsigned char* pIconData,  unsigned int uIconDataBufSize,   unsigned int* puSizeOfIconData,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateAppIcon() uAppId=0x%X uIconIndex=0x%X pIconData=%s uIconDataBufSize=0x%X puSizeOfIconData=0x%X pError=0x%X ",
			uAppId,
			uIconIndex,
			pIconData,
			uIconDataBufSize,
			puSizeOfIconData,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateAppIcon(uAppId, uIconIndex, pIconData, uIconDataBufSize, puSizeOfIconData, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  LaunchApp (unsigned int uAppId,  unsigned int uLaunchOption,  const char* cszArgs,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"LaunchApp() uAppId=0x%X uLaunchOption=0x%X cszArgs=%s pError=0x%X ",
			uAppId,
			uLaunchOption,
			cszArgs,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->LaunchApp(uAppId, uLaunchOption, cszArgs, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetCacheFilePath (unsigned int uAppId,   char* szFilePath,  unsigned int uBufferLength,  unsigned int* puRecievedLength,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetCacheFilePath() uAppId=0x%X szFilePath=%s uBufferLength=0x%X puRecievedLength=0x%X pError=0x%X ",
			uAppId,
			szFilePath,
			uBufferLength,
			puRecievedLength,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetCacheFilePath(uAppId, szFilePath, uBufferLength, puRecievedLength, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateAppVersion (unsigned int uAppId,  unsigned int uVersionIndex,  TSteamAppVersion* pAppVersion,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateAppVersion() uAppId=0x%X uVersionIndex=0x%X pAppVersion=0x%X pError=0x%X ",
			uAppId,
			uVersionIndex,
			pAppVersion,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateAppVersion(uAppId, uVersionIndex, pAppVersion, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  EnumerateAppDependency (unsigned int uAppId,  unsigned int uDependency,  TSteamAppDependencyInfo* pDependencyInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"EnumerateAppDependency() uAppId=0x%X uDependency=0x%X pDependencyInfo=0x%X pError=0x%X ",
			uAppId,
			uDependency,
			pDependencyInfo,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->EnumerateAppDependency(uAppId, uDependency, pDependencyInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  StartLoadingCache (unsigned int uAppId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"StartLoadingCache() uAppId=0x%X pError=0x%X ",
			uAppId,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->StartLoadingCache(uAppId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  InsertAppDependency (unsigned int uAppId,  unsigned int uFileSystemIndex,  TSteamAppDependencyInfo* pDependencyInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"InsertAppDependency() uAppId=0x%X uFileSystemIndex=0x%X pDependencyInfo=0x%X pError=0x%X ",
			uAppId,
			uFileSystemIndex,
			pDependencyInfo,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->InsertAppDependency(uAppId, uFileSystemIndex, pDependencyInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  RemoveAppDependency (unsigned int uAppId,  unsigned int uFileSystemIndex,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RemoveAppDependency() uAppId=0x%X uFileSystemIndex=0x%X pError=0x%X ",
			uAppId,
			uFileSystemIndex,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->RemoveAppDependency(uAppId, uFileSystemIndex, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  FindApp (const char* cszAppName,  unsigned int* puAppId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"FindApp() cszAppName=%s puAppId=0x%X pError=0x%X ",
			cszAppName,
			puAppId,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->FindApp(cszAppName, puAppId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAppDependencies (unsigned int uAppId,  unsigned int puDependecies[],  unsigned int uBufferLength,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppDependencies() uAppId=0x%X puDependecies[]=0x%X uBufferLength=0x%X pError=0x%X ",
			uAppId,
			puDependecies[],
			uBufferLength,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppDependencies(uAppId, puDependecies[], uBufferLength, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  IsSubscribed (unsigned int uSubscriptionId,  int* pbIsSubscribed,  int* pReserved,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsSubscribed() uSubscriptionId=0x%X pbIsSubscribed=0x%X pReserved=0x%X pError=0x%X ",
			uSubscriptionId,
			pbIsSubscribed,
			pReserved,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsSubscribed(uSubscriptionId, pbIsSubscribed, pReserved, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAppUserDefinedInfo (unsigned int uAppId,  const char* cszPropertyName,  char* szPropertyValue,  unsigned int uBufSize,  unsigned int* puPropertyValueLength,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppUserDefinedInfo() uAppId=0x%X cszPropertyName=%s szPropertyValue=%s uBufSize=0x%X puPropertyValueLength=0x%X pError=0x%X ",
			uAppId,
			cszPropertyName,
			szPropertyValue,
			uBufSize,
			puPropertyValueLength,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppUserDefinedInfo(uAppId, cszPropertyName, szPropertyValue, uBufSize, puPropertyValueLength, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  WaitForAppReadyToLaunch (unsigned int uAppId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"WaitForAppReadyToLaunch() uAppId=0x%X pError=0x%X ",
			uAppId,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->WaitForAppReadyToLaunch(uAppId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  IsCacheLoadingEnabled (unsigned int uAppId,  int* pbIsLoading,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsCacheLoadingEnabled() uAppId=0x%X pbIsLoading=0x%X pError=0x%X ",
			uAppId,
			pbIsLoading,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsCacheLoadingEnabled(uAppId, pbIsLoading, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  StopLoadingCache (unsigned int uAppId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"StopLoadingCache() uAppId=0x%X pError=0x%X ",
			uAppId,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->StopLoadingCache(uAppId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ESteamError  GetEncryptedUserIDTicket (const void* pEncryptionKeyReceivedFromAppServer,  unsigned int uEncryptionKeyLength,  void* pOutputBuffer,  unsigned int uSizeOfOutputBuffer,  unsigned int* pReceiveSizeOfEncryptedTicket,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetEncryptedUserIDTicket() pEncryptionKeyReceivedFromAppServer=0x%X uEncryptionKeyLength=0x%X pOutputBuffer=0x%X uSizeOfOutputBuffer=0x%X pReceiveSizeOfEncryptedTicket=0x%X pError=0x%X ",
			pEncryptionKeyReceivedFromAppServer,
			uEncryptionKeyLength,
			pOutputBuffer,
			uSizeOfOutputBuffer,
			pReceiveSizeOfEncryptedTicket,
			pError		);
		OutputDebugStringA(log);
		ESteamError  ret = m_pWrapper->GetEncryptedUserIDTicket(pEncryptionKeyReceivedFromAppServer, uEncryptionKeyLength, pOutputBuffer, uSizeOfOutputBuffer, pReceiveSizeOfEncryptedTicket, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  FlushCache (unsigned int uAppId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"FlushCache() uAppId=0x%X pError=0x%X ",
			uAppId,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->FlushCache(uAppId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  RepairOrDecryptCaches (unsigned int uAppId,  int iArg2,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RepairOrDecryptCaches() uAppId=0x%X iArg2=0x%X pError=0x%X ",
			uAppId,
			iArg2,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->RepairOrDecryptCaches(uAppId, iArg2, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  LoadCacheFromDir (unsigned int uAppId,  const char* cszPath,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"LoadCacheFromDir() uAppId=0x%X cszPath=%s pError=0x%X ",
			uAppId,
			cszPath,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->LoadCacheFromDir(uAppId, cszPath, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetCacheDefaultDirectory (char* szPath,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetCacheDefaultDirectory() szPath=%s pError=0x%X ",
			szPath,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetCacheDefaultDirectory(szPath, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  SetCacheDefaultDirectory (const char* cszPath,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SetCacheDefaultDirectory() cszPath=%s pError=0x%X ",
			cszPath,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->SetCacheDefaultDirectory(cszPath, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAppDir (unsigned int uAppId,  char* szAppDir,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppDir() uAppId=0x%X szAppDir=%s pError=0x%X ",
			uAppId,
			szAppDir,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppDir(uAppId, szAppDir, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  MoveApp (unsigned int uAppId,  const char* szPath,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"MoveApp() uAppId=0x%X szPath=%s pError=0x%X ",
			uAppId,
			szPath,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->MoveApp(uAppId, szPath, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  GetAppCacheSize (unsigned int uAppId,  unsigned int* puCacheSizeInMb,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppCacheSize() uAppId=0x%X puCacheSizeInMb=0x%X pError=0x%X ",
			uAppId,
			puCacheSizeInMb,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->GetAppCacheSize(uAppId, puCacheSizeInMb, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  SetAppCacheSize (unsigned int uAppId,  unsigned int uCacheSizeInMb,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SetAppCacheSize() uAppId=0x%X uCacheSizeInMb=0x%X pError=0x%X ",
			uAppId,
			uCacheSizeInMb,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->SetAppCacheSize(uAppId, uCacheSizeInMb, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  SetAppVersion (unsigned int uAppId,  unsigned int uAppVersionId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SetAppVersion() uAppId=0x%X uAppVersionId=0x%X pError=0x%X ",
			uAppId,
			uAppVersionId,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->SetAppVersion(uAppId, uAppVersionId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  Uninstall (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"Uninstall() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->Uninstall(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  SetNotificationCallback (SteamNotificationCallback_t pCallbackFunction,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"SetNotificationCallback() pCallbackFunction=0x%X pError=0x%X ",
			pCallbackFunction,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->SetNotificationCallback(pCallbackFunction, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  ChangeForgottenPassword (const char* cszArg1,  const char* cszArg2,  const char* cszArg3,  const char* cszArg4,  int* piArg5,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"ChangeForgottenPassword() cszArg1=%s cszArg2=%s cszArg3=%s cszArg4=%s piArg5=0x%X pError=0x%X ",
			cszArg1,
			cszArg2,
			cszArg3,
			cszArg4,
			piArg5,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->ChangeForgottenPassword(cszArg1, cszArg2, cszArg3, cszArg4, piArg5, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  RequestForgottenPasswordEmail (const char* cszArg1,  char* szArg2,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RequestForgottenPasswordEmail() cszArg1=%s szArg2=%s pError=0x%X ",
			cszArg1,
			szArg2,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->RequestForgottenPasswordEmail(cszArg1, szArg2, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  RequestAccountsByEmailAddressEmail (const char* cszArg1,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RequestAccountsByEmailAddressEmail() cszArg1=%s pError=0x%X ",
			cszArg1,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->RequestAccountsByEmailAddressEmail(cszArg1, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  RequestAccountsByCdKeyEmail (const char* cszArg1,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"RequestAccountsByCdKeyEmail() cszArg1=%s pError=0x%X ",
			cszArg1,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->RequestAccountsByCdKeyEmail(cszArg1, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  GetNumAccountsWithEmailAddress (const char *cszEmailAddress,  unsigned int *puNumAccounts,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetNumAccountsWithEmailAddress() cszEmailAddress=%s puNumAccounts=0x%X pError=0x%X ",
			cszEmailAddress,
			puNumAccounts,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->GetNumAccountsWithEmailAddress(cszEmailAddress, puNumAccounts, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  UpdateAccountBillingInfo (const TSteamPaymentCardInfo* pPaymentCardInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"UpdateAccountBillingInfo() pPaymentCardInfo=0x%X pError=0x%X ",
			pPaymentCardInfo,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->UpdateAccountBillingInfo(pPaymentCardInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  UpdateSubscriptionBillingInfo (unsigned int uSubscriptionId,  const TSteamSubscriptionBillingInfo* pSubscriptionBillingInfo,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"UpdateSubscriptionBillingInfo() uSubscriptionId=0x%X pSubscriptionBillingInfo=0x%X pError=0x%X ",
			uSubscriptionId,
			pSubscriptionBillingInfo,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->UpdateSubscriptionBillingInfo(uSubscriptionId, pSubscriptionBillingInfo, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSponsorUrl (unsigned int uAppId,  char* szUrl,  unsigned int uBufSize,  unsigned int* pUrlChars,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetSponsorUrl() uAppId=0x%X szUrl=%s uBufSize=0x%X pUrlChars=0x%X pError=0x%X ",
			uAppId,
			szUrl,
			uBufSize,
			pUrlChars,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSponsorUrl(uAppId, szUrl, uBufSize, pUrlChars, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetContentServerInfo (unsigned int uArg1,  unsigned int* puArg2,  unsigned int* puArg3,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetContentServerInfo() uArg1=0x%X puArg2=0x%X puArg3=0x%X pError=0x%X ",
			uArg1,
			puArg2,
			puArg3,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetContentServerInfo(uArg1, puArg2, puArg3, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  GetAppUpdateStats (unsigned int uAppId,  ESteamAppUpdateStatsQueryType eSteamAppUpdateStatsQueryType,  TSteamUpdateStats* pUpdateStats,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppUpdateStats() uAppId=0x%X eSteamAppUpdateStatsQueryType=0x%X pUpdateStats=0x%X pError=0x%X ",
			uAppId,
			eSteamAppUpdateStatsQueryType,
			pUpdateStats,
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->GetAppUpdateStats(uAppId, eSteamAppUpdateStatsQueryType, pUpdateStats, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetTotalUpdateStats (TSteamUpdateStats* pUpdateStats,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetTotalUpdateStats() pUpdateStats=0x%X pError=0x%X ",
			pUpdateStats,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetTotalUpdateStats(pUpdateStats, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamCallHandle_t  CreateCachePreloaders (TSteamError* pError)	{
		char log[1024];
		sprintf(log,"CreateCachePreloaders() pError=0x%X ",
			pError		);
		OutputDebugStringA(log);
		SteamCallHandle_t  ret = m_pWrapper->CreateCachePreloaders(pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  Win32SetMiniDumpComment (const char* cszComment)	{
		char log[1024];
		sprintf(log,"Win32SetMiniDumpComment() cszComment=%s ",
			cszComment		);
		OutputDebugStringA(log);
		cszComment);
		OutputDebugStringA("\n");
	}
	virtual void  Win32SetMiniDumpSourceControlId (unsigned int uSourceControlId)	{
		char log[1024];
		sprintf(log,"Win32SetMiniDumpSourceControlId() uSourceControlId=0x%X ",
			uSourceControlId		);
		OutputDebugStringA(log);
		uSourceControlId);
		OutputDebugStringA("\n");
	}
	virtual void  Win32SetMiniDumpEnableFullMemory ()	{
		char log[1024];
		sprintf(log,"Win32SetMiniDumpEnableFullMemory() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  Win32WriteMiniDump (const char*,  const char*,  const char*,  const char*,  unsigned int)	{
		char log[1024];
		sprintf(log,"Win32WriteMiniDump() =%s =%s =%s =%s int=0x%X ",
			,
			,
			,
			,
			int		);
		OutputDebugStringA(log);
		, , , , int);
		OutputDebugStringA("\n");
	}
	virtual int  GetCurrentAppId (unsigned int* puAppId,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetCurrentAppId() puAppId=0x%X pError=0x%X ",
			puAppId,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetCurrentAppId(puAppId, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAppPurchaseCountry (unsigned int uAppId,  char* szCountryCode,  unsigned int uBufferLength,  int* piRecievedLength,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppPurchaseCountry() uAppId=0x%X szCountryCode=%s uBufferLength=0x%X piRecievedLength=0x%X pError=0x%X ",
			uAppId,
			szCountryCode,
			uBufferLength,
			piRecievedLength,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppPurchaseCountry(uAppId, szCountryCode, uBufferLength, piRecievedLength, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	ISteam005_wrapper();
	virtual int  GetLocalClientVersion (unsigned int* puBootStrapperVersionNum,  unsigned int* puClientAppVersionNum,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetLocalClientVersion() puBootStrapperVersionNum=0x%X puClientAppVersionNum=0x%X pError=0x%X ",
			puBootStrapperVersionNum,
			puClientAppVersionNum,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetLocalClientVersion(puBootStrapperVersionNum, puClientAppVersionNum, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  IsFileNeededByCache (unsigned int uCacheId,  const char* cszFileName,  unsigned int uFileSize,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"IsFileNeededByCache() uCacheId=0x%X cszFileName=%s uFileSize=0x%X pError=0x%X ",
			uCacheId,
			cszFileName,
			uFileSize,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsFileNeededByCache(uCacheId, cszFileName, uFileSize, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  LoadFileToCache (unsigned int uArg1,  const char* cszArg2,  const void* pcvArg3,  unsigned int uArg4,  unsigned int uArg5,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"LoadFileToCache() uArg1=0x%X cszArg2=%s pcvArg3=0x%X uArg4=0x%X uArg5=0x%X pError=0x%X ",
			uArg1,
			cszArg2,
			pcvArg3,
			uArg4,
			uArg5,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->LoadFileToCache(uArg1, cszArg2, pcvArg3, uArg4, uArg5, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetCacheDecryptionKey (unsigned int uAppId,  char* szCacheDecryptionKey,  unsigned int uBufferLength,  unsigned int* puRecievedLength,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetCacheDecryptionKey() uAppId=0x%X szCacheDecryptionKey=%s uBufferLength=0x%X puRecievedLength=0x%X pError=0x%X ",
			uAppId,
			szCacheDecryptionKey,
			uBufferLength,
			puRecievedLength,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetCacheDecryptionKey(uAppId, szCacheDecryptionKey, uBufferLength, puRecievedLength, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSubscriptionExtendedInfo (unsigned int uSubscriptionId,  const char* cszKeyName,  char* szKeyValue,  unsigned int uBufferLength,  unsigned int* puRecievedLength,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetSubscriptionExtendedInfo() uSubscriptionId=0x%X cszKeyName=%s szKeyValue=%s uBufferLength=0x%X puRecievedLength=0x%X pError=0x%X ",
			uSubscriptionId,
			cszKeyName,
			szKeyValue,
			uBufferLength,
			puRecievedLength,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSubscriptionExtendedInfo(uSubscriptionId, cszKeyName, szKeyValue, uBufferLength, puRecievedLength, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSubscriptionPurchaseCountry (unsigned int uSubscriptionId,  char* szCountry,  unsigned int uBufferLength ,  int* piRecievedLength,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetSubscriptionPurchaseCountry() uSubscriptionId=0x%X szCountry=%s uBufferLength=0x%X piRecievedLength=0x%X pError=0x%X ",
			uSubscriptionId,
			szCountry,
			uBufferLength,
			piRecievedLength,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSubscriptionPurchaseCountry(uSubscriptionId, szCountry, uBufferLength, piRecievedLength, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetAppUserDefinedRecord (unsigned int uAppId,  KeyValueIteratorCallback_t AddEntryToKeyValueFunc,  void* pvCKeyValue,  TSteamError* pError)	{
		char log[1024];
		sprintf(log,"GetAppUserDefinedRecord() uAppId=0x%X AddEntryToKeyValueFunc=0x%X pvCKeyValue=0x%X pError=0x%X ",
			uAppId,
			AddEntryToKeyValueFunc,
			pvCKeyValue,
			pError		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppUserDefinedRecord(uAppId, AddEntryToKeyValueFunc, pvCKeyValue, pError);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
