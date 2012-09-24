#ifndef __MW3_MASTERSERVER_SERVERLIST_HPP__
#define __MW3_MASTERSERVER_SERVERLIST_HPP__

#include <Windows.h>
#include <map>
#include "MasterServerProtocol.hpp"

using namespace std;

class ServerList 
{
public:
	ServerList() : m_hTimer(INVALID_HANDLE_VALUE) {

		InitializeCriticalSection(&m_listProtection);

		m_hTimer = CreateWaitableTimer(NULL, TRUE, "MahTimah");
		printf("Timer(%08X) Create() -> ", m_hTimer);

		CreateThread(NULL, 0, garbageCollectorThread, this, 0, NULL);
	}
	~ServerList() {
		printf("ServerList() -> CancelWaitableTimer (%08X)", this);
		CancelWaitableTimer(m_hTimer);
	}
	static ServerList* getInstance(DWORD Version);

	PMW3_MS_SERVER_ENTRY getEntries(DWORD* pNumOfEntries);
	void handleEntry(DWORD ipAddress, USHORT qPort);
	

private:
	static map<DWORD, ServerList*>	s_serverLists;
	map<ULONGLONG, DWORD>			m_entries;
	CRITICAL_SECTION				m_listProtection;
	HANDLE							m_hTimer;
	static VOID CALLBACK TimerAPCProc(LPVOID lpArgToCompletionRoutine, DWORD dwTimerLowValue, DWORD dwTimerHighValue);

protected:
	static DWORD WINAPI garbageCollectorThread(LPVOID lpParameter);
};

#endif //__MW3_MASTERSERVER_SERVERLIST_HPP__