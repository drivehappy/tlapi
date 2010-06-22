#pragma once

#include "Common.h"

#include "CCameraControl.h"
#include "CSoundManager.h"
#include "CSettings.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CQuestManager.h"
#include "CLevel.h"
#include "CGameUI.h"

#include <vector>
using std::vector;


namespace TLAPI
{

  // 
  struct CGameClient : CRunicCore
  {
    PVOID vtableOgre_RenderTargetListener;
    PVOID vtableOgre_RenderQueue_RenderableListener;

    CCameraControl     *pCCameraControl;

    PVOID               pOctreeSM0;
    PVOID               pOctreeSM1;
    PVOID               pOctreeSM2;
    PVOID               pOctreeSM3;
    PVOID               pOctreeSM4;

    CSoundManager      *pCSoundManager;
    CSettings          *pCSettings;
    CPlayer            *pCPlayer;
    CMonster           *pPet;

    CQuestManager      *pCQuestManager;
    CLevel             *pCLevel;
    CGameUI            *pCGameUI;

    u32                 unkChunk[997];
    s32                 level;

    // 
    // Function hooks
  private:
    static vector<void (__cdecl *)(CGameClient*, u32)> m_Callback_LoadMap_pre;
    static vector<void (__cdecl *)(CGameClient*, u32)> m_Callback_LoadMap_post;
    
  public:
    void LoadMap(u32 unk);

    void RegisterEvent_LoadMap(void (__cdecl *callbackPre)(CGameClient*, u32),
      void (__cdecl *callbackPost)(CGameClient*, u32))
    {
      m_Callback_LoadMap_pre.push_back(callbackPre);
      m_Callback_LoadMap_post.push_back(callbackPost);
    };

    static void FireEvent_Pre STDARG {
      vector<void (__cdecl *)(CGameClient*, u32)>::iterator itr;
      for (itr = m_Callback_LoadMap_pre.begin(); itr != m_Callback_LoadMap_pre.end(); itr++) {
        (*itr)((CGameClient*)e->_this, Pz[0]);
      }
    };
    static void FireEvent_Post STDARG {
      vector<void (__cdecl *)(CGameClient*, u32)>::iterator itr;
      for (itr = m_Callback_LoadMap_post.begin(); itr != m_Callback_LoadMap_post.end(); itr++) {
        (*itr)((CGameClient*)e->_this, Pz[0]);
      }
    };

    

  };

};
