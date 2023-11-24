/*
A testing environment for the math operators made by me
Liam Tolkkinen
11/23/2023
*/

#include <stdio.h>
#include "math.h"
#include <limits>
#define multiplyRVal1 -1.0
#define multiplyIVal1 2.0
#define multiplyRVal2 3.0
#define multiplyIVal2 -4.0
// holds the largest long double possible
long double largestValue = std::numeric_limits<long double>::max();

int main()
{
    printf("testing...\n");
    printf("new complex: 5 + 19i:\n");
    ComplexNum complexValue = ComplexNum(5, 19);
    printf("toString() test: %s\n", complexValue.toString().c_str());

    printf("multiplying 2 complex numbers together:\n(%f %c %fi) * (%f %c %fi):\n", multiplyRVal1,
           (multiplyIVal1 >= 0 ? '+' : '-'), (multiplyIVal1 >= 0 ? multiplyIVal1 : multiplyIVal1 * -1),
           multiplyRVal2, (multiplyIVal2 >= 0 ? '+' : '-'),
           (multiplyIVal2 >= 0 ? multiplyIVal2 : multiplyIVal2 * -1));
    ComplexNum complexValue1 = ComplexNum(multiplyRVal1, multiplyIVal1);
    ComplexNum complexValue2 = ComplexNum(multiplyRVal2, multiplyIVal2);
    ComplexNum complexMultiplyResult = complexValue1 * complexValue2;
    printf("Result: %s\n", complexMultiplyResult.toString().c_str());

    return 0;
}