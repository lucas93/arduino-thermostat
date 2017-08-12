#pragma once

#include <Utilities.h>

class Thermostat
{
public:
  Thermostat();
  ~Thermostat();
  Thermostat(const Thermostat& other) = delete;

  void loop();

private:
  class ThermostatImpl;
  owner<ThermostatImpl> pimpl = nullptr;
};
