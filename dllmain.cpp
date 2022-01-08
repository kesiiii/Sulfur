#include <Windows.h>
#include "Util.h"
#include "Hooks.h"
#include "SDK.hpp"

DWORD WINAPI MainThread(LPVOID)
{
    Util::InitConsole();

    printf("LogUGS: Setting Up!\n");

    auto BaseAddr = Util::BaseAddress();
    auto GObjectsAddress = Util::FindPattern("48 8B 05 ? ? ? ? 48 8D 1C C8 81 4B ? ? ? ? ? 49 63 76 30", true, 3);
    auto FNameToStringAddress = Util::FindPattern("48 89 5C 24 ? 57 48 83 EC 40 83 79 04 00 48 8B DA 48 8B F9");
    auto FreeMemoryAddress = Util::FindPattern("48 85 C9 74 1D 4C 8B 05 ? ? ? ? 4D 85 C0");

    SDK::UObject::GObjects = decltype(SDK::UObject::GObjects)(GObjectsAddress);
    SDK::FNameToString = decltype(SDK::FNameToString)(FNameToStringAddress);
    SDK::FreeInternal = decltype(SDK::FreeInternal)(FreeMemoryAddress);

    auto FortEngine = SDK::UObject::FindObject<UFortEngine>("FortEngine_");
    Hooks::World = FortEngine->GameViewport->World;
    auto GPS = reinterpret_cast<UGameplayStatics*>(UGameplayStatics::StaticClass());

    auto NewConsole = GPS->STATIC_SpawnObject(UFortConsole::StaticClass(), FortEngine->GameViewport);
    FortEngine->GameViewport->ViewportConsole = (UFortConsole*)(NewConsole);

    auto NewCheatManager = GPS->STATIC_SpawnObject(UCheatManager::StaticClass(), FortEngine->GameInstance->LocalPlayers[0]->PlayerController);
    FortEngine->GameInstance->LocalPlayers[0]->PlayerController->CheatManager = (UCheatManager*)(NewCheatManager);

    Hooks::Init();

    printf("LogUGS: Hooks Setup!\n");

    return 0;
}

BOOL APIENTRY DllMain(HMODULE mod, DWORD reason, LPVOID res)
{
    if (reason == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, MainThread, mod, 0, 0);

    return TRUE;
}