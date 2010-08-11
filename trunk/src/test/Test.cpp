#include "Test.h"
#include "TestUserInterface.h"

Test::Logger testLogger("testLog.txt");

//
// 
void TestSetup()
{
  testLogger.SetLoggingLevel(Info);
  testLogger.WriteLine(Info, L"TLAPI Test Initiated");

  testLogger.WriteLine(Info, L"Registering Events...");

  // Test the WndProc
  _GLOBAL::RegisterEvent_WndProc(NULL, Test_WndProc);

  // Test the Game CreateUI
  CGame::RegisterEvent_Game_CreateUI(NULL, Test_Game_CreateUI);

  // Test the EffectGroupManager
  //CEffectGroupManager::RegisterEvent_EffectGroupManager_CreateAffix(NULL, Test_EffectGroupManager_CreateAffix);

  // Test the EffectManager
  // This is continually creating events (non are properly setup either, bad function)
  //CEffectManager::RegisterEvent_EffectManagerCreateEffect(NULL, Test_EffectManagerCreateEffect);
  CEffectManager::RegisterEvent_EffectManager_AddEffectToEquipment(NULL, Test_EffectManager_AddEffectToEquipment);

  // MouseManager
  CMouseManager::RegisterEvent_MouseManagerInput(Test_MouseManagerHandleInput, NULL);

  // Test the GameClient
  CGameClient::RegisterEvent_GameClientLoadMap(NULL, Test_GameClientLoadMap);
  CGameClient::RegisterEvent_GameClientProcessObjects(NULL, Test_GameClientProcessObjects);
  CGameClient::RegisterEvent_GameClient_SaveGame(Test_GameClient_SaveGame, NULL);
  CGameClient::RegisterEvent_GameClient_SetupUI(NULL, Test_GameClient_SetupUI);
  CGameClient::RegisterEvent_GameClient_CreateLevel(NULL, Test_GameClient_CreateLevel);
  CGameClient::RegisterEvent_GameClient_LoadLevel(Test_GameClient_LoadLevel, NULL);

  // Test a Player Initialize
  CResourceManager::RegisterEvent_ResourceManagerInitializePlayer(NULL, Test_InitCharacter);
  CResourceManager::RegisterEvent_ResourceManagerCreatePlayer(NULL, Test_CreatePlayer);
  CResourceManager::RegisterEvent_ResourceManagerCreateBaseUnit(NULL, Test_CreateBaseUnit);
  CResourceManager::RegisterEvent_ResourceManagerCreateEquipment(NULL, Test_CreateEquipment);
  CResourceManager::RegisterEvent_ResourceManagerCreateMonster(NULL, Test_CreateMonster);

  // Test an Equipment Initialize
  CEquipment::RegisterEvent_EquipmentInitialize(NULL, Test_Equipment_Initialize);
  CEquipment::RegisterEvent_EquipmentEnchant(NULL, Test_Equipment_Enchant);
  CEquipment::RegisterEvent_Equipment_AddMagicModifier(NULL, Test_Equipment_AddMagicModifier);
  CEquipment::RegisterEvent_Equipment_AddAffix(NULL, Test_Equipment_AddAffix);
  

  // Test a ResourceCreateCharacter
  //CResourceManager::RegisterEvent_ResouceManagerCreateCharacter(NULL, TestCallbackPost_CreateCharacter);


  // Level
  CLevel::RegisterEvent_LevelCharacterInitialize(NULL, Test_LevelCharacterInitialize);
  CLevel::RegisterEvent_LevelCreateAstarPathfinding(NULL, Test_LevelCreateAstarPathfinding);
  CLevel::RegisterEvent_LevelDropEquipment(NULL, Test_LevelDropEquipment);

  // Character
  CCharacter::RegisterEvent_CharacterSetAlignment(NULL, Test_CharacterSetAlignment);
  // Buggy
  //CCharacter::RegisterEvent_CharacterSetDestination(NULL, Test_CharacterSetDestination);
  CCharacter::RegisterEvent_CharacterSetAction(NULL, Test_CharacterSetAction);
  CCharacter::RegisterEvent_CharacterAddMinion(NULL, Test_CharacterAddMinion);
  CCharacter::RegisterEvent_CharacterStrike(NULL, Test_CharacterStrike);

  // Player
  CPlayer::RegisterEvent_PlayerUseSkill(NULL, Test_PlayerUseSkill);

  // GenericModel
  CGenericModel::RegisterEvent_GenericModelGetPosition(NULL, Test_GenericModelGetPosition);

  // Layout
  CLayout::RegisterEvent_LayoutSetPosition(NULL, Test_LayoutSetPosition);

  testLogger.WriteLine(Info, L"Registering Events... Done");
}
