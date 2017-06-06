#include "Polygon.h"
int Polygon::numb=0;

Polygon::Polygon(const Point arr[],const int lenght):puntos(arr,lenght)
{
    ++numb;
}

Polygon::Polygon(const PointArray &p):puntos(p)
{
    ++numb;
}
