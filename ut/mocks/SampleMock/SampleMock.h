#ifndef SIMPLE_MOCK_H
#define SIMPLE_MOCK_H


#include <gmock/gmock.h>
#include <BaseClass.h>

class MockTeaBreak : public TeaBreak
{
public:
    MOCK_METHOD2(makeCoffee,    int(bool milk, double sugars));
    MOCK_METHOD0(makeHerbalTea, int());
};

#endif // SIMPLE_MOCK_H
