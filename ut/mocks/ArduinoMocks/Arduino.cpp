#include "Arduino.h"
#include <gtest/gtest.h>
#include <memory>

GLOBAL_FUNCTIONS_MOCK_IMPLEMENTATION_CPP(Arduino);


IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(Arduino, void, pinMode, uint8_t, a, uint8_t, b)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(Arduino, void, digitalWrite, uint8_t, a, uint8_t, b)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(Arduino, int, digitalRead, uint8_t, a)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(Arduino, int, analogRead, uint8_t, a)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(Arduino, void, analogReference, uint8_t, mode)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_2(Arduino, void, analogWrite, uint8_t, a, int, b)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_0(Arduino, unsigned long, millis)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_0(Arduino, unsigned long, micros)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(Arduino, void, delay, unsigned long, a)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(Arduino, void, delay, unsigned int, us)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_3(Arduino, unsigned long, pulseIn, uint8_t, pin, uint8_t, state, unsigned long, timeout)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_4(Arduino, void, shiftOut, uint8_t, dataPin, uint8_t, clockPin, uint8_t, bitOrder, uint8_t, val)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_3(Arduino, uint8_t, shiftIn, uint8_t, dataPin, uint8_t, clockPin, uint8_t, bitOrder)
IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL_1(Arduino, void, detachInterrupt, uint8_t, pin)
void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode)
{ //function pointer needs a unique implementation
  assertArduinoMockWrapperInstanceWasCreated();\
  return ArduinoInstancePointer->attachInterrupt(interruptNum, userFunc, mode);
}



//#define IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(FUNCTION_NAME)\
//template< typename... Args>\
//auto FUNCTION_NAME(Args... args) -> decltype(arduinoInstancePointer->FUNCTION_NAME(args ...))\
//{\
//  EXPECT_NE(nullptr, arduinoInstancePointer);\
//  return arduinoInstancePointer->FUNCTION_NAME(args...);\
//}


//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(digitalWrite)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(attachInterrupt)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(pinMode)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(digitalRead)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(analogRead)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(analogReference)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(analogWrite)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(millis)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(micros)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(void, delay)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(pulseIn)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(shiftOut)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(shiftIn)
//IMPLEMENT_FUNCTION_AS_OBJECT_METHOD_CALL(detachInterrupt)
