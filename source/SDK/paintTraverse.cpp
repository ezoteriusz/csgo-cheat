#include "../SDK/sdk.h"
#include "menu/menu.h"
void __stdcall PaintTraversehook(unsigned int panel, bool force_repaint, bool allow_force)
{
	auto panel_to_draw = fnv::hash(Interfaces::panel->get_panel_name(panel));
	std::stringstream hp;
	hp <<__DATE__<<" "<<__TIME__;
	std::string t1 = "posejdon.pw v2 " + hp.str();
	const char* watermark = (char*)t1.c_str();
	switch (panel_to_draw) {
	case fnv::hash("MatSystemTopPanel"):
		int screenH, screenW;
		Interfaces::engine->get_screen_size(screenH, screenW);
		if (variables::cfg_watermark){
			render::text(100, 10, render::fonts::watermark_font, watermark, true, color::from_uint(D3DCOLOR_ARGB(150, 255, 255, 255)));
		}
		menu::toggle();
		menu::render();
		break;

	case fnv::hash("FocusOverlayPanel"):
		//Interfaces::panel->set_keyboard_input_enabled(panel, variables::menu::opened);
		Interfaces::panel->set_mouse_input_enabled(panel, variables::menu::opened);
		break;
	}

	paint_traverse_original(Interfaces::panel, panel, force_repaint, allow_force);
}