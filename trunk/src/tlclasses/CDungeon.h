#pragma once

#include "_CList.h"

// Size?: 
// 
struct CDungeon : CRunicCore
{
  PVOID unk0;

  CList<CTemplateLevelData *>    CTemplateLevelDataList;
  CList<PVOID>                   UnkList0;
  CList<PVOID>                   UnkList1;

  float unk1;
  u32 unk2;

  CString name0;    // "HATCHCAVE"

  CString name1;    // "Forsaken Caverns"

  u32 unk3[5];

  CString name2;    // "Town"

  

};
