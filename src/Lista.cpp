/* #include "Lista.hpp"

Lista::Lista(){
    tamanho = 0;
}

int Lista::GetTamanho(){
    return tamanho;
}

bool Lista::IsVazia(){
    return tamanho == 0;
}

TipoItem::TipoItem(){
    chave = -1;
}

TipoItem::TipoItem(TipoChave c){
    chave = c;
}

void TipoItem::SetChave(TipoChave c){
    chave = c;
}

TipoChave TipoItem::GetChave(){
    return chave;
}

void TipoItem::Imprimir(){
    cout << chave << " ";
}

TipoItem ListaArranjo::GetItem(int pos){
    if((pos > tamanho) || (pos <= 0))
        throw "Erro: Posicao invalida!";

    return itens[pos - 1];
}

void ListaArranjo::SetItem(TipoItem item, int pos){
    if((pos > tamanho) || (pos <= 0))
        throw "Erro: Posicao invalida!";
    
    itens[pos - 1] = item;
}

void ListaArranjo::InserirInicio(TipoItem item){
    int i;

    if(tamanho == MAX_TAM)
        throw "Erro: Lista cheia!";
    
    tamanho++;

    for(i = tamanho; i > 0; i--)
        itens[i] = itens[i-1];

    itens[0] = item;
}

void ListaArranjo::InserirFinal(TipoItem item) {
    if (tamanho == MAX_TAM)
        throw "Erro: Lista cheia!";

    itens[tamanho] = item;
    
    tamanho++; 
};

void ListaArranjo::InserirPos(TipoItem item, int pos){
    int i;

    if(tamanho == MAX_TAM)
        throw "Erro: Lista cheia!";
    
    if((pos > tamanho) || (pos <= 0))
        throw "Erro: Posicao Invalida!";
    
    pos--;
    tamanho++;
    
    for (i = tamanho; i > pos; i--)
        itens[i] = itens[i - 1];
    
    itens[pos] = item;
};

TipoItem ListaArranjo::RemoverInicio(){
    int i;
    TipoItem aux;
    
    if(tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    aux = itens[0];
    
    for (i = 0; i < tamanho; i++)
        itens[i] = itens[i + 1];
    
    tamanho--;
    
    return aux;
};

TipoItem ListaArranjo::RemoverFinal(){
    TipoItem aux;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    tamanho--;

    aux = itens[tamanho];
    
    return aux;
}

TipoItem ListaArranjo::RemoverPos(int pos){
    int i;
    TipoItem aux;

    if((pos > tamanho) || (pos <= 0))
        throw "ERRO: Posicao Invalida!";
    
    pos--;
    
    aux = itens[pos];
    
    for(i = pos; i < tamanho; i++)
        itens[i] = itens[i + 1];
    
    tamanho--;
    
    return aux;
}

TipoItem ListaArranjo::Pequisar(TipoChave c){
    int i;
    TipoItem aux;

    if(tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    aux.SetChave(-1);
    
    for(i = 0; i < tamanho; i++)
        if(itens[i].GetChave() == c){
            aux = itens[i];
            break;
        }

    return aux;
};

void ListaArranjo::Imprimir(){
    int i;

    for (i = 0; i < tamanho; i++)
        itens[i].Imprimir();
    
    cout << endl;
};

void ListaArranjo::Limpa(){
    tamanho = 0;
};

TipoCelula::TipoCelula(){
    item.SetChave(-1);
    prox = NULL;
};

ListaEncadeada::ListaEncadeada() : Lista(){
    primeiro = new TipoCelula();
    ultimo = primeiro;
};

ListaEncadeada::~ListaEncadeada(){
    Limpa();
    delete primeiro;
};

TipoCelula* ListaEncadeada::Posiciona(int pos, bool antes = false){
    TipoCelula *p;
    int i;
    
    if((pos > tamanho) || (pos <= 0))
        throw "Erro: Posicao Invalida!";
    
    p = primeiro;
    
    for(i = 1; i < pos; i++){
        p = p->prox;
    }

    if (!antes)
        p = p->prox;
    
    return p;
};

TipoItem ListaEncadeada::GetItem(int pos){
    TipoCelula *p;
    
    p = Posiciona(pos);
    
    return p->item;
};

void ListaEncadeada::SetItem(TipoItem item, int pos){
    TipoCelula *p;

    p = Posiciona(pos);
    p->item = item;
};

void ListaEncadeada::InserirInicio(TipoItem item){
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    nova->prox = primeiro->prox;
    primeiro->prox = nova;
    
    tamanho++;
    
    if (nova->prox == NULL)
        ultimo = nova;
};

void ListaEncadeada::InserirFinal(TipoItem item){
    TipoCelula *nova;

    nova = new TipoCelula();
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    
    tamanho++;
};

void ListaEncadeada::InserirPos(TipoItem item, int pos){
    TipoCelula *p, *nova;

    p = Posiciona(pos, true); // posiciona na célula anterior
    nova = new TipoCelula();
    nova->item = item;
    nova->prox = p->prox;
    p->prox = nova;
    
    tamanho++;
    
    if(nova->prox == NULL)
        ultimo = nova;
};

TipoItem ListaEncadeada::RemoverInicio(){
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "Erro: Lista vazia!";
    
    p = primeiro->prox;
    primeiro->prox = p->prox;
    
    tamanho--;
    
    if (primeiro->prox == NULL)
        ultimo = primeiro;
    
    aux = p->item;
    
    delete p;
    
    return aux;
};

TipoItem ListaEncadeada::RemoverFinal(){
    TipoItem aux;
    TipoCelula *p;
    
    if (tamanho == 0)
        throw "Erro: Lista vazia!";
    
    p = Posiciona(tamanho, true);
    p->prox = NULL;
    
    tamanho--;
    
    aux = ultimo->item;
    
    delete ultimo;
    
    ultimo = p;
    
    return aux;
};

TipoItem ListaEncadeada::RemoverPosicao(int pos){
    TipoItem aux;
    TipoCelula *p, *q;

    if (tamanho == 0)
        throw "Erro: Lista vazia!";
    
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    
    tamanho--;
    
    aux = q->item;
    
    delete q;
    
    if (p->prox == NULL)
        ultimo = p;
    
    return aux;
};

TipoItem ListaEncadeada::Pesquisa(TipoChave c){
    TipoItem aux;
    TipoCelula *p;

    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    
    p = primeiro->prox;
    aux.SetChave(-1);
    
    while(p != NULL){
        if(p->item.GetChave() == c){
            aux = p->item;
            break;
        }

        p = p->prox;
    }

    return aux;
};

void ListaEncadeada::Imprime(){
    TipoCelula *p;

    p = primeiro->prox;
    
    while(p != NULL){
        p->item.Imprimir();
        p = p->prox;
    }

    cout << endl;
};

void ListaEncadeada::Limpa(){
    TipoCelula *p;

    p = primeiro->prox;
    
    while(p != NULL){
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }

    ultimo = primeiro;
    tamanho = 0;
}; */