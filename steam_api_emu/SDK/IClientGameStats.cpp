#include "IClientGameStats.h"

	virtual SteamAPICall_t  GetNewSession ( int8 nAccountType,  uint64 ullAccountID,  AppId_t nAppID,  RTime32 rtTimeStarted )	{
		char log[1024];
		sprintf(log,"GetNewSession() nAccountType=0x%X ullAccountID=0x%X nAppID=0x%X rtTimeStarted=0x%X ",
			nAccountType,
			ullAccountID,
			nAppID,
			rtTimeStarted		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetNewSession(nAccountType, ullAccountID, nAppID, rtTimeStarted);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  EndSession ( uint64 ulSessionID,  RTime32 rtTimeEnded,  int16 nReasonCode )	{
		char log[1024];
		sprintf(log,"EndSession() ulSessionID=0x%X rtTimeEnded=0x%X nReasonCode=0x%X ",
			ulSessionID,
			rtTimeEnded,
			nReasonCode		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->EndSession(ulSessionID, rtTimeEnded, nReasonCode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddSessionAttributeInt ( uint64 ulSessionID,  const char *pstrName,  int nData )	{
		char log[1024];
		sprintf(log,"AddSessionAttributeInt() ulSessionID=0x%X pstrName=%s nData=0x%X ",
			ulSessionID,
			pstrName,
			nData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddSessionAttributeInt(ulSessionID, pstrName, nData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddSessionAttributeString ( uint64 ulSessionID,  const char *pstrName,  const char *pstrData )	{
		char log[1024];
		sprintf(log,"AddSessionAttributeString() ulSessionID=0x%X pstrName=%s pstrData=%s ",
			ulSessionID,
			pstrName,
			pstrData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddSessionAttributeString(ulSessionID, pstrName, pstrData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddSessionAttributeFloat ( uint64 ulSessionID,  const char *pstrName,  float fData )	{
		char log[1024];
		sprintf(log,"AddSessionAttributeFloat() ulSessionID=0x%X pstrName=%s fData=0x%X ",
			ulSessionID,
			pstrName,
			fData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddSessionAttributeFloat(ulSessionID, pstrName, fData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddNewRow ( uint64 *pulRowID,  uint64 ulSessionID,  const char *pstrTableName )	{
		char log[1024];
		sprintf(log,"AddNewRow() pulRowID=0x%X ulSessionID=0x%X pstrTableName=%s ",
			pulRowID,
			ulSessionID,
			pstrTableName		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddNewRow(pulRowID, ulSessionID, pstrTableName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  CommitRow ( uint64 ulRowID )	{
		char log[1024];
		sprintf(log,"CommitRow() ulRowID=0x%X ",
			ulRowID		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->CommitRow(ulRowID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  CommitOutstandingRows ( uint64 ulSessionID )	{
		char log[1024];
		sprintf(log,"CommitOutstandingRows() ulSessionID=0x%X ",
			ulSessionID		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->CommitOutstandingRows(ulSessionID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddRowAttributeInt ( uint64 ulRowID,  const char *pstrName,  int iData )	{
		char log[1024];
		sprintf(log,"AddRowAttributeInt() ulRowID=0x%X pstrName=%s iData=0x%X ",
			ulRowID,
			pstrName,
			iData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddRowAttributeInt(ulRowID, pstrName, iData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddRowAtributeString ( uint64 ulRowID,  const char *pstrName,  const char *pstrData )	{
		char log[1024];
		sprintf(log,"AddRowAtributeString() ulRowID=0x%X pstrName=%s pstrData=%s ",
			ulRowID,
			pstrName,
			pstrData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddRowAtributeString(ulRowID, pstrName, pstrData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddRowAttributeFloat ( uint64 ulRowID,  const char *pstrName,  float fData )	{
		char log[1024];
		sprintf(log,"AddRowAttributeFloat() ulRowID=0x%X pstrName=%s fData=0x%X ",
			ulRowID,
			pstrName,
			fData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddRowAttributeFloat(ulRowID, pstrName, fData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddSessionAttributeInt64 ( uint64 ulSessionID,  const char *pstrName,  int64 llData )	{
		char log[1024];
		sprintf(log,"AddSessionAttributeInt64() ulSessionID=0x%X pstrName=%s llData=0x%X ",
			ulSessionID,
			pstrName,
			llData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddSessionAttributeInt64(ulSessionID, pstrName, llData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  AddRowAttributeInt64 ( uint64 ulRowID,  const char *pstrName,  int64 llData )	{
		char log[1024];
		sprintf(log,"AddRowAttributeInt64() ulRowID=0x%X pstrName=%s llData=0x%X ",
			ulRowID,
			pstrName,
			llData		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->AddRowAttributeInt64(ulRowID, pstrName, llData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  ReportString ( uint64 ulSessionID,  int32 iSeverity,  const char *cszFormat,  ... )	{
		char log[1024];
		sprintf(log,"ReportString() ulSessionID=0x%X iSeverity=0x%X cszFormat=%s ...=0x%X ",
			ulSessionID,
			iSeverity,
			cszFormat,
			...		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->ReportString(ulSessionID, iSeverity, cszFormat, ...);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  _ReportString ( uint64 ulSessionID,  int,  char const*,  int,  unsigned char const* )	{
		char log[1024];
		sprintf(log,"_ReportString() ulSessionID=0x%X int=0x%X =%s int=0x%X =%s ",
			ulSessionID,
			int,
			,
			int,
					);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->_ReportString(ulSessionID, int, , int, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  ReportStringAccumulated ( uint64 ulSessionID,  int32 iSeverity,  const char *cszFormat,  ... )	{
		char log[1024];
		sprintf(log,"ReportStringAccumulated() ulSessionID=0x%X iSeverity=0x%X cszFormat=%s ...=0x%X ",
			ulSessionID,
			iSeverity,
			cszFormat,
			...		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->ReportStringAccumulated(ulSessionID, iSeverity, cszFormat, ...);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  _ReportStringAccumulated ( uint64 ulSessionID,  int,  char const*,  int,  unsigned char const* )	{
		char log[1024];
		sprintf(log,"_ReportStringAccumulated() ulSessionID=0x%X int=0x%X =%s int=0x%X =%s ",
			ulSessionID,
			int,
			,
			int,
					);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->_ReportStringAccumulated(ulSessionID, int, , int, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  ReportBugScreenshot ( uint64 ulSessionID,  char const* szBugText,  int32 cubScreenshot,  const uint8* pubScreenshot )	{
		char log[1024];
		sprintf(log,"ReportBugScreenshot() ulSessionID=0x%X szBugText=%s cubScreenshot=0x%X pubScreenshot=0x%X ",
			ulSessionID,
			szBugText,
			cubScreenshot,
			pubScreenshot		);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->ReportBugScreenshot(ulSessionID, szBugText, cubScreenshot, pubScreenshot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
