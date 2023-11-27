#include "math.h"
#ifdef TRIG
#define epsilon (double)(1.0E-10) // because there will always be error with appx

decimalType toDeg(decimalType rad)
{
    decimalType reducedRad = fmod(rad, 2 * PI);
    return ((reducedRad * 180.0) / PI); // PI*RAD = 180*DEG
}

decimalType toRad(decimalType deg)
{
    decimalType reducedDeg = fmod(deg, 360.0);
    return ((PI * reducedDeg) / 180.0);
}

decimalType sin(decimalType x)
{
    decimalType sum = 0.0; // start at zero
    x = fmod(x, 2 * PI);   // so that the series appx is more accurate (and faster)
    // Taylor series:
    for (int n = 0; n <= 20; n++) // 20 iterations
    {
        sum += (((n % 2 == 0 ? 1 : -1) * pow(x, ((2 * n) + 1))) / fact((2 * n) + 1));
    }
    if (std::abs(sum) < epsilon || sum == 0)
    {
        return 0.0; // to account for very small errors
    }
    else if (std::abs((1 - std::abs(sum))) < epsilon || sum == 1)
    {
        return 1.0;
    }

    return sum;
}
decimalType cos(decimalType x)
{

    decimalType sum = 0.0; // start at zero
    x = fmod(x, 2 * PI);   // so that the series appx is more accurate (and faster)
    // Taylor series:
    for (int n = 0; n <= 20; n++) // 20 iterations
    {
        sum += (n % 2 == 0 ? 1 : -1) * pow(x, (2 * n)) / fact(2 * n);
    }
    if (std::abs(sum) < epsilon || sum == 0)
    {
        return 0.0; // to account for very small errors
    }
    else if (std::abs(1 - std::abs(sum)) < epsilon || sum == 1)
    {
        return 1.0;
    }

    return sum;
}
decimalType tan(decimalType x)
{
    decimalType cosX = cos(x);
    if (cosX != 0)
    // because the cpu will think that cos(1/2 * PI) is some super small number and not 0...
    {
        return (sin(x) / cos(x));
    }
    else // divide by zero!
    {
        throw std::runtime_error("[DOMAIN ERROR] Tangent invalid input!\nCannot be a multiple of 1/2*PI or 3/2*PI!");
        return 0;
    }
}
decimalType sec(decimalType x)
{
}
decimalType csc(decimalType x)
{
}
decimalType cot(decimalType x)
{
}
decimalType arcsin(decimalType x)
{
}
decimalType arccos(decimalType x)
{
}
decimalType arctan(decimalType x)
{
}
decimalType arcsec(decimalType x)
{
}
decimalType arccsc(decimalType x)
{
}
decimalType arccot(decimalType x)
{
}
#endif