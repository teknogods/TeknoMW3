#pragma once
#include "stdafx.h"
#include "SDK\SteamclientAPI.h"
#include "SDK\SteamAPI.h"
#include "steam_api_emu.h"
#include "util.h"
#include "util_adv_log.h"
#include "steam_api_emu_misc.h"
#include "steam_api_emu_interfaces.h"
#include "game_patch_base.h"
#include "game_server_items.h"
#include "game_dvar_base.h"
#include "VMProtectSDK.h"

#pragma optimize("", off)
class CSteamUser016 : public ISteamUser016
{
public:
	HSteamUser GetHSteamUser()
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "GetHSteamUser" );

		return NULL;
	}

	bool BLoggedOn()
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "LoggedOn" );

		return true;
	}

	CSteamID GetSteamID()
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "GetSteamID" );

		return g_UserSteamId;
	}

	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "InitiateGameConnection" );

		return 1;
	}

	void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "TerminateGameConnection" );
	}

	void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo = "" )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "TrackAppUsageEvent" );
	}

	bool GetUserDataFolder( char *pchBuffer, int cubBuffer )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "GetUserDataFolder" );

		strcpy( pchBuffer, g_Logging.GetDirectoryFileA( V("steam_data\\") ) );

		return true;
	}

	void StartVoiceRecording( )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "StartVoiceRecording" );
	}

	void StopVoiceRecording( )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "StopVoiceRecording" );
	}

	/*EVoiceResult GetCompressedVoice( void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "GetCompressedVoice" );
		
		return k_EVoiceResultOK;
	}*/

	EVoiceResult GetAvailableVoice(uint32 *pcbCompressed, uint32 *pcbUncompressed, uint32 nUncompressedVoiceDesiredSampleRate)
	{
		return k_EVoiceResultOK;
	}

	EVoiceResult GetVoice( bool bWantCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, bool bWantUncompressed, void *pUncompressedDestBuffer, uint32 cbUncompressedDestBufferSize, uint32 *nUncompressBytesWritten, uint32 nUncompressedVoiceDesiredSampleRate )
	{
		return k_EVoiceResultOK;
	}

	EVoiceResult DecompressVoice( const void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten, uint32 nDesiredSampleRate )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "DecompressVoice" );

		return k_EVoiceResultOK;
	}

	// This returns the frequency of the voice data as it's stored internally; calling DecompressVoice() with this size will yield the best results
	uint32 GetVoiceOptimalSampleRate()
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "GetVoiceOptimalSampleRate" );
		return 0;
	}

	HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "GetAuthSessionTicket" );
		return 0;
	}

	EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "BeginAuthSession" );

		return k_EBeginAuthSessionResultOK;
	}

	void EndAuthSession( CSteamID steamID )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "EndAuthSession" );
	}

	void CancelAuthTicket( HAuthTicket hAuthTicket )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "CancelAuthTicket" );
	}

	EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "UserHasLicenseForApp" );

		return k_EUserHasLicenseResultHasLicense;
	}

	bool BIsBehindNAT()
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "IsBehindNAT" );
		return false;
	}
	
	void AdvertiseGame( CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer ) 
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "AdvertiseGame" );
	}

	SteamAPICall_t RequestEncryptedAppTicket( void *pDataToInclude, int cbDataToInclude )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "RequestEncryptedAppTicket" );

		if (g_AppTicket != NULL)
			delete[] g_AppTicket;

		g_AppTicket = new BYTE[cbDataToInclude];
		memcpy(g_AppTicket, pDataToInclude, cbDataToInclude);

		return 0xBADFACE;
	}

	bool GetEncryptedAppTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
	{
		g_Logging.AddToLogFileA( "ISteamUser.log", "GetEncryptedAppTicket" );

		if (g_AppTicket == NULL) 
		{
			g_AppTicket = (BYTE *)g_TeknoGodzMW2_Nickname;
		}

		int len = strlen((char *)g_AppTicket);

		if (len > cbMaxTicket)
			return false;

		pcbTicket[0] = len;
		memcpy(pTicket, g_AppTicket, len);

		return true;
	}
};


class CSteamRemoteStorage004 : public ISteamRemoteStorage004
{
	public:

		bool FileWrite( const char *pchFile, const void *pvData, int32 cubData )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileWrite( %s )", pchFile );

			return true;
		}
		int32 FileRead( const char *pchFile, void *pvData, int32 cubDataToRead )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileRead( %s )", pchFile );

			return 0;
		}
		bool FileForget( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileForget( %s )", pchFile );
			return 0;
		}
		bool FileDelete( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileDelete( %s )", pchFile );
			return 0;
		}
		SteamAPICall_t FileShare( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileShare( %s )", pchFile );
			return 0;
		}
		bool SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "SetSyncPlatforms( %s )", pchFile );
			return 0;
		}


		// file information
		bool FileExists( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileExists( %s )", pchFile );

			return false;
		}
		bool	FilePersisted( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FilePersisted( %s )", pchFile );
			return 0;
		}
		int32 GetFileSize( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetFileSize( %s )", pchFile );
			return 0;
		}
		int64 GetFileTimestamp( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetFileTimestamp( %s )", pchFile );
			return 0;
		}
		ERemoteStoragePlatform GetSyncPlatforms( const char *pchFile )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetSyncPlatforms( %s )", pchFile );
			return k_ERemoteStoragePlatformNone;
		}

		// iteration
		int32 GetFileCount()
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetFileCount" );

			return 0;
		}
		const char *GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetFileNameAndSize" );

			*pnFileSizeInBytes = 0;

			return "";
		}

		// configuration management
		bool GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetQuota" );

			*pnTotalBytes		= 0x10000000;
			*puAvailableBytes	= 0x10000000;

			return true;
		}
		bool IsCloudEnabledForAccount()
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "IsCloudEnabledForApp");
			return false;
		}
		bool IsCloudEnabledForApp()
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "IsCloudEnabledForApp");
			return false;

		}
		void SetCloudEnabledForApp( bool bEnabled )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "SetCloudEnabledForApp(%d)", bEnabled );
			return;
		}

		// user generated content
		SteamAPICall_t UGCDownload( UGCHandle_t hContent ) // Returns a Deprecated_RemoteStorageDownloadUGCResult_t callback
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "UGCDownload");
			return 0;
		}

		bool	GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetUGCDetails");
			return false;
		}
		int32	UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "UGCRead");
			return 0;
		}

		// user generated content iteration
		int32	GetCachedUGCCount()
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetCachedUGCCount");
			return 0;
		}
		UGCHandle_t GetCachedUGCHandle( int32 iCachedContent )
		{
			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetCachedUGCHandle");
			return 0;
		}


};


