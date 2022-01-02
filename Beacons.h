#pragma once
#include "minhook/MinHook.h"

#pragma comment(lib, "minhook/MinHook.lib")

namespace Beacons
{
	bool (*InitHost)(AOnlineBeaconHost*);

	static void Init()
	{
		auto BaseAddr = (uintptr_t)GetModuleHandle(0);
		InitHost = decltype(InitHost)(BaseAddr + 0x40C5F0);
	}
}