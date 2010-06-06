#include "Helper.h"

void xcept(const char *fmt, ...)
{
  static char xcept_str[0x100];

  va_list args;
  va_start(args, fmt);
  memset(xcept_str, 0, sizeof(xcept_str));
  //vsnprintf(xcept_str, sizeof(xcept_str)-1, fmt, args);
  vsnprintf_s(xcept_str, sizeof(xcept_str)-1, 0x100, fmt, args);
  throw (const char*)xcept_str;
}

double getLogTimer()
{
  static Timer logTimer;
  return logTimer.getTime();
}

void log(const char *fmt, ...)
{
  va_list args;
  va_start(args,fmt);
  string s = vformat(fmt,args);
  double t = getLogTimer();
  s = format("%4.3f  %s\n",t,s.c_str());
  printf("%s",s.c_str());
};

void log(const wchar_t* fmt, ...)
{
  va_list args;
  va_start(args,fmt);
  wstring s = vwformat(fmt, args);
  double t = getLogTimer();
  s = wformat(L"%4.3f  %s\n", t, s.c_str());
  wprintf(L"%s", s.c_str());
}

void logColor(const WORD colorFMT, const char *fmt, ...)
{
  static HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

  SetConsoleTextAttribute(hstdout, colorFMT);

  va_list args;
  va_start(args,fmt);
  string s = vformat(fmt,args);
  double t = getLogTimer();
  s = format("%4.3f  %s\n",t,s.c_str());
  printf("%s",s.c_str());

  SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}

void logColor(const WORD colorFMT, const wchar_t *fmt, ...)
{
  static HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

  SetConsoleTextAttribute(hstdout, colorFMT);

  va_list args;
  va_start(args,fmt);
  wstring s = vwformat(fmt, args);
  double t = getLogTimer();
  s = wformat(L"%4.3f  %s\n", t, s.c_str());
  wprintf(L"%s", s.c_str());

  SetConsoleTextAttribute(hstdout, csbi.wAttributes);
}

string format(const char *format, ...)
{
  string res("");
  va_list args;
  va_start(args,format);
  size_t len = _vscprintf(format,args);
  res.resize(len+1);
  char*buf = (char*)res.c_str();
  vsprintf_s(buf,len+1,format,args);
  //buf[len]='\0';
  return res.c_str();
}

wstring wformat(const wchar_t *format, ...)
{
  wstring res(L"");
  va_list args;
  va_start(args, format);
  size_t len = _vscwprintf(format, args);
  res.resize(len+1);
  wchar_t *buf = (wchar_t*)res.c_str();
  vswprintf_s(buf, len+2, format, args);
  
  return res.c_str();
}

string vformat(const char *format, va_list args)
{
  string res("");
  size_t len = _vscprintf(format,args);
  res.resize(len+1);
  char* buf = (char*)res.c_str();
  vsprintf_s(buf,len+1,format,args);
  //buf[len]='\0';
  return res.c_str();
}

wstring vwformat(const wchar_t *format, va_list args)
{
  wstring res(L"");
  size_t len = _vscwprintf(format, args);
  res.resize(len+2);
  wchar_t* buf = (wchar_t*)res.c_str();
  vswprintf_s(buf, len+2, format, args);
  //buf[len]='\0';
  return res.c_str();
}
