#include <Windows.h>
#include "Struct.h"
#include "Util.h"
#include <iostream>
#include "UE4.h"
#include "Hooks.h"

DWORD WINAPI MainThread(LPVOID)
{
    Util::SetupConsole();

    auto pGObjects = Util::FindPattern("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8D 04 D1 EB 03 48 8B ? 81 48 08 ? ? ? 40 49", true, 3);
    auto pFNameToString = Util::FindPattern("48 89 5C 24 ? 57 48 83 EC 30 83 79 04 00 48 8B DA 48 8B F9");
    auto pFreeInternal = Util::FindPattern("48 85 C9 74 2E 53 48 83 EC 20 48 8B D9");
    auto pGetFirstPlayerController = Util::FindPattern("83 B9 ? ? ? ? ? 7E ? 48 8B 89 ? ? ? ? E9");
    auto pSpawnActor = Util::FindPattern("40 53 56 57 48 83 EC 70 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? 0F 28 1D ? ? ? ? 0F 57 D2 48 8B B4 24 ? ? ? ? 0F 28 CB");

    if (!pGObjects)
    {
        MessageBoxA(NULL, "Failed to find GObjects address", "UraniumMP", MB_ICONERROR);
        return 0;
    }

    if (!pFNameToString)
    {
        MessageBoxA(NULL, "Failed to find FNameToString address", "UraniumMP", MB_ICONERROR);
        return 0;
    }

    if (!pFreeInternal)
    {
        MessageBoxA(NULL, "Failed to find FreeInternal address", "UraniumMP", MB_ICONERROR);
        return 0;
    }

    if (!pGetFirstPlayerController)
    {
        MessageBoxA(NULL, "Failed to find GetFirstPlayerController address", "UraniumMP", MB_ICONERROR);
        return 0;
    }

    if (!pSpawnActor)
    {
        MessageBoxA(NULL, "Failed to find SpawnActor address", "UraniumMP", MB_ICONERROR);
        return 0;
    }

    UObject::GObjects = decltype(UObject::GObjects)(pGObjects);
    FNameToString = decltype(FNameToString)(pFNameToString);
    FreeInternal = decltype(FreeInternal)(pFreeInternal);
    SpawnActor = decltype(SpawnActor)(pSpawnActor);
    GetFirstPlayerController = decltype(GetFirstPlayerController)(pGetFirstPlayerController);

    Globals::LocalPlayerController = GetFirstPlayerController(GetWorld());

    return 0;
}

BOOL APIENTRY DllMain(HMODULE mod, DWORD reason, LPVOID res)
{
    if (reason == DLL_PROCESS_ATTACH)
        CreateThread(0, 0, MainThread, mod, 0, 0);

    return TRUE;
}