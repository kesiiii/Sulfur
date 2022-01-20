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

// BlueprintGeneratedClass DA_PunchPack.DA_PunchPack_C
// 0x0021 (0x0BC1 - 0x0BA0)
class ADA_PunchPack_C : public AFortCustomizableAbilityDecoTool
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0BA0(0x0008) (Transient, DuplicateTransient)
	float                                              PunchPicker;                                              // 0x0BA8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0BAC(0x0004) MISSED OFFSET
	struct FTimerHandle                                ButtonHeldTimer;                                          // 0x0BB0(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               AlreadyReleased;                                          // 0x0BB8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x0BB9(0x0003) MISSED OFFSET
	float                                              MinHeldTime;                                              // 0x0BBC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               CanFire;                                                  // 0x0BC0(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass DA_PunchPack.DA_PunchPack_C");
		return ptr;
	}


	void IsOnGround(bool* bOnGround);
	void RaiseUsageError(const struct FGameplayTagContainer& FailedReason);
	void UserConstructionScript();
	void BPPressSecondaryFire(class AFortDecoHelper** FortDecoHelper);
	void BPReleaseSecondaryFire(class AFortDecoHelper** FortDecoHelper);
	void MinHeldTimeCheck();
	void BPOnUnEquip();
	void BPPressTrigger(class AFortDecoHelper** FortDecoHelper);
	void ExecuteUbergraph_DA_PunchPack(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
