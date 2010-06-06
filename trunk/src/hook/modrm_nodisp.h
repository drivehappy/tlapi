#pragma once

#include "modrm.h"

class modrm_nodisp : public modrm {
public:
  using modrm::mod; using modrm::r; using modrm::rm;
  using modrm::has_imm32; using modrm::has_imm8; using modrm::has_sib;
  using modrm::imm; using modrm::s;

  modrm_nodisp(reg _r, reg _rm);
  modrm_nodisp(reg _r, uint32_t _imm);
  modrm_nodisp(reg _r, sib _s);
};
