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

// WidgetBlueprintGeneratedClass AthenaSquadList.AthenaSquadList_C
// 0x0038 (0x0270 - 0x0238)
class UAthenaSquadList_C : public UFortHUDElementWidget
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0238(0x0008) (Transient, DuplicateTransient)
	class UVerticalBox*                                VerticalBoxSquadMembers;                                  // 0x0240(0x0008) (BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
	TArray<class UAthenaTeamMemberInfo_C*>             SquadMembers;                                             // 0x0248(0x0010) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance)
	bool                                               bAddFriendOptionsDisplayed;                               // 0x0258(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x7];                                       // 0x0259(0x0007) MISSED OFFSET
	class USoundBase*                                  Sound_SquadMemberDisconnected;                            // 0x0260(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	class USoundBase*                                  Sound_LastSquadMemberDisconnected;                        // 0x0268(0x0008) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("WidgetBlueprintGeneratedClass AthenaSquadList.AthenaSquadList_C");
		return ptr;
	}


	void HandleSquadMemberDisconnected(class AFortPlayerStateAthena* Player);
	void ClearSquadMembers();
	void RebuildSquadMembersList();
	void AppendSquadMember(class AFortPlayerStateAthena* PlayerState, int PlayerIndex);
	void Construct();
	void PreConstruct(bool* IsDesignTime);
	void ExecuteUbergraph_AthenaSquadList(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
