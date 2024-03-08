#pragma once
#include <string>
#include <stdexcept>
#include <cstdio>

/*

This Library was made by Liam Tolkkinen as a personal project.
Feel free to modify it as you see fit



This is the parent header for every file in this library.
It contains useful data types and constants for other sublibraries
*/

#define __SCIENTIFIC_NOTATION_CONSTANTS
#define __VECTOR_NOTATION_CONSTANTS
typedef double decimalType;
typedef double imaginaryType;
typedef double realType;
typedef decimalType (*term)(double); // parses the terms of a function, ex: x^2 = x*x
// defined 2 different epsilon values, depending on the function it is used for
#define epsilon_TRIG (decimalType)(1.0E-10) // because there will always be error with appx
#define epsilon_BASIC (decimalType)(1.0E-7)
// useful constants
const decimalType PI = 3.14159265358979;
const decimalType e = 2.7182818284590452;
const decimalType __SQRT_2 = 1.41421356237309504880;
const decimalType __GOLDEN_RATIO = 1.61803398874989484821;

// these are just for personal convention
#ifdef __SCIENTIFIC_NOTATION_CONSTANTS
const int STD_FORM = 0;
const int SCI_FORM = 1;
#endif
#ifdef __VECTOR_NOTATION_CONSTANTS
const int COMPONENT_NOTATION = 0;
const int UNIT_NOTATION = 1;
#endif

struct Fraction
{
    int numerator;
    int denominator;
    std::string toString();
};
// standalone functions:
Fraction toFrac(decimalType x);
int gcd(int a, int b); // returns greatest common denominator
decimalType abs(decimalType x);
bool compareMag(decimalType n1, decimalType n2); // tests if |n1| <= |n2|
decimalType fmod(decimalType x, decimalType y);  // returns x % y
decimalType sum(decimalType start, decimalType end, decimalType (*term)(decimalType));
decimalType log(decimalType base, decimalType x);
decimalType ln(decimalType x);
decimalType fact(int x); // factorial: x! = x * (x-1) * (x-2) * ... * (x-n) * 1; ex: 3! = 3*2*1
decimalType fib(int x);
// max factorial value supported is 170! (7.257416E+306)

decimalType nRoot(decimalType x, int n);
decimalType sqrt(decimalType x);
decimalType pow(decimalType x, int n);
decimalType square(decimalType x);

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
