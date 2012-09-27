#include "stdafx.h"
#include "steam_api_emu.h"
#include "game_dvar_base.h"
#include "game_patch_base.h"
#include "stdio.h"
#include "util.h"
#include "util_adv_log.h"
#include "VMProtectSDK.h"

//Declaration of funcs that we'll use to add our DVAR's
MYDVARADDBOOL  DvarAddBool  = NULL; //0
MYDVARADDFLOAT DvarAddFloat = NULL; //1
MYDVARADDINT   DvarAddInt   = NULL; //5
MYDVARADDTEXT  DvarAddText  = NULL; //7
#pragma optimize("", off)
//dvarSystem DvarSys;
//
//bool dvar::LockValAt(int Value)
//{
//	if (data->type == dvarTypes::DVAR_INT)
//	{
//		if (!IsLocked)
//		{
//			IsLocked = true;
//			LockedMin = data->ValMinDW;
//			LockedMax = data->ValMaxDW;
//			LockedCurr = data->ValA.valueDW;
//		}
//		data->ValMinDW = Value;
//		data->ValMaxDW = Value;
//		SetValue(Value);
//		return true;
//	}
//	//overload to float if type matches
//	if (data->type == dvarTypes::DVAR_FLOAT)
//	{
//		float val = Value;
//		return LockValAt(val);
//	}
//	return false;
//}
//
//bool dvar::LockValAt(float Value)
//{
//	if (data->type == dvarTypes::DVAR_FLOAT)
//	{
//		if (!IsLocked)
//		{
//			IsLocked = true;
//			LockedMin = data->ValMinDW;
//			LockedMax = data->ValMaxDW;
//			LockedCurr = data->ValA.valueDW;
//		}
//		data->ValMinFL = Value;
//		data->ValMaxFL = Value;
//		SetValue(Value);
//		return true;
//	}
//	if (data->type == dvarTypes::DVAR_INT)
//	{
//		int val = Value;
//		return LockValAt(val);
//	}
//	return false;
//}
//
//bool dvar::UnlockVal()
//{
//	if (((data->type == dvarTypes::DVAR_INT) || (data->type == dvarTypes::DVAR_FLOAT)) && (IsLocked))
//	{
//		IsLocked = false;
//		data->ValMinDW = LockedMin;
//		data->ValMaxDW = LockedMax;
//		data->ValA.valueDW = LockedCurr;
//		data->ValB.valueDW = LockedCurr;
//		return true;
//	}
//	return false;
//}


bool dvar::SetValue(bool Value)
{
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		data->ValA.valueDW = Value;
		data->ValB.valueDW = Value;
		return true;
	}
	return false;
}

bool dvar::SetValue(int Value)
{
	if (data->type == dvarTypes::DVAR_INT)
	{
		data->ValA.valueDW = Value;
		data->ValB.valueDW = Value;
		return true;
	}
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		return SetValue((bool)Value);
	}
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		float val = Value;
		return SetValue(val);
	}
	return false;
}
bool dvar::SetValue(float Value)
{
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		data->ValA.valueFL = Value;
		data->ValB.valueFL = Value;
		return true;
	}
	return false;
}

bool dvar::SetValue(char * Value)
{
	if (data->type == dvarTypes::DVAR_TEXT)
	{
		data->ValA.valueSTR = (char*)malloc(strlen(Value)+2);
		data->ValB.valueSTR = data->ValA.valueSTR;

		strcpy(data->ValA.valueSTR, Value);

		return true;
	}
	return false;
}


DWORD dvar::GetValueDW()
{
	if (Inited)
	{
		return data->ValA.valueDW;
	}
	else
		return 0;
}

float dvar::GetValueFL()
{
	if (Inited)
	{
		return data->ValA.valueFL;
	}
	else
		return 0.0f;
}

char * dvar::GetValueSTR()
{
	if (Inited)
	{
		return data->ValA.valueSTR;
	}
	else
		return "";
}


bool dvar::SetMinValue(bool Value)
{
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		data->ValMinDW = Value;
		return true;
	}
	return false;
}
bool dvar::SetMinValue(int Value)
{
	if (data->type == dvarTypes::DVAR_INT)
	{
		data->ValMinDW = Value;
		return true;
	}
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		return SetMinValue((bool)Value);
	}
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		float val = Value;
		return SetMinValue(val);
	}
	return false;
}
bool dvar::SetMinValue(float Value)
{
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		data->ValMinFL = Value;
		return true;
	}
	return false;
}




