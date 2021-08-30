#include "AlocarString2D.h"
#include <new>
#include <iostream>
using std::string;

// Aloca uma array bidimensional dinamicamente
// dado o numero de linhas 'x' e colunas 'y'
// note que, x e y devem ser dados por referencia

string** AlocarString2D(const int& x, const int& y) {
  string** ptr = new string*[x];
  
  for (int i = 0; i < x; i++) {
    ptr[i] = new string[y];
  }
  
  return ptr;
}

// Dealoca uma array bidimensional criada pela funcao
// AlocarString2D() dado a array, numero de linhas e colunas
// note que, x e y devem ser dados por referencia
void DealocarString2D(string** ptr, const int& x, const int& y) {

  for (int i = 0; i < x; i++) {
    delete [] ptr[i];
  }
  
  delete [] ptr;
}
