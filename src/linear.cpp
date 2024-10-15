// #include <mathlib/linearAlgebra.h>
#include "../include/linearAlgebra.h"
#ifdef __LINEAR_ALGEBRA
#ifdef __VECTORS
Vector::Vector()
{
    degree = 0;
    components = NULL;
}

Vector::Vector(int deg)
{
    degree = deg;
    components = new decimalType[deg];
    for (int i = 0; i < deg; i++)
    {
        components[i] = 0.0;
    }
}

Vector::~Vector()
{
    if (components != NULL)
    {
        delete[] components;
        components = NULL;
    }
}

decimalType Vector::mag()
{
    decimalType result = 0;
    for (int i = 0; i < degree; i++)
    {
        result += square(components[i]);
    }
    result = sqrt(result);
    return result;
}
std::string Vector::toString()
{ // default to component notation
    return toString(COMPONENT_NOTATION);
}
std::string Vector::toString(int notation)
{
    if (degree == 0)
        return "ZERO_VECTOR";
    if (notation == COMPONENT_NOTATION)
    { // <A, B, C, ..., Nth>
        std::string result = "<";
        for (int i = 0; i < degree - 1; i++)
        {
            char subStr[30];
            sprintf(subStr, "%f, ", components[i]);
            result.append(subStr);
        }
        char subStr[30];
        sprintf(subStr, "%f>", components[degree - 1]);
        result.append(subStr);
        return result;
    }
    else if (notation == UNIT_NOTATION)
    { // (Ai + Bk + Cj + ... + Nn)
        std::string result = "(";
        char comp = 'i'; // starting character

        for (int i = 0; i < degree - 1; i++)
        {

            char subStr[30];
            sprintf(subStr, "%f%c %c ", (components[i]) >= 0 ? components[i] : components[i] * -1, comp, (components[i + 1] >= 0) ? '+' : '-');
            result.append(subStr);
            comp++;
        }
        char subStr[30];
        sprintf(subStr, "%f%c)", components[degree - 1], comp);
        result.append(subStr);
        return result;
    }
    else
    { // unknown notation
        throw std::runtime_error("Unknown Vector Notation");
        return 0;
    }
}

void Vector::norm()
{
    decimalType mag = this->mag();
    // cannot normalize a zero vector:
    if (this->mag() == 0)
    {
        throw std::runtime_error("Cannot normalize the zero vector!");
        return;
    }
    for (int i = 0; i < degree; i++)
    {
        components[i] /= mag;
    }
}
void Vector::scale(const decimalType scalar)
{
    for (int i = 0; i < degree; i++)
    {
        components[i] *= scalar;
    }
}

decimalType Vector::dot(const Vector *other) const
{ // dot product (return a scalar quantity
    decimalType result = 0.0;
    // must have same degree:
    if (degree == other->degree)
    {
        if (degree == 0)
        { // the zero vector dotted with itself is always zero
            return 0.0;
        }
        // dot:
        for (int i = 0; i < degree; i++)
        {
            result += (components[i] * other->components[i]);
        }
        return result;
    }
    else
    {
        throw std::runtime_error("Dot Product error: CANNOT DOT 2 VECTORS WITH DIFFERENT DEGREES");
        return 0;
    }
}

Vector Vector::operator+(const Vector &other) const
{
    int deg = this->degree;
    if (this->degree != other.degree)
    {
        throw std::runtime_error("Vector::operator+() error:\nVectors must have the same degree for addition!");
    }
    Vector result(deg);
    for (int i = 0; i < deg; i++)
    {
        result.components[i] = (this->components[i] + other.components[i]);
    }
    return result;
}
Vector Vector::operator-(const Vector &other) const
{
    int deg = this->degree;
    if (this->degree != other.degree)
    {
        throw std::runtime_error("Vector::operator-() error:\nVectors must have the same degree for subtraction!");
    }
    Vector result(deg);
    for (int i = 0; i < deg; i++)
    {
        result.components[i] = (this->components[i] - other.components[i]);
    }
    return result;
}
decimalType Vector::operator*(const Vector &other) const
{
    if (this->degree != other.degree)
    {
        throw std::runtime_error("Vector::operator*() error:\nVectors must have the same degree for dot product!");
    }
    return this->dot(&other);
}

