#pragma once

#include "CRunicCore.h"

// Size?: 34h
struct CTimelineProperty : CRunicCore
{
  u32 unk0;

  u64 guid0;      // 0A59E390749D811DFh

  u32 unk1[3];

  float unk2;     // 1

  PVOID pCEditorScene;
  PVOID pCUnitTriggerDescriptor;

  u32 unk3;

  PVOID pStringUnk;

  u32 unk4;
};
