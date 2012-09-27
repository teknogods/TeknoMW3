#include "ISteamUser011.h"

class ISteamUser011_wrapper
{
public:
	virtual HSteamUser  GetHSteamUser ()	{
		char log[1024];
		sprintf(log,"GetHSteamUser() "		);
		OutputDebugStringA(log);
		HSteamUser  ret = m_pWrapper->GetHSteamUser();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BLoggedOn ()	{
		char log[1024];
		sprintf(log,"BLoggedOn() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BLoggedOn();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetSteamID ()	{
		char log[1024];
		sprintf(log,"GetSteamID() "		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetSteamID();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  InitiateGameConnection ( void *pAuthBlob,  int cbMaxAuthBlob,  CSteamID steamIDGameServer,  uint32 unIPServer,  uint16 usPortServer,  bool bSecure )	{
		char log[1024];
		sprintf(log,"InitiateGameConnection() pAuthBlob=0x%X cbMaxAuthBlob=0x%X steamIDGameServer=0x%X unIPServer=0x%X usPortServer=0x%X bSecure=0x%X ",
			pAuthBlob,
			cbMaxAuthBlob,
			steamIDGameServer,
			unIPServer,
			usPortServer,
			bSecure		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->InitiateGameConnection(pAuthBlob, cbMaxAuthBlob, steamIDGameServer, unIPServer, usPortServer, bSecure);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  TerminateGameConnection ( uint32 unIPServer,  uint16 usPortServer )	{
		char log[1024];
		sprintf(log,"TerminateGameConnection() unIPServer=0x%X usPortServer=0x%X ",
			unIPServer,
			usPortServer		);
		OutputDebugStringA(log);
		unIPServer, usPortServer);
		OutputDebugStringA("\n");
	}
	virtual void  TrackAppUsageEvent ( CGameID gameID,  EAppUsageEvent eAppUsageEvent,  const char *pchExtraInfo = "" )	{
		char log[1024];
		sprintf(log,"TrackAppUsageEvent() gameID=0x%X eAppUsageEvent=0x%X ""=%s ",
			gameID,
			eAppUsageEvent,
			""		);
		OutputDebugStringA(log);
		gameID, eAppUsageEvent, "");
		OutputDebugStringA("\n");
	}
	virtual bool  GetUserDataFolder ( char *pchBuffer,  int cubBuffer )	{
		char log[1024];
		sprintf(log,"GetUserDataFolder() pchBuffer=%s cubBuffer=0x%X ",
			pchBuffer,
			cubBuffer		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserDataFolder(pchBuffer, cubBuffer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  StartVoiceRecording ( )	{
		char log[1024];
		sprintf(log,"StartVoiceRecording() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  StopVoiceRecording ( )	{
		char log[1024];
		sprintf(log,"StopVoiceRecording() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual EVoiceResult  GetCompressedVoice ( void *pDestBuffer,  uint32 cbDestBufferSize,  uint32 *nBytesWritten )	{
		char log[1024];
		sprintf(log,"GetCompressedVoice() pDestBuffer=0x%X cbDestBufferSize=0x%X nBytesWritten=0x%X ",
			pDestBuffer,
			cbDestBufferSize,
			nBytesWritten		);
		OutputDebugStringA(log);
		EVoiceResult  ret = m_pWrapper->GetCompressedVoice(pDestBuffer, cbDestBufferSize, nBytesWritten);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EVoiceResult  DecompressVoice ( void *pCompressed,  uint32 cbCompressed,  void *pDestBuffer,  uint32 cbDestBufferSize,  uint32 *nBytesWritten )	{
		char log[1024];
		sprintf(log,"DecompressVoice() pCompressed=0x%X cbCompressed=0x%X pDestBuffer=0x%X cbDestBufferSize=0x%X nBytesWritten=0x%X ",
			pCompressed,
			cbCompressed,
			pDestBuffer,
			cbDestBufferSize,
			nBytesWritten		);
		OutputDebugStringA(log);
		EVoiceResult  ret = m_pWrapper->DecompressVoice(pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
