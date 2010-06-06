#pragma once

#include "DataTypes.h"

#include "_CString.h"
#include "CItemSaveState.h"


// Size: 200h
// Inheritance: CRunicCore
struct CCharacterSaveState : CRunicCore
{
  u32 unk0;
  u64 guid0;  // 51D9A040C33711DEh
  u64 guid1;  // 81065BD0B793A300h
  u64 guid2;  // 0D3A8F9982FA111DEh
  u64 guid3;  // 0FFFFFFFFFFFFFFFFh

  u32 unk1[2];
  float unk2;
  float unk3;
  
  CString name;                 // "Drivehappy"

  u32 unk6[9];                  // 1, 0, 4 dup (FFFFFFFFh), 302DBE98h, 1, 22h

  Vector3 position;
  Vector3 unkPosition;

  float unk7[13];               // 

  u64 guid4;  // 6B0351E39E3311DEh
  u64 guid5;  // 6B0351E39E3311DEh
  u64 guid6;  // 0FFFFFFFFFFFFFFFFh

  // ... more

  float unk90[18];  //

  CString unk91;    // "HEAL ALL"

  PVOID unk92;    // "TOWN PORTAL"

  float unk93[6];

  PVOID unk94;    // "SUMMON ZOMBIES III"

  float unk95[6];

  PVOID unk96;     // "HEAL SELF IV"

  float unk97[3];

  u32 unk98[24];

  PVOID pCOctreeSM;
  CItemSaveState** itemSaveState;

  PVOID unk99[2];

  float unk100[2];      // 0.5 0.5
};
