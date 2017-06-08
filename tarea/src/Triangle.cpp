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

double Triangle::area()
{
    int p1=puntos.get(0)->getX()- puntos.get(1)->getX();
    int p2=puntos.get(1)->getX()- puntos.get(2)->getX();
    int p3=puntos.get(2)->getX()- puntos.get(0)->getX();

    int p4=puntos.get(0)->getY()- puntos.get(1)->getY();
    int p5=puntos.get(1)->getY()- puntos.get(2)->getY();
    int p6=puntos.get(2)->getY()- puntos.get(0)->getY();

    int a=sqrt(p1*p1 + p2*p2);
    int b=sqrt(p2*p2 + p3*p3);
    int c=sqrt(p3*p3 + p1*p1);

    int s=(a+b+c)/2;

    return sqrt(s*(s-a)*(s-b)*(s-c));
}


