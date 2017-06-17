#include <ISensor.h>

class MockISensor : public ISensor {
 public:
  MOCK_METHOD0(measurement,
      float());
};
