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

// Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.OnFollowedPlayerChanged
struct UAthenaSpectatorPlayerStatus_C_OnFollowedPlayerChanged_Params
{
	class AFortPlayerControllerSpectating*             SpectatorController;                                      // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class AFortPlayerState*                            NewFollowedPlayer;                                        // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.Construct
struct UAthenaSpectatorPlayerStatus_C_Construct_Params
{
};

// Function AthenaSpectatorPlayerStatus.AthenaSpectatorPlayerStatus_C.ExecuteUbergraph_AthenaSpectatorPlayerStatus
struct UAthenaSpectatorPlayerStatus_C_ExecuteUbergraph_AthenaSpectatorPlayerStatus_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
