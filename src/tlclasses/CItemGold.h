#pragma once

#include "CItem.h"
#include "CGenericModel.h"
#include "CParticle.h"


namespace TLAPI
{

#pragma pack(1)

  struct CItemGold : CItem
  {
    u32 amount;

    float x;        // I think
    float y;

    CGenericModel  *pCGenericModel;

    u32 unk1001[16];

    CParticle      *pCParticle;



    // Character Update Health
    EVENT_DECL(CItemGold, void, ItemGold_Ctor,
      (CItemGold*, CResourceManager*, u32, bool&),
      ((CItemGold*)e->retval, (CResourceManager*)Pz[0], Pz[1], e->calloriginal));


    void dumpItemGold()
    {
      log("CItemGold Dump: %p (size: %i)", this, sizeof(CItemGold));
      log("  Amount: %i", amount);
      log("  Position: %f %f", x, y);
    }
  };
  
#pragma pack()

};

