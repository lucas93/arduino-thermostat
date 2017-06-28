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

template <typename T>
constexpr auto injectMock(T* ptr)
{
  return util::owner<T>(ptr);
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


