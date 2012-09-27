#pragma once

#define STACK_RETURN 9
#define STACK_EAX               8
#define STACK_ECX               7
#define STACK_EDX               6
#define STACK_EBX               5
#define STACK_ESP               4
#define STACK_EBP               3
#define STACK_ESI               2
#define STACK_EDI               1
#define STACK_EFLAGS		  0

static const char *STACK_REGNAME[] = {"eflags", "edi", "esi", "ebp", "esp", "ebx", "edx", "ecx", "eax", "return"};

#ifdef KERNEL
#include "ntifs.h"
#include "types.h"
#else
#include <windows.h>
#endif

DWORD makeTramp(void *addr, void *tramp, char *errormsg = NULL, DWORD numBytes = 5, bool jumpBack = true);
bool writeJump(void *addr, const void *trampoline, void *oldCode = NULL, void *newCode = NULL);
bool removeHook(void *addr, const void *oldCode = NULL, const void *newCode = NULL, DWORD numBytes = 5);

bool hookPre(void *addr, const void *hookProc, void *oldCode = NULL, void *newCode = NULL);
bool hookNoTramp(void *addr, const void *hookProc, void *oldCode = NULL, void *newCode = NULL);
bool hook(void *addr, const void *hookproc, char *errormsg = NULL, void *oldCode = NULL, void *newCode = NULL);
bool hook_cdecl(void *addr, const void *hookproc, char *errormsg = NULL, void *oldCode = NULL, void *newCode = NULL);
DWORD cloneFuncAndFixToTrue(void *addr, const void *hookproc, char *errormsg = NULL, void *oldCode = NULL, void *newCode = NULL);