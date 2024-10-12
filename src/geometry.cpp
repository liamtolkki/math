#include <mathlib/geometry.h>

decimalType Polygon::area()
{
    decimalType area = 0.0;     // initialize the area to 0
    for (int i = 0; i < n; i++) // n is the number of vertices
    {
        int j = (i + 1) % n;
        area += vertices[i].x * vertices[j].y; // really just a big determinant calculation
        area -= vertices[i].y * vertices[j].x;
    }
    area = abs(area / 2.0); // because the shoelace method calculates 2 * Area
    return area;
}

decimalType distance(point p1, point p2)
{ // returns the distance from p1 to p2
    return sqrt(square(p1.x - p2.x) + square(p1.y - p2.y));
}
decimalType Polygon::perimeter()
{
    decimalType length = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            length += distance(vertices[i], vertices[0]); // wrap back to first point
        }
        else
        {
            length += distance(vertices[i], vertices[i + 1]); // sum distance
        }
    }
    return length;
}

int Polygon::getN()
{
    return n;
}
void Polygon::setN(int newN)
{
    n = newN;
}
Polygon::Polygon()
{
    n = 0;
    vertices = NULL; // no space allocated
}
Polygon::Polygon(int nVal)
{
    n = nVal;
    vertices = new point[n]; // allocate the proper amount of space
}
Polygon::Polygon(int nVal, point *vertexArray)
{
    n = nVal;
    vertices = new point[n]; // allocate
    for (int i = 0; i < n; i++)
    {
        vertices[i] = vertexArray[i]; // hard copy
    }
}

Polygon::~Polygon()
{
    if (n > 0 && vertices != NULL) // to prevent freeing a nullptr
    {
        delete[] vertices;
    }
}
decimalType Circle::area()
{
    return PI * radius * radius; // A = PI * r**2
}
decimalType Circle::circumference()
{
    return 2.0 * PI * radius;
}
Circle::Circle() : radius(0.0), center(point()) {}
Circle::Circle(decimalType r) : radius(r), center(point()) {}
Circle::Circle(decimalType r, point p) : radius(r), center(p) {}
Circle::~Circle()
{
}