#include "Test.h"

void TestCallbackPost_GameClientLoadMap(PVOID retVal, CGameClient *client, u32 unk0)
{
  log("retVal = %x", retVal);
  log("GameClient has loaded the map (%p, %i)", client, unk0);

  client->pCPlayer->dumpEditorBase();
  //client->pCPlayer->pCInventory->dumpInventory();
}
