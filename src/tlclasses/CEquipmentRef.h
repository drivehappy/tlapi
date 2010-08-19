#pragma once

#include "CRunicCore.h"
#include "CEquipment.h"

namespace TLAPI
{
  struct CEquipment;

  struct CEquipmentRef : CRunicCore
  {
    PVOID       unk0;         // NULL -- is this the vtable?? if it is remove (defined in CRunicCore)
    CEquipment *pCEquipment;  // ptr to CEquipment

    s32 slot;         //
    s32 slotother;    //
    u32 unk2[5];


    void dumpEquipmentRef()
    {
      logColor(B_BLUE, "EquipmentRef: slot = %i %i", slot, slotother);
    }
  };

};
