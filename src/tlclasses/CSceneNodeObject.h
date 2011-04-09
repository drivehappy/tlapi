#pragma once

#include "_CString.h"
#include "CEditorBaseObject.h"
//#include "CResourceManager.h"

namespace TLAPI
{

#pragma pack(1)

  struct CResourceManager;

  struct CSceneNodeObject : CEditorBaseObject
  {
    PVOID pAnimationTrack;        // ptr to Ogre Animation Track
    PVOID pCParticleTechWrapper;  // ptr to Particle Tech Wrapper

    // "Base Glow", Also contains CPlayer's class name
    // i.e. "Destroyer"
    wstring name;
    
    PVOID pCEditorScene0;
    PVOID pCEditorScene1;

    PVOID pSharedMaterialPtr;     // ptr to Ogre shared mat ptr

    Ogre::Node            *pOctreeNode_Inventory;
    Ogre::Entity          *pShadowCaster;                  // NULL
    CResourceManager      *pCResourceManager;
    Ogre::Node            *pOctreeNode_World;
    Ogre::SceneManager    *pOctreeSM;              // ptr to Octree SM


    //
    wstring* GetName()
    {
      DWORD SceneNodeObject_GetName = 0x481CA0;

      __asm {
        call SceneNodeObject_GetName
      }
    }

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
      log("  pCResourceManager: %p", pCResourceManager);
      log("  pOctreeSM: %p", pOctreeSM);
    }
  };

#pragma pack()

};

