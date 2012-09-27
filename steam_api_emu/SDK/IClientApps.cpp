#include "IClientApps.h"

	virtual int  GetAppData ( AppId_t unAppID,  const char *pchKey,  char *pchValue,  int cchValueMax )	{
		char log[1024];
		sprintf(log,"GetAppData() unAppID=0x%X pchKey=%s pchValue=%s cchValueMax=0x%X ",
			unAppID,
			pchKey,
			pchValue,
			cchValueMax		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppData(unAppID, pchKey, pchValue, cchValueMax);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual AppId_t  GetInternalAppIDFromGameID ( CGameID gameID )	{
		char log[1024];
		sprintf(log,"GetInternalAppIDFromGameID() gameID=0x%X ",
			gameID		);
		OutputDebugStringA(log);
		AppId_t  ret = m_pWrapper->GetInternalAppIDFromGameID(gameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RequestAppCallbacks ( bool bOnlyMultiplayerApps )	{
		char log[1024];
		sprintf(log,"RequestAppCallbacks() bOnlyMultiplayerApps=0x%X ",
			bOnlyMultiplayerApps		);
		OutputDebugStringA(log);
		bOnlyMultiplayerApps);
		OutputDebugStringA("\n");
	}
	virtual int  GetAppDataSection ( AppId_t unAppID,  EAppInfoSection eSection,  uint8 *pchBuffer,  int cbBufferMax,  bool bUseSymbolsAsKeys )	{
		char log[1024];
		sprintf(log,"GetAppDataSection() unAppID=0x%X eSection=0x%X pchBuffer=0x%X cbBufferMax=0x%X bUseSymbolsAsKeys=0x%X ",
			unAppID,
			eSection,
			pchBuffer,
			cbBufferMax,
			bUseSymbolsAsKeys		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetAppDataSection(unAppID, eSection, pchBuffer, cbBufferMax, bUseSymbolsAsKeys);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestAppInfoUpdate ( const AppId_t *pAppIDs,  int nNumAppIDs,  bool bForceUpdate )	{
		char log[1024];
		sprintf(log,"RequestAppInfoUpdate() pAppIDs=0x%X nNumAppIDs=0x%X bForceUpdate=0x%X ",
			pAppIDs,
			nNumAppIDs,
			bForceUpdate		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestAppInfoUpdate(pAppIDs, nNumAppIDs, bForceUpdate);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  NotifyAppEventTriggered ( AppId_t unAppID,  EAppEvent eAppEvent )	{
		char log[1024];
		sprintf(log,"NotifyAppEventTriggered() unAppID=0x%X eAppEvent=0x%X ",
			unAppID,
			eAppEvent		);
		OutputDebugStringA(log);
		unAppID, eAppEvent);
		OutputDebugStringA("\n");
	}
	virtual void  NotifyDlcInstalled ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"NotifyDlcInstalled() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		unAppID);
		OutputDebugStringA("\n");
	}
	virtual int  GetDLCCount ( AppId_t unAppID )	{
		char log[1024];
		sprintf(log,"GetDLCCount() unAppID=0x%X ",
			unAppID		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetDLCCount(unAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetDLCDataByIndex ( AppId_t unAppID,  int iIndex,  AppId_t* unDLCAppID,  bool *,  char *,  int)	{
		char log[1024];
		sprintf(log,"BGetDLCDataByIndex() unAppID=0x%X iIndex=0x%X unDLCAppID=0x%X =0x%X =%s int=0x%X ",
			unAppID,
			iIndex,
			unDLCAppID,
			,
			,
			int		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetDLCDataByIndex(unAppID, iIndex, unDLCAppID, , , int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BReloadLocalAppInfoOverrides ()	{
		char log[1024];
		sprintf(log,"BReloadLocalAppInfoOverrides() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BReloadLocalAppInfoOverrides();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
