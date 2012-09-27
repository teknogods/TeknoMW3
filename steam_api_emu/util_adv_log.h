#pragma once
#include <windows.h>
#include <time.h>
#include <fstream>
#include <Psapi.h>
using namespace std;

#pragma comment( lib, "Psapi.lib" )


class cLogging
{
public:
	char*		GetDirectoryFileA( char *szFile );
	wchar_t*	GetDirectoryFileW( wchar_t *szFile );
	void		AddToLogFileA( char *szFile, char *szLog, ... );
	void		AddToLogFileW( wchar_t *szFile, wchar_t *szLog, ... );
	void		BaseUponModule( HMODULE hModule );
	MODULEINFO	GetSelfModuleInformation(){ return m_hMISelf; }
	
	HMODULE		m_hSelf;
	MODULEINFO	m_hMISelf;
	ofstream	ofile;	
	char		dlldir[ 320 ];
};


extern cLogging g_Logging;