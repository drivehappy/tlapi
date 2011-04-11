#pragma once

#include "CSceneNodeObject.h"

namespace TLAPI
{

#pragma pack(1)

  struct CPositionableObject;
  TLFUNC(PositionableObjectSetPosition,         void,         __thiscall, (CPositionableObject*, const Vector3*));
  TLFUNC(PositionableObjectGetPosition,         void,         __thiscall, (CPositionableObject*, Vector3&, bool));

  // CPositionableObject size = 0xF0
  struct CPositionableObject : CSceneNodeObject
  {
    u8 unkPositionable0;
    u8 playerProximity;           // @6D - Activates when close to player
    u8 unkPositionable2;          // @6E - Can activate? used for player aggro
    u8 unkPositionable3;

    Vector3 position;             // @0x70
    float unk2000[3];
    float unk11[25];              //

    PVOID pSharedPtrMaterial;     // ogre

    // Set position
    EVENT_DECL(CPositionableObject, void, PositionableObjectSetPosition,
      (CPositionableObject*, const Vector3*),
      ((CPositionableObject*)e->_this, (const Vector3*)&Pz[0]));

    // Get position
    EVENT_DECL(CPositionableObject, void, PositionableObjectGetPosition,
      (CPositionableObject*, Vector3&, bool),
      ((CPositionableObject*)e->_this, (Vector3&)Pz[0], (bool)Pz[1]));

    // Set near player
    EVENT_DECL(CPositionableObject, void, PositionableObject_SetNearPlayer,
      (CPositionableObject*, bool&, bool&),
      ((CPositionableObject*)e->_this, (bool&)Pz[0], e->calloriginal));



    void SetPosition(const Vector3* position) {
      PositionableObjectSetPosition(this, position);
    }
    Vector3& GetPosition() {
      Vector3 *position = new Vector3();
      PositionableObjectGetPosition(this, *position, true);

      return *position;
    }

    //
    void dumpPosObj()
    {
      log("CPositionableObject Dump: %p (size: %i)", this, sizeof(CPositionableObject));
      log("  pSharedPtrMaterial: %p", pSharedPtrMaterial);

      log("  Position: %f, %f, %f", position.x, position.y, position.z);

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

