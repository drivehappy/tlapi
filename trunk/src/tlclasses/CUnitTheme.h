#pragma once

#include "CRunicCore.h"

struct CUnitTheme : CRunicCore
{
  PVOID     unk0;

  CList<CUnitThemeParticle *>  ParticlesList;

  _CString  name;     // "ARMORDEBUFF"
  u32       unk1;
  u64       guid;     // 5F53DD44942A11DEh defined in: ARMORDEBUFF.dat

  float     unk2;     // 26121.625
  u32       unk3;     // 4Bh
};
