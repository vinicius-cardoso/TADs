#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

template <typename T>
class Lista{
    private:
        int tamanho = ;
        T *primeiro;
        T *ultimo;
        T *Posiciona(int pos, bool antes);

    public:
        Lista();
        ~Lista();
        T GetItem(int pos);
        int GetTamanho(){ return tamanho; }
        void SetItem(T item, int pos);
        void InsereInicio(T item);
        void InsereFinal(T item);
        void InserePosicao(T item, int pos);
        T RemoveInicio();
        T RemoveFinal();
        T RemovePosicao(int pos);
        T Pesquisa(T c);
        void Imprime();
        void Limpa();
};

template <class T>
Lista<T>::Lista() : Lista(){
    primeiro = new T();
    ultimo = primeiro;
}

template <class T>
Lista<T>::~Lista(){
    Limpa();
    delete primeiro;
}

template <class T>
T *Lista<T>::Posiciona(int pos, bool antes = false){
    T *p;
    int i;
    
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    
    // Posiciona na célula anterior a desejada
    p = primeiro;

    for (i = 1; i < pos; i++){
        p = p->prox;
    }
    
    // vai para a próxima
    // se antes for false
    if (!antes)
        p = p->prox;
    
    return p;
}

template <class T>
T Lista<T>::GetItem(int pos){
    T *p;
    p = Posiciona(pos);

    return p->item;
}

template <class T>
void Lista<T>::SetItem(T item, int pos){
    T *p;
    
    p = Posiciona(pos);
    p->item = item;
}

template <class T>
void Lista<T>::InsereInicio(T item){
    T *nova;
    nova = new T();
    
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    
    tamanho++;

    if (nova->prox == NULL)
        ultimo = nova;
}

template <class T>
void Lista<T>::InsereFinal(T item){
    T *nova;
    nova = new T();
    
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    
    tamanho++;
}

template <class T>
void Lista<T>::InserePosicao(T item, int pos){
    T *p, *nova;
    p = Posiciona(pos, true); // posiciona na célula anterior
    
    nova = new T();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    
    tamanho++;
    
    if (nova->prox == NULL)
        ultimo = nova;
}

template <class T>
T Lista<T>::RemoveInicio(){
    T aux;
    T *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    p = primeiro->prox;
    primeiro->prox = p->prox;
    
    tamanho--;
    
    if (primeiro->prox == NULL)
        ultimo = primeiro;
    
    aux = p->item;
    
    delete p;
    
    return aux;
}

template <class T>
T Lista<T>::RemoveFinal(){
    T aux;
    T *p;
    
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);
    p->prox = NULL;
    
    tamanho--;

    aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    
    return aux;
}

template <class T>
T Lista<T>::RemovePosicao(int pos){
    T aux;
    T *p, *q;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    
    tamanho--;
    
    aux = q->item;
    
    delete q;
    
    if (p->prox == NULL)
        ultimo = p;
    
    return aux;
}

template <class T>
T Lista<T>::Pesquisa(T c){
    T aux;
    T *p;
    
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    p = primeiro->prox;
    
    aux.SetChave(-1);

    while (p != NULL){
        if (p->item.GetChave() == c){
            aux = p->item;
            break;
        }

        p = p->prox;
    }

    return aux;
}

template <class T>
void Lista<T>::Imprime(){
    T *p;
    p = primeiro->prox;

    while (p != NULL){
        p->item.Imprime();
        p = p->prox;
    }

    cout << endl;
}

template <class T>
void Lista<T>::Limpa(){
    T *p;
    p = primeiro->prox;

    while (p != NULL){
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    
    ultimo = primeiro;
    tamanho = 0;
};

#endif