#include "ISteamUser004.h"

class ISteamUser004_wrapper
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
	virtual OBSOLETE_FUNCTION int  NClientGameIDAdd ( int nGameID )	{
		char log[1024];
		sprintf(log,"NClientGameIDAdd() nGameID=0x%X ",
			nGameID		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION int  ret = m_pWrapper->NClientGameIDAdd(nGameID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION void  RemoveClientGame ( int nClientGameID )	{
		char log[1024];
		sprintf(log,"RemoveClientGame() nClientGameID=0x%X ",
			nClientGameID		);
		OutputDebugStringA(log);
		nClientGameID);
		OutputDebugStringA("\n");
	}
	virtual OBSOLETE_FUNCTION void  SetClientGameServer ( int nClientGameID,  uint32 unIPServer,  uint16 usPortServer )	{
		char log[1024];
		sprintf(log,"SetClientGameServer() nClientGameID=0x%X unIPServer=0x%X usPortServer=0x%X ",
			nClientGameID,
			unIPServer,
			usPortServer		);
		OutputDebugStringA(log);
		nClientGameID, unIPServer, usPortServer);
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
	virtual OBSOLETE_FUNCTION int  GetSteamGameConnectToken ( void *pBlob,  int cbMaxBlob )	{
		char log[1024];
		sprintf(log,"GetSteamGameConnectToken() pBlob=0x%X cbMaxBlob=0x%X ",
			pBlob,
			cbMaxBlob		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION int  ret = m_pWrapper->GetSteamGameConnectToken(pBlob, cbMaxBlob);
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
	virtual int  InitiateGameConnection ( void *pBlob,  int cbMaxBlob,  CSteamID steamID,  int nGameAppID,  uint32 unIPServer,  uint16 usPortServer,  bool bSecure )	{
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
};
