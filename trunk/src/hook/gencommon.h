#pragma once

#include "udis86.h"

enum reg {badreg=-1,eax=0,ecx=1,edx=2,ebx=3,esp=4,ebp=5,esi=6,edi=7};
enum cc_codes { cc_eq, cc_ne, cc_gt, cc_gtu, cc_lt, cc_ltu, cc_ge, cc_geu, cc_le, cc_leu };

#define x1(x) c->puc((uint8_t)(x))
#define x2(x) c->pus((uint16_t)(x))
#define x4(x) c->pui(x)
#define xaddr c->addr()
