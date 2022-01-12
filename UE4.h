#pragma once

#include "Struct.h"
#include "Enums.h"

inline UObject* (*GetFirstPlayerController)(UObject* World);
inline UObject* (*SpawnActorLong)(UObject* World, UObject* Class, FVector* Position, FRotator* Rotation, const FActorSpawnParameters& SpawnParameters);
void* (*ProcessEvent)(void*, void*, void*);

static UObject* GetWorld()
{
	static auto FortEngine = UObject::FindObject("FortEngine_");
	static auto GameViewportOffset = UObject::FindOffset("ObjectProperty Engine.Engine.GameViewport");
	static auto WorldOffset = UObject::FindOffset("ObjectProperty Engine.GameViewportClient.World");

	UObject* GameViewport = *reinterpret_cast<UObject**>(__int64(FortEngine) + __int64(GameViewportOffset));
	UObject** World = reinterpret_cast<UObject**>(__int64(GameViewport) + __int64(WorldOffset));

	return *World;
}

static UObject* SpawnActor(UObject* Class, FVector Location, FRotator Rotation)
{
	auto SpawnParms = FActorSpawnParameters();
	return SpawnActorLong(GetWorld(), Class, &Location, &Rotation, SpawnParms);
}