#include "Triangle.h"
Point constructorPoint [3];

Point * updatConstructorPoints(const Point &p1 ,const Point &p2 ,const Point &p3 = Point (0 ,0))
{
    constructorPoint [0] = p1;
    constructorPoint [1] = p2;
    constructorPoint [2] = p3;
    return constructorPoint;
}

Triangle::Triangle(Point a,Point b,Point c):Polygon(updatConstructorPoints(a,b,c),3)
{

}


