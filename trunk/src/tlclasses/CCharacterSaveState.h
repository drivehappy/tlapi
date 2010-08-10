#pragma once

#include "DataTypes.h"

#include "_CString.h"
#include "CRunicCore.h"
#include "CItemSaveState.h"


namespace TLAPI
{

#pragma pack(1)

  struct CCharacterSaveState : CRunicCore
  {
    u32 unk0;
    u64 guid0;  // 51D9A040C33711DEh
    u64 guid1;  // 81065BD0B793A300h
    u64 guid2;  // 0D3A8F9982FA111DEh
    u64 guid3;  // 0FFFFFFFFFFFFFFFFh

    u32 unk1[2];
    float unk2;
    //float unk3;
    //CString name;                 // "Drivehappy"
    wstring name;

    u32 unk6[9];                  // 1, 0, 4 dup (FFFFFFFFh), 302DBE98h, 1, 22h

    Vector3 position;
    float   matrix[16];

    u64 guid4;  // 6B0351E39E3311DEh
    u64 guid5;  // 6B0351E39E3311DEh
    u64 guid6;  // 0FFFFFFFFFFFFFFFFh

    // ... more

    float unk90[17];  //

    wstring nameSpell1;
    wstring nameSpell2;
    wstring nameSpell3;
    wstring nameSpell4;

    u32 unk98[11];

    u32 strength;
    u32 dexterity;
    u32 defense;
    u32 magic;
    u32 gold;

    u32 unk99[4];

    u32 unk101[3];

    CItemSaveState** itemSaveStateBegin;
    CItemSaveState** itemSaveStateEnd1;
    CItemSaveState** itemSaveStateEnd2;

    u32 unk100[3];      // 0.5 0.5

    CEffect**         effectListBegin;
    CEffect**         effectListEnd1;
    CEffect**         effectListEnd2;


    //
    // Function Hooks

    // Create Character Save State From File
    EVENT_DECL(CCharacter, void, CharacterSaveState_LoadFromFile,
      (CCharacterSaveState*, PVOID, u32),
      ((CCharacterSaveState*)e->_this, (PVOID)Pz[0], Pz[1]));

  };

#pragma pack()

};
