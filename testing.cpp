/*
A testing environment for the math library made by me
Liam Tolkkinen
11/23/2023
*/

#include <stdio.h>
#include "math.h"
#include <limits>
#define multiplyRVal1 -1.0
#define multiplyIVal1 2.0
#define multiplyRVal2 0.0
#define multiplyIVal2 1.0
#define factorial 20.0
#define coefficient 3.0
#define exp 2
#define coefficient2 6.0
#define exp2 2

#define powBase 5.0
#define powExp 6
#define nRootBase 26.0
#define nRootN 29
#define degrees 180.0
#define radians PI
#define theta .75 * PI
#define inverseTrig 0.79274

// holds the largest long double possible
decimalType largestValue = std::numeric_limits<decimalType>::max();

int main()
{
       printf("testing...\n");
       ComplexNum complexValue1 = ComplexNum(multiplyRVal1, multiplyIVal1);
       ComplexNum complexValue2 = ComplexNum(multiplyRVal2, multiplyIVal2);
       printf("toString() test: %s\n", complexValue1.toString().c_str());

       printf("multiplying 2 complex numbers together:\n%s * %s:\n",
              complexValue1.toString().c_str(), complexValue2.toString().c_str());

       ComplexNum complexMultiplyResult = complexValue1 * complexValue2;
       printf("Result: %s\n", complexMultiplyResult.toString().c_str());

       printf("dividing 2 complex numbers together:\n%s / %s:\n",
              complexValue1.toString().c_str(), complexValue2.toString().c_str());
       ComplexNum complexDivideResult = complexValue1 / complexValue2;
       printf("Result: %s\n", complexDivideResult.toString().c_str());
       SciNot sciNotTest = SciNot(coefficient, exp);
       printf("testing scientific notation:\nCoef: %.15f\nexp: %d\nResult: %s\n", coefficient,
              exp, sciNotTest.toString().c_str());
       SciNot sciNotTest2 = SciNot(coefficient2, exp2);
       printf("Testing Scientific notation addition:\n");
       printf("%s + %s:\n", sciNotTest.toString().c_str(), sciNotTest2.toString().c_str());
       SciNot sciNotOperatorResult = sciNotTest + sciNotTest2;
       printf("%s\n", sciNotOperatorResult.toString().c_str());

       printf("Testing Scientific notation subtraction:\n");
       printf("%s - %s:\n", sciNotTest.toString().c_str(), sciNotTest2.toString().c_str());
       sciNotOperatorResult = sciNotTest - sciNotTest2;
       printf("%s\n", sciNotOperatorResult.toString().c_str());

       printf("Testing Scientific notation multiplication:\n");
       printf("%s * %s:\n", sciNotTest.toString().c_str(), sciNotTest2.toString().c_str());
       sciNotOperatorResult = sciNotTest * sciNotTest2;
       printf("%s\n", sciNotOperatorResult.toString().c_str());

       printf("Testing Scientific notation division:\n");
       printf("%s / %s:\n", sciNotTest.toString().c_str(), sciNotTest2.toString().c_str());
       sciNotOperatorResult = sciNotTest / sciNotTest2;
       printf("%s\n", sciNotOperatorResult.toString().c_str());
       decimalType powResult = pow(powBase, powExp);
       printf("testing %f^%d: %f\n", powBase, powExp, powResult);
       printf("testing nth root: %d root of %f: ", nRootN, nRootBase);
       decimalType nrootResult = nRoot(nRootBase, nRootN);
       printf("%f\n", nrootResult);
       printf("Testing Factorial: \n%f! = ", factorial);
       decimalType factResult = fact(factorial);
       printf("%f\n", factResult);
       SciNot factResultSciNot = SciNot(factResult);
       printf("conversion to Scientific Notation: %s\n", factResultSciNot.toString().c_str());
#ifdef TRIG
       printf("Degrees to Radians: %.10f deg = %.10f rad\n", degrees, toRad(degrees));
       printf("Radians to Degrees: %.10f rad = %.10f deg\n", radians, toDeg(radians));
       printf("Testing the Trig Functions:-----------------------------\n");
       printf("Testing sin(x): sin(%f) = %.10f\n", theta, sin(theta));
       printf("Testing cos(x): cos(%f) = %.10f\n", theta, cos(theta));
       printf("Testing tan(x): tan(%f) = %.10f\n", theta, tan(theta));

       printf("Testing csc(x): csc(%f) = %.10f\n", theta, csc(theta));
       printf("Testing sec(x): sec(%f) = %.10f\n", theta, sec(theta));
       printf("Testing cot(x): cot(%f) = %.10f\n", theta, cot(theta));
       printf("Testing INVERSE TRIG:----------------------------------\n");
       printf("Testing arcsin(x): arcsin(%f) = %.10f\n", inverseTrig, arcsin(inverseTrig));
       printf("Testing arccos(x): arccos(%f) = %.10f\n", inverseTrig, arccos(inverseTrig));
       printf("Testing arctan(x): arctan(%f) = %.10f\n", inverseTrig, arctan(inverseTrig));
       printf("Testing arccsc(x): arccsc(%f) = %.10f\n", inverseTrig, arccsc(inverseTrig));
       printf("Testing arcsec(x): arcsec(%f) = %.10f\n", inverseTrig, arcsec(inverseTrig));
       printf("Testing arccot(x): arccot(%f) = %.10f\n", inverseTrig, arccot(inverseTrig));


#endif
       return 0;
}