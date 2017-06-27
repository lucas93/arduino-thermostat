#pragma once
#include <DummySmartPointers.h>

using util::owner;
using util::scoped_owner;
using util::pointer;


#ifdef ARDUINO


#include "PrimitivesSizeDeployment.h"


#else // Unit Test


#include "PrimitivesSizeTesting.h"

template <typename T>
auto injectMock(T* ptr)
{
  return util::owner<T>(ptr);
}


#endif



#define INJECTABLE_INTERFACE(TYPE, NAME) \
  private: \
  util::owner<TYPE>  NAME;\
  public: \
  void inject_##TYPE(util::owner<TYPE> arg) \
  {\
    NAME = arg;\
  }
