#include "Test.h"

// Testing
void TestCallbackPost_LoadMap(CGameClient *client, u32 unk0)
{
  log("GameClient has loaded the map (%p, %i)", client, unk0);

  client->pCPlayer->dumpEditorBase();
  //client->pCPlayer->pCInventory->dumpInventory();
}



void TestSetup()
{
  // Just testing
  CGameClient gameClient;
  gameClient.RegisterEvent_LoadMap(NULL, TestCallbackPost_LoadMap);
}
