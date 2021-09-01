//
//
#include "GeraArqDadosNumericos_1.h"
#include "ChecaSeDirExiste.h"//-----Para poder usar a função  'ChecaSeDirExiste(string& Dir)'
#include "Cria_DirValido.h"//----Para usar 'Cria_DirValido(string&  Dir)'
//
#include "windows.h"//-----Escrever Caracteres Latinos
#include <iostream>//-Vai usar cin e/ou cout
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(10;...
//
#include <iomanip>//----Trabalha com precisão qualquer com double
using std::setprecision;//----Especificar precisão para double
using namespace std;
//
using namespace std;
//
//
void GeraArqDadosNumericos_1_CTrabComDir_0(//Dadose de entrada
	                                        int&            NumRegionsStringMaisDados,
	                                        int*            NumDeString,//----->
	                                        string**        ListaStringArq,
											//
											int*            NdadosPorRegiao,
											double**        Vetor,
											//
											//
											//-->ListaStringArq[i][j]; i está em {0,...,(NumRegionsStringMaisDados -1)} e j está em {0,...,NumDeString[i]}
											//-->Portanto deve ser alocado com o tamanho:  ListaStringArq = new string*[NumRegionsStringMaisDados] e 
											//-->ListaStringArq[i] = new string[NumDeString[i]+ 1]: para i = 0,.......,((NumRegionsStringMaisDados -1)
											//
											//OBS:--->Para todo i; última string a última string só deve ter caractere Espaço em Branco(Pode ter mais
											//
											string&         DirOndeColocarArquivo,//----Exemplo: D:/pasta1/Pasta2
											string&         NomeDoArquivo,//--Exemplos: ArqDado1.txt
											//
											//Retorna
											bool&           Sucesso
										)
{
	string       DirMaisArq;
	ofstream     Obj_ofstream;
	bool         Veredito;
	//
	SetConsoleOutputCP(GetACP());
	//
	Veredito = ChecaSeDirExiste(DirOndeColocarArquivo);
	//
	if (Veredito == true)
	{
		DirMaisArq = DirOndeColocarArquivo;
		DirMaisArq += "/";
		DirMaisArq += NomeDoArquivo;
	}
	else
	{
		Veredito = Cria_DirValido(DirOndeColocarArquivo);
		if (Veredito == true)
		{
			DirMaisArq = DirOndeColocarArquivo;
			DirMaisArq += "/";
			DirMaisArq += NomeDoArquivo;
		}
		else
		{
			string     Tecla;
			//
			cout << " Arquivo para dados Numéricos não pode ser Criado porque O Diretório especificado para colocar " << "\n";
			cout << " o Arquivo não é Válido. Enviado de GeraArqDadosNumericos_0_CTrabComDir_0--1. " << "\n";
			cout << "Digite Tecla para continuar" << "\n";
			cin >> Tecla;
			Sucesso = false;
		}
	}
	//	
	//
	Sucesso = true;
	//
	Obj_ofstream.open(DirMaisArq.c_str()); 
	if (Obj_ofstream.fail())
	{
		string      Tecla;
		cout << " " << "\n";
		cout << " Falha para abrir o Dir+Arquivo = " << DirMaisArq << "\n";
		cout << " " << "\n";
		cout << " Enviado de: GeraArqDadosNumericos_0_CTrabComDir_0. Digite uma Tecla para continuar " << "\n";
		cout << " " << "\n";
		cin >> Tecla;
		Sucesso = false;
		return;
	}
	else
	{
		for (int ir = 0; ir < NumRegionsStringMaisDados; ir++)
		{
			for (int in = 0; in < NumDeString[ir]; in++)
			{
				Obj_ofstream << ListaStringArq[ir][in] << "\n";
			}
			//
			Obj_ofstream << "" << "\n";
			Obj_ofstream << "" << "\n";
			//
			for (int ia = 0; ia < NdadosPorRegiao[ir]; ia++)
			{
				Obj_ofstream << "    ordem  do Vetor  = " << ia << setprecision(10) << "     Valor  do  Vetor  =  " << Vetor[ir][ia] << "\n";
				Obj_ofstream << "" << "\n";
			}
		}
	}
}
