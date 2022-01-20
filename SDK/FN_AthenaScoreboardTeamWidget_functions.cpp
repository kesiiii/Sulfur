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

// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.AddToGrid
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAthenaScoreboardPlayerBase* PlayerWidget                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UAthenaScoreboardTeamWidget_C::AddToGrid(class UAthenaScoreboardPlayerBase* PlayerWidget)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.AddToGrid");

	UAthenaScoreboardTeamWidget_C_AddToGrid_Params params;
	params.PlayerWidget = PlayerWidget;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.OnPlayerWidgetAdded
// (Event, Protected, BlueprintEvent)
// Parameters:
// class UAthenaScoreboardPlayerBase** PlayerWidget                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UAthenaScoreboardTeamWidget_C::OnPlayerWidgetAdded(class UAthenaScoreboardPlayerBase** PlayerWidget)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.OnPlayerWidgetAdded");

	UAthenaScoreboardTeamWidget_C_OnPlayerWidgetAdded_Params params;
	params.PlayerWidget = PlayerWidget;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.SetScale
// (Event, Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float*                         Scale                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaScoreboardTeamWidget_C::SetScale(float* Scale)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.SetScale");

	UAthenaScoreboardTeamWidget_C_SetScale_Params params;
	params.Scale = Scale;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.ExecuteUbergraph_AthenaScoreboardTeamWidget
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaScoreboardTeamWidget_C::ExecuteUbergraph_AthenaScoreboardTeamWidget(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.ExecuteUbergraph_AthenaScoreboardTeamWidget");

	UAthenaScoreboardTeamWidget_C_ExecuteUbergraph_AthenaScoreboardTeamWidget_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
