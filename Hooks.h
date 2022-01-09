#pragma once

#include "minhook/MinHook.h"
#include "SDK.hpp"
#include <iostream>

using namespace SDK;

#pragma comment(lib, "minhook/minhook.lib")

namespace Hooks
{
	bool bIsReady = false;
	bool bIsInGame = false;
	bool bHasSpawned = false;

	UWorld* World;
	AFortTeamInfoAthena* PlayerTeam;

	enum EBeaconState
	{
		AllowRequests,
		DenyRequests
	};

	inline AActor* SpawnActor(UClass* ActorClass, FVector Location, FRotator Rotation)
	{
		FQuat Quat;
		FTransform Transform;
		Quat.W = 0;
		Quat.X = Rotation.Pitch;
		Quat.Y = Rotation.Roll;
		Quat.Z = Rotation.Yaw;

		Transform.Rotation = Quat;
		Transform.Scale3D = FVector{ 1,1,1 };
		Transform.Translation = Location;

		auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
		auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());
		auto Actor = GPS->STATIC_BeginSpawningActorFromClass(FortEngine->GameViewport->World, ActorClass, Transform, false, nullptr);
		GPS->STATIC_FinishSpawningActor(Actor, Transform);
		return Actor;
	}

	__int64(*PreLogin)(AGameModeBase* This, FString* a2, FString* a3, __int64 a4, FString* a5);
	void* (*PauseBeaconRequest)(AOnlineBeacon* Beacon, bool);
	bool(*InitHost)(AOnlineBeaconHost*);
	void(*UWorld_NotifyControlMessage)(UWorld* World, UNetConnection* NetConnection, uint8_t a3, void* a4);
	__int64(*WelcomePlayer)(UWorld* This, UNetConnection* NetConnection);
	APlayerController* (*SpawnPlayActor)(UWorld* a1, UPlayer* a2, ENetRole a3, FURL a4, void* a5, FString& Src, uint8_t a7);

	void __fastcall AOnlineBeaconHost_NotifyControlMessageHook(AOnlineBeaconHost* BeaconHost, UNetConnection* NetConnection, uint8_t a3, void* a4)
	{
		printf("LogUGS: AOnlineBeaconHost::NotifyControlMessage Called! (%s)\n", std::to_string(a3).c_str());
		printf("LogUGS: Channel count (%s)\n", std::to_string(NetConnection->OpenChannels.Num()).c_str());
		return UWorld_NotifyControlMessage(World, NetConnection, a3, a4);
	}

	__int64 __fastcall PreLoginHook(AGameModeBase* This, FString* a2, FString* a3, __int64 a4, FString* a5)
	{
		printf("Called PreLogin!\n");
		return PreLogin(This, a2, a3, a4, a5);
	}

	__int64 __fastcall WelcomePlayerHook(UWorld* world, UNetConnection* NetConnection)
	{
		printf("LogUGS: Welcoming Player!\n");
		return WelcomePlayer(World, NetConnection);
	}

	// https://github.com/EpicGames/UnrealEngine/blob/4.19/Engine/Source/Runtime/Engine/Private/LevelActor.cpp#L705
	APlayerController* SpawnPlayActorHook(UWorld* a1, UPlayer* a2, ENetRole a3, FURL a4, void* a5, FString& Src, uint8_t a7)
	{
		printf("LogUGS: SpawnPlayActor Called!\n");

		auto NewPlayerPawn = reinterpret_cast<APlayerPawn_Athena_C*>(SpawnActor(APlayerPawn_Athena_C::StaticClass(), FVector(0, 0, 1500), FRotator()));

		auto NewPlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(SpawnPlayActor(World, a2, a3, a4, a5, Src, a7));
		NewPlayerController->Player = a2;
		NewPlayerController->Player->PlayerController = NewPlayerController;
		NewPlayerController->Possess(NewPlayerPawn);
		NewPlayerPawn->PawnUniqueID = rand() % 1000;
		NewPlayerPawn->OnRep_PawnUniqueID();
		NewPlayerPawn->PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(SpawnActor(AFortPlayerStateAthena::StaticClass(), FVector(0, 0, 10432), FRotator()));
		NewPlayerPawn->OnRep_PlayerState();
		NewPlayerController->PlayerState = NewPlayerPawn->PlayerState;
		NewPlayerController->OnRep_PlayerState();

		NewPlayerPawn->SetMaxHealth(420);
		NewPlayerPawn->SetHealth(420);

		NewPlayerPawn->PlayerState->bIsABot = false;
		NewPlayerPawn->PlayerState->bIsSpectator = false;

		auto NewAthenaPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(NewPlayerController->PlayerState);
		NewAthenaPlayerState->bHasStartedPlaying = true;
		NewAthenaPlayerState->bHasFinishedLoading = true;
		NewAthenaPlayerState->OnRep_bHasStartedPlaying();

		NewPlayerController->ServerSetClientHasFinishedLoading(true);
		NewPlayerController->ServerLoadingScreenDropped();

		NewPlayerController->bHasInitiallySpawned = true;
		NewPlayerController->bAssignedStartSpawn = true;
		NewPlayerController->bReadyToStartMatch = true;
		NewPlayerController->bClientPawnIsLoaded = true;
		NewPlayerController->bHasClientFinishedLoading = true;
		NewPlayerController->bHasServerFinishedLoading = true;

		auto MyAthenaPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(UObject::FindObject<UFortEngine>("FortEngine_")->GameInstance->LocalPlayers[0]->PlayerController->PlayerState);

		NewAthenaPlayerState->MaxShield = 100;
		NewAthenaPlayerState->CurrentShield = 69;
		NewAthenaPlayerState->TeamIndex = EFortTeam::HumanPvP_Team1;
		NewAthenaPlayerState->SquadId = MyAthenaPlayerState->SquadId;
		NewAthenaPlayerState->OnRep_SquadId();
		NewAthenaPlayerState->OnRep_PlayerTeam();

		auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
		auto PC = FortEngine->GameInstance->LocalPlayers[0]->PlayerController;
		NewPlayerController->ServerReadyToStartMatch();

		// AFortGameModeAthena->AlivePlayers == TArray of PlayerControllers that are alive / not replicated yet!

		return NewPlayerController;
	}

	void* (*ProcessEvent)(UObject*, UFunction*, void*);
	void* ProcessEventHook(UObject* pObject, UFunction* pFunction, void* pParams)
	{
		if (pFunction->GetName().find("BP_PlayButton") != std::string::npos)
		{
			auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
			World = FortEngine->GameViewport->World;
			FortEngine->GameInstance->LocalPlayers[0]->PlayerController->SwitchLevel(L"DS_BuilderGridPlane?Game=Athena");
			bIsReady = true;
		}

		if (pFunction->GetName().find("Tick") != std::string::npos)
		{
			if (GetAsyncKeyState(VK_F1) & 0x01)
			{
				auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
				World = FortEngine->GameViewport->World;
				auto PC = reinterpret_cast<AFortPlayerControllerAthena*>(FortEngine->GameInstance->LocalPlayers[0]->PlayerController);
				auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());
				auto FortCheatManager = reinterpret_cast<UFortCheatManager*>(PC->CheatManager);

				PC->CheatManager->DestroyAll(AFortHLODSMActor::StaticClass());

				auto FortHero = UObject::FindObject<UFortHero>("FortHero Transient.FortHero_");

				auto SpawnTransform = FTransform();
				SpawnTransform.Scale3D = FVector(1, 1, 1);
				SpawnTransform.Rotation = FQuat();
				SpawnTransform.Translation = FVector(0, 0, 1500);

				auto NewConsole = GPS->STATIC_SpawnObject(UFortConsole::StaticClass(), FortEngine->GameViewport);
				FortEngine->GameViewport->ViewportConsole = static_cast<UFortConsole*>(NewConsole);

				auto SpawningActor = GPS->STATIC_BeginSpawningActorFromClass(FortEngine->GameViewport->World, APlayerPawn_Athena_C::StaticClass(), SpawnTransform, false, nullptr);
				auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(GPS->STATIC_FinishSpawningActor(SpawningActor, SpawnTransform));
				Pawn->bCanBeDamaged = false;

				PC->Possess(Pawn);

				static_cast<AGameMode*>(FortEngine->GameViewport->World->AuthorityGameMode)->StartMatch();
				static_cast<AFortPlayerControllerAthena*>(PC)->ServerReadyToStartMatch();

				bIsInGame = true;
				bIsReady = false;
				bHasSpawned = true;
			}

			if (GetAsyncKeyState(VK_F2) & 0x01)
			{
				std::cout << "LogUGS: Init Beacons!\n";

				auto BaseAddr = (uintptr_t)(GetModuleHandle(NULL));

				InitHost = decltype(InitHost)(BaseAddr + 0x340670);
				PauseBeaconRequest = decltype(PauseBeaconRequest)(BaseAddr + 0xD6DFA0);
				UWorld_NotifyControlMessage = decltype(UWorld_NotifyControlMessage)(BaseAddr + 0x254BB00);
				WelcomePlayer = decltype(WelcomePlayer)(BaseAddr + 0x2557260);
				PreLogin = decltype(PreLogin)(BaseAddr + 0x217F4C0);

				auto AOnlineBeaconHost_NotifyControlMessageAddr = BaseAddr + 0x343AE0;
				auto WelcomePlayerAddr = BaseAddr + 0x2557260;
				auto SpawnPlayActorAddr = BaseAddr + 0x22372C0;
				auto PreLoginAddr = BaseAddr + 0x217F4C0;

				SpawnPlayActor = decltype(SpawnPlayActor)(SpawnPlayActorAddr);

				MH_CreateHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr), AOnlineBeaconHost_NotifyControlMessageHook, nullptr);
				MH_EnableHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr));
				MH_CreateHook((void*)(WelcomePlayerAddr), WelcomePlayerHook, (void**)(&WelcomePlayer));
				MH_EnableHook((void*)(WelcomePlayerAddr));
				MH_CreateHook((void*)(SpawnPlayActorAddr), SpawnPlayActorHook, (void**)(&SpawnPlayActor));
				MH_EnableHook((void*)(SpawnPlayActorAddr));
				MH_CreateHook((void*)(PreLoginAddr), PreLoginHook, (void**)(&PreLogin));
				MH_EnableHook((void*)(PreLoginAddr));

				auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
				World = FortEngine->GameViewport->World;
				auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());

				auto SpawnTransform = FTransform();
				SpawnTransform.Scale3D = FVector(1, 1, 1);
				SpawnTransform.Rotation = FQuat();
				SpawnTransform.Translation = FVector(0, 0, 5000);

				auto SpawningActor = GPS->STATIC_BeginSpawningActorFromClass(FortEngine->GameViewport->World, AOnlineBeaconHost::StaticClass(), SpawnTransform, false, nullptr);
				auto BeaconHost = reinterpret_cast<AOnlineBeaconHost*>(GPS->STATIC_FinishSpawningActor(SpawningActor, SpawnTransform));

				std::cout << "BeaconHost: " << BeaconHost->GetFullName() << std::endl;

				BeaconHost->ListenPort = 7777;
				auto result = InitHost(BeaconHost);
				PauseBeaconRequest(BeaconHost, false);

				std::cout << "RepFrame: " << std::to_string(BeaconHost->NetDriver->RepFrame) << std::endl;
				BeaconHost->NetDriver->RepFrame++;
				std::cout << "RepFrame: " << std::to_string(BeaconHost->NetDriver->RepFrame) << std::endl;

				std::cout << "InitHost Result: " << result << std::endl;

				//BeaconHost->BeaconState = EBeaconState::AllowRequests;

				printf("LogUGS: Beacons Setup!\n");
			}

			if (GetAsyncKeyState(VK_F3) && 0x01)
			{
			}
		}

		return ProcessEvent(pObject, pFunction, pParams);
	}

	static void Init()
	{
		MH_Initialize();

		auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
		auto FEVFT = *reinterpret_cast<void***>(FortEngine);
		auto PEAddr = FEVFT[64];

		MH_CreateHook((void*)PEAddr, ProcessEventHook, (void**)(&ProcessEvent));
		MH_EnableHook((void*)PEAddr);
	}
}