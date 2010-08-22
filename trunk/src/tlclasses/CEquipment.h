#pragma once

#include "CItem.h"
#include "CAttackDescription.h"
#include "CMasterResourceManager.h"
#include "CEffectManager.h"
#include "CEffectGroupManager.h"
#include "CInventory.h"

namespace TLAPI
{

  // Forward decl CInventory
  struct CItemSaveState;
  struct CGenericModel;
  struct CCharacter;

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

  // Size = 
  struct CEquipment : CItem
  {
    PVOID vtable_iMissle;

    u32 stackSize;    // 13h = 19 pots
    u32 stackSizeMax; // 14h = 20 max size pots

    PVOID     inventory;

    u32       stackable;
    u32       unk0999[4];

    u32       unk1002[5];
    u32       requirements[5];    // level  str  dex  magic  defense

    u32       unk0998[3];         // 0, 0, 10h

    // Correct, first corresponds to Left hand or Main hand attack
    // second corresponds to Right hand attack
    CAttackDescription *pCAttackDescriptor0;
    CAttackDescription *pCAttackDescriptor1;

    CGenericModel      *pCGenericModel;

    PVOID     unk1001;
    PVOID     unk1004;

    PVOID     pCEGUIPropertySheet;

    wstring nameUnidentified;
    wstring namePrefix;
    wstring nameSuffix;

    float unk1006[16];
    u32   minimumPhysicalDamage;      // @ 0x2E4
    u32   maximumPhysicalDamage;

    u32   unk1007;
    u32   armor;
    u32   changeMeForDamageUpdate;    // Haven't looked at the code that alters this
                                      //  but if it changes the min and max are updated correctly

    u32   enhancementCount;

    // New: Post std::vector change
    u32   unk1008[1];

    std::vector<u32> enchantTypeList;
    std::vector<u32> enchantList;

    vector<u32> enhancedDamage; // Electric, Ice, Fire, Posion

    u32   unk1010[21];

    u32                 socketCount;
    CList<CEquipment*>  gemList;

    u32   unk1011[6];


    // 
    // Function hooks
    EVENT_DECL(CEquipment, void, EquipmentCtor,
      (CEquipment*),
      ((CEquipment*)e->_this));

    // Equipment Initialization
    EVENT_DECL(CItem, void, EquipmentInitialize,
      (CEquipment*, CItemSaveState*, bool&),
      ((CEquipment*)e->_this, (CItemSaveState*)Pz[0], e->calloriginal));

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

    // Adds to the stack count
    EVENT_DECL(CEquipment, void, EquipmentAddStackCount,
      (CEquipment*, u32),
      ((CEquipment*)e->_this, Pz[0]));

    
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

      // If we don't have an effect manager for this equipment, add one
      // this is hacky, but I'm too lazy to recreate it myself
      if (!pCEffectManager) {
        logColor(B_RED, L"No EffectManager for Equipment, creating...");
        effectMgr->CreateAffix(0x5F, 0, 5, listAffixes);
        CAffix* affix = (*listAffixes)[0];
        AddAffix(affix, 0, this, 1.0f);
        pCEffectManager->effectList.size = 0;
        pCEffectManager->affixList.size = 0;
      }

      // Change the effect type and value
      // Add the unknowns, some weird effects are cropping up
      logColor(B_RED, L" Add effect to Equipment EffectManager list: Type: %x, Value: %f", type, amount);
      CEffect* effect = new CEffect;
      effect->effectType = type;
      effect->effectValue = amount;
      effect->effectIndex = pCEffectManager->effectList.size;
      effect->unk2 = 0;
      effect->unk3 = -1000.0f;
      effect->unk4[0] = 0;
      effect->unk4[1] = 0;
      effect->setup = 0x10001;
      effect->unk8 = 0x1000100;
      effect->unk9 = 1.0f;
      effect->unk6[0] = 0x64;
      effect->unk6[1] = 0x64;
      effect->unk6[2] = 0;
      effect->equipment = this;

      pCEffectManager->effectList.push(effect);

      /*
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
      */
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

      log(L"  enchantList sizeof: %i.", sizeof(enchantList));
      log(L"  enchantTypeList sizeof: %i.", sizeof(enchantTypeList));

