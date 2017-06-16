#include "BaseClass.h"

int TeaBreak::morningTea()
{
    return makeCoffee(true,  1) +
           makeCoffee(false, 0.5) +
           makeHerbalTea();
}
