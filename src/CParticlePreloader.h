#pragma once

#include "CRunicCore.h"
#include "CResourceManager.h"
#include "CResourceSettings.h"

namespace TLAPI
{

#pragma pack(1)

  struct CParticlePreloader : CRunicCore
  {
    CResourceManager  *pCResourceManager;
    CResourceSettings *pCResourceSettings;
  };

#pragma pack()

};
