//
//
//
#include "ChecaDisoValido.h"
//
//
#include "windows.h"
#include <iostream>//-Vai usar cin e/ou cout
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(10;...
using namespace std;//C++ Padrão
//
//
bool ChecaDiscoValido(string&          Disco)
{
	string          DiscoValido;
	string          Tecla;
	const char*     Dicovalido_C;
	int             Nstring;
	bool            DirValido;
	//
	SetConsoleOutputCP(GetACP());
	//
	ofstream      Obj_00_ofstream;//----Estnaciando um objeto de ofstream	
	//	
	//----Inserido em 26/04/2021
	Nstring = static_cast<int>(Disco.length());//---Fornece o número de Caracterfes da string   Disco
	//----Inseridoe m 26/04/2021
	//	
	//
	if (Nstring != 1)
	{
		cout << " Um Disco válido deve ter SÓMENTE 1 CARACTER. iSSSO FOI VIOLADO. PROGRAMA SERÁ TERMINADO." << "\n";
		cout << "\n";
		cout << " Digite uma Tecla para terminar o program" << "\n";
		cout << "\n";
		cin >> Tecla;
		exit(1);
	}
	else
	{
		string         Disco_C;
		Disco_C = "C";
		string     Aux;
		Aux = Disco.at(0);
		if (Aux == Disco_C)
		{
			cout << " Disco especificado é o Disco    'C'       (C maiúsculo) padrão do Windows." << "\n";
			cout << "\n";
			cout << " Digite uma Tecla para continuar o program" << "\n";
			cout << "\n";
			cin >> Tecla;
			//
			bool            DirValido_C;
			DirValido_C = false;
			return        DirValido_C;
			//
		}
		else
		{
			if (Aux == "c")
			{
				//
				cout << " Disco especificado não é o Disco    'C'       (C maiúsculo) padrão do Windows." << "\n";
				cout << "\n";
				cout << " Provavelmente você digitou 'c'       (c  Minúsculo) Não padrão do Windows." << "\n";
				cout << "\n";
				cout << " Digite uma Tecla para Terminar o program" << "\n";
				cout << "\n";
				cin >> Tecla;
				//
				exit(1);
				//
			}			
			//
		}
		//
	}
	DiscoValido = Disco;
	DiscoValido += ":/Arq.txt";//------>Adicionando um arquivo para teste
	//
	Dicovalido_C = DiscoValido.c_str();//----->Convertendo string C++  em const char*  do  C
	//
	Obj_00_ofstream.open(Dicovalido_C);
	//
	DirValido = Obj_00_ofstream.fail();
	//
	return    DirValido;
	//
}