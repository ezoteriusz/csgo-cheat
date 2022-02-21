#pragma once

namespace variables {
	inline bool test_bool = false;
	inline float R;
	inline float G;
	inline float B;
	inline float A;
	inline bool cfg_bunnyhop = false;
	inline bool cfg_esp = false;
	inline bool cfg_glow = false;
	inline bool cfg_watermark = true;
	inline bool cfg_triggerbot = false;
	inline bool cfg_trigger_bool_delay_bool = false;
	inline float cfg_triggerbot_delay;

	namespace menu {
		inline bool opened = false;
		inline int x = 140, y = 140;
		inline int w = 400, h = 300;
	}
}