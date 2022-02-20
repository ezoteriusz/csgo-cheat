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
	  inline void setupInterfaces() {
		g_Client = GetInterface<void>("VClient018", "client.dll");
		g_ClientMode = **reinterpret_cast<void***>((*reinterpret_cast<unsigned int**>(g_Client))[10] + 5);
		entityList = GetInterface<IClientEntityList>("VClientEntityList003", "client.dll");
		gpDebugOverlay = GetInterface<IVDebugOverlay>("VDebugOverlay004", "engine.dll");
		engine = GetInterface<IVEngineClient>("VEngineClient014", "engine.dll");
	}
}
