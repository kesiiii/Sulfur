#include <Windows.h>
#include "Util.h"
#include "Hooks.h"
#include "SDK.hpp"

DWORD WINAPI MainThread(LPVOID)
{
    Util::InitConsole();

    printf("LogUGS: Setting Up!\n");

    auto BaseAddr = Util::BaseAddress();
    auto GObjectsAddress = Util::FindPattern("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1 EB 03 48 8B ? 81 48 08 ? ? ? 40 49", true, 0x3);
    auto FNameToStringAddress = Util::FindPattern("48 89 5C 24 ? 57 48 83 EC 30 83 79 04 00 48 8B DA 48 8B F9");
    auto FreeMemoryAddress = Util::FindPattern("48 85 C9 74 2E 53 48 83 EC 20 48 8B D9");



    SDK::UObject::GObjects = decltype(SDK::UObject::GObjects)(GObjectsAddress);
    SDK::FNameToString = decltype(SDK::FNameToString)(FNameToStringAddress);
    SDK::FreeMemory = decltype(SDK::FreeMemory)(FreeMemoryAddress);

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