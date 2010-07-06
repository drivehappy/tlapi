#include "Test.h"

void Test_CharacterSetAlignment(CCharacter* character, u32 alignment)
{
  testLogger.WriteLine(Info,
    L"Character(%p)::SetAlignment( %s ) returns void",
    character, alignment == 2 ? L"Friendly" : L"Hostile");

  // Dump the GUID for more information
  testLogger.WriteLine(Verbose,
    L"  GUID: %016I64X",
    character->GUID);
}

void Test_CharacterSetDestination(CCharacter* character, CLevel* level, float x, float y)
{
  testLogger.WriteLine(Info,
    L"Character(%p)::SetDestination( Level(%p), %f, %f ) returns void",
    character, level, x, y);

  // Dump the GUID for more information
  testLogger.WriteLine(Verbose,
    L"  GUID: %016I64X",
    character->GUID);
}
