#pragma once

#include "CItem.h"
#include "CGenericModel.h"
#include "CParticle.h"


namespace TLAPI
{

#pragma pack(1)

  // Forward
  struct CItemGold;
  TLFUNC(ItemGold_Ctor, CItemGold*, __thiscall, (PVOID, CResourceManager*, u32));

  // Size: 0x238
  struct CItemGold : CItem
  {
    u32 amount;

    float x;        // I think
    float y;

    CGenericModel  *pCGenericModel;

    u32 unk1001[16];

    CParticle      *pCParticle;

    u32 unk1002;


    // Character Update Health
    EVENT_DECL(CItemGold, void, ItemGold_Ctor,
      (CItemGold*, PVOID, CResourceManager*, u32, bool&),
      ((CItemGold*)e->retval, (PVOID)e->_this, (CResourceManager*)Pz[0], Pz[1], e->calloriginal));



    CItemGold* ItemCtor(CResourceManager* resourceManager, u32 amount) {
      return ItemGold_Ctor(this, resourceManager, amount);
    }


    void dumpItemGold()
    {
      log("CItemGold Dump: %p (size: %i)", this, sizeof(CItemGold));
      log("  Amount: %i", amount);
      log("  Position: %f %f", x, y);
    }
  };
  
#pragma pack()

};

