#include "ISteamFriends009.h"

class ISteamFriends009_wrapper
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
	virtual int  GetFriendCount ( int iFriendFlags )	{
		char log[1024];
		sprintf(log,"GetFriendCount() iFriendFlags=0x%X ",
			iFriendFlags		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFriendCount(iFriendFlags);
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
	virtual bool  HasFriend ( CSteamID steamIDFriend,  int iFriendFlags )	{
		char log[1024];
		sprintf(log,"HasFriend() steamIDFriend=0x%X iFriendFlags=0x%X ",
			steamIDFriend,
			iFriendFlags		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HasFriend(steamIDFriend, iFriendFlags);
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
	virtual bool  RequestUserInformation ( CSteamID steamIDUser,  bool bRequireNameOnly )	{
		char log[1024];
		sprintf(log,"RequestUserInformation() steamIDUser=0x%X bRequireNameOnly=0x%X ",
			steamIDUser,
			bRequireNameOnly		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestUserInformation(steamIDUser, bRequireNameOnly);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestClanOfficerList ( CSteamID steamIDClan )	{
		char log[1024];
		sprintf(log,"RequestClanOfficerList() steamIDClan=0x%X ",
			steamIDClan		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestClanOfficerList(steamIDClan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetClanOwner ( CSteamID steamIDClan )	{
		char log[1024];
		sprintf(log,"GetClanOwner() steamIDClan=0x%X ",
			steamIDClan		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetClanOwner(steamIDClan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetClanOfficerCount ( CSteamID steamIDClan )	{
		char log[1024];
		sprintf(log,"GetClanOfficerCount() steamIDClan=0x%X ",
			steamIDClan		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetClanOfficerCount(steamIDClan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetClanOfficerByIndex ( CSteamID steamIDClan,  int iOfficer )	{
		char log[1024];
		sprintf(log,"GetClanOfficerByIndex() steamIDClan=0x%X iOfficer=0x%X ",
			steamIDClan,
			iOfficer		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetClanOfficerByIndex(steamIDClan, iOfficer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetUserRestrictions ()	{
		char log[1024];
		sprintf(log,"GetUserRestrictions() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetUserRestrictions();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetRichPresence ( const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetRichPresence() pchKey=%s pchValue=%s ",
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetRichPresence(pchKey, pchValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ClearRichPresence ()	{
		char log[1024];
		sprintf(log,"ClearRichPresence() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual const char * GetFriendRichPresence ( CSteamID steamIDFriend,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"GetFriendRichPresence() steamIDFriend=0x%X pchKey=%s ",
			steamIDFriend,
			pchKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFriendRichPresence(steamIDFriend, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetFriendRichPresenceKeyCount ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetFriendRichPresenceKeyCount() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFriendRichPresenceKeyCount(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetFriendRichPresenceKeyByIndex ( CSteamID steamIDFriend,  int iKey )	{
		char log[1024];
		sprintf(log,"GetFriendRichPresenceKeyByIndex() steamIDFriend=0x%X iKey=0x%X ",
			steamIDFriend,
			iKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFriendRichPresenceKeyByIndex(steamIDFriend, iKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  InviteUserToGame ( CSteamID steamIDFriend,  const char *pchConnectString )	{
		char log[1024];
		sprintf(log,"InviteUserToGame() steamIDFriend=0x%X pchConnectString=%s ",
			steamIDFriend,
			pchConnectString		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InviteUserToGame(steamIDFriend, pchConnectString);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetCoplayFriendCount ()	{
		char log[1024];
		sprintf(log,"GetCoplayFriendCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetCoplayFriendCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetCoplayFriend ( int iCoplayFriend )	{
		char log[1024];
		sprintf(log,"GetCoplayFriend() iCoplayFriend=0x%X ",
			iCoplayFriend		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetCoplayFriend(iCoplayFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetFriendCoplayTime ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetFriendCoplayTime() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFriendCoplayTime(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual AppId_t  GetFriendCoplayGame ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetFriendCoplayGame() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		AppId_t  ret = m_pWrapper->GetFriendCoplayGame(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
