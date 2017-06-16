#ifndef PRINT_H
#define PRINT_H

#include <stdio.h> // for size_t

#include "Printable.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

#define PRINT_MOCK_METHODS()\
MOCK_METHOD0(getWriteError, int());\
MOCK_METHOD0(clearWriteError, void());\
MOCK_METHOD1(print, size_t(const String&));\
MOCK_METHOD1(println, size_t(const String&));\

#define PRINT_MOCK_OBJECT_GLOBAL_METHODS()\
MOCK_OBJECT_GLOBAL_METHOD(getWriteError);\
MOCK_OBJECT_GLOBAL_METHOD(clearWriteError);\
MOCK_OBJECT_GLOBAL_METHOD(print);\
MOCK_OBJECT_GLOBAL_METHOD(println);\

#endif //PRINT_H
