#pragma once

#include "Enums.h"
#include "UE4.h"
#include "Struct.h"
#include "Globals.h"

namespace Funcs
{
	static void SwitchLevel(UObject* Controller, FString URL)
	{
		auto fn = UObject::FindObject("Function Engine.PlayerController.SwitchLevel");
		ProcessEvent(Controller, fn, &URL);
	}

	static void Possess(UObject* Controller, UObject* Pawn)
	{
		auto fn = UObject::FindObject("Function Engine.Controller.Possess");
		ProcessEvent(Controller, fn, &Pawn);
	}

	static void StartMatch(UObject* GameMode)
	{
		auto fn = UObject::FindObject("Function Engine.GameMode.StartMatch");
		ProcessEvent(GameMode, fn, nullptr);
	}

	static void ServerReadyToStartMatch(UObject* Controller)
	{
		auto fn = UObject::FindObject("Function FortniteGame.FortPlayerController.ServerReadyToStartMatch");
		ProcessEvent(Controller, fn, nullptr);
	}

	static void ServerChoosePart(UObject* Pawn, EFortCustomPartType PartType, UObject* Part)
	{
		struct
		{
			TEnumAsByte<EFortCustomPartType> Type;
			UObject* ChosenCharacterPart;
		}params;
		params.ChosenCharacterPart = Part;
		params.Type = PartType;

		auto fn = UObject::FindObject("Function FortniteGame.FortPlayerPawn.ServerChoosePart");

		ProcessEvent(Pawn, fn, &params);
	}

	static void OnRep_CharacterParts(UObject* PlayerState)
	{
		ProcessEvent(PlayerState, UObject::FindObject("Function FortniteGame.FortPlayerState.OnRep_CharacterParts"), nullptr);
	}

	static void OnRep_GamePhase(UObject* InGameState, EAthenaGamePhase OldGamePhase)
	{
		static UObject* OnRep_GamePhase = UObject::FindObject("Function /Script/FortniteGame.FortGameStateAthena.OnRep_GamePhase");

		ProcessEvent(InGameState, OnRep_GamePhase, &OldGamePhase);
	}
}