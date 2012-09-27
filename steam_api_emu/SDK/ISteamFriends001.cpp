#include "ISteamFriends001.h"

class ISteamFriends001_wrapper
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
	virtual void  SetPersonaState ( EPersonaState ePersonaState )	{
		char log[1024];
		sprintf(log,"SetPersonaState() ePersonaState=0x%X ",
			ePersonaState		);
		OutputDebugStringA(log);
		ePersonaState);
		OutputDebugStringA("\n");
	}
	virtual bool  AddFriend ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"AddFriend() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->AddFriend(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  RemoveFriend ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"RemoveFriend() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->RemoveFriend(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  HasFriend ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"HasFriend() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->HasFriend(steamIDFriend);
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
	virtual bool  Deprecated_GetFriendGamePlayed ( CSteamID steamIDFriend,  int32 *pnGameID,  uint32 *punGameIP,  uint16 *pusGamePort )	{
		char log[1024];
		sprintf(log,"Deprecated_GetFriendGamePlayed() steamIDFriend=0x%X pnGameID=0x%X punGameIP=0x%X pusGamePort=0x%X ",
			steamIDFriend,
			pnGameID,
			punGameIP,
			pusGamePort		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->Deprecated_GetFriendGamePlayed(steamIDFriend, pnGameID, punGameIP, pusGamePort);
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
	virtual int  GetFriendCount ()	{
		char log[1024];
		sprintf(log,"GetFriendCount() "		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetFriendCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual CSteamID  GetFriendByIndex ( int iFriend )	{
		char log[1024];
		sprintf(log,"GetFriendByIndex() iFriend=0x%X ",
			iFriend		);
		OutputDebugStringA(log);
		CSteamID  ret = m_pWrapper->GetFriendByIndex(iFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual void  SendMsgToFriend ( CSteamID steamIDFriend,  EChatEntryType eFriendMsgType,  const char *pchMsgBody )	{
		char log[1024];
		sprintf(log,"SendMsgToFriend() steamIDFriend=0x%X eFriendMsgType=0x%X pchMsgBody=%s ",
			steamIDFriend,
			eFriendMsgType,
			pchMsgBody		);
		OutputDebugStringA(log);
		steamIDFriend, eFriendMsgType, pchMsgBody);
		OutputDebugStringA("\n");
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
	virtual int  GetChatMessage ( CSteamID steamIDFriend,  int iChatID,  void *pvData,  int cubData,  EChatEntryType *peFriendMsgType )	{
		char log[1024];
		sprintf(log,"GetChatMessage() steamIDFriend=0x%X iChatID=0x%X pvData=0x%X cubData=0x%X peFriendMsgType=0x%X ",
			steamIDFriend,
			iChatID,
			pvData,
			cubData,
			peFriendMsgType		);
		OutputDebugStringA(log);
		int  ret = m_pWrapper->GetChatMessage(steamIDFriend, iChatID, pvData, cubData, peFriendMsgType);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  SendMsgToFriend ( CSteamID steamIDFriend,  EChatEntryType eFriendMsgType,  const void *pvMsgBody,  int cubMsgBody )	{
		char log[1024];
		sprintf(log,"SendMsgToFriend() steamIDFriend=0x%X eFriendMsgType=0x%X pvMsgBody=0x%X cubMsgBody=0x%X ",
			steamIDFriend,
			eFriendMsgType,
			pvMsgBody,
			cubMsgBody		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->SendMsgToFriend(steamIDFriend, eFriendMsgType, pvMsgBody, cubMsgBody);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION int  GetChatIDOfChatHistoryStart ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"GetChatIDOfChatHistoryStart() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		OBSOLETE_FUNCTION int  ret = m_pWrapper->GetChatIDOfChatHistoryStart(steamIDFriend);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual OBSOLETE_FUNCTION void  SetChatHistoryStart ( CSteamID steamIDFriend,  int iChatID )	{
		char log[1024];
		sprintf(log,"SetChatHistoryStart() steamIDFriend=0x%X iChatID=0x%X ",
			steamIDFriend,
			iChatID		);
		OutputDebugStringA(log);
		steamIDFriend, iChatID);
		OutputDebugStringA("\n");
	}
	virtual void  ClearChatHistory ( CSteamID steamIDFriend )	{
		char log[1024];
		sprintf(log,"ClearChatHistory() steamIDFriend=0x%X ",
			steamIDFriend		);
		OutputDebugStringA(log);
		steamIDFriend);
		OutputDebugStringA("\n");
	}
	virtual HSteamCall  InviteFriendByEmail ( const char *pchEmailOrAccountName )	{
		char log[1024];
		sprintf(log,"InviteFriendByEmail() pchEmailOrAccountName=%s ",
			pchEmailOrAccountName		);
		OutputDebugStringA(log);
		HSteamCall  ret = m_pWrapper->InviteFriendByEmail(pchEmailOrAccountName);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual uint32  GetBlockedFriendCount ()	{
		char log[1024];
		sprintf(log,"GetBlockedFriendCount() "		);
		OutputDebugStringA(log);
		uint32  ret = m_pWrapper->GetBlockedFriendCount();
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFriendGamePlayed ( CSteamID steamIDFriend,  uint64 *pulGameID,  uint32 *punGameIP,  uint16 *pusGamePort )	{
		char log[1024];
		sprintf(log,"GetFriendGamePlayed() steamIDFriend=0x%X pulGameID=0x%X punGameIP=0x%X pusGamePort=0x%X ",
			steamIDFriend,
			pulGameID,
			punGameIP,
			pusGamePort		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFriendGamePlayed(steamIDFriend, pulGameID, punGameIP, pusGamePort);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
	virtual bool  GetFriendGamePlayed2 ( CSteamID steamDIFriend,  uint64 *pulGameID,  uint32 *punGameIP,  uint16 *pusGamePort,  uint16 *pusQueryPort )	{
		char log[1024];
		sprintf(log,"GetFriendGamePlayed2() steamDIFriend=0x%X pulGameID=0x%X punGameIP=0x%X pusGamePort=0x%X pusQueryPort=0x%X ",
			steamDIFriend,
			pulGameID,
			punGameIP,
			pusGamePort,
			pusQueryPort		);
		OutputDebugStringA(log);
		bool  ret = m_pWrapper->GetFriendGamePlayed2(steamDIFriend, pulGameID, punGameIP, pusGamePort, pusQueryPort);
		sprintf(log," returned 0x%X",ret);
		OutputDebugStringA(log);
		OutputDebugStringA("\n");
		return ret;
	}
};
