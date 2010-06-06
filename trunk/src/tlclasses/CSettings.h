#pragma once

#include "_CString.h"
#include "CDynamicPropertyFile.h"


struct SettingValue {
  const char *name;
  int index;
};

struct _CUnknownStructureFloatContainer {
  PVOID unk;
  float data[5];
};

struct _CUnknownStructureStringContainer {
  float   unk;
  CString value;
};

struct CSettings : CDynamicPropertyFile
{
  PVOID     unk2;
  CString   LocalSettingsDirectory;

  PVOID     unk3;
  CString   SettingsFile;

  PVOID     unk4;
  u32       unk5[2];

  _CUnknownStructureFloatContainer   *UnkStruct0Min;
  _CUnknownStructureFloatContainer   *UnkStruct0Max;

  PVOID     unk6[2];

  u32       unk7[2];

  u32      *SettingIntIndexLow;        // These are pointers to int setting values
  u32      *SettingIntIndexHigh;       // for both local_settings and settings.txt

  PVOID     unk8[2];

  u32       unk9[2];

  float    *SettingFloatIndexLow;     // These are pointers to float setting values
  float    *SettingFloatIndexHigh;    // For "local_settings.txt" and settings.txt

  PVOID     unk10;

  u32       unk11[3];

  _CUnknownStructureStringContainer  *StringSettingValueMin;    // Contains pointers to CString + float structure  these strings are values that appear in
  _CUnknownStructureStringContainer  *StringSettingValueMax;    // For "local_settings.txt" only

  float    *unk12;

  PVOID     unk13;

  u32       unk14[2];

  _CUnknownStructureStringContainer  *StringSettingIntMin;      // Contains pointers to CString + float struct
  _CUnknownStructureStringContainer  *StringSettingIntMax;      // these strings are values that are in SETTINGS.TXT - For Ints only

  // WHERE"S THE LOCAL_SETTING.TXT String Keys + SETTINGS.TXT String keys for floats???

  float    *unk15;        // Pointer to time val float?

  PVOID     unk16;

  u32       unk17[95];    // Unsure

  u32       fileMaxSize;

  // This appears to be garbage data, oh well
  u32       unk18[2];

  wchar_t   fileContents[8192];

  // Toggle the internal logging
  void enableInternalLogging()
  {
    SettingIntIndexLow[0x3c] = 1;
  }

  // Appears to be using garbage data, not useable anyways
  void dumpSettingsFile()
  {
    logColor(B_BLUE, "CSettings Dump FileContents:");
    logColor(B_BLUE, L"%s", fileContents);
  }

  // Dump what setting information we have
  void dumpSettings()
  {
    u32 *index = SettingIntIndexLow;
    logColor(B_RED, "CSettings Dump Ints: %p %p", SettingIntIndexLow, SettingIntIndexHigh);
    while (index < SettingIntIndexHigh) {
      logColor(B_RED, "  %#2x: %i", index, *index);
      index++;
    }

    float *indexFloat = SettingFloatIndexLow;
    logColor(B_RED, "CSettings Dump Floats: %p %p", SettingFloatIndexLow, SettingFloatIndexHigh);
    while (indexFloat < SettingFloatIndexHigh) {
      logColor(B_RED, "  %#2x: %f", indexFloat, *indexFloat);
      indexFloat++;
    }

    _CUnknownStructureStringContainer *indexStringValues = StringSettingValueMin;
    logColor(B_RED, "String Values:", indexStringValues, StringSettingValueMax);
    while (indexStringValues < StringSettingValueMax) {
      logColor(B_RED, L"   %s", indexStringValues->value.getString());
      indexStringValues++;
    }

    _CUnknownStructureStringContainer *indexStringIntValues = StringSettingIntMin;
    logColor(B_RED, "String Int Values:", indexStringIntValues, StringSettingIntMax);
    while (indexStringIntValues < StringSettingIntMax) {
      logColor(B_RED, L"   %s", indexStringIntValues->value.getString());
      indexStringIntValues++;
    }
  }
};
