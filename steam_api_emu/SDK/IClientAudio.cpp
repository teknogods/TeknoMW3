#include "IClientAudio.h"

	virtual void  StartVoiceRecording ()	{
		char log[1024];
		sprintf(log,"StartVoiceRecording() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  StopVoiceRecording ()	{
		char log[1024];
		sprintf(log,"StopVoiceRecording() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  ResetVoiceRecording ()	{
		char log[1024];
		sprintf(log,"ResetVoiceRecording() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual EVoiceResult  GetAvailableVoice (uint32 *pcbCompressed,  uint32 *pcbUncompressed,  uint32 nUncompressedVoiceDesiredSampleRate)	{
		char log[1024];
		sprintf(log,"GetAvailableVoice() pcbCompressed=0x%X pcbUncompressed=0x%X nUncompressedVoiceDesiredSampleRate=0x%X ",
			pcbCompressed,
			pcbUncompressed,
			nUncompressedVoiceDesiredSampleRate		);
		OutputDebugStringA(log);
		EVoiceResult  ret = m_pWrapper->GetAvailableVoice(pcbCompressed, pcbUncompressed, nUncompressedVoiceDesiredSampleRate);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EVoiceResult  GetVoice ( bool bWantCompressed,  void *pDestBuffer,  uint32 cbDestBufferSize,  uint32 *nBytesWritten,  bool bWantUncompressed,  void *pUncompressedDestBuffer,  uint32 cbUncompressedDestBufferSize,  uint32 *nUncompressBytesWritten,  uint32 nUncompressedVoiceDesiredSampleRate )	{
		char log[1024];
		sprintf(log,"GetVoice() bWantCompressed=0x%X pDestBuffer=0x%X cbDestBufferSize=0x%X nBytesWritten=0x%X bWantUncompressed=0x%X pUncompressedDestBuffer=0x%X cbUncompressedDestBufferSize=0x%X nUncompressBytesWritten=0x%X nUncompressedVoiceDesiredSampleRate=0x%X ",
			bWantCompressed,
			pDestBuffer,
			cbDestBufferSize,
			nBytesWritten,
			bWantUncompressed,
			pUncompressedDestBuffer,
			cbUncompressedDestBufferSize,
			nUncompressBytesWritten,
			nUncompressedVoiceDesiredSampleRate		);
		OutputDebugStringA(log);
		EVoiceResult  ret = m_pWrapper->GetVoice(bWantCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, bWantUncompressed, pUncompressedDestBuffer, cbUncompressedDestBufferSize, nUncompressBytesWritten, nUncompressedVoiceDesiredSampleRate);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EVoiceResult  GetCompressedVoice ( void *pDestBuffer,  uint32 cbDestBufferSize,  uint32 *nBytesWritten )	{
		char log[1024];
		sprintf(log,"GetCompressedVoice() pDestBuffer=0x%X cbDestBufferSize=0x%X nBytesWritten=0x%X ",
			pDestBuffer,
			cbDestBufferSize,
			nBytesWritten		);
		OutputDebugStringA(log);
		EVoiceResult  ret = m_pWrapper->GetCompressedVoice(pDestBuffer, cbDestBufferSize, nBytesWritten);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EVoiceResult  DecompressVoice ( const void *pCompressed,  uint32 cbCompressed,  void *pDestBuffer,  uint32 cbDestBufferSize,  uint32 *nBytesWritten,  uint32 nDesiredSampleRate )	{
		char log[1024];
		sprintf(log,"DecompressVoice() pCompressed=0x%X cbCompressed=0x%X pDestBuffer=0x%X cbDestBufferSize=0x%X nBytesWritten=0x%X nDesiredSampleRate=0x%X ",
			pCompressed,
			cbCompressed,
			pDestBuffer,
			cbDestBufferSize,
			nBytesWritten,
			nDesiredSampleRate		);
		OutputDebugStringA(log);
		EVoiceResult  ret = m_pWrapper->DecompressVoice(pCompressed, cbCompressed, pDestBuffer, cbDestBufferSize, nBytesWritten, nDesiredSampleRate);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetVoiceOptimalSampleRate ()	{
		char log[1024];
		sprintf(log,"GetVoiceOptimalSampleRate() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetVoiceOptimalSampleRate();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  PlayAudio ( HAudio hAudio )	{
		char log[1024];
		sprintf(log,"PlayAudio() hAudio=0x%X ",
			hAudio		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->PlayAudio(hAudio);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  StopAudio ()	{
		char log[1024];
		sprintf(log,"StopAudio() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  PauseAudio ()	{
		char log[1024];
		sprintf(log,"PauseAudio() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  UnPauseAudio ()	{
		char log[1024];
		sprintf(log,"UnPauseAudio() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  SetPlayOrder ( IClientAudio::EPlayMode ePlayMode )	{
		char log[1024];
		sprintf(log,"SetPlayOrder() ePlayMode=0x%X ",
			ePlayMode		);
		OutputDebugStringA(log);
		ePlayMode);
		OutputDebugStringA("\n");
	}
	virtual void  ShufflePlayList ()	{
		char log[1024];
		sprintf(log,"ShufflePlayList() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual IClientAudio::EPlayMode  GetPlayMode ()	{
		char log[1024];
		sprintf(log,"GetPlayMode() "		);
		OutputDebugStringA(log);
		IClientAudio::EPlayMode  ret = m_pWrapper->GetPlayMode();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HAudio  GetAudioHandle ( const char *cszFilePath )	{
		char log[1024];
		sprintf(log,"GetAudioHandle() cszFilePath=%s ",
			cszFilePath		);
		OutputDebugStringA(log);
		HAudio  ret = m_pWrapper->GetAudioHandle(cszFilePath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAudioDetails ( HAudio hAudio,  char *,  int32,  char *,  int32,  char *,  int32 )	{
		char log[1024];
		sprintf(log,"GetAudioDetails() hAudio=0x%X =%s int32=0x%X =%s int32=0x%X =%s int32=0x%X ",
			hAudio,
			,
			int32,
			,
			int32,
			,
			int32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAudioDetails(hAudio, , int32, , int32, , int32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAudioArtSize ( HAudio hAudio,  uint32 *punWidth,  uint32 *punHeight )	{
		char log[1024];
		sprintf(log,"GetAudioArtSize() hAudio=0x%X punWidth=0x%X punHeight=0x%X ",
			hAudio,
			punWidth,
			punHeight		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAudioArtSize(hAudio, punWidth, punHeight);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetAudioArtImage ( HAudio hAudio,  uint8 *pubBuffer,  int32 cubBuffer )	{
		char log[1024];
		sprintf(log,"GetAudioArtImage() hAudio=0x%X pubBuffer=0x%X cubBuffer=0x%X ",
			hAudio,
			pubBuffer,
			cubBuffer		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetAudioArtImage(hAudio, pubBuffer, cubBuffer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetPlayListCount ()	{
		char log[1024];
		sprintf(log,"GetPlayListCount() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetPlayListCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddSongToPlaylist ( HAudio hAudio )	{
		char log[1024];
		sprintf(log,"AddSongToPlaylist() hAudio=0x%X ",
			hAudio		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddSongToPlaylist(hAudio);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveSongFromPlaylist ( HAudio hAudio )	{
		char log[1024];
		sprintf(log,"RemoveSongFromPlaylist() hAudio=0x%X ",
			hAudio		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveSongFromPlaylist(hAudio);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SaveCurrentPlaylistToFile ( const char *cszFilePath )	{
		char log[1024];
		sprintf(log,"SaveCurrentPlaylistToFile() cszFilePath=%s ",
			cszFilePath		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SaveCurrentPlaylistToFile(cszFilePath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  LoadPlaylistFromFile ( const char *cszFilePath )	{
		char log[1024];
		sprintf(log,"LoadPlaylistFromFile() cszFilePath=%s ",
			cszFilePath		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->LoadPlaylistFromFile(cszFilePath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetFileSourceCount ()	{
		char log[1024];
		sprintf(log,"GetFileSourceCount() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetFileSourceCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HFileSource  AddLocalFileSource ( const char *cszFileSource )	{
		char log[1024];
		sprintf(log,"AddLocalFileSource() cszFileSource=%s ",
			cszFileSource		);
		OutputDebugStringA(log);
		HFileSource  ret = m_pWrapper->AddLocalFileSource(cszFileSource);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HFileSource  AddSMBFileSource ( const char *cszFileSource )	{
		char log[1024];
		sprintf(log,"AddSMBFileSource() cszFileSource=%s ",
			cszFileSource		);
		OutputDebugStringA(log);
		HFileSource  ret = m_pWrapper->AddSMBFileSource(cszFileSource);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HFileSource  AddITunesFileSource ( const char *cszFileSource )	{
		char log[1024];
		sprintf(log,"AddITunesFileSource() cszFileSource=%s ",
			cszFileSource		);
		OutputDebugStringA(log);
		HFileSource  ret = m_pWrapper->AddITunesFileSource(cszFileSource);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveFileSource ( HFileSource hFileSource )	{
		char log[1024];
		sprintf(log,"RemoveFileSource() hFileSource=0x%X ",
			hFileSource		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveFileSource(hFileSource);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
