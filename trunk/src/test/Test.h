#pragma once

#include "Events.h"
#include "Common.h"

#include "CPlayer.h"

using namespace TLAPI;

// Testing
void TestCallbackPost_PlayerInit(CResourceManager* resourceMgr, u32 unk0, u32 unk1);
void TestCallbackPost_Equipment_Initialize(CEquipment*, CItemSaveState*);

void TestCallbackPost_GameClientLoadMap(PVOID retVal, CGameClient *client, u32 unk0);

void TestCallbackPost_CreateCharacter(CCharacter*, CResourceManager*, u64, u32, bool);
void TestCallbackPost_CreateCharacterByName(CCharacter*, CResourceManager*, const wchar_t*, const wchar_t*, u32, u32);

void TestCallbackPost_LevelCharacterInitialize(CCharacter* retVal, CLevel* level, CCharacter* character, Vector3* position, u32);

void TestCallbackPost_CharacterSetAlignment(CCharacter*, u32);
void TestCallbackPost_CharacterSetDestination(CCharacter*, CLevel*, float, float);


void TestSetup();
