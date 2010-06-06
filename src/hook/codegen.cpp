#include "codegen.h"

codegen::codegen(out_buf*p)
: c(p), esp_val(0)
{
  memset(used_registers,0,sizeof(used_registers));
}

void codegen::nop()
{
  x1(0x90);
}

void codegen::call_rel32(uint32_t addr) {
  x1(0xe8);
  x4(addr-xaddr-4);
}
void codegen::int3() {
  x1(0xcc);
}
void codegen::ret() {
  x1(0xc3);
}
void codegen::ret_imm16(uint32_t bytes) {
  x1(0xc2);
  x2(bytes);
}
void codegen::pop_m32(modrm m) {
  x1(0x8F);
  m.r=0;
  m.mk(c);
  esp_val+=4;
}
void codegen::pop_r32(reg r) {
  x1(0x58+r);
  esp_val+=4;
}
void codegen::push_rm32(modrm rm) {
  x1(0xFF);
  rm.r=6;
  rm.mk(c);
  esp_val-=4;
}
void codegen::push_r32(reg r) {
  x1(0x50+r);
  esp_val-=4;
}
void codegen::push_imm8(int8_t imm) {
  x1(0x6A);
  x1(imm);
  esp_val-=4;
}
void codegen::push_imm32(uint32_t imm) {
  x1(0x68);
  x4(imm);
  esp_val-=4;
}
void codegen::jmp_rel32(uint32_t addr) {
  x1(0xe9);
  x4(addr-xaddr-4);
}
void codegen::jmp_rel8(uint32_t addr) {
  x1(0xeb);
  x1(addr-xaddr-1);
}
void codegen::jmp_relx(uint32_t addr) {
  if ((int8_t)(addr-xaddr-2)!=(uint32_t)(addr-xaddr-2)) 
    jmp_rel32(addr); 
  else 
    jmp_rel8(addr);
}

void codegen::jz_rel32(uint32_t addr) {
  x2(0x840f);
  x4(addr-xaddr-4);
}

void codegen::jz_rel8(uint32_t addr) {
  x1(0x74);
  x1(addr-xaddr-1);
}

void codegen::jz_relx(uint32_t addr) {
  if ((int8_t)(addr-xaddr-2)!=(uint32_t)(addr-xaddr-2)) 
    jz_rel32(addr); 
  else 
    jz_rel8(addr);
}

void codegen::jnz_rel32(uint32_t addr) {
  x2(0x850f);
  x4(addr-xaddr-4);
}

void codegen::jnz_rel8(uint32_t addr) {
  x1(0x75);
  x1(addr-xaddr-1);
}

void codegen::jnz_relx(uint32_t addr) {
  if ((int8_t)(addr-xaddr-2)!=(uint32_t)(addr-xaddr-2)) 
    jnz_rel32(addr); 
  else 
    jnz_rel8(addr);
}

void codegen::add_eax_imm32(uint32_t imm) {
  x1(0x05)
    ;x4(imm);
}

void codegen::add_al_imm8(uint32_t imm) {
  x1(0x04);
  x1(imm);
}

template<>
void codegen::test_rm_r<32>(const modrm&rm)  {
  x1(0x85);
  rm.mk(c);
};

template<>
void codegen::test_rm_r<16>(const modrm&rm)  {
  x2(0x8566);
  rm.mk(c);
};

template<>
void codegen::test_rm_r<8>(const modrm&rm)  {
  x1(0x84);
  rm.mk(c);
};

