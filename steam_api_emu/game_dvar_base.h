#pragma once
#include "stdafx.h"


enum dvarTypes {
	DVAR_BOOL,  //0
	DVAR_FLOAT, //1
	DVAR_2D_VECTOR,  //2
	DVAR_3D_VECTOR_A, // 3 float:0..2
	DVAR_4D_VECTOR,  //4 float:0..1
	DVAR_INT,   //5
	DVAR_OPTIONS,  //6
	DVAR_TEXT,   //7
	DVAR_RGBA_COLOR, // 8
	DVAR_3D_VECTOR_B // 9 float:0..2
};

/*
FLAGS:
00000000000001=A (??)
00000000000010=L (needs restart)
00000000000100=C (cheat prot)   -- internal
00001000000000=U (??)
00010000000000=S (system)
00100000000000=I (write prot)
01000000000000=P (cant change)
10000000000000=R (read only)+

10111000000111=2E07 (all flags on)
*/

//#define DVF_A 1;
//#define DVF_L 2;
//#define DVF_C 4;
//#define DVF_U 0x200;
//#define DVF_S 0x400;
//#define DVF_I 0x800;
//#define DVF_R 0x2000;
//#define DVF_PRINTABLE 0x10000;

enum dvarFlags {
	DVF_A = 1,
	DVF_L = 2,
	DVF_C = 4,
	DVF_U = 0x200,
	DVF_S = 0x400,
	DVF_I = 0x800,
	DVF_R = 0x2000,
	DVF_PRINTABLE = 0x10000
};


struct dvarValue {
	union
	{
		DWORD valueDW;
		float valueFL;
		char * valueSTR;
	};
	DWORD unk1; // these unks are probably used in extended/floats
	DWORD unk2;
	DWORD unk3;
};

struct dvarBuff {
	char *name;
	//char *description;
	DWORD Flags;
	BYTE type;
	BYTE unk2;
	WORD unk3;
	dvarValue ValA;
	dvarValue ValB;
	dvarValue DefaultVal;
	union
	{
		DWORD ValMinDW;
		float ValMinFL;
		char * valueSTR;
	};
	union
	{
		DWORD ValMaxDW;
		float ValMaxFL;
		char * valueSTR;
	};
};

class dvar {
	private:
		//bool IsLocked;
		//DWORD LockedMin;
		//DWORD LockedMax;
		//DWORD LockedCurr;
		char ValueAsString[2048];
	public:
		bool Inited;
		dvarBuff * data;
		dvar ();
		dvar (char *);
		dvar (int);
		bool Init(char *);
		//bool LockValAt(int);
		//bool LockValAt(float);
		//bool UnlockVal();
		bool SetValue(int);
		bool SetValue(float);
		bool SetValue(char*);
		bool SetValue(bool);
		bool SetMinValue(int);
		bool SetMaxValue(int);
		bool SetDefValue(int);
		bool SetMinValue(float);
		bool SetMaxValue(float);
		bool SetDefValue(float);
		bool SetMinValue(bool);
		bool SetMaxValue(bool);
		bool SetDefValue(bool);
		DWORD GetValueDW();
		float GetValueFL();
		char* GetValueSTR();
		char* GetValueAsString();
};

bool DumpDvarToFile();
bool MakeAllDvarsPrintable();

typedef dvarBuff* (*MYDVARADDTEXT)(char * dvarName, char * value, int flags, char * description);
extern MYDVARADDTEXT DvarAddText;

typedef dvarBuff* (*MYDVARADDBOOL)(char * dvarName, bool value, int flags, char * description);
extern MYDVARADDBOOL DvarAddBool;

typedef dvarBuff* (*MYDVARADDFLOAT)(char * dvarName, float valueDef, float valueMin, float valueMax, int flags, char * description);
extern MYDVARADDFLOAT DvarAddFloat;

typedef dvarBuff* (*MYDVARADDINT)(char * dvarName, int valueDef, int valueMin, int valueMax, int flags, char * description);
extern MYDVARADDINT DvarAddInt;

class dvarSystem {
	private:
		void * DvarCache;
		DWORD CurrentPtr;
		bool Inited;
		char * CacheString(char *);
	public:
		dvarSystem ();
		dvarBuff* AddText(char * dvarName, char * value, int flags, char * description);
		dvarBuff* AddBool(char * dvarName, bool value, int flags, char * description);
		dvarBuff* AddFloat(char * dvarName, float valueDef, float valueMin, float valueMax, int flags, char * description);
		dvarBuff* AddInt(char * dvarName, int valueDef, int valueMin, int valueMax, int flags, char * description);
};

bool LockIntDvarTo(char * name, int val);
bool LockFloatDvarTo(char * name, float val);

extern dvarSystem DvarSys;