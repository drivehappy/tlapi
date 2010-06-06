#include "modrm.h"

modrm::modrm()
: has_imm32(false), has_imm8(false), has_sib(false)
{
}

void modrm::mk(out_buf*c) const
{
  x1(mod<<6|r<<3|rm);
  if (has_sib) {
    s.mk(c);
  }

  if (has_imm32||(has_sib&&mod==0&&s.base==ebp)) {
    x4(imm);
  } else if (has_imm8) {
    x1(imm);
  }
}
