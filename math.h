#include <string>
#include <stdexcept>
#define TRIG
// #define __LINEAR_ALGEBRA
#define __SCIENTIFIC_NOTATION_CONSTANTS
typedef double decimalType;
typedef double imaginaryType;
typedef double realType;
typedef decimalType (*term)(double); // parses the terms of a function, ex: x^2 = x*x
const decimalType PI = 3.14159265358979;
const decimalType e = 2.7182818284590452;
#ifdef __SCIENTIFIC_NOTATION_CONSTANTS
const int STD_FORM = 0;
const int SCI_FORM = 1;
#endif

const int COMPONENT_NOTATION = 0;
const int UNIT_NOTATION = 1;

// standalone functions:
decimalType fmod(decimalType x, decimalType y); // returns x % y
decimalType sum(double start, double end, decimalType (*term)(double));
decimalType log(double base, double x);
decimalType ln(double x);
long int fact(int x); // factorial: x! = x * (x-1) * (x-2) * ... * (x-n) * 1; ex: 3! = 3*2*1
decimalType nRoot(decimalType x, int n);
decimalType sqrt(decimalType x);
decimalType pow(decimalType x, int n);
decimalType square(decimalType x);

// BEGIN BASIC TRIG FUNCTIONS--------------
#ifdef TRIG
decimalType sin(decimalType x);
decimalType cos(decimalType x);
decimalType tan(decimalType x);
decimalType sec(decimalType x);
decimalType csc(decimalType x);
decimalType cot(decimalType x);
decimalType arcsin(decimalType x);
decimalType arccos(decimalType x);
decimalType arctan(decimalType x);
decimalType arcsec(decimalType x);
decimalType arccsc(decimalType x);
decimalType arccot(decimalType x);

decimalType toDeg(decimalType rad); // radians -> degrees
decimalType toRad(decimalType deg); // degrees -> radians
#endif
// END BASIC TRIG FUNCTIONS-----------------

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
#ifdef __LINEAR_ALGEBRA
class LinearAlgebra
{
public:
    class Vector
    {
    public:
        Vector();
        Vector(int degree);                 // degree is how many elements in the vector
        std::string toString();             // print the vector out in component form
        std::string toString(int notation); // for choosing what notation to print it in
        int getDegree();
        double getVal(int x); // get the value at index x
        void setDegree(int degree);
        void setVal(int x, double newVal);     // set the value at x to be newVal
        double dot(Vector *v1, Vector *v2);    // dot product
        Vector *cross(Vector *v1, Vector *v2); // cross product
        double mag(Vector *v);                 // returns the magnitude of the vector
        Vector *norm(Vector *v);               // normalize the vector

    private:
    };
    class Matrix
    {
    };
    // TODO
private:
};
#endif
