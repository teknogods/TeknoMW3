#include "ISteamRemoteStorage001.h"

class ISteamRemoteStorage001_wrapper
{
public:
	virtual bool  FileWrite ( const char *filename,  void  const *data,  int )	{
		char log[1024];
		sprintf(log,"FileWrite() filename=%s data=0x%X int=0x%X ",
			filename,
			data,
			int		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileWrite(filename, data, int);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetFileSize ( const char *filename )	{
		char log[1024];
		sprintf(log,"GetFileSize() filename=%s ",
			filename		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetFileSize(filename);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileRead ( const char *filename,  void *buffer,  int size )	{
		char log[1024];
		sprintf(log,"FileRead() filename=%s buffer=0x%X size=0x%X ",
			filename,
			buffer,
			size		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileRead(filename, buffer, size);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FileExists ( const char *filename )	{
		char log[1024];
		sprintf(log,"FileExists() filename=%s ",
			filename		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FileExists(filename);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION bool  FileDelete ( const char *filename )	{
		char log[1024];
		sprintf(log,"FileDelete() filename=%s ",
			filename		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION bool  ret = m_pWrapper->FileDelete(filename);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetFileCount ()	{
		char log[1024];
		sprintf(log,"GetFileCount() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetFileCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetFileNameAndSize ( int index,  int *size )	{
		char log[1024];
		sprintf(log,"GetFileNameAndSize() index=0x%X size=0x%X ",
			index,
			size		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFileNameAndSize(index, size);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetQuota ( int *current,  int *maximum )	{
		char log[1024];
		sprintf(log,"GetQuota() current=0x%X maximum=0x%X ",
			current,
			maximum		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetQuota(current, maximum);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
