#pragma once
#include "../SDK/usercmd.h"
using CreateMove = bool(__thiscall*)(void*, float, CUserCmd*);
inline CreateMove CreateMoveOriginal = nullptr;

bool __stdcall CreateMoveHook(float frametime, CUserCmd* cmd);