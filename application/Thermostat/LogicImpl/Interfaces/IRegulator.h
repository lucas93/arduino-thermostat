#pragma once
#include <IOutput.h>
#include <Setpoint.h>
#include <Sensor.h>

struct IRegulator
{
  virtual void controllOutput(IOutput& output,
                              Setpoint& getSetpoint,
                              Sensor& getMeasurement) = 0;
  virtual ~IRegulator() = default;
};
