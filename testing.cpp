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
// holds the largest long double possible
long double largestValue = std::numeric_limits<long double>::max();

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

    return 0;
}