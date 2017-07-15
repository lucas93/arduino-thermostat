#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <TemperatureController.h>
#include <MockIEnabler.h>
#include <MockIOutput.h>
#include <MockIRegulator.h>
#include <MockISensor.h>
#include <MockISetpoint.h>
#include <Utilities.h>

using namespace testing;
using namespace heater;
using namespace std;


//using BIND = std::bind;

struct TestTemperatureController : public Test
{
  MockIEnabler enabler {};
  MockIOutput* output = new MockIOutput();
  MockIRegulator* regulator = new MockIRegulator();
  MockISensor sensor {};
  MockISetpoint setpoint {};

  TemperatureController sut{injectMock(output),
                            bind(&MockISensor::measurement ,&sensor),
                            injectMock(regulator),
                            bind(&MockISetpoint::getSetpoint, &setpoint),
                            bind(&MockIEnabler::isEnabled, &enabler)
                           };

};


TEST_F(TestTemperatureController,
       WhenEnabled_ShouldAct)
{
  EXPECT_CALL(enabler, isEnabled())
      .WillOnce(Return(true));
  EXPECT_CALL(*regulator, controllOutput(_,_,_))
      .Times(AtLeast(1));

  sut.controlLoop();
}

TEST_F(TestTemperatureController,
       WhenNotEnabled_ShouldNotAct)
{
  EXPECT_CALL(enabler, isEnabled())
      .WillOnce(Return(false));
  EXPECT_CALL(*regulator, controllOutput(_,_,_))
      .Times(Exactly(0));

  sut.controlLoop();
}

