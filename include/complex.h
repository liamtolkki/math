#ifdef DEVELOPMENT_MODE
#include "math.h"
#else
#include <mathlib/math.h>
#endif
class ComplexNum
{
    /*
    complex numbers have both a real and an imaginary component.
    ex: 3 + 5i
    */
private:
    double real;
    double img;

public:
    ComplexNum(realType real, imaginaryType img);
    ComplexNum operator*(const ComplexNum &other) const; // overloads the * operator
    ComplexNum operator/(const ComplexNum &other) const;
    realType getReal();
    imaginaryType getImg();
    std::string toString();
};