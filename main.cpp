#include <iostream>
#include<math.h>
#include <fstream>

using namespace std;

struct no{
  no* proximo;
  float lado1;
  float lado2;
  float lado3;
};

 no* cria(float ld1, float ld2, float ld3){
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

void incluirFim(lista* plista, float ld1, float ld2, float ld3){
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

string correcaoF(string f){

  bool ponto = false, libera = false;
  string nova ="";
  char  ant =' ';

  for(int i = (f.length () - 1); i >= 0 ; i--){

      if((f[i] !='.')&&(f[i] != '0')){
        if(f[i-1] == '.'){
          libera = true;
        }
      }
      
      if(((f[i] != '0') && ponto)|| libera){
        nova = f[i] + nova;
      }

      if(f[i] == '.'){
        ponto = true;
        libera = true;
      }

  }

  return nova;
}

string preEscrita(lista* pLista){

  pLista->marcador = pLista->primeiro;
  string txt = "", l1, l2, l3;
 
  while(!finalLista(pLista)){

    l1 = correcaoF(to_string(pLista->marcador->lado1));
    l2 = correcaoF(to_string(pLista->marcador->lado2));
    l3 = correcaoF(to_string(pLista->marcador->lado3));

    txt +="l1:"+l1+"l2:"+l2+"l3:"+l3;

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

void leitura(lista* pLista){

    string texto = "",txt ="", l1, l2, l3;
    bool a = false, b = false, c = false;
    ifstream leitor;
    leitor.open("banco.txt", ios::in);

    while(!leitor.eof()){
      leitor>>txt;

      for(int i = 0; i < txt.length(); i++){

        if(txt[i] == 'l'){
            a = false;
            b = false;
            c = false;
        }

        if(a){
          l1+= txt[i];
        }else if(b){
          l2+= txt[i];
        }else if(c){
          l3+= txt[i];
        }

        if(txt[i] == ':'){
           
            if(txt[i-1] == '1'){
              a = true;
            }else if(txt[i-1] == '2'){
              b = true;
            }else if(txt[i-1] == '3'){
              c = true;
            }
        }

      }
      cout<<"\n "<<l1<<" "<<l2<<" "<<l3;
      float num_float = std::stof(str);
      l1 = "";
      l2 = "";
      l3 = "";
    }

    leitor.close();
    //return texto;
  }

  bool escrita(string txt){
    ofstream escritor;
    escritor.open("banco.txt", ios::out);
    escritor<<txt;
    escritor.close();
    return true;
  }

void gravar(lista* pLista){

  int qtd = 0;
  float l1=0, l2=0, l3=0;
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

  
  escrita(preEscrita(pLista));
  
}

void ler(lista* pLista){
  leitura(pLista);
  imprimirLista(pLista);
}

int main() {
  lista* tLista;
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
          tLista = new lista;
          iniciarLista(tLista);
          gravar(tLista);

        break;
      case 2:
          tLista = new lista;
          iniciarLista(tLista);
          ler(tLista);
          
        break;
      default:
        cout<<"Opcao nao programada";
        
    }

  }while(opcao != 0);

}