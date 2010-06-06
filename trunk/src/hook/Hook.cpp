#include "Hook.h"
using namespace TLMP;

// ----------------------------------------------------------------------- //
// Meat of the code originally developed by dengus
// Cleaned up - drivehappy
// ----------------------------------------------------------------------- //

PVOID TLMP::HookGenerateEntry(PVOID address, PVOID out_ins, size_t* out_size)
{
  ud u;
  ud_init(&u);
  ud_set_mode(&u,32);
  ud_set_input_buffer(&u,(uint8_t*)address,0x100);
  ud_set_pc(&u,(uint64_t)address);
  uint8_t*out = (uint8_t*)out_ins;
  size_t total_size=0;
  void*ret_addr = address;
  size_t size;
  // follow any jumps if the function starts with them
  for (int i=0;i<10;i++) {
    size = ud_decode(&u);
    if (!size) {
      xcept("hook entry %p; failed to decode instruction at %p",address,(void*)u.insn_offset);
    }
    ud_operand&op = u.operand[0];
    if (u.mnemonic==UD_Ijmp) {
      ret_addr = (uint8_t*)(u.pc + (op.size==32?op.lval.sdword:op.size==16?op.lval.sword:op.lval.sbyte));
      ud_set_input_buffer(&u,(uint8_t*)ret_addr,0x100);
      ud_set_pc(&u,(uint64_t)ret_addr);
      continue;
    } else break;
  }
  while (total_size<5) {
    // u already contains an instruction from the above loop
    total_size += size;


//     ud_translate_intel(&u);
//     printf(" %p :: %-16s  %s\n",(void*)ud_insn_off(&u),ud_insn_hex(&u),ud_insn_asm(&u));

    // any instructions we care about only have one operand
    ud_operand&op = u.operand[0];

    // oh no, a relative jump. we must patch it up
    if (op.type==UD_OP_JIMM) {
      uint32_t addr = (uint32_t)(u.pc + (op.size==32?op.lval.sdword:op.size==16?op.lval.sword:op.lval.sbyte));
      // check that the branch is not inside the entry
      // this routine will still generate invalid code if a function starts with, for instance, 74 00
      // but that is extremely unlikely to happen
      if (addr<(uint32_t)ret_addr||addr>(uint32_t)ret_addr + total_size) {
        uint8_t*p = (uint8_t*)u.insn_offset;
        // to be sure it'll reach, we must patch them up to use 32-bit offsets
        if (op.size==32) {
          // just copy the opcode
          memcpy(out,p,size-4);
          out += size-4;
        } else if (op.size==16) {
          // remove the prefix, and copy the opcode
          memcpy(out,p,size-2-1);
          out += size-2-1;
        } else if (op.size==8) {
          uint8_t i = *p;
          if (i==0xeb) *out+= 0xe9; // jmp short is 0xeb, jmp near is 0xe9
          else if (i>=0x70&&i<=0x7f) { // jcc
            // the conditional short jmp instructions are 0x70 - 0x7f
            // the conditional long jmp instructions are 0x80-0x8f (after the 2-byte prefix 0x0f)
            *out++ = 0x0f;
            *out++ = i+0x10;
          } else {
            xcept("hook entry %p: failed to convert instruction at %p from 8-bit relative branch to 32-bit",address,(void*)u.insn_offset);
          }
          // there are no 8-bit relative call instructions
        }
        *(uint32_t*)out = addr - (uint32_t)(out+4);
        out += 4;
        continue;
      }  
    }
    memcpy(out,(void*)u.insn_offset,size);
    out += size;

    if (total_size<5) {
      if (u.mnemonic==UD_Iret || u.mnemonic==UD_Iiretw || u.mnemonic==UD_Ijmp) {
        // function end, but let's not give up quite yet... there should be some padding
        uint8_t*p = (uint8_t*)u.pc;
        while ((*p==0xcc||*p==0x00) && total_size<5) {
          total_size++;
          p++;
        }
        if (total_size>=5) break;
        // oh well...
        xcept("hook entry %p; function too small; ret or non-conditional branch found at %p",address,(void*)u.insn_offset);
      }
      
      size = ud_decode(&u);
      if (!size) {
        xcept("hook entry %p; failed to decode instruction at %p",address,(void*)u.insn_offset);
      }
    }
  }
  // and the jump back to the real function
  *out++ = 0xe9;
  *(uint32_t*)out = ((uint32_t)ret_addr + total_size) - (uint32_t)(out+4);
  out += 4;

  if (out_size) {
    *out_size = out - (uint8_t*)out_ins;
  }

  return ret_addr;
}

HookFunctionDef* TLMP::HookNew(PVOID address, HookFunction pre, HookFunction post, u32 flags, u32 args)
{
  HookFunctionDef *f = new HookFunctionDef;
  memset(f,0,sizeof(f));
  f->address = address;
  f->pre = pre;
  f->post = post;
  f->flags = flags;
  f->args = args;
  uint8_t*p = (uint8_t*)VirtualAlloc(0,0x1000,MEM_RESERVE | MEM_COMMIT,PAGE_EXECUTE_READWRITE);
  f->entry = p;
  f->patch_address = HookGenerateEntry(address, f->entry, &f->entry_size);
  f->hook_code = (void*)(((uint32_t)(p+f->entry_size-1) & ~0xF) + 16); // align to 16 bytes
  f->hook_code_size = HookGenerate(f->hook_code,f);
  return f;
}

HookFunctionDef* TLMP::Hook(PVOID address, HookFunction pre, HookFunction post, u32 flags, u32 args)
{
  HookFunctionDef*f = HookNew(address,pre,post,flags,args);
  HookActivate(f);
  return f;
}

