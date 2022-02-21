#pragma once
#include <Windows.h>
#include <cstdlib>
#include <float.h>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iostream>
#include "../../ext/utils/mem.h"





#include "../Hacks/triggerbot.h"
#include "../Hacks/glow.h"
#include "../Hacks/radarhack.h"
#include "../Hacks/esp.h"
#include "../Hacks/bunnyhop.h"
#include "../Hacks/createmove.h"
#include "netvars.h"

#include "valve/IVEngineTraceRay.h"
#include "valve/IVEngineClient.h"
#include "valve/CEntity.h"
#include "valve/IClientEntityList.h"
#include "valve/IVDebugOverlay.h"
#include "usercmd.h"


extern DWORD client_module;
extern DWORD engine_module;
#include "interfaces.h" // KURWA NIE RUSZAJ TEGO BO CI WYJEBIE KOPA


inline CEntity* localPlayer = nullptr;