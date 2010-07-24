#pragma once

#include "CRunicCore.h"
#include "CRoomPieceDataInformation.h"

namespace TLAPI {

#pragma pack(1)

  struct CRoomPieceData : CRunicCore
  {
    u32 unk0;

    // ----

    CRoomPieceCoreData    *pCRoomPieceCoreData;

    u32 unk1;

    u64 GUID;
  };

#pragma pack()

};

