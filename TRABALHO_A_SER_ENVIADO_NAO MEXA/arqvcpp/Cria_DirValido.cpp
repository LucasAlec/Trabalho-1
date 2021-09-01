
#include "Cria_DirValido.h"
#include "ChecaSeDirExiste.h"
#include <direct.h>/*Necessário para usar a função _mkdir(const char*)*/
//
#include "windows.h"//-----Escrever Caracteres Latinos
#include <direct.h>/*Necessário para usar a função _mkdir(const char*)*/
#include <iostream>//-Vai usar cin e/ou cout
#include <fstream>//-----Usar Objetos "ofstream  Escrever em arquivos" e "ifstream ler em Arquivos
#include <cstdio>//----Usar exit(0): exit(1);...
////////////////using std::cout;
////////////////using std::cin;
using namespace std;//Para dispensar std:: em cin e cout


bool Cria_DirValido(string&         DirValido)
{
	//
	bool          Sucesso;
	string        Dir;
	string        Barra;
	int    Nstring, RetornoDe_mkdir;
	//Nstring = DirValido.length();//---Fornece o número de Caracterfes da string   DirValido
	//
	//----Inserido em 26/04/2021
	Nstring = static_cast<int>(DirValido.length());//---Fornece o número de Caracterfes da string   DirValido
	//----Inseridoe m 26/04/2021
	//
	Sucesso = true;
	//
	Barra = "/";
	//
	Dir = "";
	//
	for (int ia = 0; ia < Nstring; ia++)
	{
		Dir += DirValido.at(ia);//------DirValido.at(ia)----Fornece o Caracter de ordem "ia"
		if (DirValido.at(ia) == Barra.at(0))
		{
			RetornoDe_mkdir = _mkdir(Dir.c_str());//------Criando o Diretório
			//
			/*
			if (RetornoDe_mkdir != 0)
			{
			Sucesso = false;
			break;
			}
			//*/
		}
	}
	//
	//////////////////if (Sucesso == true)
	{
		Dir += "/";
		RetornoDe_mkdir = _mkdir(Dir.c_str());//------Criando o Diretório
		//
		/*
		if (RetornoDe_mkdir != 0)
		{
		Sucesso = false;
		}
		//*/
	}
	//
	ChecaSeDirExiste(Dir);
	Sucesso = ChecaSeDirExiste(Dir);
	//
	return  Sucesso;
}
