#pragma once

#include "_CList.h"

struct CRandomizer : CRunicCore
{
  PVOID unk0;

  CList<PVOID>    UnkList2;   // 0.0
  CList<float>    UnkList3;   // 1.0
  CList<float>    UnkList4;   // 1.0

  u32 unk4[7];

  CDataGroup           *pCDataGroup;
  CList<CDataGroup *>   CDataGroupList;

};
