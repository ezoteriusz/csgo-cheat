#include "hooks.h"
#include "SDK/sdk.h"
#include <stdexcept>
namespace hooks {
	void InitHooks()
	{
		MH_Initialize();
		MH_CreateHook(
			(*static_cast<void***>(Interfaces::g_ClientMode))[24],
			&CreateMoveHook,
			reinterpret_cast<void**>(&CreateMoveOriginal));
		MH_EnableHook(MH_ALL_HOOKS);
	}
	void UninitializeHooks()
	{
		MH_DisableHook(MH_ALL_HOOKS);
		MH_RemoveHook(MH_ALL_HOOKS);
		MH_Uninitialize();
	}
}