template<>
void codegen::shl_rm_imm<32>(modrm rm,uint8_t imm) {
  rm.r = 4;
  x1(0xc1);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::shl_rm_imm<16>(modrm rm,uint8_t imm) {
  rm.r = 4;
  x2(0xc166);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::shl_rm_imm<8>(modrm rm,uint8_t imm) {
  rm.r = 4;
  x1(0xc0);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::shr_rm_imm<32>(modrm rm,uint8_t imm) {
  rm.r = 5;
  x1(0xc1);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::shr_rm_imm<16>(modrm rm,uint8_t imm) {
  rm.r = 5;
  x2(0xc166);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::shr_rm_imm<8>(modrm rm,uint8_t imm) {
  rm.r = 5;
  x1(0xc0);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::sar_rm_imm<32>(modrm rm,uint8_t imm) {
  rm.r = 7;
  x1(0xc1);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::sar_rm_imm<16>(modrm rm,uint8_t imm) {
  rm.r = 7;
  x2(0xc166);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::sar_rm_imm<8>(modrm rm,uint8_t imm) {
  rm.r = 7;
  x1(0xc0);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::mov_r_rm<32>(const modrm&rm) {
  x1(0x8b);
  rm.mk(c);
}

template<>
void codegen::mov_r_rm<16>(const modrm&rm) {
  x2(0x8b66);
  rm.mk(c);
}

template<>
void codegen::mov_r_rm<8>(const modrm&rm) {
  x1(0x8a);
  rm.mk(c);
}

template<>
void codegen::mov_rm_r<32>(const modrm&rm) {
  x1(0x89);
  rm.mk(c);
}

template<>
void codegen::mov_rm_r<16>(const modrm&rm) {
  x1(0x66);
  x1(0x89);
  rm.mk(c);
}

template<>
void codegen::mov_rm_r<8>(const modrm&rm) {
  x1(0x88);
  rm.mk(c);
}

template<>
void codegen::mov_r_imm<32>(reg r, uint32_t imm) {
  x1(0xb8 + r);
  x4(imm);
}

template<>
void codegen::mov_r_imm<16>(reg r, uint32_t imm) {
  x2(0xb866 + r);
  x2(imm);
}

template<>
void codegen::mov_r_imm<8>(reg r, uint32_t imm) {
  x1(0xb0 + r);
  x1(imm);
}

template<>
void codegen::mov_rm_imm<32>(modrm rm, uint32_t imm) {
  rm.r = 0;
  x1(0xc7);
  rm.mk(c);
  x4(imm);
}

template<>
void codegen::mov_rm_imm<16>(modrm rm, uint32_t imm) {
  rm.r = 0;
  x2(0xc766);
  rm.mk(c);
  x2(imm);
}

template<>
void codegen::mov_rm_imm<8>(modrm rm, uint32_t imm) {
  rm.r = 0;
  x1(0xc6);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::lea_r_rm<32>(const modrm&rm) {
  x1(0x8d);
  rm.mk(c);
}

template<>
void codegen::add_rm_imm<32,8,int8_t>(modrm rm,int8_t imm) {
  rm.r=0;
  if (rm.rm==esp) esp_val+=imm;
  x1(0x83);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::add_rm_imm<32,32,uint32_t>(modrm rm,uint32_t imm) {
  rm.r=0;
  if (rm.rm==esp) 
    esp_val+=imm;
  x1(0x81);
  rm.mk(c);
  x4(imm);
}

template<>
void codegen::add_rm_immx<32>(modrm rm,uint32_t imm) {
  if ((int8_t)imm!=imm) 
    add_rm_imm<32,32>(rm,imm); 
  else 
    add_rm_imm<32,8>(rm,(int8_t)imm);
}

template<>
void codegen::add_rm_imm<16,8,int8_t>(modrm rm,int8_t imm) {
  rm.r=0;
  if (rm.rm==esp) 
    esp_val+=imm;
  x2(0x8366);
  rm.mk(c);
  x1(imm);
}

template<>
void codegen::add_rm_imm<16,16,uint16_t>(modrm rm,uint16_t imm) {
  rm.r=0;
  if (rm.rm==esp) 
    esp_val+=imm;
  x2(0x8166);
  rm.mk(c);
  x2(imm);
}

template<>
void codegen::add_rm_immx<16>(modrm rm,uint32_t imm) {
  if ((int8_t)imm!=imm)
    add_rm_imm<16,16>(rm,(uint16_t)imm);
  else 
    add_rm_imm<16,8>(rm,(int8_t)imm);
}

template<>
void codegen::add_rm_imm<8,8,int8_t>(modrm rm,int8_t imm) {
  rm.r=0;
  if (rm.rm==esp) esp_val+=imm;
  x1(0x80);
  rm.mk(c);
  x1(imm);
}
template<>
void codegen::add_rm_immx<8>(modrm rm,uint32_t imm) {
  add_rm_imm<8,8>(rm,(int8_t)imm);
}

template<>
void codegen::add_rm_r<32>(const modrm&rm) {
  x1(0x01);
  rm.mk(c);
}

template<>
void codegen::add_rm_r<16>(const modrm&rm) {
  x2(0x0166);
  rm.mk(c);
}

template<>
void codegen::add_rm_r<8>(const modrm&rm) {
  x1(0x00);
  rm.mk(c);
}

template<>
void codegen::add_r_rm<32>(const modrm&rm) {
  x1(0x03);
  rm.mk(c);
}

template<>
void codegen::add_r_rm<16>(const modrm&rm) {
  x2(0x0366);
  rm.mk(c);
}

template<>
void codegen::add_r_rm<8>(const modrm&rm) {
  x1(0x02);
  rm.mk(c);
}

template<>
void codegen::sub_rm_r<32>(const modrm&rm) {
  x1(0x29);
  rm.mk(c);
}

template<>
void codegen::sub_rm_r<16>(const modrm&rm) {
  x2(0x2966);
  rm.mk(c);
}

template<>
void codegen::sub_rm_r<8>(const modrm&rm) {
  x1(0x28);
  rm.mk(c);
}

template<>
void codegen::sub_r_rm<32>(const modrm&rm) {
  x1(0x2b);
  rm.mk(c);
}

template<>
void codegen::sub_r_rm<16>(const modrm&rm) {
  x2(0x2b66);
  rm.mk(c);
}

template<>
void codegen::sub_r_rm<8>(const modrm&rm) {
  x1(0x2a);
  rm.mk(c);
}

template<>
void codegen::jmp_rm<32>(modrm rm) {
  rm.r=4;
  x1(0xff);
  rm.mk(c);
}

template<>
void codegen::cmp_rm_r<32>(const modrm&rm) {
  x1(0x3b);
  rm.mk(c);
}

// cc_eq, cc_ne, cc_gt, cc_gtu, cc_lt, cc_ltu, cc_ge, cc_geu, cc_le, cc_leu
template<>
void codegen::jcc_rel<32>(cc_codes cc,uint32_t addr) {
  switch (cc) {
      case cc_eq:
        x2(0x840f); // je/jz
        break;
      case cc_ne:
        x2(0x850f); // jne/jnz
        break;
      case cc_gt:
        x2(0x8f0f); // jg/jnle
        break;
      case cc_gtu:
        x2(0x870f); // ja/jnbe
        break;
      case cc_lt:
        x2(0x8c0f); // jl/jnge
        break;
      case cc_ltu:
        x2(0x820f); // jb/jc/jnae
        break;
      case cc_ge:
        x2(0x8d0f); // jge/jnl
        break;
      case cc_geu:
        x2(0x830f); // jae/jnc/jnb
        break;
      case cc_le:
        x2(0x8e0f); // jle/jng
        break;
      case cc_leu:
        x2(0x860f); // jbe/jna
        break;
      default:
        x1(0xcc);
  }
  x4(addr-xaddr-4);
}
