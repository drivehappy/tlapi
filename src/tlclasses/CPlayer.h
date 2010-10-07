#pragma once

#include "Events.h"
#include "CCharacter.h"

namespace TLAPI
{

  //
#pragma pack(1)

  struct CPlayer: CCharacter
  {
    CAIManager    *pCAIManager;

    // Character Set Action
    EVENT_DECL(CPlayer, void, PlayerUseSkill,
      (u32, CPlayer*, u64),
      (e->retval, (CPlayer*)e->_this, *(u64*)&Pz[0]));

    
    void dumpPlayer()
    {
      log("CPlayer dump: %p (sizeof CPlayer: %i)", this, sizeof(CPlayer));
      log("  (sizeof CCharacter: %i)", sizeof(CCharacter));
      log("  Gold: %i", gold);
      log(L"  Name: %s", characterName.c_str());
      log(L"  Body Texture: %s", playerTextureBody.c_str());
      log(L"  Hand Texture: %s", playerTextureHands.c_str());
      log(L"  Feet Texture: %s", playerTextureFeet.c_str());
      log(L"  Chest Texture: %s", playerTextureChest.c_str());
      log("");
      //log("  AIManager: %p", pCAIManager);
    }
  };

#pragma pack()

};
