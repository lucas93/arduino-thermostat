#include <TemperatureController.h>

void TemperatureController::setup()
{

}

void TemperatureController::controlLoop()
{
  regulator.controllOutput(output);
}
