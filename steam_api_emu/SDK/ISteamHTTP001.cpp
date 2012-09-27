#include "ISteamHTTP001.h"

class ISteamHTTP001_wrapper
{
public:
	virtual HTTPRequestHandle  CreateHTTPRequest ( EHTTPMethod eHTTPRequestMethod,  const char *pchAbsoluteURL )	{
		char log[1024];
		sprintf(log,"CreateHTTPRequest() eHTTPRequestMethod=0x%X pchAbsoluteURL=%s ",
			eHTTPRequestMethod,
			pchAbsoluteURL		);
		OutputDebugStringA(log);
		HTTPRequestHandle  ret = m_pWrapper->CreateHTTPRequest(eHTTPRequestMethod, pchAbsoluteURL);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetHTTPRequestContextValue ( HTTPRequestHandle hRequest,  uint64 ulContextValue )	{
		char log[1024];
		sprintf(log,"SetHTTPRequestContextValue() hRequest=0x%X ulContextValue=0x%X ",
			hRequest,
			ulContextValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetHTTPRequestContextValue(hRequest, ulContextValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetHTTPRequestNetworkActivityTimeout ( HTTPRequestHandle hRequest,  uint32 unTimeoutSeconds )	{
		char log[1024];
		sprintf(log,"SetHTTPRequestNetworkActivityTimeout() hRequest=0x%X unTimeoutSeconds=0x%X ",
			hRequest,
			unTimeoutSeconds		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetHTTPRequestNetworkActivityTimeout(hRequest, unTimeoutSeconds);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetHTTPRequestHeaderValue ( HTTPRequestHandle hRequest,  const char *pchHeaderName,  const char *pchHeaderValue )	{
		char log[1024];
		sprintf(log,"SetHTTPRequestHeaderValue() hRequest=0x%X pchHeaderName=%s pchHeaderValue=%s ",
			hRequest,
			pchHeaderName,
			pchHeaderValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetHTTPRequestHeaderValue(hRequest, pchHeaderName, pchHeaderValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetHTTPRequestGetOrPostParameter ( HTTPRequestHandle hRequest,  const char *pchParamName,  const char *pchParamValue )	{
		char log[1024];
		sprintf(log,"SetHTTPRequestGetOrPostParameter() hRequest=0x%X pchParamName=%s pchParamValue=%s ",
			hRequest,
			pchParamName,
			pchParamValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetHTTPRequestGetOrPostParameter(hRequest, pchParamName, pchParamValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendHTTPRequest ( HTTPRequestHandle hRequest,  SteamAPICall_t *pCallHandle )	{
		char log[1024];
		sprintf(log,"SendHTTPRequest() hRequest=0x%X pCallHandle=0x%X ",
			hRequest,
			pCallHandle		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendHTTPRequest(hRequest, pCallHandle);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  DeferHTTPRequest ( HTTPRequestHandle hRequest )	{
		char log[1024];
		sprintf(log,"DeferHTTPRequest() hRequest=0x%X ",
			hRequest		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->DeferHTTPRequest(hRequest);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  PrioritizeHTTPRequest ( HTTPRequestHandle hRequest )	{
		char log[1024];
		sprintf(log,"PrioritizeHTTPRequest() hRequest=0x%X ",
			hRequest		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->PrioritizeHTTPRequest(hRequest);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetHTTPResponseHeaderSize ( HTTPRequestHandle hRequest,  const char *pchHeaderName,  uint32 *unResponseHeaderSize )	{
		char log[1024];
		sprintf(log,"GetHTTPResponseHeaderSize() hRequest=0x%X pchHeaderName=%s unResponseHeaderSize=0x%X ",
			hRequest,
			pchHeaderName,
			unResponseHeaderSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetHTTPResponseHeaderSize(hRequest, pchHeaderName, unResponseHeaderSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetHTTPResponseHeaderValue ( HTTPRequestHandle hRequest,  const char *pchHeaderName,  uint8 *pHeaderValueBuffer,  uint32 unBufferSize )	{
		char log[1024];
		sprintf(log,"GetHTTPResponseHeaderValue() hRequest=0x%X pchHeaderName=%s pHeaderValueBuffer=0x%X unBufferSize=0x%X ",
			hRequest,
			pchHeaderName,
			pHeaderValueBuffer,
			unBufferSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetHTTPResponseHeaderValue(hRequest, pchHeaderName, pHeaderValueBuffer, unBufferSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetHTTPResponseBodySize ( HTTPRequestHandle hRequest,  uint32 *unBodySize )	{
		char log[1024];
		sprintf(log,"GetHTTPResponseBodySize() hRequest=0x%X unBodySize=0x%X ",
			hRequest,
			unBodySize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetHTTPResponseBodySize(hRequest, unBodySize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetHTTPResponseBodyData ( HTTPRequestHandle hRequest,  uint8 *pBodyDataBuffer,  uint32 unBufferSize )	{
		char log[1024];
		sprintf(log,"GetHTTPResponseBodyData() hRequest=0x%X pBodyDataBuffer=0x%X unBufferSize=0x%X ",
			hRequest,
			pBodyDataBuffer,
			unBufferSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetHTTPResponseBodyData(hRequest, pBodyDataBuffer, unBufferSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ReleaseHTTPRequest ( HTTPRequestHandle hRequest )	{
		char log[1024];
		sprintf(log,"ReleaseHTTPRequest() hRequest=0x%X ",
			hRequest		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ReleaseHTTPRequest(hRequest);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetHTTPDownloadProgressPct ( HTTPRequestHandle hRequest,  float *pflPercentOut )	{
		char log[1024];
		sprintf(log,"GetHTTPDownloadProgressPct() hRequest=0x%X pflPercentOut=0x%X ",
			hRequest,
			pflPercentOut		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetHTTPDownloadProgressPct(hRequest, pflPercentOut);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetHTTPRequestRawPostBody ( HTTPRequestHandle hRequest,  const char *pchContentType,  uint8 *pubBodyData,  uint32 cubBodyData )	{
		char log[1024];
		sprintf(log,"SetHTTPRequestRawPostBody() hRequest=0x%X pchContentType=%s pubBodyData=0x%X cubBodyData=0x%X ",
			hRequest,
			pchContentType,
			pubBodyData,
			cubBodyData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetHTTPRequestRawPostBody(hRequest, pchContentType, pubBodyData, cubBodyData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
