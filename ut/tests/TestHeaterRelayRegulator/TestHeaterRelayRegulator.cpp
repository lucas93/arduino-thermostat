#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <HeaterRelayRegulator.h>
#include <MockIHeaterRegulatorParameters.h>
#include <Utilities.h>
#include <iostream>

using namespace testing;
using namespace std;

namespace heater
{

struct TestHeaterRelayRegulator : public Test
{
  MockIHeaterRegulatorParameters* parameters = new MockIHeaterRegulatorParameters();
  HeaterRelayRegulator sut{injectMock(parameters)};
};



TEST_F(TestHeaterRelayRegulator,
       Given_When_Should)
{


}

} // namespace heater
