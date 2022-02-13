#pragma once

using namespace SDK;

namespace NetHooks
{
	Beacon* BeaconHost;
	Replicator* NetReplicator;

	void(*UWorld_NotifyControlMessage)(UWorld* World, UNetConnection* NetConnection, uint8_t a3, void* a4);
	__int64(*WelcomePlayer)(UWorld* This, UNetConnection* NetConnection);
	APlayerController* (*SpawnPlayActor)(UWorld* a1, UPlayer* a2, ENetRole a3, FURL a4, void* a5, FString& Src, uint8_t a7);
	UReplicationDriver* (*CreateReplicationDriver)(UNetDriver*, FURL&, UWorld*);
	UObject* (*SCOI)(void*, void*, void*, int, unsigned int, void*, bool, void*, bool);

	UObject* SCOIHook(UObject* Outer, UObject* Class, void* a3, int a4, unsigned int a5, void* a6, bool a7, void* a8, bool a9) {
		if (Class) {
			printf("Class: (%s)\n", Class->GetFullName().c_str());
		}

		return SCOI(Outer, Class, a3, a4, a5, a6, a7, a8, a9);
	}

	void __fastcall AOnlineBeaconHost_NotifyControlMessageHook(AOnlineBeaconHost* BeaconHost, UNetConnection* NetConnection, uint8_t a3, void* a4)
	{
		if (TO_STRING(a3) == "4") {
			NetConnection->CurrentNetSpeed = 30000;
			return;
		}

		if (TO_STRING(a3) == "15") {
			return;
		}

		SULFUR_LOG("AOnlineBeaconHost::NotifyControlMessage Called! " << TO_STRING(a3).c_str());
		SULFUR_LOG("Channel Count " << TO_STRING(NetConnection->OpenChannels.Num()).c_str());
		return UWorld_NotifyControlMessage(Globals::World, NetConnection, a3, a4);
	}

	__int64 __fastcall WelcomePlayerHook(UWorld*, UNetConnection* NetConnection)
	{
		SULFUR_LOG("Welcoming Player!");
		return WelcomePlayer(Globals::World, NetConnection);
	}

	APlayerController* SpawnPlayActorHook(UWorld*, UNetConnection* Connection, ENetRole NetRole, FURL a4, void* a5, FString& Src, uint8_t a7)
	{
        auto PlayerController = SpawnPlayActor(Globals::World, Connection, NetRole, a4, a5, Src, a7);
		Connection->PlayerController = PlayerController;
		Connection->OwningActor = PlayerController;

        return PlayerController;
	}

	static void Init()
	{
		auto BaseAddr = Util::BaseAddress();

		UWorld_NotifyControlMessage = decltype(UWorld_NotifyControlMessage)(BaseAddr + UWORLD_NCM_OFFSET);
	
		auto AOnlineBeaconHost_NotifyControlMessageAddr = BaseAddr + AONLINEBEACONHOST_NCM_OFFSET;
		auto WelcomePlayerAddr = BaseAddr + WELCOME_PLAYER_OFFSET;
		auto SpawnPlayActorAddr = BaseAddr + SPAWN_PLAY_ACTOR_OFFSET;
		auto SCOIAddr = Util::FindPattern("4C 89 44 24 ? 53 55 56 57 41 54 41 56 41 57 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ?");

		SpawnPlayActor = decltype(SpawnPlayActor)(SpawnPlayActorAddr);

		MH_CreateHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr), AOnlineBeaconHost_NotifyControlMessageHook, nullptr);
		MH_EnableHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr));
		MH_CreateHook((void*)(WelcomePlayerAddr), WelcomePlayerHook, (void**)(&WelcomePlayer));
		MH_EnableHook((void*)(WelcomePlayerAddr));
		MH_CreateHook((void*)(SpawnPlayActorAddr), SpawnPlayActorHook, (void**)(&SpawnPlayActor));
		MH_EnableHook((void*)(SpawnPlayActorAddr));
		MH_CreateHook((void*)(SCOIAddr), SCOIHook, (void**)(&SCOI));
		MH_EnableHook((void*)(SCOIAddr));

		BeaconHost = new Beacon(7777);
		NetReplicator = new Replicator(BeaconHost);

		//FURL OutFURL;
		//auto ReplicationDriver = CreateReplicationDriver(BeaconHost->GetNetDriver(), OutFURL, Globals::World);
		//BeaconHost->GetNetDriver()->ReplicationDriver = ReplicationDriver;
	}
}
