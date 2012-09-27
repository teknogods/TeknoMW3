#include "ISteamGameServer004.h"

class ISteamGameServer004_wrapper
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
	virtual bool  SendUserConnectAndAuthenticate ( CSteamID steamIDUser,  uint32,  void *,  uint32 )	{
		char log[1024];
		sprintf(log,"SendUserConnectAndAuthenticate() steamIDUser=0x%X uint32=0x%X =0x%X uint32=0x%X ",
			steamIDUser,
			uint32,
			,
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendUserConnectAndAuthenticate(steamIDUser, uint32, , uint32);
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
	virtual bool  BSetServerType ( int32 nGameAppId,  uint32 unServerFlags,  uint32 unGameIP,  uint16 unGamePort,  uint16 usSpectatorPort,  uint16 usQueryPort,  const char *pchGameDir,  const char *pchVersion,  bool bLANMode )	{
		char log[1024];
		sprintf(log,"BSetServerType() nGameAppId=0x%X unServerFlags=0x%X unGameIP=0x%X unGamePort=0x%X usSpectatorPort=0x%X usQueryPort=0x%X pchGameDir=%s pchVersion=%s bLANMode=0x%X ",
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
		bool  ret = m_pWrapper->BSetServerType(nGameAppId, unServerFlags, unGameIP, unGamePort, usSpectatorPort, usQueryPort, pchGameDir, pchVersion, bLANMode);
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
};
