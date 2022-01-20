#include "Fila.hpp"

Fila::Fila(){
    fila = new int[100];
    max_tam = 99;
    inicio = 0;
    final = -1; // vazia, pois pos final (-1) < pos inicio (0)
}

Fila::~Fila(){
    delete[] fila;
}

void Fila::Adicionar(int elem){
    if(final == max_tam - 1)
        cout << "Fila cheia!" << endl;
    else
        fila[++final] = elem;
}   

void Fila::Remover(int &elem){
    if(inicio > final)
        cout << "Fila vazia!" << endl;
    else
        elem = fila[inicio];
        inicio++;
}

int Fila::GetInicio(){
    return fila[inicio];
}

int Fila::GetFinal(){
    return fila[final];
}

int Fila::GetTamanho(){
    return (final - inicio) + 1;
}

void Fila::GetFila(){
    for(int i = 0; i < final; i++)
        cout << fila[i] << " ";

    cout << endl;
}

bool Fila::IsVazia(){
    if(inicio > final)
        return true;
    else
        return false;
}

bool Fila::IsCheia(){
    if(final == max_tam - 1)
        return true;
    else
        return false;
}
