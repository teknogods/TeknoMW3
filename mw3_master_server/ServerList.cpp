#include "include\ServerList.hpp"
#include "include\MasterServerProtocol.hpp"

map<DWORD, ServerList*>	ServerList::s_serverLists;

ServerList* ServerList::getInstance(DWORD Version)
{
	//EnterCriticalSection(&m_listProtection);
	map<DWORD, ServerList*>::iterator it;
	it = s_serverLists.find(Version);
	ServerList* pInstance = NULL;
	if(it == s_serverLists.end())
	{
		pInstance = new ServerList();
		s_serverLists[Version] = pInstance;
	}
	else
	{
		pInstance = it->second;
	}
	//LeaveCriticalSection(&m_listProtection);
	return pInstance;
}

PMW3_MS_SERVER_ENTRY ServerList::getEntries(DWORD* pNumOfEntries)
{
	EnterCriticalSection(&m_listProtection);
	*pNumOfEntries = m_entries.size();
	if(0 == *pNumOfEntries)
	{
		LeaveCriticalSection(&m_listProtection);
		return NULL;
	}
	PMW3_MS_SERVER_ENTRY pEntries = new MW3_MS_SERVER_ENTRY[*pNumOfEntries];
	map<ULONGLONG, DWORD>::iterator it;
	ULONG idx = 0;
	for(it = m_entries.begin(); it != m_entries.end(); it++, idx++)
	{
		pEntries[idx].IpAddress = (DWORD)((it->first>>32) & 0xFFFFFFFF);
		pEntries[idx].QPort = (USHORT)((it->first) & 0xFFFF);
	}
	LeaveCriticalSection(&m_listProtection);
	return pEntries;
}

VOID CALLBACK ServerList::TimerAPCProc(LPVOID lpArgToCompletionRoutine, DWORD dwTimerLowValue, DWORD dwTimerHighValue)
{
	printf("TimerAPCProc() ");

	ServerList* pThis = (ServerList*)lpArgToCompletionRoutine;
	EnterCriticalSection(&pThis->m_listProtection);

	map<ULONGLONG, DWORD>::iterator itr = pThis->m_entries.begin(); 

	while(itr != pThis->m_entries.end())
	{
		if(GetTickCount() - itr->second > MW3_MS_CLEANUP_RATE)
		{
			printf("Erased server due to inactivity (%08X, %d).", (DWORD)((itr->first>>32) & 0xFFFFFFFF), (USHORT)((itr->first) & 0xFFFF)); 
			itr = pThis->m_entries.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	printf("\n");
	LeaveCriticalSection(&pThis->m_listProtection);
}

#ifndef WINE_BUILD
#define WINE_BUILD
#endif

DWORD WINAPI ServerList::garbageCollectorThread(LPVOID lpParameter)
{
		ServerList * pThis = (ServerList *)lpParameter;

		
		//set due time to1 second from now
		LARGE_INTEGER   liDueTime;
		liDueTime.QuadPart = -10000000LL;

		printf("%08X", pThis->m_hTimer);
		bool res = SetWaitableTimer(pThis->m_hTimer, &liDueTime, MW3_MS_CLEANUP_RATE, TimerAPCProc, lpParameter, FALSE);
		printf(" -> %d\n", res);

		#ifndef WINE_BUILD

		while (true)
		{
			SleepEx(INFINITE, TRUE);
		}

		#else

		while(true)
		{
			Sleep(MW3_MS_CLEANUP_RATE);
			TimerAPCProc(lpParameter, 0, 0);
		}

		#endif
}

void ServerList::handleEntry(DWORD ipAddress, USHORT qPort)
{
	ULONGLONG key = (ipAddress * 0x100000000) | qPort;
	EnterCriticalSection(&m_listProtection);
	map<ULONGLONG, DWORD>::iterator it = m_entries.find(key);
	if(it == m_entries.end())
	{
		m_entries[key] = GetTickCount();
	}
	else
	{
		it->second = GetTickCount();
	}
	LeaveCriticalSection(&m_listProtection);
}