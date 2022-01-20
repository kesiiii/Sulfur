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

// BlueprintGeneratedClass GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C
// 0x0008 (0x0428 - 0x0420)
class AGCNL_Outlander_PhaseCannon_Active_C : public AFortGameplayCueNotify_Looping
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0420(0x0008) (Transient, DuplicateTransient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GCNL_Outlander_PhaseCannon_Active.GCNL_Outlander_PhaseCannon_Active_C");
		return ptr;
	}


	void OnWhileActiveParticleSystemActivate(class UParticleSystemComponent** WhileActiveParticleSysComponent, struct FGameplayCueParameters* Parameters);
	bool WhileActive(class AActor** MyTarget, struct FGameplayCueParameters* Parameters);
	void UserConstructionScript();
	void ReceiveBeginPlay();
	void ExecuteUbergraph_GCNL_Outlander_PhaseCannon_Active(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
