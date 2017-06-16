#include <iostream>
#include <BaseClass.h>

using std::cout;

class DerivedClass : public TeaBreak
{
public:
    ~DerivedClass() = default;

private:

    int makeCoffee(bool milk, double sugars) override
    {
        return milk? (sugars) : (sugars*(-1));
    }

    int makeHerbalTea() override
    {
        return 2;
    }



};

int main()
{
    DerivedClass dc;

	auto a = 1;
    cout << "morningTea() = " <<dc.morningTea();
	return 0;
}

