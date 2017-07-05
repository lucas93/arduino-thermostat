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
  TemperatureController(owner<IOutput> output,
                        owner<ISensor> sensor,
                        owner<IRegulator> regulator,
                        owner<ISetpoint> setpoint,
                        IEnabler isEnabled) :
    output(output),
    sensor(sensor),
    regulator(regulator),
    setpoint(setpoint),
    isEnabled(util::move(isEnabled))
  { }

  virtual ~TemperatureController(){}

  virtual void setup() override;
  virtual void controlLoop() override;

private:
  INJECTABLE_INTERFACE(IOutput, output);
  INJECTABLE_INTERFACE(ISensor, sensor);
  INJECTABLE_INTERFACE(IRegulator, regulator);
  INJECTABLE_INTERFACE(ISetpoint, setpoint);
  INJECTABLE_FUNCTOR(IEnabler, isEnabled);
};

} // namespace heater
