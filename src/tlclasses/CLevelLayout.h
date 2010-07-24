#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  struct CLevelLayout : CRunicCore
  {
    u32 unk0;
    PVOID pChunkList;   // Probably: CList<CChunk*>
  };

#pragma pack()

};
