#pragma once

using namespace SDK;

namespace NetHooks
{
	Beacon* BeaconHost;
	Replicator* NetReplicator;

	void(*UWorld_NotifyControlMessage)(UWorld* World, UNetConnection* NetConnection, uint8_t a3, void* a4);
	__int64(*WelcomePlayer)(UWorld* This, UNetConnection* NetConnection);
	APlayerController* (*SpawnPlayActor)(UWorld* a1, UPlayer* a2, ENetRole a3, FURL a4, void* a5, FString& Src, uint8_t a7);

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
		NetReplicator->ReplicateActor(Globals::World->GameState, Connection);

        auto PlayerController = SpawnPlayActor(Globals::World, Connection, NetRole, a4, a5, Src, a7);
		Connection->PlayerController = PlayerController;
		Connection->OwningActor = PlayerController;

		NetReplicator->ReplicateActor(PlayerController, Connection);
		NetReplicator->ReplicateActor(PlayerController->Pawn, Connection);

        return PlayerController;
	}

	static void Init()
	{
		auto BaseAddr = Util::BaseAddress();

		UWorld_NotifyControlMessage = decltype(UWorld_NotifyControlMessage)(BaseAddr + UWORLD_NCM_OFFSET);
	
		auto AOnlineBeaconHost_NotifyControlMessageAddr = BaseAddr + AONLINEBEACONHOST_NCM_OFFSET;
		auto WelcomePlayerAddr = BaseAddr + WELCOME_PLAYER_OFFSET;
		auto SpawnPlayActorAddr = BaseAddr + SPAWN_PLAY_ACTOR_OFFSET;

		SpawnPlayActor = decltype(SpawnPlayActor)(SpawnPlayActorAddr);

		MH_CreateHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr), AOnlineBeaconHost_NotifyControlMessageHook, nullptr);
		MH_EnableHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr));
		MH_CreateHook((void*)(WelcomePlayerAddr), WelcomePlayerHook, (void**)(&WelcomePlayer));
		MH_EnableHook((void*)(WelcomePlayerAddr));
		MH_CreateHook((void*)(SpawnPlayActorAddr), SpawnPlayActorHook, (void**)(&SpawnPlayActor));
		MH_EnableHook((void*)(SpawnPlayActorAddr));

		BeaconHost = new Beacon(7777);
		NetReplicator = new Replicator(BeaconHost);
	}
}
