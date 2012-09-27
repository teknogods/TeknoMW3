#include "IClientMasterServerUpdater.h"

	virtual void  SetActive ( bool bActive )	{
		char log[1024];
		sprintf(log,"SetActive() bActive=0x%X ",
			bActive		);
		OutputDebugStringA(log);
		bActive);
		OutputDebugStringA("\n");
	}
	virtual void  SetHeartbeatInterval ( int iHeartbeatInterval )	{
		char log[1024];
		sprintf(log,"SetHeartbeatInterval() iHeartbeatInterval=0x%X ",
			iHeartbeatInterval		);
		OutputDebugStringA(log);
		iHeartbeatInterval);
		OutputDebugStringA("\n");
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
	virtual void  SetBasicServerData ( unsigned short nProtocolVersion,  bool bDedicatedServer,  const char *pRegionName,  const char *pProductName,  unsigned short nMaxReportedClients,  bool bPasswordProtected,  const char *pGameDescription )	{
		char log[1024];
		sprintf(log,"SetBasicServerData() nProtocolVersion=0x%X bDedicatedServer=0x%X pRegionName=%s pProductName=%s nMaxReportedClients=0x%X bPasswordProtected=0x%X pGameDescription=%s ",
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
	virtual void  NotifyShutdown ()	{
		char log[1024];
		sprintf(log,"NotifyShutdown() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
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
	virtual void  ForceHeartbeat ()	{
		char log[1024];
		sprintf(log,"ForceHeartbeat() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual bool  AddMasterServer ( const char *pServerAddress )	{
		char log[1024];
		sprintf(log,"AddMasterServer() pServerAddress=%s ",
			pServerAddress		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddMasterServer(pServerAddress);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveMasterServer ( const char *pServerAddress )	{
		char log[1024];
		sprintf(log,"RemoveMasterServer() pServerAddress=%s ",
			pServerAddress		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveMasterServer(pServerAddress);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetNumMasterServers ()	{
		char log[1024];
		sprintf(log,"GetNumMasterServers() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetNumMasterServers();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetMasterServerAddress ( int iServer,  char *pOut,  int outBufferSize )	{
		char log[1024];
		sprintf(log,"GetMasterServerAddress() iServer=0x%X pOut=%s outBufferSize=0x%X ",
			iServer,
			pOut,
			outBufferSize		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetMasterServerAddress(iServer, pOut, outBufferSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
