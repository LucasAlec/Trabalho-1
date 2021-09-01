#include "CTrabDirArq.h"
#include "windows.h"//-----Escrever Caracteres Latinos
//#include <iostream> Em CTrabDirArq.h 3 Linha
#include <cstdio>//----Usar exit(0): exit(10;...
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(10;...
#include <direct.h>/*Necessário para usar a função _mkdir(const char*)*/
#include <cstdio>//----Usar exit(0): exit(1);...
using namespace std;

void CTrabDirArq::CaracterProibidosDirArq()
{
    string Tecla;
	const int Ncaracter_REAL = 30;

	SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos

	if (CTrabDirArq.Ncarcter < CTrabDirArq.Ncaracter_REAL)
	{
		cout << " O número de Caracteres PROIBIDOS é  IGUAL a  " << CTrabDirArq.Ncaracter_REAL << "\n";
		cout << " O número usado para especificar o Tamanho do VETOR  'CaracterProibido[]' (Primeiro argumento da função) " << "\n";
		cout << " Foi Menor que esse valor. Especifica um número Maior ou igual ao valor dado acima. " << "\n";
		cout << " Programa será terminado. " << "\n";
		cout << "Digite uma Tecla para Terminar" << "\n";
        cin >> Tecla;
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		getline(cin, Tecla, '\n');//------>Ler string com caracter espaço em branco
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		exit(0);
	}
	else
	{
		CaracterProibido[0] = " ";
		CaracterProibido[1] = "'";
		CaracterProibido[2] = "!";
		CaracterProibido[3] = "@";
		CaracterProibido[4] = "#";
		CaracterProibido[5] = "$";
		CaracterProibido[6] = "%";
		CaracterProibido[7] = "¨";
		CaracterProibido[8] = "&";
		CaracterProibido[9] = "*";
		CaracterProibido[10] = "(";
		CaracterProibido[11] = ")";
		CaracterProibido[12] = "-";
		CaracterProibido[13] = "+";
		CaracterProibido[14] = "=";
		CaracterProibido[15] = "`";
		CaracterProibido[16] = "´";
		CaracterProibido[17] = "{";
		CaracterProibido[18] = "}";
		CaracterProibido[19] = "[";
		CaracterProibido[20] = "]";
		CaracterProibido[21] = "^";
		CaracterProibido[22] = "~";
		CaracterProibido[23] = "|";
		CaracterProibido[24] = "?";
		CaracterProibido[25] = "<";
		CaracterProibido[26] = ">";
		CaracterProibido[27] = ",";
		CaracterProibido[28] = ";";
		CaracterProibido[29] = ":";

		for (int ia = 0; ia < (CTrabDirArq.Ncarcter - CTrabDirArq.Ncaracter_REAL); ia++)
		{
			CaracterProibido[CTrabDirArq.Ncarcter_REAL + ia] = " ";
		}
	}
}

bool ChecaDiscoValido()
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
