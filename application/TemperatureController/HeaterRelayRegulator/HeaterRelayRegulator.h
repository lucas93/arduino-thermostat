#pragma once

#include <IRegulator.h>
#include <IHeaterRegulatorParameters.h>
#include <Utilities.h>

namespace heater
{

class HeaterRelayRegulator : public IRegulator
{
public:
  HeaterRelayRegulator(owner<IHeaterRegulatorParameters> parameters)
    : parameters(parameters)
  {}

  virtual void controllOutput(IOutput &output,
                              Setpoint& getSetpoint,
                              Sensor& getMeasurement) override;
private:
  INJECTABLE_INTERFACE(IHeaterRegulatorParameters, parameters);

};

} // namespace heater
