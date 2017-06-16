#ifndef __Wire_h__
#define __Wire_h__

#include <stdint.h>
#include <gmock/gmock.h>
#include "GlobalObjectMockTemplate.h"
#include "WString.h"
#include "Stream.h"

#define BUFFER_LENGTH 32

GLOBAL_MOCK_OBJECT_DEFINISION_H(
  Wire,
  {
    MOCK_METHOD0(begin, void());
    MOCK_METHOD1(begin, void(int));
    MOCK_METHOD1(beginTransmission, void(uint8_t));
    MOCK_METHOD0(endTransmission, uint8_t(void));
    MOCK_METHOD1(endTransmission, uint8_t(uint8_t));
    MOCK_METHOD2(requestFrom, uint8_t(uint8_t, uint8_t));
    MOCK_METHOD3(requestFrom, uint8_t(uint8_t, uint8_t, uint8_t));
    MOCK_METHOD1(write, size_t(unsigned int));
    MOCK_METHOD2(write, size_t(const uint8_t *, size_t));
    MOCK_METHOD0(available, int());
    MOCK_METHOD0(read, int());
    MOCK_METHOD0(peek, int());
    MOCK_METHOD0(flush, void());
    MOCK_METHOD1(onReceive, void( void (*)(int) ));
    MOCK_METHOD1(onRequest, void( void (*)(int) ));
    //inherited from Stream
    STREAM_MOCK_METHODS()
  },
  {
    MOCK_OBJECT_GLOBAL_METHOD(begin);
    MOCK_OBJECT_GLOBAL_METHOD(beginTransmission);
    MOCK_OBJECT_GLOBAL_METHOD(endTransmission);
    MOCK_OBJECT_GLOBAL_METHOD(requestFrom);
    MOCK_OBJECT_GLOBAL_METHOD(write);
    MOCK_OBJECT_GLOBAL_METHOD(available);
    MOCK_OBJECT_GLOBAL_METHOD(read);
    MOCK_OBJECT_GLOBAL_METHOD(peek);
    MOCK_OBJECT_GLOBAL_METHOD(flush);
    MOCK_OBJECT_GLOBAL_METHOD(onReceive);
    MOCK_OBJECT_GLOBAL_METHOD(onRequest);
    //inherited from Stream
    STREAM_MOCK_OBJECT_GLOBAL_METHODS()
  });

#endif
