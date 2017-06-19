#pragma once

#include <IRegulator.h>
#include <Utilities.h>

namespace heater
{

class HeaterRelayRegulator : public IRegulator
{
public:
  HeaterRelayRegulator() {}

  virtual void controllOutput(IOutput &output,
                              const ISetpoint &setpoint,
                              const ISensor &sensor) override;

};

} // namespace heater
