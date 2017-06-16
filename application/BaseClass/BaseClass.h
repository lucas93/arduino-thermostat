#ifndef BASE_CLASS_H
#define BASE_CLASS_H

class TeaBreak
{
public:
    virtual ~TeaBreak() {}

    // Return minutes taken to make the drinks
    int morningTea();


protected:
    virtual int makeCoffee(bool milk, double sugars) = 0;
    virtual int makeHerbalTea() = 0;
};

#endif // BASE_CLASS_H
