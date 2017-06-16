#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <Arduino.h>
#include <blinkLib.h>

void boo(){}

TEST(BlinkLibTests, ShouldSetupCorrectly)
{
  Arduino_MockInstanceGuard Arduino{};
  auto pin = 13;
  EXPECT_CALL(Arduino, pinMode(pin, OUTPUT));
  EXPECT_CALL(Arduino, attachInterrupt(0, boo, 0));
  blink_setup(pin);
  attachInterrupt(0, boo, 0);

}

TEST(BlinkLibTests, WhenSetupCorrectly_ShouldBlinkCorrectly)
{
  Arduino_MockInstanceGuard Arduino{};
  auto pin = 13;
  auto duration = 500ul;
  EXPECT_CALL(Arduino, pinMode(pin, OUTPUT));
  EXPECT_CALL(Arduino, digitalWrite(pin, HIGH));
  EXPECT_CALL(Arduino, delay(duration)).Times(2);
  EXPECT_CALL(Arduino, digitalWrite(pin, LOW));

  blink_setup(pin);
  blink(duration);
}


