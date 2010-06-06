#pragma once

#include "out_buf.h"

class out_buf_ptr : public out_buf {
public:
  unsigned char*c,*oc;
  unsigned int chksum;

  out_buf_ptr(unsigned char *c);

  virtual void puc(uint8_t x);
  virtual void pus(uint16_t x);
  virtual void pui(uint32_t x);
  virtual uint32_t addr();
  bool operator!=(const out_buf_ptr&n);
};
