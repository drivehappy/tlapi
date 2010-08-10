#include "Test.h"
#include "TestUserInterface.h"

CGameClient *gameClient = NULL;

void Test_GameClientLoadMap(PVOID retVal, CGameClient *client, u32 unk0, bool& calloriginal)
{
  gameClient = client;

  testLogger.WriteLine(Info,
    L"GameClient(%p)::LoadMap( unk0(%x) ) returns Unk(%p)",
    client, unk0, retVal);
}

void Test_GameClientProcessObjects(CGameClient *client, float dTime, PVOID unk1, PVOID unk2)
{
  gameClient = client;

  testLogger.WriteLine(Verbose,
    L"GameClient(%p)::ProcessObjects( dTime(%f), unk1(%x), unk2(%x) )",
    client, dTime, unk1, unk2);


}

void Test_GameClient_SaveGame(CGameClient *client, u32 unk0, u32 unk1, bool & callOriginal)
{
  gameClient = client;

  testLogger.WriteLine(Info,
    L"GameClient(%p)::SaveGame( unk0(%x), unk1(%x) )",
    client, unk0, unk1);

  testLogger.WriteLine(Info,
    L"Save Game Suppressed",
    client, unk0, unk1);

  callOriginal = false;
}

void Test_GameClient_SetupUI(CGameClient *client, u32 unk0, u32 unk1)
{
  client->pCGameUI->dumpGameUI();
}

void Test_GameClient_CreateLevel(CGameClient* client, wstring unk0, wstring unk1, u32 unk2, u32 unk3, u32 unk4, wstring unk5, bool& calloriginal)
{
  log("GameClient(%p) CreateLevel:", client);
  log(L"  unk0: %s", unk0.c_str());
  log(L"  unk1: %s", unk1.c_str());
  log("  unk2: %x", unk2);
  log("  unk3: %x", unk3);
  log("  unk4: %x", unk4);
  log(L"  unk5: %s", unk5.c_str());
}

void Test_GameClient_LoadLevel(CGameClient *client, bool& calloriginal)
{
  log("GameClient LoadLevel (client = %p)", client);
  log("  LevelChange = %i", client->level);
  log("  LevelChangeUnk = %i", client->levelUnk);
}
