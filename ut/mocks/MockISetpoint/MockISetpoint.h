#include <Setpoint.h>

class MockISetpoint{
 public:
  MOCK_METHOD0(getSetpoint,
      Temp());
};
