#ifndef __SPI_h__
#define __SPI_h__

#include <stdint.h>
#include <Arduino.h>
#include <gmock/gmock.h>
#include "GlobalObjectMockTemplate.h"

#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06
//#define SPI_CLOCK_DIV64 0x07

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR


GLOBAL_MOCK_OBJECT_DEFINISION_H(
  SPI,
  {
    MOCK_METHOD1(transfer, byte(byte));
    MOCK_METHOD0(attachInterrupt, void());
    MOCK_METHOD0(detachInterrupt, void());
    MOCK_METHOD0(begin, void());
    MOCK_METHOD0(end, void());
    MOCK_METHOD1(setBitOrder, void(uint8_t));
    MOCK_METHOD1(setDataMode, void(uint8_t));
    MOCK_METHOD1(setClockDivider, void(uint8_t));
  },
  {
    MOCK_OBJECT_GLOBAL_METHOD(transfer);
    MOCK_OBJECT_GLOBAL_METHOD(attachInterrupt);
    MOCK_OBJECT_GLOBAL_METHOD(detachInterrupt);
    MOCK_OBJECT_GLOBAL_METHOD(begin);
    MOCK_OBJECT_GLOBAL_METHOD(end);
    MOCK_OBJECT_GLOBAL_METHOD(setBitOrder);
    MOCK_OBJECT_GLOBAL_METHOD(setDataMode);
    MOCK_OBJECT_GLOBAL_METHOD(setClockDivider);
  })

#endif // __SPI_h__
