#pragma once

// Fortnite (5.21) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Parameters
//---------------------------------------------------------------------------

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.AddTeamToGrid
struct UAthenaEventTeamStatus_C_AddTeamToGrid_Params
{
	class UAthenaScoreboardTeamBase*                   TeamWidget;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                NumColumns;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.CalculateSquareGridHeight
struct UAthenaEventTeamStatus_C_CalculateSquareGridHeight_Params
{
	int                                                NumElements;                                              // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	int                                                GridHeight;                                               // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.CalculateRectangleGridHeight
struct UAthenaEventTeamStatus_C_CalculateRectangleGridHeight_Params
{
	int                                                NumElements;                                              // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	int                                                GridHeight;                                               // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.GetNumActiveColumns
struct UAthenaEventTeamStatus_C_GetNumActiveColumns_Params
{
	int                                                NumColumns;                                               // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ResetTeamGrid
struct UAthenaEventTeamStatus_C_ResetTeamGrid_Params
{
	class UUniformGridPanel*                           Grid;                                                     // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<class UAthenaScoreboardTeamBase*>           Children;                                                 // (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                NumColumns;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ShouldResizeActiveGrid
struct UAthenaEventTeamStatus_C_ShouldResizeActiveGrid_Params
{
	bool                                               bShouldResize;                                            // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                NumColumns;                                               // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ResetGrid
struct UAthenaEventTeamStatus_C_ResetGrid_Params
{
	class UUniformGridPanel*                           Grid;                                                     // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	TArray<class UAthenaScoreboardPlayerBase*>         Children;                                                 // (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)
	int                                                GridSize;                                                 // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.Construct
struct UAthenaEventTeamStatus_C_Construct_Params
{
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__ActivePlayersButton_K2Node_ComponentBoundEvent_40_OnButtonClickedEvent__DelegateSignature
struct UAthenaEventTeamStatus_C_BndEvt__ActivePlayersButton_K2Node_ComponentBoundEvent_40_OnButtonClickedEvent__DelegateSignature_Params
{
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__DeadPlayersButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature
struct UAthenaEventTeamStatus_C_BndEvt__DeadPlayersButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature_Params
{
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.OnTeamDied_BP
struct UAthenaEventTeamStatus_C_OnTeamDied_BP_Params
{
	class UAthenaScoreboardTeamBase**                  NewlyDeadTeamWidget;                                      // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.OnTeamAdded_BP
struct UAthenaEventTeamStatus_C_OnTeamAdded_BP_Params
{
	class UAthenaScoreboardTeamBase**                  NewlyAddedTeamWidget;                                     // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.BndEvt__CloseButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature
struct UAthenaEventTeamStatus_C_BndEvt__CloseButton_K2Node_ComponentBoundEvent_1_CommonButtonClicked__DelegateSignature_Params
{
	class UCommonButton*                               Button;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function AthenaEventTeamStatus.AthenaEventTeamStatus_C.ExecuteUbergraph_AthenaEventTeamStatus
struct UAthenaEventTeamStatus_C_ExecuteUbergraph_AthenaEventTeamStatus_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
