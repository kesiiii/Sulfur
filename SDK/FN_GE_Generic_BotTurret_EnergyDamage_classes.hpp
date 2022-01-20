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

// BlueprintGeneratedClass GE_Generic_BotTurret_EnergyDamage.GE_Generic_BotTurret_EnergyDamage_C
// 0x0000 (0x0638 - 0x0638)
class UGE_Generic_BotTurret_EnergyDamage_C : public UGET_DirectEnergyDamage_C
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GE_Generic_BotTurret_EnergyDamage.GE_Generic_BotTurret_EnergyDamage_C");
		return ptr;
	}

};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
