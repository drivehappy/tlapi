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

void Test_GameClient_CreateLevel(CGameClient *client, u32 unk0, u32 unk1, u32 unk2, CGameClient *client2, u32 unk4, u32 unk5,
  u32 unk6, u32 unk7, u32 unk8, u32 unk9, u32 unk10, u32 unk11,u32 unk12, u32 unk13, u32 unk14, u32 unk15, u32 unk16,
  u32 unk17,u32 unk18, u32 unk19, u32 unk20, u32 unk21, u32 unk22, u32 unk23)
{
  log("GameClient(%p) CreateLevel:", client);
  log("  unk0: %x", unk0);
  log("  unk1: %x", unk1);
  log("  unk2: %x", unk2);
  log("  CGameClient: %x", client2);
  log("  unk4: %x", unk4);
  log("  unk5: %x", unk5);
  log("  unk6: %x", unk6);
  log("  unk7: %x", unk7);
  log("  unk8: %x", unk8);
  log("  unk9: %x", unk9);
  log("  unk10: %x", unk10);
  log("  unk11: %x", unk11);
  log("  unk12: %x", unk12);
  log("  unk13: %x", unk13);
  log("  unk14: %x", unk14);
  log("  unk15: %x", unk15);
  log("  unk16: %x", unk16);
  log("  unk17: %x", unk17);
  log("  unk18: %x", unk18);
  log("  unk19: %x", unk19);
  log("  unk20: %x", unk20);
  log("  unk21: %x", unk21);
  log("  unk22: %x", unk22);
  log("  unk23: %x", unk23);
}

void Test_GameClient_LoadLevel(CGameClient *client)
{
  log("GameClient LoadLevel (client = %p)", client);
  log("  LevelChange = %i", client->level);
  log("  LevelChangeUnk = %i", client->levelUnk);
}
