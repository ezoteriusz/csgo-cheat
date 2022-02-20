#include "../SDK/sdk.h"
#include <Windows.h>
#include "esp.h"
std::string critical = "CRITICAL!";
std::string dormAnt = "LAST SEEN";
void esp::renderEsp()
{
	for (int i = 1; i <= 64; i++)
	{
		auto Player = entityList->GetClientEntity(i);
		if (!Player || !engine->is_in_game() || !localPlayer)
			continue;
		player_info_t info;
		engine->get_player_info(i, &info);
		std::stringstream health;
		health << Player->getHealth();
		std::string healthString = "HP:" + health.str();
		char* healthRead = (char*)healthString.c_str();
		char* Critical = (char*)critical.c_str();
		char* Dormant = (char*)dormAnt.c_str();
		if (Player->getTeam() != localPlayer->getTeam() && Player->getHealth() > 0 && Player->getHealth() <= 100 && Player->getHealth() > 25 && Player->getDormant() == true)
		{
			gpDebugOverlay->AddEntityTextOverlay(i, -2, 0, 150, 0, 255, 255, info.name);
			gpDebugOverlay->AddEntityTextOverlay(i, -1, 0, 0, 255, 100, 255, healthRead);
			gpDebugOverlay->AddEntityTextOverlay(i, -5, 0, 255, 255, 255, 255, Dormant);
			//gpDebugOverlay->AddEntityTextOverlay(i, 2, 0, 255, 255, 255, 255, info.guid); steam id meme
		}
		else if (Player->getTeam() != localPlayer->getTeam() && Player->getHealth() > 0 && Player->getHealth() <= 100 && Player->getHealth() > 25 && Player->getDormant() == false)
		{
			gpDebugOverlay->AddEntityTextOverlay(i, -2, 0, 150, 0, 255, 255, info.name);
			gpDebugOverlay->AddEntityTextOverlay(i, -1, 0, 0, 255, 100, 255, healthRead);
			//gpDebugOverlay->AddEntityTextOverlay(i, 2, 0, 255, 255, 255, 255, info.guid); steam id meme
		}
		else if (Player->getTeam() != localPlayer->getTeam() && Player->getHealth() > 0 && Player->getHealth() < 25 && Player->getDormant() == true)
		{
			gpDebugOverlay->AddEntityTextOverlay(i, -2, 0, 150, 0, 255, 255, info.name);
			gpDebugOverlay->AddEntityTextOverlay(i, -1, 0, 255, 0, 0, 255, Critical);
			gpDebugOverlay->AddEntityTextOverlay(i, -5, 0, 255, 255, 255, 255, Dormant);
		}
		else if (Player->getTeam() != localPlayer->getTeam() && Player->getHealth() > 0 && Player->getHealth() < 25 && Player->getDormant() == false)
		{
			gpDebugOverlay->AddEntityTextOverlay(i, -2, 0, 150, 0, 255, 255, info.name);
			gpDebugOverlay->AddEntityTextOverlay(i, -1, 0, 255, 0, 0, 255, Critical);
		}

	}
}
