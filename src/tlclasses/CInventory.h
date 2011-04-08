#pragma once

#include "Common.h"

#include "_CList.h"
#include "CEquipment.h"
#include "CEquipmentRef.h"

/* Slot IDs and their positions:

  0:  Primary Main Hand
  1:  Primary Off Hand

  12: Secondary Main Hand
  13: Secondary Off Hand

  2:  Hands
  3:  Helm
  4:  Chest
  5:  Shoulder
  6:  Feet
  7:  Waist

  8:  Left Ring
  9:  Right Ring
  10: Amulet

  14: Enchanting Slot (NPC Window)

  19-39: Equipment  Tab  (row-order)
  40-60: Spells     Tab
  61-81: Fish       Tab

  57B769
*/

namespace TLAPI
{
  struct CEffectManager;
  struct CCharacter;
  struct CInventory;
  TLFUNC(InventoryRemoveEquipment,          PVOID,  __thiscall, (CInventory*, CEquipment*));
  TLFUNC(InventoryAddEquipment,             PVOID,  __thiscall, (CInventory*, CEquipment*, u32, u32));
  TLFUNC(InventoryGetEquipmentFromSlot,     void,   __thiscall, (CEquipment*, CInventory*, u32));
  TLFUNC(InventoryGetEquipmentRefFromSlot,  void,   __thiscall, (CEquipmentRef*, CInventory*, u32));
  TLFUNC(InventoryAddTabSize,               void,   __thiscall, (CInventory*, u32, u32));

#pragma pack(1)

  // 
  struct CInventory : CRunicCore
  {
    u32                   unk0[3];

    CEffectManager       *pCEffectManager;
    CCharacter           *pCCharacter;

    u32                   maxSize;

    CList<CEquipmentRef*> equipmentList;
    CList<CRunicCore*>    unkList;        // CPlayer, CEnchantMenu, odd list...

    vector<u32>           tabIndices;     // Tab group indicies: 1, 2, 3
    vector<u32>           tabSizes;       // Tab group sizes for indicies: 13h, 28h, 3Dh ===> 19., 40., 61.

    //
    // Adds equipment to the given Inventory
    EVENT_DECL(CInventory, void, InventoryAddEquipment,
      (CEquipment*, CInventory*, CEquipment*, u32&, u32, bool&),
      ((CEquipment*)e->retval, (CInventory*)e->_this, (CEquipment*)Pz[0], Pz[1], Pz[2], e->calloriginal));

    // Removes equipment from the given Inventory
    EVENT_DECL(CInventory, void, InventoryRemoveEquipment,
      (CInventory*, CEquipment*),
      ((CInventory*)e->_this, (CEquipment*)Pz[0]));
    
    // Get Equipment from slot
    EVENT_DECL(CInventory, void, InventoryGetEquipmentFromSlot,
      (CEquipment*, CInventory*, int),
      ((CEquipment*)e->retval, (CInventory*)e->_this, Pz[0]));

    // Get EquipmentRef from slot
    EVENT_DECL(CInventory, void, InventoryGetEquipmentRefFromSlot,
      (CEquipmentRef**, CInventory*, int),
      ((CEquipmentRef**)e->retval, (CInventory*)e->_this, Pz[0]));

    // Adds a new "tab" to the inventory at the appropriate index with the size of the tab
    // The size of the tab is simply added to the maximum inventory size
    EVENT_DECL(CInventory, void, InventoryAddTabSize,
      (CInventory*, u32, u32),
      ((CInventory*)e->_this, Pz[0], Pz[1]));
    
    
    // Remove equipment from inventory
    void RemoveEquipment(CEquipment* equipment) {
      InventoryRemoveEquipment(this, equipment);
    }
    void AddEquipment(CEquipment* equipment, u32 slot, u32 unk0) {
      InventoryAddEquipment(this, equipment, slot, unk0);
    }
    void AddTabSize(u32 index, u32 size) {
      InventoryAddTabSize(this, index, size);
    }

    // Returns the slot number for the equipment in the inventory
    //  If the Equipment isn't found -1 is returned
    s32 GetEquipmentSlot(CEquipment* equipment) {
      for (u32 i = 0; i < equipmentList.size; i++) {
        if (equipmentList[i]->pCEquipment == equipment) {
          return equipmentList[i]->slot;
        }
      }
      return -1;
    }

    // Returns the equipment from the given slot number
    //  If the Slot contains no equipment NULL is returned
    CEquipment* GetEquipmentFromSlot(s32 slot) {
      for (u32 i = 0; i < equipmentList.size; i++) {
        if (equipmentList[i]->slot == slot) {
          return equipmentList[i]->pCEquipment;
        }
      }
      return NULL;
    }

    // Returns the equipmentRef from a given equipment if it exists
    //   in the inventory
    CEquipmentRef* GetEquipmentRefFromEquipment(CEquipment* equipment) {
      for (u32 i = 0; i < equipmentList.size; i++) {
        if (equipmentList[i]->pCEquipment == equipment) {
          return equipmentList[i];
        }
      }
      return NULL;
    }


    /*
    void dumpInventory() {
      logColor(B_RED, "Inventory Dump: %p", this);

      for (int i = 0; i < 3; i++) {
        logColor(B_RED, "  unk0[%i] = %9i %#9x", i, unk0[i], unk0[i]);
      }
      //logColor(B_RED, "  unk10 = %9i %#9x", unk10, unk10);

      logColor(B_RED, "  CEffectManager: %p", pCEffectManager);
      logColor(B_RED, "  CCharacter: %p", pCCharacter);
      logColor(B_RED, "  EquipmentCount: %i", equipmentList.size);
      logColor(B_RED, "  Equipment:");

      for (int i = 0; i < (int)equipmentList.size; i++) {
        //logColor(B_RED, L"  Equipment Name: %s", equipmentList[i]->pCEquipment->nameReal.getString());
        logColor(B_RED, L"  Equipment Name: %s", equipmentList[i]->pCEquipment->nameReal.c_str());
        logColor(B_RED, L"  Equipment AttackDesc:");
        CAttackDescription *attackLeftHand = equipmentList[i]->pCEquipment->pCAttackDescriptor0;
        CAttackDescription *attackRightHand = equipmentList[i]->pCEquipment->pCAttackDescriptor0;

        if (attackLeftHand)
          attackLeftHand->dumpAttack();
        if (attackRightHand)
          attackRightHand->dumpAttack();

        equipmentList[i]->dumpEquipmentRef();
      }
    }
    */
  };

#pragma pack()

};
