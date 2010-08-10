#pragma once

#include "CCharacter.h"

namespace TLAPI
{

#pragma pack(1)

  // Size?: 6D4h
  //
  struct CMonster: CCharacter
  {
    float   unk18[3];

    CList<PVOID>        listParticleAnimationTrigger;   // Type: CCharacter::CParticleAnimationTrigger

    u32     unk19[10];        // 0,0FFFFFFFFh,6 dup(   0),   7, 96h

    float   unk20;            // 60.0

  
    // 
    // Function hooks

    // Monster Process AI
    EVENT_DECL(CMonster, void, MonsterProcessAI2,
      (CMonster*, float, bool&),
      ((CMonster*)e->_this, *(float*)&Pz[0], e->calloriginal));

    // Monster Idle
    EVENT_DECL(CMonster, void, MonsterIdle,
      (CMonster*, float, bool&),
      ((CMonster*)e->_this, *(float*)&Pz[0], e->calloriginal));

  };

#pragma pack()

};