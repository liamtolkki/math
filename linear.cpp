#include "math.h"
#ifdef __LINEAR_ALGEBRA
LinearAlgebra::Vector::Vector()
{
    degree = 0;
    components = nullptr;
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
    else
    {
        throw std::runtime_error("Vector Index Out of Bounds ERROR");
        return 0;
    }
}
void LinearAlgebra::Vector::setVal(int x, decimalType newVal)
{ // sets component x to newVal
    if (x < degree)
    {
        components[x] = newVal;
    }
    return;
}
decimalType LinearAlgebra::Vector::mag()
{
    decimalType result = 0;
    for (int i = 0; i < degree; i++)
    {
        result += square(components[i]);
    }
    result = sqrt(result);
    return result;
}
std::string LinearAlgebra::Vector::toString()
{ // default to component notation
    return toString(COMPONENT_NOTATION);
}
std::string LinearAlgebra::Vector::toString(int notation)
{
    if (degree == 0)
        return "ZERO_VECTOR";
    if (notation == COMPONENT_NOTATION)
    { // <A, B, C, ..., Nth>
        std::string result = "<";
        for (int i = 0; i < degree - 1; i++)
        {
            char subStr[30];
            sprintf(subStr, "%f, ", components[i]);
            result.append(subStr);
        }
        char subStr[30];
        sprintf(subStr, "%f>", components[degree - 1]);
        result.append(subStr);
        return result;
    }
    else if (notation == UNIT_NOTATION)
    { // Ai + Bk + Cj + ... + Nn
    }
    else
    { // unknown notation
        throw std::runtime_error("Unknown Vector Notation");
        return 0;
    }
}

#endif