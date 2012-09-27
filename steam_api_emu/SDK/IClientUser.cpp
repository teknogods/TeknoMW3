#include "IClientUser.h"

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
	virtual void  LogOn ( bool bUnk1,  CSteamID steamID )	{
		char log[1024];
		sprintf(log,"LogOn() bUnk1=0x%X steamID=0x%X ",
			bUnk1,
			steamID		);
		OutputDebugStringA(log);
		bUnk1, steamID);
		OutputDebugStringA("\n");
	}
	virtual void  LogOnWithPassword ( bool bUnk1,  const char * pchLogin,  const char * pchPassword )	{
		char log[1024];
		sprintf(log,"LogOnWithPassword() bUnk1=0x%X pchLogin=%s pchPassword=%s ",
			bUnk1,
			pchLogin,
			pchPassword		);
		OutputDebugStringA(log);
		bUnk1, pchLogin, pchPassword);
		OutputDebugStringA("\n");
	}
	virtual void  LogOnAndCreateNewSteamAccountIfNeeded ( bool bUnk1 )	{
		char log[1024];
		sprintf(log,"LogOnAndCreateNewSteamAccountIfNeeded() bUnk1=0x%X ",
			bUnk1		);
		OutputDebugStringA(log);
		bUnk1);
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
	virtual bool  BTryingToLogin ()	{
		char log[1024];
		sprintf(log,"BTryingToLogin() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BTryingToLogin();
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
	virtual CSteamID  GetConsoleSteamID ()	{
		char log[1024];
		sprintf(log,"GetConsoleSteamID() "		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetConsoleSteamID();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsVACBanned ( AppId_t nGameID )	{
		char log[1024];
		sprintf(log,"IsVACBanned() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsVACBanned(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequireShowVACBannedMessage ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"RequireShowVACBannedMessage() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequireShowVACBannedMessage(nAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  AcknowledgeVACBanning ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"AcknowledgeVACBanning() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		nAppID);
		OutputDebugStringA("\n");
	}
	virtual void  SetSteam2Ticket ( uint8* pubTicket,  int cubTicket )	{
		char log[1024];
		sprintf(log,"SetSteam2Ticket() pubTicket=0x%X cubTicket=0x%X ",
			pubTicket,
			cubTicket		);
		OutputDebugStringA(log);
		pubTicket, cubTicket);
		OutputDebugStringA("\n");
	}
	virtual bool  BExistsSteam2Ticket ()	{
		char log[1024];
		sprintf(log,"BExistsSteam2Ticket() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BExistsSteam2Ticket();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetEmail ( const char *pchEmail )	{
		char log[1024];
		sprintf(log,"SetEmail() pchEmail=%s ",
			pchEmail		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetEmail(pchEmail);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetConfigString ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetConfigString() eRegistrySubTree=0x%X pchKey=%s pchValue=%s ",
			eRegistrySubTree,
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetConfigString(eRegistrySubTree, pchKey, pchValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetConfigString ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  char *pchValue,  int cbValue )	{
		char log[1024];
		sprintf(log,"GetConfigString() eRegistrySubTree=0x%X pchKey=%s pchValue=%s cbValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			pchValue,
			cbValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetConfigString(eRegistrySubTree, pchKey, pchValue, cbValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetConfigInt ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  int iValue )	{
		char log[1024];
		sprintf(log,"SetConfigInt() eRegistrySubTree=0x%X pchKey=%s iValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			iValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetConfigInt(eRegistrySubTree, pchKey, iValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetConfigInt ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  int *pValue )	{
		char log[1024];
		sprintf(log,"GetConfigInt() eRegistrySubTree=0x%X pchKey=%s pValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			pValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetConfigInt(eRegistrySubTree, pchKey, pValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetConfigStoreKeyName ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  char *pchStoreName,  int cbStoreName )	{
		char log[1024];
		sprintf(log,"GetConfigStoreKeyName() eRegistrySubTree=0x%X pchKey=%s pchStoreName=%s cbStoreName=0x%X ",
			eRegistrySubTree,
			pchKey,
			pchStoreName,
			cbStoreName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetConfigStoreKeyName(eRegistrySubTree, pchKey, pchStoreName, cbStoreName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  InitiateGameConnection ( void *pOutputBlob,  int cbBlobMax,  CSteamID steamIDGS,  CGameID gameID,  uint32 unIPServer,  uint16 usPortServer,  bool bSecure )	{
		char log[1024];
		sprintf(log,"InitiateGameConnection() pOutputBlob=0x%X cbBlobMax=0x%X steamIDGS=0x%X gameID=0x%X unIPServer=0x%X usPortServer=0x%X bSecure=0x%X ",
			pOutputBlob,
			cbBlobMax,
			steamIDGS,
			gameID,
			unIPServer,
			usPortServer,
			bSecure		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->InitiateGameConnection(pOutputBlob, cbBlobMax, steamIDGS, gameID, unIPServer, usPortServer, bSecure);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  InitiateGameConnectionOld ( void *pOutputBlob,  int cbBlobMax,  CSteamID steamIDGS,  CGameID gameID,  uint32 unIPServer,  uint16 usPortServer,  bool bSecure,  void *pvSteam2GetEncryptionKey,  int cbSteam2GetEncryptionKey )	{
		char log[1024];
		sprintf(log,"InitiateGameConnectionOld() pOutputBlob=0x%X cbBlobMax=0x%X steamIDGS=0x%X gameID=0x%X unIPServer=0x%X usPortServer=0x%X bSecure=0x%X pvSteam2GetEncryptionKey=0x%X cbSteam2GetEncryptionKey=0x%X ",
			pOutputBlob,
			cbBlobMax,
			steamIDGS,
			gameID,
			unIPServer,
			usPortServer,
			bSecure,
			pvSteam2GetEncryptionKey,
			cbSteam2GetEncryptionKey		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->InitiateGameConnectionOld(pOutputBlob, cbBlobMax, steamIDGS, gameID, unIPServer, usPortServer, bSecure, pvSteam2GetEncryptionKey, cbSteam2GetEncryptionKey);
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
	virtual void  SetSelfAsPrimaryChatDestination ()	{
		char log[1024];
		sprintf(log,"SetSelfAsPrimaryChatDestination() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual bool  IsPrimaryChatDestination ()	{
		char log[1024];
		sprintf(log,"IsPrimaryChatDestination() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsPrimaryChatDestination();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RequestLegacyCDKey ( AppId_t iAppID )	{
		char log[1024];
		sprintf(log,"RequestLegacyCDKey() iAppID=0x%X ",
			iAppID		);
		OutputDebugStringA(log);
		iAppID);
		OutputDebugStringA("\n");
	}
	virtual bool  SendGuestPassByEmail ( const char *pchEmailAccount,  GID_t gidGuestPassID,  bool bResending )	{
		char log[1024];
		sprintf(log,"SendGuestPassByEmail() pchEmailAccount=%s gidGuestPassID=0x%X bResending=0x%X ",
			pchEmailAccount,
			gidGuestPassID,
			bResending		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendGuestPassByEmail(pchEmailAccount, gidGuestPassID, bResending);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendGuestPassByAccountID ( uint32 uAccountID,  GID_t gidGuestPassID,  bool bResending )	{
		char log[1024];
		sprintf(log,"SendGuestPassByAccountID() uAccountID=0x%X gidGuestPassID=0x%X bResending=0x%X ",
			uAccountID,
			gidGuestPassID,
			bResending		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendGuestPassByAccountID(uAccountID, gidGuestPassID, bResending);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AckGuestPass ( const char *pchGuestPassCode )	{
		char log[1024];
		sprintf(log,"AckGuestPass() pchGuestPassCode=%s ",
			pchGuestPassCode		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AckGuestPass(pchGuestPassCode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RedeemGuestPass ( const char *pchGuestPassCode )	{
		char log[1024];
		sprintf(log,"RedeemGuestPass() pchGuestPassCode=%s ",
			pchGuestPassCode		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RedeemGuestPass(pchGuestPassCode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetGuestPassToGiveCount ()	{
		char log[1024];
		sprintf(log,"GetGuestPassToGiveCount() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetGuestPassToGiveCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetGuestPassToRedeemCount ()	{
		char log[1024];
		sprintf(log,"GetGuestPassToRedeemCount() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetGuestPassToRedeemCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetGuestPassLastUpdateTime ()	{
		char log[1024];
		sprintf(log,"GetGuestPassLastUpdateTime() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetGuestPassLastUpdateTime();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGuestPassToGiveInfo ( uint32 nPassIndex,  GID_t *pgidGuestPassID,  PackageId_t* pnPackageID,  RTime32* pRTime32Created,  RTime32* pRTime32Expiration,  RTime32* pRTime32Sent,  RTime32* pRTime32Redeemed,  char* pchRecipientAddress,  int cRecipientAddressSize )	{
		char log[1024];
		sprintf(log,"GetGuestPassToGiveInfo() nPassIndex=0x%X pgidGuestPassID=0x%X pnPackageID=0x%X pRTime32Created=0x%X pRTime32Expiration=0x%X pRTime32Sent=0x%X pRTime32Redeemed=0x%X pchRecipientAddress=%s cRecipientAddressSize=0x%X ",
			nPassIndex,
			pgidGuestPassID,
			pnPackageID,
			pRTime32Created,
			pRTime32Expiration,
			pRTime32Sent,
			pRTime32Redeemed,
			pchRecipientAddress,
			cRecipientAddressSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGuestPassToGiveInfo(nPassIndex, pgidGuestPassID, pnPackageID, pRTime32Created, pRTime32Expiration, pRTime32Sent, pRTime32Redeemed, pchRecipientAddress, cRecipientAddressSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGuestPassToRedeemInfo ( uint32 nPassIndex,  GID_t *pgidGuestPassID,  PackageId_t* pnPackageID,  RTime32* pRTime32Created,  RTime32* pRTime32Expiration,  RTime32* pRTime32Sent,  RTime32* pRTime32Redeemed )	{
		char log[1024];
		sprintf(log,"GetGuestPassToRedeemInfo() nPassIndex=0x%X pgidGuestPassID=0x%X pnPackageID=0x%X pRTime32Created=0x%X pRTime32Expiration=0x%X pRTime32Sent=0x%X pRTime32Redeemed=0x%X ",
			nPassIndex,
			pgidGuestPassID,
			pnPackageID,
			pRTime32Created,
			pRTime32Expiration,
			pRTime32Sent,
			pRTime32Redeemed		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGuestPassToRedeemInfo(nPassIndex, pgidGuestPassID, pnPackageID, pRTime32Created, pRTime32Expiration, pRTime32Sent, pRTime32Redeemed);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGuestPassToRedeemSenderAddress ( uint32 nPassIndex,  char* pchSenderAddress,  int cSenderAddressSize )	{
		char log[1024];
		sprintf(log,"GetGuestPassToRedeemSenderAddress() nPassIndex=0x%X pchSenderAddress=%s cSenderAddressSize=0x%X ",
			nPassIndex,
			pchSenderAddress,
			cSenderAddressSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGuestPassToRedeemSenderAddress(nPassIndex, pchSenderAddress, cSenderAddressSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetGuestPassToRedeemSenderName ( uint32 nPassIndex,  char* pchSenderName,  int cSenderNameSize )	{
		char log[1024];
		sprintf(log,"GetGuestPassToRedeemSenderName() nPassIndex=0x%X pchSenderName=%s cSenderNameSize=0x%X ",
			nPassIndex,
			pchSenderName,
			cSenderNameSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetGuestPassToRedeemSenderName(nPassIndex, pchSenderName, cSenderNameSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestGuestPassTargetList ( GID_t gidGuestPassID )	{
		char log[1024];
		sprintf(log,"RequestGuestPassTargetList() gidGuestPassID=0x%X ",
			gidGuestPassID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestGuestPassTargetList(gidGuestPassID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestGiftTargetList ( PackageId_t nPackageID )	{
		char log[1024];
		sprintf(log,"RequestGiftTargetList() nPackageID=0x%X ",
			nPackageID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestGiftTargetList(nPackageID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  AcknowledgeMessageByGID ( const char *pchMessageGID )	{
		char log[1024];
		sprintf(log,"AcknowledgeMessageByGID() pchMessageGID=%s ",
			pchMessageGID		);
		OutputDebugStringA(log);
		pchMessageGID);
		OutputDebugStringA("\n");
	}
	virtual bool  SetLanguage ( const char *pchLanguage )	{
		char log[1024];
		sprintf(log,"SetLanguage() pchLanguage=%s ",
			pchLanguage		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLanguage(pchLanguage);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  TrackAppUsageEvent ( CGameID gameID,  int eAppUsageEvent,  const char *pchExtraInfo = "" )	{
		char log[1024];
		sprintf(log,"TrackAppUsageEvent() gameID=0x%X eAppUsageEvent=0x%X ""=%s ",
			gameID,
			eAppUsageEvent,
			""		);
		OutputDebugStringA(log);
		gameID, eAppUsageEvent, "");
		OutputDebugStringA("\n");
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
	virtual void  SetAccountNameFromSteam2 ( const char *pchAccountName )	{
		char log[1024];
		sprintf(log,"SetAccountNameFromSteam2() pchAccountName=%s ",
			pchAccountName		);
		OutputDebugStringA(log);
		pchAccountName);
		OutputDebugStringA("\n");
	}
	virtual bool  SetPasswordFromSteam2 ( const char *pchPassword )	{
		char log[1024];
		sprintf(log,"SetPasswordFromSteam2() pchPassword=%s ",
			pchPassword		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetPasswordFromSteam2(pchPassword);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetAccountNameForCachedCredentialLogin ( const char *pchAccountName,  bool bRememberPassword,  bool bUnk )	{
		char log[1024];
		sprintf(log,"SetAccountNameForCachedCredentialLogin() pchAccountName=%s bRememberPassword=0x%X bUnk=0x%X ",
			pchAccountName,
			bRememberPassword,
			bUnk		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetAccountNameForCachedCredentialLogin(pchAccountName, bRememberPassword, bUnk);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetLoginInformation ( const char *pchAccountName,  const char *pchPassword,  bool bRememberPassword )	{
		char log[1024];
		sprintf(log,"SetLoginInformation() pchAccountName=%s pchPassword=%s bRememberPassword=0x%X ",
			pchAccountName,
			pchPassword,
			bRememberPassword		);
		OutputDebugStringA(log);
		pchAccountName, pchPassword, bRememberPassword);
		OutputDebugStringA("\n");
	}
	virtual void  SetAccountCreationTime ( RTime32 rtime32Time )	{
		char log[1024];
		sprintf(log,"SetAccountCreationTime() rtime32Time=0x%X ",
			rtime32Time		);
		OutputDebugStringA(log);
		rtime32Time);
		OutputDebugStringA("\n");
	}
	virtual bool  DoesTextContainUserPassword ( const char *pchText )	{
		char log[1024];
		sprintf(log,"DoesTextContainUserPassword() pchText=%s ",
			pchText		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->DoesTextContainUserPassword(pchText);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION uint32  obselete_GetCMIPAddress ()	{
		char log[1024];
		sprintf(log,"obselete_GetCMIPAddress() "		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION uint32  ret = m_pWrapper->obselete_GetCMIPAddress();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION uint32  obselete_GetP2PRelayIPAddress ()	{
		char log[1024];
		sprintf(log,"obselete_GetP2PRelayIPAddress() "		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION uint32  ret = m_pWrapper->obselete_GetP2PRelayIPAddress();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestWebAuthToken ( void )	{
		char log[1024];
		sprintf(log,"RequestWebAuthToken() void=0x%X ",
			void		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestWebAuthToken(void);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetLanguage ( char* pchLanguage,  int cbLanguage )	{
		char log[1024];
		sprintf(log,"GetLanguage() pchLanguage=%s cbLanguage=0x%X ",
			pchLanguage,
			cbLanguage		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLanguage(pchLanguage, cbLanguage);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetCyberCafe ( bool bCyberCafe )	{
		char log[1024];
		sprintf(log,"SetCyberCafe() bCyberCafe=0x%X ",
			bCyberCafe		);
		OutputDebugStringA(log);
		bCyberCafe);
		OutputDebugStringA("\n");
	}
	virtual void  CreateAccount ( const char *pchAccountName,  const char *pchNewPassword,  const char *pchNewEmail,  int iQuestion,  const char *pchNewQuestion,  const char *pchNewAnswer )	{
		char log[1024];
		sprintf(log,"CreateAccount() pchAccountName=%s pchNewPassword=%s pchNewEmail=%s iQuestion=0x%X pchNewQuestion=%s pchNewAnswer=%s ",
			pchAccountName,
			pchNewPassword,
			pchNewEmail,
			iQuestion,
			pchNewQuestion,
			pchNewAnswer		);
		OutputDebugStringA(log);
		pchAccountName, pchNewPassword, pchNewEmail, iQuestion, pchNewQuestion, pchNewAnswer);
		OutputDebugStringA("\n");
	}
	virtual void  ResetPassword ( const char *pchAccountName,  const char *pchOldPassword,  const char *pchNewPassword,  const char *pchValidationCode,  const char *pchAnswer )	{
		char log[1024];
		sprintf(log,"ResetPassword() pchAccountName=%s pchOldPassword=%s pchNewPassword=%s pchValidationCode=%s pchAnswer=%s ",
			pchAccountName,
			pchOldPassword,
			pchNewPassword,
			pchValidationCode,
			pchAnswer		);
		OutputDebugStringA(log);
		pchAccountName, pchOldPassword, pchNewPassword, pchValidationCode, pchAnswer);
		OutputDebugStringA("\n");
	}
	virtual void  TrackNatTraversalStat ( const CNatTraversalStat *pNatStat )	{
		char log[1024];
		sprintf(log,"TrackNatTraversalStat() pNatStat=0x%X ",
			pNatStat		);
		OutputDebugStringA(log);
		pNatStat);
		OutputDebugStringA("\n");
	}
	virtual void  RefreshSteam2Login ()	{
		char log[1024];
		sprintf(log,"RefreshSteam2Login() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  RefreshSteam2LoginWithSecureOption ( bool bIsSecure )	{
		char log[1024];
		sprintf(log,"RefreshSteam2LoginWithSecureOption() bIsSecure=0x%X ",
			bIsSecure		);
		OutputDebugStringA(log);
		bIsSecure);
		OutputDebugStringA("\n");
	}
	virtual bool  Steam2IsSecureComputer ()	{
		char log[1024];
		sprintf(log,"Steam2IsSecureComputer() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->Steam2IsSecureComputer();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual PackageId_t  GetPackageIDForGuestPassToRedeemByGID ( GID_t gid )	{
		char log[1024];
		sprintf(log,"GetPackageIDForGuestPassToRedeemByGID() gid=0x%X ",
			gid		);
		OutputDebugStringA(log);
		PackageId_t  ret = m_pWrapper->GetPackageIDForGuestPassToRedeemByGID(gid);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
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
	virtual void  TrackSteamGUIUsage ( const char * )	{
		char log[1024];
		sprintf(log,"TrackSteamGUIUsage() =%s ",
					);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  SetComputerInUse ()	{
		char log[1024];
		sprintf(log,"SetComputerInUse() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual bool  BIsGameRunning ( CGameID gameID )	{
		char log[1024];
		sprintf(log,"BIsGameRunning() gameID=0x%X ",
			gameID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsGameRunning(gameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint64  GetCurrentSessionToken ()	{
		char log[1024];
		sprintf(log,"GetCurrentSessionToken() "		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->GetCurrentSessionToken();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BUpdateAppOwnershipTicket ( AppId_t nAppID,  bool bOnlyUpdateIfStale,  bool unk )	{
		char log[1024];
		sprintf(log,"BUpdateAppOwnershipTicket() nAppID=0x%X bOnlyUpdateIfStale=0x%X unk=0x%X ",
			nAppID,
			bOnlyUpdateIfStale,
			unk		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BUpdateAppOwnershipTicket(nAppID, bOnlyUpdateIfStale, unk);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestCustomBinary ( const char *pszAbsolutePath,  AppId_t nAppID,  bool bForceUpdate,  bool bAppLaunchRequest )	{
		char log[1024];
		sprintf(log,"RequestCustomBinary() pszAbsolutePath=%s nAppID=0x%X bForceUpdate=0x%X bAppLaunchRequest=0x%X ",
			pszAbsolutePath,
			nAppID,
			bForceUpdate,
			bAppLaunchRequest		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestCustomBinary(pszAbsolutePath, nAppID, bForceUpdate, bAppLaunchRequest);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetCustomBinariesState ( AppId_t unAppID,  uint32 *punProgress )	{
		char log[1024];
		sprintf(log,"GetCustomBinariesState() unAppID=0x%X punProgress=0x%X ",
			unAppID,
			punProgress		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetCustomBinariesState(unAppID, punProgress);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EResult  RequestCustomBinaries ( AppId_t unAppID,  bool,  bool,  uint32 * )	{
		char log[1024];
		sprintf(log,"RequestCustomBinaries() unAppID=0x%X bool=0x%X bool=0x%X =0x%X ",
			unAppID,
			bool,
			bool,
					);
		OutputDebugStringA(log);
		EResult  ret = m_pWrapper->RequestCustomBinaries(unAppID, bool, bool, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetCellID ( CellID_t cellID )	{
		char log[1024];
		sprintf(log,"SetCellID() cellID=0x%X ",
			cellID		);
		OutputDebugStringA(log);
		cellID);
		OutputDebugStringA("\n");
	}
	virtual const char * GetUserBaseFolder ()	{
		char log[1024];
		sprintf(log,"GetUserBaseFolder() "		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetUserBaseFolder();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserDataFolder ( CGameID gameID,  char* pchBuffer,  int cubBuffer )	{
		char log[1024];
		sprintf(log,"GetUserDataFolder() gameID=0x%X pchBuffer=%s cubBuffer=0x%X ",
			gameID,
			pchBuffer,
			cubBuffer		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserDataFolder(gameID, pchBuffer, cubBuffer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetUserConfigFolder ( char *pchBuffer,  int cubBuffer )	{
		char log[1024];
		sprintf(log,"GetUserConfigFolder() pchBuffer=%s cubBuffer=0x%X ",
			pchBuffer,
			cubBuffer		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetUserConfigFolder(pchBuffer, cubBuffer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAccountName ( char* pchAccountName,  uint32 cb )	{
		char log[1024];
		sprintf(log,"GetAccountName() pchAccountName=%s cb=0x%X ",
			pchAccountName,
			cb		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAccountName(pchAccountName, cb);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequiresLegacyCDKey ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"RequiresLegacyCDKey() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequiresLegacyCDKey(nAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetLegacyCDKey ( AppId_t nAppID,  char* pchKeyData,  int cbKeyData )	{
		char log[1024];
		sprintf(log,"GetLegacyCDKey() nAppID=0x%X pchKeyData=%s cbKeyData=0x%X ",
			nAppID,
			pchKeyData,
			cbKeyData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLegacyCDKey(nAppID, pchKeyData, cbKeyData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  HasLegacyCDKey ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"HasLegacyCDKey() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HasLegacyCDKey(nAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLegacyCDKey ( AppId_t nAppID,  const char* pchKeyData )	{
		char log[1024];
		sprintf(log,"SetLegacyCDKey() nAppID=0x%X pchKeyData=%s ",
			nAppID,
			pchKeyData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLegacyCDKey(nAppID, pchKeyData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RemoveLegacyCDKey ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"RemoveLegacyCDKey() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		nAppID);
		OutputDebugStringA("\n");
	}
	virtual bool  BIsAnyGameRunning ()	{
		char log[1024];
		sprintf(log,"BIsAnyGameRunning() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsAnyGameRunning();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ChangePassword ( const char *pchOldPassword,  const char *pchNewPassword )	{
		char log[1024];
		sprintf(log,"ChangePassword() pchOldPassword=%s pchNewPassword=%s ",
			pchOldPassword,
			pchNewPassword		);
		OutputDebugStringA(log);
		pchOldPassword, pchNewPassword);
		OutputDebugStringA("\n");
	}
	virtual void  ChangeEmail ( const char *,  const char *pchEmail )	{
		char log[1024];
		sprintf(log,"ChangeEmail() =%s pchEmail=%s ",
			,
			pchEmail		);
		OutputDebugStringA(log);
		, pchEmail);
		OutputDebugStringA("\n");
	}
	virtual void  ChangeSecretQuestionAndAnswer ( const char *,  int iQuestion,  const char *pchNewQuestion,  const char *pchNewAnswer )	{
		char log[1024];
		sprintf(log,"ChangeSecretQuestionAndAnswer() =%s iQuestion=0x%X pchNewQuestion=%s pchNewAnswer=%s ",
			,
			iQuestion,
			pchNewQuestion,
			pchNewAnswer		);
		OutputDebugStringA(log);
		, iQuestion, pchNewQuestion, pchNewAnswer);
		OutputDebugStringA("\n");
	}
	virtual void  SetSteam2FullASTicket ( uint8* pubTicket,  int cubTicket )	{
		char log[1024];
		sprintf(log,"SetSteam2FullASTicket() pubTicket=0x%X cubTicket=0x%X ",
			pubTicket,
			cubTicket		);
		OutputDebugStringA(log);
		pubTicket, cubTicket);
		OutputDebugStringA("\n");
	}
	virtual uint32  GetSteam2FullASTicket ( uint8* pubTicket,  int32 cubTicket )	{
		char log[1024];
		sprintf(log,"GetSteam2FullASTicket() pubTicket=0x%X cubTicket=0x%X ",
			pubTicket,
			cubTicket		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetSteam2FullASTicket(pubTicket, cubTicket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetEmail ( char* pchEmail,  int cchEmail,  bool* pbUnk )	{
		char log[1024];
		sprintf(log,"GetEmail() pchEmail=%s cchEmail=0x%X pbUnk=0x%X ",
			pchEmail,
			cchEmail,
			pbUnk		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetEmail(pchEmail, cchEmail, pbUnk);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RequestForgottenPasswordEmail ( const char *pchAccountName,  const char *pchTriedPassword )	{
		char log[1024];
		sprintf(log,"RequestForgottenPasswordEmail() pchAccountName=%s pchTriedPassword=%s ",
			pchAccountName,
			pchTriedPassword		);
		OutputDebugStringA(log);
		pchAccountName, pchTriedPassword);
		OutputDebugStringA("\n");
	}
	virtual void  FindAccountsByEmailAddress ( const char *pchEmailAddress )	{
		char log[1024];
		sprintf(log,"FindAccountsByEmailAddress() pchEmailAddress=%s ",
			pchEmailAddress		);
		OutputDebugStringA(log);
		pchEmailAddress);
		OutputDebugStringA("\n");
	}
	virtual void  FindAccountsByCdKey ( const char *pchCdKey )	{
		char log[1024];
		sprintf(log,"FindAccountsByCdKey() pchCdKey=%s ",
			pchCdKey		);
		OutputDebugStringA(log);
		pchCdKey);
		OutputDebugStringA("\n");
	}
	virtual void  GetNumAccountsWithEmailAddress ( const char * pchEmailAddress )	{
		char log[1024];
		sprintf(log,"GetNumAccountsWithEmailAddress() pchEmailAddress=%s ",
			pchEmailAddress		);
		OutputDebugStringA(log);
		pchEmailAddress);
		OutputDebugStringA("\n");
	}
	virtual void  IsAccountNameInUse ( const char * pchAccountName )	{
		char log[1024];
		sprintf(log,"IsAccountNameInUse() pchAccountName=%s ",
			pchAccountName		);
		OutputDebugStringA(log);
		pchAccountName);
		OutputDebugStringA("\n");
	}
	virtual void  Test_FakeConnectionTimeout ()	{
		char log[1024];
		sprintf(log,"Test_FakeConnectionTimeout() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual bool  RunInstallScript ( AppId_t *pAppIDs,  int cAppIDs,  const char *pchInstallPath,  const char *pchLanguage,  bool bUninstall )	{
		char log[1024];
		sprintf(log,"RunInstallScript() pAppIDs=0x%X cAppIDs=0x%X pchInstallPath=%s pchLanguage=%s bUninstall=0x%X ",
			pAppIDs,
			cAppIDs,
			pchInstallPath,
			pchLanguage,
			bUninstall		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RunInstallScript(pAppIDs, cAppIDs, pchInstallPath, pchLanguage, bUninstall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual AppId_t  IsInstallScriptRunning ()	{
		char log[1024];
		sprintf(log,"IsInstallScriptRunning() "		);
		OutputDebugStringA(log);
		AppId_t  ret = m_pWrapper->IsInstallScriptRunning();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetInstallScriptString ( AppId_t nAppID,  const char *pchInstallPath,  const char *pchLanguage,  const char *pchKeyname,  const char *pchKeyvalue,  char* pchValue,  int cchValue )	{
		char log[1024];
		sprintf(log,"GetInstallScriptString() nAppID=0x%X pchInstallPath=%s pchLanguage=%s pchKeyname=%s pchKeyvalue=%s pchValue=%s cchValue=0x%X ",
			nAppID,
			pchInstallPath,
			pchLanguage,
			pchKeyname,
			pchKeyvalue,
			pchValue,
			cchValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetInstallScriptString(nAppID, pchInstallPath, pchLanguage, pchKeyname, pchKeyvalue, pchValue, cchValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetInstallScriptState ( char* pchDescription,  uint32 cchDescription,  uint32* punNumSteps,  uint32* punCurrStep )	{
		char log[1024];
		sprintf(log,"GetInstallScriptState() pchDescription=%s cchDescription=0x%X punNumSteps=0x%X punCurrStep=0x%X ",
			pchDescription,
			cchDescription,
			punNumSteps,
			punCurrStep		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetInstallScriptState(pchDescription, cchDescription, punNumSteps, punCurrStep);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SpawnProcess ( void *lpVACBlob,  uint32 cbBlobSize,  const char *lpApplicationName,  const char *lpCommandLine,  uint32 dwCreationFlags,  const char *lpCurrentDirectory,  CGameID gameID,  AppId_t nAppID,  const char *pchGameName,  bool bAlwaysUseShellExec )	{
		char log[1024];
		sprintf(log,"SpawnProcess() lpVACBlob=0x%X cbBlobSize=0x%X lpApplicationName=%s lpCommandLine=%s dwCreationFlags=0x%X lpCurrentDirectory=%s gameID=0x%X nAppID=0x%X pchGameName=%s bAlwaysUseShellExec=0x%X ",
			lpVACBlob,
			cbBlobSize,
			lpApplicationName,
			lpCommandLine,
			dwCreationFlags,
			lpCurrentDirectory,
			gameID,
			nAppID,
			pchGameName,
			bAlwaysUseShellExec		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SpawnProcess(lpVACBlob, cbBlobSize, lpApplicationName, lpCommandLine, dwCreationFlags, lpCurrentDirectory, gameID, nAppID, pchGameName, bAlwaysUseShellExec);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetAppOwnershipTicketLength ( uint32 nAppID )	{
		char log[1024];
		sprintf(log,"GetAppOwnershipTicketLength() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetAppOwnershipTicketLength(nAppID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetAppOwnershipTicketData ( uint32 nAppID,  void *pvBuffer,  uint32 cbBufferLength )	{
		char log[1024];
		sprintf(log,"GetAppOwnershipTicketData() nAppID=0x%X pvBuffer=0x%X cbBufferLength=0x%X ",
			nAppID,
			pvBuffer,
			cbBufferLength		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetAppOwnershipTicketData(nAppID, pvBuffer, cbBufferLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetAppOwnershipTicketExtendedData ( uint32 nAppID,  void *pvBuffer,  uint32 cbBufferLength,  uint32*,  uint32*,  uint32* ticket_length,  uint32* signature_length )	{
		char log[1024];
		sprintf(log,"GetAppOwnershipTicketExtendedData() nAppID=0x%X pvBuffer=0x%X cbBufferLength=0x%X =0x%X =0x%X ticket_length=0x%X signature_length=0x%X ",
			nAppID,
			pvBuffer,
			cbBufferLength,
			,
			,
			ticket_length,
			signature_length		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetAppOwnershipTicketExtendedData(nAppID, pvBuffer, cbBufferLength, , , ticket_length, signature_length);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAppDecryptionKey ( uint32 nAppID,  void *pvBuffer,  uint32 cbBufferLength )	{
		char log[1024];
		sprintf(log,"GetAppDecryptionKey() nAppID=0x%X pvBuffer=0x%X cbBufferLength=0x%X ",
			nAppID,
			pvBuffer,
			cbBufferLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAppDecryptionKey(nAppID, pvBuffer, cbBufferLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetMarketingMessageCount ()	{
		char log[1024];
		sprintf(log,"GetMarketingMessageCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetMarketingMessageCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetMarketingMessage ( int cMarketingMessage,  GID_t* gidMarketingMessageID,  char* pubMsgUrl,  int cubMessageUrl,  EMarketingMessageFlags *eMarketingMssageFlags )	{
		char log[1024];
		sprintf(log,"GetMarketingMessage() cMarketingMessage=0x%X gidMarketingMessageID=0x%X pubMsgUrl=%s cubMessageUrl=0x%X eMarketingMssageFlags=0x%X ",
			cMarketingMessage,
			gidMarketingMessageID,
			pubMsgUrl,
			cubMessageUrl,
			eMarketingMssageFlags		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetMarketingMessage(cMarketingMessage, gidMarketingMessageID, pubMsgUrl, cubMessageUrl, eMarketingMssageFlags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HAuthTicket  GetAuthSessionTicket ( void *pMyAuthTicket,  int cbMaxMyAuthTicket,  uint32* pcbAuthTicket )	{
		char log[1024];
		sprintf(log,"GetAuthSessionTicket() pMyAuthTicket=0x%X cbMaxMyAuthTicket=0x%X pcbAuthTicket=0x%X ",
			pMyAuthTicket,
			cbMaxMyAuthTicket,
			pcbAuthTicket		);
		OutputDebugStringA(log);
		HAuthTicket  ret = m_pWrapper->GetAuthSessionTicket(pMyAuthTicket, cbMaxMyAuthTicket, pcbAuthTicket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EBeginAuthSessionResult  BeginAuthSession ( void const* pTheirAuthTicket,  int cbTicket,  CSteamID steamID )	{
		char log[1024];
		sprintf(log,"BeginAuthSession() pTheirAuthTicket=0x%X cbTicket=0x%X steamID=0x%X ",
			pTheirAuthTicket,
			cbTicket,
			steamID		);
		OutputDebugStringA(log);
		EBeginAuthSessionResult  ret = m_pWrapper->BeginAuthSession(pTheirAuthTicket, cbTicket, steamID);
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
	virtual int  IsUserSubscribedAppInTicket ( CSteamID steamID,  AppId_t appID )	{
		char log[1024];
		sprintf(log,"IsUserSubscribedAppInTicket() steamID=0x%X appID=0x%X ",
			steamID,
			appID		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->IsUserSubscribedAppInTicket(steamID, appID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AdvertiseGame ( CGameID gameID,  CSteamID steamIDGameServer,  uint32 unIPServer ,  uint16 usPortServer )	{
		char log[1024];
		sprintf(log,"AdvertiseGame() gameID=0x%X steamIDGameServer=0x%X unIPServer=0x%X usPortServer=0x%X ",
			gameID,
			steamIDGameServer,
			unIPServer,
			usPortServer		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AdvertiseGame(gameID, steamIDGameServer, unIPServer, usPortServer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestEncryptedAppTicket ( const void *pUserData,  int cbUserData )	{
		char log[1024];
		sprintf(log,"RequestEncryptedAppTicket() pUserData=0x%X cbUserData=0x%X ",
			pUserData,
			cbUserData		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestEncryptedAppTicket(pUserData, cbUserData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetEncryptedAppTicket ( void *pTicket,  int cbMaxTicket,  uint32 *pcbTicket )	{
		char log[1024];
		sprintf(log,"GetEncryptedAppTicket() pTicket=0x%X cbMaxTicket=0x%X pcbTicket=0x%X ",
			pTicket,
			cbMaxTicket,
			pcbTicket		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetEncryptedAppTicket(pTicket, cbMaxTicket, pcbTicket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetAccountLimited ( bool bAccountLimited )	{
		char log[1024];
		sprintf(log,"SetAccountLimited() bAccountLimited=0x%X ",
			bAccountLimited		);
		OutputDebugStringA(log);
		bAccountLimited);
		OutputDebugStringA("\n");
	}
	virtual bool  BIsAccountLimited ()	{
		char log[1024];
		sprintf(log,"BIsAccountLimited() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsAccountLimited();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SendValidationEmail ()	{
		char log[1024];
		sprintf(log,"SendValidationEmail() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual bool  BGameConnectTokensAvailable ()	{
		char log[1024];
		sprintf(log,"BGameConnectTokensAvailable() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGameConnectTokensAvailable();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  NumGamesRunning ()	{
		char log[1024];
		sprintf(log,"NumGamesRunning() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->NumGamesRunning();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CGameID  GetRunningGameID ( int iGame )	{
		char log[1024];
		sprintf(log,"GetRunningGameID() iGame=0x%X ",
			iGame		);
		OutputDebugStringA(log);
		CGameID  ret = m_pWrapper->GetRunningGameID(iGame);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetAccountSecurityPolicyFlags ()	{
		char log[1024];
		sprintf(log,"GetAccountSecurityPolicyFlags() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetAccountSecurityPolicyFlags();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RequestChangeEmail ( const char *pchPassword,  int eRequestType )	{
		char log[1024];
		sprintf(log,"RequestChangeEmail() pchPassword=%s eRequestType=0x%X ",
			pchPassword,
			eRequestType		);
		OutputDebugStringA(log);
		pchPassword, eRequestType);
		OutputDebugStringA("\n");
	}
	virtual void  ChangePasswordWithCode ( const char *pchOldPassword,  const char *pchCode,  const char *pchNewPassword )	{
		char log[1024];
		sprintf(log,"ChangePasswordWithCode() pchOldPassword=%s pchCode=%s pchNewPassword=%s ",
			pchOldPassword,
			pchCode,
			pchNewPassword		);
		OutputDebugStringA(log);
		pchOldPassword, pchCode, pchNewPassword);
		OutputDebugStringA("\n");
	}
	virtual void  ChangeEmailWithCode ( const char *pchPassword,  const char *pchCode,  const char *pchEmail,  bool bUnk )	{
		char log[1024];
		sprintf(log,"ChangeEmailWithCode() pchPassword=%s pchCode=%s pchEmail=%s bUnk=0x%X ",
			pchPassword,
			pchCode,
			pchEmail,
			bUnk		);
		OutputDebugStringA(log);
		pchPassword, pchCode, pchEmail, bUnk);
		OutputDebugStringA("\n");
	}
	virtual void  ChangeSecretQuestionAndAnswerWithCode ( const char *pchPassword,  const char *pchCode,  const char *pchNewQuestion,  const char *pchNewAnswer )	{
		char log[1024];
		sprintf(log,"ChangeSecretQuestionAndAnswerWithCode() pchPassword=%s pchCode=%s pchNewQuestion=%s pchNewAnswer=%s ",
			pchPassword,
			pchCode,
			pchNewQuestion,
			pchNewAnswer		);
		OutputDebugStringA(log);
		pchPassword, pchCode, pchNewQuestion, pchNewAnswer);
		OutputDebugStringA("\n");
	}
	virtual void  SetClientStat ( EClientStat eStat,  int64 llValue,  AppId_t nAppID,  DepotId_t nDepotID,  CellID_t nCellID )	{
		char log[1024];
		sprintf(log,"SetClientStat() eStat=0x%X llValue=0x%X nAppID=0x%X nDepotID=0x%X nCellID=0x%X ",
			eStat,
			llValue,
			nAppID,
			nDepotID,
			nCellID		);
		OutputDebugStringA(log);
		eStat, llValue, nAppID, nDepotID, nCellID);
		OutputDebugStringA("\n");
	}
	virtual void  VerifyPassword ( const char *pchPassword )	{
		char log[1024];
		sprintf(log,"VerifyPassword() pchPassword=%s ",
			pchPassword		);
		OutputDebugStringA(log);
		pchPassword);
		OutputDebugStringA("\n");
	}
	virtual bool  BSupportUser ()	{
		char log[1024];
		sprintf(log,"BSupportUser() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BSupportUser();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsAppOverlayEnabled ( uint32 )	{
		char log[1024];
		sprintf(log,"BIsAppOverlayEnabled() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsAppOverlayEnabled(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsBehindNAT ()	{
		char log[1024];
		sprintf(log,"BIsBehindNAT() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsBehindNAT();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual AppId_t  GetMicroTxnAppID ( uint64 )	{
		char log[1024];
		sprintf(log,"GetMicroTxnAppID() uint64=0x%X ",
			uint64		);
		OutputDebugStringA(log);
		AppId_t  ret = m_pWrapper->GetMicroTxnAppID(uint64);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint64  GetMicroTxnOrderID ( uint64 )	{
		char log[1024];
		sprintf(log,"GetMicroTxnOrderID() uint64=0x%X ",
			uint64		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->GetMicroTxnOrderID(uint64);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetMicroTxnPrice ( uint64,  CAmount *,  CAmount *,  bool * )	{
		char log[1024];
		sprintf(log,"BGetMicroTxnPrice() uint64=0x%X =0x%X =0x%X =0x%X ",
			uint64,
			,
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetMicroTxnPrice(uint64, , , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetMicroTxnPrice ( uint64,  int *,  int *,  bool * )	{
		char log[1024];
		sprintf(log,"BGetMicroTxnPrice() uint64=0x%X =0x%X =0x%X =0x%X ",
			uint64,
			,
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetMicroTxnPrice(uint64, , , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetMicroTxnLineItemCount ( uint64 )	{
		char log[1024];
		sprintf(log,"GetMicroTxnLineItemCount() uint64=0x%X ",
			uint64		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetMicroTxnLineItemCount(uint64);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetMicroTxnLineItem ( uint64,  uint32,  CAmount *,  uint32 *,  char *,  uint32 )	{
		char log[1024];
		sprintf(log,"BGetMicroTxnLineItem() uint64=0x%X uint32=0x%X =0x%X =0x%X =%s uint32=0x%X ",
			uint64,
			uint32,
			,
			,
			,
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetMicroTxnLineItem(uint64, uint32, , , , uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetMicroTxnLineItem ( uint64,  uint32,  int *,  uint32 *,  char *,  uint32 )	{
		char log[1024];
		sprintf(log,"BGetMicroTxnLineItem() uint64=0x%X uint32=0x%X =0x%X =0x%X =%s uint32=0x%X ",
			uint64,
			uint32,
			,
			,
			,
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetMicroTxnLineItem(uint64, uint32, , , , uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsSandboxMicroTxn ( uint64,  bool* pbUnk )	{
		char log[1024];
		sprintf(log,"BIsSandboxMicroTxn() uint64=0x%X pbUnk=0x%X ",
			uint64,
			pbUnk		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsSandboxMicroTxn(uint64, pbUnk);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  AuthorizeMicroTxn ( uint64,  EMicroTxnAuthResponse )	{
		char log[1024];
		sprintf(log,"AuthorizeMicroTxn() uint64=0x%X EMicroTxnAuthResponse=0x%X ",
			uint64,
			EMicroTxnAuthResponse		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->AuthorizeMicroTxn(uint64, EMicroTxnAuthResponse);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  AuthorizeMicroTxn ( uint64,  int )	{
		char log[1024];
		sprintf(log,"AuthorizeMicroTxn() uint64=0x%X int=0x%X ",
			uint64,
			int		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->AuthorizeMicroTxn(uint64, int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  NotifyAppMicroTxnAuthResponse ( uint32,  uint64,  bool )	{
		char log[1024];
		sprintf(log,"NotifyAppMicroTxnAuthResponse() uint32=0x%X uint64=0x%X bool=0x%X ",
			uint32,
			uint64,
			bool		);
		OutputDebugStringA(log);
		uint32, uint64, bool);
		OutputDebugStringA("\n");
	}
	virtual bool  BGetWalletBalance ( bool *,  CAmount * )	{
		char log[1024];
		sprintf(log,"BGetWalletBalance() =0x%X =0x%X ",
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetWalletBalance(, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetWalletBalance ( bool *,  int * )	{
		char log[1024];
		sprintf(log,"BGetWalletBalance() =0x%X =0x%X ",
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetWalletBalance(, );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestMicroTxnInfo ( uint64 )	{
		char log[1024];
		sprintf(log,"RequestMicroTxnInfo() uint64=0x%X ",
			uint64		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestMicroTxnInfo(uint64);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetAppMinutesPlayed ( AppId_t nAppId,  int * piForever,  int * piLastTwoWeeks )	{
		char log[1024];
		sprintf(log,"BGetAppMinutesPlayed() nAppId=0x%X piForever=0x%X piLastTwoWeeks=0x%X ",
			nAppId,
			piForever,
			piLastTwoWeeks		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetAppMinutesPlayed(nAppId, piForever, piLastTwoWeeks);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetGuideURL ( AppId_t nAppId,  char * pchGuideURL,  uint32 cbGuideURL )	{
		char log[1024];
		sprintf(log,"BGetGuideURL() nAppId=0x%X pchGuideURL=%s cbGuideURL=0x%X ",
			nAppId,
			pchGuideURL,
			cbGuideURL		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetGuideURL(nAppId, pchGuideURL, cbGuideURL);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  GetClientAppListResponse_AddApp ( const ClientAppInfo * pClientAppInfo )	{
		char log[1024];
		sprintf(log,"GetClientAppListResponse_AddApp() pClientAppInfo=0x%X ",
			pClientAppInfo		);
		OutputDebugStringA(log);
		pClientAppInfo);
		OutputDebugStringA("\n");
	}
	virtual void  GetClientAppListResponse_AddDLC ( AppId_t nAppId,  bool bInstalled )	{
		char log[1024];
		sprintf(log,"GetClientAppListResponse_AddDLC() nAppId=0x%X bInstalled=0x%X ",
			nAppId,
			bInstalled		);
		OutputDebugStringA(log);
		nAppId, bInstalled);
		OutputDebugStringA("\n");
	}
	virtual void  GetClientAppListResponse_Done ( unsigned long long )	{
		char log[1024];
		sprintf(log,"GetClientAppListResponse_Done() long=0x%X ",
			long		);
		OutputDebugStringA(log);
		long);
		OutputDebugStringA("\n");
	}
	virtual void  PostUIResultToClientJob ( unsigned long long,  EResult )	{
		char log[1024];
		sprintf(log,"PostUIResultToClientJob() long=0x%X EResult=0x%X ",
			long,
			EResult		);
		OutputDebugStringA(log);
		long, EResult);
		OutputDebugStringA("\n");
	}
	virtual bool  BPromptToVerifyEmail ()	{
		char log[1024];
		sprintf(log,"BPromptToVerifyEmail() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BPromptToVerifyEmail();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BPromptToChangePassword ()	{
		char log[1024];
		sprintf(log,"BPromptToChangePassword() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BPromptToChangePassword();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BAccountLocked ()	{
		char log[1024];
		sprintf(log,"BAccountLocked() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BAccountLocked();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BAccountShouldShowLockUI ()	{
		char log[1024];
		sprintf(log,"BAccountShouldShowLockUI() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BAccountShouldShowLockUI();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BAccountLockedByIPT ()	{
		char log[1024];
		sprintf(log,"BAccountLockedByIPT() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BAccountLockedByIPT();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetCountAuthedComputers ()	{
		char log[1024];
		sprintf(log,"GetCountAuthedComputers() "		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetCountAuthedComputers();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BAccountCanUseIPT ()	{
		char log[1024];
		sprintf(log,"BAccountCanUseIPT() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BAccountCanUseIPT();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ChangeTwoFactorAuthOptions ( uint32 uOption )	{
		char log[1024];
		sprintf(log,"ChangeTwoFactorAuthOptions() uOption=0x%X ",
			uOption		);
		OutputDebugStringA(log);
		uOption);
		OutputDebugStringA("\n");
	}
	virtual void  Set2ndFactorAuthCode ( const char* pchAuthCode )	{
		char log[1024];
		sprintf(log,"Set2ndFactorAuthCode() pchAuthCode=%s ",
			pchAuthCode		);
		OutputDebugStringA(log);
		pchAuthCode);
		OutputDebugStringA("\n");
	}
	virtual bool  BAccountHasIPTConfig ()	{
		char log[1024];
		sprintf(log,"BAccountHasIPTConfig() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BAccountHasIPTConfig();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetEmailDomainFromLogonFailure ( char * pchEmailDomain,  int32 cbEmailDomain )	{
		char log[1024];
		sprintf(log,"GetEmailDomainFromLogonFailure() pchEmailDomain=%s cbEmailDomain=0x%X ",
			pchEmailDomain,
			cbEmailDomain		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetEmailDomainFromLogonFailure(pchEmailDomain, cbEmailDomain);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsSubscribedApp ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"BIsSubscribedApp() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsSubscribedApp(nAppId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RegisterActivationCode ( const char * pchActivationCode )	{
		char log[1024];
		sprintf(log,"RegisterActivationCode() pchActivationCode=%s ",
			pchActivationCode		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RegisterActivationCode(pchActivationCode);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  OptionalDLCInstallation ( AppId_t,  bool )	{
		char log[1024];
		sprintf(log,"OptionalDLCInstallation() AppId_t=0x%X bool=0x%X ",
			AppId_t,
			bool		);
		OutputDebugStringA(log);
		AppId_t, bool);
		OutputDebugStringA("\n");
	}
	virtual void  AckSystemIM (unsigned long long)	{
		char log[1024];
		sprintf(log,"AckSystemIM() long=0x%X ",
			long		);
		OutputDebugStringA(log);
		long);
		OutputDebugStringA("\n");
	}
	virtual SteamAPICall_t  RequestSpecialSurvey ( uint32 uSurveyId )	{
		char log[1024];
		sprintf(log,"RequestSpecialSurvey() uSurveyId=0x%X ",
			uSurveyId		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestSpecialSurvey(uSurveyId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  SendSpecialSurveyResponse ( uint32 uSurveyId,  const uint8 * pubData,  uint32 cubData )	{
		char log[1024];
		sprintf(log,"SendSpecialSurveyResponse() uSurveyId=0x%X pubData=0x%X cubData=0x%X ",
			uSurveyId,
			pubData,
			cubData		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->SendSpecialSurveyResponse(uSurveyId, pubData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
