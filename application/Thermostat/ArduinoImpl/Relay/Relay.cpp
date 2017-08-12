#include <Relay.h>

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

owner<IOutput> getRelayInstance()
{
  return new Relay{} ;
}

} //namespace heater
