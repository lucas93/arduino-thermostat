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
  TemperatureController(unique_ptr<IOutput> output,
                        unique_ptr<ISensor> sensor,
                        unique_ptr<IRegulator> regulator,
                        unique_ptr<ISetpoint> setpoint,
                        unique_ptr<IEnabler> enabler) :
    output(move(output)),
    sensor(move(sensor)),
    regulator(move(regulator)),
    setpoint(move(setpoint)),
    enabler(move(enabler))
  { }

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
