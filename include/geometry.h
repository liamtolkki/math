/*
Geometry header for geometry.cpp
made by Liam Tolkkinen
*/
#include "math.h"

struct point // represents a cartesian 2D point
{
    point(decimalType x_val = 0.0, decimalType y_val = 0.0) : x(x_val), y(y_val) {}
    decimalType x;
    decimalType y;
};

class Polygon
{
private:
    /* data */
    int n;           // the degree of the polygon (E.G. triangle: n = 3)
    point *vertices; // an array of vertices (points) of length n
public:
    int getN();
    void setN(int n);
    point *getVertices(); // returns an array of points

    Polygon();                         // default constructor
    Polygon(int n);                    // default constructor given n
    Polygon(int n, point *vertexList); // constructor
    ~Polygon();                        // destructor
};
