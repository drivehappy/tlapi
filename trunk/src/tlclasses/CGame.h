#pragma once

#include "_CString.h"
#include "CRunicCore.h"
#include "CCameraControl.h"
#include "CSoundManager.h"
#include "CSettings.h"

namespace TLAPI
{

#pragma pack(1)

  // Forward decls
  //struct CGame;
  //TLFUNC(Game_CreateUI, void, __thiscall, (CGame*));


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


    // 
    // Function hooks
    EVENT_DECL(CGame, void, Game_CreateUI,
      (CGame*),
      ((CGame*)e->_this));

  };

#pragma pack()

};
