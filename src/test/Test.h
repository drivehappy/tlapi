#pragma once

#include "Events.h"
#include "Common.h"

#include "CPlayer.h"

using namespace TLAPI;

// Testing
void TestCallbackPost_GameClientLoadMap(CGameClient *client, u32 unk0);
void TestCallbackPost_PlayerInit(CResourceManager* resourceMgr, u32 unk0, u32 unk1);
void TestCallbackPost_Equipment_Initialize(CEquipment*, CItemSaveState*);
void TestCallbackPost_CreateCharacter(CResourceManager*, u64, u32, bool);

void TestSetup();