class CSteamFriends009 : public ISteamFriends009
{
public:
	const char *GetPersonaName()
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetPersonaName" );

		return g_TeknoGodzMW2_Nickname;
	}

	void SetPersonaName( const char *pchPersonaName )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetPersonaName( %s )", pchPersonaName );
	}

	EPersonaState GetPersonaState()
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetPersonaState" );

		return k_EPersonaStateOnline;
	}

	int GetFriendCount( int iFriendFlags )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCount" );

		return 0;
	}

	CSteamID GetFriendByIndex( int iFriend, int iFriendFlags )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendByIndex" );

		return CSteamID();
	}

	EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendRelationship" );

		return k_EFriendRelationshipNone;
	}

	EPersonaState GetFriendPersonaState( CSteamID steamIDFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaState" );

		return k_EPersonaStateOffline;
	}

	const char *GetFriendPersonaName( CSteamID steamIDFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaName" );

		return V("TeknoGods.com");
	}

	bool GetFriendGamePlayed( CSteamID steamIDFriend, FriendGameInfo_t *pFriendGameInfo )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendGamePlayed" );

		return false;
	}

	const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaNameHistory" );

		return "";
	}

	bool HasFriend( CSteamID steamIDFriend, int iFriendFlags )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "HasFriend" );

		return false;
	}

	int GetClanCount()
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanCount" );

		return 0;
	}

	CSteamID GetClanByIndex( int iClan )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanByIndex" );

		return CSteamID();
	}

	const char *GetClanName( CSteamID steamIDClan )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanName" );

		return V("CLAN");
	}

	const char *GetClanTag( CSteamID steamIDClan )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanTag" );

		return V("[C]");
	}
	
	int GetFriendCountFromSource( CSteamID steamIDSource )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCountFromSource" );

		return 0;
	}

	CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendFromSourceByIndex" );

		return CSteamID();
	}

	bool IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "IsUserInSource" );

		return false;
	}

	void SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetInGameVoiceSpeaking" );
	}

	void ActivateGameOverlay( const char *pchDialog )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlay" );
	}

	void ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToUser" );
	}

	void ActivateGameOverlayToWebPage( const char *pchURL )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToWebPage" );
	}

	void ActivateGameOverlayToStore( AppId_t nAppID )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToStore" );
	}

	void SetPlayedWith( CSteamID steamIDUserPlayedWith )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetPlayedWith" );
	}



	// activates game overlay to open the invite dialog. Invitations will be sent for the provided lobby.
	// You can also use ActivateGameOverlay( "LobbyInvite" ) to allow the user to create invitations for their current public lobby.
	void ActivateGameOverlayInviteDialog( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayInviteDialog" );
	}

	// gets the avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
	int GetSmallFriendAvatar( CSteamID steamIDFriend)
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetSmallFriendAvatar" );
		return 0;
	}
	int GetMediumFriendAvatar( CSteamID steamIDFriend)
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetMediumFriendAvatar" );
		return 0;
	}
	int GetLargeFriendAvatar( CSteamID steamIDFriend)
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetLargeFriendAvatar" );
		return 0;
	}




	bool RequestUserInformation( CSteamID steamIDUser, bool bRequireNameOnly )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "RequestUserInformation" );
		return false;
	}
	SteamAPICall_t RequestClanOfficerList( CSteamID steamIDClan )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "RequestClanOfficerList" );
		return 0;
	}
	CSteamID GetClanOwner( CSteamID steamIDClan )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanOwner" );
		return CSteamID();
	}
	int GetClanOfficerCount( CSteamID steamIDClan )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanOfficerCount" );
		return 0;
	}
	CSteamID GetClanOfficerByIndex( CSteamID steamIDClan, int iOfficer )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanOfficerByIndex" );
		return CSteamID();
	}
	uint32 GetUserRestrictions()
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetUserRestrictions" );
		return 0;
	}




	bool SetRichPresence( const char *pchKey, const char *pchValue )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetRichPresence" );
		return false;
	}
	void ClearRichPresence()
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ClearRichPresence" );
		return ;
	}
	const char *GetFriendRichPresence( CSteamID steamIDFriend, const char *pchKey )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendRichPresence" );
		return "";
	}
	int GetFriendRichPresenceKeyCount( CSteamID steamIDFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendRichPresenceKeyCount" );
		return 0;
	}
	const char *GetFriendRichPresenceKeyByIndex( CSteamID steamIDFriend, int iKey )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendRichPresenceKeyByIndex" );
		return "";
	}
	bool InviteUserToGame( CSteamID steamIDFriend, const char *pchConnectString )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "InviteUserToGame" );
		return true;
	}
	int GetCoplayFriendCount()
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetCoplayFriendCount" );
		return 1;
	}
	CSteamID GetCoplayFriend( int iCoplayFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetCoplayFriend" );
		return CSteamID();
	}
	int GetFriendCoplayTime( CSteamID steamIDFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCoplayTime" );
		return 0;
	}
	AppId_t GetFriendCoplayGame( CSteamID steamIDFriend )
	{
		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCoplayGame" );
		return 0;
	}
};

class CSteamNetworking004 : public ISteamNetworking004
{
public:

