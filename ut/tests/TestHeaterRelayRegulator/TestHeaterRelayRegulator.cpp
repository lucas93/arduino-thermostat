#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <HeaterRegulator.h>
#include <MockIHeaterRegulatorParameters.h>
#include <MockIOutput.h>
#include <MockISetpoint.h>
#include <MockISensor.h>
#include <Utilities.h>
#include <iostream>

using namespace testing;
using namespace std;

namespace heater
{

constexpr Temp defaultDeadzone = 1.0;

struct TestHeaterRegulator : public Test
{
  MockIHeaterRegulatorParameters* parameters = new MockIHeaterRegulatorParameters();
  MockISetpoint setpointMock;
  StrictMock<MockIOutput> outputMock;
  MockISensor sensorMock;
  Setpoint getSetpoint{ [&](){ return setpointMock.getSetpoint(); } };
  Sensor getMeasurement{ [&](){ return sensorMock.measurement(); } };
  HeaterRegulator sut{injectMock(parameters)};

  TestHeaterRegulator()
  {
    ON_CALL(*parameters, deadzone()).WillByDefault(Return( defaultDeadzone ))  ;
  }

};



TEST_F(TestHeaterRegulator,
       WhenMeasurementAboveSetpoint_ShouldSetOffOutput)
{
  EXPECT_CALL(setpointMock, getSetpoint()).WillOnce(Return(25.f));
  EXPECT_CALL(sensorMock, measurement()).WillOnce(Return(27.f));
  EXPECT_CALL(outputMock, setOff());

  sut.controllOutput(outputMock, getSetpoint, getMeasurement);
}

TEST_F(TestHeaterRegulator,
       WhenMeasurementBelowSetpoint_ShouldSetOnOutput)
{
  EXPECT_CALL(setpointMock, getSetpoint()).WillOnce(Return(27.f));
  EXPECT_CALL(sensorMock, measurement()).WillOnce(Return(25.f));
  EXPECT_CALL(outputMock, setOn());

  sut.controllOutput(outputMock, getSetpoint, getMeasurement);
}

struct A {};
struct B : public A {};
struct C {};


TEST_F(TestHeaterRegulator,
       WhenMeasurementInDeadzone_ShouldntSetOutput)
{
  constexpr Temp deadzone = 1.0;
  constexpr Temp setpoint = 25.0;

  EXPECT_CALL(*parameters, deadzone());
  EXPECT_CALL(setpointMock, getSetpoint()).WillOnce(Return(setpoint));
  EXPECT_CALL(sensorMock, measurement()).WillOnce(Return(setpoint + (deadzone  / 2)));

  sut.controllOutput(outputMock, getSetpoint, getMeasurement);
}


} // namespace heater
