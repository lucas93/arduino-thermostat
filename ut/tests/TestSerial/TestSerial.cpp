#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>


using ::testing::Return;
using ::testing::_;



TEST(SerialTest, ShouldBegin)
{
  Serial_LocalMock SerialLocal;

  EXPECT_CALL(SerialLocal, available())
      .Times(3)
      .WillRepeatedly(Return(5));

  EXPECT_CALL(SerialLocal, print("Siema!")).WillOnce(Return(5));

  EXPECT_EQ(5, Serial.available());
  EXPECT_EQ(5, Serial.available());
  EXPECT_EQ(5, Serial.available());
  EXPECT_EQ(5, Serial.print("Siema!"));
}