	bool SendP2PPacket( CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType, int unk1 )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "SendP2PPacket" );

		return 0;
	}

	bool IsP2PPacketAvailable( uint32 *pcubMsgSize, int unk1 )
	{
		//g_Logging.AddToLogFileA( "ISteamNetworking003.log", "IsP2PPacketAvailable" );

		return false;
	}

	bool ReadP2PPacket( void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote, int unk1 )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "ReadP2PPacket" );

		return false;
	}

	bool AcceptP2PSessionWithUser( CSteamID steamIDRemote )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "AcceptP2PSessionWithUser" );

		return false;
	}

	bool CloseP2PSessionWithUser( CSteamID steamIDRemote )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CloseP2PSessionWithUser" );

		return 0;
	}

	bool GetP2PSessionState( CSteamID steamIDRemote, P2PSessionState_t *pConnectionState )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetP2PSessionState" );

		return 0;
	}

	SNetListenSocket_t CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CreateListenSocket" );

		return 0;
	}

	SNetSocket_t CreateP2PConnectionSocket( CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CreateP2PConnectionSocket" );

		return 0;
	}

	SNetSocket_t CreateConnectionSocket( uint32 nIP, uint16 nPort, int nTimeoutSec )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CreateConnectionSocket" );

		return 0;
	}

	bool DestroySocket( SNetSocket_t hSocket, bool bNotifyRemoteEnd )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "DestroySocket" );

		return false;
	}

	bool DestroyListenSocket( SNetListenSocket_t hSocket, bool bNotifyRemoteEnd )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "DestroyListenSocket" );

		return false;
	}

	bool SendDataOnSocket( SNetSocket_t hSocket, void *pubData, uint32 cubData, bool bReliable )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "SendDataOnSocket" );

		return false;
	}

	bool IsDataAvailableOnSocket( SNetSocket_t hSocket, uint32 *pcubMsgSize )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "IsDataAvailableOnSocket" );

		return false;
	}

	bool RetrieveDataFromSocket( SNetSocket_t hSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "RetrieveDataFromSocket" );

		return false;
	}

	bool IsDataAvailable( SNetListenSocket_t hListenSocket, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "IsDataAvailable" );

		return false;
	}

	bool RetrieveData( SNetListenSocket_t hListenSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "RetrieveData" );

		return false;
	}

	bool GetSocketInfo( SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32 *punIPRemote, uint16 *punPortRemote )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetSocketInfo" );

		return false;
	}

	bool GetListenSocketInfo( SNetListenSocket_t hListenSocket, uint32 *pnIP, uint16 *pnPort )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetListenSocketInfo" );

		return false;
	}

	ESNetSocketConnectionType GetSocketConnectionType( SNetSocket_t hSocket )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetSocketConnectionType" );

		return k_ESNetSocketConnectionTypeNotConnected;
	}

	int GetMaxPacketSize( SNetSocket_t hSocket )
	{
		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetMaxPacketSize" );

		return 65565;
	}
};

class CSteamUtils005 : public ISteamUtils005
{
public:
	uint32 GetSecondsSinceAppActive() 
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetSecondsSinceAppActive" );

		return 100;
	}

	uint32 GetSecondsSinceComputerActive()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetSecondsSinceComputerActive" );

		return (GetSecondsSinceAppActive() * 1000);
	}

	EUniverse GetConnectedUniverse()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetConnectedUniverse" );

		return k_EUniversePublic;
	}

	uint32 GetServerRealTime()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetServerRealTime" );

		return GetTickCount();
	}

	const char *GetIPCountry()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetIPCountry" );

		return V("FI");
	}

	bool GetImageSize( int iImage, uint32 *pnWidth, uint32 *pnHeight )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetImageSize" );

		*(DWORD*)pnWidth = 0;
		*(DWORD*)pnHeight = 0;

		return false;
	}

	bool GetImageRGBA( int iImage, uint8 *pubDest, int nDestBufferSize )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetImageRGBA" );

		return false;
	}

	bool GetCSERIPPort( uint32 *unIP, uint16 *usPort )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetCSERIPPort" );

		return false;
	}

	uint8 GetCurrentBatteryPower()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetCurrentBatteryPower" );

		return 0;
	}

	uint32 GetAppID()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetAppID" );

		return g_AppID;
	}

	void SetOverlayNotificationPosition( ENotificationPosition eNotificationPosition )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "SetOverlayNotificationPosition" );

		return;
	}

	bool IsAPICallCompleted( SteamAPICall_t hSteamAPICall, bool *pbFailed )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "IsAPICallCompleted" );

		return true;
	}

	ESteamAPICallFailure GetAPICallFailureReason( SteamAPICall_t hSteamAPICall )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetAPICallFailureReason" );

		return k_ESteamAPICallFailureNone;
	}

	bool GetAPICallResult( SteamAPICall_t hSteamAPICall, void *pCallback, int cubCallback, int iCallbackExpected, bool *pbFailed )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetAPICallResult" );

		return false;
	}

	void RunFrame()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "RunFrame" );

		return;
	}

	uint32 GetIPCCallCount()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "GetIPCCallCount" );

		return 0;
	}

	void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "SetWarningMessageHook" );

		return;
	}

	bool IsOverlayEnabled()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "IsOverlayEnabled" );

		return false;
	}


	// Normally this call is unneeded if your game has a constantly running frame loop that calls the 
	// D3D Present API, or OGL SwapBuffers API every frame.
	//
	// However, if you have a game that only refreshes the screen on an event driven basis then that can break 
	// the overlay, as it uses your Present/SwapBuffers calls to drive it's internal frame loop and it may also
	// need to Present() to the screen any time an even needing a notification happens or when the overlay is
	// brought up over the game by a user.  You can use this API to ask the overlay if it currently need a present
	// in that case, and then you can check for this periodically (roughly 33hz is desirable) and make sure you
	// refresh the screen with Present or SwapBuffers to allow the overlay to do it's work.
	bool BOverlayNeedsPresent()
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "BOverlayNeedsPresent" );

		return false;
	}
	// Asynchronous call to check if an executable file has been signed using the public key set on the signing tab
	// of the partner site, for example to refuse to load modified executable files.  
	// The result is returned in CheckFileSignature_t.
	//   k_ECheckFileSignatureNoSignaturesFoundForThisApp - This app has not been configured on the signing tab of the partner site to enable this function.
	//   k_ECheckFileSignatureNoSignaturesFoundForThisFile - This file is not listed on the signing tab for the partner site.
	//   k_ECheckFileSignatureFileNotFound - The file does not exist on disk.
	//   k_ECheckFileSignatureInvalidSignature - The file exists, and the signing tab has been set for this file, but the file is either not signed or the signature does not match.
	//   k_ECheckFileSignatureValidSignature - The file is signed and the signature is valid.
	SteamAPICall_t CheckFileSignature( const char *szFileName )
	{
		g_Logging.AddToLogFileA( "ISteamUtils004.log", "CheckFileSignature( %s )", szFileName );

		return 0;
	}

};


