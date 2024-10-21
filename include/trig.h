#ifdef DEVELOPMENT_MODE
#include "math.h"
#else
#include <mathlib/math.h>
#endif
// BEGIN BASIC TRIG FUNCTIONS--------------
#ifdef TRIG
decimalType sin(decimalType x);
decimalType cos(decimalType x);
decimalType tan(decimalType x);
decimalType sec(decimalType x);
decimalType csc(decimalType x);
decimalType cot(decimalType x);
decimalType arcsin(decimalType x);
decimalType arccos(decimalType x);
decimalType arctan(decimalType x);
decimalType arcsec(decimalType x);
decimalType arccsc(decimalType x);
decimalType arccot(decimalType x);

decimalType toDeg(decimalType rad); // radians -> degrees
decimalType toRad(decimalType deg); // degrees -> radians
#endif
// END BASIC TRIG FUNCTIONS-----------------