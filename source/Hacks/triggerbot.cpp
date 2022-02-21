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

		const CVector distance = eyePos + CVector{ cmd->viewAngles + aimPunch }.ToVector() * 999999.f;
		Interfaces::trace->TraceRay({ eyePos,distance }, 0x46004009, localPlayer, trace);

		if (!trace.entity || !trace.entity->isPlayer())
			return false;  
		if (!trace.entity->isAlive())
			return false;
		if (trace.entity->getTeam() == localPlayer->getTeam())
			return false;
		if (trace.hitgroup != 1)
			return false;
		console::setColor(2);
		std::cout << "[" << trace.entity << "]\n";
		console::setColor(4);
		std::cout << "[HITGROUP] " << trace.hitgroup << "\n";
		std::cout << "\n";
		cmd->buttons |= IN_ATTACK;
		return false;
}