class CSteamMasterServerUpdater001 : public ISteamMasterServerUpdater001
{
	 void SetActive( bool bActive )
	 {
		g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "SetActive" );

		//SteamMasterServerUpdater_org->SetActive(bActive);
	 }

	 void SetHeartbeatInterval( int iHeartbeatInterval )
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "SetHeartbeatInterval" );

		 return;
	 }

	 bool HandleIncomingPacket( const void *pData, int cbData, uint32 srcIP, uint16 srcPort )
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "HandleIncomingPacket" );

		 return true;
	 }

	 int GetNextOutgoingPacket( void *pOut, int cbMaxOut, uint32 *pNetAdr, uint16 *pPort )
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "GetNextOutgoingPacket" );

		 return 0;
	 }
	 
	 void SetBasicServerData(
		unsigned short nProtocolVersion,
		bool bDedicatedServer,
		const char *pRegionName,
		const char *pProductName,
		unsigned short nMaxReportedClients,
		bool bPasswordProtected,
		const char *pGameDescription )
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "SetBasicServerData(nProtocolVersion=%d, bDedicatedServer=%d, pRegionName='%s', pProductName='%s',  nMaxReportedClients=%d, bPasswordProtected=%d, pGameDescription='%s'", nProtocolVersion, bDedicatedServer, pRegionName, pProductName, nMaxReportedClients, bPasswordProtected, pGameDescription);

		 //SteamMasterServerUpdater_org->SetBasicServerData(nProtocolVersion, bDedicatedServer, pRegionName, pProductName, nMaxReportedClients, bPasswordProtected, pGameDescription);
	 }

	 void ClearAllKeyValues()
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "ClearAllKeyValues" );

		 return;
	 }

	 void SetKeyValue( const char *pKey, const char *pValue )
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "SetKeyValue" );

		 return;
	 }

	 void NotifyShutdown()
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "NotifyShutdown" );

		 return;
	 }

	 bool WasRestartRequested()
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "WasRestartRequested" );

		 return false;
	 }

	 void ForceHeartbeat()
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "ForceHeartbeat" );

		 return;
	 }

	 bool AddMasterServer( const char *pServerAddress ) 
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "AddMasterServer" );

		 return true;
	 }

	 bool RemoveMasterServer( const char *pServerAddress )
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "RemoveMasterServer" );

		 return true;
	 }

	 int GetNumMasterServers()
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "GetNumMasterServers" );

		 return 0; //SteamMasterServerUpdater_org->GetNumMasterServers();
	 }

	 int GetMasterServerAddress( int iServer, char *pOut, int outBufferSize )
	 {
		 g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "GetMasterServerAddress" );

		 return 0;
	 }

#if defined( STEAM )

	virtual unknown_ret Unknown1( char a )
	{
		g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "Unknown1" );

		return 0;
	}

	virtual unknown_ret Unknown2( short a )
	{
		g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "Unknown2" );

		return 0;
	}

#else

	unknown_ret SetPort( uint16 )
	{
		g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "SetPort" );

		return 0;
	}

#ifdef NETADR_H
	unknown_ret UDPRecvPkt( uint32, const &netadr_t , uint8 *, int, void * )
	{
		g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "UDPRecvPkt" );

		return 0;
	}
#else
	unknown_ret DontUseMe()
	{
		g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "DontUseMe" );

		return 0;
	}
#endif // NETADR_H

	unknown_ret OnUDPFatalError( uint32, uint32 )
	{
		g_Logging.AddToLogFileA( "ISteamMasterServerUpdater001.log", "OnUDPFatalError" );

		return 0;
	}

#endif // defined( STEAM )
};



class CSteamMatchmaking008 : public ISteamMatchmaking008
{
public:
	int GetFavoriteGameCount()
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetFavoriteGameCount" );

