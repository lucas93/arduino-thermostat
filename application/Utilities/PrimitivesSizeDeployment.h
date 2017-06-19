#pragma once

#define errorMsg "Adjust primitives sizes to your system!"
static_assert(sizeof(char) == 1,
              errorMsg);
static_assert(sizeof(int) == 2,
              errorMsg);
static_assert(sizeof(short int) == 2,
              errorMsg);
static_assert(sizeof(long int) == 4,
              errorMsg);
static_assert(sizeof(long long int) == 8,
              errorMsg);
static_assert(sizeof(float) == 4,
              errorMsg);
static_assert(sizeof(double) == 4,
              errorMsg);
#undef errorMsg

using i8 = signed char;
using u8 = unsigned char;
using i32 = long signed int;
using u32 = long unsigned int;
using i16 = signed int;
using u16 = unsigned int;
using i64 = signed long long int;
using u64 = unsigned long long int;
using f32 = float;
