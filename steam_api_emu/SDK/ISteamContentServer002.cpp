#include "ISteamContentServer002.h"

class ISteamContentServer002_wrapper
{
public:
	virtual bool  LogOn ( uint32 uContentServerID )	{
		char log[1024];
		sprintf(log,"LogOn() uContentServerID=0x%X ",
			uContentServerID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->LogOn(uContentServerID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  LogOff ()	{
		char log[1024];
		sprintf(log,"LogOff() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->LogOff();
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
	virtual void  SendClientContentAuthRequest ( CSteamID steamId,  uint32 unContentID,  uint64 ulSessionToken,  bool bTokenPresent )	{
		char log[1024];
		sprintf(log,"SendClientContentAuthRequest() steamId=0x%X unContentID=0x%X ulSessionToken=0x%X bTokenPresent=0x%X ",
			steamId,
			unContentID,
			ulSessionToken,
			bTokenPresent		);
		OutputDebugStringA(log);
		steamId, unContentID, ulSessionToken, bTokenPresent);
		OutputDebugStringA("\n");
	}
	virtual bool  BCheckTicket ( CSteamID steamId,  uint32 uContentID,  const void *pvTicketData,  uint32 cubTicketLength )	{
		char log[1024];
		sprintf(log,"BCheckTicket() steamId=0x%X uContentID=0x%X pvTicketData=0x%X cubTicketLength=0x%X ",
			steamId,
			uContentID,
			pvTicketData,
			cubTicketLength		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BCheckTicket(steamId, uContentID, pvTicketData, cubTicketLength);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
