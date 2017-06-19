#pragma once

#include <ISensor.h>
#include <IEnabler.h>
#include <IOutput.h>
#include <IRegulator.h>
#include <ISetpoint.h>
#include <IController.h>
#include <Utilities.h>

class TemperatureController : public IController
{
public:
  TemperatureController(IOutput& output,
                        ISensor& sensor,
                        IRegulator& regulator,
                        ISetpoint& setpoint,
                        IEnabler& enabler)
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
  IOutput& output;
  ISensor& sensor;
  IRegulator& regulator;
  ISetpoint& setpoint;
  IEnabler& enabler;
};
