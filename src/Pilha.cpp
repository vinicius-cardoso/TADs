#include "Pilha.hpp"

Pilha::Pilha(){
    pilha = new int[100];
    max_tam = 99;
    topo = -1;
}

Pilha::~Pilha(){
    delete[] pilha;
}

void Pilha::Empilhar(int elem){
    if (topo == max_tam)
        cout << "Pilha cheia!" << endl;
    else
        pilha[++topo] = elem; // incrementa e depois utilizar o valor de topo
}

void Pilha::Desempilhar(){
    if (topo == -1)
        cout << "Pilha vazia!" << endl;
    else
        topo--;
}

int Pilha::GetTopo(){
    if(topo != -1)
        return pilha[topo];
    
    return -1;
}

void Pilha::GetPilha(){
    for(int i = 0; i < topo; i++)
        cout << pilha[i] << " ";
    
    cout << endl;
}

bool Pilha::IsVazia(){
    if(topo == -1)
        return true;
    else
        return false;
}

bool Pilha::IsCheia(){
    if(topo == max_tam)
        return true;
    else
        return false;
}