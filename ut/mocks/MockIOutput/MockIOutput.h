#include <IOutput.h>

class MockIOutput : public IOutput {
 public:
  MOCK_METHOD0(setOn,
      void());
  MOCK_METHOD0(setOff,
      void());
};