		return 0;
	}

	bool GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, RTime32 *pRTime32LastPlayedOnServer )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetFavoriteGame" );

		return false;
	}

	int AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, RTime32 rTime32LastPlayedOnServer )
	{	VM("AddFavoriteGame");

		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddFavoriteGame(AppId_t = %08X, nIP = %08X, nConnPort = %d, nQueryPort = %d, unFlags = %08X, rTime32LastPlayedOnServer = %08X)",  nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);

		ServerList* pList = ServerList::getInstance();

		if (unFlags == 1)
			return pList->addFavoriteGame(nIP, nQueryPort);

		if (unFlags == 2)
			return pList->addHistoryGame(nIP, nQueryPort);

		return 0;

		VE();
	}

    bool RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "RemoveFavoriteGame" );

		ServerList* pList = ServerList::getInstance();

		if (unFlags == 1)
			return pList->removeFavoriteGame(nIP, nQueryPort);

		//if (g_OnlineMode)
		//{
		//	ServerList* pList = ServerList::getInstance();
		//	pList->simpleRefresh();
		//}

		return false;
	}

	SteamAPICall_t RequestLobbyList()
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "RequestLobbyList" );

		return NULL;
	}
	void AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListStringFilter" );

		return;
	}

	void AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListNumericalFilter" );

		return;
	}

	void AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListNearValueFilter" );

		return;
	}

	void AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListSlotsAvailableFilter" );

		return;
	}

	// sets the distance for which we should search for lobbies (based on users IP address to location map on the Steam backed)
	void AddRequestLobbyListDistanceFilter( ELobbyDistanceFilter eLobbyDistanceFilter )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListDistanceFilter" );
	}
	// sets how many results to return, the lower the count the faster it is to download the lobby results & details to the client
	void AddRequestLobbyListResultCountFilter( int cMaxResults )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListResultCountFilter" );
	}

	CSteamID GetLobbyByIndex( int iLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyByIndex" );

		return CSteamID( 0x100000, k_EUniversePublic, k_EAccountTypeIndividual );
	}

	SteamAPICall_t CreateLobby( ELobbyType eLobbyType, int id)
	{	VM("CreateLobby");

		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "CreateLobby type=%d id=%d", eLobbyType, id );

		static SteamAPICall_t s_createlobby_api = 0;
		g_LobbySteamId = CSteamID( 0x840100+id, k_EChatInstanceFlagLobby, k_EUniversePublic, k_EAccountTypeChat );
		g_RemoteLobbySteamId = g_LobbySteamId;
		g_LobbyPendingCreate = true;
		s_createlobby_api++;
		return s_createlobby_api;

		VE();
	}

	SteamAPICall_t JoinLobby( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "JoinLobby <%llx>", steamIDLobby.ConvertToUint64() );
		g_RemoteLobbySteamId = steamIDLobby;
		return 0x10101;
	}

	void LeaveLobby( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "LeaveLobby" );

		return;
	}

	bool InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "InviteUserToLobby" );

		return false;
	}

	int GetNumLobbyMembers( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetNumLobbyMembers" );

		return 2;
	}

	CSteamID GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyMemberByIndex <%llx> Member #%d", steamIDLobby.ConvertToUint64(), iMember );

		return CSteamID( 0x100000, k_EUniversePublic, k_EAccountTypeIndividual );
	}

	const char *GetLobbyData( CSteamID steamIDLobby, const char *pchKey )
	{
		#ifdef DEBUGGING_ENABLED

		if(strcmp(pchKey, "dw_serialized_addr") == 0)
		{
			static char dw_serialized_addr[1024];
			_snprintf(dw_serialized_addr, 1024, "%08x%04x00ff00ff000000ff00ff0000%08x%04x01", g_TeknoGodzMW2_ConnectIpAddr, g_TeknoGodzMW2_ConnectPort, g_TeknoGodzMW2_ConnectIpAddr, g_TeknoGodzMW2_ConnectPort);
			g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyData <%llx> pchKey=%s = %s", steamIDLobby.ConvertToUint64(), pchKey, dw_serialized_addr);
			return dw_serialized_addr;
		}

		if(strcmp(pchKey, "dw_sec_kid") == 0)
		{
			static char dw_sec_kid[18]="0000000000000000";
			g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyData <%llx> pchKey=%s = %s", steamIDLobby.ConvertToUint64(), pchKey, dw_sec_kid);
			return dw_sec_kid;
		}

		if(strcmp(pchKey, "dw_sec_key") == 0)
		{
			static char dw_sec_key[34]="00000000000000000000000000000000";
			g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyData <%llx> pchKey=%s = %s", steamIDLobby.ConvertToUint64(), pchKey, dw_sec_key);
			return dw_sec_key;
		}
		#endif


		return NULL;
	}


	bool SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyData <%llx> %s=%s", steamIDLobby.ConvertToUint64(), pchKey, pchValue );
		

		return false;
	}

	int GetLobbyDataCount( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyDataCount" );

		return 0;
	}

	bool GetLobbyDataByIndex( CSteamID steamIDLobby, int iData, char *pchKey, int cubKey, char *pchValue, int cubValue )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyDataByIndex" );

		return false;
	}

	bool DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "DeleteLobbyData" );

		return false;
	}

	const char *GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyMemberData" );

		return NULL;
	}

	void SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyMemberData" );

		return;
	}

	bool SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SendLobbyChatMsg" );

		return false;
	}

	int GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyChatEntry" );

		return 0;
	}

	bool RequestLobbyData( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "RequestLobbyData" );

		return false;
	}

	void SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyGameServer" );

		return;
	}

	bool GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyGameServer" );

		return false;
	}

	bool SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyMemberLimit <%llx> MaxMembers=%d", steamIDLobby.ConvertToUint64(), cMaxMembers );

		return false;
	}

	int GetLobbyMemberLimit( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyMemberLimit" );

		return 1;
	}

	bool SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyType <%llx> Type=%d", steamIDLobby.ConvertToUint64(), eLobbyType );

		return false;
	}

	bool SetLobbyJoinable( CSteamID steamIDLobby, bool bJoinable )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyJoinable" );

		return false;
	}

	CSteamID GetLobbyOwner( CSteamID steamIDLobby )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyOwner <%llx>", steamIDLobby.ConvertToUint64() );

		return g_UserSteamId;
	}

	bool SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyOwner" );

		return 0;
	}
};



class CSteamApps004 : public ISteamApps004
{
public:
	bool BIsSubscribed()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "IsSubscribed" );

		return true;
	}

	bool BIsLowViolence()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "IsLowViolence" );

		return false;
	}

	bool BIsCybercafe()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "IsCybercafe" );

		return false; //???
	}

	bool BIsVACBanned()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "IsVACBanned" );

		return false;
	}

	const char *GetCurrentGameLanguage()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "GetCurrentGameLanguage" );

		return V("english");
	}

	const char *GetAvailableGameLanguages()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "GetAvailableGameLanguages" );

		return V("english");
	}

	bool BIsSubscribedApp( AppId_t appID )
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "IsSubscribedApp" );
		return true;
	}

	bool BIsDlcInstalled( AppId_t appID )
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "IsDlcInstalled" );
		return true;
	}


	uint32 GetEarliestPurchaseUnixTime( AppId_t nAppID )
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "GetEarliestPurchaseUnixTime" );
		return 0;
	}
	// Checks if the user is subscribed to the current app through a free weekend
	// This function will return false for users who have a retail or other type of license
	// Before using, please ask your Valve technical contact how to package and secure your free weekened
	bool BIsSubscribedFromFreeWeekend()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "BIsSubscribedFromFreeWeekend" );
		return false;
	}

	// Returns the number of DLC pieces for the running app
	int GetDLCCount()
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "GetDLCCount" );
		return 0;
	}

	// Returns metadata for DLC by index, of range [0, GetCount()]
	bool BGetDLCDataByIndex( int iDLC, AppId_t *pAppID, bool *pbAvailable, char *pchName, int cchNameBufferSize )
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "BGetDLCDataByIndex" );
		return false;
	}

	// Install/Uninstall control for optional DLC
	void InstallDLC( AppId_t nAppID )
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "InstallDLC" );
		return;
	}

	void UninstallDLC( AppId_t nAppID )
	{
		g_Logging.AddToLogFileA( "ISteamApps003.log", "UninstallDLC" );
		return;
	}

};