      logColor(B_GREEN, "  SocketCount: %i", socketCount);
      logColor(B_GREEN, "    Gems: %i", gemList.size);
      for (u32 i = 0; i < gemList.size; i++) {
        logColor(B_RED, "      %p: GUID: %016I64X", gemList[i], gemList[i]->GUID);
      }

      logColor(B_GREEN, "  StackSize: %i", stackSize);
      logColor(B_GREEN, "  StackSize Max: %i", stackSizeMax);

      if (pCAttackDescriptor0) {
        logColor(B_GREEN, "  pCAttackDescriptor0 = %p", pCAttackDescriptor0);
        pCAttackDescriptor0->dumpAttack();
      }
      if (pCAttackDescriptor1) {
        logColor(B_GREEN, "  pCAttackDescriptor1 = %p", pCAttackDescriptor1);
        pCAttackDescriptor1->dumpAttack();
      }

      logColor(B_GREEN, "  pCGenericModel = %p", pCGenericModel);
      logColor(B_GREEN, "  unk1001 = %p", unk1001);
      logColor(B_GREEN, "  unk1004 = %p", unk1004);

      logColor(B_GREEN, "  CEGUIPropertySheet = %p", pCEGUIPropertySheet);

      logColor(B_GREEN, L"  nameUnidentified = %s", nameUnidentified.c_str());
      logColor(B_GREEN, L"  namePrefix = %s", namePrefix.c_str());
      logColor(B_GREEN, L"  nameSuffix = %s", nameSuffix.c_str());

      logColor(B_GREEN, "  Max physical damage: %i", maximumPhysicalDamage);
      logColor(B_GREEN, "  Min physical damage: %i", minimumPhysicalDamage);

      logColor(B_GREEN, "  Armor: %i", armor);

      logColor(B_GREEN, "  Item Requirements:");
      logColor(B_GREEN, "     Level: %i", requirements[0]);
      logColor(B_GREEN, "     Strength: %i", requirements[1]);
      logColor(B_GREEN, "     Dexterity: %i", requirements[2]);
      logColor(B_GREEN, "     Magic: %i", requirements[3]);
      logColor(B_GREEN, "     Defense: %i", requirements[4]);

      // New
      const char* EnchantTypeString[] = { "PHYSICAL", "UNKNOWN", "FIRE", "ICE", "ELECTRIC", "POISON" };

      logColor(B_GREEN, "  Item Enchants:");
      std::vector<u32>::iterator itr;
      for (size_t index = 0; index < enchantList.size(); index++) {
        logColor(B_GREEN, "     %s %i", EnchantTypeString[index], enchantList[index]);
      }

      logColor(B_GREEN, "  Item Enhanced Damages: size = %i", enhancedDamage.size());
      vector<u32>::iterator itr2;
      for (itr2 = enhancedDamage.begin(); itr2 != enhancedDamage.end(); itr2++) {
        logColor(B_GREEN, "    MaxDamage: %i", (*itr2));
      }

      logColor(B_GREEN, "  unk0999[4]: %x %x %x %x",
        unk0999[0], unk0999[1], unk0999[2], unk0999[3]);
      logColor(B_GREEN, "  unk1002[5]: %x %x %x %x %x",
        unk1002[0], unk1002[1], unk1002[2], unk1002[3], unk1002[4]);
      logColor(B_GREEN, "  unk0998[3]: %x %x %f",
        unk0998[0], unk0998[1], unk0998[2]);
      logColor(B_GREEN, "  unk1007: %x",
        unk1007);
      logColor(B_GREEN, "  unk1008[1]: %f (%x)",
        unk1008[0], unk1008[0]);

      logColor(B_GREEN, "  unk1010:");
      for (u32 i = 0; i < 21; i++) {
        logColor(B_GREEN, "   %x", unk1010[i]);
      }

      logColor(B_GREEN, "  unk1011[6]: %f %f %f %f %f %f",
        unk1011[0], unk1011[1], unk1011[2], unk1011[3], unk1011[4], unk1011[5]);
      

      if (pCEffectManager) {
        pCEffectManager->dumpEffectManager();
      }
    }
  };

};
