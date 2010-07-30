#pragma once

#include "Common.h"
#include "Events.h"

#include "CCharacter.h"

namespace TLAPI
{

  //
#pragma pack(1)

  struct CPlayer: CCharacter
  {

    // Character Set Action
    EVENT_DECL(CPlayer, void, PlayerUseSkill,
      (u32, CPlayer*, u64),
      (e->retval, (CPlayer*)e->_this, *(u64*)&Pz[0]));

    
    void dumpPlayer()
    {
      log("CPlayer dump: %p (sizeof CPlayer: %i)", this, sizeof(CPlayer));
      log("  (sizeof CCharacter: %i)", sizeof(CCharacter));
      log("  Gold: %i", gold);
      log(L"  Name: %s", characterName.getString());
      log(L"  Body Texture: %s", playerTextureBody.getString());
      log(L"  Hand Texture: %s", playerTextureHands.getString());
      log(L"  Feet Texture: %s", playerTextureFeet.getString());
      log(L"  Chest Texture: %s", playerTextureChest.getString());
      log("");
      log("  AIManager: %p", pCAIManager);
    }
  };

#pragma pack()

};