bool dvar::SetMaxValue(bool Value)
{
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		data->ValMaxDW = Value;
		return true;
	}
	return false;
}
bool dvar::SetMaxValue(int Value)
{
	if (data->type == dvarTypes::DVAR_INT)
	{
		data->ValMaxDW = Value;
		return true;
	}
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		return SetMaxValue((bool)Value);
	}
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		float val = Value;
		return SetMaxValue(val);
	}
	return false;
}
bool dvar::SetMaxValue(float Value)
{
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		data->ValMaxFL = Value;
		return true;
	}
	return false;
}


bool dvar::SetDefValue(bool Value)
{
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		data->DefaultVal.valueDW = Value;
		return true;
	}
	return false;
}
bool dvar::SetDefValue(int Value)
{
	if (data->type == dvarTypes::DVAR_INT)
	{
		data->DefaultVal.valueDW = Value;
		return true;
	}
	if (data->type == dvarTypes::DVAR_BOOL)
	{
		return SetDefValue((bool)Value);
	}
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		float val = Value;
		return SetDefValue(val);
	}
	return false;
}
bool dvar::SetDefValue(float Value)
{
	if (data->type == dvarTypes::DVAR_FLOAT)
	{
		data->DefaultVal.valueFL = Value;
		return true;
	}
	return false;
}

char DvarInitFailed[42] = "Dvar Init failed (dvar doesn't exist?)";


char * dvar::GetValueAsString()
{
	if (Inited)
	{
		char * Value = GetDvarValueStrFromBuffer((DWORD)data);

		memset(ValueAsString, 0, sizeof(ValueAsString));
		int s_len = strlen(Value);
		if (s_len < sizeof(ValueAsString))
			memcpy(ValueAsString, Value, strlen(Value));
		else
			strcpy(ValueAsString, V("(string too long)"));


		return ValueAsString;
	}
	else
	{
		return V(DvarInitFailed);
	}
}

dvar::dvar()
{
	Inited = false;
	//IsLocked = 0;
	//LockedMin = 0;
	//LockedMax = 0;
	//LockedCurr = 0;
	memset(ValueAsString, 0, 255);
}

bool dvar::Init(char * DvarName)
{
	if ((GetDvarValueStrFromBuffer == NULL) || (DvarCountPtr == 0) || (DvarListPtr == 0))
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 10032);
		#endif		
		return false;
	}

	if (!Inited)
	{
		DWORD buff = GetDvarBuffByName(DvarName);

		if (buff != 0)
		{
			data = (dvarBuff *)buff;
			Inited = true;
		}
	}
	return Inited;
}

dvar::dvar(char * DvarName)
{
	Inited = false;
	//IsLocked = 0;
	//LockedMin = 0;
	//LockedMax = 0;
	//LockedCurr = 0;
	memset(ValueAsString, 0, 255);

	if ((GetDvarValueStrFromBuffer == NULL) || (DvarCountPtr == 0) || (DvarListPtr == 0))
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 20032);
		#endif
		return;
	}

	Init(DvarName);
}

dvar::dvar(int DvarId)
{
	Inited = false;
	//IsLocked = 0;
	//LockedMin = 0;
	//LockedMax = 0;
	//LockedCurr = 0;
	memset(ValueAsString, 0, 255);

	if ((GetDvarValueStrFromBuffer == NULL) || (DvarCountPtr == 0) || (DvarListPtr == 0))
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 30032);
		#endif
		return;
	}

	DWORD buff = GetDvarBuffById(DvarId);

	if (buff != 0)
	{
		data = (dvarBuff *)buff;
		Inited = true;
	}
}


bool MakeAllDvarsPrintable()
{
	//validate pointers before doing anything
	if ((GetDvarValueStrFromBuffer == NULL) || (DvarCountPtr == 0) || (DvarListPtr == 0))
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 40032);
		#endif
		return false;
	}

	for (int i=0; i<(*(int*)DvarCountPtr); i++)
	{
		dvar dv(i);
		dv.data->Flags |= dvarFlags::DVF_PRINTABLE;
	}

	return true;
}

