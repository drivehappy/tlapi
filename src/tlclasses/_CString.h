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

/*
Only difference I see is there's another ptr in front, this sometimes
corresponds to a ptr to another string e.g.:
      debug159:0B7D0898 unicode 0, <You have |cFFFFBA00completed a quest|u. To receive your r>
      debug159:0B7D0898 unicode 0, <eward, travel back to the town and speak to the individua>
      debug159:0B7D0898 unicode 0, <l with a |cFFFFBA00?|u above their head. Use a |cFFFFBA00>
      debug159:0B7D0898 unicode 0, <Town Portal Scroll|u to return directly to Torchlight. >,0
*/
struct CString2
{
  wchar_t* firstStringPtr;

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
