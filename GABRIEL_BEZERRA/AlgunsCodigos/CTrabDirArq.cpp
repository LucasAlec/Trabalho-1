#include "CTrabDirArq.h"
#include "windows.h"
#include <new>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <direct.h>

CTrabDirArq::CTrabDirArq()
{
    NumeroDeDir_CTrabDirArq = 0;
    NumeroDeArqDeCadaDir_CTrabDirArq = nullptr;
    NomeArqDir_CTrabDirArq = nullptr;
}

void CTrabDirArq::setNumeroDeDir_CTrabDirArq(const int& NumeroDeDir)
{
    NumeroDeDir_CTrabDirArq = NumeroDeDir;
    return;
}

void CTrabDirArq::setNumeroDeArqDeCadaDir_CTrabDirArq(int* NumDeArqDeCadaDir) // Tem que montar isso na main() e passar pro setter.
{
    this->NumeroDeArqDeCadaDir_CTrabDirArq = NumDeArqDeCadaDir;
    return;
}

// Ela aloca o vetor dinamico, falta montar.
void CTrabDirArq::setNomeArqDir_CTrabDirArq()
{
    NomeArqDir_CTrabDirArq = new string*[NumeroDeDir_CTrabDirArq];

    for (int i = 0; i < NumeroDeDir_CTrabDirArq; i++)
    {
        int numeroArq;
        numeroArq = NumeroDeArqDeCadaDir_CTrabDirArq[i];
        NomeArqDir_CTrabDirArq[i] = new string[numeroArq];
    }
    return;
}

void CTrabDirArq::destruidorNomeArqDir_CTrabDirArq(/*string** ptr, const int&*/)
{
  for (int i = 0; i < NumeroDeDir_CTrabDirArq; i++) {
    delete [] NomeArqDir_CTrabDirArq[i];
  }

  delete [] NomeArqDir_CTrabDirArq;
  return;
}



CTrabDirArq::~CTrabDirArq()
{
	destruidorNomeArqDir_CTrabDirArq();
}

// Ate aqui esta tudo 100%




//
// ----------------------------------------------
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// Funcoes restantes para implementar em montar()
// $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// ----------------------------------------------

// CaracterProibidosDirArq
// Checar caracteres proibidos em arquivos e diretorios
// Tambem colocar nomes e usar std::find _NOME_
/*Usar .at para referenciar um caractere em uma string, fica mais rapido*/

        // ChecaDiscoValido
        // Checar se o disco e valido recebendo o nome do disco e colocando ofstream nele com :/dasdad, se funcionar o disco existe

        // ChecaSeDirExiste
        // Recebe o diretorio e faz ofstream nele, se .fail... etc.. ele existe, se nao, n existe

        // Cria_DirValido
        // Cria um diretorio valido ate  as / barras _mkdir 0 = nao criou, 1 criou _mkdir ja cria usando o path
        // use a funcao ChecaSeDirExiste para ver se deu certo.
        // Ela cria o dir quando e chamada e retorna true se deu certo e false caso contrario

// EscreveEmArq
// se nao abrir o arquivo retorna erro, escrever vetor numero com um numero predefinido de casas decimais set preciison vem antes do obj a ser gravado include <iomanip>

// obterCurrentDir
// retorna o valor do direotrio atual. poderia mostrar sting Path do atributo private om get

// TrocaCaracterAporOutroB
// Trocar de disco. C, D, E...

/*return; em funcao void*/

//obj_Ctrab.criarDir("asdasd");
// usar dois \\ backslash
/*
int         NumDeDir_CTrabDirArq;
int*        NumArqDeCadaDir_CTrabDirArq;
string*     Dir_CTrabDirArq;
string**    ArqEmCadaDir_CTrabDirArq;
*/
#include "CTrabDirArq.h"
#include "windows.h"
#include <new>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <direct.h>
//#include <string> e using std::string em "CTrabDirArq.h"
using namespace std;

// Aloca uma array bidimensional dinamicamente
// dado o numero de linhas 'x' e colunas 'y'
// note que, x e y devem ser dados por referencia

/* Receber o nome dos arquivos e pastas com getline obrigatoriamente*/
// Recebe o disco que o usuario digitou e verifica se ele existe
//
bool CTrabDirArq::checaDiscoValido_CTrabDirArq(const string& LetraDisco)
{
    ofstream obj_Ofstream;
    string testeDeDisco;
    testeDeDisco += LetraDisco;
    testeDeDisco += ":\\arquivoTeste";
    obj_Ofstream.open(testeDeDisco);

    if (obj_Ofstream.fail())
    {
        return false;
    }
    else
    {
        obj_Ofstream.close();
        remove testeDeDisco;
        return true;
    }


}

bool CTrabDirArq::checaSeDirExiste_CTrabDirArq(const string& NomeDir)
{
    // Se colocar espaco cria cada diretorio com espacos
    ofstream obj_Ofstream;
    string testeDeDir;
    testeDeDir += NomeDir;
    testeDeDir += "\\";
    testeDeDir += "arquivoTeste";
    obj_Ofstream.open(testeDeDir);

    if (obj_Ofstream.fail())
    {
        return false;
    }
    else
    {
        obj_Ofstream.close();
        return true;
    }
}

bool CTrabDirArq::criaDir_CTrabDirArq(const string& NomeDir)
{
    int sucesso;
    sucesso = _mkdir(NomeDir.c_str());
    if (sucesso == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CTrabDirArq::setNumeroDeDir_CTrabDirArq(const int& NumeroDeDir)
{
    NumeroDeDir_CTrabDirArq = NumeroDeDir;
}

void CTrabDirArq::NumeroDeArqDeCadaDir_CTrabDirArq()
{
    int NumeroDeDir_CTrabDirArq;
    int NumDeArqDeCadaDir[NumeroDeDir];
    for (int i = 0; i < NumeroDeDir; i++)
    {
        int j;
        std::cin >> j;
        NumDeArqDeCadaDir[i] = j;
    }
    for (int i = 0; i < NumeroDeDir; i++)
    {

        std::cout << NumDeArqDeCadaDir[i];
    }
    NumeroDeArqDeCadaDir_CTrabDirArq = NumDeArqDeCadaDir;
}

bool CTrabDirArq::criarArquivo_CTrabDirArq(const string& NomeArq)
{
    ofstream obj_Ofstream;
    obj_Ofstream.open(NomeArq);

    if (obj_Ofstream.fail())
    {
        return false;
    }
    else
    {
        obj_Ofstream.close();
        return true;
    }
}

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

using std::string;
void EscreverString2DArquivo(const string** string2d, const string& path) {
  int l, c;
  // l = string2d.size();
  //c = string2[0].size; // TEM QUE OBTER NUMERO DE LINHAS E COLUNAS NO INPUT
  std::ofstream file;
  file.open(path);

  for (int i = 0; i < c; i++) {
    for (int j = 0; j < l; i++) {
    	file << string2d[i][j] << "		";
    }
    file << "\n";
  }
}


