#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <TemperatureController.h>
#include <MockIEnabler.h>
#include <MockIOutput.h>
#include <MockIRegulator.h>
#include <MockISensor.h>
#include <MockISetpoint.h>

using namespace testing;

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

TEST_F(TestTemperatureController, configTest)
{
  sut.inject_IRegulator(&regulator);
  sut.controlLoop();
}


