#pragma once

// Include so we don't have to on every other file
#include "Common.h"

/** This is the base class of most Torchlight classes. */
namespace TLAPI {

#pragma pack(1)

  struct CRunicCore : Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<Ogre::MEMCATEGORY_GENERAL>>
  {
    PVOID vtable;
  };

#pragma pack()

};

