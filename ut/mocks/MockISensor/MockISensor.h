#include <Sensor.h>

class MockISensor{
 public:
  MOCK_METHOD0(measurement,
      Temp());
};
