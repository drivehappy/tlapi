#pragma once

#include "CRunicCore.h"
#include "CStringTranslate.h"
#include "CGameGlobals.h"
#include "CUnitThemes.h"
#include "CRecipes.h"
#include "CSets.h"
#include "CCinematics.h"
#include "CGameSpeed.h"
#include "CRoomPieceDataInformation.h"
#include "CEffectGroupManager.h"

namespace TLAPI {

#pragma pack(1)

  struct CMasterResourceManager;
  TLFUNC(GetMasterResourceManager, CMasterResourceManager*,__thiscall, (void));

  //
  struct CMasterResourceManager : CRunicCore
  {
    PVOID unk0;
    CStringTranslate            *pCStringTranslate;        // ptr to CStringTranslate
    CGameGlobals                *pCGameGlobals;            // ptr to CGameGlobals
    CUnitThemes                 *pCUnitThemes;             // ptr to CUnitThemes
    CRecipes                    *pCRecipes;                // ptr to CRecipes
    CSets                       *pCSets;                   // ptr to CSets
    CCinematics                 *pCCinematics;             //

    // Todo later - setup the rest
    PVOID unk1;                     // ptr to unknown structure
    PVOID pCGraphManager;           //
    PVOID pCDungeonManager;
    CEffectGroupManager *pCEffectGroupManager;
    PVOID pCMissilePreloader;
    PVOID pCResourceSettings;
    PVOID pCSkillParser;
    PVOID pCSpawnClassParser;
    PVOID pCHeirarchy;
    PVOID pCUnitResourceList;
    PVOID pCSettings;
    PVOID pCSoundManager;
    PVOID unk2;
    CGameSpeed                  *pCGameSpeed;
    PVOID unk3;
    PVOID pCFileSystem;
    
    u32 unk4;

    Ogre::SceneManager          *pOctreeSM0;
    Ogre::SceneManager          *sceneManagerPlayerInventory;   // @68h
    Ogre::SceneManager          *sceneManagerPetInventory;      // @6Ch
    Ogre::SceneManager          *pOctreeSM3;

    CRoomPieceDataInformation   *pCRoomPieceDataInformation;

    PVOID pParticleSystemManager;   // ParticleUniverse
    PVOID pCParticlePreloader;

    PVOID pCSoundBankDataInformation;

    PVOID *tomyself;
    


    static CMasterResourceManager* getInstance() {
      return GetMasterResourceManager();
    }
  };

#pragma pack()

};

