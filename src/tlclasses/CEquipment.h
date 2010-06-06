#pragma once

#include "CItem.h"
#include "CAttackDescription.h"

// Forward decl CInventory
struct CInventory;

// Size?: 3E0h
// Inherits: CItem
struct CEquipment : CItem
{
  PVOID vtable_iMissle;

  u32 stackSize;    // 13h = 19 pots
  u32 stackSizeMax; // 14h = 20 max size pots

  CInventory    *inventory;

  u32   unk0999[5];

  // Below appears to be wrong
  u32       unk1002[5];
  u32       requirements[5];    // level  str  dex   unk/unk (magic/defense?)

  CCharacter *character;
  PVOID       unk1000;
  u32         unk0998;
  //u32   id[4];
  //u32   unk1000[9];


  // Correct, first corresponds to Left hand or Main hand attack
  // second corresponds to Right hand attack
  CAttackDescription *pCAttackDescriptor0;
  CAttackDescription *pCAttackDescriptor1;

  PVOID pCGenericModel;

  PVOID unk1001;
  PVOID unk1004;

  PVOID pCEGUIPropertySheet;

  u32   unk1005;

  CString nameUnidentified;
  CString namePrefix;         // Appears to crash, not quite right?
  CString nameSuffix;

  u32   unk1006[16];
  u32   physicalDamage[2];    // Both contain it


  void dumpEquipment() {
    logColor(B_GREEN, "Equipment Dump: %p (basesize: %i)", this, sizeof(CItem));
    
    dumpItem();

    logColor(B_GREEN, "  StackSize: %i", stackSize);
    logColor(B_GREEN, "  StackSize Max: %i", stackSizeMax);

    logColor(B_GREEN, "  unk1000 = %p", unk1000);

    logColor(B_GREEN, "  pCAttackDescriptor0 = %p", pCAttackDescriptor0);
    logColor(B_GREEN, "  pCAttackDescriptor1 = %p", pCAttackDescriptor1);

    logColor(B_GREEN, "  pCGenericModel = %p", pCGenericModel);
    logColor(B_GREEN, "  unk1001 = %p", unk1001);
    logColor(B_GREEN, "  unk1004 = %p", unk1004);

    logColor(B_GREEN, "  CEGUIPropertySheet = %p", pCEGUIPropertySheet);

    logColor(B_GREEN, L"  nameUnidentified = %s", nameUnidentified.getString());
    //logColor(B_GREEN, L"  namePrefix = %s", namePrefix.getString());
    //logColor(B_GREEN, L"  nameSuffix = %s", nameSuffix.getString());

    logColor(B_GREEN, "  physicalDamage = %i %i", physicalDamage[0], physicalDamage[1]);

    logColor(B_GREEN, "  Item Requirements:");
    logColor(B_GREEN, "     Level: %i", requirements[0]);
    logColor(B_GREEN, "     Strength: %i", requirements[1]);
    logColor(B_GREEN, "     Dexterity: %i", requirements[2]);
    logColor(B_GREEN, "     Magic: %i", requirements[3]);
    logColor(B_GREEN, "     Defense: %i", requirements[4]);

    logColor(B_GREEN, "  Character: %p", character);
  }
};
