#pragma once
#include <IOutput.h>
#include <ISetpoint.h>
#include <ISensor.h>

struct IRegulator
{
  virtual void controllOutput(IOutput& output,
                              const ISetpoint& setpoint,
                              const ISensor& sensor) = 0;
};
