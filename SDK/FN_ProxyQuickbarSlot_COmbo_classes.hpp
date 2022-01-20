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

// WidgetBlueprintGeneratedClass ProxyQuickbarSlot_COmbo.ProxyQuickbarSlot_Combo_C
// 0x0098 (0x03E8 - 0x0350)
class UProxyQuickbarSlot_Combo_C : public UHUDLayoutToolProxy
{
public:
	struct FPointerToUberGraphFrame                    UberGraphFrame;                                           // 0x0350(0x0008) (Transient, DuplicateTransient)
	class UImage*                                      Image_0_1;                                                // 0x0358(0x0008) (BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
	class UFortNumericTextBlock*                       IndexBox;                                                 // 0x0360(0x0008) (BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, RepNotify, Interp, NonTransactional, EditorOnly, NoDestructor, AutoWeak, ContainsInstancedReference, AssetRegistrySearchable, SimpleDisplay, AdvancedDisplay, Protected, BlueprintCallable, BlueprintAuthorityOnly, TextExportTransient, NonPIEDuplicateTransient, ExposeOnSpawn, PersistentInstance, UObjectWrapper, HasGetValueTypeHash, NativeAccessSpecifierPublic, NativeAccessSpecifierProtected, NativeAccessSpecifierPrivate)
	EComboSlotType                                     SlotType;                                                 // 0x0368(0x0001) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0369(0x0003) MISSED OFFSET
	int                                                Index;                                                    // 0x036C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData)
	struct FSlateColor                                 Combat_Color;                                             // 0x0370(0x0028) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FSlateColor                                 Build_Color;                                              // 0x0398(0x0028) (Edit, BlueprintVisible, DisableEditOnInstance)
	struct FSlateColor                                 Combo_Color;                                              // 0x03C0(0x0028) (Edit, BlueprintVisible, DisableEditOnInstance)

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("WidgetBlueprintGeneratedClass ProxyQuickbarSlot_COmbo.ProxyQuickbarSlot_Combo_C");
		return ptr;
	}


	float BP_GetPropertyValue(int* PropertyIndex);
	void SetSlotIndex(int NewIndex);
	void SetSlotType(unsigned char Value);
	TArray<struct FText> BP_GetMultiOptionLabels(int* PropertyIndex);
	struct FText BP_GetPropertyName(int* PropertyIndex);
	int BP_GetNumOfProperties();
	void BP_GetPropertyRange(int* PropertyIndex, float* OutMin, float* OutMax);
	ELayoutPropertyType BP_GetPropertyType(int* PropertyIndex);
	void BP_SetPropertyValue(int* PropertyIndex, float* NewValue);
	void ExecuteUbergraph_ProxyQuickbarSlot_Combo(int EntryPoint);
};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
