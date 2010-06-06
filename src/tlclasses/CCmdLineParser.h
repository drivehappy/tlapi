#pragma once

#include "CRunicCore.h"

struct CCmdLineParser : CRunicCore
{
  PVOID   unk0;

  PVOID   *ptrtomyself;   // Cyclic ptr to myself
};
