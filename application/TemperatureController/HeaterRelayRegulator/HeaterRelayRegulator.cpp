#include <HeaterRelayRegulator.h>
#include <Utilities.h>

using namespace heater;

void HeaterRelayRegulator::controllOutput(IOutput &output,
                                          Setpoint& getSetpoint,
                                          Sensor& getMeasurement)
{
  const auto delta = getSetpoint() - getMeasurement();
  const auto deadzone = parameters->deadzone();

  if(delta < -deadzone) output.setOff();
  else if(deadzone < delta) output.setOn();
}
