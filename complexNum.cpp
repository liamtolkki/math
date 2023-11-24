#include "math.h"
#include <stdexcept>

ComplexNum::ComplexNum(realType newReal, imaginaryType newImg) // make a new complex number
{
    real = newReal;
    img = newImg;
}

imaginaryType ComplexNum::getImg()
{
    return img;
}
realType ComplexNum::getReal()
{
    return real;
}

ComplexNum ComplexNum::operator*(const ComplexNum &other) const
{ // apply distributive property: (a + b) * (c + d) == (a*c + a*d + b*c + b*d)

    double realProduct1 = real * other.real;
    double realProduct2 = img * other.img * -1; // because i^2 = -1
    double imgProduct1 = real * other.img;
    double imgProduct2 = img * other.real;

    double realResult = realProduct1 + realProduct2;
    double imgResult = imgProduct1 + imgProduct2;
    return ComplexNum(realResult, imgResult);
}

ComplexNum ComplexNum::operator/(const ComplexNum &other) const
{
    double realNumerator = (real * other.real) + (img * other.img);
    double realDenominator = (other.real * other.real) + (other.img * other.img);
    double imgNumerator = ((img * other.real) - (real * other.img));
    double imgDenominator = (other.real * other.real) + (other.img * other.img);
    if (realDenominator == 0 || imgDenominator == 0)
    { // handles a division by zero!
        throw std::runtime_error("division by zero!");
    }
    else
    {
        // processes the quotient and returns it
        double realComponent = realNumerator / realDenominator;
        double imgComponent = imgNumerator / imgDenominator;
        return ComplexNum(realComponent, imgComponent);
    }
}

std::string ComplexNum::toString()
{
    char result[50];

    sprintf(result, "(%f %c %fi)", real, (img >= 0 ? '+' : '-'), (img >= 0 ? img : img * -1));
    return result;
}
