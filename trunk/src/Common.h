#pragma once

// Ignore deprecated functions
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_DEPRECATE 1
#pragma warning(disable : 4996)
#pragma warning(disable : 4800)

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "winmm.lib")

#include <string>
#include <stack>
#include <vector>
using namespace std;

#include <math.h>

#define STDARG (HookStruct *e, HookFunctionDef *_f)
#define Pz e->arg
#define Ud e->user
#define rPz e->ref_arg

#include "Helper.h"
//#include "Offsets.h"
#include "Events.h"
