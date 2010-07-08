#include "Test.h"

Test::Logger testLogger("testLog.txt");

//
// 
void TestSetup()
{
  testLogger.SetLoggingLevel(Info);
  testLogger.WriteLine(Info, L"TLAPI Test Initiated");

  testLogger.WriteLine(Info, L"Registering Events...");

  // Test the GameClient
  CGameClient::RegisterEvent_GameClientLoadMap(NULL, Test_GameClientLoadMap);

  // Test a Player Initialize
  CResourceManager::RegisterEvent_ResourceManagerInitializePlayer(NULL, Test_InitCharacter);
  CResourceManager::RegisterEvent_ResourceManagerCreateSomething(NULL, Test_CreateSomething);

  // Test an Equipment Initialize
  CEquipment::RegisterEvent_EquipmentInitialize(NULL, Test_Equipment_Initialize);

  // Test a ResourceCreateCharacter
  //CResourceManager::RegisterEvent_ResouceManagerCreateCharacter(NULL, TestCallbackPost_CreateCharacter);

  // Level
  CLevel::RegisterEvent_LevelCharacterInitialize(NULL, Test_LevelCharacterInitialize);
  CLevel::RegisterEvent_LevelCreateAstarPathfinding(NULL, Test_LevelCreateAstarPathfinding);

  // Character
  CCharacter::RegisterEvent_CharacterSetAlignment(NULL, Test_CharacterSetAlignment);
  CCharacter::RegisterEvent_CharacterSetDestination(NULL, Test_CharacterSetDestination);
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