size_t TLMP::HookGenerate(PVOID out, HookFunctionDef* f)
{
  out_buf_ptr code_buf((unsigned char*)out);
  codegen gen(&code_buf);

  //gen.int3();

  gen.add_rm_immx<32>(modrm_reg(badreg,esp),-(int)sizeof(HookStruct));

#define rm_h(r,o,...) modrm_dispx(r,-gen.esp_val - sizeof(HookStruct) + (offsetof(HookStruct, o) __VA_ARGS__),sib_nomul(esp))

  for (int i=0;i<8;i++) {
    if (f->flags & HookFlag_Regs[i]) {
      gen.mov_rm_r<32>(rm_h((reg)i, _eax, +i*4));
    }
  }

  gen.mov_r_rm<32>(modrm_dispx(eax, -gen.esp_val, sib_nomul(esp)));
  gen.mov_rm_r<32>(rm_h(eax, retaddress));

  int r=2;
  for (int i=0;i<f->args;i++) {
    gen.mov_r_rm<32>(modrm_dispx((reg)r,-gen.esp_val + 4 + i*4,sib_nomul(esp)));
    gen.mov_rm_r<32>(rm_h((reg)r,arg[i]));
    gen.mov_rm_r<32>(rm_h((reg)r,ref_arg[i]));
    if (--r==-1) r=2;
  }
  if (f->pre) {
    gen.mov_rm_imm<8>(rm_h(badreg,calloriginal),1);
    if (-gen.esp_val==sizeof(HookStruct)) gen.mov_r_rm<32>(modrm_reg(eax,esp));
    else gen.lea_r_rm<32>(rm_h(eax,ref_arg[0]));
    gen.push_imm32((uint32_t)f);
    if (-gen.esp_val==sizeof(HookStruct)) gen.push_r32(esp);
    else gen.push_r32(eax);
    gen.call_rel32((uint32_t)f->pre);
    gen.add_rm_immx<32>(modrm_reg(badreg,esp),8);
    gen.mov_r_rm<8>(rm_h(eax,calloriginal));
    gen.test_rm_r<8>(modrm_reg(eax,eax));
    gen.push_imm32(0);
    uint32_t*retaddr = (uint32_t*)(gen.c->addr()-4);
    for (int i=0;i<8;i++) {
      if (f->flags & HookFlag_Regs[i]) {
        gen.mov_r_rm<32>(rm_h((reg)i,_eax,+4*i));
      }
    }
    gen.jnz_relx((uint32_t)f->entry);
    gen.mov_r_rm<32>(rm_h(eax,retval));
    gen.add_rm_immx<32>(modrm_reg(badreg,esp),4 + (f->flags & HOOKFLAG_CALLEE_CLEANUP ? 4*f->args : 0));
    while (gen.c->addr()%4) gen.nop();
    *retaddr = (uint32_t)gen.c->addr();
  } else {
    for (int i=0;i<8;i++) {
      if (f->flags & HookFlag_Regs[i]) {
        gen.mov_r_rm<32>(rm_h((reg)i,_eax,+4*i));
      }
    }
    gen.call_rel32((uint32_t)f->entry);
    if (f->flags & HOOKFLAG_CALLEE_CLEANUP) {
      gen.esp_val += 4*f->args;
    }
  }  
  if (f->post) {
    gen.mov_rm_r<32>(rm_h(eax,retval));
    if (-gen.esp_val==sizeof(HookStruct)) gen.mov_r_rm<32>(modrm_reg(eax,esp));
    else gen.lea_r_rm<32>(rm_h(eax,ref_arg[0]));
    gen.push_imm32((uint32_t)f);
    if (-gen.esp_val==sizeof(HookStruct)) gen.push_r32(esp);
    else gen.push_r32(eax);
    gen.call_rel32((uint32_t)f->post);
    gen.mov_r_rm<32>(rm_h(eax,retval));
  }

#undef rm_h
  gen.add_rm_immx<32>(modrm_reg(badreg, esp), -gen.esp_val);
  if (f->flags & HOOKFLAG_CALLEE_CLEANUP && f->args) gen.ret_imm16(f->args*4);
  else gen.ret();
  return code_buf.c - code_buf.oc;
}

void TLMP::HookDelete(HookFunctionDef* f)
{
  if (f->hook_code) VirtualFree(f->hook_code,0,MEM_RELEASE);
  delete f;
}

void TLMP::HookActivate(HookFunctionDef* f)
{
  // patch up patch_address to jump to entry

  DWORD oldprot;
  if (!VirtualProtectEx(GetCurrentProcess(), f->patch_address, 0x100, PAGE_EXECUTE_READWRITE, &oldprot)) {
    //xcept("hook entry %p; VirtualProtectEx failed (error %d)",GetLastError());
  }

  uint8_t*out = (uint8_t*)f->patch_address;
  *out++ = 0xe9;
  *(uint32_t*)out = (uint8_t*)f->hook_code - (out+4);
  out += 4;
}

void TLMP::HookDeactivate(HookFunctionDef* f)
{
  if (f->hook_code) {
    VirtualFree(f->hook_code, 0, MEM_RELEASE);
  }

  delete f;
}

void TLMP::PatchJMP(uint32_t addr, uint32_t to)
{
  //addr = EXEOFFSET(addr);

  uint8_t *p = (uint8_t*)addr;
  DWORD old;
  VirtualProtect(p, 5, PAGE_EXECUTE_READWRITE, &old);
  *p++ = 0xe9;
  *(uint32_t*)p = (uint8_t*)(to) - (p+4);
}
