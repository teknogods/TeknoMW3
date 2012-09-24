#ifndef __SERVER_ITEMS_H__
#define __SERVER_ITEMS_H__

#include "stdafx.h"

#define MW3_SERVER_4CC 'POOL'


#pragma pack(1)
typedef struct _MW3_SERVER_QUERY {
	ULONG		Magic4CC;
	ULONG		TimeStamp;
} MW3_SERVER_QUERY, *PMW3_SERVER_QUERY;

#define MW3_SERVER_INFO_MAX_RAW_DATA_SIZE 2048

typedef struct _MW_SERVER_INFO_EX
{
	BYTE		unused;
} MW_SERVER_INFO_EX, *PMW_SERVER_INFO_EX;

typedef struct _MW3_SERVER_INFO {
	ULONG		Magic4CC;
	ULONG		TimeStamp;
	int			Players;
	int			MaxPlayers;
	bool		bPasswordProtected;
	ULONG		bDedicated;
	int			ServerVersion;
	ULONGLONG	SteamId;
	ULONG		GameIP_int;
	ULONG		GameIP_ext;
	USHORT		GamePort;
	USHORT		QueryPort;
	USHORT		NetPort;
	char		SecID[8];
	char		SecKey[16];

	WORD		MapName_ptr;
	WORD		ServerName_ptr;
	WORD		ServerTags_ptr;
	WORD		ServerInfos_ptr;

	WORD		RawDataSize;
	char		RawData[MW3_SERVER_INFO_MAX_RAW_DATA_SIZE];

} MW3_SERVER_INFO, *PMW3_SERVER_INFO;

#pragma pack()

#endif //__SERVER_ITEMS_H__
