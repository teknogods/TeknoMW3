#include "ISteamGameServer003.h"

class ISteamGameServer003_wrapper
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
	virtual bool  SendUserConnect ( uint32,  uint32,  uint16,  const void *,  uint32 )	{
		char log[1024];
		sprintf(log,"SendUserConnect() uint32=0x%X uint32=0x%X uint16=0x%X =0x%X uint32=0x%X ",
			uint32,
			uint32,
			uint16,
			,
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendUserConnect(uint32, uint32, uint16, , uint32);
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
	virtual void  SetSpawnCount ( uint32 ucSpawn )	{
		char log[1024];
		sprintf(log,"SetSpawnCount() ucSpawn=0x%X ",
			ucSpawn		);
		OutputDebugStringA(log);
		ucSpawn);
		OutputDebugStringA("\n");
	}
	virtual bool  SetServerType ( int32 nGameAppId,  uint32 unServerFlags,  uint32 unGameIP,  uint16 unGamePort,  uint16 usSpectatorPort,  uint16 usQueryPort,  const char *pchGameDir,  const char *pchVersion,  bool bLANMode )	{
		char log[1024];
		sprintf(log,"SetServerType() nGameAppId=0x%X unServerFlags=0x%X unGameIP=0x%X unGamePort=0x%X usSpectatorPort=0x%X usQueryPort=0x%X pchGameDir=%s pchVersion=%s bLANMode=0x%X ",
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
		bool  ret = m_pWrapper->SetServerType(nGameAppId, unServerFlags, unGameIP, unGamePort, usSpectatorPort, usQueryPort, pchGameDir, pchVersion, bLANMode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UpdateStatus ( int cPlayers,  int cPlayersMax,  int cBotPlayers,  const char *pchServerName,  const char *pSpectatorServerName,  const char *pchMapName )	{
		char log[1024];
		sprintf(log,"UpdateStatus() cPlayers=0x%X cPlayersMax=0x%X cBotPlayers=0x%X pchServerName=%s pSpectatorServerName=%s pchMapName=%s ",
			cPlayers,
			cPlayersMax,
			cBotPlayers,
			pchServerName,
			pSpectatorServerName,
			pchMapName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UpdateStatus(cPlayers, cPlayersMax, cBotPlayers, pchServerName, pSpectatorServerName, pchMapName);
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
	virtual bool  GetUserAchievementStatus ( CSteamID steamID,  const char *pchAchievementName )	{
		char log[1024];
		sprintf(log,"GetUserAchievementStatus() steamID=0x%X pchAchievementName=%s ",
			steamID,
			pchAchievementName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserAchievementStatus(steamID, pchAchievementName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
