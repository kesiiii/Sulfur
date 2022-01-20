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

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_ZipLineLocation
struct AB_Prj_Athena_ZipLine_Primary_C_OnRep_ZipLineLocation_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_ActorsToZipLine
struct AB_Prj_Athena_ZipLine_Primary_C_OnRep_ActorsToZipLine_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.GateActorType
struct AB_Prj_Athena_ZipLine_Primary_C_GateActorType_Params
{
	class AActor*                                      OverlappingActor;                                         // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ValidActor;                                               // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_TargetZipLine
struct AB_Prj_Athena_ZipLine_Primary_C_OnRep_TargetZipLine_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.GetDestinationLoc
struct AB_Prj_Athena_ZipLine_Primary_C_GetDestinationLoc_Params
{
	class AActor*                                      TeleportingActor;                                         // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FVector                                     Location;                                                 // (Parm, OutParm, IsPlainOldData)
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.StartZipLine
struct AB_Prj_Athena_ZipLine_Primary_C_StartZipLine_Params
{
	class AActor*                                      TargetToZip;                                              // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.SetZipLineTarget
struct AB_Prj_Athena_ZipLine_Primary_C_SetZipLineTarget_Params
{
	class AB_Prj_Athena_ZipLine_Primary_C*             Actor;                                                    // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.UserConstructionScript
struct AB_Prj_Athena_ZipLine_Primary_C_UserConstructionScript_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Timeline_0__FinishedFunc
struct AB_Prj_Athena_ZipLine_Primary_C_Timeline_0__FinishedFunc_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Timeline_0__UpdateFunc
struct AB_Prj_Athena_ZipLine_Primary_C_Timeline_0__UpdateFunc_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature
struct AB_Prj_Athena_ZipLine_Primary_C_BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature_Params
{
	class UPrimitiveComponent*                         OverlappedComponent;                                      // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	class AActor*                                      OtherActor;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UPrimitiveComponent*                         OtherComp;                                                // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
	int                                                OtherBodyIndex;                                           // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bFromSweep;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	struct FHitResult                                  SweepResult;                                              // (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.BindOverlap
struct AB_Prj_Athena_ZipLine_Primary_C_BindOverlap_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Reset
struct AB_Prj_Athena_ZipLine_Primary_C_Reset_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ZipLineFX
struct AB_Prj_Athena_ZipLine_Primary_C_ZipLineFX_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Stop_Rotation
struct AB_Prj_Athena_ZipLine_Primary_C_Stop_Rotation_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ReceiveBeginPlay
struct AB_Prj_Athena_ZipLine_Primary_C_ReceiveBeginPlay_Params
{
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnStop
struct AB_Prj_Athena_ZipLine_Primary_C_OnStop_Params
{
	struct FHitResult*                                 Hit;                                                      // (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData)
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ReceiveAnyDamage
struct AB_Prj_Athena_ZipLine_Primary_C_ReceiveAnyDamage_Params
{
	float*                                             Damage;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class UDamageType**                                DamageType;                                               // (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class AController**                                InstigatedBy;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
	class AActor**                                     DamageCauser;                                             // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ExecuteUbergraph_B_Prj_Athena_ZipLine_Primary
struct AB_Prj_Athena_ZipLine_Primary_C_ExecuteUbergraph_B_Prj_Athena_ZipLine_Primary_Params
{
	int                                                EntryPoint;                                               // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
};

}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
