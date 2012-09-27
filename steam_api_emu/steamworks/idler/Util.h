#ifndef UTIL_H
#define UTIL_H

#include "SteamclientAPI.h"
#include <iostream>

void ShowError(std::string msg, int errorCode = 0);

// thanks to ZeekyHBomb :) 
std::string ObtainSteamFolder();

#endif // UTIL_H