#ifndef FILA_H
#define FILA_H

#include <iostream>

using namespace std;

template <typename T>
class Fila{
    private:
        T* fila;
        int max_tam;
        int inicio, final;

    public:
        Fila();
        ~Fila();
        void Adicionar(T elem);       
        void Remover(T &elem);
        T GetInicio();
        T GetFinal();
        T GetTamanho();
        void Imprimir();
        bool IsVazia();
        bool IsCheia();
};

template <class T>
Fila<T>::Fila(){
    fila = new T[100];
    max_tam = 99;
    inicio = 0;
    final = -1; // vazia, pois pos final (-1) < pos inicio (0)
}

template <class T>
Fila<T>::~Fila(){
    delete[] fila;
}

template <class T>
void Fila<T>::Adicionar(T elem){
    if(final == max_tam - 1)
        cout << "Fila cheia!" << endl;
    else
        fila[++final] = elem;
}   

template <class T>
void Fila<T>::Remover(T &elem){
    if(inicio > final)
        cout << "Fila vazia!" << endl;
    else
        elem = fila[inicio];
        inicio++;
}

template <class T>
T Fila<T>::GetInicio(){
    return fila[inicio];
}

template <class T>
T Fila<T>::GetFinal(){
    return fila[final];
}

template <class T>
T Fila<T>::GetTamanho(){
    return (final - inicio) + 1;
}

template <class T>
void Fila<T>::Imprimir(){
    for(int i = 0; i < final; i++)
        cout << fila[i] << " ";

    cout << endl;
}

template <class T>
bool Fila<T>::IsVazia(){
    if(inicio > final)
        return true;
    else
        return false;
}

template <class T>
bool Fila<T>::IsCheia(){
    if(final == max_tam - 1)
        return true;
    else
        return false;
}

#endif