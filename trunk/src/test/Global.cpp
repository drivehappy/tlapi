#include "Test.h"

CEquipment* SearchForEquipment(const wchar_t* searchTerm)
{
  if (gameClient == NULL) {
    log("gameClient is null, cannot proceed");
    return NULL;
  }

  CList<CEquipmentRef*> *list = &gameClient->pCPlayer->pCInventory->equipmentList;

  for (u32 i = 0; i < list->size; i++) {
    wchar_t *equipmentName = (*list)[i]->pCEquipment->nameReal.getString();
    
    int val = wcscmp(equipmentName, searchTerm);

    if (val == 0) {
      return (*list)[i]->pCEquipment;
    }
  }

  return NULL;
}

//
// This function is used for testing via keyboard inputs
//
void Test_WndProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{
  if (!(msg == 0x100 || msg == 0x101 || msg == 0x102))
    return;

  switch (msg) {
  case WM_KEYUP:
    switch (wParam) {

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

    // 5 = Add gold to player
    case '5':
      {
        gameClient->pCPlayer->gold += 100000;
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
            equipment, equipment->nameReal.getString(), equipment->enhancementCount, searchTerm);

          for (int j = 0; j < 32; j++) {
            testLogger.WriteLine(Info,
            L"  %x",
            equipment->unk1007[j]);
          }

          // unk1006
          testLogger.WriteLine(Info,
            L"  Equipment(%p) (%s) Dump of unk1006 (enhancementCount = %i):",
            equipment, equipment->nameReal.getString(), equipment->enhancementCount, searchTerm);

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
            L"  Dump of 1001/1004/1005: %x %x %x",
            equipment->unk1001, equipment->unk1004, equipment->unk1005);

          testLogger.WriteLine(Info,
            L"---------------------------",
            "");
        }
      }
      break;

    }  // End switch wParam

  } // End switch msg

}
