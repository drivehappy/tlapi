#pragma once

#include "CItem.h"
#include "CAttackDescription.h"
#include "CCharacter.h"
#include "CGenericModel.h"

namespace TLAPI
{

  // Forward decl CInventory
  struct CInventory;
  struct CItemSaveState;

  // Redefine the function here so we can use it within CEquipment
  // good ol' cyclic dependencies...
  struct CEquipment;
  TLFUNC(EquipmentEnchant,           u32,  __thiscall, (CEquipment*, u32, u32, u32));
  TLFUNC(Equipment_AddMagicModifier, void, __thiscall, (CEquipment*, u32, u32));

  // Enchantment Types
  enum EnchantType {
    PHYSICAL = 0,
    UNKNOWN,
    FIRE,
    ICE, 
    ELECTRIC,
    POISON,
  };

  // 
  struct CEquipment : CItem
  {
    PVOID vtable_iMissle;

    u32 stackSize;    // 13h = 19 pots
    u32 stackSizeMax; // 14h = 20 max size pots

    CInventory    *inventory;

    u32       unk0999[5];

    u32       unk1002[5];
    u32       requirements[5];    // level  str  dex   unk/unk (magic/defense?)

    u32       unk0998[3];         // 0, 0, 10h

    // Correct, first corresponds to Left hand or Main hand attack
    // second corresponds to Right hand attack
    CAttackDescription *pCAttackDescriptor0;
    CAttackDescription *pCAttackDescriptor1;

    CGenericModel      *pCGenericModel;

    PVOID     unk1001;
    PVOID     unk1004;

    PVOID     pCEGUIPropertySheet;

    u32       unk1005;

    CString nameUnidentified;
    CString namePrefix;         // Appears to crash, not quite right?
    CString nameSuffix;

    u32   unk1006[23];

    u32   enhancementCount;

    u32   unk1008[4];

    u32  *enchantTypeListStart;
    u32  *enchantTypeListEnd;

    u32   unk1009[4];

    u32  *enchantListStart;
    u32  *enchantListEnd;

    u32   unk1007[20];          // Possibly extends Equipment bounds, but looking for enchantment stuff
    
    // Notes:
    // Interesting 3 ptrs at offset 780
    // Partial func for enchanting: @575F4A

    // 
    // Function hooks

    // Equipment Initialization
    EVENT_DECL(CItem, void, EquipmentInitialize,
      (CEquipment*, CItemSaveState*),
      ((CEquipment*)e->_this, (CItemSaveState*)Pz[0]));

    EVENT_DECL(CEquipment, void, EquipmentEnchant,
      (u32, CEquipment*, u32, u32, u32),
      (e->retval, (CEquipment*)e->_this, Pz[0], Pz[1], Pz[2]));

    EVENT_DECL(CEquipment, void, Equipment_AddMagicModifier,
      (CEquipment*, u32, u32),
      ((CEquipment*)e->_this, Pz[0], Pz[1]));

    
    u32 Enchant(u32 unk0, u32 unk1, u32 unk2) const {
      return EquipmentEnchant((CEquipment*)this, unk0, unk1, unk2);
    }
    void AddMagicModifier(EnchantType type, u32 amount) {
      Equipment_AddMagicModifier((CEquipment*)this, type, amount);
    }

    //
    void dumpEquipment() {
      logColor(B_GREEN, "Equipment Dump: %p (basesize: %i)", this, sizeof(CEquipment));
      
      dumpItem();

      logColor(B_GREEN, "  StackSize: %i", stackSize);
      logColor(B_GREEN, "  StackSize Max: %i", stackSizeMax);

      logColor(B_GREEN, "  pCAttackDescriptor0 = %p", pCAttackDescriptor0);
      pCAttackDescriptor0->dumpAttack();
      logColor(B_GREEN, "  pCAttackDescriptor1 = %p", pCAttackDescriptor1);
      pCAttackDescriptor1->dumpAttack();

      logColor(B_GREEN, "  pCGenericModel = %p", pCGenericModel);
      logColor(B_GREEN, "  unk1001 = %p", unk1001);
      logColor(B_GREEN, "  unk1004 = %p", unk1004);

      logColor(B_GREEN, "  CEGUIPropertySheet = %p", pCEGUIPropertySheet);

      logColor(B_GREEN, L"  nameUnidentified = %s", nameUnidentified.getString());
      //logColor(B_GREEN, L"  namePrefix = %s", namePrefix.getString());
      //logColor(B_GREEN, L"  nameSuffix = %s", nameSuffix.getString());

      logColor(B_GREEN, "  Item Requirements:");
      logColor(B_GREEN, "     Level: %i", requirements[0]);
      logColor(B_GREEN, "     Strength: %i", requirements[1]);
      logColor(B_GREEN, "     Dexterity: %i", requirements[2]);
      logColor(B_GREEN, "     Magic: %i", requirements[3]);
      logColor(B_GREEN, "     Defense: %i", requirements[4]);

      u32 *itr = enchantListStart;
      u32 *itrType = enchantTypeListStart;
      const char* EnchantTypeString[] = { "PHYSICAL", "UNKNOWN", "FIRE", "ICE", "ELECTRIC", "POISON" };

      logColor(B_GREEN, "  Item Enchants:");
      while (itr != enchantListEnd) {
        logColor(B_GREEN, "     %s %i", EnchantTypeString[*itrType], (*itr));

        itr++;
        itrType++;
      }

      if (pCEffectManager) {
        pCEffectManager->dumpEffectManager();
      }
    }
  };

};
