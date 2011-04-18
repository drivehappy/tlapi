#pragma once

#include "Helper.h"

#include "udis86.h"
#include "CodeGeneration.h"

// ----------------------------------------------------------------------- //
// Code developed by dengus.
//

namespace TLAPI {

  enum {
    HOOKFLAG_EAX =            0x0001,
    HOOKFLAG_ECX =            0x0002,
    HOOKFLAG_EDX =            0x0004,
    HOOKFLAG_EBX =            0x0008,
    HOOKFLAG_ESP =            0x0010,
    HOOKFLAG_EBP =            0x0020,
    HOOKFLAG_ESI =            0x0040,
    HOOKFLAG_EDI =            0x0080,
    HOOKFLAG_CALLEE_CLEANUP = 0x0100,
  };

  static const u32 HOOKFLAG_REG_ALL = (HOOKFLAG_EAX | HOOKFLAG_ECX | HOOKFLAG_EDX | 
                                       HOOKFLAG_EBX | HOOKFLAG_ESP | HOOKFLAG_EBP |
                                       HOOKFLAG_ESI | HOOKFLAG_EDI);
  static const  u32 HOOK_CDECL =    0;
  static const  u32 HOOK_STDCALL =  HOOKFLAG_CALLEE_CLEANUP;
  static const  u32 HOOK_THISCALL = HOOKFLAG_ECX | HOOKFLAG_CALLEE_CLEANUP;
  static        int HookFlag_Regs[8] = {
    HOOKFLAG_EAX,
    HOOKFLAG_ECX,
    HOOKFLAG_EDX,
    HOOKFLAG_EBX,
    HOOKFLAG_ESP,
    HOOKFLAG_EBP,
    HOOKFLAG_ESI,
    HOOKFLAG_EDI
  };

  struct HookStruct {
    DWORD   ref_arg[32];
    DWORD   arg[32];
    DWORD   retval;
    bool    calloriginal;
    DWORD   user[16];
    PVOID   retaddress;
    DWORD   _eax;
    union {
      DWORD _ecx;
      PVOID _this;
    };
    DWORD   _edx, _ebx, _esp, _ebp, _esi, _edi;
  };

  struct HookFunctionDef;

  //
  typedef void (*HookFunction)(HookStruct *e, HookFunctionDef *_f);

  struct HookFunctionDef {
    HookFunction  pre;
    HookFunction  post;
    int           flags;
    int           args;
    int           args_size;
    PVOID         address;
    PVOID         hook_code;
    size_t        hook_code_size;
    PVOID         entry;
    size_t        entry_size;
    PVOID         patch_address;
	  DWORD         user[16];
  };

  //
  PVOID HookGenerateEntry(PVOID address, PVOID out_ins, size_t* out_size);

  HookFunctionDef* HookNew(PVOID address, HookFunction pre, HookFunction post, u32 flags, u32 args);

  HookFunctionDef* Hook(PVOID address, HookFunction pre, HookFunction post, u32 flags, u32 args);

  size_t HookGenerate(PVOID out, HookFunctionDef* f);

  void HookDelete(HookFunctionDef*);
  void HookActivate(HookFunctionDef*);
  void HookDeactivate(HookFunctionDef*);

  //
  void PatchJMP(uint32_t addr, uint32_t to);
  void PatchShortJMP(uint32_t addr, uint8_t to);

};
