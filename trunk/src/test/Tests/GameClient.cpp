#include "Test.h"
#include "TestUserInterface.h"

CGameClient *gameClient = NULL;

void Test_GameClientLoadMap(PVOID retVal, CGameClient *client, u32 unk0)
{
  gameClient = client;

  testLogger.WriteLine(Info,
    L"GameClient(%p)::LoadMap( unk0(%x) ) returns Unk(%p)",
    client, unk0, retVal);
}

void Test_GameClientProcessObjects(CGameClient *client, PVOID unk0, PVOID unk1, PVOID unk2)
{
  gameClient = client;

  testLogger.WriteLine(Verbose,
    L"GameClient(%p)::ProcessObjects( unk0(%x), unk1(%x), unk2(%x) )",
    client, unk0, unk1, unk2);

  // Handle key input for dumping current player Equipment list
  CList<CEquipmentRef*>* equipmentList = &client->pCPlayer->pCInventory->equipmentList;
}

void Test_GameClient_SaveGame(CGameClient *client, u32 unk0, u32 unk1, bool & callOriginal)
{
  gameClient = client;

  testLogger.WriteLine(Info,
    L"GameClient(%p)::SaveGame( unk0(%x), unk1(%x) )",
    client, unk0, unk1);

  /*
  testLogger.WriteLine(Info,
    L"Save Game Suppressed",
    client, unk0, unk1);

  callOriginal = false;
  */
}

void Test_GameClient_SetupUI(CGameClient *client, u32 unk0, u32 unk1)
{

}
