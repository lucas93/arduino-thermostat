#pragma once

#include <ISetupable.h>

struct ISensor
{
  virtual float measurement() = 0;
};
