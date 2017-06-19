#pragma once

#include <ISensor.h>
#include <IEnabler.h>
#include <IOutput.h>
#include <IRegulator.h>
#include <ISetpoint.h>
#include <IController.h>
#include <Utilities.h>

namespace heater
{

class TemperatureController : public IController
{
public:
  TemperatureController(IOutput* output,
                        ISensor* sensor,
                        IRegulator* regulator,
                        ISetpoint* setpoint,
                        IEnabler* enabler)
    : output(output),
      sensor(sensor),
      regulator(regulator),
      setpoint(setpoint),
      enabler(enabler)
  {}
  virtual ~TemperatureController(){}

  virtual void setup() override;
  virtual void controlLoop() override;

private:
  INJECTABLE_INTERFACE(IOutput, output);
  INJECTABLE_INTERFACE(ISensor, sensor);
  INJECTABLE_INTERFACE(IRegulator, regulator);
  INJECTABLE_INTERFACE(ISetpoint, setpoint);
  INJECTABLE_INTERFACE(IEnabler, enabler);
};

} // namespace heater
