#include "../include/math.h"

bool compareMag(decimalType n1, decimalType n2)
{ // if n1 is within the magnitude of n2, return true, else return false
    return abs(n1) <= abs(n2);
}

std::string Fraction::toString()
{
    char result[30];
    sprintf(result, "%i / %i", this->numerator, this->denominator);
    return result;
}

decimalType abs(decimalType x)
{
    if (x >= 0.0)
    {
        return x;
    }
    else
    {
        return x * -1.0;
    }
}

decimalType fmod(decimalType x, decimalType y)
{
    int intResult = static_cast<int>(x / y);
    decimalType result = x - (y * intResult);
    return result;
}
int gcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    // Assert: a >= b

    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; // gcd
}

Fraction toFrac(decimalType x)
{
    int precision = 1000000;
    Fraction result;
    result.denominator = precision;
    x *= precision;
    result.numerator = static_cast<int>(x);
    int factor = gcd(result.numerator, result.denominator); // starting value
    while (factor > 1)
    { // simplify and reduce
        result.numerator /= factor;
        result.denominator /= factor;
        factor = gcd(result.numerator, result.denominator);
    }
    return result;
}

/*
nRoot is included in this #ifdef statement because it utilizes the
pow() function (exponential functionality)
*/

#ifdef __EXPONENTIALS
decimalType nRoot(decimalType x, int n)
{
    if (x == 2 && n == 2)
        return __SQRT_2;
    int temp = 0;
    int i = 0;
    decimalType guess;
    while (temp < x && x > 0) // test to see if a perfect root
    {
        temp = pow(i, n);
        i++;
    }
    if (temp == x)
        return i - 1; // found perfect root

    // else, calculate by estimation:
    if (x < 0 && (n % 2 == 0))
    { // imaginary result
        throw std::runtime_error("Imaginary result (even root of negative number)!");
        return 0.0;
    }
    guess = x / 2;
    decimalType prevGuess = 0.0;

    while (!compareMag(guess - prevGuess, epsilon_BASIC))
    {
        prevGuess = guess;
        guess = ((n - 1.0) * guess + x / pow(guess, n - 1)) / n;
        // black magic (Newton Raphson method)
        // https://brilliant.org/wiki/newton-raphson-method/
    }
    return guess;
}

decimalType exp(decimalType x)
{ // returns e^x
    int n = 15;
    if (x < -4.0)
    {
        n = 20;
    }
    if (x < -6.0)
    {
        n = 30;
    }

    // makes sense to return a precomputed number instead of doing more computations (expensive)
    if (x < -20)
    {
        return 2.0611536224e-9; // precomputed number
    }
    if (x < -15.0)
        return 3.059023205e-7; // precomputed number
    if (x < -9.0)
    {
        return 0.000123409804087; // precomputed number
    }

    decimalType result = 0;
    for (int i = 0; i < n; i++)
    { // Taylor series
        decimalType numerator = pow(x, i);
        decimalType denominator = fact(i);
        result += (numerator / denominator); // sum
    }
    return result;
}

decimalType pow(decimalType x, int n)
{ // returns x^n
    decimalType currentProduct = 1.0;
    bool isNegExp = (n < 0);
    if (n == 0)
        return 1.0;
    if (isNegExp)
    {
        n *= -1;
    }
    for (int i = 0; i < n; i++)
    {
        currentProduct *= x;
    }
    if (isNegExp)
    {
        currentProduct = 1 / currentProduct;
    }
    return currentProduct;
}
#endif
decimalType square(decimalType x)
{
    return x * x;
}

decimalType sqrt(decimalType x)
{ // square root algorithm
    return nRoot(x, 2);
}
#ifdef __LOGARITHMS
decimalType log(decimalType base, decimalType x)
{
    return ln(x) / ln(base); // this is a logarithm identity
}
decimalType ln(decimalType x)
{
    decimalType lower = 0.36787944; // e^-1
    decimalType upper = 1.64872127; // e^0.5
    int sqrtCount = 0;              // keeps track of how many times x is square rooted
    if (x <= epsilon_BASIC)
    {
        throw std::runtime_error("ln(x): x must be greater than zero!");
    }
    if (compareMag(x - 1, epsilon_BASIC))
    { // if 1, return zero
        return 0.0;
    }
    while (x > upper || x < lower)
    {                // while outside the bounds of accuracy
        x = sqrt(x); // square rooting any positive value will make it approach 1
        sqrtCount++;
    }
    // taylor series:
    int n = 20; // number of iterations
    decimalType sum = 0.0;
    for (int i = 1; i <= n; i++) // cant start at zero because of divison errors
    {
        int sign = (i % 2 != 0) ? 1 : -1;
        sum += ((sign * pow(x - 1.0, i)) / i);
    }

    // law of logarithms states that you can pull out the exponent
    // and then multiply by it
    sum *= pow(2, sqrtCount);
    return sum;
}
#endif
decimalType fact(int x)
{
    if (x >= 0)
    {
        if (x == 1 || x == 0)
        {
            return 1;
        }
        else
        {
            return (x * fact(x - 1));
        }
    }
    else
    {
        throw std::runtime_error("Factorial error: input must be >=0");
    }
}

