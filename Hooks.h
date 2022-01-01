#pragma once

#include "Struct.h"
#include "Enums.h"
#include "UE4.h"
#include "minhook/MinHook.h"
#include "Globals.h"
#include "Functions.h"

#pragma comment(lib, "minhook/MinHook.lib")

namespace Hooks
{
	bool bIsReady = false;
	bool bIsInGame = false;
	bool bHasSpawned = false;

	void* ProcessEventDetour(UObject* pObject, UObject* pFunction, void* pParams)
	{
		if (pObject && pFunction) {
			if (pFunction->GetName().find("PlayButton") != std::string::npos)
			{
				printf("pressed play!\n");
				Funcs::SwitchLevel(Globals::LocalPlayerController, L"Athena_Terrain");
				bIsReady = true;
			}

			if (pFunction->GetName().find("ReadyToStartMatch") != std::string::npos && bIsReady)
			{
				if (!bHasSpawned) {
					Globals::LocalPlayerController = GetFirstPlayerController(GetWorld());
					Globals::GameState = UObject::FindObject("Athena_GameState_C Athena_Terrain.Athena_Terrain.PersistentLevel.Athena_GameState_C");
					Globals::GameMode = UObject::FindObject("Athena_GameMode_C Athena_Terrain.Athena_Terrain.PersistentLevel.Athena_GameMode_C");

					auto SpawnPos = FVector(0, 0, 5000);
					auto SpawnRot = FRotator();
					auto SpawnParms = FActorSpawnParameters();
					Globals::LocalPawn = SpawnActor(GetWorld(), UObject::FindObject("BlueprintGeneratedClass PlayerPawn_Athena.PlayerPawn_Athena_C"), &SpawnPos, &SpawnRot, SpawnParms);

					Funcs::Possess(Globals::LocalPlayerController, Globals::LocalPawn);

					Globals::LocalPlayerState = *reinterpret_cast<UObject**>(reinterpret_cast<uintptr_t>(Globals::LocalPlayerController) + __int64(UObject::FindObject("ObjectProperty Engine.Controller.PlayerState")));

					auto HeadPart = UObject::FindObject("CustomCharacterPart F_Med_Head1.F_Med_Head1");
					auto BodyPart = UObject::FindObject("CustomCharacterPart F_Med_Soldier_01.F_Med_Soldier_01");
					Funcs::ServerChoosePart(Globals::LocalPawn, EFortCustomPartType::Head, HeadPart);
					Funcs::ServerChoosePart(Globals::LocalPawn, EFortCustomPartType::Body, BodyPart);
					Funcs::OnRep_CharacterParts(Globals::LocalPlayerState);

					Funcs::ServerReadyToStartMatch(Globals::LocalPlayerController);
					Funcs::StartMatch(Globals::GameMode);
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