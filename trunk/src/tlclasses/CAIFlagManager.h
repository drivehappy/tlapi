#pragma once

// Inheritance: CRunicCore
struct CAIFlagManager : CRunicCore
{
  u32 unk0;
  PVOID UnkStruct0; // This appears to be a CList<CAIFlag*>
  u32 unk1[3];
  PVOID pCharacter; // Ptr to CCharacter
  PVOID pAIManager; // Ptr to AI Manager
};
