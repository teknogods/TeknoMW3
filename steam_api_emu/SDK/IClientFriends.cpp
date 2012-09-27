#include "IClientFriends.h"

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
	virtual bool  IsPersonaNameSet ()	{
		char log[1024];
		sprintf(log,"IsPersonaNameSet() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsPersonaNameSet();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
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
	virtual void  SetPersonaState ( EPersonaState ePersonaState )	{
		char log[1024];
		sprintf(log,"SetPersonaState() ePersonaState=0x%X ",
			ePersonaState		);
		OutputDebugStringA(log);
		ePersonaState);
		OutputDebugStringA("\n");
	}
	virtual bool  NotifyUIOfMenuChange ( bool bShowAvatars,  bool bSortByName,  bool bShowOnlineOnly,  bool bShowTaggedFriends )	{
		char log[1024];
		sprintf(log,"NotifyUIOfMenuChange() bShowAvatars=0x%X bSortByName=0x%X bShowOnlineOnly=0x%X bShowTaggedFriends=0x%X ",
			bShowAvatars,
			bSortByName,
			bShowOnlineOnly,
			bShowTaggedFriends		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->NotifyUIOfMenuChange(bShowAvatars, bSortByName, bShowOnlineOnly, bShowTaggedFriends);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetFriendCount ( EFriendFlags iFriendFlags )	{
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
	virtual CSteamID  GetFriendByIndex ( int iFriend,  EFriendFlags iFriendFlags )	{
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
	virtual int  GetOnlineFriendCount ()	{
		char log[1024];
		sprintf(log,"GetOnlineFriendCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetOnlineFriendCount();
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
	virtual void  SetFriendAlias ( CSteamID steamIDFriend,  const char *pchAlias )	{
		char log[1024];
		sprintf(log,"SetFriendAlias() steamIDFriend=0x%X pchAlias=%s ",
			steamIDFriend,
			pchAlias		);
		OutputDebugStringA(log);
		steamIDFriend, pchAlias);
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
	virtual void  SetFriendRegValue ( CSteamID steamIDFriend,  const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetFriendRegValue() steamIDFriend=0x%X pchKey=%s pchValue=%s ",
			steamIDFriend,
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		steamIDFriend, pchKey, pchValue);
		OutputDebugStringA("\n");
	}
	virtual const char * GetFriendRegValue ( CSteamID steamIDFriend,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"GetFriendRegValue() steamIDFriend=0x%X pchKey=%s ",
			steamIDFriend,
			pchKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFriendRegValue(steamIDFriend, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  DeleteFriendRegValue ( CSteamID steamID,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"DeleteFriendRegValue() steamID=0x%X pchKey=%s ",
			steamID,
			pchKey		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->DeleteFriendRegValue(steamID, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFriendGamePlayed ( CSteamID steamID,  FriendGameInfo_t *pGamePlayInfo )	{
		char log[1024];
		sprintf(log,"GetFriendGamePlayed() steamID=0x%X pGamePlayInfo=0x%X ",
			steamID,
			pGamePlayInfo		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFriendGamePlayed(steamID, pGamePlayInfo);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetFriendGamePlayedExtraInfo ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendGamePlayedExtraInfo() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetFriendGamePlayedExtraInfo(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetFriendGameServer ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendGameServer() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetFriendGameServer(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetFriendPersonaStateFlags ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendPersonaStateFlags() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetFriendPersonaStateFlags(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsFriendGameOnConsole ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"IsFriendGameOnConsole() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsFriendGameOnConsole(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual unknown_ret  GetFriendRestrictions ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendRestrictions() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		unknown_ret  ret = m_pWrapper->GetFriendRestrictions(steamID);
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
	virtual SteamAPICall_t  RequestPersonaNameHistory ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"RequestPersonaNameHistory() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestPersonaNameHistory(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char *  GetFriendPersonaNameHistoryAndDate ( CSteamID steamIDFriend,  int32 iPersonaName,  RTime32 * puTime )	{
		char log[1024];
		sprintf(log,"GetFriendPersonaNameHistoryAndDate() steamIDFriend=0x%X iPersonaName=0x%X puTime=0x%X ",
			steamIDFriend,
			iPersonaName,
			puTime		);
		OutputDebugStringA(log);
		const char *  ret = m_pWrapper->GetFriendPersonaNameHistoryAndDate(steamIDFriend, iPersonaName, puTime);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddFriend ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"AddFriend() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddFriend(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveFriend ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"RemoveFriend() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveFriend(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  HasFriend ( CSteamID steamID,  EFriendFlags iFriendFlags )	{
		char log[1024];
		sprintf(log,"HasFriend() steamID=0x%X iFriendFlags=0x%X ",
			steamID,
			iFriendFlags		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HasFriend(steamID, iFriendFlags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual HSteamCall  AddFriendByName ( const char *pchEmailOrAccountName )	{
		char log[1024];
		sprintf(log,"AddFriendByName() pchEmailOrAccountName=%s ",
			pchEmailOrAccountName		);
		OutputDebugStringA(log);
		HSteamCall  ret = m_pWrapper->AddFriendByName(pchEmailOrAccountName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  InviteFriendByEmail ( const char *pchEmailAddress )	{
		char log[1024];
		sprintf(log,"InviteFriendByEmail() pchEmailAddress=%s ",
			pchEmailAddress		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InviteFriendByEmail(pchEmailAddress);
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
	virtual bool  SetIgnoreFriend ( CSteamID steamID,  bool bIgnore )	{
		char log[1024];
		sprintf(log,"SetIgnoreFriend() steamID=0x%X bIgnore=0x%X ",
			steamID,
			bIgnore		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetIgnoreFriend(steamID, bIgnore);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ReportChatDeclined ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"ReportChatDeclined() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ReportChatDeclined(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  CreateFriendsGroup ( const char* pchGroupName )	{
		char log[1024];
		sprintf(log,"CreateFriendsGroup() pchGroupName=%s ",
			pchGroupName		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->CreateFriendsGroup(pchGroupName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  DeleteFriendsGroup ( int16 iGroupID )	{
		char log[1024];
		sprintf(log,"DeleteFriendsGroup() iGroupID=0x%X ",
			iGroupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->DeleteFriendsGroup(iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RenameFriendsGroup ( const char* pchNewGroupName,  int16 iGroupID )	{
		char log[1024];
		sprintf(log,"RenameFriendsGroup() pchNewGroupName=%s iGroupID=0x%X ",
			pchNewGroupName,
			iGroupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RenameFriendsGroup(pchNewGroupName, iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AddFriendToGroup ( CSteamID steamID,  int16 iGroupID )	{
		char log[1024];
		sprintf(log,"AddFriendToGroup() steamID=0x%X iGroupID=0x%X ",
			steamID,
			iGroupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddFriendToGroup(steamID, iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveFriendFromGroup ( CSteamID steamID,  int16 iGroupID )	{
		char log[1024];
		sprintf(log,"RemoveFriendFromGroup() steamID=0x%X iGroupID=0x%X ",
			steamID,
			iGroupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveFriendFromGroup(steamID, iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsFriendMemberOfFriendsGroup ( CSteamID steamID,  int16 iGroupID )	{
		char log[1024];
		sprintf(log,"IsFriendMemberOfFriendsGroup() steamID=0x%X iGroupID=0x%X ",
			steamID,
			iGroupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsFriendMemberOfFriendsGroup(steamID, iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int16  GetFriendsGroupCount ()	{
		char log[1024];
		sprintf(log,"GetFriendsGroupCount() "		);
		OutputDebugStringA(log);
		int16  ret = m_pWrapper->GetFriendsGroupCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int16  GetFriendsGroupIDByIndex ( int16 iGroupIndex )	{
		char log[1024];
		sprintf(log,"GetFriendsGroupIDByIndex() iGroupIndex=0x%X ",
			iGroupIndex		);
		OutputDebugStringA(log);
		int16  ret = m_pWrapper->GetFriendsGroupIDByIndex(iGroupIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char *  GetFriendsGroupName ( int16 iGroupID )	{
		char log[1024];
		sprintf(log,"GetFriendsGroupName() iGroupID=0x%X ",
			iGroupID		);
		OutputDebugStringA(log);
		const char *  ret = m_pWrapper->GetFriendsGroupName(iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int16  GetFriendsGroupMembershipCount ( int16 iGroupID )	{
		char log[1024];
		sprintf(log,"GetFriendsGroupMembershipCount() iGroupID=0x%X ",
			iGroupID		);
		OutputDebugStringA(log);
		int16  ret = m_pWrapper->GetFriendsGroupMembershipCount(iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetFirstFriendsGroupMember ( int16 iGroupID )	{
		char log[1024];
		sprintf(log,"GetFirstFriendsGroupMember() iGroupID=0x%X ",
			iGroupID		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetFirstFriendsGroupMember(iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetNextFriendsGroupMember ( int16 iGroupID )	{
		char log[1024];
		sprintf(log,"GetNextFriendsGroupMember() iGroupID=0x%X ",
			iGroupID		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetNextFriendsGroupMember(iGroupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int16  GetGroupFriendsMembershipCount ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetGroupFriendsMembershipCount() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		int16  ret = m_pWrapper->GetGroupFriendsMembershipCount(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int16  GetFirstGroupFriendsMember ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFirstGroupFriendsMember() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		int16  ret = m_pWrapper->GetFirstGroupFriendsMember(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int16  GetNextGroupFriendsMember ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetNextGroupFriendsMember() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		int16  ret = m_pWrapper->GetNextGroupFriendsMember(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetChatMessage ( CSteamID steamIDFriend,  int iChatID,  void *pvData,  int cubData,  EChatEntryType *peChatEntryType,  CSteamID* pSteamIDChatter )	{
		char log[1024];
		sprintf(log,"GetChatMessage() steamIDFriend=0x%X iChatID=0x%X pvData=0x%X cubData=0x%X peChatEntryType=0x%X pSteamIDChatter=0x%X ",
			steamIDFriend,
			iChatID,
			pvData,
			cubData,
			peChatEntryType,
			pSteamIDChatter		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetChatMessage(steamIDFriend, iChatID, pvData, cubData, peChatEntryType, pSteamIDChatter);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendMsgToFriend ( CSteamID steamIDFriend,  EChatEntryType eChatEntryType,  const void *pvMsgBody,  int cubMsgBody )	{
		char log[1024];
		sprintf(log,"SendMsgToFriend() steamIDFriend=0x%X eChatEntryType=0x%X pvMsgBody=0x%X cubMsgBody=0x%X ",
			steamIDFriend,
			eChatEntryType,
			pvMsgBody,
			cubMsgBody		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendMsgToFriend(steamIDFriend, eChatEntryType, pvMsgBody, cubMsgBody);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ClearChatHistory ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"ClearChatHistory() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		steamIDFriend);
		OutputDebugStringA("\n");
	}
	virtual int  GetKnownClanCount ()	{
		char log[1024];
		sprintf(log,"GetKnownClanCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetKnownClanCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetKnownClanByIndex ( int iClan )	{
		char log[1024];
		sprintf(log,"GetKnownClanByIndex() iClan=0x%X ",
			iClan		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetKnownClanByIndex(iClan);
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
	virtual const char * GetClanName ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetClanName() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetClanName(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetClanTag ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetClanTag() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetClanTag(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFriendActivityCounts ( int *pnOnline,  int *pnInGame,  bool bExcludeTaggedFriends )	{
		char log[1024];
		sprintf(log,"GetFriendActivityCounts() pnOnline=0x%X pnInGame=0x%X bExcludeTaggedFriends=0x%X ",
			pnOnline,
			pnInGame,
			bExcludeTaggedFriends		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFriendActivityCounts(pnOnline, pnInGame, bExcludeTaggedFriends);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetClanActivityCounts ( CSteamID steamID,  int *pnOnline,  int *pnInGame,  int *pnChatting )	{
		char log[1024];
		sprintf(log,"GetClanActivityCounts() steamID=0x%X pnOnline=0x%X pnInGame=0x%X pnChatting=0x%X ",
			steamID,
			pnOnline,
			pnInGame,
			pnChatting		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetClanActivityCounts(steamID, pnOnline, pnInGame, pnChatting);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  DownloadClanActivityCounts ( CSteamID groupIDs[],  int nIds )	{
		char log[1024];
		sprintf(log,"DownloadClanActivityCounts() groupIDs[]=0x%X nIds=0x%X ",
			groupIDs[],
			nIds		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->DownloadClanActivityCounts(groupIDs[], nIds);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFriendsGroupActivityCounts ( int16 iGroupID,  int *pnOnline,  int *pnInGame )	{
		char log[1024];
		sprintf(log,"GetFriendsGroupActivityCounts() iGroupID=0x%X pnOnline=0x%X pnInGame=0x%X ",
			iGroupID,
			pnOnline,
			pnInGame		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFriendsGroupActivityCounts(iGroupID, pnOnline, pnInGame);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsClanPublic ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"IsClanPublic() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsClanPublic(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsClanLarge ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"IsClanLarge() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsClanLarge(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SubscribeToPersonaStateFeed ( CSteamID,  bool )	{
		char log[1024];
		sprintf(log,"SubscribeToPersonaStateFeed() CSteamID=0x%X bool=0x%X ",
			CSteamID,
			bool		);
		OutputDebugStringA(log);
		CSteamID, bool);
		OutputDebugStringA("\n");
	}
	virtual SteamAPICall_t  JoinClanChatRoom ( CSteamID groupID )	{
		char log[1024];
		sprintf(log,"JoinClanChatRoom() groupID=0x%X ",
			groupID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->JoinClanChatRoom(groupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  LeaveClanChatRoom ( CSteamID groupID )	{
		char log[1024];
		sprintf(log,"LeaveClanChatRoom() groupID=0x%X ",
			groupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->LeaveClanChatRoom(groupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetClanChatMemberCount ( CSteamID groupID )	{
		char log[1024];
		sprintf(log,"GetClanChatMemberCount() groupID=0x%X ",
			groupID		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetClanChatMemberCount(groupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetChatMemberByIndex ( CSteamID groupID,  int iIndex )	{
		char log[1024];
		sprintf(log,"GetChatMemberByIndex() groupID=0x%X iIndex=0x%X ",
			groupID,
			iIndex		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetChatMemberByIndex(groupID, iIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendClanChatMessage ( CSteamID groupID,  const char *cszMessage )	{
		char log[1024];
		sprintf(log,"SendClanChatMessage() groupID=0x%X cszMessage=%s ",
			groupID,
			cszMessage		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendClanChatMessage(groupID, cszMessage);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetClanChatMessage ( CSteamID groupID,  int iChatID,  void *pvData,  int cubData,  EChatEntryType *peChatEntryType,  CSteamID *pSteamIDChatter )	{
		char log[1024];
		sprintf(log,"GetClanChatMessage() groupID=0x%X iChatID=0x%X pvData=0x%X cubData=0x%X peChatEntryType=0x%X pSteamIDChatter=0x%X ",
			groupID,
			iChatID,
			pvData,
			cubData,
			peChatEntryType,
			pSteamIDChatter		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetClanChatMessage(groupID, iChatID, pvData, cubData, peChatEntryType, pSteamIDChatter);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsClanChatAdmin ( CSteamID groupID,  CSteamID userID )	{
		char log[1024];
		sprintf(log,"IsClanChatAdmin() groupID=0x%X userID=0x%X ",
			groupID,
			userID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsClanChatAdmin(groupID, userID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsClanChatWindowOpenInSteam ( CSteamID groupID )	{
		char log[1024];
		sprintf(log,"IsClanChatWindowOpenInSteam() groupID=0x%X ",
			groupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsClanChatWindowOpenInSteam(groupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  OpenClanChatWindowInSteam ( CSteamID groupID )	{
		char log[1024];
		sprintf(log,"OpenClanChatWindowInSteam() groupID=0x%X ",
			groupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->OpenClanChatWindowInSteam(groupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  CloseClanChatWindowInSteam ( CSteamID groupID )	{
		char log[1024];
		sprintf(log,"CloseClanChatWindowInSteam() groupID=0x%X ",
			groupID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->CloseClanChatWindowInSteam(groupID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetListenForFriendsMessages ( bool bListen )	{
		char log[1024];
		sprintf(log,"SetListenForFriendsMessages() bListen=0x%X ",
			bListen		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetListenForFriendsMessages(bListen);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ReplyToFriendMessage ( CSteamID friendID,  const char *cszMessage )	{
		char log[1024];
		sprintf(log,"ReplyToFriendMessage() friendID=0x%X cszMessage=%s ",
			friendID,
			cszMessage		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ReplyToFriendMessage(friendID, cszMessage);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetFriendMessage ( CSteamID friendID,  int iChatID,  void *pvData,  int cubData,  EChatEntryType *peChatEntryType )	{
		char log[1024];
		sprintf(log,"GetFriendMessage() friendID=0x%X iChatID=0x%X pvData=0x%X cubData=0x%X peChatEntryType=0x%X ",
			friendID,
			iChatID,
			pvData,
			cubData,
			peChatEntryType		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFriendMessage(friendID, iChatID, pvData, cubData, peChatEntryType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  InviteFriendToClan ( CSteamID steamIDfriend,  CSteamID steamIDclan )	{
		char log[1024];
		sprintf(log,"InviteFriendToClan() steamIDfriend=0x%X steamIDclan=0x%X ",
			steamIDfriend,
			steamIDclan		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InviteFriendToClan(steamIDfriend, steamIDclan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  AcknowledgeInviteToClan ( CSteamID steamID,  bool bAcceptOrDenyClanInvite )	{
		char log[1024];
		sprintf(log,"AcknowledgeInviteToClan() steamID=0x%X bAcceptOrDenyClanInvite=0x%X ",
			steamID,
			bAcceptOrDenyClanInvite		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AcknowledgeInviteToClan(steamID, bAcceptOrDenyClanInvite);
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
	virtual CSteamID  GetCoplayFriend ( int32 iIndex )	{
		char log[1024];
		sprintf(log,"GetCoplayFriend() iIndex=0x%X ",
			iIndex		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetCoplayFriend(iIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual RTime32  GetFriendCoplayTime ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendCoplayTime() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetFriendCoplayTime(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual AppId_t  GetFriendCoplayGame ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendCoplayGame() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		AppId_t  ret = m_pWrapper->GetFriendCoplayGame(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetRichPresence ( AppId_t nAppId,  const char *szKey,  const char *szValue )	{
		char log[1024];
		sprintf(log,"SetRichPresence() nAppId=0x%X szKey=%s szValue=%s ",
			nAppId,
			szKey,
			szValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetRichPresence(nAppId, szKey, szValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ClearRichPresence ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"ClearRichPresence() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		nAppId);
		OutputDebugStringA("\n");
	}
	virtual const char*  GetFriendRichPresence ( AppId_t nAppId,  CSteamID steamIDFriend,  const char *szKey )	{
		char log[1024];
		sprintf(log,"GetFriendRichPresence() nAppId=0x%X steamIDFriend=0x%X szKey=%s ",
			nAppId,
			steamIDFriend,
			szKey		);
		OutputDebugStringA(log);
		const char*  ret = m_pWrapper->GetFriendRichPresence(nAppId, steamIDFriend, szKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int32  GetFriendRichPresenceKeyCount ( AppId_t nAppId,  CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetFriendRichPresenceKeyCount() nAppId=0x%X steamIDFriend=0x%X ",
			nAppId,
			steamIDFriend		);
		OutputDebugStringA(log);
		int32  ret = m_pWrapper->GetFriendRichPresenceKeyCount(nAppId, steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char*  GetFriendRichPresenceKeyByIndex ( AppId_t nAppId,  CSteamID steamIDFriend,  int32 iIndex )	{
		char log[1024];
		sprintf(log,"GetFriendRichPresenceKeyByIndex() nAppId=0x%X steamIDFriend=0x%X iIndex=0x%X ",
			nAppId,
			steamIDFriend,
			iIndex		);
		OutputDebugStringA(log);
		const char*  ret = m_pWrapper->GetFriendRichPresenceKeyByIndex(nAppId, steamIDFriend, iIndex);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RequestFriendRichPresence ( AppId_t nAppId,  CSteamID steamID )	{
		char log[1024];
		sprintf(log,"RequestFriendRichPresence() nAppId=0x%X steamID=0x%X ",
			nAppId,
			steamID		);
		OutputDebugStringA(log);
		nAppId, steamID);
		OutputDebugStringA("\n");
	}
	virtual bool  JoinChatRoom ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"JoinChatRoom() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->JoinChatRoom(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  LeaveChatRoom ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"LeaveChatRoom() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		steamID);
		OutputDebugStringA("\n");
	}
	virtual bool  InviteUserToChatRoom ( CSteamID steamIDfriend,  CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"InviteUserToChatRoom() steamIDfriend=0x%X steamIDchat=0x%X ",
			steamIDfriend,
			steamIDchat		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InviteUserToChatRoom(steamIDfriend, steamIDchat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendChatMsg ( CSteamID steamIDchat,  EChatEntryType eChatEntryType,  const void *pvMsgBody,  int cubMsgBody )	{
		char log[1024];
		sprintf(log,"SendChatMsg() steamIDchat=0x%X eChatEntryType=0x%X pvMsgBody=0x%X cubMsgBody=0x%X ",
			steamIDchat,
			eChatEntryType,
			pvMsgBody,
			cubMsgBody		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendChatMsg(steamIDchat, eChatEntryType, pvMsgBody, cubMsgBody);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetChatRoomEntry ( CSteamID steamIDchat,  int iChatID,  CSteamID *steamIDuser,  void *pvData,  int cubData,  EChatEntryType *peChatEntryType )	{
		char log[1024];
		sprintf(log,"GetChatRoomEntry() steamIDchat=0x%X iChatID=0x%X steamIDuser=0x%X pvData=0x%X cubData=0x%X peChatEntryType=0x%X ",
			steamIDchat,
			iChatID,
			steamIDuser,
			pvData,
			cubData,
			peChatEntryType		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetChatRoomEntry(steamIDchat, iChatID, steamIDuser, pvData, cubData, peChatEntryType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ClearChatRoomHistory ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"ClearChatRoomHistory() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		steamID);
		OutputDebugStringA("\n");
	}
	virtual bool  SerializeChatRoomDlg ( CSteamID steamIDchat,  void const* pvHistory,  int cubHistory )	{
		char log[1024];
		sprintf(log,"SerializeChatRoomDlg() steamIDchat=0x%X pvHistory=0x%X cubHistory=0x%X ",
			steamIDchat,
			pvHistory,
			cubHistory		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SerializeChatRoomDlg(steamIDchat, pvHistory, cubHistory);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetSizeOfSerializedChatRoomDlg ( CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"GetSizeOfSerializedChatRoomDlg() steamIDchat=0x%X ",
			steamIDchat		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetSizeOfSerializedChatRoomDlg(steamIDchat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetSerializedChatRoomDlg ( CSteamID steamIDchat,  void* pvHistory,  int cubBuffer,  int* pcubData )	{
		char log[1024];
		sprintf(log,"GetSerializedChatRoomDlg() steamIDchat=0x%X pvHistory=0x%X cubBuffer=0x%X pcubData=0x%X ",
			steamIDchat,
			pvHistory,
			cubBuffer,
			pcubData		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetSerializedChatRoomDlg(steamIDchat, pvHistory, cubBuffer, pcubData);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  ClearSerializedChatRoomDlg ( CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"ClearSerializedChatRoomDlg() steamIDchat=0x%X ",
			steamIDchat		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->ClearSerializedChatRoomDlg(steamIDchat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  KickChatMember ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"KickChatMember() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->KickChatMember(steamIDchat, steamIDuser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BanChatMember ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"BanChatMember() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BanChatMember(steamIDchat, steamIDuser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  UnBanChatMember ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"UnBanChatMember() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->UnBanChatMember(steamIDchat, steamIDuser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetChatRoomType ( CSteamID steamIDchat,  ELobbyType eLobbyType )	{
		char log[1024];
		sprintf(log,"SetChatRoomType() steamIDchat=0x%X eLobbyType=0x%X ",
			steamIDchat,
			eLobbyType		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetChatRoomType(steamIDchat, eLobbyType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetChatRoomLockState ( CSteamID steamIDchat,  bool *pbLocked )	{
		char log[1024];
		sprintf(log,"GetChatRoomLockState() steamIDchat=0x%X pbLocked=0x%X ",
			steamIDchat,
			pbLocked		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetChatRoomLockState(steamIDchat, pbLocked);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetChatRoomPermissions ( CSteamID steamIDchat,  uint32 *prgfChatRoomPermissions )	{
		char log[1024];
		sprintf(log,"GetChatRoomPermissions() steamIDchat=0x%X prgfChatRoomPermissions=0x%X ",
			steamIDchat,
			prgfChatRoomPermissions		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetChatRoomPermissions(steamIDchat, prgfChatRoomPermissions);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetChatRoomModerated ( CSteamID steamIDchat,  bool bModerated )	{
		char log[1024];
		sprintf(log,"SetChatRoomModerated() steamIDchat=0x%X bModerated=0x%X ",
			steamIDchat,
			bModerated		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetChatRoomModerated(steamIDchat, bModerated);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BChatRoomModerated ( CSteamID steamIDChat )	{
		char log[1024];
		sprintf(log,"BChatRoomModerated() steamIDChat=0x%X ",
			steamIDChat		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BChatRoomModerated(steamIDChat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  NotifyChatRoomDlgsOfUIChange ( CSteamID steamIDchat,  bool bShowAvatars,  bool bBeepOnNewMsg,  bool bShowSteamIDs,  bool bShowTimestampOnNewMsg )	{
		char log[1024];
		sprintf(log,"NotifyChatRoomDlgsOfUIChange() steamIDchat=0x%X bShowAvatars=0x%X bBeepOnNewMsg=0x%X bShowSteamIDs=0x%X bShowTimestampOnNewMsg=0x%X ",
			steamIDchat,
			bShowAvatars,
			bBeepOnNewMsg,
			bShowSteamIDs,
			bShowTimestampOnNewMsg		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->NotifyChatRoomDlgsOfUIChange(steamIDchat, bShowAvatars, bBeepOnNewMsg, bShowSteamIDs, bShowTimestampOnNewMsg);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  TerminateChatRoom ( CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"TerminateChatRoom() steamIDchat=0x%X ",
			steamIDchat		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->TerminateChatRoom(steamIDchat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetChatRoomCount ()	{
		char log[1024];
		sprintf(log,"GetChatRoomCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetChatRoomCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetChatRoomByIndex ( int iChatRoom )	{
		char log[1024];
		sprintf(log,"GetChatRoomByIndex() iChatRoom=0x%X ",
			iChatRoom		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetChatRoomByIndex(iChatRoom);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetChatRoomName ( CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"GetChatRoomName() steamIDchat=0x%X ",
			steamIDchat		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetChatRoomName(steamIDchat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BGetChatRoomMemberDetails ( CSteamID steamIDchat,  CSteamID steamIDuser,  uint32* pChatMemberDetails,  uint32* pChatMemberDetailsLocal )	{
		char log[1024];
		sprintf(log,"BGetChatRoomMemberDetails() steamIDchat=0x%X steamIDuser=0x%X pChatMemberDetails=0x%X pChatMemberDetailsLocal=0x%X ",
			steamIDchat,
			steamIDuser,
			pChatMemberDetails,
			pChatMemberDetailsLocal		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BGetChatRoomMemberDetails(steamIDchat, steamIDuser, pChatMemberDetails, pChatMemberDetailsLocal);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  CreateChatRoom ( EChatRoomType eType,  uint64 ulGameID,  const char *pchName,  ELobbyType eLobbyType,  CSteamID steamIDClan,  CSteamID steamIDFriendChat,  CSteamID steamIDInvited,  uint32 chatPermissionOfficer,  uint32 chatPermissionMember,  uint32 chatPermissionAll )	{
		char log[1024];
		sprintf(log,"CreateChatRoom() eType=0x%X ulGameID=0x%X pchName=%s eLobbyType=0x%X steamIDClan=0x%X steamIDFriendChat=0x%X steamIDInvited=0x%X chatPermissionOfficer=0x%X chatPermissionMember=0x%X chatPermissionAll=0x%X ",
			eType,
			ulGameID,
			pchName,
			eLobbyType,
			steamIDClan,
			steamIDFriendChat,
			steamIDInvited,
			chatPermissionOfficer,
			chatPermissionMember,
			chatPermissionAll		);
		OutputDebugStringA(log);
		eType, ulGameID, pchName, eLobbyType, steamIDClan, steamIDFriendChat, steamIDInvited, chatPermissionOfficer, chatPermissionMember, chatPermissionAll);
		OutputDebugStringA("\n");
	}
	virtual void  VoiceCall ( CSteamID steamIDlocal,  CSteamID steamIDremote )	{
		char log[1024];
		sprintf(log,"VoiceCall() steamIDlocal=0x%X steamIDremote=0x%X ",
			steamIDlocal,
			steamIDremote		);
		OutputDebugStringA(log);
		steamIDlocal, steamIDremote);
		OutputDebugStringA("\n");
	}
	virtual void  VoiceHangUp ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"VoiceHangUp() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		hVoiceCall);
		OutputDebugStringA("\n");
	}
	virtual bool  SetVoiceSpeakerVolume ( float flVolume )	{
		char log[1024];
		sprintf(log,"SetVoiceSpeakerVolume() flVolume=0x%X ",
			flVolume		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetVoiceSpeakerVolume(flVolume);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetVoiceMicrophoneVolume ( float flVolume )	{
		char log[1024];
		sprintf(log,"SetVoiceMicrophoneVolume() flVolume=0x%X ",
			flVolume		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetVoiceMicrophoneVolume(flVolume);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetAutoAnswer ( bool bAutoAnswer )	{
		char log[1024];
		sprintf(log,"SetAutoAnswer() bAutoAnswer=0x%X ",
			bAutoAnswer		);
		OutputDebugStringA(log);
		bAutoAnswer);
		OutputDebugStringA("\n");
	}
	virtual void  VoiceAnswer ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"VoiceAnswer() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		hVoiceCall);
		OutputDebugStringA("\n");
	}
	virtual void  VoicePutOnHold ( HVoiceCall HVoiceCall,  bool bOnLocalHold )	{
		char log[1024];
		sprintf(log,"VoicePutOnHold() HVoiceCall=0x%X bOnLocalHold=0x%X ",
			HVoiceCall,
			bOnLocalHold		);
		OutputDebugStringA(log);
		HVoiceCall, bOnLocalHold);
		OutputDebugStringA("\n");
	}
	virtual bool  BVoiceIsLocalOnHold ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"BVoiceIsLocalOnHold() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BVoiceIsLocalOnHold(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BVoiceIsRemoteOnHold ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"BVoiceIsRemoteOnHold() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BVoiceIsRemoteOnHold(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetDoNotDisturb ( bool bDoNotDisturb )	{
		char log[1024];
		sprintf(log,"SetDoNotDisturb() bDoNotDisturb=0x%X ",
			bDoNotDisturb		);
		OutputDebugStringA(log);
		bDoNotDisturb);
		OutputDebugStringA("\n");
	}
	virtual void  EnableVoiceNotificationSounds ( bool bEnable )	{
		char log[1024];
		sprintf(log,"EnableVoiceNotificationSounds() bEnable=0x%X ",
			bEnable		);
		OutputDebugStringA(log);
		bEnable);
		OutputDebugStringA("\n");
	}
	virtual void  SetPushToTalkEnabled ( bool bEnabled )	{
		char log[1024];
		sprintf(log,"SetPushToTalkEnabled() bEnabled=0x%X ",
			bEnabled		);
		OutputDebugStringA(log);
		bEnabled);
		OutputDebugStringA("\n");
	}
	virtual bool  IsPushToTalkEnabled ()	{
		char log[1024];
		sprintf(log,"IsPushToTalkEnabled() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsPushToTalkEnabled();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetPushToTalkKey ( int nKey )	{
		char log[1024];
		sprintf(log,"SetPushToTalkKey() nKey=0x%X ",
			nKey		);
		OutputDebugStringA(log);
		nKey);
		OutputDebugStringA("\n");
	}
	virtual int  GetPushToTalkKey ()	{
		char log[1024];
		sprintf(log,"GetPushToTalkKey() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetPushToTalkKey();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  IsPushToTalkKeyDown ()	{
		char log[1024];
		sprintf(log,"IsPushToTalkKeyDown() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsPushToTalkKeyDown();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  EnableVoiceCalibration ( bool bEnable )	{
		char log[1024];
		sprintf(log,"EnableVoiceCalibration() bEnable=0x%X ",
			bEnable		);
		OutputDebugStringA(log);
		bEnable);
		OutputDebugStringA("\n");
	}
	virtual bool  IsVoiceCalibrating ()	{
		char log[1024];
		sprintf(log,"IsVoiceCalibrating() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsVoiceCalibrating();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  GetVoiceCalibrationSamplePeak ()	{
		char log[1024];
		sprintf(log,"GetVoiceCalibrationSamplePeak() "		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->GetVoiceCalibrationSamplePeak();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetMicBoost ( bool bBoost )	{
		char log[1024];
		sprintf(log,"SetMicBoost() bBoost=0x%X ",
			bBoost		);
		OutputDebugStringA(log);
		bBoost);
		OutputDebugStringA("\n");
	}
	virtual bool  GetMicBoost ()	{
		char log[1024];
		sprintf(log,"GetMicBoost() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetMicBoost();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  HasHardwareMicBoost ()	{
		char log[1024];
		sprintf(log,"HasHardwareMicBoost() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HasHardwareMicBoost();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetMicDeviceName ()	{
		char log[1024];
		sprintf(log,"GetMicDeviceName() "		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetMicDeviceName();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  StartTalking ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"StartTalking() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		hVoiceCall);
		OutputDebugStringA("\n");
	}
	virtual void  EndTalking ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"EndTalking() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		hVoiceCall);
		OutputDebugStringA("\n");
	}
	virtual bool  VoiceIsValid ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"VoiceIsValid() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->VoiceIsValid(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetAutoReflectVoice ( bool bAuto )	{
		char log[1024];
		sprintf(log,"SetAutoReflectVoice() bAuto=0x%X ",
			bAuto		);
		OutputDebugStringA(log);
		bAuto);
		OutputDebugStringA("\n");
	}
	virtual ECallState  GetCallState ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"GetCallState() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		ECallState  ret = m_pWrapper->GetCallState(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  GetVoiceMicrophoneVolume ()	{
		char log[1024];
		sprintf(log,"GetVoiceMicrophoneVolume() "		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->GetVoiceMicrophoneVolume();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  GetVoiceSpeakerVolume ()	{
		char log[1024];
		sprintf(log,"GetVoiceSpeakerVolume() "		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->GetVoiceSpeakerVolume();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  TimeSinceLastVoiceDataReceived ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"TimeSinceLastVoiceDataReceived() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->TimeSinceLastVoiceDataReceived(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  TimeSinceLastVoiceDataSend ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"TimeSinceLastVoiceDataSend() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->TimeSinceLastVoiceDataSend(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BCanSend ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"BCanSend() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BCanSend(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BCanReceive ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"BCanReceive() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BCanReceive(hVoiceCall);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  GetEstimatedBitsPerSecond ( HVoiceCall hVoiceCall,  bool bIncoming )	{
		char log[1024];
		sprintf(log,"GetEstimatedBitsPerSecond() hVoiceCall=0x%X bIncoming=0x%X ",
			hVoiceCall,
			bIncoming		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->GetEstimatedBitsPerSecond(hVoiceCall, bIncoming);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  GetPeakSample ( HVoiceCall hVoiceCall,  bool bIncoming )	{
		char log[1024];
		sprintf(log,"GetPeakSample() hVoiceCall=0x%X bIncoming=0x%X ",
			hVoiceCall,
			bIncoming		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->GetPeakSample(hVoiceCall, bIncoming);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SendResumeRequest ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"SendResumeRequest() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		hVoiceCall);
		OutputDebugStringA("\n");
	}
	virtual void  OpenChatDialog ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"OpenChatDialog() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		steamID);
		OutputDebugStringA("\n");
	}
	virtual void  StartChatRoomVoiceSpeaking ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"StartChatRoomVoiceSpeaking() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		steamIDchat, steamIDuser);
		OutputDebugStringA("\n");
	}
	virtual void  EndChatRoomVoiceSpeaking ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"EndChatRoomVoiceSpeaking() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		steamIDchat, steamIDuser);
		OutputDebugStringA("\n");
	}
	virtual RTime32  GetFriendLastLogonTime ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendLastLogonTime() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetFriendLastLogonTime(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual RTime32  GetFriendLastLogoffTime ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"GetFriendLastLogoffTime() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		RTime32  ret = m_pWrapper->GetFriendLastLogoffTime(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetChatRoomVoiceTotalSlotCount ( CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"GetChatRoomVoiceTotalSlotCount() steamIDchat=0x%X ",
			steamIDchat		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetChatRoomVoiceTotalSlotCount(steamIDchat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetChatRoomVoiceUsedSlotCount ( CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"GetChatRoomVoiceUsedSlotCount() steamIDchat=0x%X ",
			steamIDchat		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetChatRoomVoiceUsedSlotCount(steamIDchat);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetChatRoomVoiceUsedSlot ( CSteamID steamID,  int iSlot )	{
		char log[1024];
		sprintf(log,"GetChatRoomVoiceUsedSlot() steamID=0x%X iSlot=0x%X ",
			steamID,
			iSlot		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetChatRoomVoiceUsedSlot(steamID, iSlot);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EChatRoomVoiceStatus  GetChatRoomVoiceStatus ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"GetChatRoomVoiceStatus() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		EChatRoomVoiceStatus  ret = m_pWrapper->GetChatRoomVoiceStatus(steamIDchat, steamIDuser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BChatRoomHasAvailableVoiceSlots ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"BChatRoomHasAvailableVoiceSlots() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BChatRoomHasAvailableVoiceSlots(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  BIsChatRoomVoiceSpeaking ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"BIsChatRoomVoiceSpeaking() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->BIsChatRoomVoiceSpeaking(steamIDchat, steamIDuser);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual float  GetChatRoomPeakSample ( CSteamID steamIDchat,  CSteamID steamIDuser,  bool bIncoming )	{
		char log[1024];
		sprintf(log,"GetChatRoomPeakSample() steamIDchat=0x%X steamIDuser=0x%X bIncoming=0x%X ",
			steamIDchat,
			steamIDuser,
			bIncoming		);
		OutputDebugStringA(log);
		float  ret = m_pWrapper->GetChatRoomPeakSample(steamIDchat, steamIDuser, bIncoming);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  ChatRoomVoiceRetryConnections ( CSteamID steamIDchat )	{
		char log[1024];
		sprintf(log,"ChatRoomVoiceRetryConnections() steamIDchat=0x%X ",
			steamIDchat		);
		OutputDebugStringA(log);
		steamIDchat);
		OutputDebugStringA("\n");
	}
	virtual void  SetPortTypes ( uint32 unFlags )	{
		char log[1024];
		sprintf(log,"SetPortTypes() unFlags=0x%X ",
			unFlags		);
		OutputDebugStringA(log);
		unFlags);
		OutputDebugStringA("\n");
	}
	virtual void  ReinitAudio ()	{
		char log[1024];
		sprintf(log,"ReinitAudio() "		);
		OutputDebugStringA(log);
		);
		OutputDebugStringA("\n");
	}
	virtual void  SetInGameVoiceSpeaking ( CSteamID steamIDuser,  bool bIsSpeaking )	{
		char log[1024];
		sprintf(log,"SetInGameVoiceSpeaking() steamIDuser=0x%X bIsSpeaking=0x%X ",
			steamIDuser,
			bIsSpeaking		);
		OutputDebugStringA(log);
		steamIDuser, bIsSpeaking);
		OutputDebugStringA("\n");
	}
	virtual bool  IsInGameVoiceSpeaking ()	{
		char log[1024];
		sprintf(log,"IsInGameVoiceSpeaking() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->IsInGameVoiceSpeaking();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
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
	virtual void  ActivateGameOverlayToWebPage ( const char *pchUrl )	{
		char log[1024];
		sprintf(log,"ActivateGameOverlayToWebPage() pchUrl=%s ",
			pchUrl		);
		OutputDebugStringA(log);
		pchUrl);
		OutputDebugStringA("\n");
	}
	virtual void  ActivateGameOverlayToStore ( AppId_t nAppId )	{
		char log[1024];
		sprintf(log,"ActivateGameOverlayToStore() nAppId=0x%X ",
			nAppId		);
		OutputDebugStringA(log);
		nAppId);
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
	virtual void  NotifyGameOverlayStateChanged ( bool bActive )	{
		char log[1024];
		sprintf(log,"NotifyGameOverlayStateChanged() bActive=0x%X ",
			bActive		);
		OutputDebugStringA(log);
		bActive);
		OutputDebugStringA("\n");
	}
	virtual void  NotifyGameServerChangeRequested ( const char *pchServerAddress,  const char *pchPassword )	{
		char log[1024];
		sprintf(log,"NotifyGameServerChangeRequested() pchServerAddress=%s pchPassword=%s ",
			pchServerAddress,
			pchPassword		);
		OutputDebugStringA(log);
		pchServerAddress, pchPassword);
		OutputDebugStringA("\n");
	}
	virtual bool  NotifyLobbyJoinRequested ( AppId_t nAppId,  CSteamID steamIDlobby,  CSteamID steamIDfriend )	{
		char log[1024];
		sprintf(log,"NotifyLobbyJoinRequested() nAppId=0x%X steamIDlobby=0x%X steamIDfriend=0x%X ",
			nAppId,
			steamIDlobby,
			steamIDfriend		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->NotifyLobbyJoinRequested(nAppId, steamIDlobby, steamIDfriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  NotifyRichPresenceJoinRequested ( AppId_t nAppId,  CSteamID steamID,  const char *szUnk )	{
		char log[1024];
		sprintf(log,"NotifyRichPresenceJoinRequested() nAppId=0x%X steamID=0x%X szUnk=%s ",
			nAppId,
			steamID,
			szUnk		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->NotifyRichPresenceJoinRequested(nAppId, steamID, szUnk);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EClanRelationship  GetClanRelationship ( CSteamID steamIDclan )	{
		char log[1024];
		sprintf(log,"GetClanRelationship() steamIDclan=0x%X ",
			steamIDclan		);
		OutputDebugStringA(log);
		EClanRelationship  ret = m_pWrapper->GetClanRelationship(steamIDclan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual EClanRank  GetFriendClanRank ( CSteamID steamIDuser,  CSteamID steamIDclan )	{
		char log[1024];
		sprintf(log,"GetFriendClanRank() steamIDuser=0x%X steamIDclan=0x%X ",
			steamIDuser,
			steamIDclan		);
		OutputDebugStringA(log);
		EClanRank  ret = m_pWrapper->GetFriendClanRank(steamIDuser, steamIDclan);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  VoiceIsAvailable ()	{
		char log[1024];
		sprintf(log,"VoiceIsAvailable() "		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->VoiceIsAvailable();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  TestVoiceDisconnect ( HVoiceCall hVoiceCall )	{
		char log[1024];
		sprintf(log,"TestVoiceDisconnect() hVoiceCall=0x%X ",
			hVoiceCall		);
		OutputDebugStringA(log);
		hVoiceCall);
		OutputDebugStringA("\n");
	}
	virtual void  TestChatRoomPeerDisconnect ( CSteamID steamIDchat,  CSteamID steamIDuser )	{
		char log[1024];
		sprintf(log,"TestChatRoomPeerDisconnect() steamIDchat=0x%X steamIDuser=0x%X ",
			steamIDchat,
			steamIDuser		);
		OutputDebugStringA(log);
		steamIDchat, steamIDuser);
		OutputDebugStringA("\n");
	}
	virtual void  TestVoicePacketLoss ( float flPacketDropFraction )	{
		char log[1024];
		sprintf(log,"TestVoicePacketLoss() flPacketDropFraction=0x%X ",
			flPacketDropFraction		);
		OutputDebugStringA(log);
		flPacketDropFraction);
		OutputDebugStringA("\n");
	}
	virtual HVoiceCall  FindFriendVoiceChatHandle ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"FindFriendVoiceChatHandle() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		HVoiceCall  ret = m_pWrapper->FindFriendVoiceChatHandle(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  RequestFriendsWhoPlayGame ( CGameID gameId )	{
		char log[1024];
		sprintf(log,"RequestFriendsWhoPlayGame() gameId=0x%X ",
			gameId		);
		OutputDebugStringA(log);
		gameId);
		OutputDebugStringA("\n");
	}
	virtual uint32  GetCountFriendsWhoPlayGame ( CGameID gameId )	{
		char log[1024];
		sprintf(log,"GetCountFriendsWhoPlayGame() gameId=0x%X ",
			gameId		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetCountFriendsWhoPlayGame(gameId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetFriendWhoPlaysGame ( uint32 ,  CGameID gameId )	{
		char log[1024];
		sprintf(log,"GetFriendWhoPlaysGame() uint32=0x%X gameId=0x%X ",
			uint32,
			gameId		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetFriendWhoPlaysGame(uint32, gameId);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetPlayedWith ( CSteamID steamId )	{
		char log[1024];
		sprintf(log,"SetPlayedWith() steamId=0x%X ",
			steamId		);
		OutputDebugStringA(log);
		steamId);
		OutputDebugStringA("\n");
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
	virtual SteamAPICall_t  RequestFriendProfileInfo ( CSteamID friendID )	{
		char log[1024];
		sprintf(log,"RequestFriendProfileInfo() friendID=0x%X ",
			friendID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestFriendProfileInfo(friendID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char*  GetFriendProfileInfo ( CSteamID friendID,  const char* szKey )	{
		char log[1024];
		sprintf(log,"GetFriendProfileInfo() friendID=0x%X szKey=%s ",
			friendID,
			szKey		);
		OutputDebugStringA(log);
		const char*  ret = m_pWrapper->GetFriendProfileInfo(friendID, szKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  InviteUserToGame ( CSteamID steamID,  const char *pchConnectString )	{
		char log[1024];
		sprintf(log,"InviteUserToGame() steamID=0x%X pchConnectString=%s ",
			steamID,
			pchConnectString		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InviteUserToGame(steamID, pchConnectString);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetOnlineConsoleFriendCount ()	{
		char log[1024];
		sprintf(log,"GetOnlineConsoleFriendCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetOnlineConsoleFriendCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestTrade ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"RequestTrade() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestTrade(steamID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  TradeResponse ( unsigned int,  bool )	{
		char log[1024];
		sprintf(log,"TradeResponse() int=0x%X bool=0x%X ",
			int,
			bool		);
		OutputDebugStringA(log);
		int, bool);
		OutputDebugStringA("\n");
	}
	virtual void  CancelTradeRequest ( CSteamID steamID )	{
		char log[1024];
		sprintf(log,"CancelTradeRequest() steamID=0x%X ",
			steamID		);
		OutputDebugStringA(log);
		steamID);
		OutputDebugStringA("\n");
	}
	virtual bool  HideFriend ( CSteamID friendID,  bool bHide )	{
		char log[1024];
		sprintf(log,"HideFriend() friendID=0x%X bHide=0x%X ",
			friendID,
			bHide		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HideFriend(friendID, bHide);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char *  GetFriendFacebookName ( CSteamID friendID )	{
		char log[1024];
		sprintf(log,"GetFriendFacebookName() friendID=0x%X ",
			friendID		);
		OutputDebugStringA(log);
		const char *  ret = m_pWrapper->GetFriendFacebookName(friendID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint64  GetFriendFacebookID ( CSteamID friendID )	{
		char log[1024];
		sprintf(log,"GetFriendFacebookID() friendID=0x%X ",
			friendID		);
		OutputDebugStringA(log);
		uint64  ret = m_pWrapper->GetFriendFacebookID(friendID);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
