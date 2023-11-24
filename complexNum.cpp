#include "math.h"

ComplexNum::ComplexNum(realType newReal, imaginaryType newImg) /// make a new complex number
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

std::string ComplexNum::toString()
{
    char result[50];

    sprintf(result, "%f+%fi", real, img);
    return result;
}
