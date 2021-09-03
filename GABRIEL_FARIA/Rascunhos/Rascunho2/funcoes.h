#ifndef ALOCARARRAY2D_H

#include <new>

#define ALOCARARRAY2D_H
#define DEALOCARARRAY2D_H
int** AlocarArray2D(int x, int y) {
  int** ptr = new int*[x];
  
  for (int i = 0; i < x; i++) {
    ptr[i] = new int[y];
  }
  
  return ptr;
}

void DealocarArray2D(int** ptr, int x, int y) {

  for (int i = 0; i < x; i++) {
    delete [] ptr[i];
  }
  
  delete [] ptr;
}
#endif

#ifndef ALOCARARRAY3D_H

#include <new>

#define ALOCARARRAY3D_H
#define DEALOCARARRAY3D_H
int*** AlocarArray3D(int x, int y, int z) {
   int*** ptr = new int**[x];
   
   for (int i = 0; i < x; i++) {
     ptr[i] = new int*[y];
   
     for (int j = 0; j < y; j++) {
       ptr[i][j] = new int[z];
   }
   }
   return ptr;
}

void DealocarArray3D(int*** ptr, int x, int y, int z) {
  
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      delete [] ptr[i][j];
    }
  delete [] ptr;
  }
}
#endif

#define CRIADIRETORIO_H
#include <filesystem>
using std::string;
namespace fs = std::filesystem;
// Funcao que cria um diretorio com o nome desejado
// e checa se o diretorio foi criado com sucesso
#include <filesystem>
#include <iostream>
using std::string;
namespace fs = std::filesystem;

void CriaDiretorio(string nome_do_diretorio) {
  try {
		fs::create_directory(nome_do_diretorio);
	}
	catch (std::filesystem::__cxx11::filesystem_error) {
		std::cout << "Erro na criacao do diretorio [" << nome_do_diretorio << "]: Caractere \"/\" invalido.\n";
	}
}
