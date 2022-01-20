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

// Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UAthenaEventInfoScreen_C::Construct()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.Construct");

	UAthenaEventInfoScreen_C_Construct_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.BndEvt__PreviousButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature
// (BlueprintEvent)

void UAthenaEventInfoScreen_C::BndEvt__PreviousButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.BndEvt__PreviousButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature");

	UAthenaEventInfoScreen_C_BndEvt__PreviousButton_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.BndEvt__NextButton_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature
// (BlueprintEvent)

void UAthenaEventInfoScreen_C::BndEvt__NextButton_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.BndEvt__NextButton_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature");

	UAthenaEventInfoScreen_C_BndEvt__NextButton_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.BndEvt__CloseButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*           Button                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData)

void UAthenaEventInfoScreen_C::BndEvt__CloseButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature(class UCommonButton* Button)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.BndEvt__CloseButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature");

	UAthenaEventInfoScreen_C_BndEvt__CloseButton_K2Node_ComponentBoundEvent_2_CommonButtonClicked__DelegateSignature_Params params;
	params.Button = Button;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.ExecuteUbergraph_AthenaEventInfoScreen
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaEventInfoScreen_C::ExecuteUbergraph_AthenaEventInfoScreen(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaEventInfoScreen.AthenaEventInfoScreen_C.ExecuteUbergraph_AthenaEventInfoScreen");

	UAthenaEventInfoScreen_C_ExecuteUbergraph_AthenaEventInfoScreen_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
