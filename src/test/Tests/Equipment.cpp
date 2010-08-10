#include "Test.h"

void Test_Equipment_Initialize(CEquipment* equipment, CItemSaveState* itemSaveState, bool& calloriginal)
{
  testLogger.WriteLine(Info,
    L"Equipment(%p)::Initialize( %p ) returns TODO",
    equipment, itemSaveState);

  testLogger.WriteLine(Verbose,
    L"  Name: %s",
    itemSaveState->name.c_str());

  //log("Equipment Initialize: this = %p, ItemSaveState = %p", equipment, itemSaveState);
  //itemSaveState->dumpItemSaveState();
  //equipment->dumpEquipment();

  //log(L"Equipment Initialize: %s", equipment->nameReal.c_str());
}

void Test_Equipment_Enchant(u32 retVal, CEquipment* equipment, u32 unk0, u32 unk1, u32 unk2)
{
  testLogger.WriteLine(Info,
    L"Equipment(%p)::Enchant( %x, %x, %x ) returns %i",
    equipment, unk0, unk1, unk2, retVal);

  log("Equipment(%p)::Enchant( %x, %x, %x ) returns %i",
    equipment, unk0, unk1, unk2, retVal);
}

void Test_Equipment_AddMagicModifier(CEquipment* equipment, u32 unk0, u32 unk1)
{
  testLogger.WriteLine(Info,
    L"Equipment(%p)::AddMagicModifier( %x, %x )",
    equipment, unk0, unk1);
}

void Test_Equipment_AddAffix(CEquipment* equipment, CAffix* affix, u32 unk0, CEquipment* equipment2, float unk1)
{
  testLogger.WriteLine(Info,
    L"Equipment(%p)::AddAffix( Affix(%p), unk0(%x), Equipment2(%p), unk1(%f) )",
    equipment, affix, unk0, equipment2, unk1);
}

