#pragma once

#include "CItem.h"
#include "CAttackDescription.h"
#include "CCharacter.h"
#include "CGenericModel.h"
#include "CMasterResourceManager.h"
#include "CEffectGroupManager.h"

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
  TLFUNC(Equipment_AddAffix,         void, __thiscall, (CEquipment*, CAffix*, u32, CEquipment*, float));

  // Enchantment Types
  enum EnchantType {
    PHYSICAL = 0,
    MAGICAL,
    FIRE,
    ICE, 
    ELECTRIC,
    POISON,
    ALL,

    USER,       // ???
    ITEM,       // ???

    // Values here will display as "" string in tooltip, no idea if the damage is
    // modified.

    // Defined by myself to aid in enchant
    NONE = 0xFF,
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

    CString nameUnidentified;   // 74 after this is socket count?
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

    u32   unk1007[28];          // Possibly extends Equipment bounds, but looking for enchantment stuff

    u32   socketCount;

    u32   unk1010[10];
    
    // Notes:
    // Interesting 3 ptrs at offset 780
    // Partial func for enchanting: @575F4A

    // 
    // Function hooks

    // Equipment Initialization
    EVENT_DECL(CItem, void, EquipmentInitialize,
      (CEquipment*, CItemSaveState*),
      ((CEquipment*)e->_this, (CItemSaveState*)Pz[0]));

    // Enchant
    EVENT_DECL(CEquipment, void, EquipmentEnchant,
      (u32, CEquipment*, u32, u32, u32),
      (e->retval, (CEquipment*)e->_this, Pz[0], Pz[1], Pz[2]));

    // Add only the magic modifier (PHYSICAL, ICE, FIRE, etc. [Not: CRIT, KNOCKBACK, etc])
    EVENT_DECL(CEquipment, void, Equipment_AddMagicModifier,
      (CEquipment*, u32, u32),
      ((CEquipment*)e->_this, Pz[0], Pz[1]));

    // Adds and Affix to the equipment (and internally the Effect attached to the Affix)
    EVENT_DECL(CEquipment, void, Equipment_AddAffix,
      (CEquipment*, CAffix*, u32, CEquipment*, float),
      ((CEquipment*)e->_this, (CAffix*)Pz[0], Pz[1], (CEquipment*)Pz[2], *(float*)&Pz[3]));

    
    u32 Enchant(u32 unk0, u32 unk1, u32 unk2) const {
      return EquipmentEnchant((CEquipment*)this, unk0, unk1, unk2);
    }
    void AddMagicModifier(EnchantType type, u32 amount) {
      Equipment_AddMagicModifier(this, type, amount);
    }
    void AddAffix(CAffix* affix, u32 unk0, CEquipment* equipment2, float unk1) {
      Equipment_AddAffix(this, affix, unk0, equipment2, unk1);
    }
    void AddOtherModifier(EffectType type, float amount) {
      CMasterResourceManager *masterResMgr = CMasterResourceManager::GetInstance();
      CEffectGroupManager *effectMgr = masterResMgr->pCEffectGroupManager;
      CList<CAffix*> *listAffixes = new CList<CAffix*>();
      listAffixes->size = 0;
      listAffixes->capacity = 0;
      listAffixes->growth = 1;

      effectMgr->CreateAffix(0x5F, 0, 5, listAffixes);

      if (listAffixes->size) {
        // Change the list of affixes to size 1
        listAffixes->size = 1;

        // Change the first effect list to size 1
        CAffix* affix = (*listAffixes)[0];
        CList<CEffect*> *effectList = &affix->effectList;
        effectList->size = 1;

        // Change the effect type and value
        CEffect* effect = (*effectList)[0];
        effect->effectType = type;

        // Add the modified Affix to the Equipment
        AddAffix(affix, 0, this, 1.0f);

        // Set the value after it's added, as this is changed as it's added
        effect->effectValue = amount;

        delete listAffixes;
      }
    }

    // This is designed to encompass the above into an easily callable function
    // for creating the exact item enchants requested (i.e. network item copy)
    void AddEnchant(EffectType type, EnchantType subType, float amount) {
      // Special case for regular type
      if (type == REGULAR) {
        // PHYSICAL, FIRE, ICE, POISON, ELECTRIC
        Equipment_AddMagicModifier(this, subType, (u32)amount);
      } else {
        // KNOCKBACK, FASTER ATTACK, etc.
        AddOtherModifier(type, amount);
      }
    }

    //
    void dumpEquipment() {
      logColor(B_GREEN, "Equipment Dump: %p (basesize: %i)", this, sizeof(CEquipment));
      
      dumpItem();

      /*
      logColor(B_GREEN, "  SocketTest: unk1007:");
      for (u32 i = 0; i < 30; i++) {
        logColor(B_BLUE, "    unk1007[%i] = %i", i, unk1007[i]);
      }
      logColor(B_GREEN, "  SocketTest: unk1010:");
      for (u32 i = 0; i < 10; i++) {
        logColor(B_BLUE, "    unk1010[%i] = %i", i, unk1010[i]);
      }
      */

      logColor(B_GREEN, "  SocketCount: %i", socketCount);
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
