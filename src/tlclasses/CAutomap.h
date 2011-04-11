#pragma once

#include "CRunicCore.h"

namespace TLAPI
{

  struct CAutomap;

  TLFUNC(Automap_AddBillboard,                  void,     __thiscall, (CAutomap*, u32, float*, Vector3*, u32, u32));

#pragma pack(1)

  struct CAutomap : CRunicCore
  {
    u32                 unk0;
    CResourceManager   *pCResourceManager;
    Ogre::SceneManager *sceneManager;
    Ogre::BillboardSet *billboardSet0;
    Ogre::BillboardSet *billboardSet1;
    Ogre::Node         *octreeNode0;
    Ogre::Node         *octreeNode1;
    Ogre::Camera       *octreeCamera;

    PVOID               unk1;

    Ogre::Viewport     *viewport;
    float               rect[4];    // 30, 200, 800, 600

    u32                 unk2[3];

    float               unk3[3];    // 100, 80, -112

    //
    // Adds a billboard - just hooking this to stop a bug occuring when this = NULL
    //  - Usually crashes when client or server try to load first try
    EVENT_DECL(CAutomap, void, Automap_AddBillboard,
      (CAutomap*, u32, float*, Vector3*, u32, u32, bool&),
      ((CAutomap*)e->_this, Pz[0], (float*)Pz[1], (Vector3*)Pz[2], Pz[3], Pz[4], e->calloriginal));


  };

#pragma pack()

};

