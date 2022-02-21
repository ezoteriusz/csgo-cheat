#include "misc.h"
#include "../SDK/sdk.h"
#include <iostream>
bool misc::noFlash()
{
	if (variables::cfg_no_flash)
	{
		if (!Interfaces::engine->is_in_game() || !localPlayer)
			return nullptr;
		*(float*)(localPlayer + m_flFlashMaxAlpha) = 0.f;
	}
	else if (variables::cfg_no_flash == false)
	{
		if (!Interfaces::engine->is_in_game() || !localPlayer)
			return nullptr;
		*(float*)(localPlayer + m_flFlashMaxAlpha) = 255.f;
	}
	return false;
}
