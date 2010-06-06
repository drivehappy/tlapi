#pragma once

// Size?: 0Ch
struct CAIManager : CRunicCore
{
  PVOID vtable;
  u32 unk0;
  PVOID pCharacterPtr;  // Pointer to character
  PVOID pAIFlagManager; // Ptr to AIFlagManager
  PVOID pAISkillManager;// Ptr to CAISkillManager
};
