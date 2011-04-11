#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

#pragma pack(1)

  struct CParticleCache;

  TLFUNC(ParticleCache_Dtor2,                   void,     __thiscall, (CParticleCache*));

  struct CParticleCache : CRunicCore
  {
    u32                            unk0;

    CList<PVOID>                   listParticleSystems; // Not Ogre's, uses ParticleUniverse
    CList<u32>                     unk1;
    CList<u32>                     unk2;
    CList<u32>                     unk3;
    CList<CParticleCache*>        *listParticleCache;
    CList<float>                   unk4;
    CList<float>                   unk5;
    CList<bool>                    unk6;
    CList<u32>                     unk7;

    Ogre::SceneManager            *sceneManager;
    CSoundBank                    *pCSoundBank;


    // 
    // Function hooks

    // Dtor for particle cache
    EVENT_DECL(CParticleCache, void, ParticleCache_Dtor2,
      (CParticleCache*),
      ((CParticleCache*)e->_this));

  };

#pragma pack()

};
