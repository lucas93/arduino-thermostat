#include <ISetpoint.h>

class MockISetpoint : public ISetpoint {
 public:
  MOCK_METHOD0(getSetpoint,
      float());
};
