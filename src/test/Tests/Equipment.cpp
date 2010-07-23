#include "Test.h"

void Test_Equipment_Initialize(CEquipment* equipment, CItemSaveState* itemSaveState)
{
  testLogger.WriteLine(Info,
    L"Equipment(%p)::Initialize( %p ) returns TODO",
    equipment, itemSaveState);

  testLogger.WriteLine(Verbose,
    L"  Name: %s",
    itemSaveState->name.getString());

  //log("Equipment Initialize: this = %p, ItemSaveState = %p", equipment, itemSaveState);
  //itemSaveState->dumpItemSaveState();
  //equipment->dumpEquipment();
}
