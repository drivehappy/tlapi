#pragma once

struct CString
{
  union {
    wchar_t string[8];      // In-place unicode data
    wchar_t* stringPtr[4];   // First is the unicode ptr, the rest are unk
  };

  u32 length;
  u32 lengthMax;    // Guess, double check this


  wchar_t* getString() {
    if (length > 7)
      return stringPtr[0];
    else if (length > 0)
      return string;
    else
      return L"";
  };
};
