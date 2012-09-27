#include "ISteamGameCoordinator001.h"

class ISteamGameCoordinator001_wrapper
{
public:
	virtual EGCResults  SendMessage ( uint32 unMsgType,  const void *pubData,  uint32 cubData )	{
		char log[1024];
		sprintf(log,"SendMessage() unMsgType=0x%X pubData=0x%X cubData=0x%X ",
			unMsgType,
			pubData,
			cubData		);
		OutputDebugStringA(log);
		EGCResults  ret = m_pWrapper->SendMessage(unMsgType, pubData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsMessageAvailable ( uint32 *pcubMsgSize )	{
		char log[1024];
		sprintf(log,"IsMessageAvailable() pcubMsgSize=0x%X ",
			pcubMsgSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsMessageAvailable(pcubMsgSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EGCResults  RetrieveMessage ( uint32 *punMsgType,  void *pubDest,  uint32 cubDest,  uint32 *pcubMsgSize )	{
		char log[1024];
		sprintf(log,"RetrieveMessage() punMsgType=0x%X pubDest=0x%X cubDest=0x%X pcubMsgSize=0x%X ",
			punMsgType,
			pubDest,
			cubDest,
			pcubMsgSize		);
		OutputDebugStringA(log);
		EGCResults  ret = m_pWrapper->RetrieveMessage(punMsgType, pubDest, cubDest, pcubMsgSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
