#pragma once

#include "out_buf.h"

class out_buf_nop : public out_buf {
public:
  uint32_t size;
  unsigned int chksum;

  out_buf_nop();
  virtual void puc(uint8_t x);
  virtual void pus(uint16_t x);
  virtual void pui(uint32_t x);
  virtual uint32_t addr();
  bool operator!=(const out_buf_nop &n);
};
