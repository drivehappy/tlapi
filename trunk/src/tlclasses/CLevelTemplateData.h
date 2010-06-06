#pragma once

// Size?: 0E8h (Base?)  + some
struct CLevelTemplateData : CRunicCore
{
  u32 unk0;
  PVOID unk1;

  u32 unk2[3];      // 1, Ah, Ah

  PVOID unk3;

  u32 unk4[16];

  PVOID pStringMainMenumine;  // ptr string "MAINMENUMINE"

  u32 unk5[11];

  float unk6[4];

  u32 unk7[8];

  float unk8[3];      // 1,1,0

  PVOID* ppCLevelLayout0; // ptr ptr CLevelLayout

  u32 unk9[3];       // 1, Ah, Ah

  PVOID* ppCLevelLayout1; // ptr ptr CLevelLayout

  u32 unk10[3];       // 1, Ah, Ah

  // --------- Base type breakoff -----------

  PVOID pCRandomizer;
};
