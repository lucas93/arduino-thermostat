#pragma once

#include <Sensor.h>
#include <Enabler.h>
#include <IOutput.h>
#include <IRegulator.h>
#include <Setpoint.h>
#include <IController.h>
#include <Utilities.h>

namespace heater
{

class TemperatureController : public IController
{
public:
  TemperatureController(owner<IOutput> output,
                        Sensor getMeasurement,
                        owner<IRegulator> regulator,
                        Setpoint getSetpoint,
                        Enabler isEnabled) :
    output(output),
    getMeasurement(util::move(getMeasurement)),
    regulator(regulator),
    getSetpoint(util::move(getSetpoint)),
    isEnabled(util::move(isEnabled))
  { }

  virtual ~TemperatureController(){}

  virtual void setup() override;
  virtual void controlLoop() override;

private:
  INJECTABLE_INTERFACE(IOutput, output);
  INJECTABLE_FUNCTOR(Sensor, getMeasurement);
  INJECTABLE_INTERFACE(IRegulator, regulator);
  INJECTABLE_FUNCTOR(Setpoint, getSetpoint);
  INJECTABLE_FUNCTOR(Enabler, isEnabled);
};

} // namespace heater
