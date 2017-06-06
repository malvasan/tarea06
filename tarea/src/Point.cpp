#include "Point.h"

Point::Point(int x,int y)
{
    this->x=x;
    this->y=y;
}

int Point::getX() const
{
    return x;
}
int Point::getY() const
{
    return y;
}
void Point::setX(const int new_x)
{
    x=new_x;
}
void Point::setY(const int new_y)
{
    y=new_y;
}
