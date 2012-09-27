#include "ISteamMatchmaking002.h"

class ISteamMatchmaking002_wrapper
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
	virtual bool  GetFavoriteGame ( int iGame,  uint32 *pnAppID,  uint32 *pnIP,  uint16 *pnConnPort,  uint16 *pnQueryPort,  uint32 *punFlags,  RTime32 *pRTime32LastPlayedOnServer )	{
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
	virtual int  AddFavoriteGame ( uint32 nAppID,  uint32 nIP,  uint16 nConnPort,  uint16 nQueryPort,  uint32 unFlags,  RTime32 rTime32LastPlayedOnServer )	{
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
	virtual bool  RemoveFavoriteGame ( uint32 nAppID,  uint32 nIP,  uint16 nConnPort,  uint16 nQueryPort,  uint32 unFlags )	{
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
	virtual void  RequestLobbyList ()	{
		char log[1024];
		sprintf(log,"RequestLobbyList() "		);
		OutputDebugStringA(log);
		);
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
	virtual void  CreateLobby ( bool bPrivate )	{
		char log[1024];
		sprintf(log,"CreateLobby() bPrivate=0x%X ",
			bPrivate		);
		OutputDebugStringA(log);
		bPrivate);
		OutputDebugStringA("\n");
	}
	virtual void  JoinLobby ( CSteamID steamIDLobby )	{
		char log[1024];
		sprintf(log,"JoinLobby() steamIDLobby=0x%X ",
			steamIDLobby		);
		OutputDebugStringA(log);
		steamIDLobby);
		OutputDebugStringA("\n");
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
	virtual const char * GetLobbyData ( CSteamID SteamIDLobby,  const char *pchKey )	{
		char log[1024];
		sprintf(log,"GetLobbyData() SteamIDLobby=0x%X pchKey=%s ",
			SteamIDLobby,
			pchKey		);
		OutputDebugStringA(log);
		const char * ret = m_pWrapper->GetLobbyData(SteamIDLobby, pchKey);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SetLobbyData ( CSteamID steamIDLobby,  const char *pchKey,  const char *pchValue )	{
		char log[1024];
		sprintf(log,"SetLobbyData() steamIDLobby=0x%X pchKey=%s pchValue=%s ",
			steamIDLobby,
			pchKey,
			pchValue		);
		OutputDebugStringA(log);
		steamIDLobby, pchKey, pchValue);
		OutputDebugStringA("\n");
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
};
