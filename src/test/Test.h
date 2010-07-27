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
