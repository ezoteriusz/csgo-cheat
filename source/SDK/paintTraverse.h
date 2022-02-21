#include "sdk.h"
#include "../SDK/usercmd.h"

using fn = void(__thiscall*)(i_panel*, unsigned int, bool, bool);
inline fn paint_traverse_original = nullptr;

void __stdcall PaintTraversehook(unsigned int panel, bool force_repaint, bool allow_force);
