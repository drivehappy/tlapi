#pragma once

// Size?: 2Ch
struct CSkillEffectAndAffix : CRunicCore
{
  u32 unk0;

  PVOID pCSkill;

  u32 unk1[4];

  PVOID* ppCSkillEffectData;    // ptr ptr to CSkillEffectData

  u32 unk2[3];      // <--- 1, 0Ah, 0Ah    Similar to other structs
};
