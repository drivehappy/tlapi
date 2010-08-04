#include "Test.h"
#include "TestUserInterface.h"

CEquipment* SearchForEquipment(const wchar_t* searchTerm)
{
  if (gameClient == NULL) {
    log("gameClient is null, cannot proceed");
    return NULL;
  }

  CList<CEquipmentRef*> *list = &gameClient->pCPlayer->pCInventory->equipmentList;

  /*
  for (u32 i = 0; i < list->size; i++) {
    wchar_t *equipmentName = (*list)[i]->pCEquipment->nameReal.getString();

    int val = wcscmp(equipmentName, searchTerm);

    if (val == 0) {
      return (*list)[i]->pCEquipment;
    }
  }
  */

  return NULL;
}

//
// This function is used for testing via keyboard inputs
//
void Test_WndProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{
  if (!(msg == 0x100 || msg == 0x101 || msg == 0x102 || msg == 0x201))
    return;

  switch (msg) {
  case WM_LBUTTONDOWN:
    switch (wParam) {
    case MK_LBUTTON:
      {
        //gameClient->CMouseManager.dumpMouse();
      }
      break;
    }
  case WM_KEYUP:
    break; // Skip keyboard

    switch (wParam) {

    // 9 =
    case '9':
      {
        log("GameClient(5p) size: %i, Dungeon: %p", gameClient, sizeof(CGameClient), gameClient->pCDungeon);
        gameClient->pCDungeon->dumpDungeon();

        u32 offset = ((u32*)&gameClient->pCLayout - (u32*)gameClient);
        if (gameClient->pCLayout) {
          log("  CLayout: (@: %p) %p (offset: %x)", &gameClient->pCLayout, gameClient->pCLayout, offset);
          log(L"    DescriptorManager: (@ %p) %p", &gameClient->pCLayout->pCDescriptorManager, gameClient->pCLayout->pCDescriptorManager);
          log(L"    Location: %s", gameClient->pCLayout->location.c_str());
        }

        /*
        log("UnkChunk3 GameClient:");
        for (u32 i = 0; i < 1300; i++) {
          log("  unkChunk3[%i] = %x", i, gameClient->unkChunk3[i]);
        }*/
      }
      break;

    // 8 = 
    case '8':
      {
        log("gameClient: %p", gameClient);
        gameClient->CMouseManager.dumpMouse();
      }
      break;

    // 7 = Item Creation
    case '7':
      {
        if (!resManager) {
          log("Error: ResourceManager is not initialized!");
          break;
        }

        log("Creating Chaos Gem...");
        u64 chaosGem = 0xEF8CFF367B0711DE;
        Vector3 position = gameClient->pCPlayer->position;
        CEquipment *equipmentGem0 = resManager->CreateEquipment(chaosGem, 1, 0, 0);
        CEquipment *equipmentGem1 = resManager->CreateEquipment(chaosGem, 1, 0, 0);
        equipmentGem0->AddEnchant(FASTER_ATTACK, NONE, 1000);
        equipmentGem1->AddEnchant(REGULAR, PHYSICAL, 1337);

        log("Creating Bishop Axe...");
        u64 bishopAxe = 0x764ECFC83F3D11De;
        CEquipment *equipmentBishopAxe = resManager->CreateEquipment(bishopAxe, 1, 0, 0);
        equipmentBishopAxe->socketCount = 2;
        equipmentBishopAxe->gemList.push(equipmentGem0);
        equipmentBishopAxe->gemList.push(equipmentGem1);

        equipmentBishopAxe->pCAttackDescriptor0->damageMaximumPhysical0 = 300;
        equipmentBishopAxe->pCAttackDescriptor0->damageMaximumPhysical1 = 300;
        equipmentBishopAxe->pCAttackDescriptor1->damageMaximumPhysical0 = 600;
        equipmentBishopAxe->pCAttackDescriptor1->damageMaximumPhysical1 = 600;

        equipmentBishopAxe->pCAttackDescriptor0->attackSpeed = 2;
        equipmentBishopAxe->pCAttackDescriptor1->attackSpeed = 2;
        
        resManager->pCLevel->EquipmentDrop(equipmentBishopAxe, position, 0);
        log("Done: Axe %p (Gems = %i)", equipmentBishopAxe, equipmentBishopAxe->gemList.size);
      }
      break;

    // 6 = Add equipment sockets
    case '6':
      {
        const wchar_t searchTerm[] = L"Rickety Pistol"; //L"Rock Grotesque";
        log(L"Adding socket to Player Equipment (%s)", searchTerm);
        
        CEquipment *equipment = SearchForEquipment(searchTerm);
        if (equipment) {
          log(L"Attempting to socket %s", equipment->nameReal);

          equipment->socketCount += 1;

          log("Socket done.");
        }
      }
      break;

    // 5 = Add gold to player and dump player
    case '5':
      {
        gameClient->pCPlayer->gold += 100000;
        gameClient->pCPlayer->dumpPlayer();
      }
      break;

    // 4 = Attempt to add FasterAttackSpeed modifier to equipment
    case '4':
      {
        const wchar_t searchTerm[] = L"Rickety Pistol"; //L"Rock Grotesque";
        log(L"Adding other modifier Player Equipment (%s)", searchTerm);
        
        CEquipment *equipment = SearchForEquipment(searchTerm);
        if (equipment) {
          log(L"Attempting to change %s", equipment->nameReal);

          //equipment->AddEnchant(UNKNOWN, NONE, 1);
          equipment->AddEnchant(REGULAR, PHYSICAL, 100);
          equipment->AddEnchant(REGULAR, MAGICAL, 5);
          equipment->AddEnchant(KNOCKBACK, NONE, 8);
          equipment->AddEnchant(FASTER_CAST_SPEED, NONE, 9);
          
          log("Change done.");
        }
      }
      break;

    // 3 = Attempt to add magic modifier to equipment
    case '3':
      {
        const wchar_t searchTerm[] = L"Rickety Pistol"; //L"Rock Grotesque";
        log(L"Adding magic modifier Player Equipment (%s)", searchTerm);
        
        CEquipment *equipment = SearchForEquipment(searchTerm);
        if (equipment) {
          // We found it, dump it
          log(L"Attempting to change %s", equipment->nameReal);
          equipment->AddMagicModifier(PHYSICAL, 100);
          log("Change done.");
        }
      }
      break;

    // 2 = Attempt to auto enchant equipment
    case '2':
      {
        const wchar_t searchTerm[] = L"Rickety Pistol"; //L"Rock Grotesque";
        log(L"Enchanting Player Equipment (%s)", searchTerm);
        
        CEquipment *equipment = SearchForEquipment(searchTerm);
        if (equipment) {
          // We found it, dump it
          log(L"Attempting to enchant %s", equipment->nameReal);
          u32 retVal = equipment->Enchant(0, 0, 5);
          log("Enchantment done.");
        }
      }
      break;

    // 1 = Dump Player Equipment (specificially just named "Rickety Pistol")
    case '1':
      {
        const wchar_t searchTerm[] = L"Rickety Pistol"; //L"Rock Grotesque";
        log(L"Dumping Player Equipment (%s)", searchTerm);
        
        CEquipment *equipment = SearchForEquipment(searchTerm);
        if (equipment) {
          // We found it, dump it
          equipment->dumpEquipment();
          
          // unk1007
          testLogger.WriteLine(Info,
            L"  Equipment(%p) (%s) Dump of unk1007 (enhancementCount = %i):",
            //equipment, equipment->nameReal.getString(), equipment->enhancementCount, searchTerm);
            equipment, equipment->nameReal.c_str(), equipment->enhancementCount, searchTerm);

          for (int j = 0; j < 28; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk1007[j]);
          }

          // unk1010
          for (int j = 0; j < 10; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk1010[j]);
          }

          // unk1006
          testLogger.WriteLine(Info,
            L"  Equipment(%p) (%s) Dump of unk1006 (enhancementCount = %i):",
            //equipment, equipment->nameReal.getString(), equipment->enhancementCount, searchTerm);
            equipment, equipment->nameReal.c_str(), equipment->enhancementCount, searchTerm);

          for (int j = 0; j < 23; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk1006[j]);
          }

          // unk0999
          testLogger.WriteLine(Info,
            L"  Dump of 0999:",
            "");

          for (int j = 0; j < 5; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk0999[j]);
          }

          // unk1002
          testLogger.WriteLine(Info,
            L"  Dump of 1002:",
            "");

          for (int j = 0; j < 5; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk1002[j]);
          }
          
          // unk0998
          testLogger.WriteLine(Info,
            L"  Dump of 0998:",
            "");

          for (int j = 0; j < 3; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk0998[j]);
          }

          // unk1001/1004/1005
          testLogger.WriteLine(Info,
            L"  Dump of 1001/1004: %x %x",
            equipment->unk1001, equipment->unk1004);

          testLogger.WriteLine(Info,
            L"---------------------------",
            "");
        }
      }
      break;

    }  // End switch wParam

  } // End switch msg

}
