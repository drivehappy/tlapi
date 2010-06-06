#pragma once

// Size: Unknown
// Inheritance: CPositionableObjectDescriptor
struct CAffectorDescriptor : CPositionableObjectDescriptor
{
  // TODO FIX INHERITANCE MEMBERS

  PVOID vtable;
  u32 unk0;
  u64 guid0;                // 88F20B649B211DFh
  u64 guid1;                // 0FFFFFFFFFFFFFFFFh
  u64 guid2;                // 88F20B649B211DFh

  u32 unk0[5];              // 0,0,0,0,0

  PVOID unk1;               // ptr to unk struct
  PVOID unk2;               // ptr to unk struct

  u32 unk3[4];

  PVOID pCEditorScene;      // ptr to CEditorScene
  u32 unk4;                 // 0

  PVOID unk5;
  u32 unk6;                 // 0

  PVOID pStringTextureRot;  // ptr string "Texture Rotate"

  u8 unk7[24];              // weird unicode string

  PVOID pStringBasic;       // ptr string "This is a basic accelerator for your particles"
};