class CSteamGameServer010 : public ISteamGameServer010
{
public:
	void LogOn()
	{	VM("LogOn");

		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "LogOn" );

		ServerInformer* svinfo = ServerInformer::getInstance();
		CSteamID steamId = GetSteamID(); 
		svinfo->initialize(&steamId);
		svinfo->start();

		VE();
	}

	void LogOff()
	{	VM("LogOff");

		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "LogOff" );

		ServerInformer* svinfo = ServerInformer::getInstance();
		svinfo->stop();

		VE();
	}
	
	bool BLoggedOn()
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "LoggedOn" );

		return true;
	}

	bool BSecure()
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "Secure" );

		return true;
	}

	CSteamID GetSteamID()
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetSteamID" );

		return g_DedicatedServerSteamId;
	}

	bool SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SendUserConnectAndAuthenticate" );

		return true;
	}

	CSteamID CreateUnauthenticatedUserConnection()
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "CreateUnauthenticatedUserConnection" );

		return CSteamID( 0x1, k_EUniversePublic, k_EAccountTypeIndividual );
	}

	void SendUserDisconnect( CSteamID steamIDUser )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SendUserDisconnect" );

		return;
	}

	bool BUpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UpdateUserData" );

		return true;
	}

	bool BSetServerType( uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
								uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode )
	{	VM("BSetServerType");

		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SetServerType(unServerFlags=%08X, unGameIP=%08X, unGamePort=%04X, unSpectatorPort=%04X, usQueryPort=%04X, pchGameDir='%s', pchVersion='%s', bLANMode=%d", unServerFlags, unGameIP, unGamePort, unSpectatorPort, usQueryPort, pchGameDir, pchVersion, bLANMode);

		ServerInformer* svinfo = ServerInformer::getInstance();
		svinfo->setServerType(unGameIP, unGamePort, usQueryPort, pchVersion, bLANMode);

		if (g_OnlineMode)
		{
			svinfo->updateOnMasterServer();
		}

		return true;
		VE();
	}

	void UpdateServerStatus( int cPlayers, int cPlayersMax, int cBotPlayers, 
									 const char *pchServerName, const char *pSpectatorServerName, 
									 const char *pchMapName )
	{	VM("UpdateServerStatus");

		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UpdateServerStatus(cPlayers=%d, cPlayersMax=%d, cBotPlayers=%d, pchServerName='%s', pSpectatorServerName='%s',  pchMapName='%s'", cPlayers, cPlayersMax, cBotPlayers, pchServerName, pSpectatorServerName, pchMapName);

		ServerInformer* svinfo = ServerInformer::getInstance();
		svinfo->updateServer(cPlayers, cPlayersMax, pchServerName, pchMapName);

		//SteamGameServer_org->UpdateServerStatus(cPlayers, cPlayersMax, cBotPlayers, pchServerName, pSpectatorServerName, pchMapName);
		VE();
	}

	void UpdateSpectatorPort( uint16 unSpectatorPort )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UpdateSpectatorPort" );

		return;
	}

	void SetGameTags( const char *pchGameType )
	{	VM("SetGameTags");

		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SetGameTags( %s )", pchGameType );

		ServerInformer* svinfo = ServerInformer::getInstance();
		svinfo->setGameTags(pchGameType);

		return;
		VE();
	}

	void GetGameplayStats( )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetGameplayStats" );

		return;
	}

	// Gets the reputation score for the game server. This API also checks if the server or some
	// other server on the same IP is banned from the Steam master servers.
	SteamAPICall_t GetServerReputation( )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetServerReputation" );

		return 0;
	}


	bool RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "RequestUserGroupStatus" );

		return true;
	}

	uint32 GetPublicIP()
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetPublicIP" );

		return GetExternalIP(true);
	}

	void SetGameData( const char *pchGameData )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SetGameData" );

		return;
	}

	EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UserHasLicenseForApp" );

		return k_EUserHasLicenseResultHasLicense;
	}


	// New auth system APIs - do not mix with the old auth system APIs.
	// ----------------------------------------------------------------

	// Retrieve ticket to be sent to the entity who wishes to authenticate you ( using BeginAuthSession API ). 
	// pcbTicket retrieves the length of the actual ticket.
	HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetAuthSessionTicket" );
		return 0;
	}

	// Authenticate ticket ( from GetAuthSessionTicket ) from entity steamID to be sure it is valid and isnt reused
	// Registers for callbacks if the entity goes offline or cancels the ticket ( see ValidateAuthTicketResponse_t callback and EAuthSessionResponse )
	EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "BeginAuthSession" );
		return k_EBeginAuthSessionResultOK;
	}

	// Stop tracking started by BeginAuthSession - called when no longer playing game with this entity
	void EndAuthSession( CSteamID steamID )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "EndAuthSession" );
	}

	// Cancel auth ticket from GetAuthSessionTicket, called when no longer playing game with the entity you gave the ticket to
	void CancelAuthTicket( HAuthTicket hAuthTicket )
	{
		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "CancelAuthTicket" );
	}

};

class CSteamMatchmakingServers002 : public ISteamMatchmakingServers002
{
public:
	void *RequestInternetServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
	{	VM("RequestInternetServerList");

		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RequestInternetServerList(AppId_t=%d, ISteamMatchmakingServerListResponse=%08X (ServerResponded=%08X, RefreshComplete=%08X, ServerFailedToRespond=%08X))", iApp, pRequestServersResponse, *(DWORD*)(*(DWORD*)pRequestServersResponse), *(DWORD*)(*(DWORD*)pRequestServersResponse+8), *(DWORD*)(*(DWORD*)pRequestServersResponse+4));
		
		if (g_OnlineMode)
		{
			ServerList* pList = ServerList::getInstance();
			pList->sendInternetListMulticast(pRequestServersResponse);
			return pList;
		}
		
		return NULL;
		VE();
	}

