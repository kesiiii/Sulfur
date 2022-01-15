#include <Windows.h>
#include "Util.h"
#include "Hooks.h"
#include "SDK.hpp"

DWORD WINAPI MainThread(LPVOID)
{
    Util::InitConsole();

    printf("LogUGS: Setting Up!\n");

    auto BaseAddr = Util::BaseAddress();
    auto GObjectsAddress = BaseAddr + 0x44E5CE0;
    auto FNameToStringAddress = BaseAddr + 0xC79B10;
    auto FreeMemoryAddress = BaseAddr + 0xBBCEB0;

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