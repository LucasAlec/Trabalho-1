// Checa disco valido
// Checa se dir existe
// Cria diretorio valido, checado 
// Escreve em arq
// Escreve vetor dado em path dado
// Cria arquivo em diretorio
// Obtem pwd
// Mostra no DOS um arquivo matriz
/*variaiveis: path, new dir, linhas, colunas, */
//Tudo com try_catch
/*UX: O que voce quer?
1. Mostrar Diretorio atual
2. Criar novo diretorio, especifiquie o path, padrao pwd
3. Criar um arquivo no diretorio desejado, padrap pwd
4. Mudar de direotrio -> mostra o atual
5. */

//Implementar get_set no nome do diretorio
#include "CTrabDirArq.h"
#include <iostream>
//#include <string> em CTrabDirArq.h
#include <new>
#include <cstdlib>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

class Caractere_Invalido{};

string** CTrabDirArq::alocarString2D_CTrabDirArq(const int& linhas, const int& colunas)
{
	string** ptr = new string*[linhas];
		for (int i = 0; i < linhas; i++)
		{
			ptr[i] = new string[colunas];
		}
	return ptr;
}

	
void CTrabDirArq::dealocarString2D_CTrabDirArq(string** ptr, const int& linhas, const int& colunas)
{
	for (int i = 0; i < linhas; i++)
	{
		delete [] ptr[i];
	}			
	delete [] ptr;
}
		
		
void CTrabDirArq::criarDiretorio_CTrabDirArq()
{
	fs::create_directory(novo_dir);
	/*
	 * Checar se o direotrio foi criado com sucesso
	 */
/*try {
fs::create_directory(novo_dir);
std::cout << "Diretorio criado com sucesso" << std::endl;
}
catch (std::filesystem::__cxx11::filesystem_error) {
std::cout << "Erro na criacao do diretorio " << novo_dir << endl;
}
catch (Caractere_Invalido& e) {
std::cout << "Erro na criacao do diretorio " << novo_dir << endl;
}*/
}

/*void CTrabDirArq::mostrarDiretorioAtual_CTrabDirArq()
{
	cout << fs::current_path() << endl;
}*/

/*void CTrabDirArq::mostrarTree_CTrabDirArq()
{
	system("tree");
}*/

void CTrabDirArq::setNovoDir_CTrabDirArq(string& texto_dir)
{
	for (char letra : texto_dir)
	{
		for (int i = 0; i < caracteresProibidos.size(); i++)
		{
			if (letra == caracteresProibidos[i])
			{
				cout << "Caractere invalido: " << letra << endl;
				//throw Caractere_Invalido();
			}
		}
	}
	novo_dir = texto_dir;
}

string CTrabDirArq::getNovoDir_CTrabDirArq()
{
	return novo_dir;
}

void CTrabDirArq::setNovoArq_CTrabDirArq(std::string& texto_arq)
{
	for (char letra : texto_arq)
	{
		for (int i = 0; i < caracteresProibidos.size(); i++)
		{
			if (letra == caracteresProibidos[i])
			{
				cout << "Caractere invalido: " << letra << endl;
				throw Caractere_Invalido();
			}
		}
	}
	novo_dir = texto_arq;
}

void setPathAtual_CTrabDirArq(const string& texto_path)
{
	if (texto_path = "/")
	{
		size_t found = str.find_last_of("/\\");
		path = str.substr(0,found);
	}
	else
	{
		//checar se o diretorio que quer mudar existe e tem permissao
	}
}

string getPathAtual_CTrabDirArq()
{
}












