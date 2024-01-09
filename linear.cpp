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
    { // (Ai + Bk + Cj + ... + Nn)
        std::string result = "(";
        char comp = 'i'; // starting character

        for (int i = 0; i < degree - 1; i++)
        {

            char subStr[30];
            sprintf(subStr, "%f%c %c ", (components[i]) >= 0 ? components[i] : components[i] * -1, comp, (components[i + 1] >= 0) ? '+' : '-');
            result.append(subStr);
            comp++;
        }
        char subStr[30];
        sprintf(subStr, "%f%c)", components[degree - 1], comp);
        result.append(subStr);
        return result;
    }
    else
    { // unknown notation
        throw std::runtime_error("Unknown Vector Notation");
        return 0;
    }
}

void LinearAlgebra::Vector::norm()
{
    decimalType mag = this->mag();
    // cannot normalize a zero vector:
    if (this->mag() == 0)
    {
        throw std::runtime_error("Cannot normalize the zero vector!");
        return;
    }
    for (int i = 0; i < degree; i++)
    {
        components[i] /= mag;
    }
}

decimalType LinearAlgebra::Vector::dot(Vector *other)
{ // dot product (return a scalar quantity
    decimalType result = 0.0;
    // must have same degree:
    if (degree == other->degree)
    {
        if (degree == 0)
        { // the zero vector dotted with itself is always zero
            return 0.0;
        }
        // dot:
        for (int i = 0; i < degree; i++)
        {
            result += (components[i] * other->components[i]);
        }
        return result;
    }
    else
    {
        throw std::runtime_error("Dot Product error: CANNOT DOT 2 VECTORS WITH DIFFERENT DEGREES");
        return 0;
    }
}

#endif