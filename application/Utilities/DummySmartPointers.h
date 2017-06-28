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

  T& operator*() { return *ptr; }
  T* operator->() { return ptr; }

  T* get() { return ptr; }

  T* release()
  {
    auto temp = get();
    ptr = nullptr;
    return temp;
  }

  void reassign(T* newPtr)
  {
    if(ptr) delete ptr;

    ptr = newPtr;
  }
};


template< class T > struct remove_reference      {typedef T type;};
template< class T > struct remove_reference<T&>  {typedef T type;};
template< class T > struct remove_reference<T&&> {typedef T type;};

template< class T >
constexpr typename remove_reference<T>::type&& move( T&& t ) noexcept
{
  return static_cast<typename remove_reference<T>::type&&>(t);
}




template< class T >
constexpr T&& forward( typename remove_reference<T>::type&& t ) noexcept
{
  return static_cast<T&&>(t);
}

template< class T >
constexpr T&& forward( typename remove_reference<T>::type& t ) noexcept
{
  return static_cast<T&&>(t);
}




template<class T, class U>
struct is_same
{
  const static bool value = false;
};

template<class T>
struct is_same<T, T>
{
  const static bool value = true;
};

} // namespace util
