#pragma once

#include "Helper.h"

#include "_CList.h"

#include "CEffectManager.h"
#include "CPlayer.h"
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
  9: Right Ring
  10: Amulet

  19-39: Equipment  Tab  (row-order)
  40-60: Spells     Tab
  61-81: Fish       Tab
*/

struct CPlayer;

// 
struct CInventory : CRunicCore
{
  u32                   unk0[3];

  CEffectManager       *pCEffectManager;
  CPlayer              *pCPlayer;

  u32                   unk10;

  CList<CEquipmentRef*> equipmentList;
  CList<PVOID>          iInventoryListenerList;


  void dumpInventory() {
    logColor(B_RED, "Inventory Dump: %p", this);

    for (int i = 0; i < 3; i++) {
      logColor(B_RED, "  unk0[%i] = %9i %#9x", i, unk0[i], unk0[i]);
    }
    //logColor(B_RED, "  unk10 = %9i %#9x", unk10, unk10);

    logColor(B_RED, "  CEffectManager: %p", pCEffectManager);
    logColor(B_RED, "  CPlayer: %p", pCPlayer);
    logColor(B_RED, "  EquipmentCount: %i", equipmentList.size);
    logColor(B_RED, "  Equipment:");

    for (int i = 0; i < (int)equipmentList.size; i++) {
      logColor(B_RED, L"  Equipment Name: %s", equipmentList[i]->pCEquipment->nameReal.getString());
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
};
