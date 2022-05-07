#include "Pilha.hpp"
#include "Fila.hpp"
// #include "Lista.hpp"
#include "Arvore.hpp"

void Queue(){
    Fila<int> f;

    int valor = 0;

    for(int i = 10; i < 20; i++)
        f.Adicionar(i);

    f.Remover(valor);

    f.Imprimir();

    cout << "Inicio: " << f.GetInicio() << endl;
    cout << "Final: " << f.GetFinal() << endl;

    cout << endl;

    Fila<char> f_char;

    char a = 'a';
    char b = 'b';
    char c = 'c';

    f_char.Remover(b);

    f_char.Imprimir();

    cout << "Inicio: " << f_char.GetInicio() << endl;
    cout << "Final: " << f_char.GetFinal() << endl;

    cout << endl;
}

void Stack(){
    Pilha<int> p_int;

    for(int i = 10; i < 20; i++)
        p_int.Empilhar(i);

    p_int.Desempilhar();

    p_int.Imprimir();
    
    cout << "Topo: " << p_int.GetTopo() << endl;

    cout << endl;
}

// void List(){
//     Lista<int> l;

//     for(int i = 10; i < 20; i++)
//         l.InsereFinal(i);

//     l.RemovePosicao(5);

//     l.Imprime();
    
//     cout << "Tamanho: " << l.GetTamanho() << endl;

//     cout << endl;
// }

void Tree(){
    Arvore<int> a;

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

    a.Caminhar(a.GetRaiz());

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