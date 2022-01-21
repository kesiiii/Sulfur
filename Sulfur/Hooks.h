#pragma once

#include "SDK.hpp"

#include "minhook/MinHook.h"

#pragma comment(lib, "minhook/minhook.lib")

using namespace SDK;

namespace Hooks
{
	bool bIsReady = false;
	bool bHasSpawned = false;
	bool bIsInGame = false;
	bool bHasInitedTheBeacon = false;

	LPVOID(*ProcessEvent)(void*, void*, void*);
	LPVOID ProcessEventHook(UObject* pObject, UFunction* pFunction, LPVOID pParams)
	{
		if (pFunction->GetName().find("BP_PlayButton") != std::string::npos)
		{
			Globals::PC->SwitchLevel(TEXT("Athena_Terrain"));
			bIsReady = true;
		}

		if (pFunction->GetName().find("ReceiveTick") != std::string::npos && pObject == Globals::PC && NetHooks::BeaconHost != NULL)
		{
			if (NetHooks::BeaconHost->IsBeaconValid())
			{
				if (NetHooks::BeaconHost->GetNetDriver())
				{
					if (NetHooks::BeaconHost->GetNetDriver()->ClientConnections.Num() != 0)
					{
						auto DeltaSeconds = ((AActor_ReceiveTick_Params*)pParams)->DeltaSeconds;
						NetHooks::NetReplicator->Tick(DeltaSeconds);
					}
				}
			}
		}

		if (pFunction->GetName().find("Tick") != std::string::npos)
		{
			if (GetAsyncKeyState(VK_F1) & 0x1)
			{
				if (!bHasInitedTheBeacon) {
					Replicator::InitOffsets();
					Beacon::InitOffsets();

					NetHooks::Init();
					bHasInitedTheBeacon = true;
				}
			}

			if (GetAsyncKeyState(VK_F2) & 0x1 && Globals::PC)
			{
				if (Globals::PC->Pawn)
				{
					auto Location = Globals::PC->Pawn->K2_GetActorLocation();
					auto NewFortPickup = reinterpret_cast<AFortPickup*>(Util::SpawnActor(AFortPickup::StaticClass(), Location, FRotator()));

					NewFortPickup->PrimaryPickupItemEntry.Count = 1;
					NewFortPickup->PrimaryPickupItemEntry.ItemDefinition = UObject::FindObject<UFortWeaponItemDefinition>("WID_Assault_AutoHigh_Athena_SR_Ore_T03.WID_Assault_AutoHigh_Athena_SR_Ore_T03");
					NewFortPickup->OnRep_PrimaryPickupItemEntry();

					NewFortPickup->TossPickup(Location, nullptr, 1, true);

					NetHooks::NetReplicator->Replicate(NewFortPickup); //Replicates the pickup
				}
			}
		}

		if (pFunction->GetName().find("ReadyToStartMatch") != std::string::npos && bIsReady)
		{
			Globals::FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
			Globals::World = Globals::FortEngine->GameViewport->World;
			Globals::PC = reinterpret_cast<AFortPlayerController*>(Globals::FortEngine->GameInstance->LocalPlayers[0]->PlayerController);

			if (!bHasSpawned) {
				Globals::Pawn = reinterpret_cast<PLAYER_CLASS*>(Util::SpawnActor(PLAYER_CLASS::StaticClass(), FVector(0, 0, 0), FRotator()));

				auto PlayerState = reinterpret_cast<PLAYER_STATE_CLASS*>(Globals::PC->PlayerState);
				PlayerState->CharacterParts[0] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Head1.F_Med_Head1");
				PlayerState->CharacterParts[1] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Soldier_01.F_Med_Soldier_01");
				PlayerState->OnRep_CharacterParts();

				Globals::PC->Possess(Globals::Pawn);

				bIsReady = false;
				bIsInGame = true;
				bHasSpawned = true;

				Globals::PC->ServerReadyToStartMatch();
				static_cast<AGameMode*>(Globals::World->AuthorityGameMode)->StartMatch();
			}
		}

		if (pFunction->GetName().find("LoadingScreenDropped") != std::string::npos)
		{
		}

		if (pFunction->GetName().find("ServerShortTimeout") != std::string::npos) {
			return NULL;
		}

		return ProcessEvent(pObject, pFunction, pParams);
	}

	static void Init()
	{
		auto FEVFT = *reinterpret_cast<void***>(Globals::FortEngine);
		auto PEAddr = FEVFT[64];

		MH_CreateHook(reinterpret_cast<LPVOID>(PEAddr), ProcessEventHook, reinterpret_cast<LPVOID*>(&ProcessEvent));
		MH_EnableHook(reinterpret_cast<LPVOID>(PEAddr));
	}
}