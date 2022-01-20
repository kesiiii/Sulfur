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

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.AddTeamToGrid
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAthenaScoreboardTeamBase* TeamWidget                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// int                            NumColumns                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::AddTeamToGrid(class UAthenaScoreboardTeamBase* TeamWidget, int NumColumns)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.AddTeamToGrid");

	UAthenaEventTeamStatus_C_AddTeamToGrid_Params params;
	params.TeamWidget = TeamWidget;
	params.NumColumns = NumColumns;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.CalculateSquareGridHeight
// (Private, HasOutParms, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int                            NumElements                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// int                            GridHeight                     (Parm, OutParm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::CalculateSquareGridHeight(int NumElements, int* GridHeight)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.CalculateSquareGridHeight");

	UAthenaEventTeamStatus_C_CalculateSquareGridHeight_Params params;
	params.NumElements = NumElements;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (GridHeight != nullptr)
		*GridHeight = params.GridHeight;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.CalculateRectangleGridHeight
// (Private, HasOutParms, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int                            NumElements                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// int                            GridHeight                     (Parm, OutParm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::CalculateRectangleGridHeight(int NumElements, int* GridHeight)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.CalculateRectangleGridHeight");

	UAthenaEventTeamStatus_C_CalculateRectangleGridHeight_Params params;
	params.NumElements = NumElements;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (GridHeight != nullptr)
		*GridHeight = params.GridHeight;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.GetNumActiveColumns
// (Private, HasOutParms, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// int                            NumColumns                     (Parm, OutParm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::GetNumActiveColumns(int* NumColumns)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.GetNumActiveColumns");

	UAthenaEventTeamStatus_C_GetNumActiveColumns_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (NumColumns != nullptr)
		*NumColumns = params.NumColumns;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ResetTeamGrid
// (Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UUniformGridPanel*       Grid                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// TArray<class UAthenaScoreboardTeamBase*> Children                       (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// int                            NumColumns                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::ResetTeamGrid(class UUniformGridPanel* Grid, int NumColumns, TArray<class UAthenaScoreboardTeamBase*>* Children)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ResetTeamGrid");

	UAthenaEventTeamStatus_C_ResetTeamGrid_Params params;
	params.Grid = Grid;
	params.NumColumns = NumColumns;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (Children != nullptr)
		*Children = params.Children;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ShouldResizeActiveGrid
// (Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                           bShouldResize                  (Parm, OutParm, ZeroConstructor, IsPlainOldData)
// int                            NumColumns                     (Parm, OutParm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::ShouldResizeActiveGrid(bool* bShouldResize, int* NumColumns)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ShouldResizeActiveGrid");

	UAthenaEventTeamStatus_C_ShouldResizeActiveGrid_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (bShouldResize != nullptr)
		*bShouldResize = params.bShouldResize;
	if (NumColumns != nullptr)
		*NumColumns = params.NumColumns;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ResetGrid
// (Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UUniformGridPanel*       Grid                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// TArray<class UAthenaScoreboardPlayerBase*> Children                       (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
// int                            GridSize                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::ResetGrid(class UUniformGridPanel* Grid, int GridSize, TArray<class UAthenaScoreboardPlayerBase*>* Children)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ResetGrid");

	UAthenaEventTeamStatus_C_ResetGrid_Params params;
	params.Grid = Grid;
	params.GridSize = GridSize;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (Children != nullptr)
		*Children = params.Children;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UAthenaEventTeamStatus_C::Construct()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.Construct");

	UAthenaEventTeamStatus_C_Construct_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__ActivePlayersButton_K2Node_ComponentBoundEvent_40_OnButtonClickedEvent__DelegateSignature
// (BlueprintEvent)

void UAthenaEventTeamStatus_C::BndEvt__ActivePlayersButton_K2Node_ComponentBoundEvent_40_OnButtonClickedEvent__DelegateSignature()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__ActivePlayersButton_K2Node_ComponentBoundEvent_40_OnButtonClickedEvent__DelegateSignature");

	UAthenaEventTeamStatus_C_BndEvt__ActivePlayersButton_K2Node_ComponentBoundEvent_40_OnButtonClickedEvent__DelegateSignature_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__DeadPlayersButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature
// (BlueprintEvent)

void UAthenaEventTeamStatus_C::BndEvt__DeadPlayersButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__DeadPlayersButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature");

	UAthenaEventTeamStatus_C_BndEvt__DeadPlayersButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.OnTeamDied_BP
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAthenaScoreboardTeamBase** NewlyDeadTeamWidget            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UAthenaEventTeamStatus_C::OnTeamDied_BP(class UAthenaScoreboardTeamBase** NewlyDeadTeamWidget)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.OnTeamDied_BP");

	UAthenaEventTeamStatus_C_OnTeamDied_BP_Params params;
	params.NewlyDeadTeamWidget = NewlyDeadTeamWidget;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.OnTeamAdded_BP
// (Event, Protected, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAthenaScoreboardTeamBase** NewlyAddedTeamWidget           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UAthenaEventTeamStatus_C::OnTeamAdded_BP(class UAthenaScoreboardTeamBase** NewlyAddedTeamWidget)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.OnTeamAdded_BP");

	UAthenaEventTeamStatus_C_OnTeamAdded_BP_Params params;
	params.NewlyAddedTeamWidget = NewlyAddedTeamWidget;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__CloseButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*           Button                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UAthenaEventTeamStatus_C::BndEvt__CloseButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature(class UCommonButton* Button)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__CloseButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature");

	UAthenaEventTeamStatus_C_BndEvt__CloseButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature_Params params;
	params.Button = Button;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ExecuteUbergraph_AthenaEventTeamStatus
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaEventTeamStatus_C::ExecuteUbergraph_AthenaEventTeamStatus(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ExecuteUbergraph_AthenaEventTeamStatus");

	UAthenaEventTeamStatus_C_ExecuteUbergraph_AthenaEventTeamStatus_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
