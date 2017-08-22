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
  TemperatureController(util::unique_ptr<IOutput> output,
                        Sensor getMeasurement,
                        util::unique_ptr<IRegulator> regulator,
                        Setpoint getSetpoint,
                        Enabler isEnabled) :
    output(util::move(output)),
    getMeasurement(util::move(getMeasurement)),
    regulator(util::move(regulator)),
    getSetpoint(util::move(getSetpoint)),
    isEnabled(util::move(isEnabled))
  { }

  virtual ~TemperatureController() = default;

  virtual void setup() override;
  virtual void controlLoop() override;

  static util::unique_ptr<TemperatureController> getDefaultInstance();

private:
  INJECTABLE_INTERFACE(IOutput, output);
  INJECTABLE_FUNCTOR(Sensor, getMeasurement);
  INJECTABLE_INTERFACE(IRegulator, regulator);
  INJECTABLE_FUNCTOR(Setpoint, getSetpoint);
  INJECTABLE_FUNCTOR(Enabler, isEnabled);
};

} // namespace heater
