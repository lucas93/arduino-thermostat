#include <Thermostat.h>
#include <TemperatureController.h>

using namespace heater;

class Thermostat::ThermostatImpl
{
public:
  ThermostatImpl()
  {
    tempController.reset( TemperatureController::getDefaultInstance() );
  }

  void loop()
  {

  }

private:
  unique_ptr<TemperatureController> tempController { nullptr };

};


Thermostat::Thermostat() : pimpl()
{}

Thermostat::~Thermostat()
{
  if(pimpl) delete pimpl;
}

void Thermostat::loop()
{
  pimpl->loop();
}

