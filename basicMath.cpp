#include "math.h"

decimalType sum(double start, double end, decimalType (*term)(double))
{
    decimalType result;
    // TODO
    return result;
}
decimalType log(double base, double x)
{
    decimalType result;
    return result;
}
decimalType ln(double x)
{
    return log(e, x);
}
long int fact(int x)
{
    if (x == 1 || x == 0)
    {
        return 1;
    }
    else
    {
        return (x * fact(x - 1));
    }
}

SciNot::SciNot(decimalType coefficient, int exp)
{
}
SciNot::SciNot(decimalType coefficient) {}

SciNot SciNot::operator+(const SciNot &other) const {}
SciNot SciNot::operator-(const SciNot &other) const {}
SciNot SciNot::operator*(const SciNot &other) const {}
SciNot SciNot::operator/(const SciNot &other) const {}

decimalType SciNot::getCoefficient()
{
    return coefficient;
}
int SciNot::getExp()
{
    return exp;
}
