#pragma once

// Size?: A4h
struct CLevelState : CRunicCore
{
  u32 unk0[3];    // 0,1,0

  // Probably same old UNICODE union...
  union {
    wchar_t name[8];    // In-place unicode data
    PVOID namePtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 nameLength;
  u32 maxNameLength;    // Guess, double check this

  PVOID unk1;
};
