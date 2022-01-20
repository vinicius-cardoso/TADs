#ifndef PILHA_H
#define PILHA_H

#include <iostream>

using namespace std;

class Pilha{
    private:
        int* pilha;
        int max_tam;
        int topo;

    public:
        Pilha();
        ~Pilha();
        void Empilhar(int elem);       
        void Desempilhar();
        int GetTopo();
        void GetPilha();
        bool IsVazia();
        bool IsCheia();
};

#endif