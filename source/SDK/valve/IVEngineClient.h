#pragma once
#include "./CVector.h"

struct player_info_t {
	int64_t __pad0;
	union {
		int64_t xuid;
		struct {
			int xuidlow;
			int xuidhigh;
		};
	};
	char name[128];
	int userid;
	char guid[33];
	unsigned int friendsid;
	char friendsname[128];
	bool fakeplayer;
	bool ishltv;
	unsigned int customfiles[4];
	unsigned char filesdownloaded;
};

class IVEngineClient {
public:
	int get_local_player() {
		using original_fn = int(__thiscall*)(IVEngineClient*);
		return (*(original_fn**)this)[12](this);
	}
	int get_player_for_user_id(int user_id) {
		using original_fn = int(__thiscall*)(IVEngineClient*, int);
		return (*(original_fn**)this)[9](this, user_id);
	}
	void get_player_info(int index, player_info_t* info) {
		using original_fn = void(__thiscall*)(IVEngineClient*, int, player_info_t*);
		return (*(original_fn**)this)[8](this, index, info);
	}
	void get_screen_size(int& width, int& height) {
		using original_fn = void(__thiscall*)(IVEngineClient*, int&, int&);
		return (*(original_fn**)this)[5](this, width, height);
	}
	void execute_cmd(const char* cmd) {
		using original_fn = void(__thiscall*)(IVEngineClient*, const char*);
		return (*(original_fn**)this)[108](this, cmd); // this always seems to crash whilst debugging, just feel free to continue.
	}
	bool is_in_game() {
		using original_fn = bool(__thiscall*)(IVEngineClient*);
		return (*(original_fn**)this)[26](this);
	}
	constexpr void SetViewAngles(const CVector& viewangles) noexcept
	{
		memory::Call<void, const CVector&>(this, 19, viewangles);
	}
	int GetMaxClients()
	{
		typedef bool(__thiscall* oGetMaxClients)(PVOID);
		return call_vfunc< oGetMaxClients >(this, 20)(this);
	}
};