#include "Arvore.hpp"

No::No(int chave){
    this->chave = chave;

    esq = NULL;
    dir = NULL;
}

int No::GetChave(){
    return chave;
}

void No::SetEsq(No *no){
    esq = no;
}

void No::SetDir(No *no){
    dir = no;
}

Arvore::Arvore(){
    raiz = NULL;
}

void Arvore::Inserir(int chave){
    if(raiz == NULL)
        raiz = new No(chave);
    else
        InserirAux(raiz, chave);
}

void Arvore::InserirAux(No *no, int chave){
    if(chave < no->GetChave()){
        if(no->GetEsq() == NULL){
            No *novo_no = new No(chave);
            no->SetEsq(novo_no);
        }
        else{
            InserirAux(no->GetEsq(), chave);
        }
    }
    else if(chave > no->GetChave()){
        if(no->GetDir() == NULL){
            No *novo_no = new No(chave);
            no->SetDir(novo_no);
        }
        else{
            InserirAux(no->GetDir(), chave);
        }
    }
}

void Arvore::EmOrdem(No *no){
    if(no != NULL){
        EmOrdem(no->GetEsq());
        
        cout << no->GetChave() << " ";

        EmOrdem(no->GetDir());
    }
}