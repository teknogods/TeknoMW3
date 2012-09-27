#pragma once
#include "stdafx.h"
#include "SDK\SteamclientAPI.h"
#include "SDK\SteamAPI.h"
#include "steam_api_emu.h"
#include "util.h"
#include "util_adv_log.h"
#include "steam_api_emu_misc.h"
#include "steam_api_emu_interfaces.h"
#include "game_patch_base.h"
#include "game_server_items.h"


CSteamUser016*					g_pSteamUserEmu				= new CSteamUser016;					//+SteamUser016
CSteamRemoteStorage004*			g_pSteamRemoteStorageEmu	= new CSteamRemoteStorage004;			//+STEAMREMOTESTORAGE_INTERFACE_VERSION004
CSteamFriends009*				g_pSteamFriendsEmu			= new CSteamFriends009;					//+SteamFriends008
CSteamNetworking004*			g_pSteamNetworkingEmu		= new CSteamNetworking004;				//+SteamNetworking004
CSteamMatchmaking008*			g_pSteamMatchmakingEmu		= new CSteamMatchmaking008;				//+SteamMatchMaking008
CSteamMasterServerUpdater001*	g_pSteamMasterServerUpEmu	= new CSteamMasterServerUpdater001;		//+SteamMasterServerUpdater001
CSteamUtils005*					g_pSteamUtilsEmu			= new CSteamUtils005;					//+SteamUtils005
CSteamGameServer010*			g_pSteamGameServerEmu		= new CSteamGameServer010;				//+SteamGameServer010
CSteamApps004*					g_pSteamAppsEmu				= new CSteamApps004;					//+STEAMAPPS_INTERFACE_VERSION004
CSteamMatchmakingServers002*	g_pSteamMatchmakingServEmu	= new CSteamMatchmakingServers002;		//+SteamMatchMakingServers002
CSteamUserStats009*				g_pSteamUserStatsEmu		= new CSteamUserStats009;				//-STEAMUSERSTATS_INTERFACE_VERSION009
CSteamClient008*				g_pSteamClientEmu			= new CSteamClient008;					//-SteamClient010
