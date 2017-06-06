#ifndef POLYGON_H
#define POLYGON_H
#include "PointArray.h"

class Polygon
{
    protected:
        static int numb;
        PointArray puntos;
    public:
        Polygon(const Point arr[],const int lenght);
        Polygon(PointArray &p);
        virtual double area()=0;
        int getNumPolygons(){return numb;}
        int getNumSides(){return puntos.getSize();}
        const PointArray *getPoints(){return &puntos;}
};

#endif // POLYGON_H
