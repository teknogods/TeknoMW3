#include "IClientGameCoordinator.h"

class IClientGameCoordinator_wrapper
{
public:
	virtual EGCResults  SendMessage ( AppId_t unAppID,  uint32 unMsgType,  const void *pubData,  uint32 cubData )	{
		char log[1024];
		sprintf(log,"SendMessage() unAppID=0x%X unMsgType=0x%X pubData=0x%X cubData=0x%X ",
			unAppID,
			unMsgType,
			pubData,
			cubData		);
		OutputDebugStringA(log);
		EGCResults  ret = m_pWrapper->SendMessage(unAppID, unMsgType, pubData, cubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsMessageAvailable ( AppId_t unAppID,  uint32 *pcubMsgSize )	{
		char log[1024];
		sprintf(log,"IsMessageAvailable() unAppID=0x%X pcubMsgSize=0x%X ",
			unAppID,
			pcubMsgSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsMessageAvailable(unAppID, pcubMsgSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EGCResults  RetrieveMessage ( AppId_t unAppID,  uint32 *punMsgType,  void *pubDest,  uint32 cubDest,  uint32 *pcubMsgSize )	{
		char log[1024];
		sprintf(log,"RetrieveMessage() unAppID=0x%X punMsgType=0x%X pubDest=0x%X cubDest=0x%X pcubMsgSize=0x%X ",
			unAppID,
			punMsgType,
			pubDest,
			cubDest,
			pcubMsgSize		);
		OutputDebugStringA(log);
		EGCResults  ret = m_pWrapper->RetrieveMessage(unAppID, punMsgType, pubDest, cubDest, pcubMsgSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
