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
#define factorial 10
#define coefficient 3.0
#define exp 2
#define coefficient2 6.0
#define exp2 2

#define powBase 5.0
#define powExp 6
#define nRootBase 10.0
#define nRootN 3

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
       printf("Testing Factorial: \n%d! = ", factorial);
       long int factResult = fact(factorial);
       printf("%ld\n", factResult);

       return 0;
}