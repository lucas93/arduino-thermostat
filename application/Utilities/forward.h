#pragma once

namespace util
{

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