bool DumpDvarToFile()
{
	//validate pointers before doing anything
	if ((GetDvarValueStrFromBuffer == NULL) || (DvarCountPtr == 0) || (DvarListPtr == 0))
	{
		#ifdef DEBUGGING_ENABLED
		DebugOutValue("Error", 40032);
		#endif
		return false;
	}

	//
	char dvinfo[1024];

	#ifdef DEBUGGING_ENABLED
	char dumpname[32];
	sprintf_s(dumpname, 32, "dvar_dump_%08X.log", GetTickCount());
	info("Saving %d dvar items to '%s' file...", *(DWORD*)DvarCountPtr, dumpname);
	#endif


	
	for (int i=0; i<(*(int*)DvarCountPtr); i++)
	{
		dvar dv(i);

		//dv.data->Flags |= dvarFlags::DVF_PRINTABLE;
		//dv.data->Flags = dvarFlags::DVF_A | dvarFlags::DVF_PRINTABLE;

		
		sprintf_s(dvinfo, 1024, V("FL:%08X // Type:%08X // Buffer:%08X // Name:%s // ValStr:%s"), dv.data->Flags, dv.data->type, (DWORD)(dv.data), dv.data->name, dv.GetValueAsString());
		#ifdef DEBUGGING_ENABLED
		g_Logging.AddToLogFileA(dumpname, dvinfo);
		OutputDebugStringA(dvinfo);
		#else
		OutputDebugStringA(dvinfo);
		#endif

	}
	info("Done.");

	return true;
}
#pragma optimize("", on)

bool DumpDvarToFile(char * fname)
{
	return false;
}

bool DumpFuncsToFile(char * fname)
{
	return false;
}

bool FillListWithDvarsAndFuncs(char * FindStr)
{
	return false;
}





dvarSystem::dvarSystem()
{
	Inited = GetDvarAddingFuncs();

	if (Inited)
	{
		DvarCache = malloc(0x10000);
		memset(DvarCache, 0, 0x10000);
		CurrentPtr = 0;
	}
}

char * dvarSystem::CacheString(char * str)
{
	char * currentDest = (char *)((DWORD)DvarCache + CurrentPtr);

	strcpy(currentDest, str);

	CurrentPtr += strlen(str) + 1;

	return currentDest;
}

dvarBuff* dvarSystem::AddBool(char *dvarName, bool value, int flags, char *description)
{
	if (Inited)
	{
		char * name = CacheString(dvarName);
		char * desc = CacheString(description);

		return DvarAddBool(name, value, flags, desc);
	}
	return 0;
}

dvarBuff* dvarSystem::AddFloat(char *dvarName, float valueDef, float valueMin, float valueMax, int flags, char *description)
{
	if (Inited)
	{
		char * name = CacheString(dvarName);
		char * desc = CacheString(description);

		return DvarAddFloat(name, valueDef, valueMin, valueMax, flags, desc);
	}
	return 0;
}

dvarBuff* dvarSystem::AddInt(char *dvarName, int valueDef, int valueMin, int valueMax, int flags, char *description)
{
	if (Inited)
	{
		char * name = CacheString(dvarName);
		char * desc = CacheString(description);

		return DvarAddInt(name, valueDef, valueMin, valueMax, flags, desc);
	}
	return 0;
}

dvarBuff* dvarSystem::AddText(char *dvarName, char *valueDef, int flags, char *description)
{
	if (Inited)
	{
		char * name = CacheString(dvarName);
		char * desc = CacheString(description);
		char * value = CacheString(valueDef);

		return DvarAddText(name, value, flags, desc);
	}
	return 0;
}


bool LockIntDvarTo(char * name, int val)
{
	dvar dv_a(name);

	if (dv_a.Inited)
	{
		dv_a.SetDefValue(val);
		dv_a.SetMaxValue(val);
		dv_a.SetMinValue(val);
		dv_a.SetValue(val);
		return true;
	}

	return false;
}

bool LockFloatDvarTo(char * name, float val)
{
	dvar dv_a(name);

	if (dv_a.Inited)
	{
		dv_a.SetDefValue(val);
		dv_a.SetMaxValue(val);
		dv_a.SetMinValue(val);
		dv_a.SetValue(val);
		return true;
	}

	return false;
}