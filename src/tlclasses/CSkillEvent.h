#pragma once

// Size?: 9Ch
struct CSkillEvent : CRunicCore
{
  u32 unk0;

  // ---------- Base type cutoff -----

  PVOID vtableIDamageShape;
  PVOID vtableIMissle;
  PVOID vtableIUnitSpawner;

  PVOID pCSkill;
  PVOID pCResourceManager;
  PVOID pCLayout;

  u32 unk1[11];

  PVOID pCSkillProperty;

  u32 unk2[5];

  PVOID* ppCUnitSpawner;    // ptr ptr to CUnitSpawner

  u32 unk3[13];
};
