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

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.UpdateVisibility
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// TEnumAsByte<EAthenaSpectatorNameplateState> NameplateState                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorNameplate_C::UpdateVisibility(TEnumAsByte<EAthenaSpectatorNameplateState> NameplateState)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.UpdateVisibility");

	UAthenaSpectatorNameplate_C_UpdateVisibility_Params params;
	params.NameplateState = NameplateState;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PlayerNameChanged
// (Event, Protected, BlueprintEvent)
// Parameters:
// class AFortPlayerStateAthena** InPlayerState                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FString*                InPlayerName                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor)

void UAthenaSpectatorNameplate_C::PlayerNameChanged(class AFortPlayerStateAthena** InPlayerState, struct FString* InPlayerName)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PlayerNameChanged");

	UAthenaSpectatorNameplate_C_PlayerNameChanged_Params params;
	params.InPlayerState = InPlayerState;
	params.InPlayerName = InPlayerName;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.SetTeamColor
// (Event, Protected, BlueprintEvent)
// Parameters:
// struct FLinearColor*           TeamColor                      (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)

void UAthenaSpectatorNameplate_C::SetTeamColor(struct FLinearColor* TeamColor)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.SetTeamColor");

	UAthenaSpectatorNameplate_C_SetTeamColor_Params params;
	params.TeamColor = TeamColor;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.SetTeamNumber
// (Event, Protected, BlueprintEvent)
// Parameters:
// int*                           TeamNumber                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorNameplate_C::SetTeamNumber(int* TeamNumber)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.SetTeamNumber");

	UAthenaSpectatorNameplate_C_SetTeamNumber_Params params;
	params.TeamNumber = TeamNumber;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PlayerStateChanged
// (Event, Protected, BlueprintEvent)

void UAthenaSpectatorNameplate_C::PlayerStateChanged()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PlayerStateChanged");

	UAthenaSpectatorNameplate_C_PlayerStateChanged_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UAthenaSpectatorNameplate_C::Construct()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.Construct");

	UAthenaSpectatorNameplate_C_Construct_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool*                          IsDesignTime                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorNameplate_C::PreConstruct(bool* IsDesignTime)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PreConstruct");

	UAthenaSpectatorNameplate_C_PreConstruct_Params params;
	params.IsDesignTime = IsDesignTime;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.UpdateStateFromDistance
// (Event, Protected, BlueprintEvent)
// Parameters:
// float*                         DistanceToCamera               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorNameplate_C::UpdateStateFromDistance(float* DistanceToCamera)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.UpdateStateFromDistance");

	UAthenaSpectatorNameplate_C_UpdateStateFromDistance_Params params;
	params.DistanceToCamera = DistanceToCamera;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.ExecuteUbergraph_AthenaSpectatorNameplate
// (HasDefaults)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorNameplate_C::ExecuteUbergraph_AthenaSpectatorNameplate(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.ExecuteUbergraph_AthenaSpectatorNameplate");

	UAthenaSpectatorNameplate_C_ExecuteUbergraph_AthenaSpectatorNameplate_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
