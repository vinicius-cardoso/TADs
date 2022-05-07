#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;

template <typename T>
class Arvore{
    struct No{
        T chave;
        No *esq, *dir;

        No(T valor):chave(valor), esq(NULL), dir(NULL){} 
    };

    private:
        No *raiz;
        void InserirRecursivamente(No *no, T chave);
        void RemoverRecursivamente(No* no, T chave); 
        T PesquisarRecursivamente(No* no, T chave);
        void Antecessor(No *q, No *r);
        void PreOrdem(No *no);
        void EmOrdem(No *no);
        void PosOrdem(No *no);
        void ApagarRecursivamente(No *no);

    public:
        Arvore();
        ~Arvore();
        No* GetRaiz(){
            return raiz;
        };
        void Inserir(T item);
        T Pesquisar(T chave);
        void Caminhar(No *no);
        void Remover(T item);
        void Limpar();
};

template <class T>
Arvore<T>::Arvore(){
    raiz = NULL;
}

template <class T>
Arvore<T>::~Arvore(){
    delete raiz;
}

template <class T>
void Arvore<T>::Inserir(T item){
    // posicao nula onde o item deve estar
    if(raiz == NULL)
        raiz = new No(item);
    else
        InserirRecursivamente(raiz, item);
}

template <class T>
void Arvore<T>::InserirRecursivamente(No *no, T chave){
    if(chave < no->chave){
        if(no->esq == NULL){
            No *novo_no = new No(chave);
            no->esq = novo_no;
        }
        else{
            InserirRecursivamente(no->esq, chave);
        }
    }
    else if(chave > no->chave){
        if(no->dir == NULL){
            No *novo_no = new No(chave);
            no->dir = novo_no;
        }
        else{
            InserirRecursivamente(no->dir, chave);
        }
    }
}

template <class T>
void Arvore<T>::Remover(T item){
    return RemoverRecursivamente(raiz, raiz->chave);
}

template <class T>
void Arvore<T>::RemoverRecursivamente(No *no, T chave){
    No *aux;

    if(no == NULL){
        throw("Item nao esta presente");
    }

    if(chave < no->dir)
        return RemoverRecursivamente(no->esq, chave);
    else if(chave > no->dir)
        return RemoverRecursivamente(no->dir, chave);
    else{ // achou a chave
        // se o filho da direita eh nulo, o no eh o filho da esquerda
        if(no->dir == NULL){
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL){
            aux = no;
            no = no->dir;
            free(aux);
        }
        // no tem 2 filhos. substitui o no pelo seu antecessor
        else{
            Antecessor(no, no->esq);
        }
    }
}

template <class T>
T Arvore<T>::Pesquisar(T chave){
    return PesquisarRecursivamente(raiz, chave);
}

template <class T>
T Arvore<T>::PesquisarRecursivamente(No* no, T chave){
    T aux;

    // se o no nao esta na arvore
    if(no == NULL){
        aux = -1;

        return aux;
    }

    if(chave < no->dir)
        return PesquisarRecursivamente(no->esq, chave);
    else if(chave > no->dir)
        return PesquisarRecursivamente(no->dir, chave);
    else
        return no->dir;
}

// 'q' eh o que se quer tirar e o 'r' eh o candidato a substituir
template <class T>
void Arvore<T>::Antecessor(No *q, No *r){
    if(r->dir != NULL){
        Antecessor(q, r->dir);
        return;
    }

    q->chave = r->chave;
    q = r;
    r = r->esq;
    
    free(q);
}

template <class T>
void Arvore<T>::PreOrdem(No *no){
    if(no != NULL){
        cout << no->dir << " ";
        EmOrdem(no->esq);
        EmOrdem(no->dir);
    }
}

template <class T>
void Arvore<T>::EmOrdem(No *no){
    if(no != NULL){
        EmOrdem(no->esq);
        cout << no->dir << " ";
        EmOrdem(no->dir);
    }
}

template <class T>
void Arvore<T>::PosOrdem(No *no){
    if(no != NULL){
        PosOrdem(no->esq);
        PosOrdem(no->dir);
        cout << no->dir << " ";
    }
}

template <class T>
void Arvore<T>::Caminhar(No *no){
    PosOrdem(no);
}

template <class T>
void Arvore<T>::ApagarRecursivamente(No *no){
    if (no != NULL){
        ApagarRecursivamente(no->esq);
        ApagarRecursivamente(no->dir);
        
        delete no;
    }
}

template <class T>
void Arvore<T>::Limpar(){
    Apagar(raiz);

    raiz = NULL;
}

#endif