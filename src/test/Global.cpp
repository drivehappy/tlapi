#include "Test.h"

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
    
    // 2 = Attempt to auto enchant equipment
    case '2':
      {
        log("Dumping Player Equipment (Rock Grotesque)");
        
        if (gameClient == NULL) {
          log("gameClient is null, cannot proceed");
          break;
        }

        // Grab the list and iterate through it
        const wchar_t searchTerm[] = L"Rock Grotesque";
        CList<CEquipmentRef*> *list = &gameClient->pCPlayer->pCInventory->equipmentList;

        for (u32 i = 0; i < list->size; i++) {
          wchar_t *equipmentName = (*list)[i]->pCEquipment->nameReal.getString();
          
          int val = wcscmp(equipmentName, searchTerm);

          if (val == 0) {
            CEquipment *equipment = (*list)[i]->pCEquipment;

            // We found it, dump it
            log(L"Attempting to enchant %s", equipment->nameReal);
            u32 retVal = equipment->Enchant(0, 0, 1);
            log("Enchantment done.");
          }
        }
      }
      break;


    // 1 = Dump Player Equipment (specificially just named "Rickety Pistol")
    case '1':
      {
        log("Dumping Player Equipment (Rock Grotesque)");
        
        if (gameClient == NULL) {
          log("gameClient is null, cannot proceed");
          break;
        }

        gameClient->pCPlayer->dumpPlayer();

        // Grab the list and iterate through it
        const wchar_t searchTerm[] = L"Rock Grotesque";
        CList<CEquipmentRef*> *list = &gameClient->pCPlayer->pCInventory->equipmentList;

        for (u32 i = 0; i < list->size; i++) {
          wchar_t *equipmentName = (*list)[i]->pCEquipment->nameReal.getString();
          
          int val = wcscmp(equipmentName, searchTerm);

          if (val == 0) {
            CEquipment *equipment = (*list)[i]->pCEquipment;

            // We found it, dump it
            equipment->dumpEquipment();
            
            // unk1007
            testLogger.WriteLine(Info,
              L"  Equipment(%p) (%s) Dump of unk1007 (enhancementCount = %i):",
              equipment, equipment->nameReal.getString(), equipment->enhancementCount, equipmentName);

            for (int j = 0; j < 32; j++) {
              testLogger.WriteLine(Info,
              L"  %x",
              equipment->unk1007[j]);
            }

            // unk1006
            testLogger.WriteLine(Info,
              L"  Equipment(%p) (%s) Dump of unk1006 (enhancementCount = %i):",
              equipment, equipment->nameReal.getString(), equipment->enhancementCount, equipmentName);

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

            break;
          }
        }
      }
      break;

    }
  }
}
