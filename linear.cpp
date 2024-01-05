#include "math.h"
#ifdef __LINEAR_ALGEBRA
LinearAlgebra::Vector::Vector()
{
    degree = 0;
}

LinearAlgebra::Vector::Vector(int deg)
{
    degree = deg;
    components = new decimalType[deg];
}

LinearAlgebra::Vector::~Vector()
{
    delete components;
}

int LinearAlgebra::Vector::getDegree()
{
    return degree;
}
void LinearAlgebra::Vector::setDegree(int deg)
{
    delete components;
    components = new decimalType[deg];
    degree = deg;
}
decimalType LinearAlgebra::Vector::getVal(int x)
{
    if (x < degree)
    {
        return components[x];
    }
}
void LinearAlgebra::Vector::setVal(int x, decimalType newVal)
{ // sets component x to newVal
    if (x < degree)
    {
        components[x] = newVal;
    }
}

#endif