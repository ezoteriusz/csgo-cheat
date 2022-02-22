#include <Windows.h>
#include "../../ext/minhook/MinHook.h"

namespace hooks {
	inline unsigned int get_virtual(void* _class, unsigned int index) { return static_cast<unsigned int>((*static_cast<int**>(_class))[index]); }
	void InitHooks();
	void UninitializeHooks();
}