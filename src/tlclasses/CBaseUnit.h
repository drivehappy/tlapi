#pragma once

#include "CPositionableObject.h"
#include "CDataGroup.h"
#include "CCullingBounds.h"
#include "CSkillManager.h"

namespace TLAPI
{

#pragma pack(1)

  struct CEffectManager;

  // CPositionableObject size = 0xF0
  struct CBaseUnit : CPositionableObject
  {
    u32 unk1[18];

    u32 unk3[6];        // See below
                      /*
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                      */

    u32 unk6;           // 1010101
    u32 unk06[1];          // 1000101h

    u8 destroy;
    u8 destroy1;
    u8 destroy2;
    u8 destroy3;

    u32 unk7[3];        /*
                        69740000h
                        0.30000001
                        1010101h
                        656D6101h
                        */

    u64 GUID;        // 0F59522DA8B7A11DEh

    u32 unk8;         

    u32 unk9;           // 68h    || 2ah || 1C

    CDataGroup *pCDataGroup;

    CEffectManager *pCEffectManager;
    CCullingBounds *pCCullingBounds;
    CSkillManager  *pCSkillManager;

    float unk12;        // 0.5
    u32 unk13;          // 1


    //
    void dumpBaseUnit()
    {
      log("CBaseUnit Dump: %p (size: %i)", this, sizeof(CBaseUnit));
      log("  GUID: %016I64X", GUID);
      log("  CDataGroup: %p", pCDataGroup);

      //pCDataGroup->dumpDataGroup();

      log("  CEffectManager: %p", pCEffectManager);
      log("  CCullingBounds: %p", pCCullingBounds);
      log("  CSkillManager: %p", pCSkillManager);
    }
  };

#pragma pack()

};

