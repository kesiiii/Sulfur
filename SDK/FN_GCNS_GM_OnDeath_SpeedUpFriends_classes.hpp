#pragma once

// Fortnite (3.1) SDK

#ifdef _MSC_VER
	#pragma pack(push, 0x8)
#endif

#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// BlueprintGeneratedClass GCNS_GM_OnDeath_SpeedUpFriends.GCNS_GM_OnDeath_SpeedUpFriends_C
// 0x0000 (0x00B0 - 0x00B0)
class UGCNS_GM_OnDeath_SpeedUpFriends_C : public UFortGameplayCueNotify_Simple
{
public:

	static UClass* StaticClass()
	{
		static auto ptr = UObject::FindClass("BlueprintGeneratedClass GCNS_GM_OnDeath_SpeedUpFriends.GCNS_GM_OnDeath_SpeedUpFriends_C");
		return ptr;
	}

};


}

#ifdef _MSC_VER
	#pragma pack(pop)
#endif
