#include "Test.h"

void TestCallbackPost_CreateCharacter(CCharacter* retVal, CResourceManager* resourceManager, u64 guid, u32 unk0, bool unk1)
{
  log("ResourceManager (%p) CreateCharacter: %016I64X, %x, %i", resourceManager, guid, unk0, unk1);
}

void TestCallbackPost_CreateCharacterByName(CCharacter* retVal, CResourceManager* resourceManager, const wchar_t* str1, const wchar_t* str2, u32 unk0, u32 unk1)
{
  log(L"ResourceManager (%p) CreateCharacterByName: %s %s %x %x", resourceManager, str1, str2, unk0, unk1);
  log("  retVal = %p", retVal);
}

void TestCallbackPost_CharacterSetAlignment(CCharacter* character, u32 alignment)
{
  log("Character Set Alignment: %p, Alignment: %x", character, alignment);
}

void TestCallbackPost_CharacterSetDestination(CCharacter* character, CLevel* level, float x, float y)
{
  log("Character Set Destination: %p, Level: %p, X: %f, Y: %f", character, level, x, y);
}

