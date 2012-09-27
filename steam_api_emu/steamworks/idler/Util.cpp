#include "Util.h"

#include <string>
#include <shlwapi.h>

void ShowError(std::string msg, int errorCode)
{
	std::cout << "Error: " << msg;
	if (errorCode > 0)
		std::cout<< " Error code: " << errorCode;
	
	std::cout << std::flush;

	getchar();
	exit(EXIT_FAILURE);
}

// thanks to ZeekyHBomb :) 
std::string ObtainSteamFolder()
{
	char buf[MAX_PATH];
	DWORD buf_length = sizeof(buf);
	DWORD type = REG_SZ;

	if(SHGetValue(HKEY_CURRENT_USER, TEXT("Software\\Valve\\Steam"), TEXT("SteamPath"), &type, buf, &buf_length) != ERROR_SUCCESS)
		ShowError("No Steam-directory found (HKEY_CURRENT_USER\\Software\\Valve\\Steam\\SteamPath).\n");
	
	return buf;
}