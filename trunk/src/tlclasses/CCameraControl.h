#pragma once

#include "CRunicCore.h"

struct CCameraControl : CRunicCore
{
  PVOID unk0;

  PVOID   pOctreeCamera0;     // Ogre
  PVOID   pOctreeCamera1;     // Ogre
  PVOID   pOctreeCamera2;     // Ogre
  PVOID   pOctreeCamera3;     // Ogre
  PVOID   pOctreeCamera4;     // Ogre


  float unk1[8];              //  
                              /*
                              debug157:0C572724 dd 28.5
                              debug157:0C572728 dd 12.3975
                              debug157:0C57272C dd 18.596251
                              debug157:0C572730 dd -12.3975
                              debug157:0C572734 dd 0.0
                              debug157:0C572738 dd 32.468769
                              debug157:0C57273C dd 0.29999989
                              debug157:0C572740 dd 96.872528
                              */

  // Unk rest, 0's - either u32 or floats if they're part of it
};
