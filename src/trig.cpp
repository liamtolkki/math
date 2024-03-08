#include "../include/math.h"
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
    if (abs(sum) < epsilon_TRIG || sum == 0)
    {
        return 0.0; // to account for very small errors
    }
    else if (abs((1 - abs(sum))) < epsilon_TRIG || sum == 1)
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
    if (abs(sum) < epsilon_TRIG || sum == 0)
    {
        return 0.0; // to account for very small errors
    }
    else if (abs(1 - abs(sum)) < epsilon_TRIG || sum == 1)
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
    decimalType cosX = cos(x);
    if (cosX == 0.0)
    {
        throw std::runtime_error("[DOMAIN ERROR] secant(x)");
        return 0;
    }
    else
    {
        return (1 / cosX);
    }
}
decimalType csc(decimalType x)
{
    decimalType sinX = sin(x);
    if (sinX == 0.0)
    {
        throw std::runtime_error("[DOMAIN ERROR] cosecant(x)");
        return 0;
    }
    else
    {
        return (1 / sinX);
    }
}
decimalType cot(decimalType x)
{
    decimalType tanX = tan(x);
    if (tanX == 0.0)
    {
        throw std::runtime_error("[DOMAIN ERROR] cotangent(x)");
        return 0;
    }
    else
    {
        return (1 / tanX);
    }
}
decimalType arcsin(decimalType x)
{
    decimalType sum = 0; // will hold the resulting value of the series
    int samples = 25;
    if (abs(x) > 0.75)
    {
        samples = 30;
    }
    if (abs(x) > 0.95)
    {
        samples = 40;
    }

    /*
    since arcsin is less acurate for values close to 1 and -1,
    sample size will be proportional to the input
    */

    if (x < -1 || x > 1)
    { // out of bounds!
        throw std::runtime_error("[DOMAIN ERROR]: arcsin() must be between -1 and 1");
        return 0.0;
    }
    if (x == 1)
    {
        return (PI * 0.5); // for precision purposes
    }
    else if (x == 0)
    {
        return 0.0;
    }
    else if (x == -1)
    {
        return (PI * -0.5);
    }
    if (abs(x) > 0.98) // better to use guess and check at this point
    {
        // sin(y) = x --> arcsin(x) = y
        bool next = true;
        // guess and check
        decimalType prevGuess = 1.370461484; // this is arcsine(0.98)
        decimalType currentGuess;
        // start with realitively high val
        decimalType dx = 0.1001674212; // this is (arcsin(1) - arcsin(0.98)) / 2
        decimalType sign = ((x > 0 ? 1.0 : -1.0));
        decimalType result;
        while (next)
        {
            currentGuess = prevGuess + (dx * sign);
            prevGuess = currentGuess; // update
            // this makes O(log(N)) where N is the amount of places the result is accurate to
            result = sin(currentGuess);
            if ((abs(abs(result) - abs(x))) < epsilon_TRIG)
            { // within accepted accuracy
                return currentGuess;
            }
            else if (abs(result) > abs(x))
            {
                dx /= 2; // make the dx smaller and check the new section
                sign = (x > 0 ? -1.0 : 1.0);
            }
            else
            {
                dx /= 2;
                sign = (x > 0 ? 1.0 : -1.0);
            }
        }
    }

    // taylor series:
    for (int n = 0; n < samples; n++)
    {
        // the series for arcsin(x):
        sum += (((pow(x, ((2 * n) + 1)) * fact(2 * n))) / ((pow(2, 2 * n) * (pow(fact(n), 2)) * ((2 * n) + 1))));
    }
    return sum;
}
decimalType arccos(decimalType x)
{
    if (x < -1 || x > 1)
    { // out of bounds!
        throw std::runtime_error("[DOMAIN ERROR]: arccos() must be between -1 and 1");
        return 0.0;
    }
    return ((PI * 0.5) - arcsin(x));
}
decimalType arctan(decimalType x)
{
    // arctan(x) = y --> tan(y) = x
    // basically solving for y:
    // lim x -> inf [arctan(x)] = PI / 2
    if (x == 0 || (abs(x) < epsilon_TRIG))
    {
        return 0.0;
    }
    decimalType dx = 0.7853981634; // this is PI / 4
    decimalType sign = (x > 0 ? 1.0 : -1.0);
    decimalType currentGuess = 0.0;
    decimalType result;
    while (true)
    {
        currentGuess += (sign * dx);
        result = tan(currentGuess);
        if (abs(abs(result) - abs(x)) < epsilon_TRIG)
        { // found it!
            return currentGuess;
        }
        else if (abs(result) > abs(x))
        {
            dx /= 2;
            sign = (x > 0 ? -1.0 : 1.0);
        }
        else
        { // result < x
            dx /= 2;
            sign = (x > 0 ? 1.0 : -1.0);
        }
    }
}
decimalType arcsec(decimalType x)
{
    // arcsec(x) = 1/arccos(x)
    decimalType denominator = arccos(x);
    if (abs(denominator) < epsilon_TRIG)
    {
        std::runtime_error("[DOMAIN ERROR] arcsec()");
        return 0.0;
    }
    else
    {
        return 1.0 / denominator;
    }
}
decimalType arccsc(decimalType x)
{
    // arccsc(x) = 1/arcsin(x)
    decimalType denominator = arcsin(x);
    if (abs(denominator) < epsilon_TRIG)
    {
        std::runtime_error("[DOMAIN ERROR] arccsc()");
        return 0.0;
    }
    else
    {
        return 1.0 / denominator;
    }
}
decimalType arccot(decimalType x)
{
    // arccot(x) = 1/arctan(x)
    decimalType denominator = arctan(x);
    if (abs(denominator) < epsilon_TRIG)
    {
        std::runtime_error("[DOMAIN ERROR] arccot()");
        return 0.0;
    }
    else
    {
        return 1.0 / denominator;
    }
}
#endif