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

SciNot::SciNot(decimalType newCoef, int newExp)
{
    if (newCoef > 1 && newCoef < 10)
    { // coefficient must be between 1 and 10 for it to be true scientific notation
        coefficient = newCoef;
        exp = newExp;
        printf("Coefficient: %f\nExp: %d\n", coefficient, exp);
    }
    else
    { // if not in proper form, fix it so it is:
        if (newCoef >= 10)
        {
            while (newCoef >= 10)
            { // shift the decimal place over by one and add to the exponent
                newExp++;
                newCoef /= 10;
            }
        }
        else
        { // if newCoef <= 1:
            while (newCoef <= 1)
            {
                newExp--;
                newCoef *= 10;
            }
        }
        coefficient = newCoef;
        exp = newExp;
    }
}
SciNot::SciNot(decimalType newCoefficient)
{
    // take a number and turn it into scientific notation:

    // calls the other constructor which sets the notation correctly
    SciNot temp = SciNot(newCoefficient, 0);
    coefficient = temp.coefficient;
    exp = temp.exp;
}

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

std::string SciNot::toString()
{ // converts the notation to a human readable string
    char result[30];
    std::printf("coef: %f\n", coefficient);
    sprintf(result, "%fE%d", coefficient, exp);
    return result;
}