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

// AnimBlueprintGeneratedClass BP_BoltActionSniperRifleNoScope.BP_BoltActionSniperRifleNoScope_C
// 0x0150 (0x04B0 - 0x0360)
class UBP_BoltActionSniperRifleNoScope_C : public UAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0360(0x0008) (Transient, DuplicateTransient)
	struct FAnimNode_Root                              AnimGraphNode_Root_80F88762449D5790C18126A73190A30A;      // 0x0368(0x0040)
	struct FAnimNode_Slot                              AnimGraphNode_Slot_3F9AE2D64A1081980E00CE94E79DD708;      // 0x03A8(0x0068)
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_F813E2B842B7262277782F9EC5A3917A;// 0x0410(0x00A0)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("AnimBlueprintGeneratedClass BP_BoltActionSniperRifleNoScope.BP_BoltActionSniperRifleNoScope_C");
		return ptr;
	}


	void ExecuteUbergraph_BP_BoltActionSniperRifleNoScope(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
