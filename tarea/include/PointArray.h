#ifndef POINTARRAY_H
#define POINTARRAY_H
#include "Point.h"

class PointArray
{
    private:
        Point *puntero;
        int _size;

        void _resize(int n);

    public:
        PointArray();
        PointArray(const Point arr[],const int _size);
        PointArray(const PointArray &pv);
        ~PointArray();
        void push_bac(const Point &p);
        void insertar(const int position, const Point &p);
        void remover(const int pos);
        const int getSize() const;
        void cleare();
        Point* get(const int position);
        const Point *get(const int position) const;

};

#endif // POINTARRAY_H
