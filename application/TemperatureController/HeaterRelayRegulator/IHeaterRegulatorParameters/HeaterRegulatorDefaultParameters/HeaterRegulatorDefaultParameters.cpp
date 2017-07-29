#include <HeaterRegulatorDefaultParameters.h>

using namespace heater;

class HeaterRegulatorDefaultParameters : public IHeaterRegulatorParameters
{

public:
  HeaterRegulatorDefaultParameters(Temp deadZone) :
    deadzoneRange(deadZone) {}

  ~HeaterRegulatorDefaultParameters() = default;

  virtual Temp deadzone() const override
  {
    return deadzoneRange;
  }

private:
  Temp deadzoneRange = 0;
};

IHeaterRegulatorParameters* getHeaterRegulatorDefaultParameters()
{
  return new HeaterRegulatorDefaultParameters{5};
}

