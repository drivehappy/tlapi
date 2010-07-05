#include "Test.h"

// Testing
void TestCallbackPost_GameClientLoadMap(CGameClient *client, u32 unk0)
{
  log("GameClient has loaded the map (%p, %i)", client, unk0);

  client->pCPlayer->dumpEditorBase();
  //client->pCPlayer->pCInventory->dumpInventory();
}

void TestCallbackPost_PlayerInit(CResourceManager* resourceMgr, u32 unk0, u32 unk1)
{
  log("ResourceManager = %p   unk0: %x, unk1: %x", resourceMgr, unk0, unk1);
}

void TestCallbackPost_Equipment_Initialize(CEquipment* equipment, CItemSaveState* itemSaveState)
{
  log("Equipment Initialize: this = %p, ItemSaveState = %p", equipment, itemSaveState);
  itemSaveState->dumpItemSaveState();
}

void TestCallbackPost_CreateCharacter(CResourceManager* resourceManager, u64 guid, u32 unk0, bool unk1)
{
  log("ResourceManager (%p) CreateCharacter: %016I64X, %x, %i", resourceManager, guid, unk0, unk1);
}

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
}
