//#include <Windows.h>
#include <WinSock2.h>
#include "include\MasterServerProtocol.hpp"
#include "include\ServerList.hpp"

#pragma comment(lib,"ws2_32.lib")

typedef struct _COMMUNICATION_CONTEXT {
	SOCKET		ConnectionSocket;
	SOCKADDR_IN	Peer;
} COMMUNICATION_CONTEXT, *PCOMMUNICATION_CONTEXT;

static DWORD WINAPI communicationThreadFunc(LPVOID lpParameter)
{
	PCOMMUNICATION_CONTEXT pContext = (PCOMMUNICATION_CONTEXT)lpParameter;
	u_long iMode=0;
	ioctlsocket(pContext->ConnectionSocket,FIONBIO,&iMode);

	char buf[512];
	int iResult = recv(pContext->ConnectionSocket, buf, 512, 0);
	if(iResult == SOCKET_ERROR)
	{
		closesocket(pContext->ConnectionSocket);
	}
	else
	{
		if(iResult < sizeof(DWORD))
		{
			printf("Received bad packet\n");
		}
		else
		{
			DWORD* pMagic = (DWORD*)buf;
			switch(*pMagic)
			{
			case MW3_MS_SERVER_MAGIC4CC:
				{
					if(iResult < sizeof(MW3_MS_SERVER_REQUEST))
					{
						printf("Received bad packet\n");
					}
					else
					{
						PMW3_MS_SERVER_REQUEST pRequest = (PMW3_MS_SERVER_REQUEST)buf;
						printf("Received server update {server: QP=%d, IP=%08X, VER=%08X}\n", pRequest->QPort, pContext->Peer.sin_addr.s_addr, pRequest->Version);
						ServerList::getInstance(pRequest->Version)->handleEntry(ntohl(pContext->Peer.sin_addr.s_addr), pRequest->QPort);
					}
				}
				break;
			case MW3_MS_CLIENT_MAGIC4CC:
				{
					if(iResult < sizeof(MW3_MS_CLIENT_REQUEST))
					{
						printf("Received bad packet\n");
					}
					else
					{
						printf("Received client request\n");
						PMW3_MS_CLIENT_REQUEST pRequest = (PMW3_MS_CLIENT_REQUEST)buf;
						DWORD NumOfEntries = 0;
						PMW3_MS_SERVER_ENTRY entries = ServerList::getInstance(pRequest->Version)->getEntries(&NumOfEntries);
						int sizeOfResponse = sizeof(MW3_MS_CLIENT_RESPONSE)+(sizeof(MW3_MS_SERVER_ENTRY)*NumOfEntries);
						PMW3_MS_CLIENT_RESPONSE pResponse = (PMW3_MS_CLIENT_RESPONSE)malloc(sizeOfResponse);
						pResponse->NumberOfEntries = NumOfEntries;
						memcpy(&pResponse->Entries[0], entries, sizeof(MW3_MS_SERVER_ENTRY)*NumOfEntries);

						for (int i=0; i<NumOfEntries; i++)
						{
							printf("entry %d: %08X %04X sent\n", i, pResponse->Entries[i].IpAddress, pResponse->Entries[i].QPort);
						}

						delete [] entries;
						send(pContext->ConnectionSocket, (char*)pResponse, sizeOfResponse, 0);
					}
				}
				break;
			default:
				printf("Received bad packet\n");
			}
		}
	}
	
	closesocket(pContext->ConnectionSocket);
	delete pContext;
	return 0;
}


int main(int argc, char* argv[])
{
	printf("TeknoMW3 Master Server v1.0b\n");
	printf("===========================\n\n");

	WSADATA WsaDat;
	if(WSAStartup(MAKEWORD(2,2),&WsaDat)!=0)
	{
		printf("Winsock error - Winsock initialization failed\r\n");
		WSACleanup();
		return 0;
	}

	SOCKET sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

	// If iMode!=0, non-blocking mode is enabled.
	u_long iMode=1;
	ioctlsocket(sock,FIONBIO,&iMode);

	SOCKADDR_IN SockAddr;
	SockAddr.sin_port=htons(MW3_MS_LISTEN_PORT);
	SockAddr.sin_family=AF_INET;
	SockAddr.sin_addr.s_addr=htonl(INADDR_ANY);

	int iResult = bind(sock, (SOCKADDR *) & SockAddr, sizeof (SockAddr));
	if (iResult == SOCKET_ERROR)
	{
		printf("Error binding the socket %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
		return 0;
	}

	if (listen(sock, SOMAXCONN) == SOCKET_ERROR)
	{
		printf("Error listening on the socket %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
		return 0;
	}

	printf("Listening to connections\n");
	PCOMMUNICATION_CONTEXT pContext = new COMMUNICATION_CONTEXT;
	bool bRun = true;
	while(bRun)
	{
		int AddrLen =  sizeof(pContext->Peer);
		pContext->ConnectionSocket = accept(sock, (SOCKADDR*)&pContext->Peer, &AddrLen);
		if(pContext->ConnectionSocket == INVALID_SOCKET)
		{
			int error = WSAGetLastError();

			if(error != WSAEWOULDBLOCK)
			{
				bRun = false;
				delete pContext;
			}
		}
		else
		{
			printf("connection accepted\n");
			CreateThread(NULL, 0, communicationThreadFunc, pContext, 0, NULL);
			pContext = new COMMUNICATION_CONTEXT;
		}
		Sleep(1);
	}

	closesocket(sock);
	WSACleanup();

	return 1;
}