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

// BlueprintGeneratedClass GA_Constructor_FeelTheBase_DeathListener.GA_Constructor_FeelTheBase_DeathListener_C
// 0x0042 (0x09DC - 0x099A)
class UGA_Constructor_FeelTheBase_DeathListener_C : public UGAT_GenericTriggeredAbility_C
{
public:
	unsigned char                                      UnknownData00[0x6];                                       // 0x099A(0x0006) MISSED OFFSET
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x09A0(0x0008) (Transient, DuplicateTransient)
	class UClass*                                      StackCount;                                               // 0x09A8(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FGameplayTagContainer                       OverflowTag;                                              // 0x09B0(0x0020) (Edit, BlueprintVisible, DisableEditOnInstance)
	int                                                Stack1;                                                   // 0x09D0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                Stack2;                                                   // 0x09D4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	int                                                Stack3;                                                   // 0x09D8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GA_Constructor_FeelTheBase_DeathListener.GA_Constructor_FeelTheBase_DeathListener_C");
		return ptr;
	}


	void ActivateBaseStacks(int StackCount, class AB_Constructor_BASE_C* BaseReference);
	void Exceute_GC(class AB_Constructor_BASE_C* BaseReference, bool* Overflow);
	void K2_ActivateAbilityFromEvent(struct FGameplayEventData* EventData);
	void ExecuteUbergraph_GA_Constructor_FeelTheBase_DeathListener(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
