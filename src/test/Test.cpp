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

  // Test an Equipment Initialize
  CEquipment::RegisterEvent_EquipmentInitialize(NULL, Test_Equipment_Initialize);

  // Test a ResourceCreateCharacter
  //CResourceManager::RegisterEvent_ResouceManagerCreateCharacter(NULL, TestCallbackPost_CreateCharacter);

  // Level
  CLevel::RegisterEvent_LevelCharacterInitialize(NULL, Test_LevelCharacterInitialize);

  // Character
  CCharacter::RegisterEvent_CharacterSetAlignment(NULL, Test_CharacterSetAlignment);
  CCharacter::RegisterEvent_CharacterSetDestination(NULL, Test_CharacterSetDestination);

  testLogger.WriteLine(Info, L"Registering Events... Done");
}
