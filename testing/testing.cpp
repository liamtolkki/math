/*
A testing environment for the math library made by me
Liam Tolkkinen
11/23/2023
*/

#define __MATRIX_TESTING
#define __DETERMINANT_TESTING
#define __MATRIX_SUM_TESTING

#include <stdio.h>
#include "../include/math.h"
#include "../include/linearAlgebra.h"
#include "../include/complex.h"
#ifdef __CALCULUS
#include "../include/calculus.h"
#endif
#ifdef __POLYNOMIALS
#include "../include/polynomial.h"
#endif
#include "../include/trig.h"
#include <limits>
#define multiplyRVal1 -1.0
#define multiplyIVal1 2.0
#define multiplyRVal2 0.0
#define multiplyIVal2 1.0
#define factorial 20.0
#define fibVal1 10
#define fibVal2 1000
#define gcd1 18438
#define gcd2 210
#define decimal 3.14159
#define coefficient 3.0
#define exp1 2
#define coefficient2 6.0
#define exp2 2
#define e_pow 2.653

// log testing macros
#define loginput1 0.0000245
#define loginput2 e
#define loginput3 9871813.971307031
#define loginput4 1.0
#define logbase1 10.0
#define logbase2 2.0
#define logbase3 3.14159
#define loginput5 1000.0
#define loginput6 2048.0
#define loginput7 3.9343

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

#define polynomial1Arr      \
       {                    \
              1.0, 2.0, 3.0 \
       }
#define polynomial1SZ 3

#define polynomial2Arr                \
       {                              \
              2.0, 1.0, 6.0, 5.0, 2.0 \
       }
#define polynomial2SZ 5

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
       SciNot sciNotTest = SciNot(coefficient, exp1);
       printf("testing scientific notation:\nCoef: %.15f\nexp: %d\nResult: %s\n", coefficient,
              exp1, sciNotTest.toString().c_str());
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
#ifdef __EXPONENTIALS
       decimalType powResult = pow(powBase, powExp);
       printf("testing %f^%d: %f\n", powBase, powExp, powResult);

       printf("testing exp(x):\n");
       printf("exp(%f) = %f\n", e_pow, exp(e_pow));
#endif
       printf("testing nth root: %d root of %f: ", nRootN, nRootBase);
       decimalType nrootResult = nRoot(nRootBase, nRootN);
       printf("%f\n", nrootResult);
       printf("Testing Factorial: \n%.0f! = ", factorial);
       decimalType factResult = fact(factorial);

       printf("%.0f\n", factResult);
       SciNot factResultSciNot = SciNot(factResult);
       printf("conversion to Scientific Notation: %s\n", factResultSciNot.toString().c_str());

       printf("Testing GCD:\n");
       printf("gcd(%i, %i) = %i\n", gcd1, gcd2, gcd(gcd1, gcd2));

       printf("Testing toFrac(%f)\n", decimal);
       Fraction piFrac = toFrac(decimal);
       printf("toFrac(%f) = %s\n", decimal, piFrac.toString().c_str());

       printf("Testing fibonacci:\n");
       printf("fib(%i) = ", fibVal1);
       printf("%.0f\n", fib(fibVal1));
       printf("fib(%i) = ", fibVal2);
       printf("%.0f\n", fib(fibVal2));

#ifdef __LOGARITHMS
       printf("\n\nTESTING LOGARITHMS-----------------------------\n");
       decimalType logResult1 = ln(loginput1);
       printf("Testing ln(x): ln(%f) = %f\n", loginput1, logResult1);
       decimalType logResult2 = ln(loginput2);
       printf("Testing ln(x): ln(%f) = %f\n", loginput2, logResult2);
       decimalType logResult3 = ln(loginput3);
       printf("Testing ln(x): ln(%f) = %f\n", loginput3, logResult3);
       decimalType logResult4 = ln(loginput4);
       printf("Testing ln(x): ln(%f) = %f\n", loginput4, logResult4);

       decimalType logResult5 = log(logbase1, loginput5);
       printf("Testing log(n, x): log(%f, %f) = %f\n", logbase1, loginput5, logResult5);
       decimalType logResult6 = log(logbase2, loginput6);
       printf("Testing log(n, x): log(%f, %f) = %f\n", logbase2, loginput6, logResult6);
       decimalType logResult7 = log(logbase3, loginput7);
       printf("Testing log(n, x): log(%f, %f) = %f\n", logbase3, loginput7, logResult7);

       printf("END TESTING LOGARITHMS-------------------------\n\n\n");

