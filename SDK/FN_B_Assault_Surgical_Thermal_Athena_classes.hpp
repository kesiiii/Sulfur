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

// BlueprintGeneratedClass B_Assault_Surgical_Thermal_Athena.B_Assault_Surgical_Thermal_Athena_C
// 0x0024 (0x0F6C - 0x0F48)
class AB_Assault_Surgical_Thermal_Athena_C : public AB_Assault_Generic_C
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0F48(0x0008) (Transient, DuplicateTransient)
	float                                              ScalePlayerThermal_NewTrack_0_53EEC0934805CD1ABD5237ADD42E83EE;// 0x0F50(0x0004) (ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETimelineDirection>                    ScalePlayerThermal__Direction_53EEC0934805CD1ABD5237ADD42E83EE;// 0x0F54(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0F55(0x0003) MISSED OFFSET
	class UTimelineComponent*                          ScalePlayerThermal;                                       // 0x0F58(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	struct FTimerHandle                                ScalePlayerVisibility;                                    // 0x0F60(0x0008) (Edit, BlueprintVisible, DisableEditOnInstance)
	float                                              BlendInTime;                                              // 0x0F68(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass B_Assault_Surgical_Thermal_Athena.B_Assault_Surgical_Thermal_Athena_C");
		return ptr;
	}


	void UserConstructionScript();
	void ScalePlayerThermal__FinishedFunc();
	void ScalePlayerThermal__UpdateFunc();
	void OnSetTargeting(bool* bNewIsTargeting);
	void PlayScopePP();
	void ReverseScopePP();
	void ExecuteUbergraph_B_Assault_Surgical_Thermal_Athena(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
