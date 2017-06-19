#pragma once

#include <ISetupable.h>
#include <Utilities.h>

struct ISensor
{
  using Unit = f32;
  virtual Unit measurement() = 0;
};
