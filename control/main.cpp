#include <iostream>
#include <vector>

using namespace std;

template<typename T> class Matriz;

template<typename T>
Matriz<T> operator*(Matriz<T> &matriz1,Matriz<T> &matriz2)
{
    Matriz<T> matriz3(matriz1.fila,matriz2.columna);
    if(matriz1.columna==matriz2.fila){
        for(int i=0;i<matriz3.fila;++i){
            for(int o=0;o<matriz3.columna;++o)
                matriz3.matriz[i][o]=0;
        }

        for(int i=0;i<matriz1.fila;++i){
            for(int o=0;o<matriz1.columna;++o){
                for(int p=0;p<matriz2.columna;++p){
                    matriz3.matriz[i][o]+=(matriz1.matriz[i][p]*matriz2.matriz[p][o]);
                }
            }
        }
    }
    return matriz3;
}

template<typename T>
ostream& operator <<(ostream& output,const Matriz<T> &matriz1)
{
    for(int i=0;i<matriz1.fila;++i){
        for(int o=0;o<matriz1.columna;++o){
            output<<matriz1.matriz[i][o];
        }
        output<<endl;
    }
    return output;
}

template<typename T>
class Matriz{
private:
    friend Matriz<T> operator*<>(Matriz<T> &matriz1,Matriz<T> &matriz2);
    friend ostream& operator<< <>(ostream &output,const Matriz<T> &matriz1);
public:
    T **matriz;
    int fila;
    int columna;
    Matriz(int fila,int columna)
    {
        this->fila=fila;
        this->columna=columna;
        matriz=new T*[this->fila];
        for(int i=0;i<this->fila;++i)
            matriz[i]=new T[this->columna];
    }

};
int main()
{
    Matriz<int> mat1(2,2);
    Matriz<int> mat2(2,2);
    mat1.matriz[0][0]=0;
    mat1.matriz[0][1]=1;
    mat1.matriz[1][0]=2;
    mat1.matriz[1][1]=3;
    mat2.matriz[0][0]=0;
    mat2.matriz[0][1]=1;
    mat2.matriz[1][0]=2;
    mat2.matriz[1][1]=3;
    cout<<mat1<<endl;
    cout<<mat2<<endl;
    Matriz<int> mat3(mat1.fila,mat2.columna);
    mat3=mat1*mat2;
    cout<<mat3<<endl;
    return 0;
}
