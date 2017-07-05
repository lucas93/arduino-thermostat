#pragma once
#include <DummySmartPointers.h>
#include <function.h>

using util::owner;
using util::scoped_owner;
using util::pointer;
using util::function;

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
  util::scoped_owner<TYPE>  NAME;\
  public: \
  void inject_##TYPE(util::owner<TYPE> arg) \
  {\
    NAME.reassign(arg);\
  }

#define INJECTABLE_FUNCTOR(FUNCTOR_TYPE, NAME) \
  private: \
  FUNCTOR_TYPE  NAME;\
  public: \
  void inject_##NAME(FUNCTOR_TYPE&& arg) \
  {\
    NAME = util::move(arg);\
  }


