#include "AlocarArray2D.h"
#include <new>

// Aloca uma array bidimensional dinamicamente
// dado o numero de linhas 'x' e colunas 'y'
// note que, x e y devem ser dados por referencia
int** AlocarArray2D(const int& x, const int& y) {
  int** ptr = new int*[x];
  
  for (int i = 0; i < x; i++) {
    ptr[i] = new int[y];
  }
  
  return ptr;
}

// Dealoca uma array bidimensional criada pela funcao
// AlocarArray2D() dado a array, numero de linhas e colunas
// note que, x e y devem ser dados por referencia
void DealocarArray2D(int** ptr, const int& x, const int& y) {

  for (int i = 0; i < x; i++) {
    delete [] ptr[i];
  }
  
  delete [] ptr;
}
