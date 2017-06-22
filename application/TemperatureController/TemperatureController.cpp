#include <TemperatureController.h>
#include <iostream>

using namespace heater;
using namespace std;

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
