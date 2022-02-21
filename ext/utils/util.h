#pragma once
#include <Windows.h>
#include <iostream>
#include "../../source/SDK/sdk.h"
namespace console {
	inline FILE* F;
	inline void setColor(WORD color)
	{
		HANDLE pHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(pHandle, color);
	}
	inline void Init(const char* consoleTitle)
	{
		AllocConsole();
		SetConsoleTitle(consoleTitle);
		freopen_s(&F, "CONOUT$", "w", stdout);
	}
	inline void Detach()
	{
		if (F)
			fclose(F);
		FreeConsole();
	}
}

namespace modules {
	inline void setupModules()
	{
		client_module = (DWORD)(GetModuleHandle("client.dll"));
		engine_module = (DWORD)(GetModuleHandle("engine.dll"));
	}
}