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
	APlayerPawn_Athena_C* PlayerPawn;
	AFortPlayerController* PC;

	TArray<APlayerPawn_Athena_C*> ClientPawns;

	struct AFortAsQuickBars
	{
	public:
		unsigned char                                      UnknownData00[0x1A88];
		class SDK::AFortQuickBars* QuickBars;
	};

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
	UChannel* (*CreateChannel)(UNetConnection*, int, bool, int32_t);
	TSharedRef<void*>& (*FindOrCreateReplicator)(UActorChannel*, TWeakObjectPtr2<UObject>&);
	void(*StartReplicating)(void*, UActorChannel*);

	bool (*ReplicateActorG)(UActorChannel*);

	bool Replicate(AActor* Actor, UNetConnection* Connection)
	{
		auto Channel = (UActorChannel*)CreateChannel(Connection, EChannelType::CHTYPE_Actor, 1, -1); // https://github.com/EpicGames/UnrealEngine/blob/ea87f4fb26ff8b9d8cd49b3a930f10585a6a7230/Engine/Source/Runtime/Engine/Private/DemoNetDriver.cpp#L1071
		if (Channel) SetChannelActor(Channel, Actor); // https://github.com/EpicGames/UnrealEngine/blob/ea87f4fb26ff8b9d8cd49b3a930f10585a6a7230/Engine/Source/Runtime/Engine/Private/DemoNetDriver.cpp#L1071
		return ReplicateActorG(Channel); // https://github.com/EpicGames/UnrealEngine/blob/ea87f4fb26ff8b9d8cd49b3a930f10585a6a7230/Engine/Source/Runtime/Engine/Private/DemoNetDriver.cpp#L1081
	}

	bool Replicate(AActor* Actor) // Replicate to all Clients
	{
		bool ret = false;
		UNetConnection* Connection = nullptr;
		for (int i = 0; i < BeaconHost->NetDriver->ClientConnections.Num(); i++)
		{
			ret = Replicate(Actor, BeaconHost->NetDriver->ClientConnections[i]);
		}
		return ret;
	}

	static FVector GetPlayerStateLocation()
	{
		auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());
		TArray<AActor*> OutActors;
		GPS->STATIC_GetAllActorsOfClass(World, APlayerStart::StaticClass(), &OutActors);
		auto ActorsNum = OutActors.Num();
		auto ActorToUseNum = rand() % ActorsNum;
		auto ActorToUse = OutActors[ActorToUseNum];
		return ActorToUse->K2_GetActorLocation();
	}

	static void ReplicateAllActors(UNetConnection* Connection)
	{
		auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());
		TArray<AActor*> OutActors;
		GPS->STATIC_GetAllActorsOfClass(World, AActor::StaticClass(), &OutActors);

		for (int i = 0; i < OutActors.Num(); i++)
		{
			auto Actor = OutActors[i];

			if (Actor->bReplicates && Actor->NetDormancy != ENetDormancy::DORM_Initial && !Actor->bNetStartup) {
				Replicate(Actor);
			}
		}
	}

	void __fastcall AOnlineBeaconHost_NotifyControlMessageHook(AOnlineBeaconHost* BeaconHost, UNetConnection* NetConnection, uint8_t a3, void* a4)
	{
		if (std::to_string(a3) == "4") {
			NetConnection->CurrentNetSpeed = 30000;
			return;
		}

		if (std::to_string(a3) == "15") {
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
	APlayerController* SpawnPlayActorHook(UWorld* a1, UNetConnection* Connection, ENetRole a3, FURL a4, void* a5, FString& Src, uint8_t a7)
	{
		std::cout << "Spawning Player For: " << reinterpret_cast<FString*>(a5)->ToString() << std::endl;

		auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(SpawnActor(APlayerPawn_Athena_C::StaticClass(), GetPlayerStateLocation(), FRotator()));
		Pawn->Role = ENetRole::ROLE_SimulatedProxy;
		Pawn->RemoteRole = ENetRole::ROLE_AutonomousProxy;

		auto PlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(SpawnPlayActor(World, Connection, ENetRole::ROLE_AutonomousProxy, a4, a5, Src, a7));



	}

	void* (*ProcessEvent)(UObject*, UFunction*, void*);
	void* ProcessEventHook(UObject* pObject, UFunction* pFunction, void* pParams)
	{
		if (pFunction->GetName().find("ReadyToStartMatch") != std::string::npos)
		{
			//printf("Called ReadyToStartMatch!\n");
		}

		if (pFunction->GetName().find("BP_PlayButton") != std::string::npos)
		{
			auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
			World = FortEngine->GameViewport->World;
			FortEngine->GameInstance->LocalPlayers[0]->PlayerController->SwitchLevel(L"Athena_Terrain");
			bIsReady = true;
		}

		if (pFunction->GetName().find("Tick") != std::string::npos)
		{
			if (pObject == World->AuthorityGameMode && BeaconHost) {
				BeaconHost->NetDriver->ReplicationFrame++;
			}

			if (GetAsyncKeyState(VK_F1) & 0x01)
			{
				auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
				PC = reinterpret_cast<AFortPlayerController*>(FortEngine->GameInstance->LocalPlayers[0]->PlayerController);
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
				PlayerPawn = reinterpret_cast<APlayerPawn_Athena_C*>(GPS->STATIC_FinishSpawningActor(SpawningActor, SpawnTransform));
				//Pawn->bCanBeDamaged = false;

				auto FortPlayerStateZone = reinterpret_cast<AFortPlayerStateZone*>(PC->PlayerState);

				PC->Possess(PlayerPawn);

				auto AsFortQuickbars = reinterpret_cast<AFortAsQuickBars*>(PC);
				auto NewQuickBar = reinterpret_cast<AFortQuickBars*>(SpawnActor(AFortQuickBars::StaticClass(), FVector(0, 0, 3234), FRotator()));
				NewQuickBar->SetOwner(PC);
				AsFortQuickbars->QuickBars = NewQuickBar;
				PC->OnRep_QuickBar();
				AsFortQuickbars->QuickBars->ServerActivateSlotInternal(EFortQuickBars::Primary, 0, 0, true);

				PlayerPawn->EquipWeaponDefinition(UObject::FindObject<UFortWeaponItemDefinition>("WID_Assault_AutoHigh_Athena_SR_Ore_T03.WID_Assault_AutoHigh_Athena_SR_Ore_T03"), FGuid());

				FortPlayerStateZone->CharacterParts[0] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Head1.F_Med_Head1");
				FortPlayerStateZone->CharacterParts[1] = UObject::FindObject<UCustomCharacterPart>("CustomCharacterPart F_Med_Soldier_01.F_Med_Soldier_01");
				FortPlayerStateZone->OnRep_CharacterParts();

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
				ReplicateActorG = decltype(ReplicateActorG)(BaseAddr + 0x19A60D0);

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

			if (GetAsyncKeyState(VK_F4) & 0x1)
			{
				auto FortEngine = UObject::FindObject<UFortEngine>("FortEngine_");
				auto PC = reinterpret_cast<AFortPlayerControllerAthena*>(FortEngine->GameInstance->LocalPlayers[0]->PlayerController);
				PC->ServerReadyToStartMatch();

				for (int i = 0; i < BeaconHost->NetDriver->ClientConnections.Num(); i++)
				{
					reinterpret_cast<AFortPlayerControllerAthena*>(BeaconHost->NetDriver->ClientConnections[i]->PlayerController)->ServerReadyToStartMatch();
				}

				static_cast<AGameMode*>(World->AuthorityGameMode)->StartPlay();
				static_cast<AGameMode*>(World->AuthorityGameMode)->StartMatch();

				auto AthenaGameState = static_cast<AFortGameStateAthena*>(World->GameState);
				AthenaGameState->GameplayState = EFortGameplayState::NormalGameplay;
				AthenaGameState->OnRep_GameplayState();
				AthenaGameState->GamePhase = EAthenaGamePhase::Warmup;
				AthenaGameState->OnRep_GamePhase(EAthenaGamePhase::None);

				//Replicate(World->AuthorityGameMode);
				Replicate(World->GameState);
			}

			if (GetAsyncKeyState(VK_F5) & 0x1)
			{
				Replicate(PlayerPawn);
			}

			if (GetAsyncKeyState(VK_F6) & 0x1)
			{
				auto NewFortPickup = reinterpret_cast<AFortPickup*>(SpawnActor(AFortPickup::StaticClass(), FVector(0, 0, 0), FRotator()));
				Replicate(NewFortPickup); //Replicates the pickup

				NewFortPickup->PrimaryPickupItemEntry.Count = 1;
				NewFortPickup->PrimaryPickupItemEntry.ItemDefinition = UObject::FindObject<UFortWeaponItemDefinition>("WID_Assault_AutoHigh_Athena_SR_Ore_T03.WID_Assault_AutoHigh_Athena_SR_Ore_T03");
				NewFortPickup->OnRep_PrimaryPickupItemEntry();

				NewFortPickup->TossPickup(FVector(0, 0, 0), PlayerPawn, 1, true);

				Replicate(NewFortPickup);
			}
		}

		if (pObject->Class->GetName().find("FortPlayerController") != std::string::npos && pObject != PC && pFunction->GetName().find("Tick") == std::string::npos && pFunction->GetName().find("ClientRestart") == std::string::npos) {
			std::cout << "Object: " << pObject->GetFullName() << std::endl;
			std::cout << "Function: " << pFunction->GetFullName() << std::endl;
		}

		if (pFunction->GetName().find("ServerShortTimeout") != std::string::npos) {
			return NULL;
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
