#pragma once

#include "modrm.h"
#include "gencommon.h"

class modrm_reg:public modrm {
public:
  using modrm::mod; using modrm::r; using modrm::rm;
  using modrm::has_imm32; using modrm::has_imm8; using modrm::has_sib;
  using modrm::imm; using modrm::s;

  modrm_reg(reg _r, reg _rm);
};
