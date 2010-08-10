#pragma once

#include "CRunicCore.h"

namespace TLAPI {

#pragma pack(1)

  // Size?: 118h
  struct CItemSaveState : CRunicCore
  {
    u32 unk0;

    wstring name;
    wstring name2;
    wstring name3;

    u32 unk1[1];

    u64 guid3;
    u64 guid2;
    u64 guid0;
    u64 guid1;

    u32 unk3[2];

    u32 slot;

    u32 unk2[30];


    void dumpItemSaveState()
    {
      log("ItemSaveState (%p)", this);
      log(L"  name: %s", name.c_str());
    };
  };

#pragma pack()

};
