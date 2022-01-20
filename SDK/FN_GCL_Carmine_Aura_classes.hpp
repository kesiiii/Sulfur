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

// BlueprintGeneratedClass GCL_Carmine_Aura.GCL_Carmine_Aura_C
// 0x0118 (0x0880 - 0x0768)
class AGCL_Carmine_Aura_C : public AFortGameplayCueNotify_Loop
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0768(0x0008) (Transient, DuplicateTransient)
	struct FFortGameplayCueParticleInfo                LandParticle;                                             // 0x0770(0x0058) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FFortBurstEffectData                        LandBurst;                                                // 0x07C8(0x00B8) (Edit, BlueprintVisible, DisableEditOnInstance)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GCL_Carmine_Aura.GCL_Carmine_Aura_C");
		return ptr;
	}


	void UserConstructionScript();
	void JimLanded(const struct FHitResult& Hit);
	void OnLoopingStart(class AActor** MyTarget, struct FGameplayCueParameters* Parameters, TArray<class UParticleSystemComponent*>* ParticleComponents, TArray<class UAudioComponent*>* AudioComponents);
	void OnRemoval(class AActor** MyTarget, struct FGameplayCueParameters* Parameters, TArray<class UParticleSystemComponent*>* ParticleComponents, TArray<class UAudioComponent*>* AudioComponents, class UCameraShake** BurstCameraShakeInstance, class ADecalActor** BurstDecalInstance);
	void ExecuteUbergraph_GCL_Carmine_Aura(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
