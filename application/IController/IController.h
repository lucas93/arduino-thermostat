#pragma once

#include <ISensor.h>
#include <IEnabler.h>
#include <IOutput.h>
#include <IRegulator.h>
#include <ISetpoint.h>
#include <ISetupable.h>

class IController : public ISetupable
{
public:
  IController(IOutput& output,
              ISensor& sensor,
              IRegulator& regulator,
              ISetpoint& setpoint,
              IEnabler& enabler)
    :
      output(output),
      sensor(sensor),
      regulator(regulator),
      setpoint(setpoint),
      enabler(enabler)
  {}
  virtual ~IController() {}

  virtual void loop() = 0;

private:
  IOutput& output;
  ISensor& sensor;
  IRegulator& regulator;
  ISetpoint& setpoint;
  IEnabler& enabler;
};
