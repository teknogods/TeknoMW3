#include "ISteamMatchmaking008.h"

class ISteamMatchmaking008_wrapper
{
public:
	virtual int  GetFavoriteGameCount ()	{
		char log[1024];
		sprintf(log,"GetFavoriteGameCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFavoriteGameCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFavoriteGame ( int iGame,  AppId_t *pnAppID,  uint32 *pnIP,  uint16 *pnConnPort,  uint16 *pnQueryPort,  uint32 *punFlags,  uint32 *pRTime32LastPlayedOnServer )	{
		char log[1024];
		sprintf(log,"GetFavoriteGame() iGame=0x%X pnAppID=0x%X pnIP=0x%X pnConnPort=0x%X pnQueryPort=0x%X punFlags=0x%X pRTime32LastPlayedOnServer=0x%X ",
			iGame,
			pnAppID,
			pnIP,
			pnConnPort,
			pnQueryPort,
			punFlags,
			pRTime32LastPlayedOnServer		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFavoriteGame(iGame, pnAppID, pnIP, pnConnPort, pnQueryPort, punFlags, pRTime32LastPlayedOnServer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  AddFavoriteGame ( AppId_t nAppID,  uint32 nIP,  uint16 nConnPort,  uint16 nQueryPort,  uint32 unFlags,  uint32 rTime32LastPlayedOnServer )	{
		char log[1024];
		sprintf(log,"AddFavoriteGame() nAppID=0x%X nIP=0x%X nConnPort=0x%X nQueryPort=0x%X unFlags=0x%X rTime32LastPlayedOnServer=0x%X ",
			nAppID,
			nIP,
			nConnPort,
			nQueryPort,
			unFlags,
			rTime32LastPlayedOnServer		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->AddFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags, rTime32LastPlayedOnServer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveFavoriteGame ( AppId_t nAppID,  uint32 nIP,  uint16 nConnPort,  uint16 nQueryPort,  uint32 unFlags )	{
		char log[1024];
		sprintf(log,"RemoveFavoriteGame() nAppID=0x%X nIP=0x%X nConnPort=0x%X nQueryPort=0x%X unFlags=0x%X ",
			nAppID,
			nIP,
			nConnPort,
			nQueryPort,
			unFlags		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveFavoriteGame(nAppID, nIP, nConnPort, nQueryPort, unFlags);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  RequestLobbyList ()	{
		char log[1024];
		sprintf(log,"RequestLobbyList() "		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->RequestLobbyList();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  AddRequestLobbyListStringFilter ( const char *pchKeyToMatch,  const char *pchValueToMatch,  ELobbyComparison eComparisonType )	{
		char log[1024];
		sprintf(log,"AddRequestLobbyListStringFilter() pchKeyToMatch=%s pchValueToMatch=%s eComparisonType=0x%X ",
			pchKeyToMatch,
			pchValueToMatch,
			eComparisonType		);
		OutputDebugStringA(log);
		pchKeyToMatch, pchValueToMatch, eComparisonType);
		OutputDebugStringA("\n");
	}
	virtual void  AddRequestLobbyListNumericalFilter ( const char *pchKeyToMatch,  int nValueToMatch,  ELobbyComparison eComparisonType )	{
		char log[1024];
		sprintf(log,"AddRequestLobbyListNumericalFilter() pchKeyToMatch=%s nValueToMatch=0x%X eComparisonType=0x%X ",
			pchKeyToMatch,
			nValueToMatch,
			eComparisonType		);
		OutputDebugStringA(log);
		pchKeyToMatch, nValueToMatch, eComparisonType);
		OutputDebugStringA("\n");
	}
	virtual void  AddRequestLobbyListNearValueFilter ( const char *pchKeyToMatch,  int nValueToBeCloseTo )	{
		char log[1024];
		sprintf(log,"AddRequestLobbyListNearValueFilter() pchKeyToMatch=%s nValueToBeCloseTo=0x%X ",
			pchKeyToMatch,
			nValueToBeCloseTo		);
		OutputDebugStringA(log);
		pchKeyToMatch, nValueToBeCloseTo);
		OutputDebugStringA("\n");
	}
	virtual void  AddRequestLobbyListFilterSlotsAvailable ( int nSlotsAvailable )	{
		char log[1024];
		sprintf(log,"AddRequestLobbyListFilterSlotsAvailable() nSlotsAvailable=0x%X ",
			nSlotsAvailable		);
		OutputDebugStringA(log);
		nSlotsAvailable);
		OutputDebugStringA("\n");
	}
	virtual void  AddRequestLobbyListDistanceFilter ( ELobbyDistanceFilter eLobbyDistanceFilter )	{
		char log[1024];
		sprintf(log,"AddRequestLobbyListDistanceFilter() eLobbyDistanceFilter=0x%X ",
			eLobbyDistanceFilter		);
		OutputDebugStringA(log);
		eLobbyDistanceFilter);
		OutputDebugStringA("\n");
	}
	virtual void  AddRequestLobbyListResultCountFilter ( int cMaxResults )	{
		char log[1024];
		sprintf(log,"AddRequestLobbyListResultCountFilter() cMaxResults=0x%X ",
			cMaxResults		);
		OutputDebugStringA(log);
		cMaxResults);
		OutputDebugStringA("\n");
	}
	virtual CSteamID  GetLobbyByIndex ( int iLobby )	{
		char log[1024];
		sprintf(log,"GetLobbyByIndex() iLobby=0x%X ",
			iLobby		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetLobbyByIndex(iLobby);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  CreateLobby ( ELobbyType eLobbyType,  int cMaxMembers )	{
		char log[1024];
		sprintf(log,"CreateLobby() eLobbyType=0x%X cMaxMembers=0x%X ",
			eLobbyType,
			cMaxMembers		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->CreateLobby(eLobbyType, cMaxMembers);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual SteamAPICall_t  JoinLobby ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"JoinLobby() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		SteamAPICall_t  ret = m_pWrapper->JoinLobby(steamIDLobby);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  LeaveLobby ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"LeaveLobby() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		steamIDLobby);
		OutputDebugStringA("\n");
	}
	virtual bool  InviteUserToLobby ( CSteamID steamIDLobby,  CSteamID steamIDInvitee )	{
		char log[1024];
		sprintf(log,"InviteUserToLobby() steamIDLobby=0x%X steamIDInvitee=0x%X ",
			steamIDLobby,
			steamIDInvitee		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->InviteUserToLobby(steamIDLobby, steamIDInvitee);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetNumLobbyMembers ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"GetNumLobbyMembers() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetNumLobbyMembers(steamIDLobby);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetLobbyMemberByIndex ( CSteamID steamIDLobby,  int iMember )	{
		char log[1024];
		sprintf(log,"GetLobbyMemberByIndex() steamIDLobby=0x%X iMember=0x%X ",
			steamIDLobby,
			iMember		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetLobbyMemberByIndex(steamIDLobby, iMember);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetLobbyData ( CSteamID steamIDLobby,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"GetLobbyData() steamIDLobby=0x%X pchKey=%s ",
			steamIDLobby,
			pchKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetLobbyData(steamIDLobby, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLobbyData ( CSteamID steamIDLobby,  const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetLobbyData() steamIDLobby=0x%X pchKey=%s pchValue=%s ",
			steamIDLobby,
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLobbyData(steamIDLobby, pchKey, pchValue);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetLobbyDataCount ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"GetLobbyDataCount() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetLobbyDataCount(steamIDLobby);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetLobbyDataByIndex ( CSteamID steamIDLobby,  int iLobbyData,  char *pchKey,  int cchKeyBufferSize,  char *pchValue,  int cchValueBufferSize )	{
		char log[1024];
		sprintf(log,"GetLobbyDataByIndex() steamIDLobby=0x%X iLobbyData=0x%X pchKey=%s cchKeyBufferSize=0x%X pchValue=%s cchValueBufferSize=0x%X ",
			steamIDLobby,
			iLobbyData,
			pchKey,
			cchKeyBufferSize,
			pchValue,
			cchValueBufferSize		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLobbyDataByIndex(steamIDLobby, iLobbyData, pchKey, cchKeyBufferSize, pchValue, cchValueBufferSize);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  DeleteLobbyData ( CSteamID steamIDLobby,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"DeleteLobbyData() steamIDLobby=0x%X pchKey=%s ",
			steamIDLobby,
			pchKey		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->DeleteLobbyData(steamIDLobby, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual const char * GetLobbyMemberData ( CSteamID steamIDLobby,  CSteamID steamIDUser,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"GetLobbyMemberData() steamIDLobby=0x%X steamIDUser=0x%X pchKey=%s ",
			steamIDLobby,
			steamIDUser,
			pchKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetLobbyMemberData(steamIDLobby, steamIDUser, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetLobbyMemberData ( CSteamID steamIDLobby,  const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetLobbyMemberData() steamIDLobby=0x%X pchKey=%s pchValue=%s ",
			steamIDLobby,
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		steamIDLobby, pchKey, pchValue);
		OutputDebugStringA("\n");
	}
	virtual bool  SendLobbyChatMsg ( CSteamID steamIDLobby,  const void *pvMsgBody,  int cubMsgBody )	{
		char log[1024];
		sprintf(log,"SendLobbyChatMsg() steamIDLobby=0x%X pvMsgBody=0x%X cubMsgBody=0x%X ",
			steamIDLobby,
			pvMsgBody,
			cubMsgBody		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendLobbyChatMsg(steamIDLobby, pvMsgBody, cubMsgBody);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetLobbyChatEntry ( CSteamID steamIDLobby,  int iChatID,  CSteamID *pSteamIDUser,  void *pvData,  int cubData,  EChatEntryType *peChatEntryType )	{
		char log[1024];
		sprintf(log,"GetLobbyChatEntry() steamIDLobby=0x%X iChatID=0x%X pSteamIDUser=0x%X pvData=0x%X cubData=0x%X peChatEntryType=0x%X ",
			steamIDLobby,
			iChatID,
			pSteamIDUser,
			pvData,
			cubData,
			peChatEntryType		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetLobbyChatEntry(steamIDLobby, iChatID, pSteamIDUser, pvData, cubData, peChatEntryType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RequestLobbyData ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"RequestLobbyData() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RequestLobbyData(steamIDLobby);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetLobbyGameServer ( CSteamID steamIDLobby,  uint32 unGameServerIP,  uint16 unGameServerPort,  CSteamID steamIDGameServer )	{
		char log[1024];
		sprintf(log,"SetLobbyGameServer() steamIDLobby=0x%X unGameServerIP=0x%X unGameServerPort=0x%X steamIDGameServer=0x%X ",
			steamIDLobby,
			unGameServerIP,
			unGameServerPort,
			steamIDGameServer		);
		OutputDebugStringA(log);
		steamIDLobby, unGameServerIP, unGameServerPort, steamIDGameServer);
		OutputDebugStringA("\n");
	}
	virtual bool  GetLobbyGameServer ( CSteamID steamIDLobby,  uint32 *punGameServerIP,  uint16 *punGameServerPort,  CSteamID *psteamIDGameServer )	{
		char log[1024];
		sprintf(log,"GetLobbyGameServer() steamIDLobby=0x%X punGameServerIP=0x%X punGameServerPort=0x%X psteamIDGameServer=0x%X ",
			steamIDLobby,
			punGameServerIP,
			punGameServerPort,
			psteamIDGameServer		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetLobbyGameServer(steamIDLobby, punGameServerIP, punGameServerPort, psteamIDGameServer);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLobbyMemberLimit ( CSteamID steamIDLobby,  int cMaxMembers )	{
		char log[1024];
		sprintf(log,"SetLobbyMemberLimit() steamIDLobby=0x%X cMaxMembers=0x%X ",
			steamIDLobby,
			cMaxMembers		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLobbyMemberLimit(steamIDLobby, cMaxMembers);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual int  GetLobbyMemberLimit ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"GetLobbyMemberLimit() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetLobbyMemberLimit(steamIDLobby);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLobbyType ( CSteamID steamIDLobby,  ELobbyType eLobbyType )	{
		char log[1024];
		sprintf(log,"SetLobbyType() steamIDLobby=0x%X eLobbyType=0x%X ",
			steamIDLobby,
			eLobbyType		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLobbyType(steamIDLobby, eLobbyType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLobbyJoinable ( CSteamID steamIDLobby,  bool bLobbyJoinable )	{
		char log[1024];
		sprintf(log,"SetLobbyJoinable() steamIDLobby=0x%X bLobbyJoinable=0x%X ",
			steamIDLobby,
			bLobbyJoinable		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLobbyJoinable(steamIDLobby, bLobbyJoinable);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetLobbyOwner ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"GetLobbyOwner() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetLobbyOwner(steamIDLobby);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SetLobbyOwner ( CSteamID steamIDLobby,  CSteamID steamIDNewOwner )	{
		char log[1024];
		sprintf(log,"SetLobbyOwner() steamIDLobby=0x%X steamIDNewOwner=0x%X ",
			steamIDLobby,
			steamIDNewOwner		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SetLobbyOwner(steamIDLobby, steamIDNewOwner);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
