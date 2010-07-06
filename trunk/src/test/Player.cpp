#include "Test.h"

void Test_PlayerUseSkill(u32 retVal, CPlayer* player, u64 skill)
{
  testLogger.WriteLine(Info,
    L"Player(%p)::UseSkill( Skill(%#016I64X) ) returns Int(%#x)",
    player, skill, retVal);

  // Dump the GUID for more information
  testLogger.WriteLine(Verbose,
    L"  GUID: %#016I64X",
    player->GUID);
}
