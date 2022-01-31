#ifndef FILA_H
#define FILA_H

#include <iostream>

using namespace std;

class Fila{
    private:
        int* fila;
        int max_tam;
        int inicio, final;

    public:
        Fila();
        ~Fila();
        void Adicionar(int elem);       
        void Remover(int &elem);
        int GetInicio();
        int GetFinal();
        int GetTamanho();
        void Imprimir();
        bool IsVazia();
        bool IsCheia();
};

#endif