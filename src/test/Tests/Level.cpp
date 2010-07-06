#include "Test.h"

void TestCallbackPost_LevelCharacterInitialize(CCharacter* retVal, CLevel* level, CCharacter* character, Vector3* position, u32)
{
  log("Level Initialized Character (Level = %p)", level);
  log("  retVal = %p", retVal);
  log("  character = %p", character);
  log("  position = %f %f %f", position->x, position->y, position->z);
}
