#include "out_buf_ptr.h"

out_buf_ptr::out_buf_ptr(unsigned char *c)
: c(c), oc(c), chksum(0)
{
}

void out_buf_ptr::puc(uint8_t x)
{
  chksum+=x;*c++=x;
}

void out_buf_ptr::pus(uint16_t x)
{
  chksum+=x;
  *(uint16_t*)c=(uint16_t)(x);
  c+=2;
}

void out_buf_ptr::pui(uint32_t x)
{
  chksum+=x;
  *(uint32_t*)c=(uint32_t)(x);
  c+=4;
}

uint32_t out_buf_ptr::addr()
{
  return (uint32_t)c;
}

bool out_buf_ptr::operator!=(const out_buf_ptr &n)
{
  return c!=n.c||oc!=n.oc||chksum!=n.chksum;
}
