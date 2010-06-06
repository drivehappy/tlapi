#pragma once

#include "CSceneNodeObject.h"

// Size: 68h
// Inheritance: CSceneNodeObject
#pragma pack(1)
struct CPositionableObject : CSceneNodeObject
{
  /*
  CLevel              *pCLevel;
  CHierarchy          *pCHierarchy;
  CList<CGameClient*>  pCGameClient;

  PVOID                pOgreMaterial;
  */

  u32 unk10;

  float unk11[31];

  PVOID pSharedPtrMaterial;     // ogre


  void dumpPosObj()
  {
    log("CPositionableObject Dump: %p (size: %i)", this, sizeof(CPositionableObject));
    log("  pSharedPtrMaterial: %p", pSharedPtrMaterial);
  }
};
#pragma pack()
