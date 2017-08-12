#include <HeaterRegulatorDefaultParameters.h>

namespace heater {

class MockIHeaterRegulatorParameters : public IHeaterRegulatorParameters {
 public:
  MOCK_CONST_METHOD0(deadzone,
      Temp());
};

}  // namespace heater
