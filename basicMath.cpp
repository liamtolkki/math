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

SciNot::SciNot()
{ // default constructor
    exp = 0;
    coefficient = 0;
}

SciNot::SciNot(decimalType newCoef, int newExp)
{
    coefficient = newCoef;
    exp = newExp;
    notationFix(coefficient, exp); // passes by reference so the values fix themselves
}
SciNot::SciNot(decimalType newCoefficient)
{
    // take a number and turn it into scientific notation:

    // calls the other constructor which sets the notation correctly
    SciNot temp = SciNot(newCoefficient, 0);
    coefficient = temp.coefficient;
    exp = temp.exp;
}
void SciNot::notationFix(decimalType &curCoef, int &curExp) const
{
    if (curCoef > 1 && curCoef < 10)
    { // coefficient must be between 1 and 10 for it to be true scientific notation
        // if this is the case, then do nothing, notation is already fine!
        return;
    }
    else
    { // if not in proper form, fix it so it is:
        if (curCoef >= 10)
        {
            while (curCoef >= 10)
            { // shift the decimal place over by one and add to the exponent
                curExp++;
                curCoef /= 10;
            }
        }
        else
        { // if newCoef <= 1:
            while (curCoef <= 1)
            {
                curExp--;
                curCoef *= 10;
            }
        }
        return;
    }
}

SciNot SciNot::operator+(const SciNot &other) const
{
    // make copies so that we can modify the values
    int expCpy = exp;
    int otherExpCpy = other.exp;
    decimalType coefficientCpy = coefficient;
    decimalType otherCoefficientCpy = other.coefficient;
    SciNot result;
    if (exp == other.exp)
    {
        result.coefficient = coefficient + other.coefficient;
        result.exp = exp;
        notationFix(result.coefficient, result.exp);
    }
    else if (exp > other.exp)
    {

        while (expCpy > otherExpCpy)
        {
            otherExpCpy++;
            otherCoefficientCpy /= 10;
        }
        result.coefficient = coefficientCpy + otherCoefficientCpy;
        notationFix(result.coefficient, expCpy);
        result.exp = expCpy;
    }
    else
    { // exp < other.exp
        while (expCpy < otherExpCpy)
        {
            expCpy++;
            coefficientCpy /= 10;
        }
        result.coefficient = coefficientCpy + otherCoefficientCpy;
        notationFix(result.coefficient, expCpy);
        result.exp = expCpy;
    }
    return result;
}
SciNot SciNot::operator-(const SciNot &other) const
{ // subtract 2 sciNot numbers together:
    SciNot temp = other;
    // no need to rewrite, just multiply by -1 and add:
    temp.coefficient *= -1;
    temp = operator+(temp); // add together
    return temp;
}
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
    char sign;
    if (exp > 0)
        sign = '+';
    if (exp < 0)
        sign = '-';
    sprintf(result, "%fE%c%d", coefficient, sign, (exp >= 0 ? exp : exp * -1));
    return result;
}