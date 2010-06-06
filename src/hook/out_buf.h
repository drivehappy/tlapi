#pragma once

#include "gencommon.h"

class out_buf {
public:
  virtual void puc(uint8_t) = 0;
  virtual void pus(uint16_t) = 0;
  virtual void pui(uint32_t) = 0;
  virtual uint32_t addr() = 0;
};
