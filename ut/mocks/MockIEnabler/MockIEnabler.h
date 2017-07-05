#include <IEnabler.h>

class MockIEnabler {
 public:
  MOCK_METHOD0(isEnabled,
      bool());
};
