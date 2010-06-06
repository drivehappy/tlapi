#pragma once

#include "CEditorBaseObject.h"
#include "_CString.h"

// Size?: 5Ch
// Inheritance: CEditorBaseObject
#pragma pack(1)
struct CSceneNodeObject : CEditorBaseObject
{
  PVOID pAnimationTrack;        // ptr to Ogre Animation Track
  PVOID pCParticleTechWrapper;  // ptr to Particle Tech Wrapper

  PVOID unk0;

  CString name;        // ptr string "Base Glow", Also contains CPlayer's class name
  
  //u32 unk4[5];

  //PVOID pCLayout;               // ptr to CLayout
  //PVOID pCLayout;               // ptr to CLayout (same layout as above)
  PVOID pCEditorScene0;
  PVOID pCEditorScene1;

  PVOID pSharedMaterialPtr;     // ptr to Ogre shared mat ptr

  PVOID pOctreeNode0;
  PVOID pUnk5;                  // NULL
  PVOID pCResourceManager;
  PVOID pOctreeNode1;

  PVOID pOctreeSM;              // ptr to Octree SM


  //
  void dumpSceneNodeObject()
  {
    log("CSceneNodeObject: %p (size: %i) (sizeof CString: %i)", this, sizeof(CSceneNodeObject), sizeof(CString));
    log("  pAnimationTrack = %p", pAnimationTrack);
    log("  pCParticleTechWrapper = %p", pCParticleTechWrapper);
    //log(L"  name = %s", name);
    log("  pCEditorScene0: %p", pCEditorScene0);
    log("  pCEditorScene1: %p", pCEditorScene1);
    log("  pSharedMaterialPtr: %p", pSharedMaterialPtr);
    log("  pOctreeNode0: %p", pOctreeNode0);
    log("  pUnk5: %p", pUnk5);
    log("  pCResourceManager: %p", pCResourceManager);
    log("  pOctreeSM: %p", pOctreeSM);
  }
};
#pragma pack()
