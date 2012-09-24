// mw3_nettest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#ifndef UNICODE
#define UNICODE
#endif

#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include "..\steam_api_emu\game_server_items.h"

// Link with ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

int _tmain(int argc, _TCHAR* argv[])
{

    int iResult = 0;

    WSADATA wsaData;

    SOCKET RecvSocket;
    sockaddr_in RecvAddr;

    unsigned short Port = 27057;


    char RecvBuf[1024];
    int BufLen = 1024;

    sockaddr_in SenderAddr;
    int SenderAddrSize = sizeof (SenderAddr);

    //-----------------------------------------------
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error %d\n", iResult);
        return 1;
    }
    //-----------------------------------------------
    // Create a receiver socket to receive datagrams
    RecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (RecvSocket == INVALID_SOCKET) {
        wprintf(L"socket failed with error %d\n", WSAGetLastError());
        return 1;
    }


    //-----------------------------------------------
    // Bind the socket to any address and the specified port.
    RecvAddr.sin_family = AF_INET;
    RecvAddr.sin_port = htons(Port);
    RecvAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    iResult = bind(RecvSocket, (SOCKADDR *) & RecvAddr, sizeof (RecvAddr));
    if (iResult != 0) {
        wprintf(L"bind failed with error %d\n", WSAGetLastError());
        return 1;
    }


	MW3_SERVER_QUERY query = {0};
	sockaddr_in s;
	s.sin_family = AF_INET;
	query.Magic4CC = MW3_SERVER_4CC;

	s.sin_port = htons(33333); //htons(27017);
	s.sin_addr.s_addr = htonl(0xB220335F);   //htonl(0x3eed0440);

	query.TimeStamp = GetTickCount();
	int ret = sendto(RecvSocket, (char*)&query, sizeof(query), 0, (SOCKADDR*)&s, sizeof(s));

	int rep = 5;
	while(ret == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK && rep != 0)
	{
		printf("ServerList::refreshInternetListThread() send failed. resending\n");
		query.TimeStamp = GetTickCount();
		ret = sendto(RecvSocket, (char*)&query, sizeof(query), 0, (SOCKADDR*)&s, sizeof(s));
		rep--;
		Sleep(1);
	}
	if(ret == SOCKET_ERROR)
	{
		printf("ServerList::refreshInternetListThread() send failed. Error %d\n", WSAGetLastError());
	}

    //-----------------------------------------------
    // Call the recvfrom function to receive datagrams
    // on the bound socket.
    wprintf(L"Receiving datagrams...\n");
    iResult = recvfrom(RecvSocket,
                       RecvBuf, BufLen, 0, (SOCKADDR *) & SenderAddr, &SenderAddrSize);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"recvfrom failed with error %d\n", WSAGetLastError());
    }
	else
	{
	
		PMW3_SERVER_INFO servInfo = (PMW3_SERVER_INFO)RecvBuf;

		printf("server infos ex = '%s'\n", &servInfo->RawData[servInfo->ServerInfos_ptr]);
	}

    //-----------------------------------------------
    // Close the socket when finished receiving datagrams
    wprintf(L"Finished receiving. Closing socket.\n");
    iResult = closesocket(RecvSocket);
    if (iResult == SOCKET_ERROR) {
        wprintf(L"closesocket failed with error %d\n", WSAGetLastError());
        return 1;
    }

    //-----------------------------------------------
    // Clean up and exit.
    wprintf(L"Exiting.\n");
    WSACleanup();
    return 0;
}
