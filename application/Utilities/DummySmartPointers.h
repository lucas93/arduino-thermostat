#pragma once
#include <function.h>
#include <is_base_of.h>

namespace util
{

template <typename T>
using owner = T*;

template <typename T>
using pointer = T*;

//template <typename T>
//class scoped_owner // deletes owner when gets out of scope
//{
//  T* ptr = nullptr;

//public:
//  explicit scoped_owner (T* ptr) :
//    ptr(ptr) {}

//  scoped_owner(const scoped_owner<T>& other) = delete;
//  scoped_owner<T> operator= (const scoped_owner<T>& other) = delete;

//  ~scoped_owner()
//  {
//    if (ptr) delete ptr;
//  }

//  T& operator*() { return *ptr; }
//  T* operator->() { return ptr; }

//  T* get() { return ptr; }

//  T* release()
//  {
//    auto temp = get();
//    ptr = nullptr;
//    return temp;
//  }

//  void reset(T* newPtr)
//  {
//    if(ptr) delete ptr;

//    ptr = newPtr;
//  }
//};



template< typename T>
using Deleter = void (*)(T*);

template< typename T>
void Delete(T* t) { delete t; }

template< typename T>
void dontDelete(T*) {  }

template <typename T>
class unique_ptr
{
  T* ptr = nullptr;
  using Deleter = void (*)(T*);
  Deleter deleter;

public:
  explicit unique_ptr (T* ptr, Deleter deleter = Delete<T>) :
    ptr(ptr),
    deleter(deleter){}
  unique_ptr() : unique_ptr(nullptr, Delete<T>) {}

  unique_ptr(const unique_ptr<T>& other) = delete;
  unique_ptr<T> operator= (const unique_ptr<T>& other) = delete;
  unique_ptr<T>& operator= (unique_ptr<T>&& other)
  {
    if (ptr) deleter(ptr);
    ptr = other.ptr;
    deleter = other.deleter;
    other.ptr = nullptr;

    return *this;
  }

  unique_ptr(unique_ptr<T>&& other) :
    ptr(util::move(other.ptr)),
    deleter(util::move(other.deleter))
  {
    other.ptr = nullptr;
  }


  ~unique_ptr()
  {
    if (ptr) deleter(ptr);
  }

  T& operator*() { return *ptr; }
  T* operator->() { return ptr; }

  T* get() { return ptr; }

  T* release()
  {
    auto temp = get();
    ptr = nullptr;
    return temp;
  }

  void reset(T* newPtr, Deleter newDeleter = Delete<T>)
  {
    if(ptr) deleter(ptr);

    ptr = newPtr;
    deleter = newDeleter;
  }
};

template<typename T, typename... Args >
decltype(auto) make_unique(Args&&... args)
{
  return unique_ptr<T>(new T(forward<Args>(args)...));
}

} // namespace util
