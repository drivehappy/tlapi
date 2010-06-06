#pragma once

// Size?:
// 
struct CGameGlobals : CRunicCore
{
  PVOID unk0;
  PVOID unk1;

  CString filename;   // "media/globals.dat"

  u32 unk2[3];        // 1388h, 78h, 12h
  float unk3[3];      // 6.5, 12.0, 36.0

  u32 unk4[7];        // 1,2,3,5,7,0Ah,14h

  // Unk rest
};
