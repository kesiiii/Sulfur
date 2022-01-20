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

// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.OnWhileActiveParticleSystemActivate
// (Event, Public, HasOutParms, BlueprintCallable, BlueprintEvent, Const)
// Parameters:
// class UParticleSystemComponent** WhileActiveParticleSysComponent (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// struct FGameplayCueParameters* Parameters                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void AGCNL_Outlander_PhaseCannon_Active_C::OnWhileActiveParticleSystemActivate(class UParticleSystemComponent** WhileActiveParticleSysComponent, struct FGameplayCueParameters* Parameters)
{
	static auto fn = UObject::FindObject<UFunction>("Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.OnWhileActiveParticleSystemActivate");

	AGCNL_Outlander_PhaseCannon_Active_C_OnWhileActiveParticleSystemActivate_Params params;
	params.WhileActiveParticleSysComponent = WhileActiveParticleSysComponent;
	params.Parameters = Parameters;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.WhileActive
// (Event, Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor**                 MyTarget                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FGameplayCueParameters* Parameters                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// bool                           ReturnValue                    (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)

bool AGCNL_Outlander_PhaseCannon_Active_C::WhileActive(class AActor** MyTarget, struct FGameplayCueParameters* Parameters)
{
	static auto fn = UObject::FindObject<UFunction>("Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.WhileActive");

	AGCNL_Outlander_PhaseCannon_Active_C_WhileActive_Params params;
	params.MyTarget = MyTarget;
	params.Parameters = Parameters;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	return params.ReturnValue;
}


// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AGCNL_Outlander_PhaseCannon_Active_C::UserConstructionScript()
{
	static auto fn = UObject::FindObject<UFunction>("Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.UserConstructionScript");

	AGCNL_Outlander_PhaseCannon_Active_C_UserConstructionScript_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AGCNL_Outlander_PhaseCannon_Active_C::ReceiveBeginPlay()
{
	static auto fn = UObject::FindObject<UFunction>("Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.ReceiveBeginPlay");

	AGCNL_Outlander_PhaseCannon_Active_C_ReceiveBeginPlay_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.ExecuteUbergraph_GCNL_Outlander_PhaseCannon_Active
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void AGCNL_Outlander_PhaseCannon_Active_C::ExecuteUbergraph_GCNL_Outlander_PhaseCannon_Active(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C.ExecuteUbergraph_GCNL_Outlander_PhaseCannon_Active");

	AGCNL_Outlander_PhaseCannon_Active_C_ExecuteUbergraph_GCNL_Outlander_PhaseCannon_Active_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
