#include "triggerbot.h"
#include "../SDK/sdk.h"
#include <Windows.h>

bool _stdcall triggerbot::doTrigger(CUserCmd* cmd)
{
	
	if (!Interfaces::engine->is_in_game() || !localPlayer->isAlive())
		return false;

		CTrace trace;
		CVector eyePos,aimPunch;
		localPlayer->getEyePosition(eyePos);
		localPlayer->getAimPunch(aimPunch);

		const CVector distance = eyePos + CVector{ cmd->viewAngles + aimPunch }.ToVector() * 1000.f;
		Interfaces::trace->TraceRay({ eyePos,distance }, 0x46004009, localPlayer, trace);

		if (!trace.entity || !trace.entity->isPlayer())
			return false;
		if (!trace.entity->isAlive() && trace.entity->getTeam() == localPlayer->getTeam())
			return false;

		cmd->buttons |= IN_ATTACK;

}
