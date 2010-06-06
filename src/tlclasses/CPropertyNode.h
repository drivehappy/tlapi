#pragma once

// Size?: 60h
// Node: Same base as CItem
// 
struct CPropertyNode : CPositionableObject
{
  // TODO - Use below

  /*
  PVOID vtable;
  u32 unk0;
  u64 guid0;      // 88F1C7449B211DFh
  u64 guid1;      // 0FFFFFFFFFFFFFFFFh
  u64 guid2;      // 19463565308B11DEh
  u64 guid3;      // 0F61AC062B9FC11DEh

  PVOID unk1;
  PVOID pCUnitTriggerDescriptor;    // CUnitTriggerDescriptor

  u32 unk2;       // 38h

  // UNICODE String ie "4 Gold" in place (16 bytes)
  // OR I noticed a ptr string to "TNT Barrel"
  // This appears to be that if the string is > 7 in length then it uses
  // a ptr in place of the unicode data (union)
  // Burn off the 16 bytes for now
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this

  PVOID pCEditorScene0; // ptr to CEditorScene
  PVOID pCEditorScene1; // ptr to CEditorScene (same as above)

  float unk3;

  PVOID pOctree0;
  u32 unk4;             // 0
  */
};
