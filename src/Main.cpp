// #include "Vetor.hpp"
#include "Pilha.hpp"
#include "Fila.hpp"
// #include "Lista.hpp"
// #include "ListaEncadeada.hpp"
// #include "Arvore.hpp"

// void Vector(){}

void Queue(){
    Fila f;

    int valor = 0;

    cout << "---------------------" << endl;
    cout << "Fila:" << endl;

    for(int i = 10; i < 20; i++)
        f.Adicionar(i);

    f.Remover(valor);

    f.GetFila();

    cout << "Inicio: " << f.GetInicio() << endl;
    cout << "Final: " << f.GetFinal() << endl;

    cout << endl;
}

void Stack(){
    Pilha p;

    cout << "---------------------" << endl;
    cout << "Pilha:" << endl;

    for(int i = 10; i < 20; i++)
        p.Empilhar(i);

    p.Desempilhar();

    p.GetPilha();
    
    cout << "Topo: " << p.GetTopo() << endl;

    cout << endl;
}
/*
void List(){

}

void ChainedList(){

}

void Tree(){

}
*/
int main(){
    // Vector();
    Queue();
    Stack();
    // List();
    // ChainedList();
    // Tree();
    
    return 0;
}