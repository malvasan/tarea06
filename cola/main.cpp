#include <iostream>
#include <vector>

using namespace std;

template<typename T> class Cola;

template<typename T>
Cola<T> operator+(const Cola<T> &t1,const Cola<T> &t2)
{
    Cola<T> nuevo=t1;
    for(int i=0;i<t2.cola.size();++i)
        nuevo.push(t2.cola[i]);
    return nuevo;
}

template<typename T>
Cola<T> operator-(const Cola<T> &t1,const Cola<T> &t2)
{
    Cola<T> nuevo;
    for(int i=0;i<t1.cola.size();++i){
        bool pasable=true;
        for(int o=0;o<t1.cola.size();++o){
            if(t1.cola[i]==t2.cola[o]){
                pasable=false;
                break;
            }
        }
        if(pasable==true)
            nuevo.push(t1.cola[i]);
    }
    return nuevo;
}

template<typename T>
ostream& operator<<(ostream &output,const Cola<T> &t1)
{
    for(int i=0;i<t1.cola.size();++i)
        output<<t1.cola[i];
    return output;
}

template<typename T>
class Cola{
private:
    friend Cola<T> operator+ <>(const Cola<T> &t1,const Cola<T> &t2);
    friend Cola<T> operator- <>(const Cola<T> &t1,const Cola<T> &t2);
    friend ostream& operator<<<>(ostream &output,const Cola<T> &t1);
    vector<T> cola;
public:
    void push(const T &item)
    {

        cola.push_back(item);
    }
    void pop()
    {
        cola.pop_back();
    }
};

int main()
{
    Cola <int> a,b;
    a.push(1);
    a.push(2);
    b.push(3);
    b.push(4);
    Cola <int> c= a+b;
    cout << c << endl;
    return 0;
}
