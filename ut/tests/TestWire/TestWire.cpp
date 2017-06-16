#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>
#include <Wire.h>
#include "GlobalObjectMockTemplate.h"


using ::testing::Return;
using ::testing::_;



TEST(WireTest, ShouldBegin)
{
  Wire_LocalMock WireLocal;

  EXPECT_CALL(WireLocal, begin(9600));
  EXPECT_CALL(WireLocal, print("LOOL")).WillOnce(Return(1));

  Wire.begin(9600);
  EXPECT_EQ(1, Wire.print("LOOL"));
}


