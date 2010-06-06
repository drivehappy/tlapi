#pragma once

// Ignore deprecated functions
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_DEPRECATE 1
#pragma warning(disable : 4996)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")
/*
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "ExternalLibs/cegui/lib/CEGUIBase.lib")
#pragma comment(lib, "ExternalLibs/google/lib/libprotobuf.lib")

#if defined(_DEBUG)
  #pragma comment(lib, "ExternalLibs/raknet/lib/RakNetLibStaticDebug.lib")
#else
  #pragma comment(lib, "ExternalLibs/raknet/lib/RakNetLibStatic.lib")
#endif
*/

#include <string>
#include <stack>
#include <vector>
using namespace std;

#include <math.h>

#include "DataTypes.h"
#include "Helper.h"
#include "Hook.h"
#include "Offsets.h"

#define STDARG (TLMP::HookStruct *e, TLMP::HookFunctionDef *_f)
#define Pz e->arg
#define Ud e->user
#define rPz e->ref_arg
