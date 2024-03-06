#include "math.h"
// #define epsilon .0000001

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

decimalType pow(decimalType x, decimalType n)
{                                  // returns x^n
    Fraction exponent = toFrac(n); // turn the exponent into fraction form for easier computation
    decimalType currentProduct = 1;
    bool isNegExp = (n < 0);
    if (n == 0.0)
        return 1.0;
    if (n == 1.0)
        return x;
    if (isNegExp)
    {
        exponent.numerator *= -1;
    }
    for (int i = 0; i < exponent.numerator; i++)
    {
        currentProduct *= x;
    }
    currentProduct = nRoot(currentProduct, exponent.denominator);
    if (isNegExp)
    {
        currentProduct = 1 / currentProduct;
    }
    return currentProduct;
}
decimalType square(decimalType x)
{
    return pow(x, 2);
}

decimalType sqrt(decimalType x)
{ // square root algorithm
    return nRoot(x, 2);
}
decimalType log(decimalType base, decimalType x)
{
    return ln(x) / ln(base); //
}
decimalType ln(decimalType x)
{

    if (x <= epsilon_BASIC)
    {
        throw std::runtime_error("ln(x): x must be greater than zero!");
    }
    else if (x < 1)
    {
    }
    else // x > 1
    {
    }
}
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
        throw std::runtime_error("Factorial error: input must be >0");
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
        sign = '+';
    if (exp < 0)
        sign = '-';
    if (exp == 0)
        sign = '0';
    // so that the string printer doesn't think that '0' is a string terminator
    sprintf(result, "%fE%c%d", coefficient, sign, (exp >= 0 ? exp : exp * -1));
    return result;
}
