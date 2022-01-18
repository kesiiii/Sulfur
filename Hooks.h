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
	AOnlineBeaconHost* BeaconHost;

	enum EBeaconState
	{
		AllowRequests,
		DenyRequests
	};

	enum EChannelType
	{
		CHTYPE_None = 0,
		CHTYPE_Control = 1,
		CHTYPE_Actor = 2,
		CHTYPE_File = 3,
		CHTYPE_Voice = 4,
		CHTYPE_MAX = 8
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

	bool(*InitHost)(AOnlineBeaconHost*);
	void(*UWorld_NotifyControlMessage)(UWorld* World, UNetConnection* NetConnection, uint8_t a3, void* a4);
	__int64(*WelcomePlayer)(UWorld* This, UNetConnection* NetConnection);
	APlayerController* (*SpawnPlayActor)(UWorld* a1, UPlayer* a2, ENetRole a3, FURL a4, void* a5, FString& Src, uint8_t a7);
	__int64(*SetChannelActor)(UActorChannel*, AActor*);
	UActorChannel* (*CreateChannel)(UNetConnection*, int, bool, int32_t);
	TSharedRef<void*>& (*FindOrCreateReplicator)(UActorChannel*, TWeakObjectPtr2<UObject>&);
	void(*StartReplicating)(void*, UActorChannel*);

	static void ReplicateActor(UNetConnection* NetConnection, AActor* Actor)
	{
		auto NewActorChannel = CreateChannel(NetConnection, EChannelType::CHTYPE_Actor, true, 1);
		std::cout << "NewActorChannel: " << NewActorChannel->GetFullName() << std::endl;
		SetChannelActor(NewActorChannel, Actor);

		TWeakObjectPtr2<UObject> WeakObj(Actor);

		auto Replicator = &FindOrCreateReplicator(NewActorChannel, WeakObj);
		StartReplicating(Replicator, NewActorChannel);

		std::cout << "AllOpenChannels: " << NetConnection->OpenChannels.Num() << std::endl;
	}

	static int32_t ServerReplicateActors(float DeltaSeconds)
	{
		auto This = BeaconHost->NetDriver;

		if (This->ClientConnections.Num() == 0)
			return 0;

		if (This->World == NULL)
			return 0;

		This->ReplicationFrame++;

		auto NumClientsToTick = This->ClientConnections.Num();

		AWorldSettings* WorldSettings = This->World->PersistentLevel->WorldSettings;

		for (int i = 0; i < This->ClientConnections.Num(); i++)
		{
			UNetConnection* Connection = This->ClientConnections[i];

			if (Connection == NULL)
				continue;

			
		}
	}

	void __fastcall AOnlineBeaconHost_NotifyControlMessageHook(AOnlineBeaconHost* BeaconHost, UNetConnection* NetConnection, uint8_t a3, void* a4)
	{
		if (std::to_string(a3) == "4") {
			NetConnection->CurrentNetSpeed = 30000;
			return;
		}

		printf("LogUGS: AOnlineBeaconHost::NotifyControlMessage Called! (%s)\n", std::to_string(a3).c_str());
		printf("LogUGS: Channel count (%s)\n", std::to_string(NetConnection->OpenChannels.Num()).c_str());
		return UWorld_NotifyControlMessage(World, NetConnection, a3, a4);
	}

	__int64 __fastcall WelcomePlayerHook(UWorld* world, UNetConnection* NetConnection)
	{
		printf("LogUGS: Welcoming Player!\n");
		return WelcomePlayer(World, NetConnection);
	}

	// https://github.com/EpicGames/UnrealEngine/blob/4.19/Engine/Source/Runtime/Engine/Private/LevelActor.cpp#L705
	APlayerController* SpawnPlayActorHook(UWorld* a1, UNetConnection* a2, ENetRole a3, FURL a4, void* a5, FString& Src, uint8_t a7)
	{
		printf("LogUGS: SpawnPlayActor Called!\n");

		auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());

		TArray<AActor*> OutActors;
		GPS->STATIC_GetAllActorsOfClass(World, APlayerStart::StaticClass(), &OutActors);
		auto ActorsNum = OutActors.Num();
		auto ActorToUseNum = rand() % ActorsNum;
		auto ActorToUse = OutActors[ActorToUseNum];

		auto NewPlayerPawn = reinterpret_cast<APlayerPawn_Athena_C*>(SpawnActor(APlayerPawn_Athena_C::StaticClass(), ActorToUse->K2_GetActorLocation(), FRotator()));

		ReplicateActor(a2, World->AuthorityGameMode);
		ReplicateActor(a2, World->GameState);
		ReplicateActor(a2, NewPlayerPawn);

		auto NewPlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(SpawnPlayActor(World, a2, a3, a4, a5, Src, a7));
		NewPlayerController->Player = a2;
		NewPlayerController->Player->PlayerController = NewPlayerController;
		NewPlayerController->Possess(NewPlayerPawn);
		NewPlayerPawn->PawnUniqueID = (int)a5;
		NewPlayerPawn->OnRep_PawnUniqueID();
		/*NewPlayerPawn->PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(SpawnActor(AFortPlayerStateAthena::StaticClass(), FVector(0, 0, 10432), FRotator()));
		NewPlayerPawn->OnRep_PlayerState();*/
		NewPlayerPawn->PlayerState = NewPlayerController->PlayerState;

		ReplicateActor(a2, NewPlayerController->PlayerState);
		ReplicateActor(a2, NewPlayerPawn->PlayerState);

		NewPlayerPawn->OnRep_PlayerState();

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

		NewAthenaPlayerState->CharacterParts[0] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Head1.F_Med_Head1");
		NewAthenaPlayerState->CharacterParts[1] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Soldier_01.F_Med_Soldier_01");
		NewAthenaPlayerState->OnRep_CharacterParts();

		ReplicateActor(a2, NewAthenaPlayerState);

		auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
		auto PC = FortEngine->GameInstance->LocalPlayers[0]->PlayerController;
		NewPlayerController->ServerReadyToStartMatch();

		// AFortGameModeAthena->AlivePlayers == TArray of PlayerControllers that are alive / not replicated yet!
		
		std::cout << "OpenChannels: " << a2->OpenChannels.Num() << std::endl;

		return NewPlayerController;
	}

	void* (*ProcessEvent)(UObject*, UFunction*, void*);
	void* ProcessEventHook(UObject* pObject, UFunction* pFunction, void* pParams)
	{
		if (pFunction->GetName().find("BP_PlayButton") != std::string::npos)
		{
			auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
			World = FortEngine->GameViewport->World;
			FortEngine->GameInstance->LocalPlayers[0]->PlayerController->SwitchLevel(L"Athena_Terrain?Game=Athena");
			bIsReady = true;
		}

		if (pFunction->GetName().find("Tick") != std::string::npos)
		{
			if (pObject == World->AuthorityGameMode && BeaconHost) {
				//std::cout << "OtherReplicationFrame: " << BeaconHost->NetDriver->ReplicationFrame << std::endl;
				//ReplicationFrame++;
				BeaconHost->NetDriver->ReplicationFrame++;
				//std::cout << "ReplicationFrame: " << ReplicationFrame << std::endl;
				//std::cout << "OtherReplicationFrame: " << BeaconHost->NetDriver->ReplicationFrame << std::endl;
			}

			if (GetAsyncKeyState(VK_F1) & 0x01)
			{
				auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
				auto PC = reinterpret_cast<AFortPlayerControllerAthena*>(FortEngine->GameInstance->LocalPlayers[0]->PlayerController);
				auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());
				auto FortCheatManager = reinterpret_cast<UFortCheatManager*>(PC->CheatManager);

				PC->CheatManager->DestroyAll(AFortHLODSMActor::StaticClass());

				auto FortHero = UObject::FindObject<UFortHero>("FortHero Transient.FortHero_");

				TArray<AActor*> OutActors;
				GPS->STATIC_GetAllActorsOfClass(FortEngine->GameViewport->World, APlayerStart::StaticClass(), &OutActors);
				auto ActorsNum = OutActors.Num();
				auto ActorToUseNum = rand() % ActorsNum;
				auto ActorToUse = OutActors[ActorToUseNum];

				auto SpawnTransform = FTransform();
				SpawnTransform.Scale3D = FVector(1, 1, 1);
				SpawnTransform.Rotation = FQuat();
				SpawnTransform.Translation = ActorToUse->K2_GetActorLocation();

				auto NewConsole = GPS->STATIC_SpawnObject(UFortConsole::StaticClass(), FortEngine->GameViewport);
				FortEngine->GameViewport->ViewportConsole = static_cast<UFortConsole*>(NewConsole);

				auto SpawningActor = GPS->STATIC_BeginSpawningActorFromClass(FortEngine->GameViewport->World, APlayerPawn_Athena_C::StaticClass(), SpawnTransform, false, nullptr);
				auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(GPS->STATIC_FinishSpawningActor(SpawningActor, SpawnTransform));
				Pawn->bCanBeDamaged = false;

				auto AthenaPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PC->PlayerState);

				PC->Possess(Pawn);

				AthenaPlayerState->CharacterParts[0] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Head1.F_Med_Head1");
				AthenaPlayerState->CharacterParts[1] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Soldier_01.F_Med_Soldier_01");
				AthenaPlayerState->OnRep_CharacterParts();

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

				InitHost = decltype(InitHost)(BaseAddr + 0x27B4820);
				UWorld_NotifyControlMessage = decltype(UWorld_NotifyControlMessage)(BaseAddr + 0x1DA15C0);
				WelcomePlayer = decltype(WelcomePlayer)(BaseAddr + 0x1DACC50);
				SetChannelActor = decltype(SetChannelActor)(BaseAddr + 0x19AA960);
				CreateChannel = decltype(CreateChannel)(BaseAddr + 0x1B0C510);
				FindOrCreateReplicator = decltype(FindOrCreateReplicator)(BaseAddr + 0x19943D0);
				StartReplicating = decltype(StartReplicating)(BaseAddr + 0x19ACA70);

				auto AOnlineBeaconHost_NotifyControlMessageAddr = BaseAddr + 0x27B7620;
				auto WelcomePlayerAddr = BaseAddr + 0x1DACC50;
				auto SpawnPlayActorAddr = BaseAddr + 0x1A9E7B0;

				SpawnPlayActor = decltype(SpawnPlayActor)(SpawnPlayActorAddr);

				MH_CreateHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr), AOnlineBeaconHost_NotifyControlMessageHook, nullptr);
				MH_EnableHook((void*)(AOnlineBeaconHost_NotifyControlMessageAddr));
				MH_CreateHook((void*)(WelcomePlayerAddr), WelcomePlayerHook, (void**)(&WelcomePlayer));
				MH_EnableHook((void*)(WelcomePlayerAddr));
				MH_CreateHook((void*)(SpawnPlayActorAddr), SpawnPlayActorHook, (void**)(&SpawnPlayActor));
				MH_EnableHook((void*)(SpawnPlayActorAddr));

				auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
				World = FortEngine->GameViewport->World;
				auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());

				auto SpawnTransform = FTransform();
				SpawnTransform.Scale3D = FVector(1, 1, 1);
				SpawnTransform.Rotation = FQuat();
				SpawnTransform.Translation = FVector(0, 0, 5000);

				auto SpawningActor = GPS->STATIC_BeginSpawningActorFromClass(FortEngine->GameViewport->World, AOnlineBeaconHost::StaticClass(), SpawnTransform, false, nullptr);
				BeaconHost = reinterpret_cast<AOnlineBeaconHost*>(GPS->STATIC_FinishSpawningActor(SpawningActor, SpawnTransform));

				std::cout << "BeaconHost: " << BeaconHost->GetFullName() << std::endl;

				BeaconHost->ListenPort = 7777;
				auto result = InitHost(BeaconHost);
				std::cout << "InitHost Result: " << result << std::endl;

				//auto ReplicationFrame = reinterpret_cast<uint32_t*>((uintptr_t)(BeaconHost->NetDriver) + 202);
				//std::cout << "ReplicationFrame: " << ReplicationFrame << std::endl;
				std::cout << "OtherReplicationFrame: " << BeaconHost->NetDriver->ReplicationFrame << std::endl;
				//ReplicationFrame++;
				BeaconHost->NetDriver->ReplicationFrame++;
				//std::cout << "ReplicationFrame: " << ReplicationFrame << std::endl;
				std::cout << "OtherReplicationFrame: " << BeaconHost->NetDriver->ReplicationFrame << std::endl;

				BeaconHost->BeaconState = EBeaconState::AllowRequests;

				printf("LogUGS: Beacons Setup!\n");
			}

			if (GetAsyncKeyState(VK_F3) && 0x01)
			{
				auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
				auto PC = reinterpret_cast<AFortPlayerControllerAthena*>(FortEngine->GameInstance->LocalPlayers[0]->PlayerController);
				auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PC->PlayerState);
				PlayerState->TeamIndex = EFortTeam::HumanPvP_Team2;
				PlayerState->OnRep_PlayerTeam();
				PlayerState->OnRep_SquadId();
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