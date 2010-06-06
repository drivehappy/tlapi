#pragma once

#include "CPositionableObject.h"

// Size?: 60h
// Inheritance: CPositionableObject
#pragma pack(1)
struct CBaseUnit : CPositionableObject
{
  u32 unk1[18];

  u32 unk3[6];        // See below
                    /*
                      0FFFFFFFFh
                      0FFFFFFFFh
                      0FFFFFFFFh
                      0
                      0FFFFFFFFh
                      0FFFFFFFFh
                    */

  u32 unk6;           // 1010101

  u32 unk7[5];        // 340D5401h

  u64 GUID;        // 0F59522DA8B7A11DEh

  u32 unk8;         

  u32 unk9;           // 68h    || 2ah

  PVOID pCDataGroup;
  PVOID pCEffectManager;  // NULL
  PVOID pCCullingBounds;
  PVOID pCSkillManager;

  float unk12;        // 0.5
  u32 unk13;          // 1


  //
  void dumpBaseUnit()
  {
    log("CBaseUnit Dump: %p (size: %i)", this, sizeof(CBaseUnit));
    log("  GUID: %016I64X", GUID);
    log("  CDataGroup: %p", pCDataGroup);
    log("  CEffectManager: %p", pCEffectManager);
    log("  CCullingBounds: %p", pCCullingBounds);
    log("  CSkillManager: %p", pCSkillManager);
  }
};
#pragma pack()
