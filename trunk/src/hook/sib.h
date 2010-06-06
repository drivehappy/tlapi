#pragma once

#include "gencommon.h"
#include "out_buf.h"

class sib {
public:
  int ss,index,base;
  uint32_t disp;

  sib();
  sib(int ss,int index,int base);

  void mk(out_buf *c) const;
};
