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
    Vector();
    Vector(int degree);
    ~Vector();                          // degree is how many elements in the vector
    std::string toString();             // print the vector out in component form
    std::string toString(int notation); // for choosing what notation to print it in
    int getDegree();
    decimalType getVal(int x); // get the value at index x
    void setDegree(int degree);
    void setVal(int x, decimalType newVal); // set the value at x to be newVal
    decimalType dot(Vector *other);         // dot product
    Vector *cross(Vector *other);           // cross product
    decimalType mag();                      // returns the magnitude of the vector
    void norm();                            // normalize the vector
    void scale(decimalType scalar);         // apply a scalar to the vector and return

private:
    int degree;
    decimalType *components;
};
#endif
#ifdef __MATRICES
class Matrix
{
public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix(int rows, int columns, decimalType *compArr, int sz);
    Matrix(const Matrix &other); // copy constructor
    ~Matrix();
    void initialize(decimalType *componentArray, int size);
    void initializeComp();
    decimalType get(int i, int j) const;        // get value in M(i, j)
    void set(int i, int j, decimalType newVal); // set value in M(i, j) to newVal
    std::string toString();                     // return the string print of the matrix M
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
    int getRows() const;
    int getColumns() const;

    // performs: row2 = (Scalar1*row1 + Scalar2*row2)
    void rowOp(int row1, decimalType scalar1, int row2, decimalType scalar2);
    void rowOp(int row1, decimalType scalar1, int row2);
    void rowOp(int row1, int row2, decimalType scalar2);

    void rowOp(int row1, int row2);

private:
    decimalType **components; // a 2-D array to hold the matrix components
    int rows;
    int columns;
};
#endif
#endif
