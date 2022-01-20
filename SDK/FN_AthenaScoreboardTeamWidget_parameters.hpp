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

// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.AddToGrid
struct UAthenaScoreboardTeamWidget_C_AddToGrid_Params
{
	class UAthenaScoreboardPlayerBase*                 PlayerWidget;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.OnPlayerWidgetAdded
struct UAthenaScoreboardTeamWidget_C_OnPlayerWidgetAdded_Params
{
	class UAthenaScoreboardPlayerBase**                PlayerWidget;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
};

// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.SetScale
struct UAthenaScoreboardTeamWidget_C_SetScale_Params
{
	float*                                             Scale;                                                    // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaScoreboardTeamWidget.AthenaScoreboardTeamWidget_C.ExecuteUbergraph_AthenaScoreboardTeamWidget
struct UAthenaScoreboardTeamWidget_C_ExecuteUbergraph_AthenaScoreboardTeamWidget_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
