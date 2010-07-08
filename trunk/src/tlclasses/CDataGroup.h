#pragma once

#include "CRunicCore.h"
#include "CDataValue.h"
#include "CDataGroup.h"

namespace TLAPI
{

#pragma pack(1)

  struct CDataGroup : CRunicCore
  {
    u32     unk0;
    u32     unk1;         // 3211h
    PVOID   unk2;

    CList<CDataValue*>    listDataValues;
    CList<CDataGroup*>    listDataGroups;

    CDataGroup*           unk3;
  };

#pragma pack()

};
