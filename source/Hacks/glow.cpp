#include "../SDK/sdk.h"
#include <Windows.h>
#include "glow.h"

void glow::doGlow()
{
	uintptr_t glowobj = *(uintptr_t*)(client_module + dwGlowObjectManager);

	for (int i = 1; i <= 64; i++)
	{
		auto entity = entityList->GetClientEntity(i);
		if (!entity || !engine->is_in_game())
			continue;
		if (localPlayer->getTeam() != entity->getTeam())
		{
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x8)) = 0.3f;//R
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0xC)) = 1.f;//G
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x10)) = 0.f;//B
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x14)) = 0.6f;//A
		}
		*(bool*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x28)) = true;
		*(bool*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x29)) = false;
	}
}
