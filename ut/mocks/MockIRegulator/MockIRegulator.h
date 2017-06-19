#include <IRegulator.h>

class MockIRegulator : public IRegulator {
 public:
  MOCK_METHOD3(controllOutput,
      void(IOutput&, const ISetpoint&, const ISensor& ));
};
