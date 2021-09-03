#include "CriarDiretorio.h"

#include <filesystem>
#include <iostream>
#include <cstdlib>

using std::string;
namespace fs = std::filesystem;

// Funcao que cria um diretorio com o nome desejado
// e checa se o diretorio foi criado com sucesso
// caso contrario, mostra uma mensagem de erro
void CriarDiretorio(string nome_do_diretorio) {
  try {
    fs::create_directory(nome_do_diretorio);
    std::cout << "Diretorio criado com sucesso" << std::endl;
	}
	catch (std::filesystem::__cxx11::filesystem_error) {
		std::cout << "Erro na criacao do diretorio [" << nome_do_diretorio << "]: Caractere \"/\" invalido.\n";
		exit(0);
	}

}
