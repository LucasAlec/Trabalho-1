//
//
#include "InsereArqEmDir_0.h"
#include "windows.h"//-----Escrever Caracteres Latinos
#include <iostream>//-Vai usar cin e/ou cout
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(10;...
using namespace std;
//
//
void InsereArqEmDir_0(string&  Dir, string&    Arq)
{
	string         DirArq;
	ofstream       Obj_ofstream;
	string         Tecla_0;
	DirArq = Dir;
	DirArq += "/";
	DirArq += Arq;
	Obj_ofstream.open(DirArq.c_str());
	//
	if (Obj_ofstream.fail())
	{
		SetConsoleOutputCP(GetACP());//----Escrever Caracteres Latinos
		cout << " Falha para inserir o Arquivo  " << Arq << "\n";
		cout << " Digite qualquer Tecla para Continuar " << "\n";
		////////////////cin >> Tecla_0;
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
		getline(cin, Tecla_0, '\n');//------>Ler string com caracter espaço em branco
		//------------------------------------------------------------------------------------>IMPORTANTE--28/04/2021
	}
	else
	{
		Obj_ofstream.close();//------>Fechar para usaD:/(_DOES_/ConsoleApplication4/ConsoleApplication4r o mesmo Objeto "Obj_ofstream" para inserir os outros arquivos
	}
}
