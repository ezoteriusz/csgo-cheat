#include "bunnyhop.h"
#include "../SDK/sdk.h"
#include <iostream>

void movement::bunnyhop(UserCmd* cmd)
{
	if (!(localPlayer->getFlags() & fl_onground))
		cmd->buttons &= ~IN_JUMP;
}
