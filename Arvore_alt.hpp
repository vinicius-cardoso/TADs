#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;

template <typename T>
class No{
    private:
        No *esq, *dir;
        T chave;

    public:
        No(T chave);
        void SetChave(T chave); //
        T GetChave();
        No* GetEsq(){ 
            return esq;
        };
        No* GetDir(){
            return dir;
        };
        void SetEsq(No *no);
        void SetDir(No *no);

    friend class Arvore;
}; 

template <typename T>
class Arvore{
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

No<T>::No(T chave){
    this->chave = chave;

    esq = NULL;
    dir = NULL;
}

T No<T>::GetChave(){
    return chave;
}

void No<T>::SetEsq(No *no){
    esq = no;
}

void No<T>::SetDir(No *no){
    dir = no;
}

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
    if(chave < no->GetChave()){
        if(no->GetEsq() == NULL){
            No *novo_no = new No(chave);
            no->SetEsq(novo_no);
        }
        else{
            InserirRecursivamente(no->GetEsq(), chave);
        }
    }
    else if(chave > no->GetChave()){
        if(no->GetDir() == NULL){
            No *novo_no = new No(chave);
            no->SetDir(novo_no);
        }
        else{
            InserirRecursivamente(no->GetDir(), chave);
        }
    }
}

template <class T>
void Arvore<T>::Remover(T item){
    return RemoverRecursivamente(raiz, chave);
}

template <class T>
void Arvore<T>::RemoverRecursivamente(No *no, T chave){
    No *aux;

    if(no == NULL){
        throw("Item nao esta presente");
    }

    if(chave < no->GetChave())
        return RemoverRecursivamente(no->GetEsq(), chave);
    else if(chave > no->GetChave())
        return RemoverRecursivamente(no->GetDir(), chave);
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

    if(chave < no->GetChave())
        return PesquisarRecursivamente(no->GetEsq(), chave);
    else if(chave > no->GetChave())
        return PesquisarRecursivamente(no->GetDir(), chave);
    else
        return no->GetChave();
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
        cout << no->GetChave() << " ";
        EmOrdem(no->GetEsq());
        EmOrdem(no->GetDir());
    }
}

template <class T>
void Arvore<T>::EmOrdem(No *no){
    if(no != NULL){
        EmOrdem(no->GetEsq());
        cout << no->GetChave() << " ";
        EmOrdem(no->GetDir());
    }
}

template <class T>
void Arvore<T>::PosOrdem(No *no){
    if(no != NULL){
        PosOrdem(no->esq);
        PosOrdem(no->dir);
        cout << no->GetChave() << " ";
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
    ApagarRecursivamente(raiz);

    raiz = NULL;
}

#endif