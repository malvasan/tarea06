#include <iostream>
#include <vector>

using namespace std;
/*
template<typename T >
T mini(T a,T b)
{
    if(a<b)
        return a;
    else
        return b;
}

template<typename T >
T mini(T a,T b)
{
    return a<b?a:b;
}
*/

template<typename T>
class Stack{
    friend Stack<T> operator+<>(Stack<T> &pila1,Stack<T> &pila2);
    vector<T> pila;
public:
    bool vacio()
    {
        return pila.empty();
    }
    void push(const T &item)
    {
        pila.push_back(item);
    }
    T top()
    {
        T ultimo=pila.back();
        pila.pop_back();
        return ultimo;
    }
    void pop()
    {
        pila.pop_back();
    }
};
template<typename T>
Stack<T> operator+(Stack<T> &pila1,Stack<T> &pila2)
{
    Stack<T> nuevo=pila1;

    for(int i=0;i<pila2.pila.size();++i){
        nuevo.pila.push_back(pila2.pila[i]);
    }
    return nuevo;
}

int main()
{
    return 0;
}
