#ifndef PILHA_H
#define PILHA_H

#include <iostream>

#define TAM 99

using namespace std;

template <typename T> 
class Pilha{
    private:
        T *pilha;
        T topo;

    public:
        Pilha();
        ~Pilha();
        void Empilhar(T elem);       
        void Desempilhar();
        T GetTopo();
        void Imprimir();
        bool IsVazia();
        bool IsCheia();
};

template <class T>
Pilha<T>::Pilha(){
    pilha = new T[100];
    topo = -1;
}

template <class T>
Pilha<T>::~Pilha(){
    delete[] pilha;
}

template <class T>
void Pilha<T>::Empilhar(T elem){
    if(IsCheia())
        cout << "Pilha cheia!" << endl;
    else
        pilha[++topo] = elem; // incrementa e depois utiliza o valor de topo
}

template <class T>
void Pilha<T>::Desempilhar(){
    if(IsVazia())
        cout << "Pilha vazia!" << endl;
    else
        topo--;
}

template <class T>
T Pilha<T>::GetTopo(){
    if(topo != -1)
        return pilha[topo];
    
    return -1;
}

template <class T>
void Pilha<T>::Imprimir(){
    for(int i = 0; i < topo; i++)
        cout << pilha[i] << " ";
    
    cout << endl;
}

template <class T>
bool Pilha<T>::IsVazia(){
    if(topo == -1)
        return true;
    else
        return false;
}

template <class T>
bool Pilha<T>::IsCheia(){
    if(topo == TAM)
        return true;
    else
        return false;
}

#endif