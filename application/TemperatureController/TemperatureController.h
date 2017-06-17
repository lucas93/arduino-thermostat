#pragma once

#include <IController.h>

class TemperatureController : public IController
{
public:
  template< typename... Args>
  TemperatureController(IOutput& output,
                        ISensor& sensor,
                        IRegulator& regulator,
                        ISetpoint& setpoint,
                        IEnabler& enabler)
    : IController(output,
                  sensor,
                  regulator,
                  setpoint,
                  enabler) {}

  virtual void setup() override;
  virtual void loop() override;

private:
};


