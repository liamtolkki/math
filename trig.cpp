#include "math.h"
#ifdef TRIG

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
    return sum;
}
decimalType cos(decimalType x)
{
}
decimalType tan(decimalType x)
{
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