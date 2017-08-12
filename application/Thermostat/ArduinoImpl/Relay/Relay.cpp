#include <Relay.h>
#include <DummySmartPointers.h>

namespace heater
{


// TODO: real relay impl
class Relay : public IOutput
{
public:
  Relay() {}

  virtual void setOn() override
  {}
  virtual void setOff() override
  {}

private:

};

unique_ptr<IOutput> getDefaultRelayInstance()
{
  return unique_ptr<IOutput>(new Relay{});
}

} //namespace heater
