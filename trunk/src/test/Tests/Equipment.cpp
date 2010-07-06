#include "Test.h"

void TestCallbackPost_Equipment_Initialize(CEquipment* equipment, CItemSaveState* itemSaveState)
{
  log("Equipment Initialize: this = %p, ItemSaveState = %p", equipment, itemSaveState);
  itemSaveState->dumpItemSaveState();
}
