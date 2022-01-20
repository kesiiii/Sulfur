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

// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.OnWhileActiveParticleSystemActivate
struct AGCNL_Outlander_PhaseCannon_Active_C_OnWhileActiveParticleSystemActivate_Params
{
	class UParticleSystemComponent**                   WhileActiveParticleSysComponent;                          // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FGameplayCueParameters*                     Parameters;                                               // (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};

// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.WhileActive
struct AGCNL_Outlander_PhaseCannon_Active_C_WhileActive_Params
{
	class AActor**                                     MyTarget;                                                 // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FGameplayCueParameters*                     Parameters;                                               // (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.UserConstructionScript
struct AGCNL_Outlander_PhaseCannon_Active_C_UserConstructionScript_Params
{
};

// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.ReceiveBeginPlay
struct AGCNL_Outlander_PhaseCannon_Active_C_ReceiveBeginPlay_Params
{
};

// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.ExecuteUbergraph_GCNL_Outlander_PhaseCannon_Active
struct AGCNL_Outlander_PhaseCannon_Active_C_ExecuteUbergraph_GCNL_Outlander_PhaseCannon_Active_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
