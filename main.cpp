#include <iostream>
#include"arquivo.cpp"
#include<math.h>

using namespace std;

struct no{
  no* proximo;
  int lado1;
  int lado2;
  int lado3;
};

 no* cria(int ld1, int ld2, int ld3){
    no* n = new no;
    n->lado1 = ld1;
    n->lado2 = ld2;
    n->lado3 = ld3;
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

void incluirFim(lista* plista, int ld1, int ld2, int ld3){
  no* n;
  n = cria(ld1, ld2, ld3);

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
  cout<<"Triangulos inseridos\n";
  while(!finalLista(pLista)){
    cout<<"Lado1: "<<pLista->marcador->lado1<<" Lado2: "<<pLista->marcador->lado2<<" Lado3: "<<pLista->marcador->lado3<<"\n";
    pLista->marcador = pLista->marcador->proximo;
  }
}

string preEscrita(lista* pLista){

  pLista->marcador = pLista->primeiro;
  string txt = "",num_str ="";
 
  while(!finalLista(pLista)){

    txt +="l1:"+ to_string(pLista->marcador->lado1)+"l2:"+to_string(pLista->marcador->lado2)+"l3:"+to_string(pLista->marcador->lado3);

    pLista->marcador = pLista->marcador->proximo;

    if(!finalLista(pLista)){
      txt +="\n";
    }
  }

  return txt;
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

void gravar(lista* pLista){

  int qtd = 0;
  int l1=0, l2=0, l3=0;
  cout<<"\nQuantos elementos deseja gravar:\n";
  cin>>qtd;

  while(qtd > 0){
    cout<<"\n\nInforme os lados do triangulo\n";

          cout<<"Lado 1 : ";
            cin>>l1;

          cout<<"Lado 2 : ";
            cin>>l2;

          cout<<"Lado 3 : ";
            cin>>l3;

          incluirFim(pLista, l1, l2, l3);
    qtd--;
  }

  Arquivo arquivo;
  arquivo.Escrita(preEscrita(pLista));
  
}

void ler(lista* pLista){
  imprimirLista(pLista);
}

int main() {

  lista* tLista = new lista;
  iniciarLista(tLista);

  int opcao = 0;
 
  do{
    cout<<"\n\n#Triangulos Retangulos \n";
    cout<<"\nDigite um numero:\n";
    cout<<"1 - para Gravar os dados\n";
    cout<<"2 - para Ler os dados\n";
    cout<<"0 - para Sair\n";
    cin>>opcao;

    switch(opcao) {

      case 0:
          cout<<"Saindo do programa";
        break;
      case 1:
          gravar(tLista);
        break;
      case 2:
          ler(tLista);
        break;
      default:
        cout<<"Opcao nao programada";
        
    }

  }while(opcao != 0);

}