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
        void SetChave(int chave); //
        int GetChave();
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

class Arvore{
    private:
        No *raiz;
        void InserirRecursivamente(No *no, int chave);
        void RemoverRecursivamente(No* no, int chave); 
        int PesquisarRecursivamente(No* no, int chave);
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
        void Inserir(int chave);
        int Pesquisar(int chave);
        void Remover(int chave);
        void Limpar();
};

#endif