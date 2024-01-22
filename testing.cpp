/*
A testing environment for the math library made by me
Liam Tolkkinen
11/23/2023
*/

#define __MATRIX_TESTING
#define __DETERMINANT_TESTING
#define __MATRIX_SUM_TESTING

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
// vector components:
#define degree 3
#define v1 2.0
#define v2 3.0
#define v3 4.0

#define u1 3.0
#define u2 -2.0
#define u3 2.0

// matrix testing stuff:
#define M1Rows 4
#define M1Columns 3
#define M1Sz (M1Rows * M1Columns)
#define M1CompArr                                                        \
       {                                                                 \
              4.0, 6.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 2.0, 0.0, 1.0, 4.0 \
       }

#define M2Rows 4
#define M2Columns 4
#define M2Sz (M2Rows * M2Columns)
#define M2CompArr                                                                                          \
       {                                                                                                   \
              3.0, 24.0, 6.0, 4.5, 3.04, 0.0, -28.0, 7.922, -0.23, 83.0, 2.0, 9.0, 83.1, -19.0, 2.718, 3.3 \
       }
#define M3CompArr                                         \
       {                                                  \
              4.0, 6.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 2.0 \
       }
#define M3Rows 3
#define M3Columns 3
#define M3Sz (M3Rows * M3Columns)

#define M4CompArr                \
       {                         \
              2.0, 3.0, 4.0, 2.0 \
       }
#define M4Columns 2

#define M4Rows 2
#define M4Sz (M4Rows * M4Columns)

#define M5CompArr                \
       {                         \
              1.0, 2.0, 5.0, 3.0 \
       }
#define M5Columns 2

#define M5Rows 2
#define M5Sz (M5Rows * M5Columns)

#define M6CompArr                          \
       {                                   \
              1.0, 2.0, 5.0, 3.0, 9.0, 0.0 \
       }
#define M6Columns 3

#define M6Rows 2
#define M6Sz (M6Rows * M6Columns)
#define M7CompArr                                         \
       {                                                  \
              3.0, 4.0, 0.0, -9.0, 6.5, 0.6, 3.1, 2, 8.95 \
       }
#define M7Columns 3

#define M7Rows 3
#define M7Sz (M7Rows * M7Columns)

// det(M3) should be 30
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
       printf("END Testing TRIG----------------------------------\n");

       printf("Testing INVERSE TRIG:----------------------------------\n");
       printf("Testing arcsin(x): arcsin(%f) = %.10f\n", inverseTrig, arcsin(inverseTrig));
       printf("Testing arccos(x): arccos(%f) = %.10f\n", inverseTrig, arccos(inverseTrig));
       printf("Testing arctan(x): arctan(%f) = %.10f\n", inverseTrig, arctan(inverseTrig));
       printf("Testing arccsc(x): arccsc(%f) = %.10f\n", inverseTrig, arccsc(inverseTrig));
       printf("Testing arcsec(x): arcsec(%f) = %.10f\n", inverseTrig, arcsec(inverseTrig));
       printf("Testing arccot(x): arccot(%f) = %.10f\n", inverseTrig, arccot(inverseTrig));
       printf("END Testing INVERSE TRIG----------------------------------\n");

#endif

#ifdef __LINEAR_ALGEBRA
#ifdef __VECTORS
       // test the linear algebra library
       LinearAlgebra::Vector vec1 = LinearAlgebra::Vector(degree);
       vec1.setVal(0, v1);
       vec1.setVal(1, v2);
       vec1.setVal(2, v3);
       LinearAlgebra::Vector vec2 = LinearAlgebra::Vector(degree);
       vec2.setVal(0, u1);
       vec2.setVal(1, u2);
       vec2.setVal(2, u3);
       printf("TESTING LINEAR ALGEBRA-------------------\n\n");
       printf("TESTING VECTORS--------------------------\n\n");

       printf("Vector1 (component notation): %s\n", vec1.toString(COMPONENT_NOTATION).c_str());
       printf("Vector1 (Unit notation): %s\n", vec1.toString(UNIT_NOTATION).c_str());

       printf("Vector2 (component notation): %s\n", vec2.toString(COMPONENT_NOTATION).c_str());
       printf("Vector2 (Unit notation): %s\n", vec2.toString(UNIT_NOTATION).c_str());

       printf("Vector1 magnitude: %f\n", vec1.mag());
       printf("Vector2 magnitude: %f\n", vec2.mag());

       decimalType dotResult = vec1.dot(&vec2);

       printf("Testing V1 dot V2: %f\n", dotResult);

       vec1.norm();
       vec2.norm();
       printf("Vector1 normalized: %s\n", vec1.toString().c_str());
       printf("Vector1 magnitude: %f\n", vec1.mag());
       printf("Vector2 normalized: %s\n", vec2.toString().c_str());
       printf("Vector2 magnitude: %f\n", vec2.mag());

       printf("END TESTING VECTORS----------------------\n");
