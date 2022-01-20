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

// BlueprintGeneratedClass ShielderPawn.ShielderPawn_C
// 0x0190 (0x2080 - 0x1EF0)
class AShielderPawn_C : public AEnemyPawn_Parent_C
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x1EF0(0x0008) (Transient, DuplicateTransient)
	class USphereComponent*                            ShielderReAttachRange;                                    // 0x1EF8(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              RotateShielder_LerpAlpha_F33B1BA94860E62F431B509EF30FFA64;// 0x1F00(0x0004) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETimelineDirection>                    RotateShielder__Direction_F33B1BA94860E62F431B509EF30FFA64;// 0x1F04(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x1F05(0x0003) MISSED OFFSET
	class UTimelineComponent*                          RotateShielder;                                           // 0x1F08(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              InterpShielderToNewLocation_LerpAlpha_4C3E0C0B4BF05DD8DEA964BC480F2112;// 0x1F10(0x0004) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETimelineDirection>                    InterpShielderToNewLocation__Direction_4C3E0C0B4BF05DD8DEA964BC480F2112;// 0x1F14(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x3];                                       // 0x1F15(0x0003) MISSED OFFSET
	class UTimelineComponent*                          InterpShielderToNewLocation;                              // 0x1F18(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               Debug;                                                    // 0x1F20(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               AttemptingReAttach;                                       // 0x1F21(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               ShielderVisible;                                          // 0x1F22(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               OrphanForceKill;                                          // 0x1F23(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               Orphaned_0_1;                                             // 0x1F24(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData02[0x3];                                       // 0x1F25(0x0003) MISSED OFFSET
	float                                              GameTimeWhenOrphaned;                                     // 0x1F28(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData03[0x4];                                       // 0x1F2C(0x0004) MISSED OFFSET
	class AFortPawn*                                   AttachPawn;                                               // 0x1F30(0x0008) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	class UClass*                                      GE_ShielderShield;                                        // 0x1F38(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class AFortPawn*                                   PotentialAttachPawn;                                      // 0x1F40(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	TArray<class AFortPawn*>                           PotentialAttachPawns;                                     // 0x1F48(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance)
	class UClass*                                      ShielderSpringArmClass;                                   // 0x1F58(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class AShielderSpringArm_C*                        ShielderSpringArm;                                        // 0x1F60(0x0008) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)
	struct FRotator                                    SpringArmTargetRotation;                                  // 0x1F68(0x000C) (Edit, BlueprintVisible, Net, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData04[0x4];                                       // 0x1F74(0x0004) MISSED OFFSET
	class UFortAbilitySet*                             AttachPawnAbilitySet;                                     // 0x1F78(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FCurveTableRowHandle                        EnemyScalingSheet;                                        // 0x1F80(0x0010) (Edit, BlueprintVisible, DisableEditOnInstance)
	class UParticleSystemComponent*                    P_ShielderSphere;                                         // 0x1F90(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	struct FCurveTableRowHandle                        NPCMiscCurvesSheet;                                       // 0x1F98(0x0010) (Edit, BlueprintVisible, DisableEditOnInstance)
	float                                              OrphanTimeBeforeReAttachByEncounter;                      // 0x1FA8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              OrphanTimeBeforeReAttachByProximity;                      // 0x1FAC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              OrphanTimeBeforceForceKill;                               // 0x1FB0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              MaxTimeToReAttachByEncounter;                             // 0x1FB4(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              ShielderVisibilityDelayWhenAttachingToSpawningPawn;       // 0x1FB8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData05[0x4];                                       // 0x1FBC(0x0004) MISSED OFFSET
	struct FGameplayTag                                TC_NPCStatusWearingShielder;                              // 0x1FC0(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                TC_NPCAbilityNonAttackTeleportOut;                        // 0x1FC8(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                TC_NPCAbilityNonAttackTeleportIn;                         // 0x1FD0(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                TC_NPCAbilityNonAttackSummon;                             // 0x1FD8(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                TC_NPCAbilityNonAttackDropNPC;                            // 0x1FE0(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	float                                              SpringArmRotationTimeMin;                                 // 0x1FE8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SpringArmRotationTimeMax;                                 // 0x1FEC(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              OrphanDetachZVelocity;                                    // 0x1FF0(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData06[0x4];                                       // 0x1FF4(0x0004) MISSED OFFSET
	struct FFortAbilitySetHandle                       ShielderAttachPawnAbilitySet;                             // 0x1FF8(0x0028) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                GameplayCueShieldReapplied;                               // 0x2020(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                GameplayCueShieldDestroyed;                               // 0x2028(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	class USoundBase*                                  Sound_ShieldStart_NoLoop;                                 // 0x2030(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundBase*                                  Sound_ShieldBroken;                                       // 0x2038(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundBase*                                  Sound_ShieldStart;                                        // 0x2040(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	bool                                               bShieldApplied;                                           // 0x2048(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData07[0x7];                                       // 0x2049(0x0007) MISSED OFFSET
	struct FGameplayTag                                TC_HuskSmasher;                                           // 0x2050(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                                TC_HuskTaker;                                             // 0x2058(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	class UClass*                                      GE_HideOnMiniMap;                                         // 0x2060(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class UAudioComponent*                             Sound_ShieldStart_Spawned;                                // 0x2068(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	bool                                               SuperShielder;                                            // 0x2070(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData08[0x3];                                       // 0x2071(0x0003) MISSED OFFSET
	float                                              SuperShieldOffsetFromGround;                              // 0x2074(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	class ABGA_SuperShielder_Shield_C*                 BGA_SuperShielder_Shield_Spawned;                         // 0x2078(0x0008) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass ShielderPawn.ShielderPawn_C");
		return ptr;
	}


	void SpawnSuperShielderBGA();
	void RemoveShield(class AActor* RemoveShieldFrom);
	void Orphaned(bool* IsOrphaned, class AFortPawn** AttachedPawn);
	void SetMiniMapIconStatus();
	void OnRep_bShieldApplied();
	void UpdateShieldFXVisibility();
	void ApplyShield();
	void GameTimeString(struct FString* NewParam);
	void OnRep_ShielderSpringArm();
	void DebugLineAndSphere(bool Line, const struct FLinearColor& LineColor, bool Sphere, const struct FLinearColor& SphereColor, float VisibilityOffset);
	void OnRep_ShielderVisible();
	void AttachShielderToSpringArm();
	void AttachSpringArmToAttachPawn();
	void UserConstructionScript();
	void InterpShielderToNewLocation__FinishedFunc();
	void InterpShielderToNewLocation__UpdateFunc();
	void RotateShielder__FinishedFunc();
	void RotateShielder__UpdateFunc();
	void OnStunned();
	void OnDamageServer(float* Damage, struct FGameplayTagContainer* DamageTags, struct FVector* Momentum, struct FHitResult* HitInfo, class AController** InstigatedBy, class AActor** DamageCauser, struct FGameplayEffectContextHandle* EffectContext);
	void OnKnockedback();
	void ReceiveBeginPlay();
	void OnDeathServer(float* Damage, struct FGameplayTagContainer* DamageTags, struct FVector* Momentum, struct FHitResult* HitInfo, class AController** InstigatedBy, class AActor** DamageCauser, struct FGameplayEffectContextHandle* EffectContext);
	void ShielderAttachComplete();
	void OnEncounterEnemySpawned(class UFortAIEncounterInfo* Encounter, class AFortAIPawn* SpawnedEnemy);
	void SetShielderOrphanStatus(bool Orphaned, bool GiveZVelocityOnDetach, const struct FString& Reason);
	void OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void VerifyPotentialAttachPawnIsValidAndAttachToIt(class AFortPawn* PotentialAttachPawn, bool HiddenAttach);
	void GrabRandomPotentialAttachPawn(bool HiddenAttach);
	void AttachShielderToPotentialAttachPawn();
	void BindEncounterSpawn();
	void ReApplyShield();
	void UnBindEncounterSpawn();
	void OnComponentEndOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int OtherBodyIndex);
	void ShielderShieldBroken();
	void AnimateSpringArm();
	void AttachPawnDead(bool Despawn);
	void OrphanForceKillTimer();
	void BindProxOverlap();
	void UnBindProxOverlap();
	void InterpShielderToSpringArm();
	void RotateShielderForward();
	void AdditiveHitReactDelay();
	void InvisibleOrphanTick();
	void ReceiveEndPlay(TEnumAsByte<EEndPlayReason>* EndPlayReason);
	void PostSpawnIn();
	void ExecuteUbergraph_ShielderPawn(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
