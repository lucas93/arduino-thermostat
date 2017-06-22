#pragma once

#include <memory>


#ifdef ARDUINO

  #include "PrimitivesSizeDeployment.h"

#else

  #include "PrimitivesSizeTesting.h"

#endif



#define INJECTABLE_INTERFACE(TYPE, NAME) \
  private: \
  std::unique_ptr<TYPE>  NAME;\
  public: \
  void inject_##TYPE(std::unique_ptr<TYPE> arg) \
  {\
    NAME = std::move(arg);\
  }
