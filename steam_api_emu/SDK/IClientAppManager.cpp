#include "IClientAppManager.h"

	virtual bool  LaunchApp ( AppId_t unAppID,  uint32 uLaunchOption,  const char *cszArgs )	{
		char log[1024];
		sprintf(log,"LaunchApp() unAppID=0x%X uLaunchOption=0x%X cszArgs=%s ",
			unAppID,
			uLaunchOption,
			cszArgs		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->LaunchApp(unAppID, uLaunchOption, cszArgs);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ShutdownApp ( AppId_t unAppID,  bool bForce )	{
		char log[1024];
		sprintf(log,"ShutdownApp() unAppID=0x%X bForce=0x%X ",
			unAppID,
			bForce		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ShutdownApp(unAppID, bForce);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EAppState  GetAppState ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"GetAppState() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		EAppState  ret = m_pWrapper->GetAppState(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  InstallApp ( AppId_t unAppID,  bool )	{
		char log[1024];
		sprintf(log,"InstallApp() unAppID=0x%X bool=0x%X ",
			unAppID,
			bool		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InstallApp(unAppID, bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint64  GetAppSize ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"GetAppSize() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->GetAppSize(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetAppDir ( AppId_t unAppID,  char *szBuffer,  uint32 cubBuffer )	{
		char log[1024];
		sprintf(log,"GetAppDir() unAppID=0x%X szBuffer=%s cubBuffer=0x%X ",
			unAppID,
			szBuffer,
			cubBuffer		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetAppDir(unAppID, szBuffer, cubBuffer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UninstallApp ( AppId_t unAppID,  bool bComplete )	{
		char log[1024];
		sprintf(log,"UninstallApp() unAppID=0x%X bComplete=0x%X ",
			unAppID,
			bComplete		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UninstallApp(unAppID, bComplete);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetUpdateInfo ( AppId_t unAppID,  AppUpdateInfo_s *pUpdateInfo )	{
		char log[1024];
		sprintf(log,"GetUpdateInfo() unAppID=0x%X pUpdateInfo=0x%X ",
			unAppID,
			pUpdateInfo		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetUpdateInfo(unAppID, pUpdateInfo);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetContentLocked ( AppId_t unAppID,  bool bContentLocked )	{
		char log[1024];
		sprintf(log,"SetContentLocked() unAppID=0x%X bContentLocked=0x%X ",
			unAppID,
			bContentLocked		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetContentLocked(unAppID, bContentLocked);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  StartValidatingApp ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"StartValidatingApp() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->StartValidatingApp(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetAppConfig ( AppId_t unAppID,  uint8 *pchBuffer,  int cbBuffer,  bool bUseSymbolsAsKeys )	{
		char log[1024];
		sprintf(log,"SetAppConfig() unAppID=0x%X pchBuffer=0x%X cbBuffer=0x%X bUseSymbolsAsKeys=0x%X ",
			unAppID,
			pchBuffer,
			cbBuffer,
			bUseSymbolsAsKeys		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetAppConfig(unAppID, pchBuffer, cbBuffer, bUseSymbolsAsKeys);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsAppUpToDate ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"BIsAppUpToDate() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsAppUpToDate(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetDownloadingEnabled ( bool bEnabled )	{
		char log[1024];
		sprintf(log,"SetDownloadingEnabled() bEnabled=0x%X ",
			bEnabled		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetDownloadingEnabled(bEnabled);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsDownloadingEnabled ()	{
		char log[1024];
		sprintf(log,"BIsDownloadingEnabled() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsDownloadingEnabled();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetDownloadStats ( DownloadStats_s *pStats )	{
		char log[1024];
		sprintf(log,"GetDownloadStats() pStats=0x%X ",
			pStats		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetDownloadStats(pStats);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual AppId_t  GetDownloadingAppID ()	{
		char log[1024];
		sprintf(log,"GetDownloadingAppID() "		);
		OutputDebugStringA(log);
		AppId_t  ret = m_pWrapper->GetDownloadingAppID();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ChangeAppPriority ( AppId_t unAppID,  EAppDownloadPriority eDownloadPriority )	{
		char log[1024];
		sprintf(log,"ChangeAppPriority() unAppID=0x%X eDownloadPriority=0x%X ",
			unAppID,
			eDownloadPriority		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ChangeAppPriority(unAppID, eDownloadPriority);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddSteam2Update ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"AddSteam2Update() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddSteam2Update(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveSteam2Update ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"RemoveSteam2Update() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveSteam2Update(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  StalledSteam2Update ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"StalledSteam2Update() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->StalledSteam2Update(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BHasLocalContentServer ()	{
		char log[1024];
		sprintf(log,"BHasLocalContentServer() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BHasLocalContentServer();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BuildBackup ( AppId_t unAppID,  uint64 ullMaxFileSize,  const char *cszBackupPath )	{
		char log[1024];
		sprintf(log,"BuildBackup() unAppID=0x%X ullMaxFileSize=0x%X cszBackupPath=%s ",
			unAppID,
			ullMaxFileSize,
			cszBackupPath		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BuildBackup(unAppID, ullMaxFileSize, cszBackupPath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BuildInstaller ( const char *cszProjectFile,  const char *cszBackupPath )	{
		char log[1024];
		sprintf(log,"BuildInstaller() cszProjectFile=%s cszBackupPath=%s ",
			cszProjectFile,
			cszBackupPath		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BuildInstaller(cszProjectFile, cszBackupPath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  CancelBackup ()	{
		char log[1024];
		sprintf(log,"CancelBackup() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->CancelBackup();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RestoreApp ( AppId_t unAppID,  char const* cszBackupPath )	{
		char log[1024];
		sprintf(log,"RestoreApp() unAppID=0x%X cszBackupPath=%s ",
			unAppID,
			cszBackupPath		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RestoreApp(unAppID, cszBackupPath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BNeedsFile ( AppId_t unAppID,  char const* cszFilePath,  uint64 ullFileSize,  uint32 uUnk )	{
		char log[1024];
		sprintf(log,"BNeedsFile() unAppID=0x%X cszFilePath=%s ullFileSize=0x%X uUnk=0x%X ",
			unAppID,
			cszFilePath,
			ullFileSize,
			uUnk		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BNeedsFile(unAppID, cszFilePath, ullFileSize, uUnk);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BAddFileOnDisk ( AppId_t unAppID,  char const* cszFilePath,  uint64 ullFileSize,  uint32 uUnk,  SHADigestWrapper_t ubSha1 )	{
		char log[1024];
		sprintf(log,"BAddFileOnDisk() unAppID=0x%X cszFilePath=%s ullFileSize=0x%X uUnk=0x%X ubSha1=0x%X ",
			unAppID,
			cszFilePath,
			ullFileSize,
			uUnk,
			ubSha1		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BAddFileOnDisk(unAppID, cszFilePath, ullFileSize, uUnk, ubSha1);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint64  FinishAddingFiles ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"FinishAddingFiles() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->FinishAddingFiles(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
