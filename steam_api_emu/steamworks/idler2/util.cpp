#include "Common.h"
#ifdef _WIN32
#include <DbgHelp.h>
#pragma comment(lib, "DbgHelp.lib")
#endif

void _Sleep(unsigned int dwMilliseconds)
{
#ifdef _WIN32
	Sleep(dwMilliseconds);
#else
	usleep( dwMilliseconds * 1000 );
#endif
}

const char *HumanReadableIP(u_long ip)
{
	u_long addr = ntohl(ip);
	return inet_ntoa(*(struct in_addr *) &addr);
}

#ifdef _WIN32
#include <windows.h>

LONG WINAPI mdmpfilter(_EXCEPTION_POINTERS *exc_ptr)
{
  static const char *minidumpFilename = "idler2.mdmp";
  HANDLE hDumpFile = CreateFile(minidumpFilename, GENERIC_WRITE, 0, NULL,
    CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

  if (hDumpFile != INVALID_HANDLE_VALUE) {
    __try {
      MINIDUMP_EXCEPTION_INFORMATION exceptionInfo;
      exceptionInfo.ThreadId = GetCurrentThreadId();
      exceptionInfo.ExceptionPointers = exc_ptr;
      exceptionInfo.ClientPointers = false;

      BOOL ret = MiniDumpWriteDump(GetCurrentProcess(),
        GetCurrentProcessId(), hDumpFile, MiniDumpNormal, &exceptionInfo, NULL, NULL);

      if (ret)
		  std::cerr << "Crash! Minidump information has been written to " << minidumpFilename << std::endl;

    } __except(EXCEPTION_EXECUTE_HANDLER) { }
    CloseHandle(hDumpFile);
  }

  return EXCEPTION_CONTINUE_SEARCH;
}
#endif