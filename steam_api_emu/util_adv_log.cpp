#include "stdafx.h"
#include <windows.h>
#include "util_adv_log.h"


cLogging g_Logging;

CRITICAL_SECTION g_LogProtection;

char* cLogging::GetDirectoryFileA( char *szFile )
{
	#ifdef DEBUGGING_ENABLED
	static char path[ 320 ];
	strcpy( path, dlldir );
	strcat( path, "Logs\\");
	strcat( path, szFile );
	return path;
	#endif

	return szFile;
}

wchar_t* cLogging::GetDirectoryFileW( wchar_t *szFile )
{
	#ifdef DEBUGGING_ENABLED

	char szFilename[ MAX_PATH ] = { 0 };

	wcstombs( szFilename, szFile, MAX_PATH );

	char *szDirectoryFile = GetDirectoryFileA( szFilename );

	static wchar_t szDirectoryFileW[ MAX_PATH ] = { 0 };

	mbstowcs( szDirectoryFileW, szDirectoryFile, MAX_PATH );

	return szDirectoryFileW;
	#endif

	return szFile;
}

bool g_LogLock = false;

void cLogging::AddToLogFileA( char *szFile, char *szLog, ... )
{	
	#ifdef DEBUGGING_ENABLED

	while (g_LogLock)
		Sleep(1);
	g_LogLock = true;

	va_list va_alist;
	char logbuf[ 1024 ] = { 0 };


	
	FILE * fp;

	struct tm * current_tm;

	time_t current_time;

	time( &current_time );
	current_tm = localtime( &current_time );

	sprintf( logbuf, "[ %02d:%02d:%02d ] ", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec );

	va_start( va_alist, szLog );
	
	_vsnprintf( logbuf + strlen( logbuf ), 
		sizeof( logbuf ) - strlen( logbuf ), 
		szLog, va_alist);

	va_end( va_alist );

	if ( ( fp = fopen ( GetDirectoryFileA( szFile ), "a" ) ) != NULL )
	{
		fprintf( fp, "%s\n", logbuf );
		fclose( fp );
	}
	g_LogLock = false;
	#endif







	//va_start( va_alist, szLog );

	//_vsnprintf( logbuf + strlen( logbuf ), 
	//	sizeof( logbuf ) - strlen( logbuf ), 
	//	szLog, va_alist);

	//va_end( va_alist );

	//info("%s: %s", szFile, logbuf);

	//OutputDebugStringA(logbuf);


}


void cLogging::AddToLogFileW( wchar_t *szFile, wchar_t *szLog, ... )
{
	#ifdef DEBUGGING_ENABLED
	EnterCriticalSection(&g_LogProtection);
	va_list va_alist;

	wchar_t logbuf[ 1024 ] = { 0 };
	
	FILE * fp;
	
	struct tm * current_tm;
	
	time_t current_time;

	time (&current_time);
	
	current_tm = localtime (&current_time);

	wsprintfW( logbuf, L"[ %02d:%02d:%02d ] ", current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec );

	va_start( va_alist, szLog );

	_vsnwprintf( logbuf + wcslen( logbuf ), 
		sizeof( logbuf ) - wcslen( logbuf ), 
		szLog, va_alist);
	
	va_end( va_alist );

	if ( ( fp = _wfopen( GetDirectoryFileW( szFile ), L"a" ) ) != NULL )
	{
		fwprintf( fp, L"%s\n", logbuf );
		fclose( fp );
	}
	LeaveCriticalSection(&g_LogProtection);
	#endif
}

void cLogging::BaseUponModule( HMODULE hModule )
{
	#ifdef DEBUGGING_ENABLED
	m_hSelf = hModule;

	InitializeCriticalSection(&g_LogProtection);

	GetModuleInformation( GetCurrentProcess(), m_hSelf, &m_hMISelf, sizeof( m_hMISelf ) );

  	GetModuleFileNameA(hModule, dlldir, 512);

	for(int i = ( int )strlen(dlldir); i > 0; i--) 
	{ 
		if(dlldir[i] == '\\') 
		{ 
			dlldir[i+1] = 0; break; 
		} 
	}
	#endif
}