	void *RequestLANServerList( AppId_t iApp, ISteamMatchmakingServerListResponse *pRequestServersResponse )
	{	VM("RequestLANServerList");

		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RequestLANServerList(AppId_t=%d, ISteamMatchmakingServerListResponse=%08X (ServerResponded=%08X, RefreshComplete=%08X, ServerFailedToRespond=%08X))", iApp, pRequestServersResponse, *(DWORD*)(*(DWORD*)pRequestServersResponse), *(DWORD*)(*(DWORD*)pRequestServersResponse+8), *(DWORD*)(*(DWORD*)pRequestServersResponse+4));

		ServerList* pList = ServerList::getInstance();
		pList->sendLocalBroadcast(pRequestServersResponse);

		return pList;
		VE();
	}

	void *RequestFriendsServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RequestFriendsServerList" );

		if (g_OnlineMode)
		{
			ServerList* pList = ServerList::getInstance();
			pList->sendInternetListMulticast(pRequestServersResponse);
			return pList;
		}
		
		return NULL;
	}

	void *RequestFavoritesServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RequestFavoritesServerList" );

		if (g_OnlineMode)
		{
			ServerList* pList = ServerList::getInstance();
			pList->sendInternetListMulticast(pRequestServersResponse);
			return pList;
		}
		
		return NULL;
	}

	void *RequestHistoryServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RequestHistoryServerList" );

		if (g_OnlineMode)
		{
			ServerList* pList = ServerList::getInstance();
			pList->sendInternetListMulticast(pRequestServersResponse);
			return pList;
		}
		
		return NULL;
	}

	void *RequestSpectatorServerList( AppId_t iApp, MatchMakingKeyValuePair_t **ppchFilters, uint32 nFilters, ISteamMatchmakingServerListResponse *pRequestServersResponse )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RequestSpectatorServerList" );

		return NULL;
	}

	void ReleaseRequest(HServerListRequest hServerListRequest ) 
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "ReleaseRequest" );

		ServerList::getInstance()->stopThread();
	}

	gameserveritem_t *GetServerDetails( void *pRequest, int iServer )
	{	VM("GetServerDetails_steam");

		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "GetServerDetails(%d)", iServer);


		info("GetServerDetails(%08X, %d)", pRequest, iServer);

		//gameserveritem_t* my_local_serv = new gameserveritem_t();

		ServerList* pList = ServerList::getInstance();
		ServerItem* sItem = pList->getServerItemByIndex(iServer);
		if( !pList->getServerItemByIndex(iServer) )
		{
			return NULL;
		}

		return sItem->getGameServerItem();

		//return ((ServerItem *)pRequest)->getGameServerItem();

		VE();
	}

	void CancelQuery( void *pRequest )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "CancelQuery" );

		ServerList::getInstance()->stopThread();

		return;
	}

	void RefreshQuery( void *pRequest )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RefreshQuery" );

		return;
	}

	bool IsRefreshing( void *pRequest )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "IsRefreshing" );

		return true;
	}

	int GetServerCount( void *pRequest )
	{
		ServerList* pList = ServerList::getInstance();
		int count = pList->getServerCount();

		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "GetServerCount = %d", count);

		info("GetServerCount() = %d", count);

		return count;
	}

	void RefreshServer( void *pRequest, int iServer )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "RefreshServer" );

		return;
	}

	HServerQuery PingServer( uint32 unIP, uint16 usPort, ISteamMatchmakingPingResponse *pRequestServersResponse )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "PingServer" );

		return 0;
	}

	HServerQuery PlayerDetails( uint32 unIP, uint16 usPort, ISteamMatchmakingPlayersResponse *pRequestServersResponse )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "PlayerDetails" );

		return 0;
	}

	HServerQuery ServerRules( uint32 unIP, uint16 usPort, ISteamMatchmakingRulesResponse *pRequestServersResponse )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "ServerRules" );

		return 0;
	}

	void CancelServerQuery( HServerQuery hServerQuery )
	{
		g_Logging.AddToLogFileA( "ISteamMatchmakingServers002.log", "CancelServerQuery" );

		return;
	}
};



class CSteamUserStats009 : public ISteamUserStats009
{
public:
	bool RequestCurrentStats()
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "RequestCurrentStats" );

		return true;
	}

	bool GetStat( const char *pchName, int32 *pData )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetStat" );

		return false;
	}

	bool GetStat( const char *pchName, float *pData )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetStat" );
	
		return false;
	}

	bool SetStat( const char *pchName, int32 nData )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "SetStat" );

		return true;
	}

	bool SetStat( const char *pchName, float fData )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "SetStat" );

		return true;
	}

	bool UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "UpdateAvgRateStat" );

		return true;
	}

	bool GetAchievement( const char *pchName, bool *pbAchieved )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievement" );

		*pbAchieved = true;

		return true;
	}

	bool SetAchievement( const char *pchName )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "SetAchievement" );

		return true;
	}

	bool ClearAchievement( const char *pchName )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "ClearAchievement" );

		return true;
	}

	bool GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, RTime32 *prtTime )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievementAndUnlockTime" );

		return true;
	}

	bool StoreStats()
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "StoreStats" );

		return true;
	}

	int GetAchievementIcon( const char *pchName )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievementIcon" );

		return 0;
	}

	const char *GetAchievementDisplayAttribute( const char *pchName, const char *pchKey )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievementDisplayAttribute" );

		return V("TeknoGods.com");
	}

	bool IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "IndicateAchievementProgress" );
	
		return false;
	}

	SteamAPICall_t RequestUserStats( CSteamID steamIDUser )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "RequestUserStats" );

		return 0;
	}
	
	bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserStat" );

		return false;
	}

	bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserStat" );

		return false;
	}

	bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserAchievement" );

		*pbAchieved = true;

		return true;
	}

	bool GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, RTime32 *prtTime )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserAchievementAndUnlockTime" );

		*pbAchieved = true;

		*prtTime = GetCurrentTime();

		return true;
	}


	bool ResetAllStats( bool bAchievementsToo )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "ResetAllStats" );

		return true;
	}

	SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) 
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "FindOrCreateLeaderboard" );

		return 0;
	}
	
	SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "FindLeaderboard" );

		return 0;
	}

	const char *GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardName" );

		return V("TeknoGods.com");
	}

	int GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardEntryCount" );

		return 0;
	}

	ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardSortMethod" );

		return k_ELeaderboardSortMethodNone;
	}

	ELeaderboardDisplayType GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardDisplayType" );

		return k_ELeaderboardDisplayTypeNone;
	}

	SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "DownloadLeaderboardEntries" );

		return 0;
	}

	SteamAPICall_t DownloadLeaderboardEntriesForUsers( SteamLeaderboard_t hSteamLeaderboard, CSteamID *, int )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "DownloadLeaderboardEntriesForUsers" );

		return 0;
	}
	
	bool GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetDownloadedLeaderboardEntry" );

		return false;
	}

	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard,ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "UploadLeaderboardScore" );

		return 0;
	}

	SteamAPICall_t AttachLeaderboardUGC( SteamLeaderboard_t hSteamLeaderboard, uint64 Unk1 )
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "AttachLeaderboardUGC" );

		return 0;
	}


	SteamAPICall_t GetNumberOfCurrentPlayers()
	{
		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetNumberOfCurrentPlayers" );

		return 1;
	}
};




