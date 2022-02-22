#include <Windows.h>
#include <thread>
#include "../ext/utils/util.h"
#include "Hooks/hooks.h"
#include "SDK/sdk.h"
#include "SDK/menu/verbs.h"



void startThread(const HMODULE hInstance)
{
	console::Init("debugger");
	modules::setupModules();
	std::cout << "\aWelcome back!\n";
	std::cout << "build " << __DATE__ << " " << __TIME__ << "\n";
	std::cout << "version DEBUG" << "\n";
	std::cout << "\n";
	try {
		Interfaces::setupInterfaces();
		render::initialize();
		hooks::InitHooks();
	}
	catch (const std::runtime_error& error) {
		MessageBoxA(nullptr, error.what(), "crash!", MB_OK | MB_ICONERROR);
		variables::menu::opened = false;
		hooks::UninitializeHooks();
		console::Detach();
		FreeLibraryAndExitThread(hInstance, 0);
	}

	while (!GetAsyncKeyState(VK_DELETE)) {

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	variables::menu::opened = false;
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	hooks::UninitializeHooks();
	console::Detach();
	FreeLibraryAndExitThread(hInstance,0);
}


BOOL WINAPI DllMain(HMODULE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hInstance);
		HANDLE pThread = CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(startThread), hInstance, 0, nullptr);
		if (pThread)
			CloseHandle(pThread);
	}
	return TRUE;
}