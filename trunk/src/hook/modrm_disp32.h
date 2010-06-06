#pragma once

#include "modrm.h"

class modrm_disp32 : public modrm {
public:
  using modrm::mod; using modrm::r; using modrm::rm;
  using modrm::has_imm32; using modrm::has_imm8; using modrm::has_sib;
  using modrm::imm; using modrm::s;

  modrm_disp32(reg _r, reg _rm,uint32_t disp);
  modrm_disp32(reg _r,uint32_t disp, sib _s);
};
