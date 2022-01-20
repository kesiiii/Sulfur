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

// AnimBlueprintGeneratedClass Fortnite_Base_Head_Export_Skeleton_AnimBP.Fortnite_Base_Head_Export_Skeleton_AnimBP_C
// 0x0BF8 (0x1018 - 0x0420)
class UFortnite_Base_Head_Export_Skeleton_AnimBP_C : public UCustomCharacterPartAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0420(0x0008) (Transient, DuplicateTransient)
	struct FAnimNode_PoseBlendNode                     AnimGraphNode_PoseBlendNode_0E491F3A4C933A03AAE42DA602295362;// 0x0428(0x00B0)
	struct FAnimNode_Root                              AnimGraphNode_Root_C9D648834AA29F5B677902BB5A9DC15C;      // 0x04D8(0x0040)
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_94E41D364E86D3FFC2D042845913D0EE;// 0x0518(0x00A0)
	struct FAnimNode_CopyPoseFromMesh                  AnimGraphNode_CopyPoseFromMesh_9AC0772D481A4B85CE045AA17CE0F79E;// 0x05B8(0x00E8)
	struct FAnimNode_LayeredBoneBlend                  AnimGraphNode_LayeredBoneBlend_B0BAEC37412A3BDE897683AA32FAE4E1;// 0x06A0(0x00D8)
	struct FAnimNode_TwoWayBlend                       AnimGraphNode_TwoWayBlend_3971854A46E6B529767EA2AB708A8D46;// 0x0778(0x00F8)
	struct FAnimNode_SaveCachedPose                    AnimGraphNode_SaveCachedPose_D687C7FB4A07645ECE24DBB182B71823;// 0x0870(0x00D8)
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_19E6568A48732F90AD2036B56ECA0D46;// 0x0948(0x0048)
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_C898D19D46B0E9723DD75AA4710C2707;// 0x0990(0x0048)
	struct FAnimNode_LiveLinkPose                      AnimGraphNode_LiveLinkPose_67AFEC6E4E43108E1E699081080B9448;// 0x09D8(0x0058)
	struct FAnimNode_LayeredBoneBlend                  AnimGraphNode_LayeredBoneBlend_E8FB05504628ECA52ADD038CBD818957;// 0x0A30(0x00D8)
	struct FAnimNode_SaveCachedPose                    AnimGraphNode_SaveCachedPose_91F05C994C7B4758BA35D2B1F94A7663;// 0x0B08(0x00D8)
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_53F166F14732C8ECBEC8C0A540192456;// 0x0BE0(0x0048)
	struct FAnimNode_TwoWayBlend                       AnimGraphNode_TwoWayBlend_BF175D4149F235AF8059B38CB3517406;// 0x0C28(0x00F8)
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_3D1C5A1541A1147D684D99B42EDBAB8C;// 0x0D20(0x0048)
	struct FAnimNode_Slot                              AnimGraphNode_Slot_59950130431F160E70FA618201DA0ED0;      // 0x0D68(0x0068)
	struct FAnimNode_LayeredBoneBlend                  AnimGraphNode_LayeredBoneBlend_4B2D173F4261FBC709962B837E22DAA7;// 0x0DD0(0x00D8)
	struct FAnimNode_SaveCachedPose                    AnimGraphNode_SaveCachedPose_C50053764A5016625E742C8401AAD202;// 0x0EA8(0x00D8)
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_540FAC8A423311B343A66CBDD1A68E4E;// 0x0F80(0x0048)
	struct FAnimNode_UseCachedPose                     AnimGraphNode_UseCachedPose_5C0CA1E44DCE78D6CEF568B89CA4B27B;// 0x0FC8(0x0048)
	class USkeletalMeshComponent*                      MeshToCopy;                                               // 0x1010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("AnimBlueprintGeneratedClass Fortnite_Base_Head_Export_Skeleton_AnimBP.Fortnite_Base_Head_Export_Skeleton_AnimBP_C");
		return ptr;
	}


	void BlueprintInitializeAnimation();
	void ExecuteUbergraph_Fortnite_Base_Head_Export_Skeleton_AnimBP(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
