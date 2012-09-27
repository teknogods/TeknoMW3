#include "ISteamGameServer010.h"

class ISteamGameServer010_wrapper
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
	virtual bool  BSetServerType ( uint32 unServerFlags,  uint32 unGameIP,  uint16 unGamePort,  		uint16 unSpectatorPort,  uint16 usQueryPort,  const char *pchGameDir,  const char *pchVersion,  bool bLANMode )	{
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
	virtual void  UpdateServerStatus ( int cPlayers,  int cPlayersMax,  int cBotPlayers,  		const char *pchServerName,  const char *pSpectatorServerName,  		const char *pchMapName )	{
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
	virtual void  SetGameTags ( const char *pchGameTags )	{
		char log[1024];
		sprintf(log,"SetGameTags() pchGameTags=%s ",
			pchGameTags		);
		OutputDebugStringA(log);
		pchGameTags);
		OutputDebugStringA("\n");
	}
	virtual void  GetGameplayStats ( )	{
		char log[1024];
		sprintf(log,"GetGameplayStats() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual SteamAPICall_t  GetServerReputation ( )	{
		char log[1024];
		sprintf(log,"GetServerReputation() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->GetServerReputation();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestUserGroupStatus ( CSteamID steamIDUser,  CSteamID steamIDGroup )	{
		char log[1024];
		sprintf(log,"RequestUserGroupStatus() steamIDUser=0x%X steamIDGroup=0x%X ",
			steamIDUser,
			steamIDGroup		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestUserGroupStatus(steamIDUser, steamIDGroup);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetPublicIP ()	{
		char log[1024];
		sprintf(log,"GetPublicIP() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetPublicIP();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetGameData ( const char *pchGameData)	{
		char log[1024];
		sprintf(log,"SetGameData() pchGameData=%s ",
			pchGameData		);
		OutputDebugStringA(log);
		pchGameData);
		OutputDebugStringA("\n");
	}
	virtual EUserHasLicenseForAppResult  UserHasLicenseForApp ( CSteamID steamID,  AppId_t appID )	{
		char log[1024];
		sprintf(log,"UserHasLicenseForApp() steamID=0x%X appID=0x%X ",
			steamID,
			appID		);
		OutputDebugStringA(log);
		EUserHasLicenseForAppResult  ret = m_pWrapper->UserHasLicenseForApp(steamID, appID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HAuthTicket  GetAuthSessionTicket ( void *pTicket,  int cbMaxTicket,  uint32 *pcbTicket )	{
		char log[1024];
		sprintf(log,"GetAuthSessionTicket() pTicket=0x%X cbMaxTicket=0x%X pcbTicket=0x%X ",
			pTicket,
			cbMaxTicket,
			pcbTicket		);
		OutputDebugStringA(log);
		HAuthTicket  ret = m_pWrapper->GetAuthSessionTicket(pTicket, cbMaxTicket, pcbTicket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EBeginAuthSessionResult  BeginAuthSession ( const void *pAuthTicket,  int cbAuthTicket,  CSteamID steamID )	{
		char log[1024];
		sprintf(log,"BeginAuthSession() pAuthTicket=0x%X cbAuthTicket=0x%X steamID=0x%X ",
			pAuthTicket,
			cbAuthTicket,
			steamID		);
		OutputDebugStringA(log);
		EBeginAuthSessionResult  ret = m_pWrapper->BeginAuthSession(pAuthTicket, cbAuthTicket, steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  EndAuthSession ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"EndAuthSession() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		steamID);
		OutputDebugStringA("\n");
	}
	virtual void  CancelAuthTicket ( HAuthTicket hAuthTicket )	{
		char log[1024];
		sprintf(log,"CancelAuthTicket() hAuthTicket=0x%X ",
			hAuthTicket		);
		OutputDebugStringA(log);
		hAuthTicket);
		OutputDebugStringA("\n");
	}
};
