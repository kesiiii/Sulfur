#pragma once

#include "Struct.h"

namespace Hooks
{
	bool bIsReady = false;
	bool bIsInGame = false;
	bool bHasSpawned = false;

	void* ProcessEventDetour(UObject* pObject, UObject* pFunction, void* pParams)
	{
	}
}