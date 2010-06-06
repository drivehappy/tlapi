#pragma once

// Size?: 38h
struct CSkillProperty : CRunicCore
{
  float unk0[5];

  PVOID pCResourceManager;
  PVOID pCSkillProperty;
  PVOID pCSkill;

  u32 unk1[2];

  PVOID pCDataGroup;

  u32 unk2;
  PVOID unk3;
};
