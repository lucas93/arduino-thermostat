#pragma once

#include <Utilities.h>
#include <Sensor.h>

namespace heater
{

struct IHeaterRegulatorParameters
{
  virtual Temp deadzone() const = 0;
  virtual ~IHeaterRegulatorParameters() = default;
};

} // namepsace heater
