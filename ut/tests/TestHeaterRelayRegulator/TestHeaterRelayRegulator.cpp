#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <HeaterRelayRegulator.h>
#include <MockIHeaterRegulatorParameters.h>
#include <Utilities.h>
#include <functional>
#include <iostream>

using namespace testing;
using namespace std;

namespace heater
{

struct TestHeaterRelayRegulator : public Test
{
  MockIHeaterRegulatorParameters* parameters = new MockIHeaterRegulatorParameters();
  HeaterRelayRegulator sut{injectMock(parameters)};
};


struct Bar
{
  Bar()
  {
    cout << "Bar()" << endl;
  }

  int i = 0;
  bool operator()()
  {
    return i++ % 2 == 0;
  }

  void siema()
  {
    cout << "Siema!" << endl;
  }
};

template <typename T>
class Pointer
{
private:
  T* ptr;
public:
  Pointer(T* ptr) : ptr(ptr) {}

  T operator*() { return *ptr; }
  T* operator->() { return ptr; }

};

void fizz(Pointer<function<bool()> >fun, const bool predicate)
{
  EXPECT_EQ(predicate, (*fun)());
}

TEST_F(TestHeaterRelayRegulator,
       Given_When_Should)
{
  auto func = make_unique< function<bool() > >([](){ return true; });
  EXPECT_TRUE((*func)());

  func = make_unique< function<bool() > >([](){ return false; });
  EXPECT_FALSE((*func)());

  func = make_unique< function<bool() > >( Bar() );
  EXPECT_TRUE((*func)());
  EXPECT_FALSE((*func)());

  fizz(func.get(), true);
  fizz(func.get(), false);


  Bar bar{};
  Pointer<Bar> barPtr  = &bar;
  barPtr->siema();
}

} // namespace heater
