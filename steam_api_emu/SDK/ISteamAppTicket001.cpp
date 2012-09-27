#include "ISteamAppTicket001.h"

class ISteamAppTicket001_wrapper
{
public:
	virtual uint32  GetAppOwnershipTicketData ( uint32 nAppID,  void *pvBuffer,  uint32 cbBufferLength,  uint32 *piAppId,  uint32 *piSteamId,  uint32 *piSignature,  uint32 *pcbSignature )	{
		char log[1024];
		sprintf(log,"GetAppOwnershipTicketData() nAppID=0x%X pvBuffer=0x%X cbBufferLength=0x%X piAppId=0x%X piSteamId=0x%X piSignature=0x%X pcbSignature=0x%X ",
			nAppID,
			pvBuffer,
			cbBufferLength,
			piAppId,
			piSteamId,
			piSignature,
			pcbSignature		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetAppOwnershipTicketData(nAppID, pvBuffer, cbBufferLength, piAppId, piSteamId, piSignature, pcbSignature);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
