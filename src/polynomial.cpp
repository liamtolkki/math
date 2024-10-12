#include <mathlib/polynomial.h>

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
#ifdef __FFT
Polynomial Polynomial::operator*(const Polynomial &other) const
{
    // needs FFT() and IFFT()
    // first, pad both polynomials until size = the next power of 2
    int maxSize = std::max(size, other.size);
    int pow2 = 1; // start at 1, shift until larger than current size
    while (pow2 < maxSize)
    {
        // bit shift (pow2 * 2)
        pow2 = pow2 << 1;
    }

    // this is because we need to double the size to prepare for the FFT() call
    pow2 = pow2 << 1;

    // these are the lists needed
    decimalType *list1 = new decimalType[pow2];
    decimalType *list2 = new decimalType[pow2];
    for (int i = 0; i < pow2; i++)
    { // initialize arrays with zero padding
        if (i < size)
        {
            list1[i] = coefficients[i];
        }
        else
        {
            list1[i] = 0.0; // zero pad if out of bounds
        }
        if (i < other.size)
        {
            list2[i] = other.coefficients[i];
        }
        else
        {
            list2[i] = 0.0; // zero pad if out of bounds
        }
    }
    decimalType *list3 = FFT(list1, pow2);
    decimalType *list4 = FFT(list2, pow2);
    decimalType *list5 = new decimalType[pow2];
    for (int i = 0; i < pow2; i++)
    { // O(n) multiplication
        list5[i] = list3[i] * list4[i];
    }

    // free up memory since it is no longer needed
    list3 = IFFT(list5, pow2);
    delete[] list1;
    delete[] list2;
    Polynomial result = Polynomial(list3, pow2);
    delete[] list5;
    return result;
}
#endif
decimalType Polynomial::evaluate(decimalType x)
{
    // the first coefficient is a constant, so leave it out of the chain
    return coefficients[0] + evaluateHelper(x, coefficients + 1, size - 1);
}

// recursive function. Evaluation:
// x(a + x(b + x(c + ...)))
decimalType Polynomial::evaluateHelper(decimalType x, decimalType *list, int sz)
{
    if (!sz)
    {
        return 0.0; // base case
    }
    // increment list ptr, and decrement size
    return (x * (list[0] + evaluateHelper(x, list + 1, sz - 1))); // recursive call
}
Polynomial::~Polynomial()
{
    if (coefficients)
        delete[] coefficients;
}