Vector Vector::operator*(const decimalType &other) const
{
    Vector result = Vector(degree);
    for (int i = 0; i < degree; i++)
    {
        result.components[i] = components[i] * other;
    }
    return result;
}

// Vector &Vector::operator=(const Vector &other) // assignment constructor
//{
//     degree = other.degree;
//     if (this != &other)
//     {
//         delete[] components;
//         components = new decimalType[degree];
//         for (int i = 0; i < degree; i++)
//         {
//             components[i] = other.components[i];
//         }
//     }
//     return *this;
// }

#endif

#ifdef __MATRICES

Matrix::Matrix() : rows(0), columns(0)
{
}
Matrix::Matrix(int r, int c) : rows(r), columns(c)
{
    // initialize the matrix
    components = new decimalType *[rows];
    for (int i = 0; i < rows; i++)
    {
        components[i] = new decimalType[columns];

        // initialize to 0 value:
        for (int j = 0; j < columns; j++)
        {
            components[i][j] = 0.0;
        }
    }
}
Matrix::Matrix(int r, int c, decimalType *compArr, int sz) : rows(r), columns(c)
{
    components = new decimalType *[rows];
    for (int i = 0; i < rows; i++)
    {
        components[i] = new decimalType[columns];
    }
    this->initialize(compArr, sz); // initialize the matrix
}

// copy constructor:
Matrix::Matrix(const Matrix &other) : rows(other.rows), columns(other.columns)
{
    components = new decimalType *[rows];
    for (int i = 0; i < rows; i++)
    {
        components[i] = new decimalType[columns];
        for (int j = 0; j < columns; j++)
        {
            components[i][j] = other.components[i][j];
        }
    }
}

Matrix::~Matrix()
{
    // delete all components:
    for (int i = 0; i < rows; i++)
    {
        delete[] components[i];
    }
    delete[] components;
}

std::string Matrix::toString()
{
    std::string result = ""; // start with empty string
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns - 1; j++)
        {
            // printf("appended: [%f]\n", components[i][j]);
            char temp[100];
            sprintf(temp, "[%12.6f] ", components[i][j]);
            result.append(temp);
        }
        // printf("appended: [%f]\n", components[i][columns - 1]);
        char temp[100];
        sprintf(temp, "[%12.6f]\n\n\n", components[i][columns - 1]);
        result.append(temp);
    }
    return result;
}

void Matrix::initializeComp()
{
    if (!components)
    {
        components = new decimalType *[rows];
        for (int i = 0; i < rows; i++)
        {
            components[i] = new decimalType[columns];
        }
    }
}

void Matrix::initialize(decimalType *compArr, int sz)
{
    this->initializeComp(); // just in case the component array is a nullptr
    if (rows * columns == sz)
    {
        // initialize:
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                // this maps the matrix components to the proper index of the array
                components[i][j] = compArr[(i * columns) + j];
            }
        }
    }
    else
    {
        throw std::runtime_error("Initializer array must match the size of the matrix!");
    }
}

