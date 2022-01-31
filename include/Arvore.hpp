#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;

class No{
    private:
        No *esq, *dir;
        int chave;

    public:
        No(int chave);
        int GetChave();
        No* GetEsq(){ 
            return esq;
        };
        No* GetDir(){
            return dir;
        };
        void SetEsq(No *no);
        void SetDir(No *no);
}; 

class Arvore{
    private:
        No *raiz;

    public:
        Arvore();
        void Inserir(int chave);
        void InserirAux(No *no, int chave);
        No* GetRaiz(){
            return raiz;
        };
        void EmOrdem(No *no);
};

#endif