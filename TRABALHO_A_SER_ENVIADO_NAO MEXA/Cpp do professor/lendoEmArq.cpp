//
//
//
#include "lendoEmArq.h"
#include <string>
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <iostream>//-Vai usar cin e/ou cout  Escrever na tela do DOES
#include "windows.h"//-----Escrever Caracteres Latinos
#include <cstdio>//----Usar exit(0): exit(1);...
#include <iomanip> //-------Escrever double   com precisão especificada   
using std::setprecision;//-------Para especificara a precisão
//
using namespace std;
//
void LendoEmArquivos(string&     DirMaisArq, //----Dir+Arquivode Dados
	/////////////////////////////////////////////////int&        Nlinhas,//-----Número de dados double
	bool&       SegundaLinhaEumaString,
	int&        Limite,
	string&     NomeDosDados,
	int&        Nlinhas,
	double      Vet[])
{
	ifstream          Obj_ifstream;//---DEstanciando um objeto do tipo ifstream
	string            Tecla;
	//
	//
	Obj_ifstream.open(DirMaisArq.c_str());//----Cpnvertendo string C++   em cont char* do  C
	if (Obj_ifstream.fail())
	{
		cout << "    Falha para abrir o Dir+Arq  = " << DirMaisArq << "\n";
		cout << " Digite tecla para terminar o programa " << "\n";
		cin >> Tecla;
		exit(1);
	}
	//
	Obj_ifstream >> Nlinhas;
	//
	if (Nlinhas > Limite)
	{
		cout << " Seu arquivo tem Nlinhas = " << Nlinhas << "maior que o valor máximo permitido   que é  " << Limite << "\n";
		cout << " Digite Tecla para terminar o programa " << "\n";
		cin >> Tecla;
		exit(1);
	}
	//
	if (SegundaLinhaEumaString == true)
	{

		Obj_ifstream >> NomeDosDados;
		cout << "\n";
		cout << "Nome dos dados LIDO  = " << NomeDosDados << "\n";
		cout << "\n";
		
		for (int lin = 1; lin < Nlinhas; lin++)
		{
			Obj_ifstream >> Vet[lin];

			if (Obj_ifstream.fail())
			{
				//*
				cout << "Falha para ler dados--de ordem  "<<   lin  << "---1--- enviado de 'LendoEmArquivos'" << "\n";
				cout << " digite tecla para terminar o programa " << "\n";
				cin >> Tecla;
				exit(1);
				//*/
			}

			cout << "Lin  =  " << lin << "      Vet[Lin]   =  " << Vet[lin] << "\n";
					
		}
	}
	else
	{
		for (int lin = 0; lin < Nlinhas; lin++)
		{
			Obj_ifstream >> Vet[lin];
			if (Obj_ifstream.fail())
			{
				//*
				cout << "Falha para ler dados--de ordem  " << lin << "---3--- enviado de 'LendoEmArquivos'" << "\n";
				cout << " digite tecla para terminar o programa " << "\n";
				cin >> Tecla;
				exit(1);
				//*/

			}
		}
	}
}
//

		