/* #ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

class Lista{
    protected:
        int tamanho;
    
    public:
        Lista();
        int GetTamanho();
        bool IsVazia();
        virtual TipoItem GetItem(int pos) = 0;
        virtual void SetItem(TipoItem item, int pos) = 0;
        virtual void InserirInicio(TipoItem item) = 0;
        virtual void InserirFinal(TipoItem item) = 0;
        virtual void InserirPos(TipoItem item, int pos) = 0;
        virtual TipoItem RemoverInicio() = 0;
        virtual TipoItem RemoverFinal() = 0;
        virtual TipoItem RemoverPos(int pos) = 0;
        virtual TipoItem Pequisar(TipoChave c) = 0;
        virtual void Imprimir() = 0;
        virtual void Limpa() = 0;
};

class ListaEncadeada : public Lista{
    private:
        TipoCelula* primeiro;
        TipoCelula* ultimo;
        TipoCelula* Posiciona(int pos, bool antes);
    
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InserirInicio(TipoItem item);
        void InserirFinal(TipoItem item);
        void InserirPos(TipoItem item, int pos);
        TipoItem RemoverInicio();
        TipoItem RemoverFinal();
        TipoItem RemoverPosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
};

class ListaArranjo : public Lista{
    private:
        static const int MAX_TAM = 100;
        TipoItem itens[MAX_TAM];

    public:
        ListaArranjo() : Lista(){};
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InserirInicio(TipoItem item);
        void InserirFinal(TipoItem item);
        void InserirPos(TipoItem item, int pos);
        TipoItem RemoverInicio();
        TipoItem RemoverFinal();
        TipoItem RemoverPos(int pos);
        TipoItem Pequisar(TipoChave c);
        void Imprimir();
        void Limpa();
};

typedef int TipoChave;

class TipoItem{
    private:
        TipoChave chave;

    public:
        TipoItem();
        TipoItem(TipoChave c);
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprimir();
};

class TipoCelula{
    friend class ListaEncadeada;
    
    private:
        TipoItem item;
        TipoCelula *prox;
    
    public:
        TipoCelula();
};

#endif */