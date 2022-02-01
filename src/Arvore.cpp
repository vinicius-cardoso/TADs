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

Arvore::~Arvore(){
    delete raiz;
}

void Arvore::Inserir(int item){
    // posicao nula onde o item deve estar
    if(raiz == NULL)
        raiz = new No(item);
    else
        InserirRecursivamente(raiz, item);
}

void Arvore::InserirRecursivamente(No *no, int chave){
    if(chave < no->GetChave()){
        if(no->GetEsq() == NULL){
            No *novo_no = new No(chave);
            no->SetEsq(novo_no);
        }
        else{
            InserirRecursivamente(no->GetEsq(), chave);
        }
    }
    else if(chave > no->GetChave()){
        if(no->GetDir() == NULL){
            No *novo_no = new No(chave);
            no->SetDir(novo_no);
        }
        else{
            InserirRecursivamente(no->GetDir(), chave);
        }
    }
}

void Arvore::Remover(int chave){
    return RemoverRecursivamente(raiz, chave);
}

void Arvore::RemoverRecursivamente(No *no, int chave){
    No *aux;

    if(no == NULL){
        throw("Item nao esta presente");
    }

    if(chave < no->GetChave())
        return RemoverRecursivamente(no->GetEsq(), chave);
    else if(chave > no->GetChave())
        return RemoverRecursivamente(no->GetDir(), chave);
    else{ // achou a chave
        // se o filho da direita eh nulo, o no eh o filho da esquerda
        if(no->dir == NULL){
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL){
            aux = no;
            no = no->dir;
            free(aux);
        }
        // no tem 2 filhos. substitui o no pelo seu antecessor
        else{
            Antecessor(no, no->esq);
        }
    }
}

int Arvore::Pesquisar(int chave){
    return PesquisarRecursivamente(raiz, chave);
}

int Arvore::PesquisarRecursivamente(No* no, int chave){
    int aux;

    // se o no nao esta na arvore
    if(no == NULL){
        aux = -1;

        return aux;
    }

    if(chave < no->GetChave())
        return PesquisarRecursivamente(no->GetEsq(), chave);
    else if(chave > no->GetChave())
        return PesquisarRecursivamente(no->GetDir(), chave);
    else
        return no->GetChave();
}

// 'q' eh o que se quer tirar e o 'r' eh o candidato a substituir
void Arvore::Antecessor(No *q, No *r){
    if(r->dir != NULL){
        Antecessor(q, r->dir);
        return;
    }

    q->chave = r->chave;
    q = r;
    r = r->esq;
    
    free(q);
}

void Arvore::PreOrdem(No *no){
    if(no != NULL){
        cout << no->GetChave() << " ";
        EmOrdem(no->GetEsq());
        EmOrdem(no->GetDir());
    }
}

void Arvore::EmOrdem(No *no){
    if(no != NULL){
        EmOrdem(no->GetEsq());
        cout << no->GetChave() << " ";
        EmOrdem(no->GetDir());
    }
}

void Arvore::PosOrdem(No *no){
    if(no != NULL){
        PosOrdem(no->esq);
        PosOrdem(no->dir);
        cout << no->GetChave() << " ";
    }
}

void Arvore::ApagarRecursivamente(No *no){
    if (no != NULL){
        ApagarRecursivamente(no->esq);
        ApagarRecursivamente(no->dir);
        
        delete no;
    }
}

void Arvore::Limpar(){
    ApagarRecursivamente(raiz);

    raiz = NULL;
}

