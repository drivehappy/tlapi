#pragma once

// Size?: B0h
// Inheritance: CRunicCore
struct CAffix : CRunicCore
{
  u32 unk0;

  PVOID pCAffixNext;    // Linked list struct?

  PVOID pCSkill;        // ptr to CSkill

  u32 unk1[6];          // 18h, 0, FFFFFFFFh, 0, FFFFFFFFh, CB7581ABh

  PVOID pStringMediaAffixesSk;  // ptr string = "MEDIA/AFFIXES/SKILLS/SKILL_SPELLCASTING_MASTERY.DAT"

  u32 unk2[6];          // 0,0,0,33h,37h,0

  PVOID pStringSkill_spellcast; // ptr string = "SKILL_SPELLCASTING_MASTERY"

  u32 unk3[7];          // 0,0,1078h, 1Ah, 1Fh, 80h, 0

  // UNICODE            // 0 length, unk
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this
  // --

  u32 unk4;             // 0

  // UNICODE            // 0 length, unk
  union {
    wchar_t name2[8];    // In-place unicode data
    PVOID namePtr2[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength2;
  u32 maxNameLength2;    // Guess, double check this
  // --

  u32 unk5;             // 0

  //
  u32 unk6[6];          // 64h, CB758109h, 1, 0, 9, CB758109h
};
