#pragma once

#include "CRunicCore.h"
#include "CRoomPieceDataInformation.h"

// Size?: 08h
struct CRoomPieceData : CRunicCore
{
  u32 unk0;

  // ----

  CRoomPieceCoreData    *pCRoomPieceCoreData;

  u32 unk1;

  u64 GUID;
};
