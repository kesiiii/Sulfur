#pragma once

#include "Struct.h"
#include "UE4.h"
#include "Enums.h"
#include "Functions.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include "minhook/MinHook.h"
#pragma comment(lib, "minhook/minhook.lib")

namespace NetHooks
{
	void(*UWorld_NotifyControlMessage)(UObject* World, UNetConnection* NetConnection, uint8_t a3, void* a4);
	__int64(*WelcomePlayer)(UObject* This, UNetConnection* NetConnection);
	UObject* (*SpawnPlayActor)(UObject* a1, UObject* a2, ENetRole a3, void* a4, void* a5, FString& Src, uint8_t a7);

	void __fastcall AOnlineBeaconHost_NotifyControlMessageHook(AOnlineBeaconHost* BeaconHost, UNetConnection* NetConnection, uint8_t a3, void* a4)
	{
		printf("LogUGS: AOnlineBeaconHost::NotifyControlMessage Called! (%s)\n", std::to_string(a3).c_str());
		printf("LogUGS: Channel count (%s)\n", std::to_string(NetConnection->OpenChannels.Num()).c_str());
		return UWorld_NotifyControlMessage(GetWorld(), NetConnection, a3, a4);
	}

	__int64 __fastcall WelcomePlayerHook(UObject* world, UNetConnection* NetConnection)
	{
		printf("LogUGS: Welcoming Player!\n");
		return WelcomePlayer(GetWorld(), NetConnection);
	}

	UObject* SpawnPlayActorHook(UObject* a1, UObject* a2, ENetRole a3, void* a4, void* a5, FString& Src, uint8_t a7)
	{
		printf("LogUGS: SpawnPlayActor Called!\n");
		return SpawnPlayActor(GetWorld(), a2, a3, a4, a5, Src, a7);
	}

	static void Init()
	{
		auto BaseAddr = (uintptr_t)(GetModuleHandle(0));
		auto UWorld_NotifyControlMessageAddr = BaseAddr + 0x29E27A0;
		auto SpawnPlayActorAddr = BaseAddr + 0x2692430;
		auto WelcomePlayerAddr = BaseAddr + 0x29EFE00;
		auto AOnlineBeaconHost_NotifyControlMessageAddr = BaseAddr + 0x40FEE0;

		UWorld_NotifyControlMessage = decltype(UWorld_NotifyControlMessage)(UWorld_NotifyControlMessageAddr);
		SpawnPlayActor = decltype(SpawnPlayActor)(SpawnPlayActorAddr);
		WelcomePlayer = decltype(WelcomePlayer)(WelcomePlayerAddr);

		MH_CreateHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr), AOnlineBeaconHost_NotifyControlMessageHook, nullptr);
		MH_EnableHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr));
		MH_CreateHook((void*)(WelcomePlayerAddr), WelcomePlayerHook, (void**)(&WelcomePlayer));
		MH_EnableHook((void*)(WelcomePlayerAddr));
		MH_CreateHook((void*)(SpawnPlayActorAddr), SpawnPlayActorHook, (void**)(&SpawnPlayActor));
		MH_EnableHook((void*)(SpawnPlayActorAddr));

		printf("LogUGS: Setup NetHooks!\n");
	}
}