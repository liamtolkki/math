/*
----------------------
Liam Tolkkinen
liamtolkki@gmail.com
----------------------
A fun project to calculate certain math operations
--basic
    --basic math functions
        --log_n(base, x)
        --exp(x)
        --sqrt(x)
        --nthroot(n, x)
    --complex numbers (EX: 3 + 5i)
        ...
--Calculus
    --differentiation
    --integration
    --sums
    ...
--Linear Algebra
    --matrices
        --determinants
    --vector/matrix multiplication
    --cross/dot product
    ...
*/

typedef long double mathType;
typedef double imaginaryType;
typedef double realType;
class BasicMath
{

    // TODO
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
    void compexNum(realType real, imaginaryType img);
    realType getReal();
    imaginaryType getImg();
    
};

class Calculus
{
    // TODO
};

class LinearAlgebra
{
    // TODO
};
