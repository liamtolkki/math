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