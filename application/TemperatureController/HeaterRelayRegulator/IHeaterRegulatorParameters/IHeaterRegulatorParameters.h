#pragma once

#include <Utilities.h>
#include <Sensor.h>

namespace heater
{

struct IHeaterRegulatorParameters
{
  virtual Unit deadzone() const = 0;
};

} // namepsace heater
