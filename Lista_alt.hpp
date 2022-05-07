#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

typedef int TipoChave; // TipoChave é um inteiro

class TipoItem{    
    public:
        TipoItem();
        TipoItem(TipoChave c);
        bool Vazio(){ return tamanho == 0; };
        void SetChave(TipoChave c);
        TipoChave GetChave();
        void Imprime();

    private:
        TipoChave chave;
        int tamanho;
};

class TipoCelula{
    public:
        TipoCelula();

    private:
        TipoItem item;
        TipoCelula *prox;

    friend class ListaEncadeada;
};


class Lista{
    protected:
        int tamanho;

    public:
        Lista() { tamanho = 0; };
        int GetTamanho() { return tamanho; };
        bool Vazia() { return tamanho == 0; };
        virtual TipoItem GetItem(int pos) = 0;
        virtual void SetItem(TipoItem item, int pos) = 0;
        virtual void InsereInicio(TipoItem item) = 0;
        virtual void InsereFinal(TipoItem item) = 0;
        virtual void InserePosicao(TipoItem item, int pos) = 0;
        virtual TipoItem RemoveInicio() = 0;
        virtual TipoItem RemoveFinal() = 0;
        virtual TipoItem RemovePosicao(int pos) = 0;
        virtual TipoItem Pesquisa(TipoChave c) = 0;
        virtual void Imprime() = 0;
        virtual void Limpa() = 0;
};

class ListaEncadeada : public Lista{
    private:
        TipoCelula *primeiro;
        TipoCelula *ultimo;
        TipoCelula *Posiciona(int pos, bool antes);
    
    public:
        ListaEncadeada();
        ~ListaEncadeada();
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
};

class ListaArranjo : public Lista{
    private:
        static const int MAXTAM = 100;
        TipoItem itens[MAXTAM];
    
    public:
        ListaArranjo() : Lista(){};
        TipoItem GetItem(int pos);
        void SetItem(TipoItem item, int pos);
        void InsereInicio(TipoItem item);
        void InsereFinal(TipoItem item);
        void InserePosicao(TipoItem item, int pos);
        TipoItem RemoveInicio();
        TipoItem RemoveFinal();
        TipoItem RemovePosicao(int pos);
        TipoItem Pesquisa(TipoChave c);
        void Imprime();
        void Limpa();
};

TipoCelula::TipoCelula(){
    item.SetChave(-1);
    prox = NULL;
}

TipoItem::TipoItem(){
    chave = -1; // indica um item vazio
}
TipoItem::TipoItem(TipoChave c){
    chave = c;
}
void TipoItem::SetChave(TipoChave c)
{
    chave = c;
}
TipoChave TipoItem::GetChave(){
    return chave;
}

void TipoItem::Imprime(){
    printf("%d ", chave);
}

ListaEncadeada::ListaEncadeada() : Lista(){
    primeiro = new TipoCelula();
    ultimo = primeiro;
}

ListaEncadeada::~ListaEncadeada(){
    Limpa();
    delete primeiro;
}

TipoCelula *ListaEncadeada::Posiciona(int pos, bool antes = false){
    TipoCelula *p;
    int i;
    
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    
    // Posiciona na célula anterior a desejada
    p = primeiro;

    for (i = 1; i < pos; i++){
        p = p->prox;
    }
    
    // vai para a próxima
    // se antes for false
    if (!antes)
        p = p->prox;
    
    return p;
}

TipoItem ListaEncadeada::GetItem(int pos){
    TipoCelula *p;
    p = Posiciona(pos);

    return p->item;
}

void ListaEncadeada::SetItem(TipoItem item, int pos){
    TipoCelula *p;
    
    p = Posiciona(pos);
    p->item = item;
}

void ListaEncadeada::InsereInicio(TipoItem item){
    TipoCelula *nova;
    nova = new TipoCelula();
    
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    
    tamanho++;

    if (nova->prox == NULL)
        ultimo = nova;
}

void ListaEncadeada::InsereFinal(TipoItem item){
    TipoCelula *nova;
    nova = new TipoCelula();
    
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    
    tamanho++;
}

