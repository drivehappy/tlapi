#pragma once

#include <stdarg.h>
#include <string>
using namespace std;

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "Timer.h"
#include "DataTypes.h"

extern u32 exeBaseReal;
#define EXEBASE       0x400000
#define EXEOFFSET(o1) (((o1)-EXEBASE)+(exeBaseReal))

#define TLFUNC(v1, t1, c1, a1)          extern t1(c1 *v1)a1;
#define TLFUNCPTR(v1, t1, c1, a1, o1)   t1(c1 *TLMP::v1)a1 = ((t1(c1 *)a1)EXEOFFSET(o1));

const WORD B_RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
const WORD B_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
const WORD B_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;


void xcept(const char *fmt, ...);

static HANDLE h_log_file = INVALID_HANDLE_VALUE;
void log(const char *fmt, ...);
void log(const wchar_t *fmt, ...);

void logColor(const WORD colorFMT, const char *fmt, ...);
void logColor(const WORD colorFMT, const wchar_t *fmt, ...);

#define NL_ITERATE(var,type,list) for (slist_table<type>::iterator var(list);var.i!=list.size();++var)
string format(const char *format, ...);
string vformat(const char*format, va_list args);

wstring wformat(const wchar_t *format, ...);
wstring vwformat(const wchar_t *format, va_list args);
