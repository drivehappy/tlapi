#pragma once

// Size?: 30h
struct CSkipCutscene : CEditorBaseObject
{
  PVOID unk1;

  CSkipCutsceneDescriptor   *pCSkipCutsceneDescriptor;

  CString *name;      // "skipCutscene"


};
