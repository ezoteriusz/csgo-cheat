#pragma once
#include <Windows.h>
#include <cstdlib>
#include <float.h>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iostream>
#include "../SDK/math/vector2d.h"
#include "../SDK/math/vector3d.h"
#include "../SDK/math/vertex2.h"
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

#include "../Hacks/misc.h"
#include "../Hacks/triggerbot.h"
#include "../Hacks/glow.h"
#include "../Hacks/radarhack.h"
#include "../Hacks/esp.h"
#include "../Hacks/bunnyhop.h"


#include "../Hooks/createmove.h"
#include "../SDK/valve/netvars.h"

#include "valve/ISurface.h"
#include "valve/IPanel.h"
#include "valve/IVEngineTraceRay.h"
#include "valve/IVEngineClient.h"
#include "valve/CEntity.h"
#include "valve/IClientEntityList.h"
#include "valve/IVDebugOverlay.h"
#include "../SDK/valve/usercmd.h"
#include "../Hooks/paintTraverse.h"
#include "interfaces/interfaces.h" // KURWA NIE RUSZAJ TEGO BO CI WYJEBIE KOPA

inline CEntity* localPlayer = nullptr;