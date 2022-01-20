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

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.UpdateVisibility
struct UAthenaSpectatorNameplate_C_UpdateVisibility_Params
{
	TEnumAsByte<EAthenaSpectatorNameplateState>        NameplateState;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PlayerNameChanged
struct UAthenaSpectatorNameplate_C_PlayerNameChanged_Params
{
	class AFortPlayerStateAthena**                     InPlayerState;                                            // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FString*                                    InPlayerName;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor)
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.SetTeamColor
struct UAthenaSpectatorNameplate_C_SetTeamColor_Params
{
	struct FLinearColor*                               TeamColor;                                                // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.SetTeamNumber
struct UAthenaSpectatorNameplate_C_SetTeamNumber_Params
{
	int*                                               TeamNumber;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PlayerStateChanged
struct UAthenaSpectatorNameplate_C_PlayerStateChanged_Params
{
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.Construct
struct UAthenaSpectatorNameplate_C_Construct_Params
{
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.PreConstruct
struct UAthenaSpectatorNameplate_C_PreConstruct_Params
{
	bool*                                              IsDesignTime;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.UpdateStateFromDistance
struct UAthenaSpectatorNameplate_C_UpdateStateFromDistance_Params
{
	float*                                             DistanceToCamera;                                         // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaSpectatorNameplate.AthenaSpectatorNameplate_C.ExecuteUbergraph_AthenaSpectatorNameplate
struct UAthenaSpectatorNameplate_C_ExecuteUbergraph_AthenaSpectatorNameplate_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
