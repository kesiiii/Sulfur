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

// AnimBlueprintGeneratedClass Reaper_GliderChute_AnimBP.Reaper_GliderChute_AnimBP_C
// 0x09D4 (0x0D34 - 0x0360)
class UReaper_GliderChute_AnimBP_C : public UAnimInstance
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0360(0x0008) (Transient, DuplicateTransient)
	struct FAnimNode_Root                              AnimGraphNode_Root_5A54842C408A8050100891AB4058C8A7;      // 0x0368(0x0048)
	struct FAnimNode_Slot                              AnimGraphNode_Slot_20D39D7944CAC167C18F5789F7C0AE7B;      // 0x03B0(0x0070)
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_A7104FFA48E926160BE03DA88FF45BE4;// 0x0420(0x0080)
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_DA64D86640F381D54CDEA8BAF301A576;// 0x04A0(0x0080)
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_BA0E544049ED8F65C9C2CEA2EDD69609;// 0x0520(0x0080)
	struct FAnimNode_TransitionResult                  AnimGraphNode_TransitionResult_662E8E6C45285723236371918314AAD4;// 0x05A0(0x0080)
	struct FAnimNode_SequencePlayer                    AnimGraphNode_SequencePlayer_04CC95284A110C598F3C67BDCD6CC50B;// 0x0620(0x00B0)
	struct FAnimNode_Root                              AnimGraphNode_StateResult_F474D4544C209E11499B409F08B33765;// 0x06D0(0x0048)
	struct FAnimNode_BlendSpacePlayer                  AnimGraphNode_BlendSpacePlayer_2D4C5ACE49343C8AF6D3DEA4F137822F;// 0x0718(0x0128)
	struct FAnimNode_Root                              AnimGraphNode_StateResult_E7DC43FB4F5DE4E559B3ADBF27269D5C;// 0x0840(0x0048)
	struct FAnimNode_BlendSpacePlayer                  AnimGraphNode_BlendSpacePlayer_F917F9D5454B41D2C1384D922EE22F1B;// 0x0888(0x0128)
	struct FAnimNode_Root                              AnimGraphNode_StateResult_57252E8F4B03ABB40F4F82BDCFC8E239;// 0x09B0(0x0048)
	struct FAnimNode_StateMachine                      AnimGraphNode_StateMachine_8AEB2C074A7DD9593AE7AA884E2EE980;// 0x09F8(0x00E0)
	struct FAnimNode_BlendSpacePlayer                  AnimGraphNode_BlendSpacePlayer_D64B97FB4C7A78E8F47D6C8124F85A8A;// 0x0AD8(0x0128)
	struct FAnimNode_ApplyAdditive                     AnimGraphNode_ApplyAdditive_02247F954A8CD3E7D1F22CB0CAE94F23;// 0x0C00(0x0118)
	bool                                               IsParachuteOpen;                                          // 0x0D18(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0D19(0x0003) MISSED OFFSET
	float                                              AimPitch;                                                 // 0x0D1C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              DeployAnimRate;                                           // 0x0D20(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              SkydiveYaw;                                               // 0x0D24(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              UseDynamicsAlpha;                                         // 0x0D28(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Forward;                                                  // 0x0D2C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	float                                              Right;                                                    // 0x0D30(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("AnimBlueprintGeneratedClass Reaper_GliderChute_AnimBP.Reaper_GliderChute_AnimBP_C");
		return ptr;
	}


	void EvaluateGraphExposedInputs_ExecuteUbergraph_Reaper_GliderChute_AnimBP_AnimGraphNode_TransitionResult_662E8E6C45285723236371918314AAD4();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_Reaper_GliderChute_AnimBP_AnimGraphNode_BlendSpacePlayer_2D4C5ACE49343C8AF6D3DEA4F137822F();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_Reaper_GliderChute_AnimBP_AnimGraphNode_TransitionResult_DA64D86640F381D54CDEA8BAF301A576();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_Reaper_GliderChute_AnimBP_AnimGraphNode_BlendSpacePlayer_F917F9D5454B41D2C1384D922EE22F1B();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_Reaper_GliderChute_AnimBP_AnimGraphNode_BlendSpacePlayer_D64B97FB4C7A78E8F47D6C8124F85A8A();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_Reaper_GliderChute_AnimBP_AnimGraphNode_TransitionResult_A7104FFA48E926160BE03DA88FF45BE4();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_Reaper_GliderChute_AnimBP_AnimGraphNode_TransitionResult_BA0E544049ED8F65C9C2CEA2EDD69609();
	void BlueprintUpdateAnimation(float* DeltaTimeX);
	void AnimNotify_TurnONEngines();
	void ExecuteUbergraph_Reaper_GliderChute_AnimBP(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
