#pragma once
#include "minhook/MinHook.h"

#pragma comment(lib, "minhook/MinHook.lib")

namespace Beacons
{
	bool (*InitHost)(AOnlineBeaconHost*);
	void (*PauseBeaconRequest)(AOnlineBeacon*, bool);

	static void Init()
	{
		auto BaseAddr = (uintptr_t)GetModuleHandle(0);
		InitHost = decltype(InitHost)(BaseAddr + 0x40C5F0);
		PauseBeaconRequest = decltype(PauseBeaconRequest)(BaseAddr + 0x1099910);

		auto Beacon = static_cast<AOnlineBeaconHost*>(SpawnActor(UObject::FindObjectFullName("Class OnlineSubsystemUtils.OnlineBeaconHost"), FVector(0, 0, 20932), FRotator()));
		Beacon->ListenPort = 7777;
		std::cout << "BeaconRes: " << Beacons::InitHost(Beacon) << std::endl;
		
		PauseBeaconRequest(Beacon, false);

		printf("LogUGS: Setup Beacons!\n");
	}
}