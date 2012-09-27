#pragma once
#include "stdafx.h"
#include "SDK\SteamclientAPI.h"
#include "SDK\SteamAPI.h"
#include "AppTools.h"
#include "util.h"
#include "steam_api_emu.h"
#include "steam_api_emu_misc.h"
#include "steam_api_emu_interfaces.h"
#include "game_patch_base.h"
#include "game_server_items.h"
int none = 0;
//public:
//	HSteamUser GetHSteamUser()
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetHSteamUser" );
//
//		return NULL;
//	}
//
//	bool BLoggedOn()
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "LoggedOn" );
//
//		return true;
//	}
//
//	CSteamID GetSteamID()
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetSteamID" );
//
//		return g_UserSteamId;
//	}
//
//	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "InitiateGameConnection" );
//
//		return 1;
//	}
//
//	void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "TerminateGameConnection" );
//	}
//
//	void TrackAppUsageEvent( CGameID gameID, EAppUsageEvent eAppUsageEvent, const char *pchExtraInfo = "" )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "TrackAppUsageEvent" );
//	}
//
//	bool GetUserDataFolder( char *pchBuffer, int cubBuffer )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetUserDataFolder" );
//
//		strcpy( pchBuffer, g_Logging.GetDirectoryFileA( "steam_data\\" ) );
//
//		return true;
//	}
//
//	void StartVoiceRecording( )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "StartVoiceRecording" );
//	}
//
//	void StopVoiceRecording( )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "StopVoiceRecording" );
//	}
//
//	EVoiceResult GetAvailableVoice( uint32 *, uint32 * )
//	{
//		return k_EVoiceResultOK;
//	}
//
//	EVoiceResult GetVoice( bool, void *pDestBuffer, uint32 cbDestBufferSize, unsigned int *nBytesWritten, bool, void *, uint32, uint32 * )
//	{
//		return k_EVoiceResultOK;
//	}
//
//	EVoiceResult DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "DecompressVoice" );
//
//		return k_EVoiceResultOK;
//	}
//
//	HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetAuthSessionTicket" );
//
//		return 0;
//	}
//
//	EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "BeginAuthSession" );
//
//		return k_EBeginAuthSessionResultOK;
//	}
//
//	void EndAuthSession( CSteamID steamID )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "EndAuthSession" );
//	}
//
//	void CancelAuthTicket( HAuthTicket hAuthTicket )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "CancelAuthTicket" );
//	}
//
//	EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "UserHasLicenseForApp" );
//
//		return k_EUserHasLicenseResultHasLicense;
//	}
//
//	bool BIsBehindNAT()
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "IsBehindNAT" );
//		return false;
//	}
//	
//	bool AdvertiseGame( CSteamID steamIDGameServer, uint32 unIPServer , uint16 usPortServer )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "AdvertiseGame" );
//		return false;
//	}
//
//	SteamAPICall_t RequestEncryptedAppTicket(const void *pUserData, int cbUserData)
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "RequestEncryptedAppTicket" );
//		return 0xBADF00D;
//	}
//
//	bool GetEncryptedAppTicket(void *pTicket, int cbMaxTicket, uint32 *pcbTicket)
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetEncryptedAppTicket" );
//
//		return false;
//	}
//};
//
//class CSteamUser012 : public ISteamUser012
//{
//public:
//	HSteamUser GetHSteamUser()
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetHSteamUser" );
//
//		return NULL;
//	}
//
//	bool LoggedOn()
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "LoggedOn" );
//
//		return true;
//	}
//
//	CSteamID GetSteamID()
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetSteamID" );
//
//		return g_UserSteamId;
//	}
//
//	int InitiateGameConnection( void *pAuthBlob, int cbMaxAuthBlob, CSteamID steamIDGameServer, uint32 unIPServer, uint16 usPortServer, bool bSecure )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "InitiateGameConnection" );
//
//		return 1;
//	}
//
//	void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "TerminateGameConnection" );
//
//		//
//	}
//
//	void TrackAppUsageEvent( CGameID gameID, int eAppUsageEvent, const char *pchExtraInfo )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "TrackAppUsageEvent" );
//
//		//
//	}
//
//	bool GetUserDataFolder( char *pchBuffer, int cubBuffer )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetUserDataFolder" );
//
//		strcpy( pchBuffer, g_Logging.GetDirectoryFileA( "steam_data\\" ) );
//
//		return true;
//	}
//
//	void StartVoiceRecording( )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "StartVoiceRecording" );
//	}
//
//	void StopVoiceRecording( )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "StopVoiceRecording" );
//	}
//
//	EVoiceResult GetCompressedVoice( void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetCompressedVoice" );
//		
//		return k_EVoiceResultOK;
//	}
//
//	EVoiceResult DecompressVoice( void *pCompressed, uint32 cbCompressed, void *pDestBuffer, uint32 cbDestBufferSize, uint32 *nBytesWritten )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "DecompressVoice" );
//
//		return k_EVoiceResultOK;
//	}
//
//	HAuthTicket GetAuthSessionTicket( void *pTicket, int cbMaxTicket, uint32 *pcbTicket )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "GetAuthSessionTicket" );
//
//		return 0;
//	}
//
//	EBeginAuthSessionResult BeginAuthSession( const void *pAuthTicket, int cbAuthTicket, CSteamID steamID )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "BeginAuthSession" );
//
//		return k_EBeginAuthSessionResultOK;
//	}
//
//	void EndAuthSession( CSteamID steamID )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "EndAuthSession" );
//	}
//
//	void CancelAuthTicket( HAuthTicket hAuthTicket )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "CancelAuthTicket" );
//	}
//
//	uint32 UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
//	{
//		g_Logging.AddToLogFileA( "ISteamUser.log", "UserHasLicenseForApp" );
//
//		return 1;
//	}
//};
//
//
//class CSteamRemoteStorage002 : public ISteamRemoteStorage002
//{
//	public:
//		bool FileWrite( const char *pchFile, const void *pvData, int32 cubData )
//		{
//			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileWrite( %s )", pchFile );
//
//			return true;
//		}
//
//		int32 GetFileSize( const char *pchFile )
//		{
//			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetFileSize( %s )", pchFile );
//
//			//get file size of something? nothx
//
//			return 0;
//		}
//
//		int32 FileRead( const char *pchFile, void *pvData, int32 cubDataToRead )
//		{
//			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileRead( %s )", pchFile );
//
//			return 0;
//		}
//
//		bool FileExists( const char *pchFile )
//		{
//			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "FileExists( %s )", pchFile );
//
//			return false;
//		}
//
//		int32 GetFileCount()
//		{
//			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetFileCount" );
//
//			return 0;
//		}
//
//		const char *GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes )
//		{
//			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetFileNameAndSize" );
//
//			*pnFileSizeInBytes = 0;
//
//			return "";
//		}
//
//		bool GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes )
//		{
//			g_Logging.AddToLogFileA( "ISteamRemoteStorage.log", "GetQuota" );
//
//			*pnTotalBytes		= 0x10000000;
//			*puAvailableBytes	= 0x10000000;
//
//			return true;
//		}
//};
//
//
//
//class CSteamFriends008 : public ISteamFriends008
//{
//public:
//	const char *GetPersonaName()
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetPersonaName" );
//
//		return g_TeknoGodzMW2_Nickname;
//	}
//
//	void SetPersonaName( const char *pchPersonaName )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetPersonaName( %s )", pchPersonaName );
//	}
//
//	EPersonaState GetPersonaState()
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetPersonaState" );
//
//		return k_EPersonaStateOnline;
//	}
//
//	int GetFriendCount( EFriendFlags eFriendFlags )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCount" );
//
//		return 0;
//	}
//
//	CSteamID GetFriendByIndex( int iFriend, int iFriendFlags )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendByIndex" );
//
//		return CSteamID();
//	}
//
//	EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendRelationship" );
//
//		return k_EFriendRelationshipNone;
//	}
//
//	EPersonaState GetFriendPersonaState( CSteamID steamIDFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaState" );
//
//		return k_EPersonaStateOffline;
//	}
//
//	const char *GetFriendPersonaName( CSteamID steamIDFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaName" );
//
//		return "TeknoGods.com";
//	}
//
//	bool GetFriendGamePlayed( CSteamID steamIDFriend, FriendGameInfo_t *pFriendGameInfo )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendGamePlayed" );
//
//		return false;
//	}
//
//	const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaNameHistory" );
//
//		return "";
//	}
//
//	bool HasFriend( CSteamID steamIDFriend, EFriendFlags eFriendFlags )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "HasFriend" );
//
//		return false;
//	}
//
//	int GetClanCount()
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanCount" );
//
//		return 0;
//	}
//
//	CSteamID GetClanByIndex( int iClan )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanByIndex" );
//
//		return CSteamID();
//	}
//
//	const char *GetClanName( CSteamID steamIDClan )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanName" );
//
//		return "CLAN";
//	}
//
//	const char *GetClanTag( CSteamID steamIDClan )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanTag" );
//
//		return "[C]";
//	}
//	
//	int GetFriendCountFromSource( CSteamID steamIDSource )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCountFromSource" );
//
//		return 0;
//	}
//
//	CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendFromSourceByIndex" );
//
//		return CSteamID();
//	}
//
//	bool IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "IsUserInSource" );
//
//		return false;
//	}
//
//	void SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetInGameVoiceSpeaking" );
//	}
//
//	void ActivateGameOverlay( const char *pchDialog )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlay" );
//	}
//
//	void ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToUser" );
//	}
//
//	void ActivateGameOverlayToWebPage( const char *pchURL )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToWebPage" );
//	}
//
//	void ActivateGameOverlayToStore( AppId_t nAppID )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToStore" );
//	}
//
//	void SetPlayedWith( CSteamID steamIDUserPlayedWith )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetPlayedWith" );
//	}
//
//
//
//	// activates game overlay to open the invite dialog. Invitations will be sent for the provided lobby.
//	// You can also use ActivateGameOverlay( "LobbyInvite" ) to allow the user to create invitations for their current public lobby.
//	void ActivateGameOverlayInviteDialog( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayInviteDialog" );
//	}
//
//	// gets the avatar of the current user, which is a handle to be used in IClientUtils::GetImageRGBA(), or 0 if none set
//	int GetSmallFriendAvatar( CSteamID steamIDFriend)
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetSmallFriendAvatar" );
//		return 0;
//	}
//	int GetMediumFriendAvatar( CSteamID steamIDFriend)
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetMediumFriendAvatar" );
//		return 0;
//	}
//	int GetLargeFriendAvatar( CSteamID steamIDFriend)
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetLargeFriendAvatar" );
//		return 0;
//	}
//
//	bool RequestUserInformation( CSteamID steamID, bool bUnk1 )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "RequestUserInformation" );
//		return false;
//	}
//
//	SteamAPICall_t RequestClanOfficerList( CSteamID clanId )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "RequestClanOfficerList" );
//		return 0;
//	}
//
//	CSteamID GetClanOwner( CSteamID clanId )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanOwner" );
//		return CSteamID();
//	}
//	int GetClanOfficerCount( CSteamID clanId )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanOfficerCount" );
//		return 0;
//	}
//	CSteamID GetClanOfficerByIndex( CSteamID clanId, int iIndex )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanOfficerByIndex" );
//		return CSteamID();
//	}
//
//	unknown_ret GetUserRestrictions()
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetUserRestrictions" );
//		return 0;
//	}
//};
//
//class CSteamFriends005 : public ISteamFriends005
//{
//public:
//	const char *GetPersonaName()
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetPersonaName" );
//
//		return g_TeknoGodzMW2_Nickname;
//	}
//
//	void SetPersonaName( const char *pchPersonaName )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetPersonaName( %s )", pchPersonaName );
//	}
//
//	EPersonaState GetPersonaState()
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetPersonaState" );
//
//		return k_EPersonaStateOnline;
//	}
//
//	int GetFriendCount( EFriendFlags eFriendFlags )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCount" );
//
//		return 0;
//	}
//
//	CSteamID GetFriendByIndex( int iFriend, int iFriendFlags )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendByIndex" );
//
//		return CSteamID();
//	}
//
//	EFriendRelationship GetFriendRelationship( CSteamID steamIDFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendRelationship" );
//
//		return k_EFriendRelationshipNone;
//	}
//
//	EPersonaState GetFriendPersonaState( CSteamID steamIDFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaState" );
//
//		return k_EPersonaStateOffline;
//	}
//
//	const char *GetFriendPersonaName( CSteamID steamIDFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaName" );
//
//		return "TeknoGods.com";
//	}
//
//	int GetFriendAvatar( CSteamID steamIDFriend, int eAvatarSize )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendAvatar" );
//
//		return 0;
//	}
//
//	bool GetFriendGamePlayed( CSteamID steamIDFriend, FriendGameInfo_t *pFriendGameInfo )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendGamePlayed" );
//
//		return false;
//	}
//
//	const char *GetFriendPersonaNameHistory( CSteamID steamIDFriend, int iPersonaName )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendPersonaNameHistory" );
//
//		return "";
//	}
//
//	bool HasFriend( CSteamID steamIDFriend, EFriendFlags eFriendFlags )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "HasFriend" );
//
//		return false;
//	}
//
//	int GetClanCount()
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanCount" );
//
//		return 0;
//	}
//
//	CSteamID GetClanByIndex( int iClan )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanByIndex" );
//
//		return CSteamID();
//	}
//
//	const char *GetClanName( CSteamID steamIDClan )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetClanName" );
//
//		return "CLAN";
//	}
//
//	int GetFriendCountFromSource( CSteamID steamIDSource )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendCountFromSource" );
//
//		return 0;
//	}
//
//	CSteamID GetFriendFromSourceByIndex( CSteamID steamIDSource, int iFriend )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "GetFriendFromSourceByIndex" );
//
//		return CSteamID();
//	}
//
//	bool IsUserInSource( CSteamID steamIDUser, CSteamID steamIDSource )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "IsUserInSource" );
//
//		return false;
//	}
//
//	void SetInGameVoiceSpeaking( CSteamID steamIDUser, bool bSpeaking )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetInGameVoiceSpeaking" );
//	}
//
//	void ActivateGameOverlay( const char *pchDialog )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlay" );
//	}
//
//	void ActivateGameOverlayToUser( const char *pchDialog, CSteamID steamID )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToUser" );
//	}
//
//	void ActivateGameOverlayToWebPage( const char *pchURL )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToWebPage" );
//	}
//
//	void ActivateGameOverlayToStore( AppId_t nAppID )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "ActivateGameOverlayToStore" );
//	}
//
//	void SetPlayedWith( CSteamID steamIDUserPlayedWith )
//	{
//		g_Logging.AddToLogFileA( "ISteamFriends005.log", "SetPlayedWith" );
//	}
//};
//
//class CSteamNetworking003 : public ISteamNetworking003
//{
//public:
//
//	bool SendP2PPacket( CSteamID steamIDRemote, const void *pubData, uint32 cubData, EP2PSend eP2PSendType )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "SendP2PPacket" );
//
//		return 0;
//	}
//
//	bool IsP2PPacketAvailable( uint32 *pcubMsgSize )
//	{
//		//g_Logging.AddToLogFileA( "ISteamNetworking003.log", "IsP2PPacketAvailable" );
//
//		return false;
//	}
//
//	bool ReadP2PPacket( void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, CSteamID *psteamIDRemote )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "ReadP2PPacket" );
//
//		return false;
//	}
//
//	bool AcceptP2PSessionWithUser( CSteamID steamIDRemote )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "AcceptP2PSessionWithUser" );
//
//		return false;
//	}
//
//	bool CloseP2PSessionWithUser( CSteamID steamIDRemote )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CloseP2PSessionWithUser" );
//
//		return 0;
//	}
//
//	bool GetP2PSessionState( CSteamID steamIDRemote, P2PSessionState_t *pConnectionState )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetP2PSessionState" );
//
//		return 0;
//	}
//
//	SNetListenSocket_t CreateListenSocket( int nVirtualP2PPort, uint32 nIP, uint16 nPort, bool bAllowUseOfPacketRelay )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CreateListenSocket" );
//
//		return 0;
//	}
//
//	SNetSocket_t CreateP2PConnectionSocket( CSteamID steamIDTarget, int nVirtualPort, int nTimeoutSec, bool bAllowUseOfPacketRelay )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CreateP2PConnectionSocket" );
//
//		return 0;
//	}
//
//	SNetSocket_t CreateConnectionSocket( uint32 nIP, uint16 nPort, int nTimeoutSec )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "CreateConnectionSocket" );
//
//		return 0;
//	}
//
//	bool DestroySocket( SNetSocket_t hSocket, bool bNotifyRemoteEnd )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "DestroySocket" );
//
//		return false;
//	}
//
//	bool DestroyListenSocket( SNetListenSocket_t hSocket, bool bNotifyRemoteEnd )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "DestroyListenSocket" );
//
//		return false;
//	}
//
//	bool SendDataOnSocket( SNetSocket_t hSocket, void *pubData, uint32 cubData, bool bReliable )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "SendDataOnSocket" );
//
//		return false;
//	}
//
//	bool IsDataAvailableOnSocket( SNetSocket_t hSocket, uint32 *pcubMsgSize )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "IsDataAvailableOnSocket" );
//
//		return false;
//	}
//
//	bool RetrieveDataFromSocket( SNetSocket_t hSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "RetrieveDataFromSocket" );
//
//		return false;
//	}
//
//	bool IsDataAvailable( SNetListenSocket_t hListenSocket, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "IsDataAvailable" );
//
//		return false;
//	}
//
//	bool RetrieveData( SNetListenSocket_t hListenSocket, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize, SNetSocket_t *phSocket )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "RetrieveData" );
//
//		return false;
//	}
//
//	bool GetSocketInfo( SNetSocket_t hSocket, CSteamID *pSteamIDRemote, int *peSocketStatus, uint32 *punIPRemote, uint16 *punPortRemote )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetSocketInfo" );
//
//		return false;
//	}
//
//	bool GetListenSocketInfo( SNetListenSocket_t hListenSocket, uint32 *pnIP, uint16 *pnPort )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetListenSocketInfo" );
//
//		return false;
//	}
//
//	ESNetSocketConnectionType GetSocketConnectionType( SNetSocket_t hSocket )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetSocketConnectionType" );
//
//		return k_ESNetSocketConnectionTypeNotConnected;
//	}
//
//	int GetMaxPacketSize( SNetSocket_t hSocket )
//	{
//		g_Logging.AddToLogFileA( "ISteamNetworking003.log", "GetMaxPacketSize" );
//
//		return 65565;
//	}
//};
//
//
//
//class CSteamMatchmaking007 : public ISteamMatchmaking007
//{
//public:
//	int GetFavoriteGameCount()
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetFavoriteGameCount" );
//
//		return 0;
//	}
//
//	bool GetFavoriteGame( int iGame, AppId_t *pnAppID, uint32 *pnIP, uint16 *pnConnPort, uint16 *pnQueryPort, uint32 *punFlags, RTime32 *pRTime32LastPlayedOnServer )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetFavoriteGame" );
//
//		return false;
//	}
//
//	int AddFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags, RTime32 rTime32LastPlayedOnServer )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddFavoriteGame" );
//
//		return 0;
//	}
//
//    bool RemoveFavoriteGame( AppId_t nAppID, uint32 nIP, uint16 nConnPort, uint16 nQueryPort, uint32 unFlags )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "RemoveFavoriteGame" );
//
//		return false;
//	}
//
//	SteamAPICall_t RequestLobbyList()
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "RequestLobbyList" );
//
//		return NULL;
//	}
//	void AddRequestLobbyListStringFilter( const char *pchKeyToMatch, const char *pchValueToMatch, ELobbyComparison eComparisonType )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListStringFilter" );
//
//		return;
//	}
//
//	void AddRequestLobbyListNumericalFilter( const char *pchKeyToMatch, int nValueToMatch, ELobbyComparison eComparisonType )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListNumericalFilter" );
//
//		return;
//	}
//
//	void AddRequestLobbyListNearValueFilter( const char *pchKeyToMatch, int nValueToBeCloseTo )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListNearValueFilter" );
//
//		return;
//	}
//
//	void AddRequestLobbyListFilterSlotsAvailable( int nSlotsAvailable )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "AddRequestLobbyListSlotsAvailableFilter" );
//
//		return;
//	}
//
//	CSteamID GetLobbyByIndex( int iLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyByIndex" );
//
//		return CSteamID( 0x100000, k_EUniversePublic, k_EAccountTypeIndividual );
//	}
//
//	SteamAPICall_t CreateLobby( ELobbyType eLobbyType, int id)
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "CreateLobby type=%d id=%d", eLobbyType, id );
//
//		static SteamAPICall_t s_createlobby_api = 0;
//		g_LobbySteamId = CSteamID( 0x840100+id, k_EChatInstanceFlagLobby, k_EUniversePublic, k_EAccountTypeChat );
//		g_RemoteLobbySteamId = g_LobbySteamId;
//		g_LobbyPendingCreate = true;
//		s_createlobby_api++;
//		return s_createlobby_api;
//	}
//
//	SteamAPICall_t JoinLobby( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "JoinLobby <%llx>", steamIDLobby.ConvertToUint64() );
//		g_RemoteLobbySteamId = steamIDLobby;
//		return 0x10101;
//	}
//
//	void LeaveLobby( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "LeaveLobby" );
//
//		return;
//	}
//
//	bool InviteUserToLobby( CSteamID steamIDLobby, CSteamID steamIDInvitee )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "InviteUserToLobby" );
//
//		return false;
//	}
//
//	int GetNumLobbyMembers( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetNumLobbyMembers" );
//
//		return 2;
//	}
//
//	CSteamID GetLobbyMemberByIndex( CSteamID steamIDLobby, int iMember )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyMemberByIndex <%llx> Member #%d", steamIDLobby.ConvertToUint64(), iMember );
//
//		return CSteamID( 0x100000, k_EUniversePublic, k_EAccountTypeIndividual );
//	}
//
//	#pragma optimize("", off)
//	const char *GetLobbyData( CSteamID steamIDLobby, const char *pchKey )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyData <%llx> pchKey=%s", steamIDLobby.ConvertToUint64(), pchKey );
//
//		static char localAddress[16] = "";
//		static char remoteAddress[16] = "";
//		static char locPort[16] = "";
//		static char remotePort[16] = "";
//		
//		_snprintf(localAddress,16,"%d", g_TeknoGodzMW2_ConnectIpAddr);
//		_snprintf(remoteAddress,16,"%d", g_TeknoGodzMW2_ConnectIpAddr);
//		_snprintf(locPort,16,"%d",g_TeknoGodzMW2_ConnectPort);
//		_snprintf(remotePort,16,"%d",g_TeknoGodzMW2_ConnectPort);
//
//		if(strcmp(pchKey, "addrLoc") == 0 )
//		{
//			return localAddress;
//		}
//		if(strcmp(pchKey, "addr") == 0)
//		{
//			return remoteAddress;
//		}
//
//		if(strcmp(pchKey, "portLoc") == 0 )
//		{
//			return locPort;
//		}
//
//		if(strcmp(pchKey, "port") == 0)
//		{
//			return remotePort;
//		}
//
//		return NULL;
//	}
//	#pragma optimize("", on)
//
//	bool SetLobbyData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyData <%llx> %s=%s", steamIDLobby.ConvertToUint64(), pchKey, pchValue );
//		
//
//		return false;
//	}
//
//	int GetLobbyDataCount( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyDataCount" );
//
//		return 0;
//	}
//
//	bool GetLobbyDataByIndex( CSteamID steamIDLobby, int iData, char *pchKey, int cubKey, char *pchValue, int cubValue )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyDataByIndex" );
//
//		return false;
//	}
//
//	bool DeleteLobbyData( CSteamID steamIDLobby, const char *pchKey )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "DeleteLobbyData" );
//
//		return false;
//	}
//
//	const char *GetLobbyMemberData( CSteamID steamIDLobby, CSteamID steamIDUser, const char *pchKey )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyMemberData" );
//
//		return NULL;
//	}
//
//	void SetLobbyMemberData( CSteamID steamIDLobby, const char *pchKey, const char *pchValue )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyMemberData" );
//
//		return;
//	}
//
//	bool SendLobbyChatMsg( CSteamID steamIDLobby, const void *pvMsgBody, int cubMsgBody )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SendLobbyChatMsg" );
//
//		return false;
//	}
//
//	int GetLobbyChatEntry( CSteamID steamIDLobby, int iChatID, CSteamID *pSteamIDUser, void *pvData, int cubData, EChatEntryType *peChatEntryType )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyChatEntry" );
//
//		return 0;
//	}
//
//	bool RequestLobbyData( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "RequestLobbyData" );
//
//		return false;
//	}
//
//	void SetLobbyGameServer( CSteamID steamIDLobby, uint32 unGameServerIP, uint16 unGameServerPort, CSteamID steamIDGameServer )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyGameServer" );
//
//		return;
//	}
//
//	bool GetLobbyGameServer( CSteamID steamIDLobby, uint32 *punGameServerIP, uint16 *punGameServerPort, CSteamID *psteamIDGameServer )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyGameServer" );
//
//		return false;
//	}
//
//	bool SetLobbyMemberLimit( CSteamID steamIDLobby, int cMaxMembers )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyMemberLimit <%llx> MaxMembers=%d", steamIDLobby.ConvertToUint64(), cMaxMembers );
//
//		return false;
//	}
//
//	int GetLobbyMemberLimit( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyMemberLimit" );
//
//		return 1;
//	}
//
//	bool SetLobbyType( CSteamID steamIDLobby, ELobbyType eLobbyType )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyType <%llx> Type=%d", steamIDLobby.ConvertToUint64(), eLobbyType );
//
//		return false;
//	}
//
//	bool SetLobbyJoinable( CSteamID steamIDLobby, bool bJoinable )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyJoinable" );
//
//		return false;
//	}
//
//	CSteamID GetLobbyOwner( CSteamID steamIDLobby )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "GetLobbyOwner <%llx>", steamIDLobby.ConvertToUint64() );
//
//		return g_UserSteamId;
//	}
//
//	bool SetLobbyOwner( CSteamID steamIDLobby, CSteamID steamIDNewOwner )
//	{
//		g_Logging.AddToLogFileA( "ISteamMatchmaking007.log", "SetLobbyOwner" );
//
//		return 0;
//	}
//};
//
//
//class CSteamGameServer009 : public ISteamGameServer009
//{
//public:
//	void LogOn()
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "LogOn" );
//
//	}
//
//	void LogOff()
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "LogOff" );
//	}
//	
//	bool BLoggedOn()
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "LoggedOn" );
//
//		return true;
//	}
//
//	bool BSecure()
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "Secure" );
//
//		return true;
//	}
//
//	CSteamID GetSteamID()
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetSteamID" );
//
//		return CSteamID( 0x100000, k_EUniversePublic, k_EAccountTypeIndividual );
//	}
//
//	bool SendUserConnectAndAuthenticate( uint32 unIPClient, const void *pvAuthBlob, uint32 cubAuthBlobSize, CSteamID *pSteamIDUser )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SendUserConnectAndAuthenticate" );
//
//		return true;
//	}
//
//	CSteamID CreateUnauthenticatedUserConnection()
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "CreateUnauthenticatedUserConnection" );
//
//		return CSteamID( 0x1, k_EUniversePublic, k_EAccountTypeIndividual );
//	}
//
//	void SendUserDisconnect( CSteamID steamIDUser )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SendUserDisconnect" );
//
//		return;
//	}
//
//	bool BUpdateUserData( CSteamID steamIDUser, const char *pchPlayerName, uint32 uScore )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UpdateUserData" );
//
//		return true;
//	}
//
//	bool BSetServerType( uint32 unServerFlags, uint32 unGameIP, uint16 unGamePort, 
//								uint16 unSpectatorPort, uint16 usQueryPort, const char *pchGameDir, const char *pchVersion, bool bLANMode )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SetServerType" );
//
//		return true;
//	}
//
//	void UpdateServerStatus( int cPlayers, int cPlayersMax, int cBotPlayers, 
//									 const char *pchServerName, const char *pSpectatorServerName, 
//									 const char *pchMapName )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UpdateServerStatus(cPlayers=%d, cPlayersMax=%d, cBotPlayers=%d, pchServerName='%s', pSpectatorServerName='%s',  pchMapName='%s'", cPlayers, cPlayersMax, cBotPlayers, pchServerName, pSpectatorServerName, pchMapName);
//
//		return;
//	}
//
//	void UpdateSpectatorPort( uint16 unSpectatorPort )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UpdateSpectatorPort" );
//
//		return;
//	}
//
//	void SetGameType( const char *pchGameType )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SetGameType" );
//
//		return;
//	}
//
//	bool BGetUserAchievementStatus( CSteamID steamID, const char *pchAchievementName )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetUserAchievementStatus" );
//
//		return true;
//	}
//
//	void GetGameplayStats( )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetGameplayStats" );
//
//		return;
//	}
//
//	bool RequestUserGroupStatus( CSteamID steamIDUser, CSteamID steamIDGroup )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "RequestUserGroupStatus" );
//
//		return true;
//	}
//
//	uint32 GetPublicIP()
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "GetPublicIP" );
//
//		return NULL;
//	}
//
//	void SetGameData( const char *pchGameData )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "SetGameData" );
//
//		return;
//	}
//
//	EUserHasLicenseForAppResult UserHasLicenseForApp( CSteamID steamID, AppId_t appID )
//	{
//		g_Logging.AddToLogFileA( "ISteamGameServer009.log", "UserHasLicenseForApp" );
//
//		return k_EUserHasLicenseResultHasLicense;
//	}
//};
//
//
//
//class CSteamUserStats006 : public ISteamUserStats006
//{
//public:
//	bool RequestCurrentStats()
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "RequestCurrentStats" );
//
//		return true;
//	}
//
//	bool GetStat( const char *pchName, int32 *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetStat" );
//
//		return false;
//	}
//
//	bool GetStat( const char *pchName, float *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetStat" );
//	
//		return false;
//	}
//
//	bool SetStat( const char *pchName, int32 nData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "SetStat" );
//
//		return true;
//	}
//
//	bool SetStat( const char *pchName, float fData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "SetStat" );
//
//		return true;
//	}
//
//	bool UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "UpdateAvgRateStat" );
//
//		return true;
//	}
//
//	bool GetAchievement( const char *pchName, bool *pbAchieved )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetAchievement" );
//
//		*pbAchieved = true;
//
//		return true;
//	}
//
//	bool SetAchievement( const char *pchName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "SetAchievement" );
//
//		return true;
//	}
//
//	bool ClearAchievement( const char *pchName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "ClearAchievement" );
//
//		return true;
//	}
//
//	bool StoreStats()
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "StoreStats" );
//
//		return true;
//	}
//
//	int GetAchievementIcon( const char *pchName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetAchievementIcon" );
//
//		return 0;
//	}
//
//	const char *GetAchievementDisplayAttribute( const char *pchName, const char *pchKey )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetAchievementDisplayAttribute" );
//
//		return "TeknoGods.com";
//	}
//
//	bool IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "IndicateAchievementProgress" );
//	
//		return false;
//	}
//
//	SteamAPICall_t RequestUserStats( CSteamID steamIDUser )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "RequestUserStats" );
//
//		return 0;
//	}
//	
//	bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetUserStat" );
//
//		return false;
//	}
//
//	bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetUserStat" );
//
//		return false;
//	}
//
//	bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetUserAchievement" );
//
//		*pbAchieved = true;
//
//		return true;
//	}
//
//	bool ResetAllStats( bool bAchievementsToo )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "ResetAllStats" );
//
//		return true;
//	}
//
//	SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) 
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "FindOrCreateLeaderboard" );
//
//		return 0;
//	}
//	
//	SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "FindLeaderboard" );
//
//		return 0;
//	}
//
//	const char *GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetLeaderboardName" );
//
//		return "TeknoGods.com";
//	}
//
//	int GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetLeaderboardEntryCount" );
//
//		return 0;
//	}
//
//	ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetLeaderboardSortMethod" );
//
//		return k_ELeaderboardSortMethodNone;
//	}
//
//	ELeaderboardDisplayType GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetLeaderboardDisplayType" );
//
//		return k_ELeaderboardDisplayTypeNone;
//	}
//
//	SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "DownloadLeaderboardEntries" );
//
//		return 0;
//	}
//
//	bool GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry001_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetDownloadedLeaderboardEntry" );
//
//		return false;
//	}
//
//	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard,ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "UploadLeaderboardScore" );
//
//		return 0;
//	}
//
//	SteamAPICall_t GetNumberOfCurrentPlayers()
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats006.log", "GetNumberOfCurrentPlayers" );
//
//		return 1;
//	}
//};
//
//
//
//class CSteamUserStats007 : public ISteamUserStats007
//{
//public:
//	bool RequestCurrentStats()
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "RequestCurrentStats" );
//
//		return true;
//	}
//
//	bool GetStat( const char *pchName, int32 *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetStat" );
//
//		return false;
//	}
//
//	bool GetStat( const char *pchName, float *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetStat" );
//	
//		return false;
//	}
//
//	bool SetStat( const char *pchName, int32 nData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "SetStat" );
//
//		return true;
//	}
//
//	bool SetStat( const char *pchName, float fData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "SetStat" );
//
//		return true;
//	}
//
//	bool UpdateAvgRateStat( const char *pchName, float flCountThisSession, double dSessionLength )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "UpdateAvgRateStat" );
//
//		return true;
//	}
//
//	bool GetAchievement( const char *pchName, bool *pbAchieved )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievement" );
//
//		*pbAchieved = true;
//
//		return true;
//	}
//
//	bool SetAchievement( const char *pchName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "SetAchievement" );
//
//		return true;
//	}
//
//	bool ClearAchievement( const char *pchName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "ClearAchievement" );
//
//		return true;
//	}
//
//	bool GetAchievementAndUnlockTime( const char *pchName, bool *pbAchieved, RTime32 *prtTime )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievementAndUnlockTime" );
//
//		return true;
//	}
//
//	bool StoreStats()
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "StoreStats" );
//
//		return true;
//	}
//
//	int GetAchievementIcon( const char *pchName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievementIcon" );
//
//		return 0;
//	}
//
//	const char *GetAchievementDisplayAttribute( const char *pchName, const char *pchKey )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetAchievementDisplayAttribute" );
//
//		return "TeknoGods.com";
//	}
//
//	bool IndicateAchievementProgress( const char *pchName, uint32 nCurProgress, uint32 nMaxProgress )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "IndicateAchievementProgress" );
//	
//		return false;
//	}
//
//	SteamAPICall_t RequestUserStats( CSteamID steamIDUser )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "RequestUserStats" );
//
//		return 0;
//	}
//	
//	bool GetUserStat( CSteamID steamIDUser, const char *pchName, int32 *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserStat" );
//
//		return false;
//	}
//
//	bool GetUserStat( CSteamID steamIDUser, const char *pchName, float *pData )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserStat" );
//
//		return false;
//	}
//
//	bool GetUserAchievement( CSteamID steamIDUser, const char *pchName, bool *pbAchieved )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserAchievement" );
//
//		*pbAchieved = true;
//
//		return true;
//	}
//
//	bool GetUserAchievementAndUnlockTime( CSteamID steamIDUser, const char *pchName, bool *pbAchieved, RTime32 *prtTime )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetUserAchievementAndUnlockTime" );
//
//		*pbAchieved = true;
//
//		*prtTime = GetCurrentTime();
//
//		return true;
//	}
//
//
//	bool ResetAllStats( bool bAchievementsToo )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "ResetAllStats" );
//
//		return true;
//	}
//
//	SteamAPICall_t FindOrCreateLeaderboard( const char *pchLeaderboardName, ELeaderboardSortMethod eLeaderboardSortMethod, ELeaderboardDisplayType eLeaderboardDisplayType ) 
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "FindOrCreateLeaderboard" );
//
//		return 0;
//	}
//	
//	SteamAPICall_t FindLeaderboard( const char *pchLeaderboardName )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "FindLeaderboard" );
//
//		return 0;
//	}
//
//	const char *GetLeaderboardName( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardName" );
//
//		return "TeknoGods.com";
//	}
//
//	int GetLeaderboardEntryCount( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardEntryCount" );
//
//		return 0;
//	}
//
//	ELeaderboardSortMethod GetLeaderboardSortMethod( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardSortMethod" );
//
//		return k_ELeaderboardSortMethodNone;
//	}
//
//	ELeaderboardDisplayType GetLeaderboardDisplayType( SteamLeaderboard_t hSteamLeaderboard )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetLeaderboardDisplayType" );
//
//		return k_ELeaderboardDisplayTypeNone;
//	}
//
//	SteamAPICall_t DownloadLeaderboardEntries( SteamLeaderboard_t hSteamLeaderboard, ELeaderboardDataRequest eLeaderboardDataRequest, int nRangeStart, int nRangeEnd )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "DownloadLeaderboardEntries" );
//
//		return 0;
//	}
//	
//	bool GetDownloadedLeaderboardEntry( SteamLeaderboardEntries_t hSteamLeaderboardEntries, int index, LeaderboardEntry001_t *pLeaderboardEntry, int32 *pDetails, int cDetailsMax )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetDownloadedLeaderboardEntry" );
//
//		return false;
//	}
//
//	SteamAPICall_t UploadLeaderboardScore( SteamLeaderboard_t hSteamLeaderboard,ELeaderboardUploadScoreMethod eLeaderboardUploadScoreMethod, int32 nScore, int32 *pScoreDetails, int cScoreDetailsCount )
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "UploadLeaderboardScore" );
//
//		return 0;
//	}
//
//	SteamAPICall_t GetNumberOfCurrentPlayers()
//	{
//		g_Logging.AddToLogFileA( "ISteamUserStats007.log", "GetNumberOfCurrentPlayers" );
//
//		return 1;
//	}
//};
//