#endif
#ifdef __MATRICES
#ifdef __MATRIX_TESTING

       printf("TESTING MATRICES--------------------------\n\n");

       decimalType componentArray1[] = M1CompArr;
       LinearAlgebra::Matrix m1 = LinearAlgebra::Matrix(M1Rows, M1Columns, componentArray1, M1Sz);
       printf("Matrix 1:\n%s\n", m1.toString().c_str());

       decimalType componentArray2[] = M2CompArr;
       LinearAlgebra::Matrix m2 = LinearAlgebra::Matrix(M2Rows, M2Columns, componentArray2, M2Sz);
       printf("Matrix 2:\n%s\n", m2.toString().c_str());

       decimalType componentArray3[] = M3CompArr;
       LinearAlgebra::Matrix m3 = LinearAlgebra::Matrix(M3Rows, M3Columns, componentArray3, M3Sz);
       printf("Matrix 3:\n%s\n", m3.toString().c_str());

       printf("testing get():\n");
       printf("getting matrix_1(1,1): %f\n", m1.get(1, 1));
       printf("getting matrix_2(1,1): %f\n", m2.get(1, 1));
       m1.set(1, 1, 3.1415);
       m2.set(1, 1, 12.34);
       printf("testing set():\n");

       printf("setting matrix_1(1,1) to 3.1415:\n");
       printf("Matrix 1:\n%s\n", m1.toString().c_str());

       printf("setting matrix_2(1,1) to 12.34:\n");
       printf("Matrix 2:\n%s\n", m2.toString().c_str());

#ifdef __DETERMINANT_TESTING
       printf("Testing determinants----------------------\n");

       // det(M3) should be 30
       decimalType detTest2 = m3.det();
       printf("det(M3) = %f\n", detTest2);

       decimalType componentArray4[] = M4CompArr;
       LinearAlgebra::Matrix m4 = LinearAlgebra::Matrix(M4Rows, M4Columns, componentArray4, M4Sz);
       printf("Matrix 4:\n%s", m4.toString().c_str());
       decimalType detTest1 = m4.det();
       printf("det(M4) = %f\n", detTest1);

       decimalType componentArray5[] = M5CompArr;
       LinearAlgebra::Matrix m5 = LinearAlgebra::Matrix(M5Rows, M5Columns, componentArray5, M5Sz);
       printf("Matrix 5:\n%s\n", m5.toString().c_str());

#ifdef __MATRIX_SUM_TESTING
       LinearAlgebra::Matrix matSum = LinearAlgebra::Matrix(M1Rows, M1Columns);
       matSum = m1 + m1;
       printf("Testing M1 + M1:\n%s", matSum.toString().c_str());

       matSum = m4 - m5;
       printf("Testing M4 - M5:\n%s", matSum.toString().c_str());

       LinearAlgebra::Matrix matProd = m4 * m4;
       printf("Testing M4 * M4:\n%s", matProd.toString().c_str());
       matProd = m5 * m5;
       printf("Testing M5 * M5:\n%s", matProd.toString().c_str());

       decimalType componentArray6[] = M6CompArr;
       LinearAlgebra::Matrix m6 = LinearAlgebra::Matrix(M6Rows, M6Columns, componentArray6, M6Sz);
       printf("Matrix 6:\n%s\n", m6.toString().c_str());

       decimalType componentArray7[] = M7CompArr;
       LinearAlgebra::Matrix m7 = LinearAlgebra::Matrix(M7Rows, M7Columns, componentArray7, M7Sz);
       printf("Matrix 7:\n%s\n", m7.toString().c_str());
       matProd = m6 * m7;
       printf("Testing M6 * M7:\n%s", matProd.toString().c_str());

#endif

#endif
#endif
#endif

       printf("END TESTING LINEAR ALGEBRA---------------\n");

#endif
       return 0;
}