#include "Pilha.hpp"

#include <string>

typedef struct Aluno {
    string nome;
    int idade;
} Aluno;

int main() {
    Pilha<Aluno> alunos;

    Aluno aluno1;
    aluno1.nome = "Alceu";
    aluno1.idade = 15;

    Aluno aluno2;
    aluno1.nome = "Bernardo";
    aluno1.idade = 16;

    Aluno aluno3;
    aluno1.nome = "Caio";
    aluno1.idade = 17;

    alunos.Empilhar(aluno1);
    alunos.Empilhar(aluno2);
    alunos.Empilhar(aluno3);

    cout << "Quantidade de alunos: " << alunos.GetTamanho() << endl;
}

// int main() {
//     Pilha<char> p;

//     string entrada;

//     cin >> entrada;

//     for (int i = 0; i < entrada.size(); i++) {
//         if (entrada[i] == '(') {
//             p.Empilhar(entrada[i]);
//         } else if (entrada[i] == ')') {
//             if (p.IsVazia()) {
//                 continue;
//             } else {
//                 p.Desempilhar();
//             }
//         } else {
//             throw "Erro";
//         }
//     }

//     if (p.IsVazia()) {
//         cout << "Partiu RU!" << endl;
//     } else {
//         cout << "Ainda temos " << p.GetTamanho() << " assunto(s) pendente(s)!" << endl;
//     }

//     return 0;
// }
