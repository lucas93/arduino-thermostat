#include <TemperatureController.h>

using namespace heater;

void TemperatureController::setup()
{

}

void TemperatureController::controlLoop()
{
  if(isEnabled())
  {
    regulator->controllOutput(*output,
                              getSetpoint,
                              getMeasurement);
  }
}
