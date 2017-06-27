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

template<typename T> class Stack;

template<typename T>
Stack<T> operator+(const Stack<T> &pila1,const Stack<T> &pila2)
{
    Stack<T> nuevo=pila1;

    for(int i=0;i<pila2.pila.size();++i){
        nuevo.pila.push_back(pila2.pila[i]);
    }
    return nuevo;
}

template<typename T>
Stack<T> operator-(const Stack<T> &pila1,const Stack<T> &pila2)
{
    Stack<T> nuevo;
    for(int i=0;i<pila1.pila.size();++i){
        bool pasar=true;
        for(int o=0;o<pila2.pila.size();++o){
            if(pila1.pila[i]==pila2.pila[o]){
                pasar=false;
                break;
            }
        }
        if(pasar==true)
            nuevo.push(pila1.pila[i]);
    }
    return nuevo;
}

template<typename T>
ostream& operator<<(ostream &output,const Stack<T> &pila1)
{
    for(int i=0;i<pila1.pila.size();++i)
        output<<pila1.pila[i];
    return output;
}

template<typename T>
class Stack{
    friend Stack<T> operator+<>(const Stack<T> &pila1,const Stack<T> &pila2);
    friend Stack<T> operator-<>(const Stack<T> &pila1,const Stack<T> &pila2);
    friend ostream& operator<<<>(ostream &output,const Stack<T> &pila1);
    vector<T> pila;
public:
    bool vacio()
    {
        return pila.empty();
    }
    void push(const T &item)
    {
        std::vector<int>::iterator it;
        it=pila.begin();
        pila.insert(it,item);
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


int main()
{
    Stack<int> a,b;
    a.push(1);
    a.push(2);
    a.push(3);
    b.push(4);
    b.push(5);
    b.push(6);
    Stack<int> c=a-b;
    cout<<c<<endl;


}
