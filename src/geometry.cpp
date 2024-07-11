#include "../include/geometry.h"

Polygon::Polygon()
{
    n = 0;
    vertices = nullptr; // no space allocated
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
    if (n > 0 && vertices != nullptr) // to prevent freeing a nullptr
    {
        delete[] vertices;
    }
}