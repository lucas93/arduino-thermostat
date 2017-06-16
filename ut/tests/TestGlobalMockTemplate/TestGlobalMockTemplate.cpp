#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "GlobalObjectMockTemplate.h"

GLOBAL_MOCK_OBJECT_DEFINISION_H(
  SomeGlobalObject,
  {
    MOCK_METHOD0(foo, int() );
    MOCK_METHOD1(foo, int(int) );
    MOCK_METHOD2(foo, int(int, int) );
    MOCK_METHOD0(boo, int() );
    MOCK_METHOD1(boo, int(int) );
    MOCK_METHOD2(boo, int(int, int) );
  },
  {
    MOCK_OBJECT_GLOBAL_METHOD(foo)
    MOCK_OBJECT_GLOBAL_METHOD(boo)
  }
);

GLOBAL_OBJECT_MOCK_DEFINISION_CPP(SomeGlobalObject);

using ::testing::Return;
using ::testing::_;

TEST(GlobalMockTemplateTest, FirstTest)
{
  SomeGlobalObject_LocalMock obj;

  EXPECT_CALL(obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(obj, foo(3, 3)).WillOnce(Return(3) );
  EXPECT_CALL(obj, boo(3, 3)).WillOnce(Return(4) );

  EXPECT_EQ(1, SomeGlobalObject.foo());
  EXPECT_EQ(2, SomeGlobalObject.foo(2));
  EXPECT_EQ(3, SomeGlobalObject.foo(3, 3));
  EXPECT_EQ(4, SomeGlobalObject.boo(3, 3));
}

TEST(GlobalMockTemplateTest, SecondTest)
{
  SomeGlobalObject_LocalMock obj;

  EXPECT_CALL(obj, foo()).WillOnce(Return(1) );
  EXPECT_CALL(obj, foo(2)).WillOnce(Return(2) );
  EXPECT_CALL(obj, foo(3, 3)).WillOnce(Return(3) );

  EXPECT_EQ(1, SomeGlobalObject.foo());
  EXPECT_EQ(2, SomeGlobalObject.foo(2));
  EXPECT_EQ(3, SomeGlobalObject.foo(3, 3));
}



