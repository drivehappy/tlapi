#include "modrm_dispx.h"

modrm_dispx::modrm_dispx(reg _r, reg _rm,uint32_t disp)
{
  r=_r; rm=_rm; imm=disp;
  if (disp==0&&_rm!=ebp) mod=0;
  else if ((int8_t)disp==disp) {mod=1;has_imm8=true;}
  else {mod=2; has_imm32=true;}
  //if (_rm==esp) bad :(
}
  
modrm_dispx::modrm_dispx(reg _r,uint32_t disp, sib _s)
{
  r=_r; rm=esp; imm=disp; s = _s;;
  has_sib=true;
  if (disp==0) mod=0;
  else if ((int8_t)disp==disp) {mod=1;has_imm8=true;}
  else {mod=2; has_imm32=true;}
}
