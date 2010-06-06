#pragma once

#include "sib.h"
#include "gencommon.h"

class sib_nomul : public sib {
public:
  using sib::ss;
  using sib::index;
  using sib::base;
  using sib::disp;

  sib_nomul(reg _index,reg _base) {
    ss=0, index=_index, base=_base;
  }
  sib_nomul(reg _index,uint32_t disp32) {
    ss=0, index=_index, base=ebp, disp=disp32;
  }
  sib_nomul(reg _base) {
    ss=0, index=esp, base=_base;
  }
  sib_nomul(uint32_t disp32) {
    ss=0, index=esp, base=ebp, disp=disp32;
  }
};
