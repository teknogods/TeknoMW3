#include "ISteamGameServer011.h"

class ISteamGameServer011_wrapper
{
public:
	virtual bool  InitGameServer ( uint32 unGameIP,  uint16 unGamePort,  uint16 usQueryPort,  uint32 unServerFlags,  AppId_t nAppID,  const char *pchVersion )	{
		char log[1024];
		sprintf(log,"InitGameServer() unGameIP=0x%X unGamePort=0x%X usQueryPort=0x%X unServerFlags=0x%X nAppID=0x%X pchVersion=%s ",
			unGameIP,
			unGamePort,
			usQueryPort,
			unServerFlags,
			nAppID,
			pchVersion		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InitGameServer(unGameIP, unGamePort, usQueryPort, unServerFlags, nAppID, pchVersion);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetProduct ( const char *pchProductName )	{
		char log[1024];
		sprintf(log,"SetProduct() pchProductName=%s ",
			pchProductName		);
		OutputDebugStringA(log);
		pchProductName);
		OutputDebugStringA("\n");
	}
	virtual void  SetGameDescription ( const char *pchGameDescription )	{
		char log[1024];
		sprintf(log,"SetGameDescription() pchGameDescription=%s ",
			pchGameDescription		);
		OutputDebugStringA(log);
		pchGameDescription);
		OutputDebugStringA("\n");
	}
	virtual void  SetModDir ( const char *pchModDir )	{
		char log[1024];
		sprintf(log,"SetModDir() pchModDir=%s ",
			pchModDir		);
		OutputDebugStringA(log);
		pchModDir);
		OutputDebugStringA("\n");
	}
	virtual void  SetDedicatedServer ( bool bDedicatedServer )	{
		char log[1024];
		sprintf(log,"SetDedicatedServer() bDedicatedServer=0x%X ",
			bDedicatedServer		);
		OutputDebugStringA(log);
		bDedicatedServer);
		OutputDebugStringA("\n");
	}
	virtual void  LogOn ( const char *pchLogin,  const char *pchPassword )	{
		char log[1024];
		sprintf(log,"LogOn() pchLogin=%s pchPassword=%s ",
			pchLogin,
			pchPassword		);
		OutputDebugStringA(log);
		pchLogin, pchPassword);
		OutputDebugStringA("\n");
	}
	virtual void  LogOnAnonymous ()	{
		char log[1024];
		sprintf(log,"LogOnAnonymous() "		);
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
	virtual bool  WasRestartRequested ()	{
		char log[1024];
		sprintf(log,"WasRestartRequested() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->WasRestartRequested();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetMaxPlayerCount ( int cPlayersMax )	{
		char log[1024];
		sprintf(log,"SetMaxPlayerCount() cPlayersMax=0x%X ",
			cPlayersMax		);
		OutputDebugStringA(log);
		cPlayersMax);
		OutputDebugStringA("\n");
	}
	virtual void  SetBotPlayerCount ( int cBotPlayers )	{
		char log[1024];
		sprintf(log,"SetBotPlayerCount() cBotPlayers=0x%X ",
			cBotPlayers		);
		OutputDebugStringA(log);
		cBotPlayers);
		OutputDebugStringA("\n");
	}
	virtual void  SetServerName ( const char *pchServerName )	{
		char log[1024];
		sprintf(log,"SetServerName() pchServerName=%s ",
			pchServerName		);
		OutputDebugStringA(log);
		pchServerName);
		OutputDebugStringA("\n");
	}
	virtual void  SetMapName ( const char *pchMapName )	{
		char log[1024];
		sprintf(log,"SetMapName() pchMapName=%s ",
			pchMapName		);
		OutputDebugStringA(log);
		pchMapName);
		OutputDebugStringA("\n");
	}
	virtual void  SetPasswordProtected ( bool bPasswordProtected )	{
		char log[1024];
		sprintf(log,"SetPasswordProtected() bPasswordProtected=0x%X ",
			bPasswordProtected		);
		OutputDebugStringA(log);
		bPasswordProtected);
		OutputDebugStringA("\n");
	}
	virtual void  SetSpectatorPort ( uint16 unSpectatorPort )	{
		char log[1024];
		sprintf(log,"SetSpectatorPort() unSpectatorPort=0x%X ",
			unSpectatorPort		);
		OutputDebugStringA(log);
		unSpectatorPort);
		OutputDebugStringA("\n");
	}
	virtual void  SetSpectatorServerName ( const char *pchSpectatorServerName )	{
		char log[1024];
		sprintf(log,"SetSpectatorServerName() pchSpectatorServerName=%s ",
			pchSpectatorServerName		);
		OutputDebugStringA(log);
		pchSpectatorServerName);
		OutputDebugStringA("\n");
	}
	virtual void  ClearAllKeyValues ()	{
		char log[1024];
		sprintf(log,"ClearAllKeyValues() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  SetKeyValue ( const char *pKey,  const char *pValue )	{
		char log[1024];
		sprintf(log,"SetKeyValue() pKey=%s pValue=%s ",
			pKey,
			pValue		);
		OutputDebugStringA(log);
		pKey, pValue);
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
	virtual void  SetGameData ( const char *pchGameData )	{
		char log[1024];
		sprintf(log,"SetGameData() pchGameData=%s ",
			pchGameData		);
		OutputDebugStringA(log);
		pchGameData);
		OutputDebugStringA("\n");
	}
	virtual void  SetRegion ( const char *pchRegionName )	{
		char log[1024];
		sprintf(log,"SetRegion() pchRegionName=%s ",
			pchRegionName		);
		OutputDebugStringA(log);
		pchRegionName);
		OutputDebugStringA("\n");
	}
	virtual int  SendUserConnectAndAuthenticate ( uint32 unIPClient,  const void *pvAuthBlob,  uint32 cubAuthBlobSize,  CSteamID *pSteamIDUser )	{
		char log[1024];
		sprintf(log,"SendUserConnectAndAuthenticate() unIPClient=0x%X pvAuthBlob=0x%X cubAuthBlobSize=0x%X pSteamIDUser=0x%X ",
			unIPClient,
			pvAuthBlob,
			cubAuthBlobSize,
			pSteamIDUser		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->SendUserConnectAndAuthenticate(unIPClient, pvAuthBlob, cubAuthBlobSize, pSteamIDUser);
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
	virtual bool  HandleIncomingPacket ( const void *pData,  int cbData,  uint32 srcIP,  uint16 srcPort )	{
		char log[1024];
		sprintf(log,"HandleIncomingPacket() pData=0x%X cbData=0x%X srcIP=0x%X srcPort=0x%X ",
			pData,
			cbData,
			srcIP,
			srcPort		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HandleIncomingPacket(pData, cbData, srcIP, srcPort);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetNextOutgoingPacket ( void *pOut,  int cbMaxOut,  uint32 *pNetAdr,  uint16 *pPort )	{
		char log[1024];
		sprintf(log,"GetNextOutgoingPacket() pOut=0x%X cbMaxOut=0x%X pNetAdr=0x%X pPort=0x%X ",
			pOut,
			cbMaxOut,
			pNetAdr,
			pPort		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetNextOutgoingPacket(pOut, cbMaxOut, pNetAdr, pPort);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  EnableHeartbeats ( bool bEnabled )	{
		char log[1024];
		sprintf(log,"EnableHeartbeats() bEnabled=0x%X ",
			bEnabled		);
		OutputDebugStringA(log);
		bEnabled);
		OutputDebugStringA("\n");
	}
	virtual void  SetHeartbeatInterval ( int iInterval )	{
		char log[1024];
		sprintf(log,"SetHeartbeatInterval() iInterval=0x%X ",
			iInterval		);
		OutputDebugStringA(log);
		iInterval);
		OutputDebugStringA("\n");
	}
	virtual void  ForceHeartbeat ()	{
		char log[1024];
		sprintf(log,"ForceHeartbeat() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual SteamAPICall_t  AssociateWithClan ( CSteamID clanID )	{
		char log[1024];
		sprintf(log,"AssociateWithClan() clanID=0x%X ",
			clanID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->AssociateWithClan(clanID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  ComputeNewPlayerCompatibility ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"ComputeNewPlayerCompatibility() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->ComputeNewPlayerCompatibility(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
