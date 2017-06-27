#pragma once

namespace util
{

template <typename T>
using owner = T*;

template <typename T>
using pointer = T*;

template <typename T>
class scoped_owner // deletes owner when gets out of scope
{
  T* ptr = nullptr;

public:
  explicit scoped_owner (T* ptr) :
    ptr(ptr) {}

  scoped_owner(const scoped_owner<T>& other) = delete;
  scoped_owner<T> operator= (const scoped_owner<T>& other) = delete;

  ~scoped_owner()
  {
    if (ptr) delete ptr;
  }

  T operator*() { return *ptr; }
  T* operator->() { return ptr; }

  T* get() { return ptr; }

  T* release()
  {
    auto temp = get();
    ptr = nullptr;
    return temp;
  }
};


} // namespace util
