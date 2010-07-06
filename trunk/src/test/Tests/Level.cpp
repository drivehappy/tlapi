#include "Test.h"

void Test_LevelCharacterInitialize(CCharacter* retVal, CLevel* level, CCharacter* character, Vector3* position, u32)
{
  testLogger.WriteLine(Info,
    L"Level(%p)::InitializeCharacter( Character(%p), Position(%p) ) returns Character(%p)",
    level, character, position, retVal);

  testLogger.WriteLine(Verbose,
    L"  Position: %f, %f, %f",
    position->x, position->y, position->z);
}
