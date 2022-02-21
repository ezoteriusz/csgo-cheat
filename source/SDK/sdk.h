#pragma once
#include <Windows.h>
#include <cstdlib>
#include <float.h>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iostream>

inline DWORD client_module;
inline DWORD engine_module;
template< typename Function > Function call_vfunc(PVOID Base, DWORD Index) 
{
	PDWORD* VTablePointer = (PDWORD*)Base;
	PDWORD VTableFunctionBase = *VTablePointer;
	DWORD dwAddress = VTableFunctionBase[Index];
	return (Function)(dwAddress);
}

#include "../SDK/menu/verbs.h"
#include "../../ext/utils/mem.h"
#include "../../ext/utils/util.h"
#include "../../ext/utils/fnv.h"

#include "../Hacks/triggerbot.h"
#include "../Hacks/glow.h"
#include "../Hacks/radarhack.h"
#include "../Hacks/esp.h"
#include "../Hacks/bunnyhop.h"


#include "createmove.h"
#include "netvars.h"

#include "valve/ISurface.h"
#include "valve/IPanel.h"
#include "valve/IVEngineTraceRay.h"
#include "valve/IVEngineClient.h"
#include "valve/CEntity.h"
#include "valve/IClientEntityList.h"
#include "valve/IVDebugOverlay.h"
#include "usercmd.h"
#include "paintTraverse.h"
#include "interfaces.h" // KURWA NIE RUSZAJ TEGO BO CI WYJEBIE KOPA


inline CEntity* localPlayer = nullptr;