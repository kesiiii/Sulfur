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

		auto Beacon = static_cast<AOnlineBeaconHost*>(SpawnActor(UObject::FindObjectFullName("Class OnlineSubsystemUtils.OnlineBeaconHost"), FVector(0, 0, 20932), FRotator()));
		Beacon->ListenPort = 7777;
		std::cout << "BeaconRes: " << Beacons::InitHost(Beacon) << std::endl;
		Beacon->BeaconState = EBeaconState::AllowRequests;

		printf("LogUGS: Setup Beacons!\n");
	}
}