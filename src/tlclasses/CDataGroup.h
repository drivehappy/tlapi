#pragma once

#include "CDataValue.h"

struct CDataGroup : CRunicCore
{
  u32 unk0;
  u32 unk1;             // 3211h
  PVOID unk2;
  PVOID pCDataValues;   // Probably: CList<CDataValue*>
  u32 unk3, unk4, unk5; // All contain the above size for the vector
};
