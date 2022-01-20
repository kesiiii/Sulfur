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

// Function SpectatedPlayerItem.SpectatedPlayerItem_C.OnClicked
// (Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry               MyGeometry                     (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
// struct FPointerEvent           MouseEvent                     (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply             Reply                          (Parm, OutParm)

void USpectatedPlayerItem_C::OnClicked(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent, struct FEventReply* Reply)
{
	static auto fn = UObject::FindObject<UFunction>("Function SpectatedPlayerItem.SpectatedPlayerItem_C.OnClicked");

	USpectatedPlayerItem_C_OnClicked_Params params;
	params.MyGeometry = MyGeometry;
	params.MouseEvent = MouseEvent;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (Reply != nullptr)
		*Reply = params.Reply;
}


// Function SpectatedPlayerItem.SpectatedPlayerItem_C.SetPlayer
// (Public, HasOutParms, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPotentialSpectatorTarget SpectatorInfo                  (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void USpectatedPlayerItem_C::SetPlayer(struct FPotentialSpectatorTarget* SpectatorInfo)
{
	static auto fn = UObject::FindObject<UFunction>("Function SpectatedPlayerItem.SpectatedPlayerItem_C.SetPlayer");

	USpectatedPlayerItem_C_SetPlayer_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;

	if (SpectatorInfo != nullptr)
		*SpectatorInfo = params.SpectatorInfo;
}


// Function SpectatedPlayerItem.SpectatedPlayerItem_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool*                          IsDesignTime                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void USpectatedPlayerItem_C::PreConstruct(bool* IsDesignTime)
{
	static auto fn = UObject::FindObject<UFunction>("Function SpectatedPlayerItem.SpectatedPlayerItem_C.PreConstruct");

	USpectatedPlayerItem_C_PreConstruct_Params params;
	params.IsDesignTime = IsDesignTime;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function SpectatedPlayerItem.SpectatedPlayerItem_C.ExecuteUbergraph_SpectatedPlayerItem
// (HasDefaults)
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void USpectatedPlayerItem_C::ExecuteUbergraph_SpectatedPlayerItem(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function SpectatedPlayerItem.SpectatedPlayerItem_C.ExecuteUbergraph_SpectatedPlayerItem");

	USpectatedPlayerItem_C_ExecuteUbergraph_SpectatedPlayerItem_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
