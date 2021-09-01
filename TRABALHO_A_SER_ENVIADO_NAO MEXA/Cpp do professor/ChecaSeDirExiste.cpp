//
#include "ChecaSeDirExiste.h"
//
//
#include "windows.h"//-----Escrever Caracteres Latinos
#include <direct.h>/*Necessário para usar a função _mkdir(const char*)*/
#include <iostream>//-Vai usar cin e/ou cout
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(1);...
////////////////using std::cout;
////////////////using std::cin;
using namespace std;//Para dispensar std:: em cin e cout

bool ChecaSeDirExiste(string&  Dir)
{
	bool          Veredito;
	string        DirValido;
	ofstream      Obj_Dir_ofstream;
	DirValido = Dir;
	string        DiscoValido;
	ofstream      Obj_00_ofstream;
	DiscoValido = Dir;
	DiscoValido += "/ArqParaTestarSeDirValido.txt";
	Obj_00_ofstream.open(DiscoValido.c_str());
	//
	if (Obj_00_ofstream.fail())
	{
		Veredito = false;//------Disco   não é um disco válido
	}
	else
	{
		//
		Obj_00_ofstream.close();
		//
		Veredito = true;//------Disco   é um disco válido
		//		
	}
	//
	return  Veredito;
}