void ListaEncadeada::InserePosicao(TipoItem item, int pos){
    TipoCelula *p, *nova;
    p = Posiciona(pos, true); // posiciona na célula anterior
    
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    
    tamanho++;
    
    if (nova->prox == NULL)
        ultimo = nova;
}

TipoItem ListaEncadeada::RemoveInicio(){
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    p = primeiro->prox;
    primeiro->prox = p->prox;
    
    tamanho--;
    
    if (primeiro->prox == NULL)
        ultimo = primeiro;
    
    aux = p->item;
    
    delete p;
    
    return aux;
}

TipoItem ListaEncadeada::RemoveFinal(){
    TipoItem aux;
    TipoCelula *p;
    
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    // posiciona p na celula anterior à última
    p = Posiciona(tamanho, true);
    p->prox = NULL;
    
    tamanho--;

    aux = ultimo->item;
    delete ultimo;
    ultimo = p;
    
    return aux;
}

TipoItem ListaEncadeada::RemovePosicao(int pos){
    TipoItem aux;
    TipoCelula *p, *q;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    
    tamanho--;
    
    aux = q->item;
    
    delete q;
    
    if (p->prox == NULL)
        ultimo = p;
    
    return aux;
}

TipoItem ListaEncadeada::Pesquisa(TipoChave c){
    TipoItem aux;
    TipoCelula *p;
    
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    p = primeiro->prox;
    
    aux.SetChave(-1);

    while (p != NULL){
        if (p->item.GetChave() == c){
            aux = p->item;
            break;
        }

        p = p->prox;
    }

    return aux;
}

void ListaEncadeada::Imprime(){
    TipoCelula *p;
    p = primeiro->prox;

    while (p != NULL){
        p->item.Imprime();
        p = p->prox;
    }

    cout << endl;
}

void ListaEncadeada::Limpa(){
    TipoCelula *p;
    p = primeiro->prox;

    while (p != NULL){
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    
    ultimo = primeiro;
    tamanho = 0;
};

TipoItem ListaArranjo::GetItem(int pos){
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    
    return itens[pos - 1];
}

void ListaArranjo::SetItem(TipoItem item, int pos){
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";

    itens[pos - 1] = item;
}

void ListaArranjo::InsereInicio(TipoItem item){
    int i;
    
    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";
    
    tamanho++;

    for (i = tamanho; i > 0; i--)
        itens[i] = itens[i - 1];

    itens[0] = item;
};

void ListaArranjo::InsereFinal(TipoItem item){
    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";
    
    itens[tamanho] = item;
    
    tamanho++;
};

void ListaArranjo::InserePosicao(TipoItem item, int pos){
    int i;

    if (tamanho == MAXTAM)
        throw "ERRO: Lista cheia!";

    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    
    pos--; // posição no vetor = pos-1 (vetor começa em 0)
    tamanho++;
    
    for (i = tamanho; i > pos; i--)
        itens[i] = itens[i - 1];
    
    itens[pos] = item;
};

TipoItem ListaArranjo::RemoveInicio(){
    int i;
    TipoItem aux;
    
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    aux = itens[0];
    
    for (i = 0; i < tamanho; i++)
        itens[i] = itens[i + 1];
    
    tamanho--;

    return aux;
}

TipoItem ListaArranjo::RemoveFinal(){
    TipoItem aux;
    
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    tamanho--;
    
    aux = itens[tamanho];

    return aux;
}

TipoItem ListaArranjo::RemovePosicao(int pos){
    int i;
    TipoItem aux;
    
    if ((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    
    pos--; // posição no vetor = pos-1 (vetor começa em 0)
    
    aux = itens[pos];
    
    for (i = pos; i < tamanho; i++)
        itens[i] = itens[i + 1];
    
    tamanho--;
    
    return aux;
}

TipoItem ListaArranjo::Pesquisa(TipoChave c){
    int i;
    TipoItem aux;
    
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    aux.SetChave(-1); // indica pesquisa sem sucesso
    
    for (i = 0; i < tamanho; i++)
        if (itens[i].GetChave() == c){
            aux = itens[i];
            break;
        }

    return aux;
};

void ListaArranjo::Imprime(){
    int i;

    for (i = 0; i < tamanho; i++)
        itens[i].Imprime();

    cout << endl;
};

void ListaArranjo::Limpa(){
    tamanho = 0;
};

#endif