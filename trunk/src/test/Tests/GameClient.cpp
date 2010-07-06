#include "Test.h"

void Test_GameClientLoadMap(PVOID retVal, CGameClient *client, u32 unk0)
{
  testLogger.WriteLine(Info,
    L"GameClient(%p)::LoadMap( unk0(%x) ) returns Unk(%p)",
    client, unk0, retVal);
}
