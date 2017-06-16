#ifndef Printable_h
#define Printable_h

#include <gmock/gmock.h>

class Print;

struct Printable
{
  virtual size_t printTo(Print& p) const = 0;
};

#endif
