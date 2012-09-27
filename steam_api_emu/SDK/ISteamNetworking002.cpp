#include "ISteamNetworking002.h"

class ISteamNetworking002_wrapper
{
public:
	virtual SNetListenSocket_t  CreateListenSocket ( int nVirtualP2PPort,  uint32 nIP,  uint16 nPort,  bool bAllowUseOfPacketRelay )	{
		char log[1024];
		sprintf(log,"CreateListenSocket() nVirtualP2PPort=0x%X nIP=0x%X nPort=0x%X bAllowUseOfPacketRelay=0x%X ",
			nVirtualP2PPort,
			nIP,
			nPort,
			bAllowUseOfPacketRelay		);
		OutputDebugStringA(log);
		SNetListenSocket_t  ret = m_pWrapper->CreateListenSocket(nVirtualP2PPort, nIP, nPort, bAllowUseOfPacketRelay);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SNetSocket_t  CreateP2PConnectionSocket ( CSteamID steamIDTarget,  int nVirtualPort,  int nTimeoutSec,  bool bAllowUseOfPacketRelay )	{
		char log[1024];
		sprintf(log,"CreateP2PConnectionSocket() steamIDTarget=0x%X nVirtualPort=0x%X nTimeoutSec=0x%X bAllowUseOfPacketRelay=0x%X ",
			steamIDTarget,
			nVirtualPort,
			nTimeoutSec,
			bAllowUseOfPacketRelay		);
		OutputDebugStringA(log);
		SNetSocket_t  ret = m_pWrapper->CreateP2PConnectionSocket(steamIDTarget, nVirtualPort, nTimeoutSec, bAllowUseOfPacketRelay);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SNetSocket_t  CreateConnectionSocket ( uint32 nIP,  uint16 nPort,  int nTimeoutSec )	{
		char log[1024];
		sprintf(log,"CreateConnectionSocket() nIP=0x%X nPort=0x%X nTimeoutSec=0x%X ",
			nIP,
			nPort,
			nTimeoutSec		);
		OutputDebugStringA(log);
		SNetSocket_t  ret = m_pWrapper->CreateConnectionSocket(nIP, nPort, nTimeoutSec);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  DestroySocket ( SNetSocket_t hSocket,  bool bNotifyRemoteEnd )	{
		char log[1024];
		sprintf(log,"DestroySocket() hSocket=0x%X bNotifyRemoteEnd=0x%X ",
			hSocket,
			bNotifyRemoteEnd		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->DestroySocket(hSocket, bNotifyRemoteEnd);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  DestroyListenSocket ( SNetListenSocket_t hSocket,  bool bNotifyRemoteEnd )	{
		char log[1024];
		sprintf(log,"DestroyListenSocket() hSocket=0x%X bNotifyRemoteEnd=0x%X ",
			hSocket,
			bNotifyRemoteEnd		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->DestroyListenSocket(hSocket, bNotifyRemoteEnd);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendDataOnSocket ( SNetSocket_t hSocket,  void *pubData,  uint32 cubData,  bool bReliable )	{
		char log[1024];
		sprintf(log,"SendDataOnSocket() hSocket=0x%X pubData=0x%X cubData=0x%X bReliable=0x%X ",
			hSocket,
			pubData,
			cubData,
			bReliable		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendDataOnSocket(hSocket, pubData, cubData, bReliable);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsDataAvailableOnSocket ( SNetSocket_t hSocket,  uint32 *pcubMsgSize )	{
		char log[1024];
		sprintf(log,"IsDataAvailableOnSocket() hSocket=0x%X pcubMsgSize=0x%X ",
			hSocket,
			pcubMsgSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsDataAvailableOnSocket(hSocket, pcubMsgSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RetrieveDataFromSocket ( SNetSocket_t hSocket,  void *pubDest,  uint32 cubDest,  uint32 *pcubMsgSize )	{
		char log[1024];
		sprintf(log,"RetrieveDataFromSocket() hSocket=0x%X pubDest=0x%X cubDest=0x%X pcubMsgSize=0x%X ",
			hSocket,
			pubDest,
			cubDest,
			pcubMsgSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RetrieveDataFromSocket(hSocket, pubDest, cubDest, pcubMsgSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsDataAvailable ( SNetListenSocket_t hListenSocket,  uint32 *pcubMsgSize,  SNetSocket_t *phSocket )	{
		char log[1024];
		sprintf(log,"IsDataAvailable() hListenSocket=0x%X pcubMsgSize=0x%X phSocket=0x%X ",
			hListenSocket,
			pcubMsgSize,
			phSocket		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsDataAvailable(hListenSocket, pcubMsgSize, phSocket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RetrieveData ( SNetListenSocket_t hListenSocket,  void *pubDest,  uint32 cubDest,  uint32 *pcubMsgSize,  SNetSocket_t *phSocket )	{
		char log[1024];
		sprintf(log,"RetrieveData() hListenSocket=0x%X pubDest=0x%X cubDest=0x%X pcubMsgSize=0x%X phSocket=0x%X ",
			hListenSocket,
			pubDest,
			cubDest,
			pcubMsgSize,
			phSocket		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RetrieveData(hListenSocket, pubDest, cubDest, pcubMsgSize, phSocket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetSocketInfo ( SNetSocket_t hSocket,  CSteamID *pSteamIDRemote,  ESNetSocketState *peSocketStatus,  uint32 *punIPRemote,  uint16 *punPortRemote )	{
		char log[1024];
		sprintf(log,"GetSocketInfo() hSocket=0x%X pSteamIDRemote=0x%X peSocketStatus=0x%X punIPRemote=0x%X punPortRemote=0x%X ",
			hSocket,
			pSteamIDRemote,
			peSocketStatus,
			punIPRemote,
			punPortRemote		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetSocketInfo(hSocket, pSteamIDRemote, peSocketStatus, punIPRemote, punPortRemote);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetListenSocketInfo ( SNetListenSocket_t hListenSocket,  uint32 *pnIP,  uint16 *pnPort )	{
		char log[1024];
		sprintf(log,"GetListenSocketInfo() hListenSocket=0x%X pnIP=0x%X pnPort=0x%X ",
			hListenSocket,
			pnIP,
			pnPort		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetListenSocketInfo(hListenSocket, pnIP, pnPort);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual ESNetSocketConnectionType  GetSocketConnectionType ( SNetSocket_t hSocket )	{
		char log[1024];
		sprintf(log,"GetSocketConnectionType() hSocket=0x%X ",
			hSocket		);
		OutputDebugStringA(log);
		ESNetSocketConnectionType  ret = m_pWrapper->GetSocketConnectionType(hSocket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetMaxPacketSize ( SNetSocket_t hSocket )	{
		char log[1024];
		sprintf(log,"GetMaxPacketSize() hSocket=0x%X ",
			hSocket		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetMaxPacketSize(hSocket);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
