#include <TemperatureSensor.h>

using namespace heater;


// TODO: impl default ArduinoTemperatureSensor
Sensor getDefaultTemperatureSensor()
{
  return { []()
    {
      return Temp{ 20 };
    } };
}
