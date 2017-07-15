#include <Enabler.h>

class MockIEnabler {
 public:
  MOCK_METHOD0(isEnabled,
      bool());
};
