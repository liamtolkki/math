#include "../include/polynomial.h"

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

Polynomial::~Polynomial()
{
    if (coefficients)
        delete[] coefficients;
}