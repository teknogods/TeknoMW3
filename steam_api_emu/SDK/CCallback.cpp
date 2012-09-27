#include "CCallback.h"

	virtual destructor because we export this binary interface across dll's	virtual void  Run ( void *pvParam )	{
		char log[1024];
		sprintf(log,"Run() pvParam=0x%X ",
			pvParam		);
		OutputDebugStringA(log);
		pvParam);
		OutputDebugStringA("\n");
	}
	virtual void  Run ( void *pvParam,  bool bIOFailure,  SteamAPICall_t hSteamAPICall )	{
		char log[1024];
		sprintf(log,"Run() pvParam=0x%X bIOFailure=0x%X hSteamAPICall=0x%X ",
			pvParam,
			bIOFailure,
			hSteamAPICall		);
		OutputDebugStringA(log);
		pvParam, bIOFailure, hSteamAPICall);
		OutputDebugStringA("\n");
	}
	virtual int  GetCallbackSizeBytes ()	{
		char log[1024];
		sprintf(log,"GetCallbackSizeBytes() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetCallbackSizeBytes();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  Run ( void *pvParam )	{
		char log[1024];
		sprintf(log,"Run() pvParam=0x%X ",
			pvParam		);
		OutputDebugStringA(log);
		pvParam);
		OutputDebugStringA("\n");
	}
	virtual void  Run ( void *pvParam )	{		(m_pObj->*m_Func)( (P *)pvParam )	{
		char log[1024];
		sprintf(log,"Run() )pvParam=0x%X ",
			)pvParam		);
		OutputDebugStringA(log);
		)pvParam);
		OutputDebugStringA("\n");
	}
	virtual void  Run ( void *pvParam,  bool,  SteamAPICall_t )	{		(m_pObj->*m_Func)( (P *)pvParam )	{
		char log[1024];
		sprintf(log,"Run() pvParam=0x%X bool=0x%X )pvParam=0x%X ",
			pvParam,
			bool,
			)pvParam		);
		OutputDebugStringA(log);
		pvParam, bool, )pvParam);
		OutputDebugStringA("\n");
	}
};
