#pragma once

// Size?: 68h   - base 0Ch
// Inherits: CRunicCore
struct CSkill : CRunicCore
{
  PVOID unk0;

  // ----------- End Base Data members -----

  PVOID vtableIUnitObserver;

  PVOID pCResourceManager;
  PVOID pCSkillManager;
  PVOID pCDataGroup;

  u32 unk1[4];

  PVOID unk2;

  u32 unk3[7];

  float unk4;

  u32 unk5[4];

  PVOID pCSkillProperty0;
  PVOID pCSkillProperty1;
  PVOID pCSkillProperty2;
};
