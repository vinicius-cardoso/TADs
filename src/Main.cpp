#include "Pilha.hpp"
#include "Fila.hpp"
#include "Lista.hpp"
#include "Arvore.hpp"

void Queue(){
    Fila f;

    int valor = 0;

    for(int i = 10; i < 20; i++)
        f.Adicionar(i);

    f.Remover(valor);

    f.Imprimir();

    cout << "Inicio: " << f.GetInicio() << endl;
    cout << "Final: " << f.GetFinal() << endl;

    cout << endl;
}

void Stack(){
    Pilha p;

    for(int i = 10; i < 20; i++)
        p.Empilhar(i);

    p.Desempilhar();

    p.Imprimir();
    
    cout << "Topo: " << p.GetTopo() << endl;

    cout << endl;
}
/* 
void List(){
    ListaArranjo l ;

    cout << "---------------------" << endl;
    cout << "Lista:" << endl;

    for(int i = 10; i < 20; i++)
        l.InserirFinal(i);

    l.RemoverPos(5);

    l.Imprimir();
    
    cout << "Tamanho: " << l.GetTamanho() << endl;

    cout << endl;
}
 */
void Tree(){
    Arvore a;

    a.Inserir(8);
    a.Inserir(10);
    a.Inserir(14);
    a.Inserir(13);
    a.Inserir(3);
    a.Inserir(1);
    a.Inserir(6);
    a.Inserir(4);
    a.Inserir(7);

    cout << "Percorrendo em ordem..." << endl;

    a.EmOrdem(a.GetRaiz());

    cout << endl << endl;
}

int main(){
    cout << "---------------------" << endl;
    cout << "Fila:" << endl;
    cout << "---------------------" << endl;
    Queue();
    
    cout << "---------------------" << endl;
    cout << "Pilha:" << endl;
    cout << "---------------------" << endl;
    Stack();

    cout << "---------------------" << endl;
    cout << "Lista:" << endl;
    cout << "---------------------" << endl;
    // List();
    
    cout << "---------------------" << endl;
    cout << "Arvore:" << endl;
    cout << "---------------------" << endl;
    Tree();
    cout << "---------------------" << endl;

    return 0;
}