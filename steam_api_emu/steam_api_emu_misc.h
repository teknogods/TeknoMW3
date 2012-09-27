#pragma once

int GetHWIDSteamID();
void InitFloat();
bool SteamDataCrypto(BYTE * data, BYTE * outbuf, int size, CSteamID *steam_id);
char * GetMpdataName(CSteamID * steam_id);
bool ValidateLoaderMutex();
bool ValidateDumperMutex();
DWORD GetHWIDchunk(int chunk);
bool GetHWID(DWORD * hwid);