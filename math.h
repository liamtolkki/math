#pragma once
#include <string>
#include <stdexcept>
#include <cstdio>
#define TRIG
#define __LINEAR_ALGEBRA
#define __VECTORS
#define __MATRICES
// #define __MATRIX_INVERSE
#define __SCIENTIFIC_NOTATION_CONSTANTS
#define __VECTOR_NOTATION_CONSTANTS
typedef double decimalType;
typedef double imaginaryType;
typedef double realType;
typedef decimalType (*term)(double); // parses the terms of a function, ex: x^2 = x*x
const decimalType PI = 3.14159265358979;
const decimalType e = 2.7182818284590452;
const decimalType __SQRT_2 = 1.41421356237309504880;
#ifdef __SCIENTIFIC_NOTATION_CONSTANTS
const int STD_FORM = 0;
const int SCI_FORM = 1;
#endif
#ifdef __VECTOR_NOTATION_CONSTANTS
const int COMPONENT_NOTATION = 0;
const int UNIT_NOTATION = 1;
#endif

// standalone functions:
decimalType abs(decimalType x);
decimalType fmod(decimalType x, decimalType y); // returns x % y
decimalType sum(double start, double end, decimalType (*term)(double));
decimalType log(double base, double x);
decimalType ln(double x);
decimalType fact(int x); // factorial: x! = x * (x-1) * (x-2) * ... * (x-n) * 1; ex: 3! = 3*2*1
decimalType fib(int x);
// max factorial value supported is 170! (7.257416E+306)

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
#ifdef __VECTORS
    class Vector
    {
    public:
        Vector();
        Vector(int degree);
        ~Vector();                          // degree is how many elements in the vector
        std::string toString();             // print the vector out in component form
        std::string toString(int notation); // for choosing what notation to print it in
        int getDegree();
        decimalType getVal(int x); // get the value at index x
        void setDegree(int degree);
        void setVal(int x, decimalType newVal); // set the value at x to be newVal
        decimalType dot(Vector *other);         // dot product
        Vector *cross(Vector *other);           // cross product
        decimalType mag();                      // returns the magnitude of the vector
        void norm();                            // normalize the vector
        void scale(decimalType scalar);         // apply a scalar to the vector and return

    private:
        int degree;
        decimalType *components;
    };
#endif
#ifdef __MATRICES
    class Matrix
    {
    public:
        Matrix();
        Matrix(int rows, int columns);
        Matrix(int rows, int columns, decimalType *compArr, int sz);
        Matrix(const Matrix &other); // copy constructor
        ~Matrix();
        void initialize(decimalType *componentArray, int size);
        void initializeComp();
        decimalType get(int i, int j) const;        // get value in M(i, j)
        void set(int i, int j, decimalType newVal); // set value in M(i, j) to newVal
        std::string toString();                     // return the string print of the matrix M
        Matrix &operator=(const Matrix &other);
        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(const Matrix &other) const;
#ifdef __MATRIX_INVERSE
        Matrix inverse() const; // return the inverse of M (if exists)
#endif

        void scale(decimalType scalar);         // multiply a scalar to all the elements of M
        decimalType det();                      // determinant of M
        Matrix transpose() const;               // transpose of M
        decimalType minor(int row, int column); // returns the minor of M. (eg: M(1,2))
        int getRows() const;
        int getColumns() const;

        // performs: row2 = (Scalar1*row1 + Scalar2*row2)
        void rowOp(int row1, decimalType scalar1, int row2, decimalType scalar2);
        void rowOp(int row1, decimalType scalar1, int row2);
        void rowOp(int row1, int row2, decimalType scalar2);

        void rowOp(int row1, int row2);

    private:
        decimalType **components; // a 2-D array to hold the matrix components
        int rows;
        int columns;
    };
#endif

    // TODO
private:
};
#endif
