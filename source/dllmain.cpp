#include <Windows.h>
#include <thread>
#include "../ext/utils/util.h"
#include "hooks.h"
#include "SDK/sdk.h"



void startThread(const HMODULE hInstance)
{
	console::Init("debugger");
	modules::setupModules();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	Interfaces::setupInterfaces();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	hooks::InitHooks();
	std::cout << "\aWelcome back owner!\n";
	std::cout << "build " << __DATE__ << " " << __TIME__ << "\n";
	std::cout << "version debug" << "\n";
	std::cout << "\n";
	while (!GetAsyncKeyState(VK_DELETE)) {

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
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