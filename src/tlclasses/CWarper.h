#pragma once

// Size?: 118h
struct CWarper : CPositionableObject
{
  // TODO use below

  /*
  PVOID vtable;
  u32 unk0;

  u64 guid0;  // 0A83F79FE49D311DFh
  u64 guid1;  // 0A83F75CD49D311DFh
  u64 guid2;  // 0CDEFB2A8BB7F11DEh
  u64 guid3;  // 0

  PVOID unk1;

  PVOID pCWarperDescriptor;

  u32 unk2;

  PVOID pStringWarperMain;    // ptr string = "WarperMain"

  u32 unk3[5];

  PVOID pCEditorScene0;
  PVOID pCEditorScene1;   // same as above

  float unk4;     // -0.5

  PVOID pOctree0;

  float unk5;     // 0

  PVOID pCResourceManager;

  float unk6;     // 0

  PVOID pOctree1;

  u32 unk7[36];

  u32 unk8;

  // UNICODE STRING from CItem
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this
  */
};
