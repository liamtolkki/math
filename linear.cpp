#include "math.h"
#ifdef __LINEAR_ALGEBRA
#ifdef __VECTORS
LinearAlgebra::Vector::Vector()
{
    degree = 0;
    components = nullptr;
}

LinearAlgebra::Vector::Vector(int deg)
{
    degree = deg;
    components = new decimalType[deg];
}

LinearAlgebra::Vector::~Vector()
{
    delete components;
}

int LinearAlgebra::Vector::getDegree()
{
    return degree;
}
void LinearAlgebra::Vector::setDegree(int deg)
{
    delete components;
    components = new decimalType[deg];
    degree = deg;
}
decimalType LinearAlgebra::Vector::getVal(int x)
{
    if (x < degree)
    {
        return components[x];
    }
    else
    {
        throw std::runtime_error("Vector Index Out of Bounds ERROR");
        return 0;
    }
}
void LinearAlgebra::Vector::setVal(int x, decimalType newVal)
{ // sets component x to newVal
    if (x < degree)
    {
        components[x] = newVal;
    }
    return;
}
decimalType LinearAlgebra::Vector::mag()
{
    decimalType result = 0;
    for (int i = 0; i < degree; i++)
    {
        result += square(components[i]);
    }
    result = sqrt(result);
    return result;
}
std::string LinearAlgebra::Vector::toString()
{ // default to component notation
    return toString(COMPONENT_NOTATION);
}
std::string LinearAlgebra::Vector::toString(int notation)
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

void LinearAlgebra::Vector::norm()
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

decimalType LinearAlgebra::Vector::dot(Vector *other)
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
#endif

#ifdef __MATRICES

LinearAlgebra::Matrix::Matrix() : rows(0), columns(0), components(nullptr)
{
}

LinearAlgebra::Matrix::Matrix(int r, int c) : rows(r), columns(c)
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
LinearAlgebra::Matrix::Matrix(int r, int c, decimalType *compArr, int sz) : rows(r), columns(c)
{
    components = new decimalType *[rows];
    for (int i = 0; i < rows; i++)
    {
        components[i] = new decimalType[columns];
    }
    this->initialize(compArr, sz); // initialize the matrix
}
LinearAlgebra::Matrix::~Matrix()
{
    // delete all components:
    for (int i = 0; i < rows; i++)
    {
        delete components[i];
    }
    delete components;
}

decimalType LinearAlgebra::Matrix::get(int i, int j)
{
    if ((i < rows) && (j < columns))
    {
        return components[i][j];
    }
    else
    {
        throw std::runtime_error("index out of range of matrix");
    }
}
void LinearAlgebra::Matrix::set(int i, int j, decimalType newVal)
{
    if ((i < rows) && (j < columns))
    {
        components[i][j] = newVal;
    }
    else
    {
        throw std::runtime_error("index out of range of matrix");
    }
}

std::string LinearAlgebra::Matrix::toString()
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

void LinearAlgebra::Matrix::initialize(decimalType *compArr, int sz)
{
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

//+, -, * operators:

LinearAlgebra::Matrix LinearAlgebra::Matrix::operator+(const Matrix &other) const
{
    if (columns == other.columns && rows == other.rows)
    { // add
        Matrix matSum = Matrix(rows, columns);
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

#endif

#endif
