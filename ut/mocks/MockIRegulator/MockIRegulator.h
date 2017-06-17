#include <IRegulator.h>

class MockIRegulator : public IRegulator {
 public:
  MOCK_METHOD1(controllOutput,
      void(IOutput& output));
};
