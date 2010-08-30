#pragma once

#include "_CList.h"
#include "CLevelTemplateData.h"

namespace TLAPI
{

#pragma pack(1)

  //
  struct CDungeon : CRunicCore
  {
    PVOID unk0;

    CList<CLevelTemplateData*>     CLevelTemplateDataList;
    CList<PVOID>                   UnkList0;
    CList<PVOID>                   UnkList1;

    u32 unk2;

    wstring name0;    // "MAIN", "HATCHCAVE", "TOWN", "RANDOMDUNGEON"

    wstring name1;    // "Forsaken Caverns", ""

    u32   unk3[4];

    wstring name2;    // "Town"

    u32   unk4;

    
    void dumpDungeon() {
      log("Dungeon Dump (%p):", this);
      log(L"  name0: %s", name0.c_str());
      log(L"  name1: %s", name1.c_str());
      log(L"  name2: %s", name2.c_str());
    }

  };

#pragma pack()

};
