#pragma once

// Fortnite (5.21) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// BlueprintGeneratedClass GA_Athena_ZipLine_MoveToLocation.GA_Athena_ZipLine_MoveToLocation_C
// 0x0038 (0x0908 - 0x08D0)
class UGA_Athena_ZipLine_MoveToLocation_C : public UFortGameplayAbility
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x08D0(0x0008) (Transient, DuplicateTransient)
	struct FGameplayTag                                EventTriggerTagA;                                         // 0x08D8(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                EventTriggerTagB;                                         // 0x08E0(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               bIsTraveling;                                             // 0x08E8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x08E9(0x0007) MISSED OFFSET
	class UAbilityTask_ApplyRootMotionMoveToForce*     PlayerMovement;                                           // 0x08F0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FTimerHandle                                LineTraceCheck;                                           // 0x08F8(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	class AB_Prj_Athena_ZipLine_Primary_C*             ZipLinePrimary;                                           // 0x0900(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GA_Athena_ZipLine_MoveToLocation.GA_Athena_ZipLine_MoveToLocation_C");
		return ptr;
	}


	void OnTimedOutAndDestinationReached_33FEF4B74C81B887F8E6D3B55B38FC7D();
	void OnTimedOut_33FEF4B74C81B887F8E6D3B55B38FC7D();
	void OnTimedOutAndDestinationReached_33FEF4B74C81B887F8E6D3B518EBF39F();
	void OnTimedOut_33FEF4B74C81B887F8E6D3B518EBF39F();
	void EventReceived_20C2E1834971499489C165A2B10EBE34(const struct FGameplayEventData& Payload);
	void EventReceived_F91E99724E7B1544B779CFAC235CE860(const struct FGameplayEventData& Payload);
	void K2_ActivateAbility();
	void TraceForObjectsInPath();
	void ExecuteUbergraph_GA_Athena_ZipLine_MoveToLocation(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
