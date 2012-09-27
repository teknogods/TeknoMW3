#include "ISteamUser005.h"

class ISteamUser005_wrapper
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
	virtual void  LogOn ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"LogOn() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		steamID);
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
	virtual bool  IsVACBanned ( EVACBan eVACBan )	{
		char log[1024];
		sprintf(log,"IsVACBanned() eVACBan=0x%X ",
			eVACBan		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsVACBanned(eVACBan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequireShowVACBannedMessage ( EVACBan eVACBan )	{
		char log[1024];
		sprintf(log,"RequireShowVACBannedMessage() eVACBan=0x%X ",
			eVACBan		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequireShowVACBannedMessage(eVACBan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  AcknowledgeVACBanning ( EVACBan eVACBan )	{
		char log[1024];
		sprintf(log,"AcknowledgeVACBanning() eVACBan=0x%X ",
			eVACBan		);
		OutputDebugStringA(log);
		eVACBan);
		OutputDebugStringA("\n");
	}
	virtual void  SetSteam2Ticket ( uint8 *pubTicket,  int cubTicket )	{
		char log[1024];
		sprintf(log,"SetSteam2Ticket() pubTicket=0x%X cubTicket=0x%X ",
			pubTicket,
			cubTicket		);
		OutputDebugStringA(log);
		pubTicket, cubTicket);
		OutputDebugStringA("\n");
	}
	virtual OBSOLETE_FUNCTION void  AddServerNetAddress ( uint32 unIP,  uint16 unPort )	{
		char log[1024];
		sprintf(log,"AddServerNetAddress() unIP=0x%X unPort=0x%X ",
			unIP,
			unPort		);
		OutputDebugStringA(log);
		unIP, unPort);
		OutputDebugStringA("\n");
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
	virtual bool  SetRegistryString ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetRegistryString() eRegistrySubTree=0x%X pchKey=%s pchValue=%s ",
			eRegistrySubTree,
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetRegistryString(eRegistrySubTree, pchKey, pchValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetRegistryString ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  char *pchValue,  int cbValue )	{
		char log[1024];
		sprintf(log,"GetRegistryString() eRegistrySubTree=0x%X pchKey=%s pchValue=%s cbValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			pchValue,
			cbValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetRegistryString(eRegistrySubTree, pchKey, pchValue, cbValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetRegistryInt ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  int iValue )	{
		char log[1024];
		sprintf(log,"SetRegistryInt() eRegistrySubTree=0x%X pchKey=%s iValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			iValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetRegistryInt(eRegistrySubTree, pchKey, iValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetRegistryInt ( ERegistrySubTree eRegistrySubTree,  const char *pchKey,  int *piValue )	{
		char log[1024];
		sprintf(log,"GetRegistryInt() eRegistrySubTree=0x%X pchKey=%s piValue=0x%X ",
			eRegistrySubTree,
			pchKey,
			piValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetRegistryInt(eRegistrySubTree, pchKey, piValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  InitiateGameConnection ( void *pBlob,  int cbMaxBlob,  CSteamID steamID,  CGameID nGameAppID,  uint32 unIPServer,  uint16 usPortServer,  bool bSecure )	{
		char log[1024];
		sprintf(log,"InitiateGameConnection() pBlob=0x%X cbMaxBlob=0x%X steamID=0x%X nGameAppID=0x%X unIPServer=0x%X usPortServer=0x%X bSecure=0x%X ",
			pBlob,
			cbMaxBlob,
			steamID,
			nGameAppID,
			unIPServer,
			usPortServer,
			bSecure		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->InitiateGameConnection(pBlob, cbMaxBlob, steamID, nGameAppID, unIPServer, usPortServer, bSecure);
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
	virtual bool  GetGuestPassToGiveInfo ( uint32 nPassIndex,  GID_t *pgidGuestPassID,  PackageId_t* pnPackageID,  RTime32* pRTime32Created,  RTime32* pRTime32Expiration,  RTime32* pRTime32Sent,  RTime32* pRTime32Redeemed,  char * pchRecipientAddress,  int cRecipientAddressSize )	{
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
	virtual void  SetAccountName ( const char* pchAccountName )	{
		char log[1024];
		sprintf(log,"SetAccountName() pchAccountName=%s ",
			pchAccountName		);
		OutputDebugStringA(log);
		pchAccountName);
		OutputDebugStringA("\n");
	}
	virtual void  SetPassword ( const char* pchPassword )	{
		char log[1024];
		sprintf(log,"SetPassword() pchPassword=%s ",
			pchPassword		);
		OutputDebugStringA(log);
		pchPassword);
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
};
