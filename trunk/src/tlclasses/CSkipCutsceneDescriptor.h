#pragma once

// Size: Unknown, listing interesting data, member count is not correct
struct CSkipCutsceneDescriptor
{
  PVOID vtable;
  u32 unk0;

  u64 guid0;      // 92D33FB549DE11DFh
  u64 guid1;      // 0FFFFFFFFFFFFFFFFh
  u64 guid2;      // 92D33FB549DE11DFh
  u64 guid3;      // 0

  PVOID unk1;

  u32 unk2;     // 0

  float unk3;   // -24.9444

  PVOID unk4;   // float* to 8 float values

  float unk5[3];    // 0.694, -0.519, -2.928

  u32 unk6[2];    // 0, 7

  PVOID pCEditorScene0;

  float unk7[3];    // 0,0,-24.783

  // UNICODE --   "Skip Cutscene"
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this
  // --

  u32 unk8;             // 0

  // UNICODE --   "watches the esc key to skip cut scene"
  union {
    wchar_t name2[8];    // In-place unicode data
    PVOID namePtr2[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength2;
  u32 maxNameLength2;    // Guess, double check this
  // --

  u32 unk9;             // 0

  // UNICODE --   "skipcutscene"
  union {
    wchar_t name3[8];    // In-place unicode data
    PVOID namePtr3[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength3;
  u32 maxNameLength3;    // Guess, double check this
  // --
  
  float unk10;    // 1.0

  // UNICODE --   "Logic"
  union {
    wchar_t name4[8];    // In-place unicode data
    PVOID namePtr4[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength4;
  u32 maxNameLength4;    // Guess, double check this
  // --

  u32 unk11[2];

  float unk12[5];

  PVOID unk13;

  u32 unk14;          // 2

  PVOID* ppCDescriptorProp;   // ptr ptr to CDescriptorProp

  u32 unk15[3];       // 2, 0Ah, 0Ah

};
