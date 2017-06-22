#pragma once

#include <IRegulator.h>
#include <IHeaterRegulatorParameters.h>
#include <Utilities.h>

namespace heater
{

class HeaterRelayRegulator : public IRegulator
{
public:
  HeaterRelayRegulator(std::unique_ptr<IHeaterRegulatorParameters> parameters)
    : parameters(std::move(parameters))
  {}

  virtual void controllOutput(IOutput &output,
                              const ISetpoint &setpoint,
                              const ISensor &sensor) override;
private:
  INJECTABLE_INTERFACE(IHeaterRegulatorParameters, parameters);

};

} // namespace heater
