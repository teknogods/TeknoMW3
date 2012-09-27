#include "ISteamGameServer005.h"

class ISteamGameServer005_wrapper
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
	virtual bool  SendUserConnectAndAuthenticate ( uint32 unIPClient,  const void *pvAuthBlob,  uint32 cubAuthBlobSize,  CSteamID *pSteamIDUser )	{
		char log[1024];
		sprintf(log,"SendUserConnectAndAuthenticate() unIPClient=0x%X pvAuthBlob=0x%X cubAuthBlobSize=0x%X pSteamIDUser=0x%X ",
			unIPClient,
			pvAuthBlob,
			cubAuthBlobSize,
			pSteamIDUser		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  CreateUnauthenticatedUserConnection ()	{
		char log[1024];
		sprintf(log,"CreateUnauthenticatedUserConnection() "		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->CreateUnauthenticatedUserConnection();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SendUserDisconnect ( CSteamID steamIDUser )	{
		char log[1024];
		sprintf(log,"SendUserDisconnect() steamIDUser=0x%X ",
			steamIDUser		);
		OutputDebugStringA(log);
		steamIDUser);
		OutputDebugStringA("\n");
	}
	virtual bool  BUpdateUserData ( CSteamID steamIDUser,  const char *pchPlayerName,  uint32 uScore )	{
		char log[1024];
		sprintf(log,"BUpdateUserData() steamIDUser=0x%X pchPlayerName=%s uScore=0x%X ",
			steamIDUser,
			pchPlayerName,
			uScore		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BUpdateUserData(steamIDUser, pchPlayerName, uScore);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BSetServerType ( uint32 unServerFlags,  uint32 unGameIP,  uint16 unGamePort,  uint16 unSpectatorPort,  uint16 usQueryPort,  const char *pchGameDir,  const char *pchVersion,  bool bLANMode )	{
		char log[1024];
		sprintf(log,"BSetServerType() unServerFlags=0x%X unGameIP=0x%X unGamePort=0x%X unSpectatorPort=0x%X usQueryPort=0x%X pchGameDir=%s pchVersion=%s bLANMode=0x%X ",
			unServerFlags,
			unGameIP,
			unGamePort,
			unSpectatorPort,
			usQueryPort,
			pchGameDir,
			pchVersion,
			bLANMode		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BSetServerType(unServerFlags, unGameIP, unGamePort, unSpectatorPort, usQueryPort, pchGameDir, pchVersion, bLANMode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  UpdateServerStatus ( int cPlayers,  int cPlayersMax,  int cBotPlayers,  const char *pchServerName,  const char *pSpectatorServerName,  const char *pchMapName )	{
		char log[1024];
		sprintf(log,"UpdateServerStatus() cPlayers=0x%X cPlayersMax=0x%X cBotPlayers=0x%X pchServerName=%s pSpectatorServerName=%s pchMapName=%s ",
			cPlayers,
			cPlayersMax,
			cBotPlayers,
			pchServerName,
			pSpectatorServerName,
			pchMapName		);
		OutputDebugStringA(log);
		cPlayers, cPlayersMax, cBotPlayers, pchServerName, pSpectatorServerName, pchMapName);
		OutputDebugStringA("\n");
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
	virtual bool  BGetUserAchievementStatus ( CSteamID steamID,  const char *pchAchievementName )	{
		char log[1024];
		sprintf(log,"BGetUserAchievementStatus() steamID=0x%X pchAchievementName=%s ",
			steamID,
			pchAchievementName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetUserAchievementStatus(steamID, pchAchievementName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  GetGameplayStats ( )	{
		char log[1024];
		sprintf(log,"GetGameplayStats() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
};
