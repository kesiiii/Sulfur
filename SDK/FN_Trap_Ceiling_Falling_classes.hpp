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

// BlueprintGeneratedClass Trap_Ceiling_Falling.Trap_Ceiling_Falling_C
// 0x00B1 (0x0E09 - 0x0D58)
class ATrap_Ceiling_Falling_C : public ABuildingTrapCeiling_Falling
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0D58(0x0008) (Transient, DuplicateTransient)
	class UStaticMeshComponent*                        Door_2_3;                                                 // 0x0D60(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Door_1_2;                                                 // 0x0D68(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    P_FallingDirt;                                            // 0x0D70(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_9_10;                                                // 0x0D78(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_8_9;                                                 // 0x0D80(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_7_8;                                                 // 0x0D88(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_6_7;                                                 // 0x0D90(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_5_6;                                                 // 0x0D98(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_4_5;                                                 // 0x0DA0(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_3_4;                                                 // 0x0DA8(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_2_3;                                                 // 0x0DB0(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        Tire_1_2;                                                 // 0x0DB8(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UStaticMeshComponent*                        StaticMesh1;                                              // 0x0DC0(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UBoxComponent*                               Box;                                                      // 0x0DC8(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class USceneComponent*                             Root;                                                     // 0x0DD0(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	float                                              OpenDoor_Rotation_679D553A46783E44EDCECCA7D120A863;       // 0x0DD8(0x0004) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETimelineDirection>                    OpenDoor__Direction_679D553A46783E44EDCECCA7D120A863;     // 0x0DDC(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0DDD(0x0003) MISSED OFFSET
	class UTimelineComponent*                          OpenDoor;                                                 // 0x0DE0(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	bool                                               SocketTransforms;                                         // 0x0DE8(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData01[0x7];                                       // 0x0DE9(0x0007) MISSED OFFSET
	TArray<class UStaticMeshComponent*>                Tires;                                                    // 0x0DF0(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	struct FTimerHandle                                TimerHandle;                                              // 0x0E00(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                               bActivated;                                               // 0x0E08(0x0001) (Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass Trap_Ceiling_Falling.Trap_Ceiling_Falling_C");
		return ptr;
	}


	void ToggleTiresAndFX();
	void ToggleDoors(bool bToggle);
	void OnRep_bActivated();
	void ToggleTireVisibility(bool NewHidden);
	void UserConstructionScript();
	void OpenDoor__FinishedFunc();
	void OpenDoor__UpdateFunc();
	void OnPlaced();
	void TrapActivated(float* CooldownDuration);
	void ShowTires();
	void FireDustFX();
	void OpenDoors();
	void CloseDoors();
	void ExecuteUbergraph_Trap_Ceiling_Falling(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
