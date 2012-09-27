#include "stdafx.h"
#include "util.h"
#include "dw_stun_server.h"
#include "game_patch_base.h"
#include "steam_api_emu.h"
#include "game_server_items.h"
#include <winsock2.h>
#include "VMProtectSDK.h"

#pragma optimize("", off)

short StunServerPort = (GetCurrentProcessId() % 400) + 27599;
char  StunServerHost[32] = "127.0.0.1";

#pragma pack(1)
typedef struct _TSTUN_MSG_15
{
	WORD magic;
	BYTE unk;
	DWORD PubIP;
	short PubPort;
	DWORD LocalIP;
	short LocalPort;
} TSTUN_MSG_15, *PTSTUN_MSG_15;
typedef struct _TSTUN_MSG_9 
{
	WORD magic;
	BYTE unk;
	DWORD PubIP;
	short PubPort;
} TSTUN_MSG_9, *PTSTUN_MSG_9;
#pragma pack()

PTSTUN_MSG_9 STUN_MSG_9 = NULL;
PTSTUN_MSG_15 STUN_MSG_15 = NULL;


bool StunReplyMessagesInited = false;

bool StunServerInitMessages(sockaddr_in * sender)
{	VM("StunServerInitMessages");

	info("StunServerInitMessages()");

	if (sender != NULL)
	{
		if (StunReplyMessagesInited)
		{
			return true;
		}
		else
		{
			info("StunServerInitMessages() begin init");
			STUN_MSG_9 = new TSTUN_MSG_9;
			STUN_MSG_15 = new TSTUN_MSG_15;

			STUN_MSG_15->magic = 0x215;
			STUN_MSG_9->magic = 0x21f;
			STUN_MSG_15->unk = 0;
			STUN_MSG_9->unk = 0;
			STUN_MSG_9->PubIP = GetExternalIP(false);
			STUN_MSG_15->PubIP = GetExternalIP(false);
			short PubPort = ((sender->sin_port & 0xFF) << 8) ^ ((sender->sin_port & 0xFF00) >> 8);
			STUN_MSG_9->PubPort = PubPort;
			STUN_MSG_15->PubPort = PubPort;
			STUN_MSG_15->LocalIP = sender->sin_addr.S_un.S_addr;
			STUN_MSG_15->LocalPort = 0;//StunServerPort;

			StunReplyMessagesInited = true;
			info("StunServerThreadFunc() Messages initialized\n");

			return true;
		}
	}
	return false;
	VE();
}



DWORD WINAPI StunServerThreadFunc(LPVOID lpParameter)
{
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if(INVALID_SOCKET == sock)
	{
		info("StunServerThreadFunc ERROR: Could not initialize a socket\n");
		return 0;
	}

	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	service.sin_port = htons(StunServerPort);
	int res = bind(sock, (SOCKADDR*)&service, sizeof(service));
	if(SOCKET_ERROR == res)
	{
		closesocket(sock);
		info("StunServerThreadFunc ERROR: Could not bind the socket\n");
		return 0;
	}

	char* recvBuf = new char[2048];
	sockaddr_in senderAddr;
	int senderAddrSize = sizeof(senderAddr);
	int dataLen = recvfrom(sock, recvBuf, 2048, 0, (SOCKADDR*)&senderAddr, &senderAddrSize);

	while(dataLen != SOCKET_ERROR)
	{
		if( dataLen > 1 )
		{
			if (StunServerInitMessages(&senderAddr))
			{	VM("StunServerThreadFunc_process_msg");

				BYTE *pType = (BYTE*)recvBuf;
				info("StunServerThreadFunc Received StunCMD(%02X:%02X)", pType[0], pType[1]);

				PrintBuffer((BYTE*)recvBuf, dataLen, 16);

				if(pType[0] == 0x14 && dataLen == 4)
				{
					int b_sent = sendto(sock, (char *)STUN_MSG_15, 15, 0, (SOCKADDR*)&senderAddr, sizeof(senderAddr));
					info("StunServerThreadFunc Replied to StunCMD(%02X:%02X) Reply: %d bytes", pType[0], pType[1], b_sent);
					PrintBuffer((BYTE *)STUN_MSG_15, sizeof(TSTUN_MSG_15), 16);
				}
				else if(pType[0] == 0x1e)
				{
					int b_sent = sendto(sock, (char *)STUN_MSG_9, 9, 0, (SOCKADDR*)&senderAddr, sizeof(senderAddr));
					info("StunServerThreadFunc Replied to StunCMD(%02X:%02X) Reply: %d bytes", pType[0], pType[1], b_sent);
					PrintBuffer((BYTE *)STUN_MSG_9, sizeof(TSTUN_MSG_9), 16);
				}
				else if(pType[0] == 0xe)
				{
					info("StunServerThreadFunc -> Received Keep-Alive msg.");

					//keep-alive server entry on master server
					if (g_OnlineMode)
					{
						ServerInformer* svinfo = ServerInformer::getInstance();
						svinfo->updateOnMasterServer();
					}

				}
				VE();
			}
			else
			{
				info("StunServerThreadFunc ERROR: Could not init reply messages\n");
				return 0;
			}
		}

		Sleep(1);
		dataLen = recvfrom(sock, recvBuf, 2048, 0, (SOCKADDR*)&senderAddr, &senderAddrSize);
		info("datalen was %d", dataLen);
	}

	return 0;
}

bool g_IpDiscoveryThreadFunc_running = false;
DWORD WINAPI IpDiscoveryThreadFunc(LPVOID lpParameter)
{
	int ret = 5;
	int fsize = 0;
	char ipbuf[256];

	while (ret != 0 && fsize == 0)
	{
		fsize = HttpReadFile(V("http://teknogods.com/ip.php"), ipbuf, sizeof(ipbuf));
		ret--;
		Sleep(1);
	}

	if (fsize != 0 && fsize <= 20)
		GetExternalIP(false, ipbuf);
	else
		info("Failed to get external ip from ip.php");

	g_IpDiscoveryThreadFunc_running = false;

	return 0;
}

#pragma optimize("", on)

void StartIpDiscovery()
{
	g_IpDiscoveryThreadFunc_running = true;
	CreateThread(NULL, 0, IpDiscoveryThreadFunc, NULL, 0, NULL);
	info("IpDiscoveryThreadFunc Created\n");

	ConsolePrintf(0, V("Discovering external IP address"));

	int ct = 0;
	while (g_IpDiscoveryThreadFunc_running)
	{
		Sleep(1);
		ct++;
		if (ct % 800 == 1) ConsolePrintf(0, ".");
	}

	char ip[256];
	makeIPstr(GetExternalIP(false), ip);
	ConsolePrintf(0, V(" Done (%s).\n"), ip);

	//IpDiscoveryThreadFunc(NULL);
	info("IpDiscoveryFunc finished\n");
	
}


void StartStunServer()
{
	CreateThread(NULL, 0, StunServerThreadFunc, NULL, 0, NULL);
	info("StunServerThreadFunc Created\n");
}
