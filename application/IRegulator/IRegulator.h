#pragma once
#include <IOutput.h>

struct IRegulator
{
  virtual void controllOutput(IOutput& output) = 0;
};
