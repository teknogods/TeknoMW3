#include "IClientConfigStore.h"

	virtual bool  IsSet ( EConfigStore eConfigStore,  const char *keyName )	{
		char log[1024];
		sprintf(log,"IsSet() eConfigStore=0x%X keyName=%s ",
			eConfigStore,
			keyName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsSet(eConfigStore, keyName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetBool ( EConfigStore eConfigStore,  const char *keyName,  bool defaultValue )	{
		char log[1024];
		sprintf(log,"GetBool() eConfigStore=0x%X keyName=%s defaultValue=0x%X ",
			eConfigStore,
			keyName,
			defaultValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetBool(eConfigStore, keyName, defaultValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetInt ( EConfigStore eConfigStore,  const char *keyName,  int defaultValue )	{
		char log[1024];
		sprintf(log,"GetInt() eConfigStore=0x%X keyName=%s defaultValue=0x%X ",
			eConfigStore,
			keyName,
			defaultValue		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetInt(eConfigStore, keyName, defaultValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint64  GetUint64 ( EConfigStore eConfigStore,  const char *keyName,  uint64 defaultValue )	{
		char log[1024];
		sprintf(log,"GetUint64() eConfigStore=0x%X keyName=%s defaultValue=0x%X ",
			eConfigStore,
			keyName,
			defaultValue		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->GetUint64(eConfigStore, keyName, defaultValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  GetFloat ( EConfigStore eConfigStore,  const char *keyName,  float defaultValue )	{
		char log[1024];
		sprintf(log,"GetFloat() eConfigStore=0x%X keyName=%s defaultValue=0x%X ",
			eConfigStore,
			keyName,
			defaultValue		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->GetFloat(eConfigStore, keyName, defaultValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char*  GetString ( EConfigStore eConfigStore,  const char *keyName,  const char *defaultValue )	{
		char log[1024];
		sprintf(log,"GetString() eConfigStore=0x%X keyName=%s defaultValue=%s ",
			eConfigStore,
			keyName,
			defaultValue		);
		OutputDebugStringA(log);
		const char*  ret = m_pWrapper->GetString(eConfigStore, keyName, defaultValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetBinary ( EConfigStore eConfigStore,  const char *keyName,  uint8 *pBuffer,  uint32 uSize )	{
		char log[1024];
		sprintf(log,"GetBinary() eConfigStore=0x%X keyName=%s pBuffer=0x%X uSize=0x%X ",
			eConfigStore,
			keyName,
			pBuffer,
			uSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetBinary(eConfigStore, keyName, pBuffer, uSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetBinaryWatermarked ( EConfigStore eConfigStore,  const char *keyName,  uint8 *pBuffer,  uint32 uSize )	{
		char log[1024];
		sprintf(log,"GetBinaryWatermarked() eConfigStore=0x%X keyName=%s pBuffer=0x%X uSize=0x%X ",
			eConfigStore,
			keyName,
			pBuffer,
			uSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetBinaryWatermarked(eConfigStore, keyName, pBuffer, uSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetBool ( EConfigStore eConfigStore,  const char *keyName,  bool value )	{
		char log[1024];
		sprintf(log,"SetBool() eConfigStore=0x%X keyName=%s value=0x%X ",
			eConfigStore,
			keyName,
			value		);
		OutputDebugStringA(log);
		eConfigStore, keyName, value);
		OutputDebugStringA("\n");
	}
	virtual void  SetInt ( EConfigStore eConfigStore,  const char *keyName,  int value )	{
		char log[1024];
		sprintf(log,"SetInt() eConfigStore=0x%X keyName=%s value=0x%X ",
			eConfigStore,
			keyName,
			value		);
		OutputDebugStringA(log);
		eConfigStore, keyName, value);
		OutputDebugStringA("\n");
	}
	virtual void  SetUint64 ( EConfigStore eConfigStore,  const char *keyName,  uint64 value )	{
		char log[1024];
		sprintf(log,"SetUint64() eConfigStore=0x%X keyName=%s value=0x%X ",
			eConfigStore,
			keyName,
			value		);
		OutputDebugStringA(log);
		eConfigStore, keyName, value);
		OutputDebugStringA("\n");
	}
	virtual void  SetFloat ( EConfigStore eConfigStore,  const char *keyName,  float value )	{
		char log[1024];
		sprintf(log,"SetFloat() eConfigStore=0x%X keyName=%s value=0x%X ",
			eConfigStore,
			keyName,
			value		);
		OutputDebugStringA(log);
		eConfigStore, keyName, value);
		OutputDebugStringA("\n");
	}
	virtual void  SetString ( EConfigStore eConfigStore,  const char *keyName,  const char *value )	{
		char log[1024];
		sprintf(log,"SetString() eConfigStore=0x%X keyName=%s value=%s ",
			eConfigStore,
			keyName,
			value		);
		OutputDebugStringA(log);
		eConfigStore, keyName, value);
		OutputDebugStringA("\n");
	}
	virtual void  SetBinary ( EConfigStore eConfigStore,  const char *keyName,  const uint8 *pBuffer,  uint32 uSize )	{
		char log[1024];
		sprintf(log,"SetBinary() eConfigStore=0x%X keyName=%s pBuffer=0x%X uSize=0x%X ",
			eConfigStore,
			keyName,
			pBuffer,
			uSize		);
		OutputDebugStringA(log);
		eConfigStore, keyName, pBuffer, uSize);
		OutputDebugStringA("\n");
	}
	virtual void  SetBinaryWatermarked ( EConfigStore eConfigStore,  const char *keyName,  const uint8 *pBuffer,  uint32 uSize )	{
		char log[1024];
		sprintf(log,"SetBinaryWatermarked() eConfigStore=0x%X keyName=%s pBuffer=0x%X uSize=0x%X ",
			eConfigStore,
			keyName,
			pBuffer,
			uSize		);
		OutputDebugStringA(log);
		eConfigStore, keyName, pBuffer, uSize);
		OutputDebugStringA("\n");
	}
	virtual void  RemoveKey ( EConfigStore eConfigStore,  const char *keyName )	{
		char log[1024];
		sprintf(log,"RemoveKey() eConfigStore=0x%X keyName=%s ",
			eConfigStore,
			keyName		);
		OutputDebugStringA(log);
		eConfigStore, keyName);
		OutputDebugStringA("\n");
	}
	virtual bool  GetKeySerialized ( EConfigStore eConfigStore,  const char *keyName,  uint8 *pBuffer,  int iSize )	{
		char log[1024];
		sprintf(log,"GetKeySerialized() eConfigStore=0x%X keyName=%s pBuffer=0x%X iSize=0x%X ",
			eConfigStore,
			keyName,
			pBuffer,
			iSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetKeySerialized(eConfigStore, keyName, pBuffer, iSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  FlushToDisk ( bool )	{
		char log[1024];
		sprintf(log,"FlushToDisk() bool=0x%X ",
			bool		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->FlushToDisk(bool);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
