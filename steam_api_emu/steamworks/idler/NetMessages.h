#ifndef NETMESSAGES_H
#define NETMESSAGES_H

enum ENetworkMessages
{
	// server
	eServerBegin = 0,
	eServerSendInfo = eServerBegin + 1,

	// client
	eClientBegin = 20,
	eClientInitConnection = eClientBegin + 1,
	eClientAuth = eClientBegin + 2,

	// force 32bit enum
	eDWORD  = 0x7fffffff,
};

struct NetClientInitConnection_t
{
	NetClientInitConnection_t() : messageType( eClientInitConnection ) { }
	const DWORD messageType;
};

struct NetServerInfo_t
{
	NetServerInfo_t() : messageType( eServerSendInfo ) { }
	const DWORD messageType;

	uint64 serverSteamID;
	bool vacSecure;
};

struct NetClientAuthentication_t
{
	NetClientAuthentication_t() : messageType( eClientAuth ) { }
	const DWORD messageType;

	uint32 ticketLen;
	byte authTicket[1024];
};


#endif // NETMESSAGES_H