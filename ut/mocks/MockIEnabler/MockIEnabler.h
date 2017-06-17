#include <IEnabler.h>

class MockIEnabler : public IEnabler {
 public:
  MOCK_METHOD0(isEnabled,
      bool());
};
