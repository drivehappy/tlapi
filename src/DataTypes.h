#pragma once

#include <windows.h>
#define WIN32_LEAN_AND_MEAN

#ifdef _WIN64
#define X64
#endif

#undef max
#undef min

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned long ulong;
typedef unsigned char uchar;
typedef uchar byte;
typedef ushort word;
typedef ulong dword;
typedef unsigned long long qword;

typedef char int8;
typedef short int16;
typedef long int32;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
#ifdef _MSC_VER
typedef unsigned __int64 uint64;
#else
typedef unsigned long long uint64;
#endif

typedef uint index_t;

#ifdef X64
typedef uint64 ptr_t;
#else
typedef uint32 ptr_t;
#endif

typedef char                s8;
typedef short               s16;
typedef long                s32;
typedef unsigned char       u8;
typedef unsigned short      u16;
typedef unsigned long       u32;
typedef unsigned long long  u64;
template<class t>
class be_v {
public:
  t n;
  static u8 convert8(u8 n) {return n;}
  static u8 convert(u8 n) {return n;}
  static u16 convert16(u16 n) {return ((n&0xFF)<<8)|((n&0xFF00)>>8);}
  static u16 convert(u16 n) {return ((n&0xFF)<<8)|((n&0xFF00)>>8);}
  static u32 convert32(u32 n) {return ((n&0xFF)<<24)|((n&0xFF00)<<8)|((n&0xFF0000)>>8)|((n&0xFF000000)>>24);}
  static u32 convert(u32 n) {return ((n&0xFF)<<24)|((n&0xFF00)<<8)|((n&0xFF0000)>>8)|((n&0xFF000000)>>24);}
  be_v(t nn) : n(convert(nn)) {}
  operator t() {return convert(n);}
  be_v() {} 
};
typedef be_v<s8> ns8;
typedef be_v<s16> ns16;
typedef be_v<s32> ns32;
typedef be_v<u8> nu8;
typedef be_v<u16> nu16;
typedef be_v<u32> nu32;

typedef void* PVOID;

__declspec(align(1))
struct Vector3 {
  float x, y, z;
};

#define NULL 0
