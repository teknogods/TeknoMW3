#include "IClientDepotBuilder.h"

class IClientDepotBuilder_wrapper
{
public:
	virtual uint32  RegisterAppBuild ( AppId_t nAppID,  const char *cszDescription )	{
		char log[1024];
		sprintf(log,"RegisterAppBuild() nAppID=0x%X cszDescription=%s ",
			nAppID,
			cszDescription		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->RegisterAppBuild(nAppID, cszDescription);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetRegisteredBuildID ( uint32 )	{
		char log[1024];
		sprintf(log,"GetRegisteredBuildID() uint32=0x%X ",
			uint32		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetRegisteredBuildID(uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HDEPOTBUILD  InitializeDepotBuildForConfigFile ( const char *pchConfigFile )	{
		char log[1024];
		sprintf(log,"InitializeDepotBuildForConfigFile() pchConfigFile=%s ",
			pchConfigFile		);
		OutputDebugStringA(log);
		HDEPOTBUILD  ret = m_pWrapper->InitializeDepotBuildForConfigFile(pchConfigFile);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  StartBuild ( HDEPOTBUILD hDepotBuild,  uint32 uFlags,  const char *cszBetaKey,  const char *cszChunksPath,  uint32 )	{
		char log[1024];
		sprintf(log,"StartBuild() hDepotBuild=0x%X uFlags=0x%X cszBetaKey=%s cszChunksPath=%s uint32=0x%X ",
			hDepotBuild,
			uFlags,
			cszBetaKey,
			cszChunksPath,
			uint32		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->StartBuild(hDepotBuild, uFlags, cszBetaKey, cszChunksPath, uint32);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetDepotBuildStatus ( HDEPOTBUILD hDepotBuild,  EDepotBuildStatus* pStatusOut,  uint32* pPercentDone )	{
		char log[1024];
		sprintf(log,"BGetDepotBuildStatus() hDepotBuild=0x%X pStatusOut=0x%X pPercentDone=0x%X ",
			hDepotBuild,
			pStatusOut,
			pPercentDone		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetDepotBuildStatus(hDepotBuild, pStatusOut, pPercentDone);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  CloseDepotBuildHandle ( HDEPOTBUILD hDepotBuild )	{
		char log[1024];
		sprintf(log,"CloseDepotBuildHandle() hDepotBuild=0x%X ",
			hDepotBuild		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->CloseDepotBuildHandle(hDepotBuild);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HDEPOTBUILD  ReconstructDepotFromManifestAndChunks ( const char *pchLocalManifestPath,  const char *pchLocalChunkPath,  const char *pchRestorePath )	{
		char log[1024];
		sprintf(log,"ReconstructDepotFromManifestAndChunks() pchLocalManifestPath=%s pchLocalChunkPath=%s pchRestorePath=%s ",
			pchLocalManifestPath,
			pchLocalChunkPath,
			pchRestorePath		);
		OutputDebugStringA(log);
		HDEPOTBUILD  ret = m_pWrapper->ReconstructDepotFromManifestAndChunks(pchLocalManifestPath, pchLocalChunkPath, pchRestorePath);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetChunkCounts ( HDEPOTBUILD hDepotBuild,  uint32 *unTotalChunksInNewBuild,  uint32 *unChunksAlsoInOldBuild )	{
		char log[1024];
		sprintf(log,"BGetChunkCounts() hDepotBuild=0x%X unTotalChunksInNewBuild=0x%X unChunksAlsoInOldBuild=0x%X ",
			hDepotBuild,
			unTotalChunksInNewBuild,
			unChunksAlsoInOldBuild		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetChunkCounts(hDepotBuild, unTotalChunksInNewBuild, unChunksAlsoInOldBuild);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetManifestGIDs ( HDEPOTBUILD hDepotBuild,  uint64 *,  uint64 * )	{
		char log[1024];
		sprintf(log,"GetManifestGIDs() hDepotBuild=0x%X =0x%X =0x%X ",
			hDepotBuild,
			,
					);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetManifestGIDs(hDepotBuild, , );
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  RebaseAndBuildDepot ( uint64,  uint64 )	{
		char log[1024];
		sprintf(log,"RebaseAndBuildDepot() uint64=0x%X uint64=0x%X ",
			uint64,
			uint64		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->RebaseAndBuildDepot(uint64, uint64);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  SetAppBuildLive ( uint32 /*uBuildID ?*/,  uint32 /*nAppID ?*/,  const char *pchBetaKey )	{
		char log[1024];
		sprintf(log,"SetAppBuildLive() /=0x%X /=0x%X pchBetaKey=%s ",
			/,
			/,
			pchBetaKey		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->SetAppBuildLive(/, /, pchBetaKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
