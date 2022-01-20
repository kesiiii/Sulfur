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

// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_ZipLineLocation
// (BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::OnRep_ZipLineLocation()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_ZipLineLocation");

	AB_Prj_Athena_ZipLine_Primary_C_OnRep_ZipLineLocation_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_ActorsToZipLine
// (BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::OnRep_ActorsToZipLine()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_ActorsToZipLine");

	AB_Prj_Athena_ZipLine_Primary_C_OnRep_ActorsToZipLine_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.GateActorType
// (Public, HasOutParms, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                  OverlappingActor               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// bool                           ValidActor                     (Parm, OutParm, ZeroConstructor, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::GateActorType(class AActor* OverlappingActor, bool* ValidActor)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.GateActorType");

	AB_Prj_Athena_ZipLine_Primary_C_GateActorType_Params params;
	params.OverlappingActor = OverlappingActor;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (ValidActor != nullptr)
		*ValidActor = params.ValidActor;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_TargetZipLine
// (BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::OnRep_TargetZipLine()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnRep_TargetZipLine");

	AB_Prj_Athena_ZipLine_Primary_C_OnRep_TargetZipLine_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.GetDestinationLoc
// (Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class AActor*                  TeleportingActor               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FVector                 Location                       (Parm, OutParm, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::GetDestinationLoc(class AActor* TeleportingActor, struct FVector* Location)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.GetDestinationLoc");

	AB_Prj_Athena_ZipLine_Primary_C_GetDestinationLoc_Params params;
	params.TeleportingActor = TeleportingActor;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (Location != nullptr)
		*Location = params.Location;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.StartZipLine
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AActor*                  TargetToZip                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::StartZipLine(class AActor* TargetToZip)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.StartZipLine");

	AB_Prj_Athena_ZipLine_Primary_C_StartZipLine_Params params;
	params.TargetToZip = TargetToZip;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.SetZipLineTarget
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class AB_Prj_Athena_ZipLine_Primary_C* Actor                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::SetZipLineTarget(class AB_Prj_Athena_ZipLine_Primary_C* Actor)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.SetZipLineTarget");

	AB_Prj_Athena_ZipLine_Primary_C_SetZipLineTarget_Params params;
	params.Actor = Actor;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.UserConstructionScript
// (Event, Public, BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::UserConstructionScript()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.UserConstructionScript");

	AB_Prj_Athena_ZipLine_Primary_C_UserConstructionScript_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Timeline_0__FinishedFunc
// (BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::Timeline_0__FinishedFunc()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Timeline_0__FinishedFunc");

	AB_Prj_Athena_ZipLine_Primary_C_Timeline_0__FinishedFunc_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Timeline_0__UpdateFunc
// (BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::Timeline_0__UpdateFunc()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Timeline_0__UpdateFunc");

	AB_Prj_Athena_ZipLine_Primary_C_Timeline_0__UpdateFunc_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature
// (HasOutParms, BlueprintEvent)
// Parameters:
// class UPrimitiveComponent*     OverlappedComponent            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// class AActor*                  OtherActor                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// class UPrimitiveComponent*     OtherComp                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)
// int                            OtherBodyIndex                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// bool                           bFromSweep                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// struct FHitResult              SweepResult                    (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature");

	AB_Prj_Athena_ZipLine_Primary_C_BndEvt__CapsuleComponent_K2Node_ComponentBoundEvent_0_ComponentBeginOverlapSignature__DelegateSignature_Params params;
	params.OverlappedComponent = OverlappedComponent;
	params.OtherActor = OtherActor;
	params.OtherComp = OtherComp;
	params.OtherBodyIndex = OtherBodyIndex;
	params.bFromSweep = bFromSweep;
	params.SweepResult = SweepResult;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.BindOverlap
// (Net, NetReliable, NetMulticast, BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::BindOverlap()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.BindOverlap");

	AB_Prj_Athena_ZipLine_Primary_C_BindOverlap_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Reset
// (BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::Reset()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Reset");

	AB_Prj_Athena_ZipLine_Primary_C_Reset_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ZipLineFX
// (Net, NetMulticast, BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::ZipLineFX()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ZipLineFX");

	AB_Prj_Athena_ZipLine_Primary_C_ZipLineFX_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Stop_Rotation
// (BlueprintCallable, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::Stop_Rotation()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.Stop_Rotation");

	AB_Prj_Athena_ZipLine_Primary_C_Stop_Rotation_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void AB_Prj_Athena_ZipLine_Primary_C::ReceiveBeginPlay()
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ReceiveBeginPlay");

	AB_Prj_Athena_ZipLine_Primary_C_ReceiveBeginPlay_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnStop
// (Event, Public, HasOutParms, BlueprintEvent)
// Parameters:
// struct FHitResult*             Hit                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::OnStop(struct FHitResult* Hit)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.OnStop");

	AB_Prj_Athena_ZipLine_Primary_C_OnStop_Params params;
	params.Hit = Hit;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ReceiveAnyDamage
// (BlueprintAuthorityOnly, Event, Public, BlueprintEvent)
// Parameters:
// float*                         Damage                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// class UDamageType**            DamageType                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// class AController**            InstigatedBy                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)
// class AActor**                 DamageCauser                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::ReceiveAnyDamage(float* Damage, class UDamageType** DamageType, class AController** InstigatedBy, class AActor** DamageCauser)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ReceiveAnyDamage");

	AB_Prj_Athena_ZipLine_Primary_C_ReceiveAnyDamage_Params params;
	params.Damage = Damage;
	params.DamageType = DamageType;
	params.InstigatedBy = InstigatedBy;
	params.DamageCauser = DamageCauser;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ExecuteUbergraph_B_Prj_Athena_ZipLine_Primary
// (HasDefaults)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void AB_Prj_Athena_ZipLine_Primary_C::ExecuteUbergraph_B_Prj_Athena_ZipLine_Primary(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function B_Prj_Athena_ZipLine_Primary.B_Prj_Athena_ZipLine_Primary_C.ExecuteUbergraph_B_Prj_Athena_ZipLine_Primary");

	AB_Prj_Athena_ZipLine_Primary_C_ExecuteUbergraph_B_Prj_Athena_ZipLine_Primary_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
