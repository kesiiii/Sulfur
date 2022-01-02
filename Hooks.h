#pragma once

#include "Struct.h"
#include "Enums.h"
#include "UE4.h"
#include "Globals.h"
#include "Functions.h"

namespace Hooks
{
	bool bIsReady = false;
	bool bIsInGame = false;
	bool bHasSpawned = false;

	void* ProcessEventDetour(UObject* pObject, UObject* pFunction, void* pParams)
	{
		if (pObject && pFunction) {
			if (pFunction->GetName().find("Tick") != std::string::npos && pObject == Globals::LocalPlayerController)
			{
				if (GetKeyState(VK_F5) & 0x1)
				{
					auto SpawnPos = FVector(0, 0, 15000);
					auto SpawnRot = FRotator();
					auto Beacon = static_cast<AOnlineBeaconHost*>(SpawnActor(GetWorld(), UObject::FindObject("Class OnlineSubsystemUtils.OnlineBeaconHost"), &SpawnPos, &SpawnRot, FActorSpawnParameters()));
					Beacon->ListenPort = 7777;
					std::cout << "BeaconRes: " << Beacons::InitHost(Beacon) << std::endl;
					Beacon->BeaconState = EBeaconState::AllowRequests;
				}
			}

			if (pFunction->GetName().find("PlayButton") != std::string::npos)
			{
				printf("pressed play!\n");
				Funcs::SwitchLevel(Globals::LocalPlayerController, L"Athena_Terrain?Game=Athena");
				bIsReady = true;
			}

			if (pFunction->GetName().find("ReadyToStartMatch") != std::string::npos && bIsReady)
			{
				if (!bHasSpawned) {
					Globals::LocalPlayerController = GetFirstPlayerController(GetWorld());
					Globals::GameState = UObject::FindObject("Athena_GameState_C Athena_Terrain.Athena_Terrain.PersistentLevel.Athena_GameState_C");
					Globals::GameMode = UObject::FindObject("Athena_GameMode_C Athena_Terrain.Athena_Terrain.PersistentLevel.Athena_GameMode_C");

					std::cout << "Controller: " << Globals::LocalPlayerController->GetFullName() << std::endl;
					std::cout << "GameMode: " << Globals::GameMode->GetFullName() << std::endl;
					std::cout << "GameState: " << Globals::GameState->GetFullName() << std::endl;

					auto SpawnPos = FVector(0, 0, 5000);
					auto SpawnRot = FRotator();
					Globals::LocalPawn = SpawnActor(GetWorld(), UObject::FindObject("BlueprintGeneratedClass PlayerPawn_Athena.PlayerPawn_Athena_C"), &SpawnPos, &SpawnRot, FActorSpawnParameters());

					std::cout << "Pawn: " << Globals::LocalPawn->GetFullName() << std::endl;

					Funcs::Possess(Globals::LocalPlayerController, Globals::LocalPawn);

					std::cout << "Possessed!\n";

					auto PlayerStateOffset = UObject::FindOffset("ObjectProperty Engine.Controller.PlayerState");
					Globals::LocalPlayerState = *reinterpret_cast<UObject**>(reinterpret_cast<uintptr_t>(Globals::LocalPlayerController) + __int64(PlayerStateOffset));

					std::cout << "PlayerState: " << Globals::LocalPlayerState->GetFullName() << std::endl;

					auto HeadPart = UObject::FindObject("CustomCharacterPart F_Med_Head1.F_Med_Head1");
					auto BodyPart = UObject::FindObject("CustomCharacterPart F_Med_Soldier_01.F_Med_Soldier_01");
					Funcs::ServerChoosePart(Globals::LocalPawn, EFortCustomPartType::Head, HeadPart);
					Funcs::ServerChoosePart(Globals::LocalPawn, EFortCustomPartType::Body, BodyPart);
					Funcs::OnRep_CharacterParts(Globals::LocalPlayerState);

					auto GamePhaseOffset = UObject::FindOffset("EnumProperty FortniteGame.FortGameStateAthena.GamePhase");
					EAthenaGamePhase* CurrentGamePhase = reinterpret_cast<EAthenaGamePhase*>(__int64(Globals::GameState) + __int64(GamePhaseOffset));
					*CurrentGamePhase = EAthenaGamePhase::Aircraft;
					Funcs::OnRep_GamePhase(Globals::GameState, EAthenaGamePhase::None);

					Funcs::ServerReadyToStartMatch(Globals::LocalPlayerController);

					bIsInGame = true;
					bIsReady = false;
					bHasSpawned = true;
				}
			}
		}

		return ProcessEvent(pObject, pFunction, pParams);
	}

	static void Init()
	{
		auto FortEngine = UObject::FindObject("FortEngine_");
		auto VFT = *reinterpret_cast<void***>(FortEngine);
		auto PEAddr = VFT[0x40];
		ProcessEvent = decltype(ProcessEvent)(PEAddr);

		MH_Initialize();

		MH_CreateHook((void*)PEAddr, ProcessEventDetour, (void**)(&ProcessEvent));
		MH_EnableHook((void*)PEAddr);
	}
}