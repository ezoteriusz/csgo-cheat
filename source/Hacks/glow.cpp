#include "../SDK/sdk.h"
#include <Windows.h>
#include "glow.h"
void glow::doGlow()
{
	uintptr_t glowobj = *(uintptr_t*)(client_module + dwGlowObjectManager);

	for (int i = 1; i <= 64; i++)
	{
		auto entity = Interfaces::entityList->GetClientEntity(i);
		if (!entity || !Interfaces::engine->is_in_game())
			continue;
		 if (localPlayer->getTeam() != entity->getTeam() && entity->getHealth() > 0 && entity->getHealth() <= 100)
		{
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x8)) = 0.3f;//R            // 0.3f
 			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0xC)) = 1.f;//G			   // 1.f
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x10)) = 0.f;//B
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x14)) = 0.7f;//A           // 0.6f
		}
		if(localPlayer->getTeam() != entity->getTeam() && entity->getHealth() > 0 && entity->getHealth() < 50)
		{
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x8)) = 1.f;//R
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0xC)) = 0.3f;//G
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x10)) = 0.f;//B
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x14)) = 0.7f;//A
		}
		if (localPlayer->getTeam() != entity->getTeam() && entity->getHealth() > 0 && entity->getHealth() < 25)
		{
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x8)) = 1.f;//R
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0xC)) = 0.f;//G
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x10)) = 0.f;//B
			*(float*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x14)) = 0.7f;//A
		}
		*(bool*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x28)) = true;
		*(bool*)(glowobj + ((entity->getGlowIndex() * 0x38) + 0x29)) = false;
	}
}
