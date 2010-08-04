#pragma once

//#include "TestUserInterface.h"

#include "Events.h"
#include "Common.h"

#include "CPlayer.h"
#include "Globals.h"

#include "Logger.h"


using namespace TLAPI;
using namespace Test;


extern Logger            testLogger;
extern CGameClient      *gameClient;
extern CResourceManager *resManager;
extern bool              suppressInGameMouse;

// Testing

// Globals
void Test_WndProc(HWND, UINT, WPARAM, LPARAM);

// Game
void Test_Game_CreateUI(CGame*);

// EffectGroupManager
void Test_EffectGroupManager_CreateAffix(CEffectGroupManager* effectGroupManager, u32 unk0, u32 unk1, u32 unk2, CList<CAffix*> *listAffixes);

// EffectManager
void Test_EffectManagerCreateEffect(CEffect* retVal, CEffectManager* effectManager);
void Test_EffectManager_AddEffectToEquipment(CEffectManager* effectManager, CEquipment* equipment, CEffect* effect);

// MouseManager
void Test_MouseManagerHandleInput(CMouseManager*, u32 wParam, u32 mouseButton, bool* callOriginal);

// ResourceManager
void Test_CreateCharacter(CCharacter*, CResourceManager*, u64, u32, bool);
void Test_CreateCharacterByName(CCharacter*, CResourceManager*, const wchar_t*, const wchar_t*, u32, u32);
void Test_InitCharacter(CResourceManager* resourceMgr, u32 unk0, u32 unk1);
void Test_CreateSomething(PVOID retVal, CResourceManager*, u64, u32, u32, u32);
void Test_CreateEquipment(CEquipment* retval, CResourceManager* resManager, u64 guid, u32 unk0, u32 unk1, u32 unk2);

// Equipment
void Test_Equipment_Initialize(CEquipment*, CItemSaveState*);
void Test_Equipment_Enchant(u32 retVal, CEquipment* equipment, u32 unk0, u32 unk1, u32 unk2);
void Test_Equipment_AddMagicModifier(CEquipment* equipment, u32 unk0, u32 unk1);
void Test_Equipment_AddAffix(CEquipment* equipment, CAffix* affix, u32 unk0, CEquipment* equipment2, float unk1);

// GameClient
void Test_GameClientLoadMap(PVOID retVal, CGameClient *client, u32 unk0);
void Test_GameClientProcessObjects(CGameClient*, PVOID, PVOID, PVOID);
void Test_GameClient_SaveGame(CGameClient *client, u32 unk0, u32 unk1, bool & callOriginal);
void Test_GameClient_SetupUI(CGameClient *client, u32 unk0, u32 unk1);
void Test_GameClient_CreateLevel(CGameClient *client, u32 unk0, u32 unk1, u32 unk2, CGameClient *client2, u32 unk4, u32 unk5,
  u32 unk6, u32 unk7, u32 unk8, u32 unk9, u32 unk10, u32 unk11,u32 unk12, u32 unk13, u32 unk14, u32 unk15, u32 unk16,
  u32 unk17,u32 unk18, u32 unk19, u32 unk20, u32 unk21, u32 unk22, u32 unk23);
void Test_GameClient_LoadLevel(CGameClient *client);

// Level
void Test_LevelCharacterInitialize(CCharacter* retVal, CLevel* level, CCharacter* character, Vector3* position, u32);
void Test_LevelCreateAstarPathfinding(CAstarPathfinder*, float, float, u32, u32, PVOID, PVOID, float);
void Test_LevelDropEquipment(CLevel*, CEquipment*, Vector3 &, bool);

// Character
void Test_CharacterSetAlignment(CCharacter*, u32);
void Test_CharacterSetDestination(CCharacter*, CLevel*, float, float);
void Test_CharacterSetAction(CCharacter* character, u32 action);
void Test_CharacterAddMinion(CCharacter* character, CCharacter* minion);
void Test_CharacterStrike(CCharacter*, CLevel*, CCharacter*, PVOID, u32, float, float, u32);

// Player
void Test_PlayerUseSkill(u32 retVal, CPlayer*, u64);

// GenericModel
void Test_GenericModelGetPosition(CGenericModel* genericModel, Vector3 position, u32 unk);

// Layout
void Test_LayoutSetPosition(CLayout* layout, const Vector3 position);

//
void TestSetup();
