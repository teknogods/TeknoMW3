#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <string>
#include "Wininet.h"
#include "winsock2.h"
#include "util.h"
#pragma comment(lib, "Wininet.lib")



void nettest()
{
		#ifdef DEBUGGING_ENABLED
		info("Hello");

		SOCKET sd = socket(AF_INET, SOCK_DGRAM, 0);
		char          sendbuf[20] = "hello butterface!";
		int            ret, i;
		SOCKADDR_IN    recipient;

		if (sd == INVALID_SOCKET)
		{
			info("Could not create socket.");
			WSACleanup();
			ExitProcess(0);
		}

		recipient.sin_family = AF_INET;
		recipient.sin_port = htons((short)27017);

		char HOSTNAME[30] = "192.168.11.35";


		if ((recipient.sin_addr.s_addr = inet_addr(HOSTNAME)) == INADDR_NONE)
		{
			struct hostent *host=NULL;
 
			host = gethostbyname(HOSTNAME);
			if (host)
				CopyMemory(&recipient.sin_addr, host->h_addr_list[0], host->h_length);
			else
			{
				info("gethostbyname() failed: %d\n", WSAGetLastError());
				WSACleanup();
				ExitProcess(0);
			}
		}

		//local.sin_family = AF_INET;
		//local.sin_port = htons((short)666);
		//local.sin_addr.s_addr = inet_addr("192.168.11.35");
		//bind(sd, (SOCKADDR *)&local, sizeof(local));

		for (i = 0; i < 10; i++)
		{
			ret = sendto(sd, sendbuf, strlen(sendbuf), 0,
			(SOCKADDR *)&recipient, sizeof(recipient));

			if (ret == SOCKET_ERROR)
			{
				info("sendto() failed; %d\n", WSAGetLastError());
				break;
			}
			else if (ret == 0)
			break;
			// sendto() succeeded!
		}


		ExitProcess(0);
		#endif
}