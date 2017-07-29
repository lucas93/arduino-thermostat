#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <HeaterRelayRegulator.h>
#include <MockIHeaterRegulatorParameters.h>
#include <MockIOutput.h>
#include <MockISetpoint.h>
#include <MockISensor.h>
#include <Utilities.h>
#include <iostream>

using namespace testing;
using namespace std;

//IOutput &output,
//Setpoint& getSetpoint,
//Sensor& getMeasurement

namespace heater
{

struct TestHeaterRelayRegulator : public Test
{
  MockIHeaterRegulatorParameters* parameters = new MockIHeaterRegulatorParameters();
  MockISetpoint setpointMock;
  StrictMock<MockIOutput> outputMock;
  MockISensor sensorMock;
  Setpoint getSetpoint{ [&](){ return setpointMock.getSetpoint(); } };
  Sensor getMeasurement{ [&](){ return sensorMock.measurement(); } };
  HeaterRelayRegulator sut{injectMock(parameters)};

  TestHeaterRelayRegulator()
  {
    ON_CALL(*parameters, deadzone()).WillByDefault(Return( defaultDeadzone ))  ;
  }

  const Temp defaultDeadzone = 1.0;
};



TEST_F(TestHeaterRelayRegulator,
       WhenMeasurementAboveSetpoint_ShouldSetOffOutput)
{
  EXPECT_CALL(setpointMock, getSetpoint()).WillOnce(Return(25.f));
  EXPECT_CALL(sensorMock, measurement()).WillOnce(Return(27.f));
  EXPECT_CALL(outputMock, setOff());

  sut.controllOutput(outputMock, getSetpoint, getMeasurement);
}

TEST_F(TestHeaterRelayRegulator,
       WhenMeasurementBelowSetpoint_ShouldSetOnOutput)
{
  EXPECT_CALL(setpointMock, getSetpoint()).WillOnce(Return(27.f));
  EXPECT_CALL(sensorMock, measurement()).WillOnce(Return(25.f));
  EXPECT_CALL(outputMock, setOn());

  sut.controllOutput(outputMock, getSetpoint, getMeasurement);
}

TEST_F(TestHeaterRelayRegulator,
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
