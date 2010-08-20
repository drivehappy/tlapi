#pragma once

#include "CSceneNodeObject.h"

namespace TLAPI
{

#pragma pack(1)

  // CPositionableObject size = 0xF0
  struct CPositionableObject : CSceneNodeObject
  {
    u32 unk10;

    Vector3 position;
    float unk2000[3];
    float unk11[25];

    PVOID pSharedPtrMaterial;     // ogre


    void dumpPosObj()
    {
      log("CPositionableObject Dump: %p (size: %i)", this, sizeof(CPositionableObject));
      log("  pSharedPtrMaterial: %p", pSharedPtrMaterial);

      log("  Position: %f, %f, %f", position.x, position.y, position.z);

      /*
      log("  unk2000:");
      for (u32 i = 0; i < 6; i++)
        log("    %i: %f", i, unk2000[i]);

      log("  unk11:");
      for (u32 i = 0; i < 25; i++)
        log("    %i: %f", i, unk11[i]);
      */
    }
  };

#pragma pack()

};

