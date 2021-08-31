#include "CTrabDirArq.h"
#include "windows.h"
#include <new>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <direct.h>
#include <stdio.h>
#include <cstdio>

using namespace std;
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

void CTrabDirArq::setNumeroDeArqDeCadaDir_CTrabDirArq(int* NumDeArqDeCadaDir)
{
    this->NumeroDeArqDeCadaDir_CTrabDirArq = NumDeArqDeCadaDir;
    return;
}

// Metodo ainda nao testado, sinto que o professor quer que o direotrio seja criado com os nomes
// e depois fazer o trem de colocar arq nos dir.
/* Receber o nome dos arquivos e pastas com getline obrigatoriamente*/
void CTrabDirArq::setNomeArqDir_CTrabDirArq()
{
    try
    {
    	NomeArqDir_CTrabDirArq = new string*[NumeroDeDir_CTrabDirArq];

    for (int i = 0; i < NumeroDeDir_CTrabDirArq; i++)
    {
        int numeroArq;
        numeroArq = NumeroDeArqDeCadaDir_CTrabDirArq[i];
        NomeArqDir_CTrabDirArq[i] = new string[numeroArq];
    }
    }
    catch(bad_alloc& ba)
    {
    	cout << "Ocorreu má alocação dinâmica" << ba.what() << endl;
    	//break; Falta testar
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

/**
 * Verifica se o disco especificado existe.
 * @param LetraDisco Letra do disco a ser verificado.
 * @return Retorna true se o disco existe e false caso contrario
 * @since 31/08/21
 */
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
        remove(testeDeDisco.c_str());
        return true;
    }
}

// Talvez nao seja desnecessario, uma vez que, ao criar diretorio com _mkdir() ja retorna se foi
// criado com sucesso ou nao (CTrabDirArq::criaDir_CTrabDirArq)
/**
 * Verifica se um diretorio existe dado o nome do diretorio no path atual.
 * @param NomeDir Nome do diretorio a ser verificado.
 * @return Retorna true se o diretorio existe e false caso contrario
 * @since 31/08/21
 */
bool CTrabDirArq::checaSeDirExiste_CTrabDirArq(const string& NomeDir)
{
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
        remove(testeDeDir.c_str());
        return true;
    }
}

/**
 * Cria um diretorio, no path atual, dado o nome do diretorio.
 * @param NomeDir Nome do diretorio a ser criado.
 * @return Retorna true se o diretorio foi criado com sucesso e false caso contrario
 * @since 31/08/21
 */
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

/**
 * Cria um arquivo, no path atual, dado o nome do arquivo.
 * @param NomeArq Nome do arquivo a ser criado.
 * @return Retorna true se o arquivo foi criado com sucesso e false caso contrario
 * @since 31/08/21
 */
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

template<typename T>
bool CTrabDirArq::escreveVetor2DArq_CTrabDirArq(T* numerico2D, const string& nomeArq, const int& linhas, const int& colunas)
{
    ofstream objOfstream;
    objOfstream.open(nomeArq);
    if (objOfstream.fail())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                objOfstream << setprecision(10) << numerico2D[i][j] << "    ";
            }
            objOfstream << "\n";
        }
        objOfstream.close();
        return true;
    }
}

bool CTrabDirArq::escreveVetor2DArq_CTrabDirArq(string* string2D, const string& nomeArq, const int& linhas, const int& colunas)
{
    ofstream objOfstream;
    objOfstream.open(nomeArq);
    if (objOfstream.fail())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; i++)
            {
                objOfstream << string2D[i][j] << "    ";
            }
        objOfstream << "\n";
        }
        return true;
    }
}
bool CTrabDirArq::montar_CTrabDirArq()
{

}






