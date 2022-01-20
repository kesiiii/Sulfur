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

// BlueprintGeneratedClass DA_HandyPack.DA_HandyPack_C
// 0x0030 (0x0BD0 - 0x0BA0)
class ADA_HandyPack_C : public AFortCustomizableAbilityDecoTool
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0BA0(0x0008) (Transient, DuplicateTransient)
	float                                              MinHeldTime;                                              // 0x0BA8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x0BAC(0x0004) MISSED OFFSET
	struct FTimerHandle                                ButtonHeldTimer;                                          // 0x0BB0(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               CanFire;                                                  // 0x0BB8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               AlreadyReleased;                                          // 0x0BB9(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x6];                                       // 0x0BBA(0x0006) MISSED OFFSET
	class ABP_Med_Pack_OverlapVolume_C*                OverlapVolume;                                            // 0x0BC0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	class AActor*                                      TargetToKnock;                                            // 0x0BC8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass DA_HandyPack.DA_HandyPack_C");
		return ptr;
	}


	void UserConstructionScript();
	void BPPressTrigger(class AFortDecoHelper** FortDecoHelper);
	void BPReleaseTrigger(class AFortDecoHelper** FortDecoHelper);
	void ExecuteUbergraph_DA_HandyPack(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
