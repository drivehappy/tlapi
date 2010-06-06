#pragma once

// Size?: 144h
struct CPathController : CPositionableObject
{
  // TODO - Use below, mostly CPosObj struct though

  /*
  PVOID vtable;
  u32 unk0;

  u64 guid0;    // 0CB13E6E049CB11DFh
  u64 guid1;    // 0CB13E60949CB11DFh
  u64 guid2;    // 0CB757DA0BB7F11DEh
  u64 guid3;    // 0

  float unk1;   // 524288.0 ? maybe

  PVOID pCPathControllerDescriptor;

  u32 unk2;

  // Unicode string again from CItem
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check 

  PVOID pCEditorScene;
  PVOID unk3;

  float unk4;   // -0.5

  PVOID pOctree0;

  float unk5;   // 0.0

  PVOID pCResourceManager;

  u32 unk6;   // 0

  PVOID pOctree1;

  float unk7;   // 0.5

  PVOID unk8;

  float unk9[37]; // List of floats?

  ///
  PVOID pStringMonsters;    // ptr string = "MONSTERS"

  float unk10[14];  //
  */
};
