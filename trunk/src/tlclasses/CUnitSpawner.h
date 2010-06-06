#pragma once

#include "CShape.h"

// Size?: 1FCh
// Note: Similar structure to CItem
//
struct CUnitSpawner : CShape
{
  // TODO use below

  /*
  PVOID vtable;
  u32 unk0;

  u64 guid0;
  u64 guid1;
  u64 guid2;
  u64 guid3;

  PVOID pAnimationTrack;    // ogre

  PVOID pCUnitSpawnerDescriptor;

  u32 unk1;

  // UNICODE from CItem
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this
  // --

  PVOID pCEditorScene0; // ptr to CEditorScene
  PVOID pCEditorScene1; // ptr to CEditorScene (same as above)

  float unk3;

  PVOID pOctree0;
  u32 unk4;             // 0

  // ---- Possible inheritance breakoff ---


  PVOID pCResourceManager;
  u32 unk5;             // 0

  PVOID pOctree1;

  // ---- End CItem Diff ---

  float unk6[36];

  PVOID pCDynamicAttributeFixed0;   // particleuniverse
  PVOID pCDynamicAttributeFixed1;   // particleuniverse
  PVOID pCDynamicAttributeFixed2;   // particleuniverse
  PVOID pCDynamicAttributeFixed3;   // particleuniverse

  float unk7[9];

  // ------ Inheritance cutoff -----

  PVOID vtableIRandomWeight;
  PVOID vtableIUnitObserver;

  u32 unk8[2];

  float unk9[13];

  PVOID pStringMonsters;      // ptr string "Monsters"

  u32 unk10[6];

  // UNICODE from CItem
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this
  // --

  float unk11[7];

  u32 unk12[15];
  */
};
