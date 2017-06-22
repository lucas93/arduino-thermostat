#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <HeaterRelayRegulator.h>
#include <MockIHeaterRegulatorParameters.h>

using namespace testing;
using namespace std;

namespace heater
{

struct TestHeaterRelayRegulator : public Test
{
  HeaterRelayRegulator sut{unique_ptr<MockIHeaterRegulatorParameters>()};
};


TEST_F(TestHeaterRelayRegulator,
       Given_When_Should)
{

}

} // namespace heater
