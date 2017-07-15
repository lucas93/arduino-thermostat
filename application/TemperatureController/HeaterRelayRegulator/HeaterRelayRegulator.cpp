#include <HeaterRelayRegulator.h>
#include <Utilities.h>

using namespace heater;

void HeaterRelayRegulator::controllOutput(IOutput &output,
                                          Setpoint& getSetpoint,
                                          Sensor& getMeasurement)
{
  const auto setpoint = getSetpoint();
  const auto sensorVal = getMeasurement();


}
