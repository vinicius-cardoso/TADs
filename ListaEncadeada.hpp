#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <iostream>

using namespace std;

template <class T>
class ListaEncadeada;

template <class T>
class No {
   private:
    T dado;
    No<T> *prox;
    No<T> *ant;
    No();
    No(T item);

    friend class ListaEncadeada<T>;
};

template <class T>
No<T>::No() {
    prox = NULL;
    ant = NULL;
}

template <class T>
No<T>::No(T item) {
    dado = item;
    prox = NULL;
    ant = NULL;
}

template <class T>
class ListaEncadeada {
   private:
    No<T> *primeiro;
    No<T> *ultimo;
    int tamanho;

   public:
    ListaEncadeada();
    void InsereInicio(T item);
    void InsereFinal(T item);
    void InserePosicao(T item, int pos);
    No<T> RemoveInicio();
    No<T> RemoveFinal();
    No<T> RemovePosicao(int pos);
    No<T> Pesquisa(T item);
    void Imprime();
    bool IsVazia();
    bool IsCheia();
    No<T> GetItem(int pos);
    void SetItem(int pos);
    int GetTamanho();
};

template <class T>
ListaEncadeada<T>::ListaEncadeada() {
    primeiro = new No<T>;
    ultimo = new No<T>;
    primeiro->prox = ultimo;
    primeiro->ant = primeiro;
    ultimo->prox = ultimo;
    ultimo->ant = primeiro;
    tamanho = 0;
}

template <class T>
void ListaEncadeada<T>::InsereInicio(T item) {
    No<T> *nova = new No<T>(item);

    nova->dado = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;

    tamanho++;

    if (nova->prox == NULL)
        ultimo = nova;
}

// template <class T>
// void ListaEncadeada<T>::Imprime() {
//     No<T> *p = new No<T>();

//     while (p) {
//         cout << p->dado << ", ";
//         p = p->prox;
//     }

//     cout << endl;
// }

template <class T>
int ListaEncadeada<T>::GetTamanho() {
    return tamanho;
}

#endif