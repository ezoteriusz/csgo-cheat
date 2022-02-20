#pragma once
#include "../SDK/usercmd.h"
using CreateMove = bool(__thiscall*)(void*, float, UserCmd*);
inline CreateMove CreateMoveOriginal = nullptr;

bool __stdcall CreateMoveHook(float frametime, UserCmd* cmd);