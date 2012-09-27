#include "ISteamGameServer002.h"

class ISteamGameServer002_wrapper
{
public:
	virtual void  LogOn ()	{
		char log[1024];
		sprintf(log,"LogOn() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  LogOff ()	{
		char log[1024];
		sprintf(log,"LogOff() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
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
	virtual void  SetSpawnCount ( uint32 ucSpawn )	{
		char log[1024];
		sprintf(log,"SetSpawnCount() ucSpawn=0x%X ",
			ucSpawn		);
		OutputDebugStringA(log);
		ucSpawn);
		OutputDebugStringA("\n");
	}
	virtual bool  GetSteam2GetEncryptionKeyToSendToNewClient ( void *pvEncryptionKey,  uint32 *pcbEncryptionKey,  uint32 cbMaxEncryptionKey )	{
		char log[1024];
		sprintf(log,"GetSteam2GetEncryptionKeyToSendToNewClient() pvEncryptionKey=0x%X pcbEncryptionKey=0x%X cbMaxEncryptionKey=0x%X ",
			pvEncryptionKey,
			pcbEncryptionKey,
			cbMaxEncryptionKey		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetSteam2GetEncryptionKeyToSendToNewClient(pvEncryptionKey, pcbEncryptionKey, cbMaxEncryptionKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendSteam2UserConnect (  uint32 unUserID,  const void *pvRawKey,  uint32 unKeyLen,  uint32 unIPPublic,  uint16 usPort,  const void *pvCookie,  uint32 cubCookie )	{
		char log[1024];
		sprintf(log,"SendSteam2UserConnect() unUserID=0x%X pvRawKey=0x%X unKeyLen=0x%X unIPPublic=0x%X usPort=0x%X pvCookie=0x%X cubCookie=0x%X ",
			unUserID,
			pvRawKey,
			unKeyLen,
			unIPPublic,
			usPort,
			pvCookie,
			cubCookie		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendSteam2UserConnect(unUserID, pvRawKey, unKeyLen, unIPPublic, usPort, pvCookie, cubCookie);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendSteam3UserConnect ( CSteamID steamID,  uint32 unIPPublic,  const void *pvCookie,  uint32 cubCookie )	{
		char log[1024];
		sprintf(log,"SendSteam3UserConnect() steamID=0x%X unIPPublic=0x%X pvCookie=0x%X cubCookie=0x%X ",
			steamID,
			unIPPublic,
			pvCookie,
			cubCookie		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendSteam3UserConnect(steamID, unIPPublic, pvCookie, cubCookie);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveUserConnect ( uint32 unUserID )	{
		char log[1024];
		sprintf(log,"RemoveUserConnect() unUserID=0x%X ",
			unUserID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveUserConnect(unUserID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendUserDisconnect ( CSteamID steamID,  uint32 unUserID )	{
		char log[1024];
		sprintf(log,"SendUserDisconnect() steamID=0x%X unUserID=0x%X ",
			steamID,
			unUserID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendUserDisconnect(steamID, unUserID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendUserStatusResponse ( CSteamID steamID,  int nSecondsConnected,  int nSecondsSinceLast )	{
		char log[1024];
		sprintf(log,"SendUserStatusResponse() steamID=0x%X nSecondsConnected=0x%X nSecondsSinceLast=0x%X ",
			steamID,
			nSecondsConnected,
			nSecondsSinceLast		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendUserStatusResponse(steamID, nSecondsConnected, nSecondsSinceLast);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  Obsolete_GSSetStatus ( int32 nAppIdServed,  uint32 unServerFlags,  int cPlayers,  int cPlayersMax,  int cBotPlayers,  int unGamePort,  const char *pchServerName,  const char *pchGameDir,  const char *pchMapName,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"Obsolete_GSSetStatus() nAppIdServed=0x%X unServerFlags=0x%X cPlayers=0x%X cPlayersMax=0x%X cBotPlayers=0x%X unGamePort=0x%X pchServerName=%s pchGameDir=%s pchMapName=%s pchVersion=%s ",
			nAppIdServed,
			unServerFlags,
			cPlayers,
			cPlayersMax,
			cBotPlayers,
			unGamePort,
			pchServerName,
			pchGameDir,
			pchMapName,
			pchVersion		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->Obsolete_GSSetStatus(nAppIdServed, unServerFlags, cPlayers, cPlayersMax, cBotPlayers, unGamePort, pchServerName, pchGameDir, pchMapName, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UpdateStatus ( int cPlayers,  int cPlayersMax,  int cBotPlayers,  const char *pchServerName,  const char *pchMapName )	{
		char log[1024];
		sprintf(log,"UpdateStatus() cPlayers=0x%X cPlayersMax=0x%X cBotPlayers=0x%X pchServerName=%s pchMapName=%s ",
			cPlayers,
			cPlayersMax,
			cBotPlayers,
			pchServerName,
			pchMapName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateStatus(cPlayers, cPlayersMax, cBotPlayers, pchServerName, pchMapName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BSecure ()	{
		char log[1024];
		sprintf(log,"BSecure() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BSecure();
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
	virtual bool  SetServerType ( int32 nGameAppId,  uint32 unServerFlags,  uint32 unGameIP,  uint32 unGamePort,  const char *pchGameDir,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"SetServerType() nGameAppId=0x%X unServerFlags=0x%X unGameIP=0x%X unGamePort=0x%X pchGameDir=%s pchVersion=%s ",
			nGameAppId,
			unServerFlags,
			unGameIP,
			unGamePort,
			pchGameDir,
			pchVersion		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetServerType(nGameAppId, unServerFlags, unGameIP, unGamePort, pchGameDir, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetServerType2 ( int32 nGameAppId,  uint32 unServerFlags,  uint32 unGameIP,  uint16 unGamePort,  uint16 usSpectatorPort,  uint16 usQueryPort,  const char *pchGameDir,  const char *pchVersion,  bool bLANMode )	{
		char log[1024];
		sprintf(log,"SetServerType2() nGameAppId=0x%X unServerFlags=0x%X unGameIP=0x%X unGamePort=0x%X usSpectatorPort=0x%X usQueryPort=0x%X pchGameDir=%s pchVersion=%s bLANMode=0x%X ",
			nGameAppId,
			unServerFlags,
			unGameIP,
			unGamePort,
			usSpectatorPort,
			usQueryPort,
			pchGameDir,
			pchVersion,
			bLANMode		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetServerType2(nGameAppId, unServerFlags, unGameIP, unGamePort, usSpectatorPort, usQueryPort, pchGameDir, pchVersion, bLANMode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UpdateStatus2 ( int cPlayers,  int cPlayersMax,  int cBotPlayers,  const char *pchServerName,  const char *pSpectatorServerName,  const char *pchMapName )	{
		char log[1024];
		sprintf(log,"UpdateStatus2() cPlayers=0x%X cPlayersMax=0x%X cBotPlayers=0x%X pchServerName=%s pSpectatorServerName=%s pchMapName=%s ",
			cPlayers,
			cPlayersMax,
			cBotPlayers,
			pchServerName,
			pSpectatorServerName,
			pchMapName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateStatus2(cPlayers, cPlayersMax, cBotPlayers, pchServerName, pSpectatorServerName, pchMapName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  CreateUnauthenticatedUser ( CSteamID *pSteamID )	{
		char log[1024];
		sprintf(log,"CreateUnauthenticatedUser() pSteamID=0x%X ",
			pSteamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->CreateUnauthenticatedUser(pSteamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetUserData ( CSteamID steamIDUser,  const char *pchPlayerName,  uint32 uScore )	{
		char log[1024];
		sprintf(log,"SetUserData() steamIDUser=0x%X pchPlayerName=%s uScore=0x%X ",
			steamIDUser,
			pchPlayerName,
			uScore		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetUserData(steamIDUser, pchPlayerName, uScore);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  UpdateSpectatorPort ( uint16 unSpectatorPort )	{
		char log[1024];
		sprintf(log,"UpdateSpectatorPort() unSpectatorPort=0x%X ",
			unSpectatorPort		);
		OutputDebugStringA(log);
		unSpectatorPort);
		OutputDebugStringA("\n");
	}
	virtual void  SetGameType ( const char *pchGameType )	{
		char log[1024];
		sprintf(log,"SetGameType() pchGameType=%s ",
			pchGameType		);
		OutputDebugStringA(log);
		pchGameType);
		OutputDebugStringA("\n");
	}
};
