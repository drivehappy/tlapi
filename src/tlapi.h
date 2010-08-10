#pragma once

#pragma comment(lib, "../externallibs/cegui/lib/CEGUIBase.lib")

#include "Common.h"

#include "_CString.h"
#include "_CList.h"

#include "CRunicCore.h"
#include "CAffix.h"
#include "CEffect.h"
#include "CHierarchy.h"

#include "CEffectManager.h"

#include "CDynamicPropertyFile.h"
#include "CSettings.h"

#include "CEditorBaseObject.h"
#include "CSceneNodeObject.h"
#include "CPositionableObject.h"

#include "CBaseUnit.h"
#include "CItem.h"
#include "CEquipment.h"
#include "CEquipmentRef.h"
#include "CInventory.h"

#include "CLevel.h"
#include "CResourceManager.h"

#include "CSoundObject.h"

#include "CEditorScene.h"
#include "CLayoutScene.h"

#include "CAllDescriptorsScene.h"
#include "CLayout.h"

#include "CDescriptorManager.h"

#include "CCharacter.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CGameClient.h"

#include "Globals.h"

namespace TLAPI {
  
  void Initialize();
  
  void PatchProcess();
  void HookFunctions();

  CGameClient* GetGameClient();

};
