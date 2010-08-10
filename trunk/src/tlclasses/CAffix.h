#pragma once

#include "_CString.h"
#include "_CList.h"

#include "CRunicCore.h"
#include "CEffect.h"

namespace TLAPI {

#pragma pack(1)

  /* Notes for Affix creation (call @0x5FC0F0):
      u32 param is type?
        1 - Tiger (Faster Attack)
        3 - Ice
  */

  struct CAffix : CRunicCore
  {
    u32 unk0;

    PVOID pCAffixNext;    // Linked list struct?

    PVOID pCSkill;        // ptr to CSkill

    u32 unk1[6];          // 18h, 0, FFFFFFFFh, 0, FFFFFFFFh, CB7581ABh

    CString pStringMediaAffixesSk;  // string = "MEDIA/AFFIXES/SKILLS/SKILL_SPELLCASTING_MASTERY.DAT"

    u32 unk2;             // 0

    CString pStringSkill_spellcast; // ptr string = "SKILL_SPELLCASTING_MASTERY"

    u32 unk3[8];          // 80h, 0

    CString name;         // "Expert [ITEM]"

    u32 unk4[3];             // 0

    //PVOID pOgreSharedPtr;   //

    //u32 unk5[6];             // 0

    u32 unkInteresting[2];    // 0Ah, 2   -- Magic Type IDs?

    u32 unk6[2];          // 0

    CList<CEffect*> effectList;

    PVOID pOgreGenerateShadowVolume;

    u32 unk7[4];

    CList<PVOID>  unkList;
  };

#pragma pack()

};

