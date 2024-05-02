#include "../include/polynomial.h"

void Polynomial::printPoly()
{
    printf("{");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%.5f, ", coefficients[i]);
    }
    printf("%.5f}\n", coefficients[size - 1]);
}

Polynomial::Polynomial()
{
    coefficients = NULL;
}
Polynomial::Polynomial(decimalType *list, int sz)
{
    size = sz;
    coefficients = new decimalType[sz]; // make hard copy
    for (int i = 0; i < sz; i++)
    {
        coefficients[i] = list[i];
    }
}
Polynomial Polynomial::operator+(const Polynomial &other) const
{
    int degree = std::max(size, other.size); // must fit the degree to be the max of the two
    decimalType *list = new decimalType[degree];
    for (int i = 0; i < degree; i++)
    {
        decimalType a, b;
        if (i >= size)
        {
            a = 0.0; // if out of bounds, treat as if it is a zero
        }
        else
            a = coefficients[i];
        if (i >= other.size)
        {
            b = 0.0;
        }
        else
            b = other.coefficients[i];
        list[i] = a + b;
    }
    Polynomial result = Polynomial(list, degree);
    delete[] list;
    return result;
}

Polynomial Polynomial::operator-(const Polynomial &other) const
{
    decimalType *list = new decimalType[other.size];
    for (int i = 0; i < other.size; i++)
    {
        list[i] = -1.0 * other.coefficients[i]; // make negative, then add (subtraction)
    }
    Polynomial temp = Polynomial(list, other.size);
    delete[] list;
    return operator+(temp);
}

Polynomial::~Polynomial()
{
    if (coefficients)
        delete[] coefficients;
}