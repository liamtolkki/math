#include "math.h"
class Polynomial
{
    // by default, a polynomial is represented in coefficient form
    // must be converted to point value form for fast multiplication (FFT)
public:
    Polynomial();
    Polynomial(decimalType *list, int size);
    ~Polynomial();
    int getSize();
    void printPoly(); // prints the polynomial to stdout
    decimalType evaluate(decimalType x);
    decimalType evaluateHelper(decimalType x, decimalType *list, int sz); // recursive function
    Polynomial operator+(const Polynomial &other) const;
    Polynomial operator-(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;

    decimalType getElement(int index); // returns the value at specified index

private:
    int size;
    decimalType *coefficients; // will hold the coefficients
};