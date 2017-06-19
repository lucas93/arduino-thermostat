#pragma once

#define errorMsg "Adjust primitives sizes to your system!"
static_assert(sizeof(char) == 1,
              errorMsg);
static_assert(sizeof(int) == 4,
              errorMsg);
static_assert(sizeof(short int) == 2,
              errorMsg);
static_assert(sizeof(long int) == 8,
              errorMsg);
static_assert(sizeof(float) == 4,
              errorMsg);
static_assert(sizeof(double) == 8,
              errorMsg);
#undef errorMsg

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using i64 = signed long int;
using u64 = unsigned long int;
using f32 = float;
