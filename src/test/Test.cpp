#include "Test.h"

//
// 
void TestSetup()
{
  // Test the GameClient
  CGameClient::RegisterEvent_GameClientLoadMap(NULL, TestCallbackPost_GameClientLoadMap);

  // Test a Player Initialize
  CResourceManager::RegisterEvent_ResourceManagerInitializePlayer(NULL, TestCallbackPost_PlayerInit);

  // Test an Equipment Initialize
  CEquipment::RegisterEvent_EquipmentInitialize(NULL, TestCallbackPost_Equipment_Initialize);

  // Test a ResourceCreateCharacter
  //CResourceManager::RegisterEvent_ResouceManagerCreateCharacter(NULL, TestCallbackPost_CreateCharacter);

  // Level
  CLevel::RegisterEvent_LevelCharacterInitialize(NULL, TestCallbackPost_LevelCharacterInitialize);

  // Character
  CCharacter::RegisterEvent_CharacterSetAlignment(NULL, TestCallbackPost_CharacterSetAlignment);
  CCharacter::RegisterEvent_CharacterSetDestination(NULL, TestCallbackPost_CharacterSetDestination);
}
