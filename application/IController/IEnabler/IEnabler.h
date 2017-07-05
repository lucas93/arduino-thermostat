#pragma once
#include <Utilities.h>

//struct IEnabler
//{
//  virtual bool isEnabled() = 0;
//};

using IEnabler = util::unique_function< bool() >;
