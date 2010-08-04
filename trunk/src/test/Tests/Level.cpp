#include "Test.h"

void Test_LevelCharacterInitialize(CCharacter* retVal, CLevel* level, CCharacter* character, Vector3* position, u32)
{
  testLogger.WriteLine(Info,
    L"Level(%p)::InitializeCharacter( Character(%p), Position(%p) ) returns Character(%p)",
    level, character, position, retVal);

  testLogger.WriteLine(Verbose,
    L"  Position: %f, %f, %f",
    position->x, position->y, position->z);

  log(
    L"InitializeCharacter: %s (%p)",
    character->name.c_str(), character);
}

void Test_LevelCreateAstarPathfinding(CAstarPathfinder* pathFinder, float unk0, float unk1, u32 unk2, u32 unk3, PVOID unk4, PVOID unk5, float unk6)
{
  testLogger.WriteLine(Info,
    L"LevelCreateAstarPathfinder(%p) (%f, %f, %x, %x, %p, %p, %f)",
    pathFinder, unk0, unk1, unk2, unk3, unk4, unk5, unk6
    );
}

void Test_LevelDropEquipment(CLevel* level, CEquipment* equipment, Vector3 & position, bool unk0)
{
  log(
    L"Level::DropEquipment(%p) (%p, (%f, %f, %f), %x) - %s", level, equipment,
    position.x, position.y, position.z, unk0, equipment->nameReal.c_str());
}

