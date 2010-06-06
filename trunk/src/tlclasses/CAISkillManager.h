#pragma once

struct CAISkillManager : CRunicCore
{
  u32 unk0[4];  // values of 0
  u32 unk1;     // value of 2 w/ first pass
  PVOID pCCharacter;  // ptr to CCharacter
  PVOID pCAIManager;  // ptr to CAIManager
  PVOID pMediaModelString;  // ptr string value: MEDIA/MODELS/WEAPONS/HACKER/weapon_hacker
};
