#include "Rectangle.h"
Point constructorPoints [4];

Point * updateConstructorPoints(const Point &p1 ,const Point &p2 ,const Point &p3 ,const Point &p4 = Point (0 ,0))
{
    constructorPoints [0] = p1;
    constructorPoints [1] = p2;
    constructorPoints [2] = p3;
    constructorPoints [3 ] = p4;
    return constructorPoints;
}

Rectangle::Rectangle(Point left,Point upper):Polygon(updateConstructorPoints(left,Point(left.getX(),upper.getY()),Point(upper.getX(),left.getY()),upper),4)
{

}

Rectangle::Rectangle(int x1,int y1,int x2, int y2):Polygon(updateConstructorPoints(Point(x1,y1),Point(x1,y2),Point(x2,y1),Point(x2,y2)),4)
{

}

double Rectangle::area()
{
    double len=puntos.get(0)->getX()-puntos.get(3)->getX();
    double ancho=puntos.get(1)->getY()-puntos.get(2)->getY();
    return len*ancho;
}
