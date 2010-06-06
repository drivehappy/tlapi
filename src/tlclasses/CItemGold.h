#pragma once

#include "CItem.h"
#include "CGenericModel.h"
#include "CParticle.h"

//
struct CItemGold : CItem
{
  u32 amount;

  float x;        // I think
  float y;

  CGenericModel  *pCGenericModel;

  u32 unk1001[16];

  CParticle      *pCParticle;


  void dumpItemGold()
  {
    log("CItemGold Dump: %p (size: %i)", this, sizeof(CItemGold));
    log("  Amount: %i", amount);
    log("  Position: %f %f", x, y);
  }
};