decimalType fibHelper(int x, decimalType *dict)
{
    if (x < 0)
    {
        throw std::runtime_error("fib(x) error: x must be greater than 0");
    }
    if (x < 2)
    {
        dict[x] = x;
        return x;
    }

    if (dict[x] != 0)
    {
        return dict[x];
    }
    else
    {
        dict[x] = fibHelper(x - 2, dict) + fibHelper(x - 1, dict);
        return dict[x];
    }
}

decimalType fib(int x)
{
    decimalType *dict = new decimalType[x + 1]; // to hold fibonacci values that are already known for faster runtime
    for (int i = 0; i <= x; i++)
    {
        dict[i] = 0.0; // initialize to zeroes
    }
    decimalType result = fibHelper(x, dict);
    delete[] dict;
    return result;
}

std::vector<ComplexNum> FFT(const std::vector<decimalType> list, const int sz)
{ // TODO
    //ComplexNum *p = new ComplexNum[sz];
    if (sz == 1)
    {
        return;
    }
}

std::vector<ComplexNum> IFFT(const std::vector<ComplexNum> list, const int sz)
{ // TODO
}

SciNot::SciNot()
{ // default constructor
    exp = 0;
    coefficient = 0;
}

SciNot::SciNot(decimalType newCoef, int newExp)
{
    coefficient = newCoef;
    exp = newExp;
    notationFix(coefficient, exp); // passes by reference so the values fix themselves
}
SciNot::SciNot(decimalType newCoefficient)
{
    // take a number and turn it into scientific notation:

    // calls the other constructor which sets the notation correctly
    SciNot temp = SciNot(newCoefficient, 0);
    coefficient = temp.coefficient;
    exp = temp.exp;
}
void SciNot::notationFix(decimalType &curCoef, int &curExp) const
{
    bool isNeg;
    isNeg = (curCoef < 0);
    curCoef = (isNeg ? -1 * curCoef : curCoef);
    if (curCoef == 0)
    {
        curExp = 0;
        return;
    }
    if (curCoef > 1 && curCoef < 10)
    { // coefficient must be between 1 and 10 for it to be true scientific notation
        // if this is the case, then do nothing, notation is already fine!
        if (isNeg)
            curCoef *= -1;
        return;
    }
    else
    { // if not in proper form, fix it so it is:
        if (curCoef >= 10)
        {
            while (curCoef >= 10)
            { // shift the decimal place over by one and add to the exponent
                curExp++;
                curCoef /= 10;
            }
        }
        else
        { // if newCoef <= 1:
            while (curCoef <= 1)
            {
                curExp--;
                curCoef *= 10;
            }
        }
        if (isNeg)
            curCoef *= -1;
        return;
    }
}

SciNot SciNot::operator+(const SciNot &other) const
{
    // make copies so that we can modify the values
    int expCpy = exp;
    int otherExpCpy = other.exp;
    decimalType coefficientCpy = coefficient;
    decimalType otherCoefficientCpy = other.coefficient;
    SciNot result;
    if (exp == other.exp)
    {
        result.coefficient = coefficient + other.coefficient;
        result.exp = exp;
        notationFix(result.coefficient, result.exp);
    }
    else if (exp > other.exp)
    {

        while (expCpy > otherExpCpy)
        {
            otherExpCpy++;
            otherCoefficientCpy /= 10;
        }
        result.coefficient = coefficientCpy + otherCoefficientCpy;
        notationFix(result.coefficient, expCpy);
        result.exp = expCpy;
    }
    else
    { // exp < other.exp
        while (expCpy < otherExpCpy)
        {
            expCpy++;
            coefficientCpy /= 10;
        }
        result.coefficient = coefficientCpy + otherCoefficientCpy;
        notationFix(result.coefficient, expCpy);
        result.exp = expCpy;
    }
    return result;
}
SciNot SciNot::operator-(const SciNot &other) const
{ // subtract 2 sciNot numbers together:
    SciNot temp = other;
    // no need to rewrite, just multiply by -1 and add:
    temp.coefficient *= -1;
    temp = operator+(temp); // add together
    return temp;
}
SciNot SciNot::operator*(const SciNot &other) const
{ // multiplication operator:
    SciNot result;
    result.coefficient = coefficient * other.coefficient;
    result.exp = exp + other.exp;
    notationFix(result.coefficient, result.exp);
    return result;
}
SciNot SciNot::operator/(const SciNot &other) const
{ // divide 2 SciNot numbers:
    SciNot result;
    if (other.coefficient == 0)
    { // cant divide by zero!
        throw std::runtime_error("Divide by Zero!");
        return result;
    }
    result.coefficient = coefficient / other.coefficient;
    result.exp = exp - other.exp;
    notationFix(result.coefficient, result.exp);
    return result;
}

decimalType SciNot::getCoefficient()
{
    return coefficient;
}
int SciNot::getExp()
{
    return exp;
}

std::string SciNot::toString()
{ // converts the notation to a human readable string
    char result[30];
    char sign;
    if (exp > 0)
    {
        sign = '+';
    }
    else if (exp < 0)
    {
        sign = '-';
    }
    else // exp == 0
    {
        sign = '0';
    }
    // so that the string printer doesn't think that '0' is a string terminator
    sprintf(result, "%fe%c%d", coefficient, sign, (exp >= 0 ? exp : exp * -1));
    return result;
}
