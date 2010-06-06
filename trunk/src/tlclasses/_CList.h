#pragma once

// This isn't explicitly defined as a runic structure, but from the common list structures encountered,
// it's structure is working

// Note: dengus already figured this out, underneath old List.h (c_runic_list)

template<typename T>
struct CList
{
  T     *list;

  u32   size;
  u32   capacity;
  u32   growth;

  T operator[](int index) {
    return list[index];
  };
};
