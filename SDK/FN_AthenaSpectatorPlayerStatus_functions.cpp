// Fortnite (5.21) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------------

// Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.OnFollowedPlayerChanged
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AFortPlayerControllerSpectating* SpectatorController            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// class AFortPlayerState*        NewFollowedPlayer              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorPlayerStatus_C::OnFollowedPlayerChanged(class AFortPlayerControllerSpectating* SpectatorController, class AFortPlayerState* NewFollowedPlayer)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.OnFollowedPlayerChanged");

	UAthenaSpectatorPlayerStatus_C_OnFollowedPlayerChanged_Params params;
	params.SpectatorController = SpectatorController;
	params.NewFollowedPlayer = NewFollowedPlayer;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UAthenaSpectatorPlayerStatus_C::Construct()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.Construct");

	UAthenaSpectatorPlayerStatus_C_Construct_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.ExecuteUbergraph_AthenaSpectatorPlayerStatus
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorPlayerStatus_C::ExecuteUbergraph_AthenaSpectatorPlayerStatus(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.ExecuteUbergraph_AthenaSpectatorPlayerStatus");

	UAthenaSpectatorPlayerStatus_C_ExecuteUbergraph_AthenaSpectatorPlayerStatus_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
