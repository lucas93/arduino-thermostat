#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <HeaterRelayRegulator.h>
#include <MockIHeaterRegulatorParameters.h>
#include <Utilities.h>
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
  Bar(const Bar& other) : i(other.i)
  {
    cout << "Bar(const Bar& other)" << endl;
  }
  ~Bar()
  {
    cout << "~Bar()" << endl;
  }


  int i = 0;
  bool operator()()
  {
    cout << "Bar::operator() with " << (this) << endl;
    return i++ % 2 == 0;
  }

  void siema()
  {
    cout << "Siema!" << endl;
  }
};

struct Baz
{
  Baz()
  {
    cout << "Baz() with " << (this) << endl;
  }
  Baz(const Baz& other) : i(other.i)
  {
    cout << "Baz(const Bar& other) with " << (this) << endl;
  }
  ~Baz()
  {
    cout << "~Baz() with " << (this) << endl;
  }


  int i = 0;
  int operator()()
  {
    cout << "Baz::operator() with " << (this) << endl;
    return ++i;
  }

  void siema()
  {
    cout << "Siema!" << endl;
  }
};

using util::unique_function;
using util::function;



void fizz(function<bool()>& fun, const bool predicate)
{
  EXPECT_EQ(predicate, fun());
}

TEST_F(TestHeaterRelayRegulator,
       Given_When_Should)
{
//  auto func = unique_function<bool() > {[](){ return true; }};
//  unique_function<bool() > func2 = {[](){ return true; }};
//  {
//  auto func = util::function<bool() > {[](){ return true; }};
//  EXPECT_TRUE(func());

////  func = make_unique< util::function<bool() > >([](){ return false; });
//  util::function<bool() >*  ptr = &func;
//  (*ptr)();


//  func =util::function<bool() > ( Bar() );
//  EXPECT_TRUE(func());
//  EXPECT_FALSE(func());

//  fizz(func, true);
//  auto func2 = util::move(func);
//  fizz(func2, false);
//  }

  unique_function<int()> func1 = {[](){ return 1; }};
  unique_function<int()> func2 = {[](){ return 2; }};
  auto func3 = unique_function<int()> {[](){ return 3; }};
  unique_function<int()> func4 = Baz{};
  auto func6 = util::move(func4);
  auto func7 = util::move(func6);
  auto func8 = util::move(func7);
  func1 = util::move(func2);

  EXPECT_EQ(2, func1());
  EXPECT_EQ(0, func2());
  EXPECT_EQ(3, func3());
  EXPECT_EQ(0, func4());


  unique_function<int(int)> func5 = {[](int i){ return i * 5; }};
  EXPECT_EQ(5, func5(1));

}

} // namespace heater
