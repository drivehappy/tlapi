#pragma once

#include "CRunicCore.h"
#include "CSoundBank.h"

struct CAttackDescription : CRunicCore
{
  u32     unk0;       // 0

  PVOID  *unkPointer; // Seen this pt to CSoundBank and CAttackDescription...

  // I think this is a special ascii string similar
  // to the CString struct (but non-wide).. or garbage
  // i.e. "Polearm",          for epic polearm
  // i.e. "LSLASH", "RSLASH"  for Ordrak's Wingblade
  float   unk1;       // 12.770342
  u32     unk2[2];    // 2004853h  6
  float   unk3;       // 0.46488699
  u32     unk4[2];    // 6   0Fh


  u32     unk5;       // Bitfield? 0C4000001h - Ordrak's Wingblade
                      //            11000100000000000000000000000001
  PVOID   unk11;
  u32     unk10;
  
  u32     damageMaximumPhysical0;
  u32     unk6[6];
  u32     damageMaximumPhysical1;
  u32     unk12[9];


  float   unk7[2];    // 0.6    1.1     // Wobbly Ratchet
                      // 1.0    1.5     // Epic Polearm     - only 2hander
                      // 0.6    1.1     // Ordrak's
                      // 0.6    1.1     // Bishop's

  float   attackSpeed;

  u32     unk13;
  float   unk8[30];
  u32     unk9[2];    // 552f4630h  10Bh


  void dumpAttack()
  {
    log("CAttackDescription: %p", this);
    log("  AttackSpeed: %f", attackSpeed);
    log("  damageMaximumPhysical0: %i", damageMaximumPhysical0);
    log("  damageMaximumPhysical1: %i", damageMaximumPhysical1);
    log("  unk6: %x %x %x %x %x %x", unk6[0], unk6[1], unk6[2], unk6[3], unk6[4], unk6[5]);
    log("  unk12: %x %x %x %x %x %x %x %x %x", unk12[0], unk12[1], unk12[2], unk12[3], unk12[4], unk12[5], unk12[6], unk12[7], unk12[8]);
    log("  unk7: %x %x", unk7[0], unk7[1]);
    log("  unk10: %x", unk10);
    log("  unk13: %x", unk13);
  }
};
