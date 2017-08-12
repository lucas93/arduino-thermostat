#include <TemperatureController.h>
#include <Relay.h>
#include <TemperatureSensor.h>
#include <TemperatureSetpoint.h>

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

owner<TemperatureController> TemperatureController::getDefaultInstance()
{
  owner<TemperatureController> tempController;

//  auto output = getDefaultRelayInstance();
//  auto sensor = getDefaultTemperatureSensor();
//  auto setpoint = getDefaultTemperatureSetpoint();

  return {};
}
