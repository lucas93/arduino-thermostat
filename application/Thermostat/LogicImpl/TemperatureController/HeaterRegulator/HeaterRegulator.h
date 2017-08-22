#pragma once

#include <IRegulator.h>
#include <IHeaterRegulatorParameters.h>
#include <Utilities.h>

namespace heater
{

class HeaterRegulator : public IRegulator
{
public:
  HeaterRegulator(util::unique_ptr<IHeaterRegulatorParameters> parameters)
    : parameters(util::move(parameters))
  {}

  virtual void controllOutput(IOutput &output,
                              Setpoint& getSetpoint,
                              Sensor& getMeasurement) override;
private:
  INJECTABLE_INTERFACE(IHeaterRegulatorParameters, parameters);

};

} // namespace heater
