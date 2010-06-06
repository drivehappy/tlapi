#include "out_buf_nop.h"

out_buf_nop::out_buf_nop()
: size(0), chksum(0)
{
}

void out_buf_nop::puc(uint8_t x)
{
  chksum+=x;
  size++;
}

void out_buf_nop::pus(uint16_t x)
{
  chksum+=x;
  size+=2;
}

void out_buf_nop::pui(uint32_t x)
{
  chksum+=x;
  size+=4;
}

uint32_t out_buf_nop::addr()
{
  return 0x10000000 + size;
}

bool out_buf_nop::operator !=(const out_buf_nop &n)
{
  return size!=n.size||chksum!=n.chksum;
}
