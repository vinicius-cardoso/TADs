#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

typedef int TipoChave; // TipoChave é um inteiro

class TipoItem{    
    public:
        TipoItem();
        TipoItem(TipoChave c);
        bool Vazio(){ return tamanho == 0; };
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();

    private:
        TipoChave chave;
        int tamanho;
};

class TipoCelula{
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;

    friend class ListaEncadeada;
};

class Lista{
    protected:
        int tamanho;

    public:
        Lista() { tamanho = 0; };
        int GetTamanho() { return tamanho; };
        bool Vazia() { return tamanho == 0; };
        virtual TipoItem GetItem(int pos) = 0;
        virtual void SetItem(TipoItem item, int pos) = 0;
        virtual void InsereInicio(TipoItem item) = 0;
        virtual void InsereFinal(TipoItem item) = 0;
        virtual void InserePosicao(TipoItem item, int pos) = 0;
        virtual TipoItem RemoveInicio() = 0;
        virtual TipoItem RemoveFinal() = 0;
        virtual TipoItem RemovePosicao(int pos) = 0;
        virtual TipoItem Pesquisa(TipoChave c) = 0;
        virtual void Imprime() = 0;
        virtual void Limpa() = 0;
};

class ListaEncadeada : public Lista{
    private:
        TipoCelula *primeiro;
        TipoCelula *ultimo;
        TipoCelula *Posiciona(int pos, bool antes);
    
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
};

class ListaArranjo : public Lista{
    private:
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];
    
    public:
        ListaArranjo() : Lista(){};
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
};

#endif