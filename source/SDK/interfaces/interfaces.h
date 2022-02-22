#include "sdk.h"


template <typename T>
T* GetInterface(const char* name, const char* lib)
{
	const auto pHandle = GetModuleHandle(lib);
	if (!pHandle)
		return nullptr;
	const auto functionAddress = GetProcAddress(pHandle, "CreateInterface");
	if (!functionAddress)
		return nullptr;
	using Fn = T * (*)(const char*, int*);
	const auto CreateInterface = reinterpret_cast<Fn>(functionAddress);

	return CreateInterface(name, nullptr);
}


namespace Interfaces {
	inline void* g_Client = nullptr;
	inline void* g_ClientMode = nullptr;
	inline i_panel* panel = nullptr;
	inline IClientEntityList* entityList = nullptr;
	inline IVDebugOverlay* gpDebugOverlay = nullptr;
	inline IVEngineClient* engine = nullptr;
	inline i_surface* surface = nullptr;
	inline IEngineTraceClient* trace = nullptr;
	  inline void setupInterfaces() {
		g_Client = GetInterface<void>("VClient018", "client.dll");
		g_ClientMode = **reinterpret_cast<void***>((*reinterpret_cast<unsigned int**>(g_Client))[10] + 5);
		entityList = GetInterface<IClientEntityList>("VClientEntityList003", "client.dll");
		gpDebugOverlay = GetInterface<IVDebugOverlay>("VDebugOverlay004", "engine.dll");
		trace = GetInterface<IEngineTraceClient>("EngineTraceClient004", "engine.dll");
		panel = GetInterface<i_panel>("VGUI_Panel009","vgui2.dll");
		surface = GetInterface<i_surface>("VGUI_Surface031", "vguimatsurface.dll");
		engine = GetInterface<IVEngineClient>("VEngineClient014", "engine.dll");
	}
}
