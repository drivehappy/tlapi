#pragma once

#include <string.h>

#include "modrm.h"
#include "gencommon.h"

class codegen {
public:
  out_buf *c;
  int esp_val;

  codegen(out_buf *p);

  void nop();
  template<int bits> void mov_r_rm(const modrm &rm);
  template<int bits> void mov_rm_r(const modrm &rm);
  template<int bits> void mov_r_imm(reg r, uint32_t imm);
  template<int bits> void mov_rm_imm(modrm rm, uint32_t imm);
  template<int bits> void lea_r_rm(const modrm&rm);
  void call_rel32(uint32_t addr);
  void int3();
  void ret();
  void ret_imm16(uint32_t bytes);
  void pop_m32(modrm m);
  void pop_r32(reg r);
  void push_rm32(modrm rm);
  void push_r32(reg r);
  void push_imm8(int8_t imm);
  void push_imm32(uint32_t imm);
  void jmp_rel32(uint32_t addr);
  void jmp_rel8(uint32_t addr);
  void jmp_relx(uint32_t addr);
  void jz_rel32(uint32_t addr);
  void jz_rel8(uint32_t addr);
  void jz_relx(uint32_t addr);
  void jnz_rel32(uint32_t addr);
  void jnz_rel8(uint32_t addr);
  void jnz_relx(uint32_t addr);
  void add_eax_imm32(uint32_t imm);
  void add_al_imm8(uint32_t imm);
  template<int rmbits,int immbits,typename immtype> void add_rm_imm(modrm rm,immtype imm);
  template<int bits> void add_rm_immx(modrm rm,uint32_t imm);
  template<int bits> void test_rm_r(const modrm&rm);
  template<int bits> void add_rm_r(const modrm&rm);
  template<int bits> void add_r_rm(const modrm&rm);
  template<int bits> void sub_rm_r(const modrm&rm);
  template<int bits> void sub_r_rm(const modrm&rm);
  template<int bits> void jmp_rm(modrm rm);
  template<int bits> void cmp_rm_r(const modrm&rm);
  template<int bits> void jcc_rel(cc_codes cc,uint32_t addr);
  template<int bits> void shl_rm_imm(modrm rm,uint8_t imm);
  template<int bits> void shr_rm_imm(modrm rm,uint8_t imm);
  template<int bits> void sar_rm_imm(modrm rm,uint8_t imm);
  template<int bits> void shl_rm_cl(modrm rm);
  template<int bits> void shr_rm_cl(modrm rm);
  template<int bits> void sar_rm_cl(modrm rm);
  template<int bits> void rol_rm_imm(modrm rm,uint8_t imm);
  template<int bits> void rol_rm_cl(modrm rm);
  template<int bits> void ror_rm_imm(modrm rm,uint8_t imm);
  template<int bits> void ror_rm_cl(modrm rm);
  template<int bits> void xor_rm_imm(modrm rm,uint32_t imm);
  template<int bits> void xor_rm_r(const modrm&rm);
  template<int bits> void xor_r_rm(const modrm&rm);
  template<int bits> void or_rm_imm(modrm rm,uint32_t imm);
  template<int bits> void or_rm_r(const modrm&rm);
  template<int bits> void or_r_rm(const modrm&rm);
  template<int bits> void and_rm_imm(modrm rm,uint32_t imm);
  template<int bits> void and_rm_r(const modrm&rm);
  template<int bits> void and_r_rm(const modrm&rm);
  template<int bits> void not_rm(modrm rm);
  void cld();
  int used_registers[8];
  reg get_free_preserved_reg();
  void release_preserved_reg(reg r);
  void restore_preserved_registers();
  void restore_esp();
};
