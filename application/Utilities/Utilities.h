#pragma once

#define INJECTABLE_INTERFACE(TYPE, NAME) \
  private: \
  TYPE * NAME;\
  public: \
  void inject_##TYPE(TYPE * arg) \
  {\
    NAME = arg;\
  }

#ifdef ARDUINO
  #include "PrimitivesSizeDeployment.h"
#else
  #include "PrimitivesSizeTesting.h"
#endif

