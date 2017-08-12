#pragma once
#include <DummySmartPointers.h>
#include <function.h>
#include <is_base_of.h>

using util::owner;
using util::unique_ptr;
using util::pointer;
using util::function;
using util::is_base_of;

#ifdef ARDUINO


#include "PrimitivesSizeDeployment.h"


#else // Unit Test


#include "PrimitivesSizeTesting.h"
#include <functional>

using std::bind;


template <typename T>
constexpr auto injectMock(T* ptr)
{
  return util::owner<T>(ptr);
}


template <typename T, typename R, typename... Args>
constexpr auto injectFunctor(T& mock, R (T::*mockedFunction)(Args...))
{
  return [&](Args... args)
  {
    return (mock.*mockedFunction)(args...);
  };
}


#endif



//#define INJECTABLE_INTERFACE(TYPE, NAME) \
//  private: \
//  util::owner<TYPE>  NAME;\
//  public: \
//  void inject_##TYPE(util::owner<TYPE> arg) \
//  {\
//    NAME = (arg);\
//  }


#define INJECTABLE_INTERFACE(TYPE, NAME) \
  private: \
  util::unique_ptr<TYPE>  NAME;\
  public: \
  void inject_##TYPE(util::owner<TYPE> arg) \
  {\
    NAME.reset(arg);\
  }

#define INJECTABLE_FUNCTOR(FUNCTOR_TYPE, NAME) \
  private: \
  FUNCTOR_TYPE  NAME;\
  public: \
  void inject_##NAME(FUNCTOR_TYPE&& arg) \
  {\
    NAME = util::move(arg);\
  }

namespace util
{

template<typename T>
class OnlyStaticAllocated
{
    using byte = char;
public:
    template< int N, typename... Args>
    static T& getInstance(Args&&... args)
    {
      constexpr auto instanceSize = sizeof(T);
      static byte memory[instanceSize] = {0};

      T* instance = reinterpret_cast<T*>(memory);
      new (instance) T(util::forward<Args>(args)...);

      return *instance;
    }

    OnlyStaticAllocated(const OnlyStaticAllocated& other) = delete;
    OnlyStaticAllocated& operator=( const OnlyStaticAllocated& other) = delete;

protected:

    OnlyStaticAllocated() = default;

};



} // namespace util
