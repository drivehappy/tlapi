#pragma once

#include "CRunicCore.h"
#include "CEquipment.h"

namespace TLAPI
{
  struct CEquipment;

  struct CEquipmentRef : CRunicCore
  {
    PVOID       unk0;
    CEquipment *pCEquipment;  // ptr to CEquipment

    s32 slot;         //
    s32 slotother;    //
    
    bool unk1[4];

    PVOID       vtable__iSelected;

    
    // EquipmentRef Dtor
    EVENT_DECL(CEquipmentRef, void, EquipmentRef_Dtor,
      (CEquipmentRef*, u32),
      ((CEquipmentRef*)e->_this, Pz[0]));


    void dumpEquipmentRef()
    {
      logColor(B_BLUE, "EquipmentRef: slot = %i %i", slot, slotother);
    }
  };

};
