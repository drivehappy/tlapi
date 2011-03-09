#pragma once

#include "CPositionableObject.h"
#include "CDataGroup.h"
#include "CCullingBounds.h"
#include "CSkillManager.h"

namespace TLAPI
{

#pragma pack(1)

  struct CEffectManager;
  TLFUNC(BaseUnit_AddSkill, void, __thiscall, (CBaseUnit*, wstring*, u32));

  // CBaseUnit Size = 0x190
  struct CBaseUnit : CPositionableObject
  {
    u32 level;        // Level of Character/Unit

    u32 unk1[3]; 
    u32 visibility_test;  // @0x1a4  [3] = Visibility flag?
    u32 unk2[13];

    u32 unk3[6];        // See below
                      /*
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                        0FFFFFFFFh
                      */

    u32 unk6;           
    u8 unk06[4];          // [1]

    u8 destroy;
    u8 destroy1;
    u8 destroy2;
    u8 destroy3;

    float unk7;           // 0.3
    
    u8  unkFlags[4];           // Early out test for [3] in CharacterUpdate

    u8  visibility_test2; // @164h
    u8  unk10[3];

    u64 GUID;        // 0F59522DA8B7A11DEh

    u32 unk8;         


    u32 type__;       // What is this? A type flag?
      // 68h || 2ah || 1C
      // 68h = Valeria
      // AFh = Goldenrod
      // 68h = Gar
      // 68h = Horse
      // 68h = Syl
      // 1Ch = Server's Player - Drivehappy
      // 57h = Server's Player's Pet
      // 1Ch = Server created monster (player - Drivehappy)
      // 2Dh = Ordrak's Wingblade
      // 54h = Scale Haubergeon
      // 50h = Scale Greaves
      // 4Dh = Epic Leather Shoulders


    CDataGroup *pCDataGroup;

    CEffectManager *pCEffectManager;    // @17Ch
    CCullingBounds *pCCullingBounds;
    CSkillManager  *pCSkillManager;

    float unk12;        // 0.5
    u32 unk13;          // 1


    EVENT_DECL(CBaseUnit, void, BaseUnit_AddSkill,
      (CBaseUnit*, wstring*, u32, bool&),
      ((CBaseUnit*)e->_this, (wstring*)Pz[0], Pz[1], e->calloriginal));
    

    void addSkill(wstring* name, u32 unk0)
    {
      BaseUnit_AddSkill(this, name, unk0);
    }

    void Destroy() {
      destroy = true;
    }

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

