#include "modrm_reg.h"

modrm_reg::modrm_reg(reg _r, reg _rm)
{
  mod = 3;
  r = _r;
  rm = _rm;
}
