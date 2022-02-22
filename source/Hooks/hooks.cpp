#include "hooks.h"
#include "SDK/sdk.h"
#include <stdexcept>

namespace hooks {
	void InitHooks()
	{
		const auto paint_traverse_target = reinterpret_cast<void*>(get_virtual(Interfaces::panel, 41));
		const auto create_move_target = reinterpret_cast<void*>(get_virtual(Interfaces::g_ClientMode, 24));

		if (MH_Initialize() != MH_OK)
			throw std::runtime_error("failed to initialize MH_Initialize.");

		if (MH_CreateHook(create_move_target, &CreateMoveHook, reinterpret_cast<void**>(&CreateMoveOriginal)) != MH_OK)
			throw std::runtime_error("failed to initialize create_move. (outdated index?)");

		if (MH_CreateHook(paint_traverse_target, &PaintTraversehook, reinterpret_cast<void**>(&paint_traverse_original)) != MH_OK)
			throw std::runtime_error("failed to initialize paint_traverse. (outdated index?)");

		if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
			throw std::runtime_error("failed to enable hooks.");
	}
	void UninitializeHooks()
	{
		MH_DisableHook(MH_ALL_HOOKS);
		MH_RemoveHook(MH_ALL_HOOKS);
		MH_Uninitialize();
	}
}