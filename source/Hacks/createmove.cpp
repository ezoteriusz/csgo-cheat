#include "createmove.h"
#include "../SDK/sdk.h"
#include <iostream>
using namespace std;
bool __stdcall CreateMoveHook(float frametime, UserCmd* cmd) {
	//	const bool result = CreateMoveOriginal(g_ClientMode, frametime, cmd); /// na bhopa if !0 then jump

	localPlayer = static_cast<CEntity*>(entityList->GetClientEntity(engine->get_local_player()));

	movement::bunnyhop(cmd);
	esp::renderEsp();
	glow::doGlow();
	
	return false;
}