#include "Lista.hpp"

int main() {
    Lista<int> *l;

    l->InsereFinal(1);
    l->InsereFinal(2);
    l->InsereFinal(3);
    l->InsereFinal(4);
    l->InsereFinal(5);

    l->Imprime();

    return 0;
}