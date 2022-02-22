#include "createmove.h"
#include "../SDK/sdk.h"
#include <iostream>
using namespace std;
bool __stdcall CreateMoveHook(float frametime, CUserCmd* cmd) {
	const bool result = CreateMoveOriginal(Interfaces::g_ClientMode, frametime, cmd); /// na bhopa if !0 then jump

	localPlayer = Interfaces::entityList->GetClientEntity(Interfaces::engine->get_local_player());
	if (result)
		Interfaces::engine->SetViewAngles(cmd->viewAngles);

	triggerbot::doTrigger(cmd);
	movement::bunnyhop(cmd);
	esp::renderEsp();
	glow::doGlow();
	misc::noFlash();

	return false;
}