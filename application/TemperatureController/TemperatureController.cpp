#include <TemperatureController.h>

using namespace heater;

void TemperatureController::setup()
{

}

void TemperatureController::controlLoop()
{
  if(enabler->isEnabled())
  {
    regulator->controllOutput(*output,
                              *setpoint,
                              *sensor);
  }
}
