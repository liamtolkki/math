#include "math.h"
#define __LINEAR_ALGEBRA
#define __VECTORS
#define __MATRICES
#define __VECTOR_NOTATION_CONSTANTS
#ifdef __VECTOR_NOTATION_CONSTANTS
const int COMPONENT_NOTATION = 0;
const int UNIT_NOTATION = 1;
#endif
#ifdef __LINEAR_ALGEBRA
#ifdef __VECTORS

class Vector
{
public:
    int degree;
    decimalType *components;
    Vector();
    Vector(int degree);
    ~Vector();
    std::string toString();                     // print the vector out in component form
    std::string toString(int notation);         // for choosing what notation to print it in
    decimalType dot(const Vector *other) const; // dot product
    Vector *cross(Vector *other);               // cross product
    decimalType mag();                          // returns the magnitude of the vector
    void norm();                                // normalize the vector
    void scale(const decimalType scalar);       // apply a scalar to the vector and return

    // vector operators:
    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    decimalType operator*(const Vector &other) const;
    Vector operator*(const decimalType &other) const; // for scalar multiplication
    // Vector &operator=(const Vector &other);           // assignment constructor
};
#endif
#ifdef __MATRICES
class Matrix
{
public:
    decimalType **components; // a 2-D array to hold the matrix components
    int rows;
    int columns;
    Matrix();
    Matrix(int rows, int columns);
    Matrix(int rows, int columns, decimalType *compArr, int sz);
    Matrix(const Matrix &other); // copy constructor
    ~Matrix();
    void initialize(decimalType *componentArray, int size);
    void initializeComp();
    std::string toString(); // return the string print of the matrix M
    Matrix &operator=(const Matrix &other);
    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
#ifdef __MATRIX_INVERSE
    Matrix inverse() const; // return the inverse of M (if exists)
#endif

    void scale(decimalType scalar);         // multiply a scalar to all the elements of M
    decimalType det();                      // determinant of M
    Matrix transpose() const;               // transpose of M
    decimalType minor(int row, int column); // returns the minor of M. (eg: M(1,2))
    // performs: row2 = (Scalar1*row1 + Scalar2*row2)
    void rowOp(int row1, decimalType scalar1, int row2, decimalType scalar2);
    void rowOp(int row1, decimalType scalar1, int row2);
    void rowOp(int row1, int row2, decimalType scalar2);

    void rowOp(int row1, int row2);
};
#endif
#endif
