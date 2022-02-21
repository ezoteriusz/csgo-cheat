#pragma once
#include "framework.h"
#include "verbs.h"
#include "../../../ext/utils/util.h"

namespace menu {
	inline int current_tab{ 0 };

	void render();
	void toggle();
};