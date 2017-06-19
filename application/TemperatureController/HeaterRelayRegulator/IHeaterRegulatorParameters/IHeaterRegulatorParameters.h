#pragma once

#include <Utilities.h>
#include <ISensor.h>

namespace heater
{

struct IHeaterRegulatorParameters
{
  using Unit = ISensor::Unit;
  virtual Unit deadzone() const = 0;
};

} // namepsace heater
