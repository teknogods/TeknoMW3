#include "ISteamFriends008.h"

class ISteamFriends008_wrapper
{
public:
	virtual const char * GetPersonaName ()	{
		char log[1024];
		sprintf(log,"GetPersonaName() "		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetPersonaName();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetPersonaName ( const char *pchPersonaName )	{
		char log[1024];
		sprintf(log,"SetPersonaName() pchPersonaName=%s ",
			pchPersonaName		);
		OutputDebugStringA(log);
		pchPersonaName);
		OutputDebugStringA("\n");
	}
	virtual EPersonaState  GetPersonaState ()	{
		char log[1024];
		sprintf(log,"GetPersonaState() "		);
		OutputDebugStringA(log);
		EPersonaState  ret = m_pWrapper->GetPersonaState();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetFriendCount ( EFriendFlags eFriendFlags )	{
		char log[1024];
		sprintf(log,"GetFriendCount() eFriendFlags=0x%X ",
			eFriendFlags		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFriendCount(eFriendFlags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetFriendByIndex ( int iFriend,  int iFriendFlags )	{
		char log[1024];
		sprintf(log,"GetFriendByIndex() iFriend=0x%X iFriendFlags=0x%X ",
			iFriend,
			iFriendFlags		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetFriendByIndex(iFriend, iFriendFlags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EFriendRelationship  GetFriendRelationship ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetFriendRelationship() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		EFriendRelationship  ret = m_pWrapper->GetFriendRelationship(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EPersonaState  GetFriendPersonaState ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetFriendPersonaState() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		EPersonaState  ret = m_pWrapper->GetFriendPersonaState(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetFriendPersonaName ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetFriendPersonaName() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFriendPersonaName(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFriendGamePlayed ( CSteamID steamIDFriend,  FriendGameInfo_t *pFriendGameInfo )	{
		char log[1024];
		sprintf(log,"GetFriendGamePlayed() steamIDFriend=0x%X pFriendGameInfo=0x%X ",
			steamIDFriend,
			pFriendGameInfo		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFriendGamePlayed(steamIDFriend, pFriendGameInfo);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetFriendPersonaNameHistory ( CSteamID steamIDFriend,  int iPersonaName )	{
		char log[1024];
		sprintf(log,"GetFriendPersonaNameHistory() steamIDFriend=0x%X iPersonaName=0x%X ",
			steamIDFriend,
			iPersonaName		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFriendPersonaNameHistory(steamIDFriend, iPersonaName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  HasFriend ( CSteamID steamIDFriend,  EFriendFlags eFriendFlags )	{
		char log[1024];
		sprintf(log,"HasFriend() steamIDFriend=0x%X eFriendFlags=0x%X ",
			steamIDFriend,
			eFriendFlags		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HasFriend(steamIDFriend, eFriendFlags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetClanCount ()	{
		char log[1024];
		sprintf(log,"GetClanCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetClanCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetClanByIndex ( int iClan )	{
		char log[1024];
		sprintf(log,"GetClanByIndex() iClan=0x%X ",
			iClan		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetClanByIndex(iClan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetClanName ( CSteamID steamIDClan )	{
		char log[1024];
		sprintf(log,"GetClanName() steamIDClan=0x%X ",
			steamIDClan		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetClanName(steamIDClan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetClanTag ( CSteamID steamIDClan )	{
		char log[1024];
		sprintf(log,"GetClanTag() steamIDClan=0x%X ",
			steamIDClan		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetClanTag(steamIDClan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetFriendCountFromSource ( CSteamID steamIDSource )	{
		char log[1024];
		sprintf(log,"GetFriendCountFromSource() steamIDSource=0x%X ",
			steamIDSource		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFriendCountFromSource(steamIDSource);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetFriendFromSourceByIndex ( CSteamID steamIDSource,  int iFriend )	{
		char log[1024];
		sprintf(log,"GetFriendFromSourceByIndex() steamIDSource=0x%X iFriend=0x%X ",
			steamIDSource,
			iFriend		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetFriendFromSourceByIndex(steamIDSource, iFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsUserInSource ( CSteamID steamIDUser,  CSteamID steamIDSource )	{
		char log[1024];
		sprintf(log,"IsUserInSource() steamIDUser=0x%X steamIDSource=0x%X ",
			steamIDUser,
			steamIDSource		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsUserInSource(steamIDUser, steamIDSource);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetInGameVoiceSpeaking ( CSteamID steamIDUser,  bool bSpeaking )	{
		char log[1024];
		sprintf(log,"SetInGameVoiceSpeaking() steamIDUser=0x%X bSpeaking=0x%X ",
			steamIDUser,
			bSpeaking		);
		OutputDebugStringA(log);
		steamIDUser, bSpeaking);
		OutputDebugStringA("\n");
	}
	virtual void  ActivateGameOverlay ( const char *pchDialog )	{
		char log[1024];
		sprintf(log,"ActivateGameOverlay() pchDialog=%s ",
			pchDialog		);
		OutputDebugStringA(log);
		pchDialog);
		OutputDebugStringA("\n");
	}
	virtual void  ActivateGameOverlayToUser ( const char *pchDialog,  CSteamID steamID )	{
		char log[1024];
		sprintf(log,"ActivateGameOverlayToUser() pchDialog=%s steamID=0x%X ",
			pchDialog,
			steamID		);
		OutputDebugStringA(log);
		pchDialog, steamID);
		OutputDebugStringA("\n");
	}
	virtual void  ActivateGameOverlayToWebPage ( const char *pchURL )	{
		char log[1024];
		sprintf(log,"ActivateGameOverlayToWebPage() pchURL=%s ",
			pchURL		);
		OutputDebugStringA(log);
		pchURL);
		OutputDebugStringA("\n");
	}
	virtual void  ActivateGameOverlayToStore ( AppId_t nAppID )	{
		char log[1024];
		sprintf(log,"ActivateGameOverlayToStore() nAppID=0x%X ",
			nAppID		);
		OutputDebugStringA(log);
		nAppID);
		OutputDebugStringA("\n");
	}
	virtual void  SetPlayedWith ( CSteamID steamIDUserPlayedWith )	{
		char log[1024];
		sprintf(log,"SetPlayedWith() steamIDUserPlayedWith=0x%X ",
			steamIDUserPlayedWith		);
		OutputDebugStringA(log);
		steamIDUserPlayedWith);
		OutputDebugStringA("\n");
	}
	virtual void  ActivateGameOverlayInviteDialog ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"ActivateGameOverlayInviteDialog() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		steamIDLobby);
		OutputDebugStringA("\n");
	}
	virtual int  GetSmallFriendAvatar ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetSmallFriendAvatar() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSmallFriendAvatar(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetMediumFriendAvatar ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetMediumFriendAvatar() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetMediumFriendAvatar(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetLargeFriendAvatar ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetLargeFriendAvatar() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetLargeFriendAvatar(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestUserInformation ( CSteamID steamID,  bool bUnk1 )	{
		char log[1024];
		sprintf(log,"RequestUserInformation() steamID=0x%X bUnk1=0x%X ",
			steamID,
			bUnk1		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestUserInformation(steamID, bUnk1);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestClanOfficerList ( CSteamID clanId )	{
		char log[1024];
		sprintf(log,"RequestClanOfficerList() clanId=0x%X ",
			clanId		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestClanOfficerList(clanId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetClanOwner ( CSteamID clanId )	{
		char log[1024];
		sprintf(log,"GetClanOwner() clanId=0x%X ",
			clanId		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetClanOwner(clanId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetClanOfficerCount ( CSteamID clanId )	{
		char log[1024];
		sprintf(log,"GetClanOfficerCount() clanId=0x%X ",
			clanId		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetClanOfficerCount(clanId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetClanOfficerByIndex ( CSteamID clanId,  int iIndex )	{
		char log[1024];
		sprintf(log,"GetClanOfficerByIndex() clanId=0x%X iIndex=0x%X ",
			clanId,
			iIndex		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetClanOfficerByIndex(clanId, iIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetUserRestrictions ()	{
		char log[1024];
		sprintf(log,"GetUserRestrictions() "		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetUserRestrictions();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
