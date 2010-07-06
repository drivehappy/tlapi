#pragma once

#include "Events.h"
#include "Common.h"

#include "CPlayer.h"

#include "Logger.h"


using namespace TLAPI;
using namespace Test;


extern Logger testLogger;


// Testing
// ResourceManager
void Test_CreateCharacter(CCharacter*, CResourceManager*, u64, u32, bool);
void Test_CreateCharacterByName(CCharacter*, CResourceManager*, const wchar_t*, const wchar_t*, u32, u32);
void Test_InitCharacter(CResourceManager* resourceMgr, u32 unk0, u32 unk1);

// Equipment
void Test_Equipment_Initialize(CEquipment*, CItemSaveState*);

// GameClient
void Test_GameClientLoadMap(PVOID retVal, CGameClient *client, u32 unk0);

// Level
void Test_LevelCharacterInitialize(CCharacter* retVal, CLevel* level, CCharacter* character, Vector3* position, u32);

// Character
void Test_CharacterSetAlignment(CCharacter*, u32);
void Test_CharacterSetDestination(CCharacter*, CLevel*, float, float);


void TestSetup();
