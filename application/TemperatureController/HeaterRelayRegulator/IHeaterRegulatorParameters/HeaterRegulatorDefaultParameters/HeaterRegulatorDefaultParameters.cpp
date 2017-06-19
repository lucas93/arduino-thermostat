#include <HeaterRegulatorDefaultParameters.h>

using namespace heater;

class HeaterRegulatorDefaultParameters : public IHeaterRegulatorParameters
{

public:
  HeaterRegulatorDefaultParameters(Unit deadZone) :
    deadzoneRange(deadZone) {}


  virtual Unit deadzone() const override
  {
    return deadzoneRange;
  }

private:
  Unit deadzoneRange = 0;
};

IHeaterRegulatorParameters* getHeaterRegulatorDefaultParameters()
{
  return new HeaterRegulatorDefaultParameters{5};
}

