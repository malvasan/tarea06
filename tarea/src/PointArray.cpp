#include "PointArray.h"

PointArray::PointArray()
{
    this->_size=0;
    puntero= new Point[0];
}

PointArray::PointArray(const Point arr[],const int _size)
{
    this->_size=_size;
    puntero=new Point[_size];
    for(int i=0;i<_size;++i)
        puntero[i]=arr[i];
}

PointArray::PointArray(const PointArray &v)
{
    this->_size=v._size;
    puntero=new Point[_size];
    for(int i=0;i<_size;++i)
        puntero[i]=v.puntero[i];
}
PointArray::~PointArray()
{
    delete[] puntero;
}
void PointArray::_resize(int n)
{
    Point* pts=new Point[n];
    int mini=0;
    if(n>this->_size)
        mini=this->_size;
    else
        mini=n;

    for(int i=0;i<mini;++i)
        pts[i]=puntero[i];

    delete[] puntero;
    this->_size=n;
    puntero=pts;
}


void PointArray::push_bac(const Point &p)
{
    _resize(_size+1);
    puntero[_size-1]=p;
}


void PointArray::insertar(const int position, const Point &p)
{
    _resize(_size+1);
    Point nuevo=p;
    Point viejo;
    for(int i=position;i<_size;++i){
        viejo=puntero[i];
        puntero[i]=nuevo;
        nuevo=viejo;

    }
}

void PointArray::remover(const int pos)
{
    for(int i=pos;i<_size;i++){
        puntero[i]=puntero[i+1];
    }
    _resize(_size-1);
}

const int PointArray::getSize() const
{
    return this->_size;
}

void PointArray::cleare()
{
    _resize(0);
}

Point *PointArray::get(const int position)
{
    return &puntero[position];
}

const Point *PointArray::get(const int position) const
{
    return &puntero[position];
}

