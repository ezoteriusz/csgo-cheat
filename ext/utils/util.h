#pragma once
#include <Windows.h>
#include <iostream>
DWORD client_module;
DWORD engine_module;
namespace console {
	FILE* F;
	void setColor(WORD color)
	{
		HANDLE pHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(pHandle, color);
	}
	void Init(const char* consoleTitle)
	{
		AllocConsole();
		SetConsoleTitle(consoleTitle);
		freopen_s(&F, "CONOUT$", "w", stdout);
	}
	void Detach()
	{
		if (F)
			fclose(F);
		FreeConsole();
	}
}

namespace modules {
	void setupModules()
	{
		client_module = (DWORD)(GetModuleHandle("client.dll"));
		engine_module = (DWORD)(GetModuleHandle("engine.dll"));
	}
}