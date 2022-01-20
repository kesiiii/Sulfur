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

// AnimBlueprintGeneratedClass SK_F_LRG_Constructor_01_Skeleton_AnimBP.SK_F_LRG_Constructor_01_Skeleton_AnimBP_C
// 0x339C (0x37BC - 0x0420)
class USK_F_LRG_Constructor_01_Skeleton_AnimBP_C : public UCustomCharacterPartAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0420(0x0008) (Transient, DuplicateTransient)
	struct FAnimNode_Root                              AnimGraphNode_Root_BBB13A1043E829C1CC58D9A49D49F566;      // 0x0428(0x0040)
	struct FAnimNode_CopyPoseFromMesh                  AnimGraphNode_CopyPoseFromMesh_A0A7862C41D58A2D7BA59DB29DC489F6;// 0x0468(0x00E8)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_A14060684EA36E6A38C64C9CC3B1D9AB;// 0x0550(0x0390)
	struct FAnimNode_ConvertLocalToComponentSpace      AnimGraphNode_LocalToComponentSpace_DAA1FFE44162B99482DFA5B4159C7405;// 0x08E0(0x0040)
	struct FAnimNode_ConvertComponentToLocalSpace      AnimGraphNode_ComponentToLocalSpace_ECD817444DCDA9467A6F8BBBF6A2EFA0;// 0x0920(0x0040)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_CB3D6B164B59E44D18B490B3841357B8;// 0x0960(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_F74199DA4EA69D7DDF67BCADDD574900;// 0x0CF0(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_DA9E260A4D1351ED0E17E58B79953B20;// 0x1080(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_EAC240C941C5FF15BA213E8AAE7D17F3;// 0x1410(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_CF18CD1F453F70B994906BAD08D8FE6B;// 0x17A0(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_CD1FE29D46CD2DE2B656CC945C67F8FE;// 0x1B30(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_92E1B7D74567C03375E012B851D8CD81;// 0x1EC0(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_DBA4FC8449C310563A81A095EE9AC303;// 0x2250(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_4858A3D249AA3874A2388D912273B290;// 0x25E0(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_42944FB54D814E3C274720A692DF63CA;// 0x2970(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_31F5F26747E828356CE78D849F177EEB;// 0x2D00(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_6057D72E42852A339E4F66840D894B6D;// 0x3090(0x0390)
	struct FAnimNode_AnimDynamics                      AnimGraphNode_AnimDynamics_B6385FE84A87BF3442422786D1AB2689;// 0x3420(0x0390)
	class USkeletalMeshComponent*                      MeshToCopy;                                               // 0x37B0(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData)
	float                                              HammerDynamicsOK;                                         // 0x37B8(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("AnimBlueprintGeneratedClass SK_F_LRG_Constructor_01_Skeleton_AnimBP.SK_F_LRG_Constructor_01_Skeleton_AnimBP_C");
		return ptr;
	}


	void EvaluateGraphExposedInputs_ExecuteUbergraph_SK_F_LRG_Constructor_01_Skeleton_AnimBP_AnimGraphNode_CopyPoseFromMesh_A0A7862C41D58A2D7BA59DB29DC489F6();
	void BlueprintInitializeAnimation();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_SK_F_LRG_Constructor_01_Skeleton_AnimBP_AnimGraphNode_AnimDynamics_A14060684EA36E6A38C64C9CC3B1D9AB();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_SK_F_LRG_Constructor_01_Skeleton_AnimBP_AnimGraphNode_AnimDynamics_B6385FE84A87BF3442422786D1AB2689();
	void BlueprintUpdateAnimation(float* DeltaTimeX);
	void ExecuteUbergraph_SK_F_LRG_Constructor_01_Skeleton_AnimBP(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
