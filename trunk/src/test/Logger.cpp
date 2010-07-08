#include "Logger.h"

using namespace Test;


Logger::Logger(const char* filename)
{
  SetLoggingLevel(Verbose);
  m_logTimer.reset();
  m_outFile.open(filename, ios_base::out);
}

Logger::~Logger()
{
  m_outFile.close();
}



wstring Logger::wFormat(const wchar_t *format, ...)
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

wstring Logger::wvFormat(const wchar_t *format, va_list args)
{
  wstring res(L"");
  size_t len = _vscwprintf(format, args);
  res.resize(len+2);
  wchar_t* buf = (wchar_t*)res.c_str();
  vswprintf_s(buf, len+2, format, args);
  
  return res.c_str();
}


void Logger::WriteLine(LoggingLevel level, const wchar_t* fmt, ...)
{
  // Don't log unneccessary stuff
  if (level < m_logLevel)
    return;

  if (level == Error) {
    const wchar_t errorString[] = L"ERROR";
    m_outFile.write(errorString, wcslen(errorString));
  }

  // We're good, dump it out
  va_list args;
  va_start(args,fmt);

  // Dump the time
  wstring time, s;
  double t = m_logTimer.getTime();
  time = wFormat(L"%4.3f", t);

  // Dump the actual log
  s = wvFormat(fmt, args);
  s = wFormat(L"%s", s.c_str());

  m_outFile << setiosflags(ios::left);
  m_outFile << setw(10) << time << s << endl;

  m_outFile.flush();
}

void Logger::Write(LoggingLevel level, const wchar_t* fmt, ...)
{
  // Don't log unneccessary stuff
  if (level < m_logLevel)
    return;

  if (level == Error) {
    const wchar_t errorString[] = L"ERROR";
    m_outFile.write(errorString, wcslen(errorString));
  }

  // We're good, dump it out
  va_list args;
  va_start(args,fmt);

  wstring s;

  // Dump the actual log
  s = wvFormat(fmt, args);
  s = wFormat(L"%s", s.c_str());

  m_outFile << setiosflags(ios::left);
  m_outFile << s;
}

void Logger::SetLoggingLevel(LoggingLevel level)
{
  m_logLevel = level;
}