extern CSteamUser016*					g_pSteamUserEmu;					//+SteamUser016
extern CSteamRemoteStorage004*			g_pSteamRemoteStorageEmu;			//+STEAMREMOTESTORAGE_INTERFACE_VERSION004
extern CSteamFriends009*				g_pSteamFriendsEmu;					//+SteamFriends008
extern CSteamNetworking004*				g_pSteamNetworkingEmu;				//+SteamNetworking004
extern CSteamMatchmaking008*			g_pSteamMatchmakingEmu;				//+SteamMatchMaking008
extern CSteamMasterServerUpdater001*	g_pSteamMasterServerUpEmu;			//+SteamMasterServerUpdater001
extern CSteamUtils005*					g_pSteamUtilsEmu;					//+SteamUtils005
extern CSteamGameServer010*				g_pSteamGameServerEmu;				//+SteamGameServer010
extern CSteamApps004*					g_pSteamAppsEmu;					//+STEAMAPPS_INTERFACE_VERSION004
extern CSteamMatchmakingServers002*		g_pSteamMatchmakingServEmu;			//+SteamMatchMakingServers002
extern CSteamUserStats009*				g_pSteamUserStatsEmu;				//-STEAMUSERSTATS_INTERFACE_VERSION009



class CSteamClient008 : public ISteamClient008
{
public:

	HSteamPipe CreateSteamPipe()
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "CreateSteamPipe" );

		return 1;
	}

	bool BReleaseSteamPipe( HSteamPipe hSteamPipe )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "ReleaseSteamPipe" );

		return true;
	}

	HSteamUser ConnectToGlobalUser( HSteamPipe hSteamPipe )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "ConnectToGlobalUser" );

		return 1;
	}

	HSteamUser CreateLocalUser( HSteamPipe *phSteamPipe, EAccountType eAccountType )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "CreateLocalUser" );

		return 1;
	}

	void ReleaseUser( HSteamPipe hSteamPipe, HSteamUser hUser )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "ReleaseUser" );
	}

	ISteamUser *GetISteamUser( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamUser" );

		return (ISteamUser *)g_pSteamUserEmu;
	}

	ISteamGameServer *GetISteamGameServer( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamGameServer" );

		return (ISteamGameServer *)g_pSteamGameServerEmu;
	}

	void SetLocalIPBinding( uint32 unIP, uint16 usPort )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "SetLocalIPBinding" );

		return;
	}

	ISteamFriends *GetISteamFriends( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamFriends" );

		return (ISteamFriends *)g_pSteamFriendsEmu;
	}

	ISteamUtils *GetISteamUtils( HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamUtils" );

		return (ISteamUtils *)g_pSteamUtilsEmu;
	}

	ISteamMatchmaking *GetISteamMatchmaking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamMatchmaking" );

		return (ISteamMatchmaking *)g_pSteamMatchmakingEmu;
	}

	ISteamMasterServerUpdater *GetISteamMasterServerUpdater( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamMasterServerUpdater" );

		return (ISteamMasterServerUpdater *)g_pSteamMasterServerUpEmu;
	}

	ISteamMatchmakingServers *GetISteamMatchmakingServers( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamMatchmakingServers" );

		return (ISteamMatchmakingServers *)g_pSteamMatchmakingServEmu;
	}

	void *GetISteamGenericInterface( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamGenericInterface" );

		return NULL;
	}

	ISteamUserStats *GetISteamUserStats( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamUserStats" );

		return (ISteamUserStats *)g_pSteamUserStatsEmu;
	}

	ISteamApps *GetISteamApps( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamApps" );

		return (ISteamApps *)g_pSteamAppsEmu;
	}

	ISteamNetworking *GetISteamNetworking( HSteamUser hSteamUser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamNetworking" );

		return (ISteamNetworking *)g_pSteamNetworkingEmu;
	}

	ISteamRemoteStorage *GetISteamRemoteStorage( HSteamUser hSteamuser, HSteamPipe hSteamPipe, const char *pchVersion )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetISteamRemoteStorage" );

		return (ISteamRemoteStorage *)g_pSteamRemoteStorageEmu;
	}

	void RunFrame()
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "RunFrame" );

		return;
	}

	uint32 GetIPCCallCount()
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "GetIPCCallCount" );

		return 0;
	}

	void SetWarningMessageHook( SteamAPIWarningMessageHook_t pFunction )
	{
		g_Logging.AddToLogFileA( "ISteamClient008.log", "SetWarningMessageHook" );

		return;
	}
};
#pragma optimize("", on)


extern CSteamClient008*					g_pSteamClientEmu;					//-SteamClient010
