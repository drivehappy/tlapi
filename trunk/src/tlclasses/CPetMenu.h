#pragma once

struct CPetMenu : CSubMenu
{
  PVOID vtable;
  PVOID unk0;
  PVOID vtableIInventoryListener; // vtable ptr
  PVOID pCEGUIBaseGUISheet;       // ptr to GUI Sheet
  // 6 more GUISheet ptrs
};
