#pragma once

#include "CRunicCore.h"
#include "CEquipment.h"

// Size: 40 bytes (at least, no more than)
struct CEquipmentRef : CRunicCore
{
  PVOID       unk0;         // NULL -- is this the vtable?? if it is remove (defined in CRunicCore)
  CEquipment *pCEquipment;  // ptr to CEquipment

  u32 unk1[2];        // 67h, 67h
  u32 unk2[5];


  void dumpEquipmentRef()
  {
    logColor(B_BLUE, "EquipmentRef: %i %i", unk1[0], unk1[1]);
  }
};
