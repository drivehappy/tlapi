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



  };

#pragma pack()

};