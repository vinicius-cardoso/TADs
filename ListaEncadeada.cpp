#include "ListaEncadeada.hpp"

#include <string>

typedef struct Aluno {
    string nome;
    int idade;
} Aluno;

int main() {
    ListaEncadeada<Aluno> alunos;

    Aluno aluno1;
    aluno1.nome = "Alceu";
    aluno1.idade = 15;

    Aluno aluno2;
    aluno1.nome = "Bernardo";
    aluno1.idade = 16;

    Aluno aluno3;
    aluno1.nome = "Caio";
    aluno1.idade = 17;

    alunos.InsereInicio(aluno1);
    alunos.InsereInicio(aluno2);
    alunos.InsereInicio(aluno3);

    // alunos.Imprime();

    cout << "Quantidade de alunos: " << alunos.GetTamanho() << endl;
}