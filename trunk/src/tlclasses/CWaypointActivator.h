#pragma once

#include "CPositionableObject.h"

// Size?: 0F0h
//
struct CWaypointActivator : CPositionableObject
{
  // TODO use below

  /*
  PVOID vtable;
  u32 unk0;
  u64 guid0;      // 88F1C7449B211DFh
  u64 guid1;      // 0FFFFFFFFFFFFFFFFh
  u64 guid2;      // 19463565308B11DEh
  u64 guid3;      // 0F61AC062B9FC11DEh

  PVOID unk1;
  PVOID pCWaypointDescriptor;

  // UNICODE          // PlayerPlaysCorruption
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this
  // --

  PVOID pCEditorScene0; // ptr to CEditorScene
  PVOID pCEditorScene1; // ptr to CEditorScene (same as above)

  float unk3;           // 1

  PVOID pCResourceManager;
  u32 unk5;             // 0

  // UNICODE 2        // special_powerup_loop
  union {
    wchar_t name2[8];    // In-place unicode data
    PVOID namePtr2[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength2;
  u32 maxNameLength2;    // Guess, double check this
  // --

  u32 unk6[4];
  */
};
