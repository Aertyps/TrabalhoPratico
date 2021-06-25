#include <iostream>
using namespace std;

struct no{
  no* proximo;
  int info;
};

 no* cria(int info){
    no* n = new no;
    n->info = info;
    return n;
  }

struct lista{
  no* primeiro;
  no* ultimo;
  no* marcador;
  int tamanho;
};

void iniciarLista(lista* plista){
  plista -> primeiro = NULL;
  plista -> ultimo = NULL;
  plista -> marcador = NULL;
  plista -> tamanho = 0;
}

int obterTamanho(lista* plista){
  return plista->tamanho;
}

bool listaVazia(lista* plista){
  return (plista->tamanho == 0);
}

bool finalLista(lista* plista){
  return (plista->marcador == NULL);
}

void incluirFim(lista* plista, int info){
  no* n;
  n = cria(info);

  if(listaVazia(plista)){
    plista->primeiro = n;
  }else{
    plista->ultimo->proximo = n;
  }

  plista->ultimo = n;
  plista->marcador = n;
  plista->tamanho ++;

}

void imprimirLista(lista* pLista){
  pLista->marcador = pLista->primeiro;

  while(!finalLista(pLista)){
    int informacao = pLista->marcador->info;
    cout<<"A informação é "<<informacao<<"\n";

    pLista->marcador = pLista->marcador->proximo;
  }
}

void excluirPosicao(lista* pLista, int pos){
  no* anterior = new no;
  no* aux = new no;

  if(!listaVazia(pLista)){
    pLista->marcador = pLista->primeiro;

    if(pos == 0){
      pLista->primeiro = pLista->marcador->proximo;

    }else{

        if(pos < obterTamanho(pLista)){
          
          for(int i=0;i<pos;i++){
            anterior = pLista->marcador;
            pLista->marcador = pLista->marcador->proximo;
            aux = pLista->marcador->proximo;
          }
        anterior->proximo = aux;
      }
    }
  }
 
}

int main() {
 
}