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

// BlueprintGeneratedClass Trap_Athena_WallSpikes.Trap_Athena_WallSpikes_C
// 0x0008 (0x0E00 - 0x0DF8)
class ATrap_Athena_WallSpikes_C : public ATrap_Athena_Spikes_C
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0DF8(0x0008) (Transient, DuplicateTransient)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass Trap_Athena_WallSpikes.Trap_Athena_WallSpikes_C");
		return ptr;
	}


	void UserConstructionScript();
	void SetSpikePosition(float* NewSpikePosition);
	void ExecuteUbergraph_Trap_Athena_WallSpikes(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
