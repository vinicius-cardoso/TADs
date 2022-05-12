#ifndef PILHA_H
#define PILHA_H

#include <iostream>

using namespace std;

template <class T>
class Pilha;

template <class T>
class No {
   private:
    T dado;
    No<T> *prox;
    No();
    No(T item);

    friend class Pilha<T>;
};

template <class T>
No<T>::No() {
    prox = NULL;
}

template <class T>
No<T>::No(T item) {
    dado = item;
    prox = NULL;
}

template <class T>
class Pilha {
   private:
    No<T> *topo;
    int tamanho;

   public:
    Pilha();
    No<T> Empilhar(T item);
    void Desempilhar();
    bool IsVazia();
    int GetTamanho();
};

template <class T>
Pilha<T>::Pilha() {
    topo = new No<T>;
    topo->prox = topo;
    tamanho = 0;
}

template <class T>
No<T> Pilha<T>::Empilhar(T item) {
    No<T> *aux = new No<T>(item);

    topo->prox = aux;
    aux->prox = topo->prox;
    topo->prox = aux;

    tamanho++;

    return *aux;
}

template <class T>
void Pilha<T>::Desempilhar() {
    if (topo != NULL) {
        No<T> *aux = topo;
        topo = topo->prox;

        delete aux;

        tamanho--;
    }
}

template <class T>
bool Pilha<T>::IsVazia() {
    return (tamanho == 0);
}

template <class T>
int Pilha<T>::GetTamanho() {
    return tamanho;
}

#endif