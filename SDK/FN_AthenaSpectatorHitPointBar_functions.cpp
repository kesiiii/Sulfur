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

// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.InitializeBar
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)

void UAthenaSpectatorHitPointBar_C::InitializeBar()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.InitializeBar");

	UAthenaSpectatorHitPointBar_C_InitializeBar_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool*                          IsDesignTime                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorHitPointBar_C::PreConstruct(bool* IsDesignTime)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.PreConstruct");

	UAthenaSpectatorHitPointBar_C_PreConstruct_Params params;
	params.IsDesignTime = IsDesignTime;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.UpdateBars_BP
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void UAthenaSpectatorHitPointBar_C::UpdateBars_BP()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.UpdateBars_BP");

	UAthenaSpectatorHitPointBar_C_UpdateBars_BP_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.OnDBNOChanged_BP
// (Event, Protected, BlueprintCallable, BlueprintEvent)

void UAthenaSpectatorHitPointBar_C::OnDBNOChanged_BP()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.OnDBNOChanged_BP");

	UAthenaSpectatorHitPointBar_C_OnDBNOChanged_BP_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.ExecuteUbergraph_AthenaSpectatorHitPointBar
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorHitPointBar_C::ExecuteUbergraph_AthenaSpectatorHitPointBar(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorHitPointBar.AthenaSpectatorHitPointBar_C.ExecuteUbergraph_AthenaSpectatorHitPointBar");

	UAthenaSpectatorHitPointBar_C_ExecuteUbergraph_AthenaSpectatorHitPointBar_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
