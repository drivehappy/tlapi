#pragma once

#include "_CList.h"

struct CRandomizer : CRunicCore
{
  CRandomizer     *pCRandomizer;

  CList<PVOID>   UnkList2;
  CList<PVOID>   UnkList3;

  u32 unk4[7];

  CDataGroup           *pCDataGroup;
  CList<CDataGroup *>   CDataGroupList;

};
