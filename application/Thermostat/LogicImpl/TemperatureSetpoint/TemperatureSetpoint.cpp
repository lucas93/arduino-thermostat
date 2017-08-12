#include <TemperatureSetpoint.h>

using namespace heater;

Setpoint getDefaultTemperatureSetpoint()
{
  return { []()
    {
      return Temp{ 20.0 };
    } };
}
