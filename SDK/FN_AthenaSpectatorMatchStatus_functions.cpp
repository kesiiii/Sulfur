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

// Function AthenaSpectatorMatchStatus.AthenaSpectatorMatchStatus_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UAthenaSpectatorMatchStatus_C::Construct()
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorMatchStatus.AthenaSpectatorMatchStatus_C.Construct");

	UAthenaSpectatorMatchStatus_C_Construct_Params params;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


// Function AthenaSpectatorMatchStatus.AthenaSpectatorMatchStatus_C.ExecuteUbergraph_AthenaSpectatorMatchStatus
// ()
// Parameters:
// int                            EntryPoint                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData)

void UAthenaSpectatorMatchStatus_C::ExecuteUbergraph_AthenaSpectatorMatchStatus(int EntryPoint)
{
	static auto fn = UObject::FindObject<UFunction>("Function AthenaSpectatorMatchStatus.AthenaSpectatorMatchStatus_C.ExecuteUbergraph_AthenaSpectatorMatchStatus");

	UAthenaSpectatorMatchStatus_C_ExecuteUbergraph_AthenaSpectatorMatchStatus_Params params;
	params.EntryPoint = EntryPoint;

	auto flags = fn->FunctionFlags;

	UObject::ProcessEvent(fn, &params);

	fn->FunctionFlags = flags;
}


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
