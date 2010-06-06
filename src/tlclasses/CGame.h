#pragma once

#include "CRunicCore.h"

struct CGame : CRunicCore
{
  PVOID   unk0;

  PVOID   vtable_OgreFrameListener;
  PVOID   vtable_OgreWindowEventListener;
  PVOID   vtable_iEditorResourceManager;
  PVOID   vtable_OgreRenderQueue;
  PVOID   vtable_RenderTargetListener;

  CCameraControl   *pCCameraControl;

  PVOID   unk2;

  PVOID  *pOctreeSM[6];    // Ogre -- why 6 SceneManagers?

  PVOID  *pViewportOgre;    // Ogre
  PVOID  *pString;          // Points to (-8) of a CString struct non-wide

  u32     unk3;
  CString UnkString;

  u32     unk4[6];

  CSettings     *pCSettings;
  CSoundManager *pCSoundManager;

  u32 unk5[2];
  CString   UnkString2;


}
