#include <string>
#include <stdexcept>
typedef double decimalType;
typedef double imaginaryType;
typedef double realType;
typedef decimalType (*term)(double); // parses the terms of a function, ex: x^2 = x*x
const decimalType pi = 3.14159265358979;
const decimalType e = 2.7182818284590452;
const int STD_FORM = 0;
const int SCI_FORM = 1;

const int COMPONENT_NOTATION = 0;
const int UNIT_NOTATION = 1;

// standalone functions:
decimalType sum(double start, double end, decimalType (*term)(double));
decimalType log(double base, double x);
decimalType ln(double x);
long int fact(int x); // factorial: x! = x * (x-1) * (x-2) * ... * (x-n) * 1; ex: 3! = 3*2*1

class BasicMath
{
public:
};

class SciNot
{ // for scientific notation, ex: 9747582 = 9.747582E+6
public:
    SciNot();
    SciNot(decimalType coefficient, int exp);
    SciNot(decimalType coefficient);
    void notationFix(decimalType &coefficient, int &exp) const;
    SciNot operator+(const SciNot &other) const;
    SciNot operator-(const SciNot &other) const;
    SciNot operator*(const SciNot &other) const;
    SciNot operator/(const SciNot &other) const;

    decimalType getCoefficient();
    int getExp();

    std::string toString();

private:
    decimalType coefficient;
    int exp;
};

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

class Calculus
{
    // TODO
};

class LinearAlgebra
{
public:
    class Vector
    {
    public:
        Vector();
        Vector(int degree);     // degree is how many elements in the vector
        std::string toString(); // print the vector out in component form
        std::string toString(int notation);

    private:
    };
    class Matrix
    {
    };
    // TODO
private:
};
