//todo auto elements positioning
#include "menu.h"

auto do_frame = [&](std::int32_t x, std::int32_t y, std::int32_t w, std::int32_t h, color bg, color header_text, color header_line, const std::string& name) {
	render::draw_filled_rect(x, y, w, h, bg);
	render::draw_filled_rect(x, y, w, 30, header_text);
	render::draw_filled_rect(x, y + 30, w, 2, header_line);
	render::text(x + 10, y + 8, render::fonts::menu_font, name, false, color::white());
};

void menu::render() {
	if (!variables::menu::opened)
		return;

	do_frame(variables::menu::x, variables::menu::y, variables::menu::w, variables::menu::h, color(36, 36, 36, 255), color(25, 25, 25, 255), color(36, 36, 36, 255), "posejdon.pw v2");
	render::text(36, 1065, render::fonts::menu_font, "VER 1.3+ DEBUG", true, color::from_uint(D3DCOLOR_ARGB(150, 255, 255, 255)));
	menu_framework::group_box(variables::menu::x + 5, variables::menu::y + 35, 100, 260, render::fonts::menu_font, "tabs", false); {
		menu_framework::tab(variables::menu::x + 5, variables::menu::y + (260 / 2) - 35, 100, 30, render::fonts::menu_font, "aim assist", menu::current_tab, 0, false);
		menu_framework::tab(variables::menu::x + 5, variables::menu::y + (260 / 2), 100, 30, render::fonts::menu_font, "esp", menu::current_tab, 1, false);
		menu_framework::tab(variables::menu::x + 5, variables::menu::y + (260 / 2) + 35, 100, 30, render::fonts::menu_font, "misc", menu::current_tab, 2, false);
	}

	switch (current_tab) {
	case 0:
		menu_framework::group_box(variables::menu::x + 110, variables::menu::y + 35, 285, 260, render::fonts::menu_font, "aimbot", false); {
			menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 45, variables::menu::x + 375, render::fonts::menu_font, "Triggerbot", variables::cfg_triggerbot);
			menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 65, variables::menu::x + 375, render::fonts::menu_font, "Triggerbot delay", variables::cfg_trigger_bool_delay_bool);
			if (variables::cfg_trigger_bool_delay_bool)
			{
				menu_framework::slider(variables::menu::x + 120, variables::menu::y + 85, 120, render::fonts::menu_font, "Delay in ms", variables::cfg_triggerbot_delay, 0.f, 1.f);
			}
		}
		break;
	case 1:
		menu_framework::group_box(variables::menu::x + 110, variables::menu::y + 35, 285, 260, render::fonts::menu_font, "esp", false); {
			menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 45, variables::menu::x + 375, render::fonts::menu_font, "ESP", variables::cfg_esp);
			menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 70, variables::menu::x + 375, render::fonts::menu_font, "Glow", variables::cfg_glow);
			if (variables::cfg_glow)
			{
				menu_framework::slider(variables::menu::x + 120, variables::menu::y + 85, 120, render::fonts::menu_font, "R", variables::R, 0.0f, 1.0f);
				menu_framework::slider(variables::menu::x + 119, variables::menu::y + 100, 120, render::fonts::menu_font,"G", variables::G, 0.0f, 1.0f);
				menu_framework::slider(variables::menu::x + 120, variables::menu::y + 115, 120, render::fonts::menu_font, "B", variables::B, 0.0f, 1.0f);
				menu_framework::slider(variables::menu::x + 120, variables::menu::y + 130, 120, render::fonts::menu_font, "A", variables::A, 0.0f, 1.0f);
				menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 145, variables::menu::x + 375, render::fonts::menu_font, "Health", variables::cfg_glow_health);
			}
		}
		break;
	case 2:
		menu_framework::group_box(variables::menu::x + 110, variables::menu::y + 35, 285, 260, render::fonts::menu_font, "misc", false); {
			menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 45, variables::menu::x + 375, render::fonts::menu_font, "Auto Bunnyhop", variables::cfg_bunnyhop);
			menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 65, variables::menu::x + 375, render::fonts::menu_font, "Watermark", variables::cfg_watermark);
			menu_framework::check_box(variables::menu::x + 120, variables::menu::y + 85, variables::menu::x + 375, render::fonts::menu_font, "No Flash", variables::cfg_no_flash);
		}
		break;
	}

	menu_framework::menu_movement(variables::menu::x, variables::menu::y, variables::menu::w, 35);
}

void menu::toggle() {
	if (GetAsyncKeyState(VK_INSERT) & 1)
		variables::menu::opened = !variables::menu::opened;
}