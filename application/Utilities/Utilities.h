#pragma once



#ifdef ARDUINO


#include "PrimitivesSizeDeployment.h"
#include <Unique_ptr.h>


#else // Unit Test


#include "PrimitivesSizeTesting.h"

using std::unique_ptr;
template <typename T>
auto injectMock(T* ptr)
{
  return std::unique_ptr<T>(ptr);
}


#endif



#define INJECTABLE_INTERFACE(TYPE, NAME) \
  private: \
  unique_ptr<TYPE>  NAME;\
  public: \
  void inject_##TYPE(std::unique_ptr<TYPE> arg) \
  {\
    NAME = move(arg);\
  }