// recursive function helper:
decimalType detHelp(Matrix *sub)
{
    decimalType result = 0.0;
    int subRows = sub->rows;
    int subCols = sub->columns;

    if (subRows == 1 && subCols == 1)
    { // -------BASE CASE-------
      //    CURRENT SUB IS 1X1
        return sub->components[0][0];
    }
    decimalType currCoef = 0.0;
    int sign = 1; // will either be +1 or -1
    for (int i = 0; i < subCols; i++)
    {
        currCoef = sub->components[0][i]; // current coefficient to multiply to the minor
        sign = (i % 2 == 0) ? 1 : -1;     // check to see if i is even
        currCoef *= sign;                 // sets the sign
        int subSz = (subCols - 1) * (subRows - 1);
        decimalType *compArr = new decimalType[subSz];
        int nextIndx = 0;
        // initialize the component array
        for (int j = 0; j < subCols; j++) // j = new i (column index)
        {
            if (j == i)
            {
                ; // skip the current column
            }
            else
            {
                for (int k = 1; k < subCols; k++) // k == row index
                {
                    compArr[nextIndx] = sub->components[k][j]; // @todo test this
                    nextIndx++;
                }
            }
        }
        Matrix *newSub = new Matrix(subRows - 1, subCols - 1, compArr, subSz);

        // actual recursive step:

        result += currCoef * detHelp(newSub); // multiply the coefficient to the current minor

        // free up mem
        delete newSub;
        delete[] compArr;
    }
    return result;
}
decimalType Matrix::det()
{
    decimalType determinant = 0.0;
    if (rows == columns) // must be a square matrix
    {
        determinant = detHelp(this);
    }
    else
    {
        throw std::runtime_error("Det(M) error: M must be a square matrix");
    }
    return determinant;
}
Matrix Matrix::transpose() const
{
    Matrix result = Matrix(columns, rows); // new matrix, but rows&columns flipped
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.components[j][i] = components[i][j]; // copy (inverted)
        }
    }
    return result;
}

void Matrix::rowOp(int row1, decimalType scalar1, int row2, decimalType scalar2)
{
    if (row1 >= rows || row2 >= rows)
    {
        throw std::runtime_error("rowOp() error: row index out of bounds of matrix!");
    }
    else
    {
        for (int i = 0; i < columns; i++)
        {
            components[row2][i] = (scalar2 * components[row2][i]) + (scalar1 * components[row1][i]);
        }
    }
}

// rowOp overloads:
void Matrix::rowOp(int row1, decimalType scalar1, int row2)
{
    rowOp(row1, scalar1, row2, 1.0);
}
void Matrix::rowOp(int row1, int row2, decimalType scalar2)
{
    rowOp(row1, 1.0, row2, scalar2);
}
void Matrix::rowOp(int row1, int row2)
{
    rowOp(row1, 1.0, row2, 1.0);
}

//+, -, *, = operators:

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {

        for (int i = 0; i < rows; i++)
        {
            delete[] components[i];
        }
        delete[] components;

        // copy the matrix
        rows = other.rows;
        columns = other.columns;
        components = new decimalType *[rows];

        for (int i = 0; i < rows; i++)
        {
            components[i] = new decimalType[columns];
            for (int j = 0; j < columns; j++)
            {
                components[i][j] = other.components[i][j]; // copy!!
            }
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &other) const
{
    Matrix matSum = Matrix(rows, columns);
    if (columns == other.columns && rows == other.rows)
    { // add
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matSum.components[i][j] = components[i][j] + other.components[i][j];
            }
        }

        return matSum;
    }
    else
    {
        throw std::runtime_error("Addition error: both matrices must have the same dimensions");
    }
}

Matrix Matrix::operator-(const Matrix &other) const
{
    Matrix result = Matrix(rows, columns);
    if (columns == other.columns && rows == other.rows)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                result.components[i][j] = components[i][j] - other.components[i][j];
            }
        }
    }
    else
    {
        throw std::runtime_error("Subtraction error: both matrices must have the same dimensions");
    }
    return result;
}

/*
Pre::M1 columns = M2 Rows
Post::multiplies both matrices as M1 X M2
*/
Matrix Matrix::operator*(const Matrix &other) const
{
    if (columns != other.rows)
    {
        throw std::runtime_error("Multiplication error!\nM1's columns must match M2's rows!");
    }
    Matrix result = Matrix(rows, other.columns);
    // multiply:
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < other.columns; j++)
        {
            decimalType tempSum = 0.0;
            for (int k = 0; k < columns; k++)
            {
                tempSum += (components[i][k] * other.components[k][j]);
            }
            result.components[i][j] = tempSum;
        }
    }
    return result;
}

#endif

#endif
