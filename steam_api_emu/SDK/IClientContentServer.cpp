#include "IClientContentServer.h"

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
	virtual void  LogOn ( uint32 uContentServerID )	{
		char log[1024];
		sprintf(log,"LogOn() uContentServerID=0x%X ",
			uContentServerID		);
		OutputDebugStringA(log);
		uContentServerID);
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
	virtual bool  SendClientContentAuthRequest ( CSteamID steamID,  uint32 unContentID,  bool bUseToken,  uint64 ulSessionToken,  bool bTokenPresent )	{
		char log[1024];
		sprintf(log,"SendClientContentAuthRequest() steamID=0x%X unContentID=0x%X bUseToken=0x%X ulSessionToken=0x%X bTokenPresent=0x%X ",
			steamID,
			unContentID,
			bUseToken,
			ulSessionToken,
			bTokenPresent		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendClientContentAuthRequest(steamID, unContentID, bUseToken, ulSessionToken, bTokenPresent);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BCheckTicket ( CSteamID steamID,  uint32 uContentID,  const void *pvTicketData,  uint32 cubTicketLength )	{
		char log[1024];
		sprintf(log,"BCheckTicket() steamID=0x%X uContentID=0x%X pvTicketData=0x%X cubTicketLength=0x%X ",
			steamID,
			uContentID,
			pvTicketData,
			cubTicketLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BCheckTicket(steamID, uContentID, pvTicketData, cubTicketLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
