#pragma once

#include "sib.h"

class modrm {
public:
  int mod,r,rm;
  bool has_imm32;
  bool has_imm8;
  bool has_sib;
  uint32_t imm;
  sib s;

  modrm();

  void mk(out_buf*c) const;
};
