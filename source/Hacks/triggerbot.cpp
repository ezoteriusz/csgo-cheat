#include "triggerbot.h"
#include "../SDK/sdk.h"
#include <Windows.h>

bool _stdcall triggerbot::doTrigger(CUserCmd* cmd)
{
	if (variables::cfg_triggerbot) {
		if (!Interfaces::engine->is_in_game() || !localPlayer->isAlive())
			return false;

		CTrace trace;
		CVector eyePos, aimPunch;
		localPlayer->getEyePosition(eyePos);
		localPlayer->getAimPunch(aimPunch);

		const CVector distance = eyePos + CVector{ cmd->viewAngles + aimPunch }.ToVector() * 999999.f;
		Interfaces::trace->TraceRay({ eyePos,distance }, 0x46004009, localPlayer, trace);

		if (!trace.entity || !trace.entity->isPlayer())
			return false;
		if (!trace.entity->isAlive())
			return false;
		if (trace.entity->getTeam() == localPlayer->getTeam())
			return false;
		/*if (trace.hitgroup != 1)
			return false;*/
			cmd->buttons |= IN_ATTACK;
	}
		return false;
}
