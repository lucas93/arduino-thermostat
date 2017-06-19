#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <TemperatureController.h>
#include <MockIEnabler.h>
#include <MockIOutput.h>
#include <MockIRegulator.h>
#include <MockISensor.h>
#include <MockISetpoint.h>

using namespace testing;
using namespace heater;

struct TestTemperatureController : public Test
{
  MockIEnabler enabler;
  MockIOutput output;
  MockIRegulator regulator;
  MockISensor sensor;
  MockISetpoint setpoint;
  TemperatureController sut{&output,
                            &sensor,
                            &regulator,
                            &setpoint,
                            &enabler
                           };
};

TEST_F(TestTemperatureController,
       WhenNotEnabled_ShouldNotAct)
{
  EXPECT_CALL(enabler, isEnabled())
      .WillOnce(Return(false));
  EXPECT_CALL(regulator, controllOutput(_,_,_))
      .Times(Exactly(0));

  sut.controlLoop();
}

TEST_F(TestTemperatureController,
       WhenEnabled_ShouldAct)
{
  EXPECT_CALL(enabler, isEnabled())
      .WillOnce(Return(true));
  EXPECT_CALL(regulator, controllOutput(_,_,_))
      .Times(AtLeast(1));

  sut.controlLoop();
}


