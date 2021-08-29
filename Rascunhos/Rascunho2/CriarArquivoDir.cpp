#include "CriarArquivoDir.h"
#include <fstream>
#include <filesystem>
#include <iostream>

using std::string, std::ofstream;
namespace fs = std::filesystem;

// Cria um arquivo no diretorio desejado assumindo que
// o diretorio esta no diretorio atual
void CriarArquivoDir(const string& dir, const string arq) {

	string path = dir + "/" + arq;
	ofstream novo;
	novo.open(path.c_str());
	if (novo.fail()) {
	  std::cout << "Erro ao criar o arquivo " << arq << std::endl;
	} else {
	  novo.close();
	}
	system("tree");
}
