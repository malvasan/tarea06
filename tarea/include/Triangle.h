#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.h"

class Triangle:public Polygon
{
    public:
        Triangle(Point a,Point b,Point c);
        virtual double area();
};

#endif // TRIANGLE_H
