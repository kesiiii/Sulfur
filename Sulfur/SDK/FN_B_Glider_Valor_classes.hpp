#pragma once

// Fortnite (4.1) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// BlueprintGeneratedClass B_Glider_Valor.B_Glider_Valor_C
// 0x001F (0x0388 - 0x0369)
class AB_Glider_Valor_C : public AB_EmptyBaseGlider_C
{
public:
	unsigned char                                      UnknownData00[0x7];                                       // 0x0369(0x0007) MISSED OFFSET
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0370(0x0008) (Transient, DuplicateTransient)
	class UFortVehicleAudioVoice*                      FortVehicleAudioVoice;                                    // 0x0378(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UParticleSystemComponent*                    TrailParticles_2_3;                                       // 0x0380(0x0008) (BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass B_Glider_Valor.B_Glider_Valor_C");
		return ptr;
	}


	void UserConstructionScript();
	void OnParachuteTrailUpdated(float* MovementLengthSquared, float* ForwardDot, float* RightDot, float* RotationalMovementAcceleration);
	void ResetDoOnce();
	void ExecuteUbergraph_B_Glider_Valor(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
