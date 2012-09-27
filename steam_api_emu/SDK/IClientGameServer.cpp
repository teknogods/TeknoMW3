#include "IClientGameServer.h"

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
	virtual EUserHasLicenseForAppResult  IsUserSubscribedAppInTicket ( CSteamID steamID,  AppId_t appID )	{
		char log[1024];
		sprintf(log,"IsUserSubscribedAppInTicket() steamID=0x%X appID=0x%X ",
			steamID,
			appID		);
		OutputDebugStringA(log);
		EUserHasLicenseForAppResult  ret = m_pWrapper->IsUserSubscribedAppInTicket(steamID, appID);
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
	virtual ELogonState  GetLogonState ()	{
		char log[1024];
		sprintf(log,"GetLogonState() "		);
		OutputDebugStringA(log);
		ELogonState  ret = m_pWrapper->GetLogonState();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BConnected ()	{
		char log[1024];
		sprintf(log,"BConnected() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BConnected();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  RaiseConnectionPriority ( EConnectionPriority eConnectionPriority )	{
		char log[1024];
		sprintf(log,"RaiseConnectionPriority() eConnectionPriority=0x%X ",
			eConnectionPriority		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->RaiseConnectionPriority(eConnectionPriority);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ResetConnectionPriority ( int hRaiseConnectionPriorityPrev )	{
		char log[1024];
		sprintf(log,"ResetConnectionPriority() hRaiseConnectionPriorityPrev=0x%X ",
			hRaiseConnectionPriorityPrev		);
		OutputDebugStringA(log);
		hRaiseConnectionPriorityPrev);
		OutputDebugStringA("\n");
	}
	virtual void  SetCellID ( CellID_t cellID )	{
		char log[1024];
		sprintf(log,"SetCellID() cellID=0x%X ",
			cellID		);
		OutputDebugStringA(log);
		cellID);
		OutputDebugStringA("\n");
	}
	virtual void  TrackSteamUsageEvent ( ESteamUsageEvent eSteamUsageEvent,  const uint8 *pubKV,  uint32 cubKV )	{
		char log[1024];
		sprintf(log,"TrackSteamUsageEvent() eSteamUsageEvent=0x%X pubKV=0x%X cubKV=0x%X ",
			eSteamUsageEvent,
			pubKV,
			cubKV		);
		OutputDebugStringA(log);
		eSteamUsageEvent, pubKV, cubKV);
		OutputDebugStringA("\n");
	}
	virtual void  SetCountOfSimultaneousGuestUsersPerSteamAccount ( int nCount )	{
		char log[1024];
		sprintf(log,"SetCountOfSimultaneousGuestUsersPerSteamAccount() nCount=0x%X ",
			nCount		);
		OutputDebugStringA(log);
		nCount);
		OutputDebugStringA("\n");
	}
	virtual bool  EnumerateConnectedUsers ( int iterator,  ConnectedUserInfo_t *pConnectedUserInfo )	{
		char log[1024];
		sprintf(log,"EnumerateConnectedUsers() iterator=0x%X pConnectedUserInfo=0x%X ",
			iterator,
			pConnectedUserInfo		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->EnumerateConnectedUsers(iterator, pConnectedUserInfo);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
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
	virtual void  ForceHeartbeatViaCM ()	{
		char log[1024];
		sprintf(log,"ForceHeartbeatViaCM() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual bool  _BGetUserAchievementStatus ( CSteamID steamID,  const char *pchAchievementName )	{
		char log[1024];
		sprintf(log,"_BGetUserAchievementStatus() steamID=0x%X pchAchievementName=%s ",
			steamID,
			pchAchievementName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_BGetUserAchievementStatus(steamID, pchAchievementName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  _GSSetSpawnCount ( uint32 ucSpawn )	{
		char log[1024];
		sprintf(log,"_GSSetSpawnCount() ucSpawn=0x%X ",
			ucSpawn		);
		OutputDebugStringA(log);
		ucSpawn);
		OutputDebugStringA("\n");
	}
	virtual bool  _GSGetSteam2GetEncryptionKeyToSendToNewClient ( void *pvEncryptionKey,  uint32 *pcbEncryptionKey,  uint32 cbMaxEncryptionKey )	{
		char log[1024];
		sprintf(log,"_GSGetSteam2GetEncryptionKeyToSendToNewClient() pvEncryptionKey=0x%X pcbEncryptionKey=0x%X cbMaxEncryptionKey=0x%X ",
			pvEncryptionKey,
			pcbEncryptionKey,
			cbMaxEncryptionKey		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSGetSteam2GetEncryptionKeyToSendToNewClient(pvEncryptionKey, pcbEncryptionKey, cbMaxEncryptionKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  _GSSendSteam2UserConnect ( uint32 unUserID,  const void *pvRawKey,  uint32 unKeyLen,  uint32 unIPPublic,  uint16 usPort,  const void *pvCookie,  uint32 cubCookie )	{
		char log[1024];
		sprintf(log,"_GSSendSteam2UserConnect() unUserID=0x%X pvRawKey=0x%X unKeyLen=0x%X unIPPublic=0x%X usPort=0x%X pvCookie=0x%X cubCookie=0x%X ",
			unUserID,
			pvRawKey,
			unKeyLen,
			unIPPublic,
			usPort,
			pvCookie,
			cubCookie		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSSendSteam2UserConnect(unUserID, pvRawKey, unKeyLen, unIPPublic, usPort, pvCookie, cubCookie);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  _GSSendSteam3UserConnect ( CSteamID steamID,  uint32 unIPPublic,  const void *pvCookie,  uint32 cubCookie )	{
		char log[1024];
		sprintf(log,"_GSSendSteam3UserConnect() steamID=0x%X unIPPublic=0x%X pvCookie=0x%X cubCookie=0x%X ",
			steamID,
			unIPPublic,
			pvCookie,
			cubCookie		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSSendSteam3UserConnect(steamID, unIPPublic, pvCookie, cubCookie);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  _GSSendUserConnect ( uint32 unUserID,  uint32 unIPPublic,  uint16 usPort,  const void *pvCookie,  uint32 cubCookie )	{
		char log[1024];
		sprintf(log,"_GSSendUserConnect() unUserID=0x%X unIPPublic=0x%X usPort=0x%X pvCookie=0x%X cubCookie=0x%X ",
			unUserID,
			unIPPublic,
			usPort,
			pvCookie,
			cubCookie		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSSendUserConnect(unUserID, unIPPublic, usPort, pvCookie, cubCookie);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  _GSRemoveUserConnect ( uint32 unUserID )	{
		char log[1024];
		sprintf(log,"_GSRemoveUserConnect() unUserID=0x%X ",
			unUserID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSRemoveUserConnect(unUserID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  _GSUpdateStatus ( int cPlayers,  int cPlayersMax,  int cBotPlayers,  const char *pchServerName,  const char *pSpectatorServerName,  const char *pchMapName )	{
		char log[1024];
		sprintf(log,"_GSUpdateStatus() cPlayers=0x%X cPlayersMax=0x%X cBotPlayers=0x%X pchServerName=%s pSpectatorServerName=%s pchMapName=%s ",
			cPlayers,
			cPlayersMax,
			cBotPlayers,
			pchServerName,
			pSpectatorServerName,
			pchMapName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSUpdateStatus(cPlayers, cPlayersMax, cBotPlayers, pchServerName, pSpectatorServerName, pchMapName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  _GSCreateUnauthenticatedUser ( CSteamID *pSteamID )	{
		char log[1024];
		sprintf(log,"_GSCreateUnauthenticatedUser() pSteamID=0x%X ",
			pSteamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSCreateUnauthenticatedUser(pSteamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  _GSSetServerType ( int iAppID,  uint32 unServerFlags,  uint32 unGameIP,  uint16 unGamePort,  uint16 unSpectatorPort,  uint16 usQueryPort,  const char *pchGameDir,  const char *pchVersion,  bool bLANMode )	{
		char log[1024];
		sprintf(log,"_GSSetServerType() iAppID=0x%X unServerFlags=0x%X unGameIP=0x%X unGamePort=0x%X unSpectatorPort=0x%X usQueryPort=0x%X pchGameDir=%s pchVersion=%s bLANMode=0x%X ",
			iAppID,
			unServerFlags,
			unGameIP,
			unGamePort,
			unSpectatorPort,
			usQueryPort,
			pchGameDir,
			pchVersion,
			bLANMode		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSSetServerType(iAppID, unServerFlags, unGameIP, unGamePort, unSpectatorPort, usQueryPort, pchGameDir, pchVersion, bLANMode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  _SetBasicServerData ( unsigned short nProtocolVersion,  bool bDedicatedServer,  const char *pRegionName,  const char *pProductName,  unsigned short nMaxReportedClients,  bool bPasswordProtected,  const char *pGameDescription )	{
		char log[1024];
		sprintf(log,"_SetBasicServerData() nProtocolVersion=0x%X bDedicatedServer=0x%X pRegionName=%s pProductName=%s nMaxReportedClients=0x%X bPasswordProtected=0x%X pGameDescription=%s ",
			nProtocolVersion,
			bDedicatedServer,
			pRegionName,
			pProductName,
			nMaxReportedClients,
			bPasswordProtected,
			pGameDescription		);
		OutputDebugStringA(log);
		nProtocolVersion, bDedicatedServer, pRegionName, pProductName, nMaxReportedClients, bPasswordProtected, pGameDescription);
		OutputDebugStringA("\n");
	}
	virtual bool  _GSSendUserDisconnect ( CSteamID,  uint32 unUserID )	{
		char log[1024];
		sprintf(log,"_GSSendUserDisconnect() CSteamID=0x%X unUserID=0x%X ",
			CSteamID,
			unUserID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->_GSSendUserDisconnect(CSteamID, unUserID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
