#pragma once

#include <memory>


#ifdef ARDUINO

#include "PrimitivesSizeDeployment.h"

#else // Unit Test

#include "PrimitivesSizeTesting.h"
template <typename T>
auto injectMock(T* ptr)
{
  return std::unique_ptr<T>(ptr);
}

#endif



#define INJECTABLE_INTERFACE(TYPE, NAME) \
  private: \
  std::unique_ptr<TYPE>  NAME;\
  public: \
  void inject_##TYPE(std::unique_ptr<TYPE> arg) \
  {\
    NAME = std::move(arg);\
  }
