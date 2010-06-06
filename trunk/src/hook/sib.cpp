#include "sib.h"

sib::sib()
{
}

sib::sib(int ss,int index,int base)
: ss(ss), index(index), base(base)
{
}

void sib::mk(out_buf*c) const
{
  x1(ss<<6|index<<3|base);
}
