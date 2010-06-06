#pragma once

#include "CCameraControl.h"
#include "CSoundManager.h"
#include "CSettings.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CQuestManager.h"
#include "CLevel.h"
#include "CGameUI.h"

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
};
