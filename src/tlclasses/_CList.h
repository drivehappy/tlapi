#pragma once

// This isn't explicitly defined as a runic structure, but from the common list 
// structures encountered its structure is working

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

  // Our own... too lazy to find the real one
  void push(T item) {
    if (size >= capacity) {
      if (growth == 0)
        return;   // Can't do it

      capacity += growth;

      // Create new list, copy old to new
      T *newList = new T[capacity];
      memcpy(newList, list, sizeof(T*) * size);

      // Delete old and replace with new
      delete[] list;
      list = newList;
    }

    // And finally push our item onto the list
    list[size++] = item;
  }
};
