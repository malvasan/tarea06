#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Polygon.h"

class Rectangle:public Polygon
{
    public:
        Rectangle(Point left, Point upper);
        Rectangle(int x1,int y1,int x2,int y2);
        virtual double area();

};

#endif // RECTANGLE_H
