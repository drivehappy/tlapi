#pragma once

#include "CSceneNodeObject.h"

namespace TLAPI
{

#pragma pack(1)

  // CPositionableObject size = 0xF0
  struct CPositionableObject : CSceneNodeObject
  {
    u8 unkPositionable[4];

    Vector3 position;             // @0xF4
    float unk2000[3];
    float unk11[25];              // 5, 11, 17  -- 5 @9C

    PVOID pSharedPtrMaterial;     // ogre

    //
    void dumpPosObj()
    {
      log("CPositionableObject Dump: %p (size: %i)", this, sizeof(CPositionableObject));
      log("  pSharedPtrMaterial: %p", pSharedPtrMaterial);

      log("  Position: %f, %f, %f", position.x, position.y, position.z);

      log("  unkPositionable: %x", unkPositionable[0]);

      log("  unk2000:");
      for (u32 i = 0; i < 6; i++)
        log("    %i: %f", i, unk2000[i]);

      log("  unk11:");
      for (u32 i = 0; i < 25; i++)
        log("    %i: %f", i, unk11[i]);
    }
  };

#pragma pack()

};

