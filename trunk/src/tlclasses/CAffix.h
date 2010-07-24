#pragma once

#include "CRunicCore.h"
#include "_CString.h"

namespace TLAPI {

#pragma pack(1)

  struct CAffix : CRunicCore
  {
    u32 unk0;

    PVOID pCAffixNext;    // Linked list struct?

    PVOID pCSkill;        // ptr to CSkill

    u32 unk1[6];          // 18h, 0, FFFFFFFFh, 0, FFFFFFFFh, CB7581ABh

    CString pStringMediaAffixesSk;  // string = "MEDIA/AFFIXES/SKILLS/SKILL_SPELLCASTING_MASTERY.DAT"

    u32 unk2;             // 0

    CString pStringSkill_spellcast; // ptr string = "SKILL_SPELLCASTING_MASTERY"

    u32 unk3[2];          // 80h, 0

    CString name;

    u32 unk4;             // 0

    CString name2;

    u32 unk5;             // 0

    //
    u32 unk6[6];          // 64h, CB758109h, 1, 0, 9, CB758109h
  };

#pragma pack()

};

