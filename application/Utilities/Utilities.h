#pragma once

#define INJECTABLE_INTERFACE(TYPE, NAME) \
  public: \
  TYPE * NAME;\
  private: \
  void inject_##TYPE(TYPE arg) \
  {\
    NAME = arg;\
  }

#ifdef ARDUINO
  #include "PrimitivesSizeDeployment.h"
#else
  #include "PrimitivesSizeTesting.h"
#endif

