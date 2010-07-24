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

void Test_Equipment_Enchant(u32 retVal, CEquipment* equipment, u32 unk0, u32 unk1, u32 unk2)
{
  testLogger.WriteLine(Info,
    L"Equipment(%p)::Enchant( %x, %x, %x ) returns %i",
    equipment, unk0, unk1, unk2, retVal);

  log("Equipment(%p)::Enchant( %x, %x, %x ) returns %i",
    equipment, unk0, unk1, unk2, retVal);
}
