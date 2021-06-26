 #include <iostream>
 #include <fstream>
 using namespace std;

struct Arquivo{

  string Leitura(){

    string texto = "";
    ifstream leitura;
    leitura.open("banco.txt", ios::in);

    while(!leitura.eof()){
      leitura>>texto;
    }

    leitura.close();

    return " ";
  }

  bool Escrita(string txt){
    ofstream escrita;
    escrita.open("banco.txt", ios::out);
    escrita<<txt;
    escrita.close();
    return true;
  }
  
};