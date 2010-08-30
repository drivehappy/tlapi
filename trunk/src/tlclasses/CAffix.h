#pragma once

#include "_CString.h"
#include "_CList.h"

#include "CRunicCore.h"
#include "CEffect.h"
#include "CSkill.h"

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

    CSkill *pCSkill;        // ptr to CSkill

    u32 unk1[5];          // 18h, 0, FFFFFFFFh, 0, FFFFFFFFh, CB7581ABh

    wstring pStringMediaAffixesSk;  // string = "MEDIA/AFFIXES/SKILLS/SKILL_SPELLCASTING_MASTERY.DAT"

    wstring pStringSkill_spellcast; // ptr string = "SKILL_SPELLCASTING_MASTERY"

    u32 unk3[7];          // 80h, 0

    wstring name;         // "Expert [ITEM]"

    u32 unk4[3];             // 0

    //PVOID pOgreSharedPtr;   //

    //u32 unk5[6];             // 0

    u32 unkInteresting[2];    // 0Ah, 2   -- Magic Type IDs?

    u32 unk6[2];          // 0

    CList<CEffect*> effectList;

    PVOID pOgreGenerateShadowVolume;

    u32 unk7[4];

    CList<PVOID>  unkList;


    void dumpAffix() {
      logColor(B_GREEN, L"Affix Dump (%p)", this);
      logColor(B_GREEN, L"  Skill: (%p)", pCSkill);
      logColor(B_GREEN, L"    SkillName: (%s)", pCSkill->pCSkillProperty0->skillName.c_str());
      logColor(B_GREEN, L"  pStringSkill_spellcast: (%s)", pStringSkill_spellcast.c_str());

    }
  };

#pragma pack()

};