#endif
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
       Vector vec1 = Vector(degree);
       vec1.setVal(0, v1);
       vec1.setVal(1, v2);
       vec1.setVal(2, v3);
       Vector vec2 = Vector(degree);
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
       Matrix m1 = Matrix(M1Rows, M1Columns, componentArray1, M1Sz);
       printf("Matrix 1:\n%s\n", m1.toString().c_str());

       decimalType componentArray2[] = M2CompArr;
       Matrix m2 = Matrix(M2Rows, M2Columns, componentArray2, M2Sz);
       printf("Matrix 2:\n%s\n", m2.toString().c_str());

       decimalType componentArray3[] = M3CompArr;
       Matrix m3 = Matrix(M3Rows, M3Columns, componentArray3, M3Sz);
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
       Matrix m4 = Matrix(M4Rows, M4Columns, componentArray4, M4Sz);
       printf("Matrix 4:\n%s", m4.toString().c_str());
       decimalType detTest1 = m4.det();
       printf("det(M4) = %f\n", detTest1);

       decimalType componentArray5[] = M5CompArr;
       Matrix m5 = Matrix(M5Rows, M5Columns, componentArray5, M5Sz);
       printf("Matrix 5:\n%s\n", m5.toString().c_str());

#ifdef __MATRIX_SUM_TESTING
       Matrix matSum = Matrix(M1Rows, M1Columns);
       matSum = m1 + m1;
       printf("Testing M1 + M1:\n%s", matSum.toString().c_str());

       matSum = m4 - m5;
       printf("Testing M4 - M5:\n%s", matSum.toString().c_str());

       Matrix matProd = m4 * m4;
       printf("Testing M4 * M4:\n%s", matProd.toString().c_str());
       matProd = m5 * m5;
       printf("Testing M5 * M5:\n%s", matProd.toString().c_str());

       decimalType componentArray6[] = M6CompArr;
       Matrix m6 = Matrix(M6Rows, M6Columns, componentArray6, M6Sz);
       printf("Matrix 6:\n%s\n", m6.toString().c_str());

       decimalType componentArray7[] = M7CompArr;
       Matrix m7 = Matrix(M7Rows, M7Columns, componentArray7, M7Sz);
       printf("Matrix 7:\n%s\n", m7.toString().c_str());
       matProd = m6 * m7;
       printf("Testing M6 * M7:\n%s", matProd.toString().c_str());
       printf("Testing (M6 * M7) transpose:\n");
       Matrix matProdT = matProd.transpose();
       printf("%s\n", matProdT.toString().c_str());

       printf("row operations (matrix_5):\n");
       printf("%s", m5.toString().c_str());

       printf("(M5): R1*(2) + R2*(-5.2) --> R2\n");
       m5.rowOp(0, 2.0, 1, -5.2);
       printf("%s", m5.toString().c_str());

#endif

#endif
#endif
#endif

       printf("END TESTING LINEAR ALGEBRA---------------\n\n");

#endif
#ifdef __POLYNOMIALS
       printf("TESTING POLYNOMIALS-----------------\n");
       Polynomial emptyPolynomial; // to test default constructor
       decimalType poly1Arr[] = polynomial1Arr;
       Polynomial poly1 = Polynomial(poly1Arr, polynomial1SZ);
       printf("Polynomial 1\n");
       poly1.printPoly();
       decimalType poly2Arr[] = polynomial2Arr;
       Polynomial poly2 = Polynomial(poly2Arr, polynomial2SZ);
       printf("Polynomial 2\n");
       poly2.printPoly();
       printf("Testing Polynomial1 + polynomial2:\n");
       Polynomial polySum = poly1 + poly2;
       polySum.printPoly();
       printf("Testing polynomial1 - polynomial2:\n");
       Polynomial polySubtract = poly1 - poly2;
       polySubtract.printPoly();
#endif
       return 0;
}