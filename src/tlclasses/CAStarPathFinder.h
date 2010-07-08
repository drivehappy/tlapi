#pragma once

#include "_CUnknownStruct0.h"

namespace TLAPI
{

#pragma pack(1)

  // Size?: 34h
  // Inheritance: CRunicCore
  struct CAstarPathfinder : CRunicCore
  {
    u32     unk0[5];    // 0, 0, 0, 0, 0

    PVOID   unk1;

    u32     unk2[3];    // 610000h,2 dup(   0)

    float   unk3;       // 0.4

    u32     unk4;       // 268FEh, 

    CUnknownStruct0*  unkData;   // Contains 404 ptrs to u8[800]

    PVOID   unk100;     //
    u32     unk5[4];    // -19.2, 32.4

    u32     unkSize0;   // 240h
    u32     unkSize1;   // 4Ah
    u32     unkSize2;   // 28D9Dh

    u32     unk6[4];    // 40h, 0

    CString unkString;  // nulled

    u32     unk7[5];    // 0, 77D89E00h, 8Bh, 0, 0

    float   unk8[4];    // -10000.0,2 dup( 10000.0), 0.0

    u32     unk9[3];    //  1,2 dup(   0)

    float   unk10[4];   // 3 dup( 5000.0), 0.0

    PVOID   unk11;

    u32     unk12[6];   // 0's

    u32     unk13[7];   // 0, 7, ptrs..., 0, 0

    float*  bounds;     // ptr to 6 floats
    u32     unk14;

    PVOID   pOctreeSM;


  };

#pragma pack()

};
