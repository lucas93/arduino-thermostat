#include <HeaterRelayRegulator.h>
#include <Utilities.h>

using namespace heater;

void HeaterRelayRegulator::controllOutput(IOutput &output,
                                          const ISetpoint &setpoint,
                                          const ISensor &sensor)
{
  int* ptr = new int{5};
  int* ptr2 = util::move(ptr);
  delete ptr2;
}
